#pragma once
#include "wx/wx.h"
class IBaseCommand
{
public:
	virtual wxString Execute() = 0;
};

class AddCommand : public IBaseCommand
{
public:
	//default
	AddCommand()
	{
		
	}
	wxString Execute()
	{
		return " + ";
	}
};

//class SubtractCommand: public IBaseCommand
//{
//public:
//	SubtractCommand(double num1, double num2)
//	{
//		mNum1 = num1;
//		mNum2 = num2;
//	}
//	double Execute(bool isFirstNum)
//	{
//		return mNum1 - mNum2;
//	}
//};
//
//class MultiplyCommand: public IBaseCommand
//{
//	public:
//	MultiplyCommand(double num1, double num2)
//	{
//		mNum1 = num1;
//		mNum2 = num2;
//	}
//	double Execute(bool isFirstNum)
//	{
//		return mNum1 * mNum2;
//	}
//};
//
//class DivideCommand : public IBaseCommand
//{
//	public:
//	DivideCommand(double num1, double num2)
//	{
//		mNum1 = num1;
//		mNum2 = num2;
//	}
//	double Execute(bool isFirstNum)
//	{
//		return mNum1 / mNum2;
//	}
//};
//
//class ModulusCommand : public IBaseCommand
//{
//	public:
//	ModulusCommand(double num1, double num2)
//	{
//		mNum1 = num1;
//		mNum2 = num2;
//	}
//	double Execute(bool isFirstNum)
//	{
//		return (int)mNum1 % (int)mNum2;
//	}
//};