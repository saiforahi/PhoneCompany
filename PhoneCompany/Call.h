#pragma once
#include "PhoneNumber.h"
#include "Person.h"
class Call
{
private:
	PhoneNumber callerNumber;
	Person fromPerson;
	int relationship=0;
	int durationInSeconds = 0;
public:
	Call();
	Call(PhoneNumber, Person, int, int);//parameterized constructor
	~Call();//destructor
};

