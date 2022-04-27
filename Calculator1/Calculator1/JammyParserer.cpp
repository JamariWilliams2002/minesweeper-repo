#include "JammyParserer.h"
#include <vector>
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
	std::vector<double> nums;
	std::vector<char> operations;
	//building vectors
	for (int i = 0; i < expression.length();)
	{
		char currentChar = expression[i];
		//if it's a space, then continue
		if (currentChar == ' ')
		{
			i++;
			continue;
		}
		else if (IsOperator(currentChar)) //found operator
		{
			op = currentChar;
			operations.push_back(currentChar);
			i++;
		}
		else if (IsNumber(currentChar)) //found a number
		{
			std::string number = "";
			int nextNum = currentChar, digit, count = i;
			do//get the remaining digits in that number
			{
				digit = GetNumberFromChar(nextNum);
				number += std::to_string(digit);
				//continue in the string
				nextNum = expression[count + 1];
				count++;
			} while (IsNumber(nextNum));

			//add to vector
			nums.push_back(std::stod(number));
			i = count;
		}
	}

	//complete operations
	for (int i = 0; i < operations.size(); i++)
	{
		char currentChar = expression[i];
		int precedence = GetPrecedence(currentChar);
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
	return c - '0';
}
