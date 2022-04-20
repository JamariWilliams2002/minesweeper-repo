#include "CMain.h"
#include "ButtonFactory.h"
#include "tinyexpr.h"
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#define NORMAL_CODE true


wxBEGIN_EVENT_TABLE(CMain, wxFrame)
EVT_BUTTON(wxID_ANY, OnClickNumbers)
wxEND_EVENT_TABLE();


//main window stuff
const int CAL_POINT_X = 30;
const int CAL_POINT_Y = 30;
const int CAL_SIZE_WIDTH = 700;
const int CAL_SIZE_HEIGHT = 700;

CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's Calculator", wxPoint(CAL_POINT_X, CAL_POINT_Y), wxSize(CAL_SIZE_WIDTH, CAL_SIZE_HEIGHT))
{
	//display & buttons
	GeneratePreview();
	GenerateDisplay();
	GenerateButtons();
	ButtonSpecs();
	//since starting in decimal, disable buttons for hex
	ToggleButtonsForHex();

	//set the grid
	//this->SetSizer(calGrid);
	//calGrid->Layout();
}

void CMain::GeneratePreview()
{
	//dimensions and position
	//rest of layout depends on the preview
	int previewPointX = CAL_POINT_X - displayPointBuffer;
	int previewPointY = CAL_POINT_Y - displayPointBuffer;
	previewPoint = wxPoint(previewPointX, previewPointY);
	int preivewSizeX = 650;
	int preivewSizeY = 50;
	previewSize = wxSize(preivewSizeX, preivewSizeY);

	calPreview = new wxTextCtrl(this, wxID_ANY, "", previewPoint, previewSize, wxTE_READONLY);

}

void CMain::GenerateDisplay()
{
	int displayPointX = previewPoint.x;
	int displayPointY = previewPoint.y + previewSize.y + previewToDisplayBuffer;
	displayPoint = wxPoint(displayPointX, displayPointY);
	int displaySizeX = previewSize.x;
	int displaySizeY = 200;
	displaySize = wxSize(displaySizeX, displaySizeY);

	calDisplay = new wxTextCtrl(this, wxID_ANY, "", displayPoint, displaySize, wxTE_READONLY);
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
	//buttonTest = new wxButton(this, wxID_ANY, "this is a button", buttonPos, buttonSize);S

	//CalculatorButtonFactory factory(this, calButtons, fieldRows, fieldCols);
	//create all buttons
	//factory.GenerateButtonGrid(buttonSize, x, y);

#if NORMAL_CODE
	CalculatorButtonFactory factory(this, calButtons, fieldRows, fieldCols);
	for (int row = 0; row < fieldRows; row++)
	{
		for (int col = 0; col < fieldCols; col++)
		{
			//create button, add to grid
			int currentButton = col * fieldRows + row;
			int buttonID = 1000 + currentButton;

			wxButton* button = factory.CreateButton(buttonID, buttonPos, buttonSize);

			calButtons[currentButton] = button;

			//change x, leave y
			buttonPos.x += (buttonSize.x + 5);
		}
		//reset x, change y
		buttonPos.x = x;
		buttonPos.y += buttonSize.y + 20;
	}
	ButtonSpecs();
#else
#endif // NORMAL_CODE


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
	calButtons[GetButtonIndex(1, 6)]->SetLabel("*");
	for (int rows = 1; rows <= 3; rows++)
	{
		for (int cols = 5; cols <= 6; cols++)
			calButtons[GetButtonIndex(rows, cols)]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CMain::OnClickArithmetic, this);
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

int CMain::ConvertToBinary(int decimal)
{
	int binary = 0, remainder, product = 1;

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

	numClick = true;

	//update current num str and fl
	if (isBin)
		ConvertToBinary((int)currentNumFl);

	currentNumStr = currentNumStr + label;

	if (isDec || isBin)
		currentNumFl = wxAtof(currentNumStr);
	//update display
	if (!equalsClicked)
		calDisplay->AppendText(label);
	else
	{
		calDisplay->SetLabelText(label);
		equalsClicked = false;
	}
	UpdatePreview();
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
	//if a number hasn't been enterd, nothing to do
	if (calDisplay->GetValue() == "")
		return;

	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);
	wxString label = calButtons[buttonIndex]->GetLabel();
	clickedAction = label;
	//increment num of arithmetic
	enteredOperations.push_back(clickedAction);
	ResetCurrentNum();
	//move to next num
	arithmeticClick = true;
	//display to preview
	UpdatePreview();
	//display to display
	calDisplay->SetLabelText("");
}

void CMain::ResetCurrentNum()
{
	currentNumFl = 0.0f;
	currentNumStr = "";
}

void CMain::UpdatePreview()
{
	wxString updatedStr = calPreview->GetValue();

	calPreview->SetLabelText(UpdateStrings(updatedStr));
}

