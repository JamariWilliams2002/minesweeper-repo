#include "CMain.h"

wxBEGIN_EVENT_TABLE();

wxEND_EVENT_TABLE();


CMain::CMain() : wxFrame(nullptr, wxID_ANY, "Jammy's MineSweeper", wxPoint(30, 30), wxSize(800, 800))
{
	btn1 = new wxButton(this, wxID_ANY, "Button", wxPoint(40, 50), wxSize(100, 50));
	text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(40, 150), wxSize(100, 40));
	list = new wxListBox(this, wxID_ANY, wxPoint(40, 250), wxSize(100, 40));
}

CMain::~CMain()
{

}

void CMain::OnButtonClick(wxCommandEvent& evt)
{

}