#include "CMain.h"

wxBEGIN_EVENT_TABLE(CMain, wxFrame)
EVT_BUTTON(1001, OnButtonClick)
wxEND_EVENT_TABLE()


CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's MineSweeper", wxPoint(30, 30), wxSize(800, 800))
{
	btn = new wxButton * [fieldWidth * fieldHeight];
	wxGridSizer* grid = new wxGridSizer(fieldWidth, fieldHeight, 0, 0);
	field = new int [fieldWidth * fieldHeight];
	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int row = 0; row < fieldWidth; row++)
	{
		for (int col = 0; col < fieldHeight; col++)
		{
			int currentButton = col * fieldWidth + row;
			btn[currentButton] = new wxButton(this, 1000 + (currentButton));
			btn[currentButton]->SetFont(font);
			grid->Add(btn[currentButton], 1, wxEXPAND | wxALL);
			btn[currentButton]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnButtonClick, this);
			field[currentButton] = 0;
		}
	}

	this->SetSizer(grid);
	grid->Layout();

}

CMain::~CMain()
{
	delete[] btn;
	delete[] field;
}

void CMain::OnButtonClick(wxCommandEvent& evt)
{
	int row = (evt.GetId() - 1000) % fieldWidth;
	int col = (evt.GetId() - 1000) / fieldHeight;
	int currentButton = col * fieldWidth + row;
	int isMine = -1;
	//populate mines
	if (firstClick)
	{
		int mines = 30;
		while (mines != 0)
		{
			int rx = rand() % fieldWidth;
			int ry = rand() % fieldHeight;
			int buttonCheck = ry * fieldWidth + rx;

			if (field[buttonCheck] == 0 && rx != row && ry != col)
			{
				field[buttonCheck] = isMine;
				mines--;
			}
		}
	}
	firstClick = false;

	//disable button from being clicked again
	btn[currentButton]->Enable(false);
	//check for mine
	if (field[currentButton] == isMine)
	{
		wxMessageBox("BOOM!!! Game Over!!");
		firstClick = true;
		for (int forRow = 0; forRow < fieldWidth; forRow++)
		{
			for (int forCol = 0; forCol < fieldHeight; forCol++)
			{
				int checkButton = forCol * fieldWidth + forRow;
				field[checkButton] = 0; 
				btn[checkButton]->SetLabel("");
				btn[checkButton]->Enable(true);
			}
		}
	}
	else //no mine
	{
		//count neighbors
		int mineCount = 0;
		bool needMine = true;
		for (int i = -1;  i < 2;  i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (row + i >= 0 && row + i < fieldWidth && col + j >= 0 && col + j < fieldHeight)
				{
					if (field[(col + j) * fieldWidth + (row + i)] == isMine)
						mineCount++;
				}
			}
		}

		//update button labels
		if (mineCount > 0)
			btn[currentButton]->SetLabel(std::to_string(mineCount));
	}
}