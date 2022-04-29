#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <string>
#include"wx/wx.h"
class JammyParser
{
public:
	JammyParser();
	~JammyParser();
	int Interpret(std::string expression);
	int Interpret(wxString expression);
private:
	std::vector<double> nums;
	std::vector<char> operations;
	std::vector<int> operationPrecedence;
	//helper variables
	int prec1;
	int prec2;

	bool IsOperator(char c);
	bool IsNumber(char c);
	int GetPrecedence(char c);
	int GetNumberFromChar(char c);
	void OrganizeVectors();
	void SwapOperators(int index);
	void SwapNumbers(int index);
	int Evaluate(int num1, int num2, char op);

	std::vector<char>::iterator CheckMultiply();
	std::vector<char>::iterator CheckDivide();
	std::vector<char>::iterator CheckModulus();


};

