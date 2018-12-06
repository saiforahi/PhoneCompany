#pragma once
#include <string>
#include "Call.h"
#include <vector>
using namespace std;
const int MAX_SIZE = 100;
class PhoneNumber
{
private:
	string number, operatorName;
	Call* queuedCalls=nullptr;
	int queuedCallsSize = 0;
	int queuedCallsMaxSize = MAX_SIZE;
public:
	PhoneNumber();
	PhoneNumber(string, string); //parameterized constructor
	~PhoneNumber();

	void set_operatorName(string); //modifier
	void enqueue_call(Call);
	void dequeue_call();
	//list of accessors
	void ReheapUp(int,int);
	void ReheapDown(int,int);
	bool is_call_list_empty();
	bool is_call_list_full();
	void swap(Call&,Call&);
	string get_number();
	string get_operatorName();
	void print_details();
};


