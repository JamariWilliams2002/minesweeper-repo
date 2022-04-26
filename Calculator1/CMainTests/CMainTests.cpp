#include <iostream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS 
#include "CalculatorProcessorTests.h"
int main()
{

#pragma region Calculator Processor
	std::cout << "Calculator Processor: " << std::endl;
	std::cout << "----------------------" << std::endl;
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

	if (DecToBin245())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (HexToDec328())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (HexToDec18())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (DecToHex84())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (DecToHex99())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (BinToHex200())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;

	if (HexToBin408())
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;
#pragma endregion

}