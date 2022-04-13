#include "CMain.h"

wxBEGIN_EVENT_TABLE(CMain, wxFrame)
EVT_BUTTON(1001, OnClickNumbers)
wxEND_EVENT_TABLE();


//main window stuff
const int CAL_POINT_X = 30;
const int CAL_POINT_Y = 30;
const int CAL_SIZE_WIDTH = 700;
const int CAL_SIZE_HEIGHT = 700;

CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's Calculator", wxPoint(CAL_POINT_X, CAL_POINT_Y), wxSize(CAL_SIZE_WIDTH, CAL_SIZE_HEIGHT))
{
	//display & buttons
	GenerateDisplay();
	GenerateButtons();
	ButtonSpecs();

	//set the grid
	//this->SetSizer(calGrid);
	//calGrid->Layout();
}

void CMain::GenerateDisplay()
{
	calDisplay = new wxTextCtrl(this, wxID_ANY, "", wxPoint(CAL_POINT_X - displayPointBuffer, CAL_POINT_Y - displayPointBuffer), wxSize(650, 200), wxTE_READONLY);
	displayPoint = wxPoint(CAL_POINT_X - displayPointBuffer, CAL_POINT_Y - displayPointBuffer);
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
	//grab default color
	defaultButtonColor = calButtons[0, 0]->GetBackgroundColour();

	//main numbers 0-9
	calButtons[GetButtonIndex(0, 2)]->SetLabel("7");
	calButtons[GetButtonIndex(0, 3)]->SetLabel("8");
	calButtons[GetButtonIndex(0, 4)]->SetLabel("9");
	calButtons[GetButtonIndex(1, 2)]->SetLabel("4");
	calButtons[GetButtonIndex(1, 3)]->SetLabel("5");
	calButtons[GetButtonIndex(1, 4)]->SetLabel("6");
	calButtons[GetButtonIndex(2, 2)]->SetLabel("1");
	calButtons[GetButtonIndex(2, 3)]->SetLabel("2");
	calButtons[GetButtonIndex(2, 4)]->SetLabel("3");
	calButtons[GetButtonIndex(3, 3)]->SetLabel("0");
	//zero specs
	calButtons[GetButtonIndex(3, 3)]->SetBackgroundColour((*wxLIGHT_GREY));
	calButtons[GetButtonIndex(3, 3)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickNumbers, this);
	//all other number specs
	for (int rows = 0; rows <= 2; rows++)
	{
		for (int cols = 2; cols <= 4; cols++)
		{
			calButtons[GetButtonIndex(rows, cols)]->SetBackgroundColour((*wxLIGHT_GREY));
			calButtons[GetButtonIndex(rows, cols)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickNumbers, this);
		}
	}
	//arithmetic
	calButtons[GetButtonIndex(3, 5)]->SetLabel("+");
	calButtons[GetButtonIndex(2, 5)]->SetLabel("-");
	calButtons[GetButtonIndex(2, 6)]->SetLabel("/");
	calButtons[GetButtonIndex(1, 5)]->SetLabel("%");
	calButtons[GetButtonIndex(1, 6)]->SetLabel("X");
	for (int rows = 1; rows <= 3; rows++)
	{
		for (int cols = 5; cols <= 6; cols++)
		{
			calButtons[GetButtonIndex(rows, cols)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickArithmetic, this);
		}
	}

	//bin/hex/dec
	calButtons[GetButtonIndex(1, 1)]->SetLabel("bin");
	calButtons[GetButtonIndex(2, 1)]->SetLabel("dec");
	calButtons[GetButtonIndex(3, 1)]->SetLabel("hex");
	for (int row = 1; row <= 3; row++)
		calButtons[GetButtonIndex(row, 1)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickBinHexDec, this);
	//dec is on by default
	calButtons[GetButtonIndex(2, 1)]->SetBackgroundColour(*wxCYAN);



	//hex buttons
	calButtons[GetButtonIndex(4, 0)]->SetLabel("A");
	calButtons[GetButtonIndex(3, 0)]->SetLabel("B");
	calButtons[GetButtonIndex(2, 0)]->SetLabel("C");
	calButtons[GetButtonIndex(1, 0)]->SetLabel("D");
	calButtons[GetButtonIndex(0, 0)]->SetLabel("E");
	calButtons[GetButtonIndex(0, 1)]->SetLabel("F");


	//misc
	calButtons[GetButtonIndex(3, 2)]->SetLabel("+/-");
	calButtons[GetButtonIndex(3, 2)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickMisc, this);


	calButtons[GetButtonIndex(3, 6)]->SetLabel("=");
	calButtons[GetButtonIndex(3, 6)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickMisc, this);

	calButtons[GetButtonIndex(3, 4)]->SetLabel(".");
	calButtons[GetButtonIndex(3, 4)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickMisc, this);

	calButtons[GetButtonIndex(0, 5)]->SetLabel("del");
	calButtons[GetButtonIndex(0, 6)]->SetLabel("clear");
	calButtons[GetButtonIndex(0, 6)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickMisc, this);


}

