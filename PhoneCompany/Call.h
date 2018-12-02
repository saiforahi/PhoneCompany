#pragma once
#include <string>
#include "PhoneNumber.h"
#include "Person.h"



class Call
{
private:
	PhoneNumber callerNumber;
	Person fromPerson;
	int relationship=0;
	int durationInSeconds = 0;
	int hours, minutes, seconds;
public:
	Call();
	Call(PhoneNumber, Person, int, int);//parameterized constructor
	PhoneNumber get_caller_number();
	int get_relationship();
	string get_duration();
	bool operator<(const Call & newCall)const
	{
		return relationship < newCall.relationship;
	}
	bool operator>(const Call & newCall)const
	{
		return relationship > newCall.relationship;
	}
	bool operator == (const Call & newCall)const
	{
		return durationInSeconds > newCall.durationInSeconds;
	}
	~Call();//destructor
};

