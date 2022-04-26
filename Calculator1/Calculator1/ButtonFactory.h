#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "wx/wx.h"

class CalculatorButtonFactory
{
private:
	wxWindow* mMainWindow;
	wxButton** mCalButtons;
	int mFieldRows;
	int mFieldCols;
	//garbage code, don't use
	void GenerateButtonGrid(wxSize buttonSize, int xPos, int yPos);
public:
	//constructors
	CalculatorButtonFactory(wxWindow* mainWindow, wxButton** calButtons, int fieldRows, int fieldCols);
	CalculatorButtonFactory(wxWindow* mainWindow);
	CalculatorButtonFactory();
	~CalculatorButtonFactory();
	wxButton* CreateButton(int buttonID, wxPoint buttonPos, wxSize buttonSize, wxString text = "this is a button");

//private:
#pragma region Button Functions
	//numpad
	wxButton* Button1(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button2(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button3(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button3();

	wxButton* Button4(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button5(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button6(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button7(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button8(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button9(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* Button0(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	//arithmetic
	wxButton* ButtonAdd(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonSubtract(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonSubtract();
	wxButton* ButtonMultiply(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonMultiply();
	wxButton* ButtonDivide(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonModulus(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonModulus();
	//bin/hex/dec
	wxButton* ButtonBinary(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonBinary();
	wxButton* ButtonDecimal(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonHexadecimal(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	//hex buttons
	wxButton* ButtonHexA(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonHexA();
	wxButton* ButtonHexB(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonHexC(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonHexD(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonHexE(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonHexF(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	//miscellaneous
	wxButton* ButtonPlusMinus(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonEquals(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonDecimalPoint(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonDelete(int buttonID, wxPoint buttonPos, wxSize buttonSize);
	wxButton* ButtonClear(int buttonID, wxPoint buttonPos, wxSize buttonSize);
#pragma endregion

};
