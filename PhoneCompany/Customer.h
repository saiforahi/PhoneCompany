#pragma once
#include "Person.h"
#include "PhoneNumber.h"
#include <list>

const int MAX_SIZE = 15;

class Customer :
	public Person
{
private:
	list <PhoneNumber> numbers;
	list<PhoneNumber>::iterator currentPos;
public:
	Customer();
	Customer(string givenFirstName, string givenLastName, PhoneNumber firstNumber, string givenFatherName, string givenMotherName, string givenNID, string givenPassportNo, string givenDrivingLicense, string givenPresentAddress, string givenPermanentAddress, string givenMaritalStatus, string givenSpouseName, string givenHeight, string givenWeight, string givenHairColor, string givenEyeColor, string givenSpecialMark);
	~Customer();

	void add_number(PhoneNumber);//modifier
	void reset_number_list();//modifier
	void make_empty();//modifier
	void delete_number(PhoneNumber);//modifier
	void change_operatorName(PhoneNumber);//modifier

	bool is_Full();//accessor
	PhoneNumber get_phoneNumber(PhoneNumber, bool&);//accessor
	bool is_Empty();//accessor
	bool hasNextNumber();//accessor
	PhoneNumber getNextNumber();//accessor
	int get_length();//accessor
	void print_details();//accessor
};

