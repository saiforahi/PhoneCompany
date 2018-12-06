#include "PhoneNumber.h"
#include <iostream>
using namespace std;


PhoneNumber::PhoneNumber()
{
	listData = nullptr;
	length = 0;
	currentPos = nullptr;
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
	listData = nullptr;
	length = 0;
	currentPos = nullptr;
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

void PhoneNumber::enqueue_call(Call newCall)
{
	if (is_call_list_full())
		return;
	NodeType* newNode = new NodeType;
	newNode->item = newCall;
	NodeType* curr = listData;
	NodeType* prev = nullptr;
	bool posFound = false;
	while (curr != nullptr && !posFound) {
		if (curr->item.get_relationship() < newCall.get_relationship()) {
			prev = curr;
			curr = curr->next;
		}
		else {
			posFound = true;
			newNode->next = curr;
			if (prev == nullptr) {
				listData = newNode;
			}
			else {
				prev->next = newNode;
			}
		}
	}
	if (!posFound)
	{
		posFound = true;
		newNode->next = curr;
		if (prev == nullptr) {
			listData = newNode;
		}
		else {
			prev->next = newNode;
		}
	}
	length++;
}

void PhoneNumber::dequeue_call(Call &callToDequeue)
{
	if (is_call_list_empty()) {
		cout << "Empty queue" << endl;
	}
	else {
		NodeType* dequeuedNode = listData;
		listData = listData->next;
		callToDequeue = dequeuedNode->item;
		delete dequeuedNode;
		this->length--;
	}
}




bool PhoneNumber::is_call_list_full()
{
	try {
		NodeType* newNode = new NodeType;
		delete newNode;
	}
	catch (std::bad_alloc exception) {
		return true;
	}
	return false;
}

bool PhoneNumber::is_call_list_empty()
{
	return length==0 && listData==nullptr;
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