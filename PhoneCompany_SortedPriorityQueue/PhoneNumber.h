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
	bool is_call_list_full();//accessor
	bool is_call_list_empty();//accessor
	int get_call_list_size();//accessor
	string get_number();//accessor
	string get_operatorName();//accessor
	Call get_next_call();//accessor
	bool hasNextCall();//accessor
	void make_empty();//modifier
	void print_queued_calls();//accessor
	void print_details();//accessor
};


