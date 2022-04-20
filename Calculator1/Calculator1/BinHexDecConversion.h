#pragma once
#include "wx/wx.h"
#include <string>
class BinHexDecConversion
{
public:
	BinHexDecConversion();
	
	//conversion methods
	int DecimalToBinary(int decimal);
	int BinaryToDecimal(int n);
	std::string DecimalToHex(int num);
	int HexToDecimal(wxString hex);
};

