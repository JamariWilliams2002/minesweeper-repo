#include "CalculatorProcessor.h"
#include "JammyParserer.h"
#include "IBaseCommand.h"
#include <sstream>

CalculatorProcessor::CalculatorProcessor()
{

}
CalculatorProcessor::CalculatorProcessor(wxString expression)
{
	ProjectedSolution(expression);
}

#pragma region Solution

void CalculatorProcessor::ProjectedSolution(wxString decStr)
{
	double numResult = 0;
	wxString strResult;
	JammyParser parser;
	numResult = parser.Interpret((std::string)decStr);
	//numResult = te_interp(decStr, 0);
	strResult = std::to_string(numResult);

	resultAsDouble = numResult;
	resultAswxString = strResult;
}

void CalculatorProcessor::NewProjectedSolution(wxString decStr)
{
	//decStr = "124";
	char op = 0;
	std::string nums = "";
	for (int i = 0; i < decStr.length(); i++)
	{
		char currentChar = decStr[i];
		if (IsOperator(currentChar)) //found operator
		{
			op = currentChar;
		}
		else if (IsNumber(currentChar)) //found a number
		{
			int nextNum = i, nextIndex = 1;

			do//get the remaining digits in that number
			{
				nums += (char)nextNum;
				//add the number to the string
				nextNum = decStr[i + nextIndex];
			} while (IsNumber(nextNum));
		}
		else if (currentChar == ' ')
			continue;
		//if it's a space, then continue
	}
}

void CalculatorProcessor::NewestProjectedSolution()
{
	wxString decStr = "", clickedAction;
	int count = 0;
	//build the string
	for (size_t i = 0; i < commands.size(); i++)
	{
		//count = i + 1;
		clickedAction = commands[i]->Execute();
		decStr = decStr + std::to_string(nums[i]) + clickedAction;
		if (commands.size() - 1 == i)
		{
			decStr = decStr + std::to_string(nums[i + 1]);
			/*if (commands.size() > 1)
			{
				decStr = decStr + commands[i + 1]->Execute() + std::to_string(nums[i + 2]);
			}*/
		}
	}
	//call projected solution with the created decStr
	ProjectedSolution(decStr);
}

void CalculatorProcessor::NewerProjectedSolution(std::string s)
{
	double numResult = 0;
	wxString strResult;
	JammyParser parser;
	numResult = parser.Interpret(s);
	strResult = std::to_string(numResult);

	resultAsDouble = numResult;
	resultAswxString = strResult;

}
bool CalculatorProcessor::IsOperator(char c)
{
	bool result;
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
		result = true;
	else
		result = false;
	return result;
}
bool CalculatorProcessor::IsNumber(char c)
{
	bool result;
	if (c >= '0' && c <= '9')
		result = true;
	else
		result = false;
	return result;
}

int CalculatorProcessor::GetPrecedence(char c)
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

#pragma endregion

#pragma region Commands 
void CalculatorProcessor::PushNums(double num)
{
	nums.push_back(num);
}

void CalculatorProcessor::PushAddCommand(double num)
{
	commands.push_back(new AddCommand());
	nums.push_back(num);
}

void CalculatorProcessor::PushSubtractCommand(double num)
{
	commands.push_back(new SubtractCommand());
	nums.push_back(num);
}

void CalculatorProcessor::PushMultiplyCommand(double num)
{
	commands.push_back(new MultiplyCommand());
	nums.push_back(num);
}

void CalculatorProcessor::PushDivideCommand(double num)
{
	commands.push_back(new DivideCommand());
	nums.push_back(num);
}
void CalculatorProcessor::PushModulusCommand(double num)
{
	commands.push_back(new ModulusCommand());
	nums.push_back(num);
}

void CalculatorProcessor::ClearNums()
{
	nums.clear();
}
void CalculatorProcessor::ClearCommandVector()
{
	//clear allocated memory
	for (size_t i = 0; i < commands.size(); i++)
	{
		delete commands[i];
	}
	commands.clear();
}

#pragma endregion

#pragma region Conversions
int CalculatorProcessor::DecimalToBinary(int decimal)
{
	int binary = 0, remainder, product = 1;

	while (decimal != 0) {
		remainder = decimal % 2;
		binary = binary + (remainder * product);
		decimal = decimal / 2;
		product *= 10;
	}
	return binary;
}

std::string CalculatorProcessor::DecimalToHex(int num)
{
	std::stringstream ss;
	ss << std::hex << num; // int decimal_value
	std::string res(ss.str());
	return res;
}

int CalculatorProcessor::BinaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;

	// Initializing base value to 1, i.e 2^0
	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

int CalculatorProcessor::HexToDecimal(wxString hex)
{
	int result;
	std::stringstream ss;
	ss << hex;
	ss >> std::hex >> result;

	return result;
}

std::string CalculatorProcessor::BinToHex(int n)
{
	int result = BinaryToDecimal(n);
	return DecimalToHex(result);
}

int CalculatorProcessor::HexToBinary(wxString hex)
{
	int result = HexToDecimal(hex);
	return DecimalToBinary(result);
}
#pragma endregion


CalculatorProcessor::~CalculatorProcessor()
{
	ClearCommandVector();
}