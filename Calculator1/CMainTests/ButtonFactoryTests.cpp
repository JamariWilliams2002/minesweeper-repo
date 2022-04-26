#include "../Calculator1/ButtonFactory.h"
#include "wx/wx.h"
bool Button3LabelReturn()
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
	wxButton* button = factory.Button3();

	return result;
}
bool ButtonMultiplyLabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}
bool ButtonBinLabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}
bool ButtonModulusLabelCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}

bool ButtonSizeCheck()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}
bool ButtonColorDec()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}
bool ButtonColorDefault()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}
bool ButtonPosition()
{
	bool result = true;
	CalculatorButtonFactory factory;
	wxButton* button = factory.Button3();

	return result;
}
