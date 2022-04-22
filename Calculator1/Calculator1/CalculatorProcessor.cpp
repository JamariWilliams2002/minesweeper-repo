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

void CalculatorProcessor::ProjectedSolution(wxString decStr)
{
	double numResult = 0;
	wxString strResult;
	numResult = te_interp(decStr, 0);
	strResult = std::to_string(numResult);

	resultAsDouble = numResult;
	resultAswxString = strResult;
}

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
void CalculatorProcessor::PushClearCommandVector()
{
	for (int i = 0; i < commands.size(); i++)
		commands.pop_back();
}
