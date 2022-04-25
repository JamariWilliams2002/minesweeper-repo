#include "../Calculator1/CalculatorProcessor.h"
#include "../Calculator1/BinHexDecConversion.h"
bool BinToDec5()
{
	int binNum = 1011;
	std::string s = std::to_string(binNum);
	CalculatorProcessor* calc = &CalculatorProcessor::GetInstance(s);
	calc->BinaryToDecimal(binNum);

	bool result = false;
	return result;
}