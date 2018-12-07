#pragma once
#include <string>
#include "Call.h"
#include <vector>
using namespace std;
const int MAXIMUM_SIZE = 100;
class PhoneNumber
{
private:
	string number, operatorName;
	Call* queuedCalls=nullptr;
	int queuedCallsSize = 0;
	int queuedCallsMaxSize = MAXIMUM_SIZE;
public:
	PhoneNumber();
	PhoneNumber(string, string); //parameterized constructor
	~PhoneNumber();

	void set_operatorName(string); //modifier
	void enqueue_call(Call);
	void dequeue_call(Call&);
	void Heapify_callList();
	void ReheapDown(int, int);
	void ReheapUp(int, int);
	//list of accessors
	bool is_call_list_empty();
	bool is_call_list_full();
	void swap(Call&,Call&);
	string get_number();
	string get_operatorName();
	void print_queued_calls();
	void print_details();
};


