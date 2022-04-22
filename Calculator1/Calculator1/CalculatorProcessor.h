#pragma once
#include "wx/wx.h"

class IBaseCommand;
class CalculatorProcessor
{
public:
	static CalculatorProcessor& GetInstance(wxString expression)
	{
		static CalculatorProcessor calc;
		calc.ProjectedSolution(expression);
		return calc;
	}
private: 
	std::vector<IBaseCommand*> commands;
	std::vector<double> nums;
	//conversion functions
	//only valid constructor
	CalculatorProcessor(wxString expression);
	CalculatorProcessor();

	//Pass in the whole string, include all arithmetic. Will return a decimal number
	void ProjectedSolution(wxString decStr);
	void NewProjectedSolution(wxString decStr);

	bool IsOperator(char c);
	bool IsNumber(char c);
	int GetPrecedence(char c);


	void PushNums();
	void PushAddCommand();
	void PushSubtractCommand();
	void PushMultiplyCommand();
	void PushDivideCommand();
	void PushModulusCommand();
	void ClearCommandVector();
	void ClearNums();
public:
	double resultAsDouble;
	wxString resultAswxString;
	CalculatorProcessor(CalculatorProcessor const&) = delete;
	void operator=(CalculatorProcessor const&) = delete;
};
