#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <string>
#include"wx/wx.h"
class JammyParser
{
public:
	JammyParser();
	~JammyParser();
	int Interpret(const char* equation);
private:
    const char* expressionToParse;

    char peek();
    char get();
    int expression();
    int number();
    int factor();
    int term();

};

