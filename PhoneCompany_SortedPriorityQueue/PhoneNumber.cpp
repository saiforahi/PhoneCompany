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
		else if (curr->item.get_relationship() == newCall.get_relationship())
		{
			if (curr->item.get_durationInSeconds() >= newCall.get_durationInSeconds())
			{
				prev = curr;
				curr = curr->next;
			}
			else if (curr->item.get_durationInSeconds() < newCall.get_durationInSeconds())
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

void PhoneNumber::dequeue_call(Call & dequeuedCall)
{
	if (is_call_list_empty()) {
		cout << "Empty queue" << endl;
	}
	else {
		NodeType* dequeuedNode = listData;
		listData = listData->next;
		dequeuedCall = dequeuedNode->item;
		delete dequeuedNode;
		this->length--;
	}
}


bool PhoneNumber::hasNextCall()
{
	return listData != nullptr;
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

int PhoneNumber::get_call_list_size()
{
	return length;
}

string PhoneNumber::get_number()
{
	return number;
}

string PhoneNumber::get_operatorName()
{
	return operatorName;
}

Call PhoneNumber::get_next_call()
{
	if (!is_call_list_empty())
	{
		return listData->item;
	}
	return Call();
}

void PhoneNumber::make_empty()
{
	NodeType* locationToDelete = nullptr;
	while (listData != nullptr) {
		locationToDelete = listData;
		listData = listData->next;
		if (currentPos == locationToDelete) {
			currentPos = currentPos->next;
		}
		delete locationToDelete;
		length--;
	}
}

void PhoneNumber::print_queued_calls()
{
	if (!is_call_list_empty())
	{
		NodeType* demo = listData;
		while (demo != nullptr)
		{
			demo->item.print_call();
			demo = demo->next;
		}
	}
	else
		cout << "  \t\t\t\t\tno calls  " << endl;
}


void PhoneNumber::print_details()
{
	cout << "\n\t" << operatorName << "\t" << number << endl;
	cout << "\t\tCalls:" << endl;
	print_queued_calls();
}