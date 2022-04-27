#include "JammyParserer.h"
JammyParser::JammyParser()
{

}


JammyParser::~JammyParser()
{

}
void JammyParser::Interpret(std::string expression)
{
	//decStr = "124";
	char op = 0;
	std::string nums = "";
	for (int i = 0; i < expression.length(); i++)
	{
		char currentChar = expression[i];
		if (currentChar == ' ') //if it's a space, then continue
			continue;
		else if (IsOperator(currentChar)) //found operator
		{
			op = currentChar;
		}
		else if (IsNumber(currentChar)) //found a number
		{
			int nextNum = i, digit;
			do//get the remaining digits in that number
			{
				digit = GetNumberFromChar(nextNum);
				nums += digit;
				//add the number to the string
				nextNum = expression[i + 1];
			} while (IsNumber(nextNum));
		}
	}
	
}
void JammyParser::Interpret(wxString expression)
{

}


bool JammyParser::IsOperator(char c)
{
	bool result;
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		result = true;
	else
		result = false;
	return result;
}
bool JammyParser::IsNumber(char c)
{
	bool result;
	if (c >= '0' && c <= '9')
		result = true;
	else
		result = false;
	return result;
}

int JammyParser::GetPrecedence(char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 3;
	case '*':
	case '/':
	case '%':
		return 2;
	case '(':
	case ')':
		return 3;
	default:
		return -1;
	}
}

int JammyParser::GetNumberFromChar(char c)
{
	return '0' - c;
}
