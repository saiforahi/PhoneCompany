#pragma once
#include <string>
#include "Call.h"
#include <vector>
#include "HeapType.h"
using namespace std;

class PhoneNumber
{
private:
	string number, operatorName;
	HeapType queuedCalls;
public:
	PhoneNumber();
	PhoneNumber(string, string); //parameterized constructor
	~PhoneNumber();

	void set_operatorName(string); //modifier
	void enqueue_call(Call);//modifier
	void dequeue_call(Call&);//modifier
	void make_call_list_empty();//modifier

	//list of accessors
	bool is_call_list_empty();
	bool is_call_list_full();
	string get_number();
	bool hasNextCall();
	string get_operatorName();
	int get_callList_size();
	void print_queued_calls();
	void print_details();
};


