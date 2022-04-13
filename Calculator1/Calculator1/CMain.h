#pragma once
#include "wx/wx.h"

//TO DO::
// create display
// create 0-9 buttons
// 
// EXTRAS:
// make functioning sizer
//


//RETURNING NOTES:
//



class CMain : public wxFrame
{
private:
	//enum for buttons
	


	//generic fields
	wxPoint displayPoint;
	//buffer variables
	const int displayPointBuffer = 10;
	const int displayToButtonBuffer = 20;
	const int betweenButtonBuffer = 5;
	//constants
	const int fieldRows = 4;
	const int fieldCols = 7;
	const int numButtons = fieldRows * fieldCols;
	//controls
	wxButton* buttonTest = nullptr;
	wxButton** calButtons = nullptr;
	wxTextCtrl *calDisplay = nullptr;
	//set up methods
	void GenerateDisplay();
	void GenerateButtons();
	void ButtonSpecs();
	int GetButtonIndex(int rows, int cols);
	//runtime methods
	void OnClickNumbers(wxCommandEvent &evt);
	void OnClickArithmetic(wxCommandEvent& evt);
	void OnClickBinHexDec(wxCommandEvent& evt);
	void OnClickMisc(wxCommandEvent &evt);
public:

	//constructor/destructor
	CMain();
	~CMain();


	//events

	wxDECLARE_EVENT_TABLE();


};