void CMain::OnClickNumbers(wxCommandEvent& evt)
{
	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);
	wxString label = calButtons[buttonIndex]->GetLabel();

	//find the row and column
	if (arithmeticClick)
		onNextNum = true;
	
		if (onNextNum)
		{
			nextNumStr = nextNumStr + label;
			nextNumFl = wxAtof(nextNumStr);
		}
		else
		{
			prevNumStr = prevNumStr + label;
			prevNumFl = wxAtof(prevNumStr);
		}

	if (!equalsClicked)
		calDisplay->AppendText(label);
	else
	{
		calDisplay->SetLabelText(label);
		equalsClicked = false;
	}
	//update prevNum

}

void CMain::OnClickBinHexDec(wxCommandEvent& evt)
{
	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);

	if (calButtons[buttonIndex]->GetLabel() == "bin")
	{
		isBin = !isBin;
		isHex = false;
		calButtons[GetButtonIndex(3, 1)]->SetBackgroundColour(defaultButtonColor); //hex
		isDec = false;
		calButtons[GetButtonIndex(2, 1)]->SetBackgroundColour(defaultButtonColor); //dec

	}
	else if (calButtons[buttonIndex]->GetLabel() == "dec")
	{
		isDec = !isDec;
		isBin = false;
		calButtons[GetButtonIndex(1, 1)]->SetBackgroundColour(defaultButtonColor); //binary
		isHex = false;
		calButtons[GetButtonIndex(3, 1)]->SetBackgroundColour(defaultButtonColor); //hex
	}
	else if (calButtons[buttonIndex]->GetLabel() == "hex")
	{
		isHex = !isHex;
		isBin = false;
		calButtons[GetButtonIndex(1, 1)]->SetBackgroundColour(defaultButtonColor); //binary
		isDec = false;
		calButtons[GetButtonIndex(2, 1)]->SetBackgroundColour(defaultButtonColor); //dec

	}
	calButtons[buttonIndex]->SetBackgroundColour(*wxCYAN);
}

void CMain::OnClickArithmetic(wxCommandEvent& evt)
{
	if (prevNumStr == "")
		return;
	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);
	wxString label = calButtons[buttonIndex]->GetLabel();
	//if (prevNumStr == "" && tempResult == textEmpty)

	arithmeticClick = true;
	clickedAction = label;

	//calButtons[buttonIndex]->SetBackgroundColour(*wxCYAN);

	calDisplay->AppendText(" " + label + " ");

}

void CMain::OnClickMisc(wxCommandEvent& evt)
{
	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);

	float numResult = 0;
	wxString strResult;
	if (calButtons[buttonIndex]->GetLabel() == "=")
	{
		if (arithmeticClick)
		{
			//actual operation
			if (clickedAction == "+")
				numResult = prevNumFl + nextNumFl;
			else if (clickedAction == "-")
				numResult = prevNumFl - nextNumFl;
			else if (clickedAction == "X")
				numResult = prevNumFl * nextNumFl;
			else if (clickedAction == "/")
				numResult = prevNumFl / nextNumFl;
			else if (clickedAction == "%")
				numResult = (int)prevNumFl % (int)nextNumFl;

			strResult = wxString::Format(wxT("%f"), numResult);
			calDisplay->SetLabelText(strResult);

			//setting flags and resetting
			tempResult = strResult;
			arithmeticClick = false;
			equalsClicked = true;
			onNextNum = false;
			ResetPrevAndNextNum();
		}
	}
	else if (calButtons[buttonIndex]->GetLabel() == "clear")
	{
		calDisplay->SetLabelText("");
		ResetPrevAndNextNum();
		ResetArithmetic();
	}
	else if (calButtons[buttonIndex]->GetLabel() == "+/-")
	{
		if (onNextNum)
		{
			nextNumFl = -nextNumFl;
			nextNumStr = wxString::Format(wxT("%f"), nextNumFl);
			calDisplay->SetLabelText(nextNumStr);
		}
		else
		{
			prevNumFl = -prevNumFl;
			prevNumStr = wxString::Format(wxT("%f"), prevNumFl);
			calDisplay->SetLabelText(prevNumStr);
		}
	}
	else if (calButtons[buttonIndex]->GetLabel() == ".")
	{
		decimalPointClicked = true;
		if (onNextNum)
		{
			nextNumStr = nextNumStr + ".";
			calDisplay->SetLabelText(nextNumStr);
		}
		else
		{
			prevNumStr = prevNumStr + ".";
			calDisplay->SetLabelText(prevNumStr);
		}
	}
}

void CMain::ResetArithmetic()
{
	arithmeticClick = false;
	clickedAction = "";
}

void CMain::ResetPrevAndNextNum()
{
	prevNumFl = 0.0f;
	prevNumStr = "";
	nextNumFl = 0.0f;
	nextNumStr = "";
	onNextNum = false;
}

CMain::~CMain()
{
	delete[] calButtons;
}
