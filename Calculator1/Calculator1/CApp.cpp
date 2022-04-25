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
#if 0 //means that we are checking for tests
	frame1 = new CMain();
	frame1->Show();

#endif // 0

	return true;
}