#pragma once
#include "wx/wx.h"
#include "CMain.h"

class CApp : public wxApp
{
public:
	CApp();
	~CApp();
	virtual bool OnInit();
	
private:
	CMain* m_frame1 = nullptr;
};

