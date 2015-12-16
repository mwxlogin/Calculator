#include "Pch.h"
#include "Parser.h"
#include <sstream>
#include "Expression.h"

Parser::Parser()
{
}

Parser::~Parser()
{
}


bool Parser::Parse(std::string& p_expressionStr, Expression& p_expression)
{
	Trim(p_expressionStr);
	p_expression.GetTokenMap().clear();

	if (!IsStringValide(p_expressionStr))
	{
		return false;
	}

	Token token;
	Token tokenNum;
	int preSignLocation = -1;
	int stringCounter = -1;
	int mapCounter = 0;
	std::string subStr;
	std::string::iterator it;
	for (it = p_expressionStr.begin(); it != p_expressionStr.end(); it++)
	{
		bool isSign = false;
		++stringCounter;
		switch (*it)
		{
		case '+':
			token.SetType(TokenType_Plus);
			token.SetValue(TokenType_Plus);
			isSign = true;
			break;
		case '-':
			token.SetType(TokenType_Minus);
			token.SetValue(TokenType_Minus);
			isSign = true;
			break;
		case '*':
			token.SetType(TokenType_Multiply);
			token.SetValue(TokenType_Multiply);
			isSign = true;
			break;
		case '/':
			token.SetType(TokenType_Divide);
			token.SetValue(TokenType_Divide);
			isSign = true;
			break;
		default:
			break;
		}
		
		if (isSign)
		{
			mapCounter++;
			p_expression.GetTokenMap()[mapCounter] = token;

			if (preSignLocation+1 == stringCounter)
			{
				return false;
			}

			subStr = p_expressionStr.substr(preSignLocation + 1, stringCounter);
			tokenNum.SetType(TokenType_Num);
			tokenNum.SetValue(strToNum(subStr));
			p_expression.GetTokenMap()[mapCounter - 1] = tokenNum;
			mapCounter++;

			preSignLocation = stringCounter;
		}
		
	}
	
	int endSignLocation = GetEndSignLocation(p_expressionStr);
	subStr = p_expressionStr.substr(endSignLocation + 1, -1);
	tokenNum.SetType(TokenType_Num);
	tokenNum.SetValue(strToNum(subStr));
	p_expression.GetTokenMap()[mapCounter] = tokenNum;

	return true;
}

float Parser::strToNum(std::string& p_str)
{
	float value = 0.0f;
	sscanf_s(p_str.c_str(), "%f", &value);
	return value;
}

int Parser::GetEndSignLocation(std::string& p_expression)
{
	int length = p_expression.length();
	for (size_t i = length; i > 0; i--)
	{
		switch (p_expression[i])
		{
		case '+':
		case '-':
		case '*':
		case '/':
			return i;
		default:
			break;
		}
	}

	return 0;
}

bool Parser::IsStringValide(std::string& p_expression)
{
	std::string::iterator it;
	for (it = p_expression.begin(); it != p_expression.end(); ++it)
	{
		if (*it >= '0' && *it <= '9')
		{
			continue;
		}

		if (*it == '+' ||
			*it == '-' ||
			*it == '*' ||
			*it == '/' ||
			*it == '.'
			)
		{
			continue;
		}

		return false;
	}

	return true;
}

void Parser::Trim(std::string &str)
{
	if (str.empty())
	{
		return;
	}
	str.erase(0, str.find_first_not_of(' '));
	str.erase(str.find_last_not_of(' ') + 1);
	return;
}
