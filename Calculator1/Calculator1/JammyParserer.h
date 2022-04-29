#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <string>
#include"wx/wx.h"
class JammyParser
{
public:
	JammyParser();
	~JammyParser();
	void Interpret(std::string expression);
	void Interpret(wxString expression);
	std::vector<double> nums;
	std::vector<char> operations;
	std::vector<int> operationPrecedence;
private:
	bool IsOperator(char c);
	bool IsNumber(char c);
	int GetPrecedence(char c);
	int GetNumberFromChar(char c);
	void OrganizeVectors();
	void SwapOperators(int index);
	void SwapNumbers(int index);
	int Evaluate(int num1, int num2, char op);



};

