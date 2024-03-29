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
	//the following functions rely on the functions above
	std::string BinToHex(int n);
	int HexToBinary(wxString hex);
};

