#ifndef Token_h__
#define Token_h__

enum EmTokenType
{
	TokenType_Num,
	TokenType_Plus,
	TokenType_Minus,
	TokenType_Multiply,
	TokenType_Divide,
	TokenType_LeftBracket,
	TokenType_RightBracket,
	TokenType_Max
};

class Token
{
public:
	Token();
	Token(EmTokenType p_type);
	Token(EmTokenType p_type, float p_value);
	~Token();
public:
	float GetValue();
	EmTokenType GetType();

	void SetValue(float p_value);
	void SetType(EmTokenType p_type);
private:
	EmTokenType m_type;
	float		m_value;
};

#endif
