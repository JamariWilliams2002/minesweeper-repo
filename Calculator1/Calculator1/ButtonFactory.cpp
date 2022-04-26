#include "ButtonFactory.h"
CalculatorButtonFactory::CalculatorButtonFactory(wxWindow* mainWindow, wxButton** calButtons, int fieldRows, int fieldCols)
{
	mMainWindow = mainWindow;
	mCalButtons = calButtons;
	mFieldRows = fieldRows;
	mFieldCols = fieldCols;
}

CalculatorButtonFactory::CalculatorButtonFactory(wxWindow* window)
{
	mMainWindow = window;
}

//destructor
CalculatorButtonFactory::CalculatorButtonFactory()
{

}

//destructor
CalculatorButtonFactory::~CalculatorButtonFactory()
{
	ClearMemory();
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
			int currentButton = col * mFieldRows + row;
			int buttonID = 1000 + currentButton;
			wxButton* button;
#pragma region Ifs for Button Creation
			//numpad
			if (row == 0 && col == 2) // 7 button
				button = Button7(buttonID, buttonPos, buttonSize);
			else if (row == 0 && col == 3) //8 button
				button = Button8(buttonID, buttonPos, buttonSize);
			else if (row == 0 && col == 4) //9 button
				button = Button9(buttonID, buttonPos, buttonSize);
			else if (row == 1 && col == 2) //4 button
				button = Button4(buttonID, buttonPos, buttonSize);
			else if (row == 1 && col == 3) //5 button
				button = Button5(buttonID, buttonPos, buttonSize);
			else if (row == 1 && col == 4) //6 button
				button = Button6(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 2) //1 button
				button = Button1(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 3) //2 button
				button = Button2(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 4) //3 button
				button = Button3(buttonID, buttonPos, buttonSize);
			else if (row == 3 && col == 3) //0 button
				button = Button0(buttonID, buttonPos, buttonSize);
			//arithmetic
			else if (row == 3 && col == 5)
				button = ButtonAdd(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 5)
				button = ButtonSubtract(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 6)
				button = ButtonDivide(buttonID, buttonPos, buttonSize);
			else if (row == 1 && col == 5)
				button = ButtonModulus(buttonID, buttonPos, buttonSize);
			else if (row == 1 && col == 6)
				button = ButtonMultiply(buttonID, buttonPos, buttonSize);
			//binhexdec
			else if (row == 1 && col == 1)
				button = ButtonBinary(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 1)
				button = ButtonDecimal(buttonID, buttonPos, buttonSize);
			else if (row == 3 && col == 5)
				button = ButtonHexadecimal(buttonID, buttonPos, buttonSize);
			//hex buttons
			else if (row == 4 && col == 0)
				button = ButtonHexA(buttonID, buttonPos, buttonSize);
			else if (row == 3 && col == 0)
				button = ButtonHexB(buttonID, buttonPos, buttonSize);
			else if (row == 2 && col == 0)
				button = ButtonHexC(buttonID, buttonPos, buttonSize);
			else if (row == 1 && col == 0)
				button = ButtonHexD(buttonID, buttonPos, buttonSize);
			else if (row == 0 && col == 0)
				button = ButtonHexE(buttonID, buttonPos, buttonSize);
			else if (row == 4 && col == 1)
				button = ButtonHexF(buttonID, buttonPos, buttonSize);
			//misc
			else if (row == 3 && col == 2)
				button = ButtonPlusMinus(buttonID, buttonPos, buttonSize);
			else if (row == 3 && col == 6)
				button = ButtonEquals(buttonID, buttonPos, buttonSize);
			else if (row == 3 && col == 4)
				button = ButtonDecimalPoint(buttonID, buttonPos, buttonSize);
			else if (row == 0 && col == 5)
				button = ButtonDelete(buttonID, buttonPos, buttonSize);
			else if (row == 0 && col == 6)
				button = ButtonClear(buttonID, buttonPos, buttonSize);
			else
				button = CreateButton(buttonID, buttonPos, buttonSize);
#pragma endregion
			mCalButtons[currentButton] = button;
			//change x, leave y
			buttonPos.x += (buttonSize.x + 5);
		}
		//reset x, change y
		buttonPos.x = xPos;
		buttonPos.y += buttonSize.y + 20;
	}
}

#pragma region Numpad
wxButton* CalculatorButtonFactory::CreateButton(int buttonID, wxPoint buttonPos, wxSize buttonSize, wxString text)
{
	wxButton* button = new wxButton(mMainWindow, buttonID, text, buttonPos, buttonSize);
	return button;
}

