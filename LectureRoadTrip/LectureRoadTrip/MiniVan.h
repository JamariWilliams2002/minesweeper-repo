#pragma once
#include "Person.h"
class MiniVan
{
private:
	std::vector<Person> mRiders;
	
public:
	MiniVan(char* make, char* model, char* year, char* color);
	void AddPerson(Person personToAdd);
	void AddPeople(std::vector<Person> vPeopleToAdd);
	
};

