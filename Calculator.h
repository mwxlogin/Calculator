#ifndef Calculator_h__
#define Calculator_h__
#include"Expression.h"

class Calculator
{
public:
	Calculator();
	~Calculator();
public:
	static float Calculate(Expression& p_expression);
private:
	static void CalcuSecond(Expression& p_expression);
	static float CalcuFirst(Expression& p_expression);
};
#endif