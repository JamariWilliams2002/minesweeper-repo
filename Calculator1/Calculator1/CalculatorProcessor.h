#pragma once
#include "wx/wx.h"
class CalculatorProcessor
{
public:
	static CalculatorProcessor& getInstance()
	{
		static CalculatorProcessor calc;
		return calc;
	}
private: 
	CalculatorProcessor(){}
	CalculatorProcessor(CalculatorProcessor const&);
	void operator=(CalculatorProcessor const&);
	
	wxString ProjectedSolution(wxString decStr);
public:
	CalculatorProcessor(CalculatorProcessor const&) = delete;
	void operator=(CalculatorProcessor const&) = delete;
};

