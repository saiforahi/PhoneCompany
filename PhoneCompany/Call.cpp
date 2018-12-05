#include "Call.h"
#include <iostream>
using namespace std;
Call::Call()
{
}

Call::Call(string givenNumber, string givenOperatorName,string givenNumberToCall,string operatorOfNumberToCall, Person newPerson, relationship relationshipNumber, int givenDuration)
{
	callFromNumber.number = givenNumber;
	callFromNumber.operatorName = givenOperatorName;
	callToNumber.number = givenNumberToCall;
	callToNumber.operatorName = operatorOfNumberToCall;
	caller = newPerson;
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
	cout <<"\t"<< relationship(relationshipType)<<"\t"<<get_duration() << endl;
}

Call::~Call()
{
}



