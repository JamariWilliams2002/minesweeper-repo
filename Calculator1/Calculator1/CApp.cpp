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
	//means that we are checking for tests if false
#if 0
	frame1 = new CMain();
	frame1->Show();

#endif // 0

	return true;
}