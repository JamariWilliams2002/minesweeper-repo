#pragma once
#include "wx/wx.h"
class IBaseCommand
{
public:
	virtual  wxString  Execute() = 0;
};

class AddCommand : public IBaseCommand
{
public:
	//default
	AddCommand()
	{
		
	}
	 wxString  Execute()
	{
		return " + ";
	}
};

class SubtractCommand: public IBaseCommand
{
public:
	SubtractCommand()
	{

	}
	 wxString Execute()
	{
		return " - ";
	}
};

class MultiplyCommand: public IBaseCommand
{
	public:
	MultiplyCommand()
	{
	}
	wxString Execute()
	{
		return " * ";
	}
};

class DivideCommand : public IBaseCommand
{
	public:
	DivideCommand()
	{
	}
	 wxString Execute()
	{
		return " / ";
	}
};

class ModulusCommand : public IBaseCommand
{
	public:
	ModulusCommand()
	{
	}
	 wxString Execute()
	{
		return " % ";
	}
};