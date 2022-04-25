#pragma once
#include "wx/wx.h"

class IBaseCommand;
class CalculatorProcessor
{
public:
	static CalculatorProcessor& GetInstance(wxString expression)
	{
		static CalculatorProcessor calc;
		return calc;
	}
	void NewestProjectedSolution();	
	void ClearCommandVector();
	void ClearNums();
	~CalculatorProcessor();
private:
	std::vector<IBaseCommand*> commands;
	std::vector<double> nums;
	//conversion functions
	//only valid constructor
	CalculatorProcessor(wxString expression);
	CalculatorProcessor();

	wxString mainStr;

	//Pass in the whole string, include all arithmetic. Will return a decimal number
	void ProjectedSolution(wxString decStr);
	void NewProjectedSolution(wxString decStr);

	bool IsOperator(char c);
	bool IsNumber(char c);
	int GetPrecedence(char c);

	/// <summary>
	/// displaystr = calDisplay->GetValue()
	/// previewStr = calPreview->GetValue()
	/// </summary>
	/// <param name="strToUpdate"></param>
	/// <param name="displayStr"></param>
	/// <returns></returns>
	/// 
	//wxString UpdateStrings(wxString strToUpdate, wxString displayStr, wxString clickedAction, wxString prePreviewStr, wxString previewStr,
	//	bool numClick, bool arithmeticClick, bool equalsClicked, bool onNextNum)
	//{
	//	wxString updatedStr = "";
	//	wxString currentLabel = displayStr;
	//	//early return for when numbers are clicked and nextnum is off
	//	if (!arithmeticClick && !equalsClicked && !onNextNum)
	//		return updatedStr;
	//	else if (equalsClicked || currentLabel == "")//equalsClicked or calDisplay is an empty string
	//		updatedStr = "";
	//	else if (numClick && !onNextNum && arithmeticClick) //if the first num was entered, this will only happen once
	//	{
	//		updatedStr = currentLabel + " " + clickedAction + " ";
	//		//update copies, this is the first run through
	//		UpdateToDecimalStr();
	//		prePreviewStr = updatedStr;
	//		//reset flags
	//		numClick = false;
	//		onNextNum = true;
	//		arithmeticClick = false;
	//	}
	//	else if (arithmeticClick && onNextNum) //onNextNum
	//	{
	//		/*wxString projSol = ProjectedSolution();*/
	//		//updatedStr = prePreviewStr + currentLabel + " = " + projSol;
	//		updatedStr = previewStr + " " + clickedAction + " ";
	//		prePreviewStr = updatedStr;
	//		UpdateToDecimalStr();
	//		//reset flags
	//		arithmeticClick = false;
	//	}
	//	else if (numClick && onNextNum) //update the string that is shown in preview
	//		updatedStr = prePreviewStr + currentLabel;
	//	return updatedStr;
	//}
public:
	void PushNums(double num);
	void PushAddCommand(double num);
	void PushSubtractCommand(double num);
	void PushMultiplyCommand(double num);
	void PushDivideCommand(double num);
	void PushModulusCommand(double num);
	double resultAsDouble;
	wxString resultAswxString;
	CalculatorProcessor(CalculatorProcessor const&) = delete;
	void operator=(CalculatorProcessor const&) = delete;
};
