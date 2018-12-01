#include "Call.h"
using namespace std;
Call::Call()
{
}

Call::Call(PhoneNumber givenNumber, Person givenPerson, int relationshipNumber, int givenDuration)
{
	callerNumber = givenNumber;
	fromPerson = givenPerson;
	relationship = relationshipNumber;
	durationInSeconds = givenDuration;
	hours = durationInSeconds / 3600;
	minutes = (durationInSeconds % 3600) / 60;
	seconds = (durationInSeconds % 3600) % 60;
}

PhoneNumber Call::get_caller_number()
{
	return callerNumber;
}

int Call::get_relationship()
{
	return relationship;
}

string Call::get_duration()
{
	return hours + ":" + minutes + ':' + seconds;
}


Call::~Call()
{
}