void CMain::OnClickMisc(wxCommandEvent& evt)
{
	int row = (evt.GetId() - 1000) % fieldRows;
	int col = (evt.GetId() - 1000) / fieldRows;
	int buttonIndex = GetButtonIndex(row, col);

	wxString strResult;
	if (calButtons[buttonIndex]->GetLabel() == "=")
	{
		equalsClicked = true;
		if (onNextNum)
		{
			UpdateToDecimalStr();
			strResult = ProjectedSolution();
			calDisplay->SetLabelText(strResult);
			//setting flags and resetting
			tempResult = strResult;
			onNextNum = false;
			decimalPointClicked = false;
			UpdatePreview();
		}
	}
	else if (calButtons[buttonIndex]->GetLabel() == "clear")
	{
		calDisplay->SetLabelText("");
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
	clickedAction = "";
}

wxString CMain::ProjectedSolution()
{
	//stuff for result
	double numResult = 0;
	wxString strResult;
	//wxString calDisplayStr = calDisplay->GetValue();
	//wxString currentOperation;
	//std::vector<wxString> sortedOperations;
	//std::vector<int> indeciesOfOperations;
	//wxString operationToFind;
	//float num1 = 0, num2 = 0;

	////iterator to store position
	//std::vector<wxString>::iterator enteredOperationsIter;
	//std::vector<wxString>::iterator fullExpressionIter;


	////sort the list of operations
	//for (int i = 0; i < enteredOperations.size(); i++)
	//{
	//	for (int j = 0; j < operationsInPemdas.size(); j++)
	//	{
	//		operationToFind = operationsInPemdas[j];
	//		enteredOperationsIter = std::find(enteredOperations.begin(), enteredOperations.end(), operationToFind);
	//		//found the operation
	//		if (enteredOperationsIter != enteredOperations.end())
	//		{
	//			sortedOperations.push_back(operationToFind);
	//			//find numbers between the found operations
	//			break;
	//		}
	//		//do math based on the operations
	//	}
	//}

	numResult = te_interp(prePreviewDecStr, 0);
	//back to hex/bin
	if (isDec)
	{
		if (decimalPointClicked || numResult - (int)numResult != 0) //check for double
			strResult = wxString::Format(wxT("%f"), numResult);
		else
			strResult = wxString::Format(wxT("%i"), (int)numResult);
	}
	else if (isBin)
	{
		numResult = ConvertToBinary((int)numResult);
		strResult = wxString::Format(wxT("%i"), (int)numResult);
	}
	else //isHex
		strResult = DecimalToHex((int)numResult);


	return strResult;
}

CMain::~CMain()
{
	delete[] calButtons;
}
//first entry is false by default
void CMain::UpdateToDecimalStr(bool resetStr)
{
	if (resetStr)
	{
		prePreviewDecStr = "";
		return;
	}
	wxString currentLabel = calDisplay->GetValue();
	double numToEnter = 0;
	//convert 
	if (isDec)
		numToEnter = wxAtof(currentLabel);
	else if (isBin)
		numToEnter = BinaryToDecimal((int)wxAtof(currentLabel));
	else if (isHex)
		numToEnter = HexToDecimal(currentLabel);
	//update the string
	wxString numToEnterStr = std::to_string(numToEnter);

	if (numClick && !onNextNum && arithmeticClick) //first num was entered
	{
		prePreviewDecStr = numToEnterStr + " " + clickedAction + " ";
	}
	else if (arithmeticClick && onNextNum) //nextnum
	{
		prePreviewDecStr += numToEnterStr + " " + clickedAction;
	}
	else if (equalsClicked)
	{
		prePreviewDecStr += " " + numToEnterStr;
	}
}

wxString CMain::UpdateStrings(wxString strToUpdate)
{
	wxString updatedStr = "";
	wxString currentLabel = calDisplay->GetValue();
	//early return for when numbers are clicked and nextnum is off
	if (!arithmeticClick && !equalsClicked && !onNextNum)
		return updatedStr;
	else if (equalsClicked || currentLabel == "")//equalsClicked or calDisplay is an empty string
		updatedStr = "";
	else if (numClick && !onNextNum && arithmeticClick) //if the first num was entered, this will only happen once
	{
		updatedStr = currentLabel + " " + clickedAction + " ";
		//update copies, this is the first run through
		UpdateToDecimalStr();
		prePreviewStr = updatedStr;
		//reset flags
		numClick = false;
		onNextNum = true;
		arithmeticClick = false;
	}
	else if (arithmeticClick && onNextNum) //onNextNum
	{
		/*wxString projSol = ProjectedSolution();*/
		//updatedStr = prePreviewStr + currentLabel + " = " + projSol;
		updatedStr = calPreview->GetValue() + " " + clickedAction + " ";
		prePreviewStr = updatedStr;
		UpdateToDecimalStr();
		//reset flags
		arithmeticClick = false;
	}
	else if (numClick && onNextNum) //update the string that is shown in preview
	{
		updatedStr = prePreviewStr + currentLabel;
	}
	return updatedStr;
}