#include "CMain.h"
#include <sstream>

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
	//since starting in decimal, disable buttons for hex
	ToggleButtonsForHex();
	
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

	//handle f
	calButtons[GetButtonIndex(0, 1)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickNumbers, this);

	//other letters
	for (int rows = 0; rows <= 4; rows++)
		calButtons[GetButtonIndex(rows, 0)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickNumbers, this);

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

int CMain::ConvertToBinary()
{
	int decimal, binary = 0, remainder, product = 1;
	if (onNextNum)
		decimal = (int)nextNumFl;
	else
		decimal = (int)prevNumFl;

	while (decimal != 0) {
		remainder = decimal % 2;
		binary = binary + (remainder * product);
		decimal = decimal / 2;
		product *= 10;
	}
	return binary;
}

int CMain::ConvertToBinary(int num)
{
	int decimal = num, binary = 0, remainder, product = 1;

	while (decimal != 0) {
		remainder = decimal % 2;
		binary = binary + (remainder * product);
		decimal = decimal / 2;
		product *= 10;
	}
	return binary;
}

std::string CMain::DecimalToHex(int num)
{
	std::stringstream ss;
	ss << std::hex << num; // int decimal_value
	std::string res(ss.str());
	return res;
}

int CMain::HexToDecimal(wxString hex)
{
	int result;
	std::stringstream ss;
	ss << hex;
	ss >> std::hex >> result;

	return result;
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
		if (isBin)
			ConvertToBinary();

		nextNumStr = nextNumStr + label;

		if (isDec || isBin)
			nextNumFl = wxAtof(nextNumStr);
	}
	else
	{
		if (isBin)
			ConvertToBinary();

		prevNumStr = prevNumStr + label;

		if (isDec || isBin)
			prevNumFl = wxAtof(prevNumStr);
	}

	if (!equalsClicked)
		calDisplay->AppendText(label);
	else
	{
		calDisplay->SetLabelText(label);
		equalsClicked = false;
	}

}

int CMain::BinaryToDecimal(int n)
{
	int num = n;
	int dec_value = 0;

	// Initializing base value to 1, i.e 2^0
	int base = 1;

	int temp = num;
	while (temp) {
		int last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

void CMain::OnClickBinHexDec(wxCommandEvent& evt)
{
	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);

	if (calButtons[buttonIndex]->GetLabel() == "bin")
	{
		isBin = true;
		isHex = false;
		calButtons[GetButtonIndex(3, 1)]->SetBackgroundColour(defaultButtonColor); //hex
		isDec = false;
		calButtons[GetButtonIndex(2, 1)]->SetBackgroundColour(defaultButtonColor); //dec

		//disable all except 1 and 0
	}
	else if (calButtons[buttonIndex]->GetLabel() == "dec" && (isBin == false || isHex == false || isDec == true))
	{
		isDec = true;
		isBin = false;
		calButtons[GetButtonIndex(1, 1)]->SetBackgroundColour(defaultButtonColor); //binary
		isHex = false;
		calButtons[GetButtonIndex(3, 1)]->SetBackgroundColour(defaultButtonColor); //hex
	}
	else if (calButtons[buttonIndex]->GetLabel() == "hex")
	{
		isHex = true;
		isBin = false;
		calButtons[GetButtonIndex(1, 1)]->SetBackgroundColour(defaultButtonColor); //binary
		isDec = false;
		calButtons[GetButtonIndex(2, 1)]->SetBackgroundColour(defaultButtonColor); //dec
	}
	ToggleButtonsForHex();
	ToggleButtonsForBinary();
	calButtons[buttonIndex]->SetBackgroundColour(*wxCYAN);
}

void CMain::ToggleButtonsForHex()
{
	//other four letters
	for (int rows = 0; rows <= 4; rows++)
	{
		if (isHex)
			calButtons[GetButtonIndex(rows, 0)]->Enable();
		else
			calButtons[GetButtonIndex(rows, 0)]->Disable();
	}
	//handle f
	if (isHex)
		calButtons[GetButtonIndex(0, 1)]->Enable();
	else
		calButtons[GetButtonIndex(0, 1)]->Disable();

}

void CMain::ToggleButtonsForBinary()
{
	for (int rows = 0; rows <= 2; rows++)
	{
		for (int cols = 2; cols <= 4; cols++)
		{
			if (calButtons[GetButtonIndex(rows, cols)]->GetLabel() == "1")
				continue;
			if (isBin)
				calButtons[GetButtonIndex(rows, cols)]->Disable();
			else
				calButtons[GetButtonIndex(rows, cols)]->Enable();
		}
	}
	//no plus/minus
	if (isBin)
		calButtons[GetButtonIndex(3, 2)]->Disable();
	else
		calButtons[GetButtonIndex(3, 2)]->Enable();
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
	calDisplay->SetLabelText("");

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
			//going to decimal
			if (isBin)
			{
				prevNumFl = BinaryToDecimal(prevNumFl);
				nextNumFl = BinaryToDecimal(nextNumFl);
			}
			else if (isHex)
			{
				prevNumFl = HexToDecimal(prevNumStr);
				nextNumFl = HexToDecimal(nextNumStr);
			}
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

			//back to hex/bin
			if (isDec)
				strResult = wxString::Format(wxT("%f"), numResult);
			else if (isBin)
			{
				strResult = wxString::Format(wxT("%i"), (int)numResult);
				numResult = ConvertToBinary((int)numResult);
			}
			else //isHex
				strResult = DecimalToHex((int)numResult);

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
