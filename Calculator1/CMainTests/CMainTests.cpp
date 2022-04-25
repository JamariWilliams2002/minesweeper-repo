#include <iostream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 
#include "CalculatorProcessorTests.h"
int main()
{

#pragma region Calculator Processor
	if (BinToDec11())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (BinToDec138())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (DecToBin42())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;
#pragma endregion

}