#pragma once
#include <string>
#include <queue>
#include"wx/wx.h"
class JammyParser
{
public:
	JammyParser();
	~JammyParser();
	int Interpret(std::string expression);
	int Interpret(wxString expression);
private:
	enum Operators
	{
		Multiply = 1,
		Divide,
		Modulus,
		Addition,
		Subtraction
	};
	
	std::priority_queue<Operators> ops;
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
	int RecursiveDescent(int tempResult = INT32_MAX);

	std::vector<char>::iterator CheckMultiply();
	std::vector<char>::iterator CheckDivide();
	std::vector<char>::iterator CheckModulus();


};

