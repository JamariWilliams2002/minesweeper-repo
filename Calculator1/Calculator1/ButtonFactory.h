#pragma once
#include "wx/wx.h"
class CalculatorButtonFactory
{
private:
	
public:
	//constructors
	CalculatorButtonFactory();
	~CalculatorButtonFactory();


#pragma region Button Functions
	//numpad
	wxButton* Button1();
	wxButton* Button2();
	wxButton* Button3();
	wxButton* Button4();
	wxButton* Button5();
	wxButton* Button6();
	wxButton* Button7();
	wxButton* Button8();
	wxButton* Button9();
	wxButton* Button0();
	//arithmetic
	wxButton* ButtonAdd();
	wxButton* ButtonSubtract();
	wxButton* ButtonMultiply();
	wxButton* ButtonDivide();
	wxButton* ButtonModulus();
	//bin/hex/dec
	wxButton* ButtonBinary();
	wxButton* ButtonDecimal();
	wxButton* ButtonHexadecimal();
	//hex buttons
	wxButton* ButtonHexA();
	wxButton* ButtonHexB();
	wxButton* ButtonHexC();
	wxButton* ButtonHexD();
	wxButton* ButtonHexE();
	wxButton* ButtonHexF();
	//miscellaneus
	wxButton* ButtonPlusMinus();
	wxButton* ButtonEquals();
	wxButton* ButtonDecimalPoint();
	wxButton* ButtonDelete();
	wxButton* ButtonClear();

#pragma endregion


	wxButton* CreateButton(wxWindow* mainWindow, int buttonID, wxPoint buttonPos, wxSize buttonSize);
};

