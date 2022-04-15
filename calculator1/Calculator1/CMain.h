#pragma once
#include "wx/wx.h"

//TO DO::
// make functioning sizer
//create preview for display
//when the user clicks a different operation, the operation in question changes
//		------make this apply to the preview display as well
//delete button
// EXTRAS:
// parenthases
// make iterator for the operations
// square roots



//RETURNING NOTES:
//working on the updatePreview function. trying to make it update when the user clicks a number and when multiple operations have been entered



class CMain : public wxFrame
{
private:
	//refactored variables
	float currentNumFl;
	wxString currentNumStr;
	std::vector<float> enteredNums;
	std::vector<wxString> enteredOperations;
	//doesn't include P or E
	std::vector<wxString> operationsInPemdas { "X", "/", "%", "+", "-" };

	//flags for operations
	//means atleast one arithmetic has been clicked and we are working on a second number
	bool onNextNum = false;
	bool onFirstNum = true;
	//false if number is clicked, true if it's arithmetic
	bool arithmeticClick = false;
	bool numClick = false;
	wxString clickedAction;
	float prevNumFl;
	wxString prevNumStr = "";
	float nextNumFl;
	wxString nextNumStr = "";
	bool equalsClicked = false;
	bool negPosButtonClicked = false;
	bool decimalPointClicked = false;
	bool isBin = false;
	bool isDec = true;
	bool isHex = false; 
	wxString tempResult = "";
	wxColour defaultButtonColor;
	//generic fields
	wxPoint previewPoint;
	wxSize previewSize;
	wxPoint displayPoint;
	wxSize displaySize;
	wxString prePreviewStr;
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
	//helper methods
	void ResetArithmetic();
	void ResetPrevAndNextNum();
	int ConvertToBinary(int decimal);
	int BinaryToDecimal(int n);
	std::string DecimalToHex(int num);
	int HexToDecimal(wxString hex);
	void ToggleButtonsForBinary();
	void ToggleButtonsForHex();
	void UpdatePreview();
	wxString ProjectedSolution();
	void ResetCurrentNum();
public:
	//constructor/destructor
	CMain();
	~CMain();
	//events
	wxDECLARE_EVENT_TABLE();
};

