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

	//vector matching precedence for operators
	for (int i = 0; i < operations.size(); i++)
		operationPrecedence.push_back(GetPrecedence(operations[i]));

	//organize the vectors with the highest precedence being at lower indecies
	OrganizeVectors();

	//complete operations
	for (int i = 0; i < operations.size(); i++)
	{
		char currentChar = operations[i];
		int precedence = GetPrecedence(currentChar);

		//grab index of the param

		//multiply, mod, divide
		if (precedence == 2)
		{

		}

	}

}
void JammyParser::Interpret(wxString expression)
{
	std::string expressionStr = (std::string)expression;
	Interpret(expressionStr);
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
		/*case '(':
		case ')':
			return 3;*/
	default:
		return -1;
	}
}

int JammyParser::GetNumberFromChar(char c)
{
	return c - '0';
}

void JammyParser::OrganizeVectors()
{
	for (int i = 1; i <= operations.size(); i++)
	{
		if (operationPrecedence[i] > 1)
		{
			//swap operators
			SwapOperators(i);
			for (size_t i = 0; i < 2; i++)
				SwapNumbers(2 - i);
		}
	}

}

void JammyParser::SwapOperators(int index)
{
	int temp = operations[index - 1];
	operations[index - 1] = operations[index];
	operations[index] = temp;
}
void JammyParser::SwapNumbers(int index)
{
	int temp = nums[index];
	nums[index] = nums[index + 1];
	nums[index + 1] = temp;
}

int Evaluate(int num1, int num2, char op)
{
	int result = 0;
	if (op == '*')
		result = num1 * num2;
	else if (op == '/')
		result = num1 / num2;
	else if (op == '%')
		result = num1 % num2;
	else if (op == '+')
		result = num1 + num2;
	else if (op == '-')
		result = num1 - num2;
	return result;
}
