#pragma once
#include "wx/wx.h"
#include "CMain.h"
class CApp : public wxApp
{
private:
	CMain* frame1 = nullptr;
public:
	CApp();
	~CApp();
	virtual bool OnInit();


};

