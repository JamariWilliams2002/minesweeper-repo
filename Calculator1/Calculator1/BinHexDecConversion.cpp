#include "BinHexDecConversion.h"
#include <sstream>
#include <string>

BinHexDecConversion::BinHexDecConversion()
{

}

int BinHexDecConversion::DecimalToBinary(int decimal)
{
	int binary = 0, remainder, product = 1;

	while (decimal != 0) {
		remainder = decimal % 2;
		binary = binary + (remainder * product);
		decimal = decimal / 2;
		product *= 10;
	}
	return binary;
}

std::string BinHexDecConversion::DecimalToHex(int num)
{
	std::stringstream ss;
	ss << std::hex << num; // int decimal_value
	std::string res(ss.str());
	return res;
}

int BinHexDecConversion::BinaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;

	// Initializing base value to 1, i.e 2^0
	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

int BinHexDecConversion::HexToDecimal(wxString hex)
{
	int result;
	std::stringstream ss;
	ss << hex;
	ss >> std::hex >> result;

	return result;
}