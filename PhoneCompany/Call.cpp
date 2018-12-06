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
	case Spouse:
		cout <<"\t\t\tSpouse\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Child:
		cout << "\t\t\tChild\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Parent:
		cout << "\t\t\tParent\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Sibling:
		cout << "\t\t\tSibling\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Relatives:
		cout << "\t\t\tRelatives\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Cousins:
		cout << "\t\t\tCousins\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Significant:
		cout << "\t\t\tSignificant\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Friend:
		cout << "\t\t\tFriend\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Boss:
		cout << "\t\t\tBoss\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Subordinate:
		cout << "\t\t\tSubordinate\t" << relationship(relationshipType) << "\t" << get_duration() << endl; break;
	case Acquaintance:
		cout << "\t\t\tAcquaintance\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
		break;
	case Blocked:
		cout << "\t\t\tBlocked\t" << relationship(relationshipType) << "\t" << get_duration() << endl;
		break;
	}
	
}

Call::~Call()
{
}



