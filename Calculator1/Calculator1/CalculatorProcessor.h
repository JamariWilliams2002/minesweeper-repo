#pragma once
#include "wx/wx.h"

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
	//conversion functions
	//only valid constructor
	CalculatorProcessor(wxString expression);
	CalculatorProcessor();

	//Pass in the whole string, include all arithmetic. Will return a decimal number
	void ProjectedSolution(wxString decStr);
public:
	double resultAsDouble;
	wxString resultAswxString;
	CalculatorProcessor(CalculatorProcessor const&) = delete;
	void operator=(CalculatorProcessor const&) = delete;
};