wxButton* CalculatorButtonFactory::Button1(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "1");
	return button;
}
wxButton* CalculatorButtonFactory::Button2(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "2");
	return button;
}
wxButton* CalculatorButtonFactory::Button3(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "3");
	return button;
}
wxButton* CalculatorButtonFactory::Button4(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "4");
	return button;
}
wxButton* CalculatorButtonFactory::Button5(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "5");
	return button;
}
wxButton* CalculatorButtonFactory::Button6(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "6");
	return button;
}
wxButton* CalculatorButtonFactory::Button7(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "7");
	return button;
}
wxButton* CalculatorButtonFactory::Button8(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "8");
	return button;
}
wxButton* CalculatorButtonFactory::Button9(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "9");
	return button;
}
wxButton* CalculatorButtonFactory::Button0(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "0");
	return button;
}
#pragma endregion

#pragma region Arithmetic
wxButton* CalculatorButtonFactory::ButtonAdd(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "+");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonSubtract(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "-");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonMultiply(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "*");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonDivide(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "/");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonModulus(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "%");
	return button;
}

#pragma endregion

#pragma region Bin/Hex/Dec

wxButton* CalculatorButtonFactory::ButtonBinary(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "bin");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonDecimal(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "dec");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonHexadecimal(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "hex");
	return button;
}
#pragma endregion

#pragma region Hex Buttons
wxButton* CalculatorButtonFactory::ButtonHexA(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "A");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonHexB(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "B");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonHexC(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "C");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonHexD(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "D");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonHexE(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "E");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonHexF(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "F");
	return button;
}
#pragma endregion

#pragma region Miscellaneous
wxButton* CalculatorButtonFactory::ButtonPlusMinus(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "+/-");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonEquals(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "=");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonDecimalPoint(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, ".");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonDelete(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "del");
	return button;
}
wxButton* CalculatorButtonFactory::ButtonClear(int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = CreateButton(buttonID, buttonPos, buttonSize, "clear");
	return button;
}
#pragma endregion

#pragma region For Tests Lab
wxButton* CalculatorButtonFactory::Button3()
{
	int buttonID = '3'; //ascii code
	wxPoint p(3, 3);
	wxSize a(3, 3);
	wxWindow* window = new wxWindow();
	windowV.push_back(window);

	wxButton* button = new wxButton(window, buttonID, "3", p, a);
	button->SetLabel("3");
	button->SetBackgroundColour((*wxLIGHT_GREY));


	return button;
}

wxButton* CalculatorButtonFactory::ButtonMultiply()
{
	int buttonID = '*'; //ascii code
	wxPoint p(3, 3);
	wxSize a(3, 3);

	wxWindow* window = new wxWindow();
	windowV.push_back(window);

	wxButton* button = new wxButton(window, buttonID, "*", p, a);
	button->SetLabel("*");
	return button;
}

wxButton* CalculatorButtonFactory::ButtonBinary()
{
	int buttonID = 'b'; //ascii code
	wxPoint p(3, 3);
	wxSize a(3, 3);

	wxWindow* window = new wxWindow();
	windowV.push_back(window);

	wxButton* button = new wxButton(window, buttonID, "", p, a);
	button->SetLabel("bin");
	return button;
}

wxButton* CalculatorButtonFactory::ButtonModulus()
{
	int buttonID = '%'; //ascii code
	wxPoint p(3, 3);
	wxSize a(3, 3);

	wxWindow* window = new wxWindow();
	windowV.push_back(window);

	wxButton* button = new wxButton(window, buttonID, "*", p, a);
	button->SetLabel("%");
	return button;
}

wxButton* CalculatorButtonFactory::ButtonSubtract()
{
	int buttonID = '-'; //ascii code
	wxPoint p(3, 3);
	wxSize a(3, 3);

	wxWindow* window = new wxWindow();
	windowV.push_back(window);

	wxButton* button = new wxButton(window, buttonID, "", p, a);
	button->SetLabel("-");
	button->SetBackgroundColour((*wxLIGHT_GREY));

	return button;
}

wxButton* CalculatorButtonFactory::ButtonHexA()
{
	int buttonID = 'A'; //ascii code
	wxPoint p(3, 3);
	wxSize a(3, 3);

	wxWindow* window = new wxWindow();
	windowV.push_back(window);

	wxButton* button = new wxButton(window, buttonID, "", p, a);
	button->SetLabel("A");
	return button;
}
#pragma endregion

void CalculatorButtonFactory::ClearMemory()
{
	for (int i = 0; i < windowV.size(); i++)
		delete windowV[i];
	windowV.clear();
}

