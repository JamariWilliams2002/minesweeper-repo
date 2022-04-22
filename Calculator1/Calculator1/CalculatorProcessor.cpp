#include "CalculatorProcessor.h"
#include "tinyexpr.h"
#include "BinHexDecConversion.h"
#include "IBaseCommand.h"

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
	numResult = te_interp(decStr, 0);
	strResult = std::to_string(numResult);

	resultAsDouble = numResult;
	resultAswxString = strResult;
}

void CalculatorProcessor::NewProjectedSolution(wxString decStr)
{
	char op;
	std::string nums;
	for (int i = 0; i < decStr.length(); i++)
	{
		if (IsOperator(decStr[i])) //found operator
		{

		}
		else if (IsNumber(decStr[i])) //found a number
		{
			int nextNum = i;
			while (IsNumber(decStr[i])) //get the remaining digits in that number
			{

			}
		}
		//if it's a space, then continue
	}
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
void CalculatorProcessor::PushAddCommand()
{
	commands.push_back(new AddCommand(1, 2));
}
void CalculatorProcessor::PushSubtractCommand()
{
	commands.push_back(new SubtractCommand(1, 2));
}
void CalculatorProcessor::PushMultiplyCommand()
{
	commands.push_back(new MultiplyCommand(1, 2));
}
void CalculatorProcessor::PushDivideCommand()
{
	commands.push_back(new DivideCommand(1, 2));
}
void CalculatorProcessor::PushModulusCommand()
{
	commands.push_back(new ModulusCommand(1, 2));
}
void CalculatorProcessor::ClearCommandVector()
{
	for (int i = 0; i < commands.size(); i++)
		commands.pop_back();
}
#pragma endregion

