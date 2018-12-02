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
	hours = givenDuration / 3600;
	minutes = (givenDuration % 3600) / 60;
	seconds = (givenDuration % 3600) % 60;
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
	return to_string(hours) + ":" +to_string(minutes) + ":" +to_string(seconds);
}


Call::~Call()
{
}

bool Call::operator <(const Call& newCall) const
{
	if ( relationship< newCall.relationship)
	{
		return true;
	}
	else if (relationship == newCall.relationship)
	{
		if (durationInSeconds < newCall.durationInSeconds)
		{
			return true;
		}
	}
	return false;
}

bool Call::operator>(const Call & newCall) const
{
	if (relationship > newCall.relationship)
	{
		return true;
	}
	else if (relationship == newCall.relationship)
	{
		if (durationInSeconds > newCall.durationInSeconds)
		{
			return true;
		}
	}
	return false;
}
