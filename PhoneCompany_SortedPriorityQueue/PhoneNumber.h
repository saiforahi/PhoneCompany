#pragma once
#include <string>
#include "Call.h"
using namespace std;
class PhoneNumber
{
	struct NodeType
	{
		Call item;
		NodeType* next=nullptr;
	};
private:
	string number, operatorName;
	NodeType* listData=nullptr;
	int length = 0;
	NodeType* currentPos = nullptr;
public:
	PhoneNumber();
	PhoneNumber(string, string); //parameterized constructor
	~PhoneNumber();

	void set_operatorName(string); //modifier
	
	//list of accessors

	string get_number();
	string get_operatorName();
	void print_details();
};


