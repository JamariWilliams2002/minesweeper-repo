#pragma once
#include <vector>
class Person
{
public: 
	//struct Address
	//{
	//	char* mStreet;
	//	char* mCity;
	//	char* mState;
	//	//idk why but it won't compile without default constructor
	//	Address()
	//	{

	//	}
	//	Address(const char* street, const char* city, const char* state)
	//	{
	//		
	//	}
	//	void CopyStrings(const char* s, char* element)
	//	{
	//		int len = strlen(s);
	//		element = new char[len + 1];
	//		strcpy_s(element, s);
	//	}
	//};
	struct Item
	{
		char* myItem;
		Item(char* item)
		{
			myItem = item;
		}
	};

private:
	//fields
	std::vector<Item> mBackpack;
	char* mName;
	
	char* mStreet;
	char* mCity;
	char* mState;

public:
	//rule of 3
	Person(char* name, char* street, char* city, char* state);
	
	//functions
	void FillBackpack();



};

