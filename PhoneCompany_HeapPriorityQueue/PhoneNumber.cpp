#include "PhoneNumber.h"
#include <iostream>
using namespace std;


PhoneNumber::PhoneNumber()
{
	queuedCalls = new Call[queuedCallsMaxSize];
	queuedCallsSize = 0;
}

PhoneNumber::PhoneNumber(string givenNumber, string givenOperator)
{
	if (givenNumber.size() < 11 || givenNumber.size() > 11)
	{
		cout << "Wrong phone number entry!" << endl;
	}
	else {
		number = givenNumber;
		operatorName = givenOperator;
		queuedCalls = new Call[queuedCallsMaxSize];
		queuedCallsSize = 0;
	}
}

PhoneNumber::~PhoneNumber()
{
	delete[]queuedCalls;
}

void PhoneNumber::set_operatorName(string givenName)
{
	if (givenName == "GP" || givenName == "gp")
		operatorName = givenName;
	else if (givenName == "BANGLALINK" || givenName == "banglalink")
		operatorName = givenName;
	else if (givenName == "ROBI" || givenName == "robi")
		operatorName = givenName;
	else if (givenName == "TELETALK" || givenName == "teletalk")
		operatorName = givenName;
	else if (givenName == "KOMKOTHAKOIBEN" || givenName == "komkothekoiben" || givenName == "KomKothaKoiben")
		operatorName = givenName;
	else
		cout << "Invalid operator name" << endl;
}

bool PhoneNumber::is_call_list_empty()
{
	return queuedCallsSize==0 ;
}

bool PhoneNumber::is_call_list_full()
{
	return queuedCallsSize== queuedCallsMaxSize;
}


void PhoneNumber::swap(Call & one, Call & two)
{
	Call temp;
	temp = one;
	one = two;
	two = temp;
}

string PhoneNumber::get_number()
{
	return number;
}

string PhoneNumber::get_operatorName()
{
	return operatorName;
}

void PhoneNumber::print_details()
{
	cout << "\t\t" << operatorName << "\t\t" << number << endl;
}