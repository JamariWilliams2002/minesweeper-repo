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
void CalculatorProcessor::ClearNums()
{
	nums.clear();
}
void CalculatorProcessor::ClearCommandVector()
{
	commands.clear();
}

#pragma endregion

