#pragma once
#include "wx/wx.h"

//TO DO::
// create display
// create 0-9 buttons
// 
// EXTRAS:
// make functioning sizer
//create preview for display
//when the user clicks a different operation, the operation in question changes
// parenthases
// 
//delete button


//RETURNING NOTES:
//



class CMain : public wxFrame
{
private:
	//flags for operations
	bool arithmeticClick = false;
	wxString clickedAction;
	float prevNumFl;
	wxString prevNumStr = "";
	float nextNumFl;
	wxString nextNumStr = "";
	bool onNextNum = false;
	bool equalsClicked = false;
	bool negPosButtonClicked = false;
	bool decimalPointClicked = false;
	bool isBin = false;
	bool isDec = true;
	bool isHex = false; 
	wxString textEmpty = "Empty";
	wxString tempResult = textEmpty;
	wxColour defaultButtonColor;
	//generic fields
	wxPoint previewPoint;
	wxSize previewSize;
	wxPoint displayPoint;
	wxSize displaySize;
	//buffer variables
	const int previewToDisplayBuffer = 10;
	const int displayPointBuffer = 10;
	const int displayToButtonBuffer = 20;
	const int betweenButtonBuffer = 5;
	//constants
	const int fieldRows = 5;
	const int fieldCols = 7;
	const int numButtons = fieldRows * fieldCols;
	//controls
	wxButton* buttonTest = nullptr;
	wxButton** calButtons = nullptr;
	wxTextCtrl *calDisplay = nullptr;
	wxTextCtrl* calPreview = nullptr;
	//set up methods
	void GeneratePreview();
	void GenerateDisplay();
	void GenerateButtons();
	void ButtonSpecs();
	int GetButtonIndex(int rows, int cols);
	//runtime methods
	void OnClickNumbers(wxCommandEvent &evt);
	void OnClickArithmetic(wxCommandEvent& evt);
	void OnClickBinHexDec(wxCommandEvent& evt);
	void OnClickMisc(wxCommandEvent &evt);
	void ResetArithmetic();
	void ResetPrevAndNextNum();
	//void CheckButtonColor();
	int ConvertToBinary();
	int ConvertToBinary(int num);
	std::string DecimalToHex(int num);
	int HexToDecimal(wxString hex);
	int BinaryToDecimal(int n);
	void ToggleButtonsForBinary();
	void ToggleButtonsForHex();
public:

	//constructor/destructor
	CMain();
	~CMain();


	//events

	wxDECLARE_EVENT_TABLE();


};

