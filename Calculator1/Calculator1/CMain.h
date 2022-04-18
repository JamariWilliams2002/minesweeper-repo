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
//need to keep a copy of the prepreview string, except all of the numbers are already converted to decimal. 
// this will allow us to enter the copied str into the te_interp function with no issues about conversions
// **see function called "UpdateToDecimalStr". 
// The following example is entered like: (dec * bin * hex), EX:
// Entered Expression = 8 * 101 * AB
// Copy of prepreview = 8 * 5 * 171



class CMain : public wxFrame
{
private:
	int myButtonID = 1000;
	int idOffset;

	//refactored variables
	double currentNumFl;
	wxString currentNumStr;
	//these numbers are always converted to decimal before being entered
	std::vector<double> enteredNums;
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
	wxString prePreviewStr = "";
	//copy of prepreviewstr, just in the number's original form
	wxString prePreviewDecStr = "";
	//keep a copy of the string
	wxString cpy;

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
	int ConvertToBinary(int decimal);
	int BinaryToDecimal(int n);
	std::string DecimalToHex(int num);
	int HexToDecimal(wxString hex);
	void ToggleButtonsForBinary();
	void ToggleButtonsForHex();
	void UpdatePreview();
	wxString ProjectedSolution();
	void ResetCurrentNum();
	void UpdateToDecimalStr(bool resetStr = false);
	wxString UpdateStrings(wxString strToUpdate);
	int FactoryButtonID(bool nextRow = false);
public:
	//constructor/destructor
	CMain();
	~CMain();
	//events
	wxDECLARE_EVENT_TABLE();
};

