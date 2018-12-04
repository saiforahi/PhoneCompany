#pragma once
#include <string>
using namespace std;
class Person
{
	string firstName, lastName;
	int dateOfBirth,monthOfBirth,yearOfBirth;
	string fatherName, motherName;
	string NID, passportNo, drivingLicenseNo;
	string presentAddress, permanentAddress;        //fields of person class
	string maritalStatus, spouseName;
	string height, weight, hairColor, eyeColor;
	string specialMark;
public:
	Person();
	Person(string, string, string);
	Person(string, string, string, string, string, string, string, string, string, string, string, string, string, string, string, string,string,int,int,int);               // parameterized constructor
	~Person();

	//list of modifiers

	void set_name(string, string);
	void set_dateOfBirth(int,int,int);
	void set_fatherName(string);
	void set_motherName(string);
	void set_NID(string);
	void set_passportNo(string);
	void set_drivingLicense(string);
	void set_presentAddress(string);
	void set_permanentAddress(string);
	void set_maritalStatus(string);
	void set_spouseName(string);
	void set_height(string);
	void set_weight(string);
	void set_hairColor(string);
	void set_eyeColor(string);
	void set_specialMark(string);

	//list of accessors
	string get_name();
	string get_fatherName();
	string get_motherName();
	string get_NID();
	string get_passportNo();
	string get_drivingLicense();
	string get_presentAddress();
	string get_permanentAddress();
	string get_maritalStatus();
	string get_spouseName();
	string get_height();
	string get_weight();
	string get_hairColor();
	string get_eyeColor();
	string get_specialMark();
};




