#pragma once
#include "Call.h"
#include <string>
#include <queue>
using namespace std;

class PhoneNumber
{
private:
	string number, operatorName;
	priority_queue<Call> calls;
	
public:
	PhoneNumber();
	PhoneNumber(string, string); //parameterized constructor
	~PhoneNumber();

	void set_operatorName(string); //modifier

	//list of accessors

	string get_number();
	string get_operatorName();
	void enqueue_call(Call);
	Call get_call();
	void print_details();
};


