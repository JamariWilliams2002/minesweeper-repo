#include "CApp.h"
wxIMPLEMENT_APP(CApp);

CApp::CApp()
{
}
CApp::~CApp()
{
}

bool CApp::OnInit()
{
	frame1 = new CMain();
	frame1->Show();
	return true;
}