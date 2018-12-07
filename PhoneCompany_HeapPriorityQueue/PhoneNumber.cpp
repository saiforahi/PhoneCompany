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

void PhoneNumber::enqueue_call(Call newItem)
{
	if (queuedCallsSize >= queuedCallsMaxSize)
		cout << "List is full" << endl;
	else {
		queuedCallsSize++;
		queuedCalls[queuedCallsSize - 1] = newItem;
		ReheapUp(0, queuedCallsSize - 1);
	}
}

void PhoneNumber::dequeue_call(Call & item)
{
	if (is_call_list_empty())
		cout << "no call to dequeue" << endl;
	else {
		item = queuedCalls[0];
		queuedCalls[0] = queuedCalls[queuedCallsSize - 1];
		queuedCallsSize--;
		ReheapDown(0, queuedCallsSize - 1);
	}
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

void PhoneNumber::print_queued_calls()
{
	Call *demo;
	for (int index = 0; index < queuedCallsSize; index++)
	{
		demo[index] = queuedCalls[index];
	}

}


void PhoneNumber::print_details()
{
	cout << "\t\t" << operatorName << "\t\t" << number << endl;
	cout << "\t\tCalls:" << endl;
	
	for (int index = 0; index < queuedCallsSize; index++)
	{
		cout <<"\n"<< queuedCalls[index].get_relationship()<<"\t"<<queuedCalls[index].get_durationInSeconds() << endl;
	}
}