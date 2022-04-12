#include "CMain.h"

wxBEGIN_EVENT_TABLE(CMain, wxFrame)

wxEND_EVENT_TABLE();


//main window stuff
const int CAL_POINT_X = 30;
const int CAL_POINT_Y = 30;
const int CAL_SIZE_WIDTH = 700;
const int CAL_SIZE_HEIGHT = 900;

CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's Calculator", wxPoint(CAL_POINT_X, CAL_POINT_Y), wxSize(CAL_SIZE_WIDTH, CAL_SIZE_HEIGHT))
{
#pragma region Convenience Variables
	//display
	int displayPointBuffer = 10;
	int displayPointX = CAL_POINT_X - displayPointBuffer;
	int displayPointY = CAL_POINT_Y - displayPointBuffer;
	int displaySizeX = CAL_SIZE_WIDTH - 50;
	int displaySizeY = 200;

	//buttons
	int displayFirstButtonBuffer = 20;
	int betweenButtonBuffer = 5;
	int firstButtonY = ((displaySizeY + displayPointY) + displayFirstButtonBuffer);
	int buttonSizeX;
	wxSize buttonSize((displaySizeX / 7) - betweenButtonBuffer, 50);
#pragma endregion
	calDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(displayPointX, displayPointY), wxSize(displaySizeX, displaySizeY));
	//btn = new wxButton(this, wxID_ANY, "this is a button", wxPoint(displayPointX, firstButtonY), wxSize((displaySizeX / 4) - betweenButtonBuffer, 50));

	//wxGridSizer* calGrid = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);
	calButtons = new wxButton * [fieldWidth * fieldHeight];

	int x = displayPointX;
	int y = firstButtonY;
	for (int row = 0; row < fieldWidth - 1; row++)
	{
		
		for (int col = 0; col < fieldHeight; col++)
		{
			//create button, add to grid
			int currentButton = col * fieldWidth + row;
			int buttonID = 1000 + currentButton;
			calButtons[currentButton] = new wxButton(this, wxID_ANY, "this is a button", wxPoint(x, y), buttonSize);
			//calGrid->Add(calButtons[currentButton], 1, wxEXPAND | wxALL);

			//next col
			y += firstButtonY + betweenButtonBuffer;
		}
		//next row
		x += displayPointX + betweenButtonBuffer + buttonSize.x;
		y = firstButtonY;
	}

	//for (int i = 0; i < numButtons; i++)
	//{
	//	//specs for each button
	//}
	FillButtonText();

	//set the grid
	//this->SetSizer(calGrid);
	//calGrid->Layout();
}

void CMain::FillButtonText()
{

}

CMain::~CMain()
{
	delete[] calButtons;
}
