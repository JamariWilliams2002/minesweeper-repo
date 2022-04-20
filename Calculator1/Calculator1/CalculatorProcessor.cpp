#include "CalculatorProcessor.h"
#include "tinyexpr.h"

wxString CalculatorProcessor::ProjectedSolution(wxString decStr)
{
	double numResult = 0;
	wxString strResult;
	numResult = te_interp(decStr, 0);
	//back to hex/bin
	if (isDec)
	{
		if (decimalPointClicked || numResult - (int)numResult != 0) //check for double
			strResult = wxString::Format(wxT("%f"), numResult);
		else
			strResult = wxString::Format(wxT("%i"), (int)numResult);
	}
	else if (isBin)
	{
		numResult = DecimalToBinary((int)numResult);
		strResult = wxString::Format(wxT("%i"), (int)numResult);
	}
	else //isHex
		strResult = DecimalToHex((int)numResult);


	return strResult;
}

