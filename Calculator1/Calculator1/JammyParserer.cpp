#include "JammyParserer.h"
#include <vector>
JammyParser::JammyParser()
{

}
JammyParser::~JammyParser()
{

}
int JammyParser::Interpret(const char* equation)
{
    expressionToParse = equation;
	int result = expression();
    return result;
}
//int JammyParser::Interpret(wxString expression)
//{
//	std::string expressionStr = (std::string)expression;
//	return Interpret(expressionStr);
//}


int JammyParser::term()
{
    int result = factor();
    while (peek() == '*' || peek() == '/')
        if (get() == '*')
            result *= factor();
        else
            result /= factor();
    return result;
}
int JammyParser::expression()
{
    int result = term();
    while (peek() == '+' || peek() == '-')
        if (get() == '+')
            result += term();
        else
            result -= term();
    return result;
}

int JammyParser::factor()
{
    if (peek() >= '0' && peek() <= '9')
        return number();
    else if (peek() == '(')
    {
        get(); // '('
        int result = expression();
        get(); // ')'
        return result;
    }
    else if (peek() == '-')
    {
        get();
        return -factor();
    }
    return 0; // error
}

int JammyParser::number()
{
    int result = get() - '0';
    while (peek() >= '0' && peek() <= '9')
    {
        result = 10 * result + get() - '0';
    }
    return result;
}

char JammyParser::get()
{
    return *expressionToParse++;
}

char JammyParser::peek()
{
    return *expressionToParse;
}