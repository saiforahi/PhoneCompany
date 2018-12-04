#include "Call.h"

Call::Call()
{
}

Call::Call(string givenNumber, string givenOperatorName, Person newPerson, relationship relationshipNumber, int givenDuration)
{
	callFromNumber.number = givenNumber;
	callFromNumber.operatorName = givenOperatorName;
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

relationship Call::get_relationship()
{
	return relationshipType;
}

string Call::get_duration()
{
	return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}

Person Call::get_caller()
{
	return caller;
}

Call::~Call()
{
}



