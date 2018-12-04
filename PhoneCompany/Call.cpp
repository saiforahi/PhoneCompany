#include "Call.h"

Call::Call()
{
}

Call::Call(string givenNumber, string givenOperatorName, string givenName,string givenNID, relationship relationshipNumber, int givenDuration)
{
	callFromNumber.number = givenNumber;
	callFromNumber.operatorName = givenOperatorName;
	fromPerson.name = givenName;
	fromPerson.NID = givenNID;
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

string Call::get_caller_name()
{
	return fromPerson.name;
}

string Call::get_caller_NID()
{
	return fromPerson.NID;
}

string Call::get_caller_fatherName()
{
	return fromPerson.fatherName;
}

string Call::get_caller_motherName()
{
	return fromPerson.motherName;
}

string Call::get_caller_passportNo()
{
	return fromPerson.passportNo;
}

string Call::get_caller_drivingLicenseNo()
{
	return fromPerson.drivingLicenseNo;
}

string Call::get_caller_presentAddress()
{
	return fromPerson.presentAddress;
}

string Call::get_caller_permanentAddress()
{
	return fromPerson.permanentAddress;
}

string Call::get_caller_maritalStatus()
{
	return fromPerson.maritalStatus;
}

string Call::get_caller_spouseName()
{
	return fromPerson.spouseName;
}

string Call::get_caller_height()
{
	return fromPerson.height;
}

string Call::get_caller_weight()
{
	return fromPerson.weight;
}

string Call::get_caller_hairColor()
{
	return fromPerson.hairColor;
}

string Call::get_caller_eyeColor()
{
	return fromPerson.eyeColor;
}

string Call::get_caller_specialMark()
{
	return fromPerson.specialMark;
}

Call::~Call()
{
}



