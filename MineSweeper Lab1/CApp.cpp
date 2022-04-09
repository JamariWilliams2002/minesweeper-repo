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
	m_frame1 = new CMain();
	m_frame1->Show();
	return true;
}