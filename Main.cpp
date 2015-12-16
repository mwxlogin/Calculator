#include "Pch.h"
#include <iostream>
#include "Parser.h"
#include "Calculator.h"
#include "Expression.h"

int main(int argc, char* argv[])
{
	char charArray[256];
	std::string expressionStr;
	TokenMap tokenMap;
	Expression expression;
	while (expressionStr != "exit")
	{
		std::cout << "Expression:";
		std::cin.getline(charArray, 256);
		expressionStr = charArray;
		bool isParseOk = Parser::Parse(expressionStr, expression);
		if (isParseOk)
		{
			std::cout << "result:" << Calculator::Calculate(expression) << std::endl;
		}
		else
		{
			std::cout << "result:" << expressionStr << std::endl;
		}
	}

	return 0;
}