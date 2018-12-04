#include "Call.h"

Call::Call()
{
}

Call::Call(PhoneNumber givenNumber, Person givenPerson, relationship relationshipNumber, int givenDuration)
{
	callerNumber = givenNumber;
	fromPerson = givenPerson;
	relationship_type = relationshipNumber;
	durationInSeconds = givenDuration;
	hours = givenDuration / 3600;
	minutes = (givenDuration % 3600) / 60;
	seconds = (givenDuration % 3600) % 60;
}

PhoneNumber Call::get_caller_number()
{
	return callerNumber;
}

relationship Call::get_relationship()
{
	return relationship_type;
}

string Call::get_duration()
{
	return to_string(hours) + ":" + to_string(minutes) + ":" + to_string(seconds);
}

Call::~Call()
{
}



