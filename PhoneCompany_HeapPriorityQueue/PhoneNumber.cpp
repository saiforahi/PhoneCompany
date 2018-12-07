#include "PhoneNumber.h"
#include <iostream>
using namespace std;


PhoneNumber::PhoneNumber()
{
	
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
	}
}

PhoneNumber::~PhoneNumber()
{
	queuedCalls.~HeapType();
}

void PhoneNumber::set_operatorName(string givenName)
{
	if (givenName == "GP" || givenName == "gp")
		operatorName = givenName;
	else if (givenName == "BANGLALINK" || givenName == "banglalink" || givenName == "Banglalink")
		operatorName = givenName;
	else if (givenName == "ROBI" || givenName == "robi" || givenName == "Robi")
		operatorName = givenName;
	else if (givenName == "TELETALK" || givenName == "teletalk" || givenName == "Teletalk")
		operatorName = givenName;
	else if (givenName == "KOMKOTHAKOIBEN" || givenName == "komkothekoiben" || givenName == "KomKothaKoiben")
		operatorName = givenName;
	else
		cout << "Invalid operator name" << endl;
}

void PhoneNumber::enqueue_call(Call newItem)
{
	queuedCalls.enqueue(newItem);
}

void PhoneNumber::dequeue_call(Call &dequeuedCall)
{
	queuedCalls.dequeue(dequeuedCall);
}

void PhoneNumber::make_call_list_empty()
{
	queuedCalls.make_empty();
}



bool PhoneNumber::is_call_list_empty()
{
	return queuedCalls.is_empty() ;
}

bool PhoneNumber::is_call_list_full()
{
	return queuedCalls.is_full();
}

string PhoneNumber::get_number()
{
	return number;
}

bool PhoneNumber::hasNextCall()
{
	return queuedCalls.hasNextCall();
}

string PhoneNumber::get_operatorName()
{
	return operatorName;
}

int PhoneNumber::get_callList_size()
{
	return queuedCalls.get_size();
}

void PhoneNumber::print_queued_calls()
{
	HeapType dummy = queuedCalls;
	while (!dummy.is_empty())
	{
		Call demo;
		dummy.dequeue(demo);
		demo.print_call();
	}
}


void PhoneNumber::print_details()
{
	cout << "\n\t\t" << operatorName << "\t\t" << number << endl;
	cout << "\t\tCalls:" << endl;
	print_queued_calls();
}