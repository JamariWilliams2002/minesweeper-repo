#pragma once
#include "wx/wx.h"

//TO DO::
// create display
// create 0-9 buttons
// 
//


//RETURNING NOTES:
//



class CMain : public wxFrame
{
public:
	//constants
	const int fieldWidth = 7;
	const int fieldHeight = 4;
	
	//his controls
	wxButton* btn = nullptr;
	wxButton* btn2 = nullptr;

	wxTextCtrl* txt = nullptr;
	wxListBox* list = nullptr;

	//controls
	wxButton* test = nullptr;
	wxButton** calButtons = nullptr;
	wxTextCtrl *calDisplay = nullptr;

	//constructor/destructor
	CMain();
	~CMain();

	//methods
	void FillButtonText();

	//events

	wxDECLARE_EVENT_TABLE();


};

