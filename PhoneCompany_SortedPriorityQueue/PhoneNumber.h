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
	void enqueue_call(Call);
	void dequeue_call(Call&);
	//list of accessors
	bool is_call_list_full();
	bool is_call_list_empty();
	string get_number();
	string get_operatorName();
	Call get_next_call();
	void make_empty();
	void print_queued_calls();
	void print_details();
};


