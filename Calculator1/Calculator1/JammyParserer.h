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
private:
	bool IsOperator(char c);
	bool IsNumber(char c);
	int GetPrecedence(char c);
	int GetNumberFromChar(char c);

};

