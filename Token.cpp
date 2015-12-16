#include "Pch.h"
#include "Token.h"

Token::Token()
{
}

Token::Token(EmTokenType p_type)
{
	m_type = p_type;
}

Token::Token(EmTokenType p_type, float p_value)
{
	m_type = p_type;
	m_value = p_value;
}

Token::~Token()
{
}

float Token::GetValue()
{
	return m_value;
}

EmTokenType Token::GetType()
{
	return m_type;
}

void Token::SetValue(float p_value)
{
	m_value = p_value;
}

void Token::SetType(EmTokenType p_type)
{
	m_type = p_type;
}
