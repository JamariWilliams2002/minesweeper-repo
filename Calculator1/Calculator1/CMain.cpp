#include "CMain.h"

wxBEGIN_EVENT_TABLE(CMain, wxFrame)

wxEND_EVENT_TABLE();


//main window stuff
const int CAL_POINT_X = 30;
const int CAL_POINT_Y = 30;
const int CAL_SIZE_WIDTH = 700;
const int CAL_SIZE_HEIGHT = 700;

CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's Calculator", wxPoint(CAL_POINT_X, CAL_POINT_Y), wxSize(CAL_SIZE_WIDTH, CAL_SIZE_HEIGHT))
{
	//display & buttons

	calDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(CAL_POINT_X - displayPointBuffer, CAL_POINT_Y - displayPointBuffer), wxSize(650, 200));
	displayPoint = wxPoint(CAL_POINT_X - displayPointBuffer, CAL_POINT_Y - displayPointBuffer);
	
	GenerateButtons();
	ButtonSpecs();

	//set the grid
	//this->SetSizer(calGrid);
	//calGrid->Layout();
}

void CMain::GenerateButtons()
{
	//wxGridSizer* calGrid = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);
	calButtons = new wxButton * [fieldRows * fieldCols];

	//variables for loop
	wxSize buttonSize((calDisplay->GetSize().x / fieldCols) - betweenButtonBuffer, 50);
	int x = displayPoint.x;
	int y = displayPoint.y + calDisplay->GetSize().y + displayToButtonBuffer;
	wxPoint buttonPos(x, y);
	//buttonTest = new wxButton(this, wxID_ANY, "this is a button", buttonPos, buttonSize);

	for (int row = 0; row < fieldRows; row++)
	{
		for (int col = 0; col < fieldCols; col++)
		{
			//create button, add to grid
			int currentButton = col * fieldRows + row;
			int buttonID = 1000 + currentButton;
			calButtons[currentButton] = new wxButton(this, buttonID, "this is a button", buttonPos, buttonSize);
			//calGrid->Add(calButtons[currentButton], 1, wxEXPAND | wxALL);

			//change x, leave y
			buttonPos.x += (buttonSize.x + 5);
		}
		//reset x, change y
		buttonPos.x = x;
		buttonPos.y += buttonSize.y + 20;
	}
	ButtonSpecs();
}

int CMain::GetButtonIndex(int rows, int cols)
{
	return cols * fieldRows + rows;
}

void CMain::ButtonSpecs()
{
	//main numbers 0-9
	calButtons[GetButtonIndex(1, 2)]->SetLabel("7");
	calButtons[GetButtonIndex(1, 3)]->SetLabel("8");
	calButtons[GetButtonIndex(1, 4)]->SetLabel("9");
	calButtons[GetButtonIndex(2, 2)]->SetLabel("4");
	calButtons[GetButtonIndex(2, 3)]->SetLabel("5");
	calButtons[GetButtonIndex(2, 4)]->SetLabel("6");
	calButtons[GetButtonIndex(3, 2)]->SetLabel("1");
	calButtons[GetButtonIndex(3, 3)]->SetLabel("2");
	calButtons[GetButtonIndex(3, 4)]->SetLabel("3");
	
	//arithmetic
	calButtons[GetButtonIndex(3, 5)]->SetLabel("+");

}

CMain::~CMain()
{
	delete[] calButtons;
}
