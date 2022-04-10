#pragma once
#include "wx/wx.h"


class CMain : public wxFrame
{
public:
	//constructor/destructor
	CMain();
	~CMain();
	//member fields
	int fieldHeight = 10;
	int fieldWidth = 10;
	wxButton** btn;
	int* field = nullptr;
	bool firstClick = true;
	//colors
	wxColor unclickedButtonColor;
	wxColor clickedButtonColor;
	wxColor flagButtonColor;
	//click events
	void OnButtonClick(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

};

