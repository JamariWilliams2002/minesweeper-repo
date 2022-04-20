#pragma once
#include "wx/wx.h"
class CalculatorProcessor
{
public:
	static CalculatorProcessor& GetInstance(wxString expression)
	{
		static CalculatorProcessor calc(expression);
		return calc;
	}
private: 
	//conversion functions
	//only valid constructor
	CalculatorProcessor(wxString expression){}
	CalculatorProcessor(CalculatorProcessor const&);
	void operator=(CalculatorProcessor const&);

	//Pass in the whole string, include all arithmetic. Will return a decimal number
	void ProjectedSolution(wxString decStr);
public:
	Result mResult;
	CalculatorProcessor(CalculatorProcessor const&) = delete;
	void operator=(CalculatorProcessor const&) = delete;
};

struct Result
{
	static double AsDouble;
	static wxString AswxString;
};