#include <iostream>
#include <windows.h>
#include "CalculatorProcessorTests.h"
#include "ButtonFactoryTests.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define MEMORY_LEAK_LINE 3818

void TestCheck(bool(*func)());
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	_CrtDumpMemoryLeaks();
	_CrtSetBreakAlloc(MEMORY_LEAK_LINE); // DO NOT COMMENT OUT THIS LINE

#pragma region Calculator Processor
	const int arrSize = 10;
	bool (*calcProcessorArr[arrSize])() {
		&BinToDec11, &BinToDec138, &DecToBin42, &DecToBin245,
		&HexToDec328, &HexToDec18, &DecToHex84, &DecToHex99, &BinToHex200, &HexToBin408
	};
	bool (*buttonFactoryArr[arrSize])() {
		&Button3LabelCheck, &Button3IDCheck, ButtonMultiplyIDCheck, ButtonMultiplyLabelCheck,
			&ButtonBinLabelCheck, &ButtonModulusLabelCheck, &ButtonSubtractColor,
			&Button3ColorDec, &ButtonSubtractIDCheck, &ButtonAIDCheck
	};
	

	std::cout << "Calculator Processor: " << std::endl;
	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < arrSize; i++)
	{
		std::cout << "Test " << i + 1 << " = ";
		TestCheck(calcProcessorArr[i]);
	}

#pragma endregion

#pragma region Button Factory

	std::cout << "\nButton Factory: " << std::endl;
	std::cout << "----------------------" << std::endl;

	for (int i = 0; i < arrSize; i++)
	{
		std::cout << "Test " << i + 1 << " = ";
		TestCheck(buttonFactoryArr[i]);
	}

#pragma endregion

}

void TestCheck(bool(*func)())
{
	if ((*func)() == true)
		std::cout << "Success" << std::endl;
	else
		std::cout << "Fail" << std::endl;
}

