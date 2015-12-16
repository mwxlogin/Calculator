#include "Pch.h"
#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

// 计算二级运算
void Calculator::CalcuSecond(Expression& p_expression)
{
	Token result(EmTokenType::TokenType_Num);

	TokenMap::iterator it;

	for (it = p_expression.GetTokenMap().begin(); it != p_expression.GetTokenMap().end();)
	{
		if (it->second.GetType() != TokenType_Num)
		{
			switch (it->second.GetType())
			{
			case TokenType_Num:
			case TokenType_Plus:
			case TokenType_Minus:
				it++;
				break;
			case TokenType_Multiply:
			case TokenType_Divide:
				p_expression.GetResult(it);
				break;
			case TokenType_LeftBracket:
				break;
			case TokenType_RightBracket:
				break;
			case TokenType_Max:
				break;
			default:
				break;
			}
		}
		else
		{
			++it;
		}
	}
}

// 计算一级运算
float Calculator::CalcuFirst(Expression& p_expression)
{
	Token result(EmTokenType::TokenType_Num);
	TokenMap::iterator it;
	int counter = -1;
	for (it = p_expression.GetTokenMap().begin(); it != p_expression.GetTokenMap().end();)
	{
		counter++;

		if (it->second.GetType() != TokenType_Num)
		{
			switch (it->second.GetType())
			{
				case TokenType_Plus:
				case TokenType_Minus:
					p_expression.GetResult(it);
					break;
				case TokenType_Multiply:
					break;
				case TokenType_Divide:
					break;
				case TokenType_LeftBracket:
					break;
				case TokenType_RightBracket:
					break;
				case TokenType_Max:
					break;
				default:
					break;
			}
		}
		else
		{
			++it;
		}
	}

	return p_expression.GetTokenMap()[0].GetValue();
}

float Calculator::Calculate(Expression& p_expression)
{
	CalcuSecond(p_expression);
	
	float value;
	value = CalcuFirst(p_expression);

	return value;
}
