#include "ButtonFactory.h"
CalculatorButtonFactory::CalculatorButtonFactory()
{

}
CalculatorButtonFactory::~CalculatorButtonFactory()
{

}
wxButton* CalculatorButtonFactory::CreateButton(wxWindow* mainWindow, int buttonID, wxPoint buttonPos, wxSize buttonSize)
{
	wxButton* button = new wxButton(mainWindow, buttonID, "this is a button", buttonPos, buttonSize);
	return button;
}

wxButton* Button1()
{

}
wxButton* Button2()
{

}
wxButton* Button3()
{

}
wxButton* Button4()
{

}
wxButton* Button5()
{

}
wxButton* Button6()
{

}
wxButton* Button7()
{

}
wxButton* Button8()
{

}
wxButton* Button9()
{

}
wxButton* Button0()
{

}