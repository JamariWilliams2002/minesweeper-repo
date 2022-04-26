#include "../Calculator1/ButtonFactory.h"
#include "wx/wx.h"
bool Button3LabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;

	wxButton* button = factory.Button3();
	wxString text = button->GetLabelText();

	if (text != "3")
		result = false;

	return result;

}

bool Button3IDCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;

	wxButton* button = factory.Button3();
	int id = button->GetId();

	if (id != '3')
		result = false;
	return result;
}


bool ButtonMultiplyIDCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.ButtonMultiply();
	int id = button->GetId();

	//evaluate
	if (id != '*')
		result = false;

	//clean up

	return result;
}
bool ButtonMultiplyLabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.ButtonMultiply();
	wxString text = button->GetLabel();

	if (text != "*")
		result = false;
	return result;
}
bool ButtonBinLabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.ButtonBinary();
	wxString text = button->GetLabel();

	if (text != "bin")
		result = false;

	return result;
}
bool ButtonModulusLabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.ButtonModulus();
	wxString text = button->GetLabel();

	if (text != "%")
		result = false;

	return result;
}

bool ButtonSubtractColor()
{
	bool result = true;

	CalculatorButtonFactory factory;


	wxButton* button = factory.ButtonSubtract();
	
	if ((*wxLIGHT_GREY) != button->GetBackgroundColour())
		result = false;

	return result;
}
bool Button3ColorDec()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	if ((*wxLIGHT_GREY) != button->GetBackgroundColour())
		result = false;

	return result;
}
bool ButtonSubtractIDCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.ButtonSubtract();

	if (button->GetId() != '-')
		result = false;
	return result;
}
bool ButtonAIDCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.ButtonHexA();

	if(button->GetId() != 'A')
		result = false;
	return result;
}
