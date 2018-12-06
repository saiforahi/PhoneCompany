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

string PhoneNumber::get_number()
{
	return number;
}

string PhoneNumber::get_operatorName()
{
	return operatorName;
}

void PhoneNumber::enqueue_call(Call newCall)
{
	calls.push(newCall);
}

Call PhoneNumber::dequeue_call()
{
	if (!calls.empty())
	{
		Call demo = calls.top();
		calls.pop();
		return demo;
	}
	return Call();
}

Call PhoneNumber::get_next_call()
{
	return calls.top();
}

void PhoneNumber::print_queued_calls()
{
	if (calls.empty())
	{
		cout << "  \t\t\t\t\tno calls  " << endl;
	}
	else
	{
		queuedCalls demo = calls;
		Call dummy;
		while (!demo.empty())
		{
			dummy = demo.top();
			dummy.print_call();
			demo.pop();
		}
	}
}

void PhoneNumber::print_details()
{
	cout << "\n\t" << operatorName << "\t" << number << endl;
	cout << "\t\tCalls:" << endl;
	print_queued_calls();
}


