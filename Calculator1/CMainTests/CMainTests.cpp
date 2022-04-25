#include <iostream>
#define _CRT_SECURE_NO_WARNINGS 
#include "CalculatorProcessorTests.h"
int main()
{
	if (BinToDec5())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;
}