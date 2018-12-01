#include "Call.h"



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


Call::~Call()
{
}
