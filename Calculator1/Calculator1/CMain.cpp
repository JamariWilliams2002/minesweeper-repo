#include "CMain.h"

wxBEGIN_EVENT_TABLE(CMain, wxFrame)

wxEND_EVENT_TABLE();


//main window stuff
const int CAL_POINT_X = 30;
const int CAL_POINT_Y = 30;
const int CAL_SIZE_WIDTH = 1200;
const int CAL_SIZE_HEIGHT = 800;

CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's Calculator", wxPoint(CAL_POINT_X, CAL_POINT_Y), wxSize(CAL_SIZE_WIDTH, CAL_SIZE_HEIGHT))
{
	wxGridSizer* calGrid = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);
	calButtons = new wxButton * [fieldWidth * fieldHeight];
	for (int row = 0; row < fieldWidth; row++)
	{
		for (int col = 0; col < fieldHeight; col++)
		{
			//create button, add to grid
			int currentButton = col * fieldWidth + row;
			int buttonID = 1000 + currentButton;
			calButtons[currentButton] = new wxButton(this, buttonID);
			calGrid->Add(calButtons[currentButton], 1, wxEXPAND | wxALL);
		}
	}

	//for (int i = 0; i < numButtons; i++)
	//{
	//	//specs for each button
	//}
	FillButtonText();

	//set the grid
	this->SetSizer(calGrid);
	calGrid->Layout();
}

void CMain::FillButtonText()
{

}

CMain::~CMain()
{
	delete[] calButtons;
}
