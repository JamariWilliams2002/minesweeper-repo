#pragma once
#include "wx/wx.h"
class ButtonFactory
{
private:

public:
	ButtonFactory();
	~ButtonFactory();
	wxButton* CreateAddButton();
	wxButton* test(wxWindow* a, int buttonID, wxPoint buttonPos, wxSize buttonSize)
	{
		wxButton* button = new wxButton(a, buttonID, "this is a button", buttonPos, buttonSize);
		return button;
	}
};

