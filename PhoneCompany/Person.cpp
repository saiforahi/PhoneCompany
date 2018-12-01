#include "Person.h"
#include <iostream>
using namespace std;


Person::Person()
{
}

Person::Person(string givenFirstName, string GivenLastName)
{
	firstName = givenFirstName;
	lastName = GivenLastName;
}


Person::~Person()
{
}

void Person::set_name(string givenFirstName, string givenLastName)
{
	firstName = givenFirstName;
	lastName = givenLastName;
}

void Person::set_fatherName(string givenFatherName)
{
	fatherName = givenFatherName;
}

void Person::set_motherName(string givenMotherName)
{
	motherName = givenMotherName;
}

void Person::set_NID(string givenNID)
{
	if (givenNID.size() < 11 || givenNID.size() > 11)
	{
		cout << "Wrong entry!" << endl;
	}
	else {
		NID = givenNID;
	}
}

void Person::set_passportNo(string givenPassportNo)
{
	passportNo = givenPassportNo;
}

void Person::set_drivingLicense(string givenLicenseNo)
{
	drivingLicenseNo = givenLicenseNo;
}

void Person::set_presentAddress(string givenAddress)
{
	presentAddress = givenAddress;
}

void Person::set_permanentAddress(string givenAddress)
{
	permanentAddress = givenAddress;
}

void Person::set_maritalStatus(string givenStatus)
{
	maritalStatus = givenStatus;
}

void Person::set_spouseName(string givenName)
{
	spouseName = givenName;
}

void Person::set_height(string givenHeight)
{
	height = givenHeight;
}

void Person::set_weight(string givenWeight)
{
	weight = givenWeight;
}

void Person::set_hairColor(string givenColor)
{
	hairColor = givenColor;
}

void Person::set_eyeColor(string givenColor)
{
	eyeColor = givenColor;
}

void Person::set_specialMark(string givenMark)
{
	specialMark = givenMark;
}

string Person::get_name()
{
	return firstName + " " + lastName;
}

string Person::get_fatherName()
{
	return fatherName;
}

string Person::get_motherName()
{
	return motherName;
}

string Person::get_NID()
{
	return NID;
}

string Person::get_passportNo()
{
	return passportNo;
}

string Person::get_drivingLicense()
{
	return drivingLicenseNo;
}

string Person::get_presentAddress()
{
	return presentAddress;
}

string Person::get_permanentAddress()
{
	return permanentAddress;
}

string Person::get_maritalStatus()
{
	return maritalStatus;
}

string Person::get_spouseName()
{
	return spouseName;
}

string Person::get_height()
{
	return height;
}

string Person::get_weight()
{
	return weight;
}

string Person::get_hairColor()
{
	return hairColor;
}

string Person::get_eyeColor()
{
	return eyeColor;
}

string Person::get_specialMark()
{
	return specialMark;
}