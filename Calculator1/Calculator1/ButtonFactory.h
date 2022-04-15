#pragma once
#include "CMain.h"
#include "wx/wx.h"
class ButtonFactory
{
private:

public:
	ButtonFactory();
	~ButtonFactory();
	wxButton* CreateAddButton();
	void test(wxWindow* a)
	{
		wxButton* s = new wxButton(a, 3);
		return;
	}
};

