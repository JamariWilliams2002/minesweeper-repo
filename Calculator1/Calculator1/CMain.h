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
// square roots


//RETURNING NOTES:
//wanted to work on 3rd todo in list



class CMain : public wxFrame
{
private:
	//refactored variables
	float currentNumFl;
	wxString currentNumStr;
	std::vector<float> enteredNums;
	std::vector<std::string> enteredOperations;


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
public:
	//constructor/destructor
	CMain();
	~CMain();
	//events
	wxDECLARE_EVENT_TABLE();
};

