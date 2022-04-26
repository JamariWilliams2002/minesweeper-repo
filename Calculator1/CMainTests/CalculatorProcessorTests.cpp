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
	int num = 245, conversion = 0;
	std::string s = std::to_string(num);

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->DecimalToBinary(num);

	if(conversion != 11110101)
		result = false;
	return result;
}
bool HexToDec328()
{
	bool result = true;
	int conversion = 0;
	std::string s = "148";

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->HexToDecimal(s);

	if(conversion != 328)
		result = false;
	return result;
}
bool HexToDec18()
{
	bool result = true;
	int conversion = 0;
	std::string s = "12";

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->HexToDecimal(s);

	if(conversion != 18)
		result = false;
	return result;
}
bool DecToHex84()
{
	bool result = true;
	int num = 84;
	std::string conversion = "";

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance("");
	conversion = calc->DecimalToHex(num);

	if(conversion != "54")
		result = false;
	return result;
}
bool DecToHex99()
{
	bool result = true;
	int num = 99;
	std::string conversion = "";

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance("");
	conversion = calc->DecimalToHex(num);

	if (conversion != "63")
		result = false;
	return result;
}
bool BinToHex200()
{
	bool result = true;
	int num = 11001000;
	std::string conversion = "";

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance("");
	conversion = calc->BinToHex(num);

	if(conversion != "c8")
		result = false;
	return result;
}
bool HexToBin408()
{
	bool result = true;
	int conversion = 0;
	std::string s = "198";

	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	conversion = calc->HexToBinary(s);

	if (conversion != 110011000)
		result = false;
	return result;
}
