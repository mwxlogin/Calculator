#include "Pch.h"
#include "Expression.h"

Expression::Expression()
{
	m_tokenMap.clear();
}

Expression::~Expression()
{
}

void Expression::GetResult(TokenMap::iterator& p_it)
{
	TokenMap::iterator itTemp;
	TokenMap::iterator itPre;
	TokenMap::iterator itNext;

	itTemp = p_it;
	itPre = --itTemp;
	itTemp = p_it;
	itNext = ++itTemp;
	float value = 0.0f;
	switch (p_it->second.GetType())
	{
	case TokenType_Plus:
		value = itPre->second.GetValue() + itNext->second.GetValue();
		break;
	case TokenType_Minus:
		value = itPre->second.GetValue() - itNext->second.GetValue();
		break;
	case TokenType_Multiply:
		value = itPre->second.GetValue() * itNext->second.GetValue();
		break;
	case TokenType_Divide:
		value = itPre->second.GetValue() / itNext->second.GetValue();
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
	
	Token result(TokenType_Num);
	result.SetValue(value);
	itPre->second = result;

	p_it = m_tokenMap.erase(p_it);
	p_it = m_tokenMap.erase(p_it);
}
