#include "JammyParserer.h"
#include <vector>
JammyParser::JammyParser()
{
	prec1 = 0;
	prec2 = 0;
}


JammyParser::~JammyParser()
{

}
int JammyParser::Interpret(std::string expression)
{
	//decStr = "124";
	char op = 0;
	int result = 0;
	bool isNegative = false;
	//building vectors
	for (int i = 0; i < (int)expression.length();)
	{
		//check if it's a negative value
		if (expression[i] == '-' && IsNumber(expression[i + 1]))
		{
			isNegative = true;
			i++;
		}

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
			int nextNum = currentChar, digit, numToPush = 0, count = i;
			do//get the remaining digits in that number
			{
				digit = GetNumberFromChar(nextNum);
				number += std::to_string(digit);
				//continue in the string
				nextNum = expression[count + 1];
				count++;
			} while (IsNumber(nextNum));
			if (isNegative)
			{
				isNegative = false;
				numToPush = (std::stod(number)) * -1;
			}
			else
				numToPush = (std::stod(number));

			//add to vector
			nums.push_back(numToPush);
			i = count;
		}
	}
	//simple if only one operation
	if (operations.size() == 1)
	{
		result = Evaluate(nums[0], nums[1], operations[0]);
	}
	else
	{
		//vector matching precedence for operators
		for (int i = 0; i < (int)operations.size(); i++)
			operationPrecedence.push_back(GetPrecedence(operations[i]));

		//organize the vectors with the highest precedence being at lower indecies
		OrganizeVectors();

		result = RecursiveDescent(nums[0]);


		//first operation
		//int tempResult = Evaluate(nums[0], nums[1], operations[0]);
		//auto it1 = nums.begin();
		//auto it2 = nums.begin() + 1;
		//auto it3 = operations.begin();
		//operations.erase(it3);
		//nums.erase(it1);
		//nums.erase(it2);
		//result = Evaluate(tempResult, nums[2], operations[0]);

		//for (int i = 0; i < operations.size(); i++)
		//{
		//	//grab temp result
		//	tempResult = Evaluate(nums[0], nums[1], operations[0]);

		//	//pop the values used
		/*	auto it1 = nums.begin();
			auto it2 = nums.begin() + 1;
			auto it3 = operations.begin();
			operations.erase(it3);
			nums.erase(it1);
			nums.erase(it2);
			result = nums[2];
			result = Evaluate(tempResult)
		}*/
	}



	//complete operations
	//int size = operations.size();
	//bool change = false;
	//for (int i = 0; i < size; i++)
	//{
	//	int temp;
	//	char currentChar = operations[i];
	//	int precedence = GetPrecedence(currentChar);
	//	//grab index of the param

	//	int index = i;
	//	//check to see if there are any high precedent operators
	//	if (operations.size() != 1) //atleast one high precedence operator
	//	{
	//		//find high precedence operator
	//		auto it = std::find(operations.begin(), operations.end(), '%');
	//		if (it != operations.end())
	//		{
	//			index = it - operations.begin();
	//			change == true;
	//		}
	//		//change the value in the vector
	//	}

	//	//evaluate result

	//	result = Evaluate(nums[index], nums[index + 1], operations[index]);
	//	//make the value unreadable so it's not evaluated twice. 
	//	operations[index] = 'd';

	//	//change the values in the nums vector
	//	nums[index] = Evaluate(nums[index], nums[index + 1], operations[index]);
	//	nums[index + 1] = INT32_MAX;

	//}
	return result;
}
int JammyParser::Interpret(wxString expression)
{
	std::string expressionStr = (std::string)expression;
	return Interpret(expressionStr);
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
		prec1++;
		return 1;
	case '*':
	case '/':
	case '%':
		prec2++;
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
	int prevOpPrec = 0;
	int index = 0;
	bool needSwap = false;
	//no work required for one operator
	if (operations.size() == 1)
		return;
	for (int i = 0; i < (int)operations.size(); i++)
	{
		if (operations.size() == i + 1)
		{
			index = i;
			needSwap = operationPrecedence[index] > operationPrecedence[prevOpPrec];
		}
		else
			index = i + 1;
		prevOpPrec = index - 1;
		while (operationPrecedence[index] < operationPrecedence[prevOpPrec] || needSwap)
		{
			//swap operators
			SwapOperators(index);
			//means we have at least 3 nums
			SwapNumbers(index + 1);
			needSwap = false;
		}

	}
}

void JammyParser::SwapOperators(int index)
{
	//operator vector
	int temp = operations[index - 1];
	operations[index - 1] = operations[index];
	operations[index] = temp;

	//operator precedence vector
	//temp = operationPrecedence[index - 1];
	//operationPrecedence[index - 1] = operationPrecedence[index];
	//operationPrecedence[index] = temp;
}
void JammyParser::SwapNumbers(int index)
{
	/*int temp = nums[index];

	nums[index] = nums[index + 1];
	nums[index + 1] = temp;*/

	int temp = nums[index];
	int temp2 = nums[index - 1];
	int temp3 = nums[index - 2];
	nums[index] = temp3;
	nums[index - 1] = temp;
	nums[index - 2] = temp2;
}

int JammyParser::Evaluate(int num1, int num2, char op)
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

std::vector<char>::iterator JammyParser::CheckMultiply()
{
	return std::find(operations.begin(), operations.end(), '%');
}
std::vector<char>::iterator JammyParser::CheckDivide()
{
	return std::find(operations.begin(), operations.end(), '%');
}
std::vector<char>::iterator JammyParser::CheckModulus()
{
	return std::find(operations.begin(), operations.end(), '%');
}

int JammyParser::RecursiveDescent(int indexZero)
{
	//pass in the first index of the nums vector
	indexZero = Evaluate(indexZero, nums[1], operations[0]);

	//pops the used values
	auto numIt = nums.begin();
	auto opIt = operations.begin();
	operations.erase(opIt);
	nums.erase(numIt);
	nums[0] = indexZero;
	//keep going until finished
	if (operations.size() != 0)
		indexZero = RecursiveDescent(indexZero);
	return indexZero;
}
