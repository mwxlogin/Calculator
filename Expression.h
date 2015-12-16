#ifndef Expression_h__
#define Expression_h__
#include "Token.h"

typedef std::map<int, Token> TokenMap;

class Expression
{
public:
	Expression();
	~Expression();
public:
	void GetResult(TokenMap::iterator& p_it);
	TokenMap& GetTokenMap(){ return m_tokenMap; }
private:
	TokenMap m_tokenMap;
};

#endif