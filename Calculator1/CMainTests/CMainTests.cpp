#include <iostream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 
#include "CalculatorProcessorTests.h"

void TestCheck(bool(*func)());
int main()
{

#pragma region Calculator Processor
	const int arrSize = 10;
	bool (*calcProcessorArr[arrSize])() {
		&BinToDec11, &BinToDec138, &DecToBin42, &DecToBin245,
		&HexToDec328, &HexToDec18, &DecToHex84, &DecToHex99, &BinToHex200, &HexToBin408
	};
	bool (*buttonFactoryArr[arrSize])() {
	
	
	};
	

	std::cout << "Calculator Processor: " << std::endl;
	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < arrSize; i++)
		TestCheck(calcProcessorArr[i]);


#pragma endregion

#pragma region Button Factory

#pragma endregion

}

void TestCheck(bool(*func)())
{
	if (func)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;
}

