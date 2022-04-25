#include "../Calculator1/CalculatorProcessor.h"
#include "../Calculator1/BinHexDecConversion.h"
bool BinToDec11()
{
	bool result = true;
	int binNum = 1011, conversion = 0;
	std::string s = std::to_string(binNum);

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->BinaryToDecimal(binNum);

	if (conversion != 11)
		result = false;
	return result;
}

bool BinToDec138()
{
	bool result = true;
	int num = 10001010, conversion = 0;
	std::string s = std::to_string(num);

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->BinaryToDecimal(num);

	if(conversion != 138)
		result = false;
	return result;
}
bool DecToBin42()
{
	bool result = true;
	int num = 42, conversion = 0;
	std::string s = std::to_string(num);

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->DecimalToBinary(num);

	if (conversion != 101010)
		result = false;
	return result;
}
bool DecToBin245()
{
	bool result = true;
	int num = 0, conversion = 0;

	std::string s = std::to_string(num);
	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);

	if(conversion != 0)
		result = false;
	return result;
}
bool HexToDec328()
{
	bool result = true;
	int num = 0, conversion = 0;

	if(conversion != 0)
		result = false;
	return result;
}
bool HexToDec18()
{
	bool result = true;
	int num = 0, conversion = 0;

	if(conversion != 0)
		result = false;
	return result;
}
bool DecToHex84()
{
	bool result = true;
	int num = 0, conversion = 0;

	if(conversion != 0)
		result = false;
	return result;
}
bool DecToHex99()
{
	bool result = true;
	int num = 0, conversion = 0;

	if(conversion != 0)
		result = false;
	return result;
}
bool BinToHex200()
{
	bool result = true;
	int num = 0, conversion = 0;

	if(conversion != 0)
		result = false;
	return result;
}
bool HexToBin408()
{
	bool result = true;
	int num = 0, conversion = 0;

	if(conversion != 0)
		result = false;
	return result;
}
