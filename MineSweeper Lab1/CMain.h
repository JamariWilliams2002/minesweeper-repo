#pragma once
#include "wx/wx.h"


class CMain : public wxFrame
{
public:
	//constructor/destructor
	CMain();
	~CMain();
	//member fields
	wxButton* btn1 = nullptr;
	wxTextCtrl* text1 = nullptr;
	wxListBox* list = nullptr;

	//click events
	void OnButtonClick(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

};

