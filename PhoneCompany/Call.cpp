#include "Call.h"
#include <iostream>
using namespace std;
Call::Call()
{
}

Call::Call(string givenNumber, string givenOperatorName,string givenNumberToCall,string operatorOfNumberToCall,string givenRecieverNID,Person newPerson, relationship relationshipNumber, int givenDuration)
{
	callFromNumber.number = givenNumber;
	callFromNumber.operatorName = givenOperatorName;
	callToNumber.number = givenNumberToCall;
	callToNumber.operatorName = operatorOfNumberToCall;
	caller = newPerson;
	recieverNID = givenRecieverNID;
	relationshipType = relationshipNumber;
	durationInSeconds = givenDuration;
	hours = givenDuration / 3600;
	minutes = (givenDuration % 3600) / 60;
	seconds = (givenDuration % 3600) % 60;
}

string Call::get_caller_number()
{
	return callFromNumber.number;
}

string Call::get_caller_operator()
{
	return callFromNumber.operatorName;
}

string Call::get_reciever_number()
{
	return callToNumber.number;
}

string Call::get_reciever_operator()
{
	return callToNumber.operatorName;
}

relationship Call::get_relationship()
{
	return relationshipType;
}

string Call::get_duration()
{
	return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}

string Call::get_recieverNID()
{
	return recieverNID;
}

int Call::get_durationInSeconds()
{
	return durationInSeconds;
}

Person Call::get_caller()
{
	return caller;
}

void Call::set_duration(int newValue)
{
	durationInSeconds = newValue;
	hours = durationInSeconds / 3600;
	minutes = (durationInSeconds % 3600) / 60;
	seconds = (durationInSeconds % 3600) % 60;
}

void Call::update_duration(int newValue)
{
	durationInSeconds += newValue;
	hours = durationInSeconds / 3600;
	minutes = (durationInSeconds % 3600) / 60;
	seconds = (durationInSeconds % 3600) % 60;
}

void Call::print_call()
{
	switch (relationshipType)
	{
	case 1:
		cout <<"Spouse\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 2:
		cout << "Child\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 3:
		cout << "Parent\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 4:
		cout << "Sibling\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 5:
		cout << "Relatives\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 6:
		cout << "Cousins\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 7:
		cout << "Significant\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 8:
		cout << "Friend\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 9:
		cout << "Boss\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 10:
		cout << "Subordinate\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 11:
		cout << "Acquaintance\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	case 12:
		cout << "Blocked\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
	default:
		break;
	}
	
}

Call::~Call()
{
}



