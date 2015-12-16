#ifndef Parser_h__
#define Parser_h__
#include <sstream>

class Expression;

class Parser
{
public:
	Parser();
	~Parser();
public:
	static bool Parse(std::string& p_expression, Expression& p_tokenMap);
	static float strToNum(std::string& p_str);
	static int GetEndSignLocation(std::string& p_expression);
	static bool IsStringValide(std::string& p_expression);
	static void Trim(std::string &str);
private:

};

#endif