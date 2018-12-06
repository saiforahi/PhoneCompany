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

void PhoneNumber::dequeue_call()
{
	if (is_call_list_empty())
		cout<<"no call to dequeue"<<endl;
	else {
		queuedCalls[0] = queuedCalls[queuedCallsSize - 1];
		queuedCallsSize--;
		ReheapDown(0, queuedCallsSize - 1);
	}
}

void PhoneNumber::ReheapUp(int root, int bottom)
{
	
	int parent=(bottom-1)/2;
	if (parent < root)
		return;
	else if (queuedCalls[parent].get_relationship() > queuedCalls[bottom].get_relationship())
	{
		swap(queuedCalls[parent], queuedCalls[bottom]);
		ReheapUp(root, parent);
	}
	else if (queuedCalls[bottom].get_relationship() == queuedCalls[parent].get_relationship())
	{
		if (queuedCalls[bottom].get_durationInSeconds() > queuedCalls[root].get_durationInSeconds()) {
			swap(queuedCalls[parent], queuedCalls[bottom]);
			ReheapUp(root, parent);
		}
	}
	
}

void PhoneNumber::ReheapDown(int root, int bottom)
{
	int maxChild;
	int rightChild;
	int leftChild;
	leftChild = root * 2 + 1;
	rightChild = root * 2 + 2;
	if (leftChild <= bottom)
	{
		if (leftChild == bottom)
			maxChild = leftChild;
		else
		{
			if (queuedCalls[leftChild].get_relationship() >= queuedCalls[rightChild].get_relationship())
				maxChild = rightChild;
			else
				maxChild = leftChild;
		}
		if (queuedCalls[root].get_relationship() > queuedCalls[maxChild].get_relationship()) {
			swap(queuedCalls[root], queuedCalls[maxChild]);
			ReheapDown(maxChild, bottom);
		}
		if (queuedCalls[root].get_relationship() == queuedCalls[maxChild].get_relationship()) {
			if (queuedCalls[root].get_durationInSeconds() < queuedCalls[maxChild].get_durationInSeconds())
			{
				swap(queuedCalls[root], queuedCalls[maxChild]);
				ReheapDown(maxChild, bottom);
			}
		}
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

void PhoneNumber::print_details()
{
	cout << "\t\t" << operatorName << "\t\t" << number << endl;
}