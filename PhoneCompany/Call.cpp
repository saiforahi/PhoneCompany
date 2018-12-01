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
	return to_string(durationInSeconds / 3600) + ":" + to_string((durationInSeconds % 3600) / 60) + ':' + to_string((durationInSeconds % 3600) % 60);
}


Call::~Call()
{
}
