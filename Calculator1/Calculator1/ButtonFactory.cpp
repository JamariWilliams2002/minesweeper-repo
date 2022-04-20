#include "ButtonFactory.h"
CalculatorButtonFactory::CalculatorButtonFactory(wxWindow* mainWindow, wxButton** calButtons, int fieldRows, int fieldCols)
{
	mMainWindow = mainWindow;
	mCalButtons = calButtons;	
	mFieldCols = fieldCols;
	mFieldRows = fieldRows;
}

CalculatorButtonFactory::~CalculatorButtonFactory()
{

}

void CalculatorButtonFactory::GenerateButtonGrid(wxSize buttonSize, int xPos, int yPos)
{
	//create button pos
	wxPoint buttonPos(xPos, yPos);

	mCalButtons = new wxButton * [mFieldRows * mFieldCols];
	
	for (int row = 0; row < mFieldRows; row++)
	{
		for (int col = 0; col < mFieldCols; col++)
		{
			int currentButton = col * mFieldRows+ row;
			int buttonID = 1000 + currentButton;
			wxButton* button;
			//button creation
			if (true) // 0 button
				button = Button0(buttonID, buttonPos, buttonSize);
			mCalButtons[currentButton] = button;
		}
	}
}

#pragma region Numpad
wxButton* CalculatorButtonFactory::CreateButton(int buttonID, wxPoint buttonPos, wxSize buttonSize, wxString text)
{
	return new wxButton(mMainWindow, buttonID, text, buttonPos, buttonSize);
}

wxButton* CalculatorButtonFactory::Button1(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "1");
}
wxButton* CalculatorButtonFactory::Button2(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "2");
}
wxButton* CalculatorButtonFactory::Button3(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "3");
}
wxButton* CalculatorButtonFactory::Button4(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "4");
}
wxButton* CalculatorButtonFactory::Button5(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "5");
}
wxButton* CalculatorButtonFactory::Button6(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "6");
}
wxButton* CalculatorButtonFactory::Button7(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "7");
}
wxButton* CalculatorButtonFactory::Button8(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "8");
}
wxButton* CalculatorButtonFactory::Button9(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "9");
}
wxButton* CalculatorButtonFactory::Button0(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "0");
}
#pragma endregion

#pragma region Arithmetic
wxButton* CalculatorButtonFactory::ButtonAdd(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "+");
}
wxButton* CalculatorButtonFactory::ButtonSubtract(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "-");
}
wxButton* CalculatorButtonFactory::ButtonMultiply(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "*");
}
wxButton* CalculatorButtonFactory::ButtonDivide(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "/");
}
wxButton* CalculatorButtonFactory::ButtonModulus(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "%");
}

#pragma endregion

#pragma region Bin/Hex/Dec

wxButton* CalculatorButtonFactory::ButtonBinary(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "bin");
}
wxButton* CalculatorButtonFactory::ButtonDecimal(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "dec");
}
wxButton* CalculatorButtonFactory::ButtonHexadecimal(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "hex");
}
#pragma endregion

#pragma region Hex Buttons
wxButton* CalculatorButtonFactory::ButtonHexA(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "A");
}
wxButton* CalculatorButtonFactory::ButtonHexB(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "B");
}
wxButton* CalculatorButtonFactory::ButtonHexC(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "C");
}
wxButton* CalculatorButtonFactory::ButtonHexD(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "D");
}
wxButton* CalculatorButtonFactory::ButtonHexE(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "E");
}
wxButton* CalculatorButtonFactory::ButtonHexF(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "F");
}
#pragma endregion

#pragma region miscellaneous
wxButton* CalculatorButtonFactory::ButtonPlusMinus(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "+/-");
}
wxButton* CalculatorButtonFactory::ButtonEquals(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "=");
}
wxButton* CalculatorButtonFactory::ButtonDecimalPoint(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, ".");
}
wxButton* CalculatorButtonFactory::ButtonDelete(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "del");
}
wxButton* CalculatorButtonFactory::ButtonClear(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	return CreateButton(buttonID, buttonPos, buttonSize, "clear");
}
#pragma endregion