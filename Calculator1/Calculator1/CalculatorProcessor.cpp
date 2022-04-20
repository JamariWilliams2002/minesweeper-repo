#include "CalculatorProcessor.h"
#include "tinyexpr.h"
#include "BinHexDecConversion.h"

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

	mResult.AsDouble = numResult;
	mResult.AswxString = strResult;
}

