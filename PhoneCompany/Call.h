#pragma once
#include <string>
#include "PhoneNumber.h"
#include "Person.h"
enum relationship { spouse = 1, Child = 2, Parent = 3, Sibling = 4, Aunt = 5, Uncle = 5, Cousins = 6, Significant = 7, Friend = 8, Boss = 9, Subordinate = 10, Acquaintance = 11, Blocked = 12 };
class Call
{
private:
	PhoneNumber callerNumber;
	Person fromPerson;
	relationship relationship_type;
	int durationInSeconds = 0;
	int hours, minutes, seconds;
public:
	Call();
	Call(PhoneNumber, Person, relationship, int);//parameterized constructor
	PhoneNumber get_caller_number();
	relationship get_relationship();
	string get_duration();

	~Call();//destructor
};