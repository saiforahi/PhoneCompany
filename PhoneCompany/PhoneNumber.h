#pragma once
#include "Call.h"
#include <string>
#include <queue>

using namespace std;


struct call_compare
{
	bool operator()(Call call1, Call call2)
	{
		if (call1.get_relationship() > call2.get_relationship())
			return true;
		else if (call1.get_relationship() == call2.get_relationship())
		{
			if (call1.get_durationInSeconds() < call2.get_durationInSeconds())
				return true;
			else
				return false;
		}
		else
			return false;
	}
};

class PhoneNumber
{
private:
	typedef priority_queue< Call, std::vector<Call>, call_compare > queuedCalls;
	string number;
	string operatorName;
	queuedCalls calls;
public:
	PhoneNumber();
	PhoneNumber(string, string); //parameterized constructor
	~PhoneNumber();

	void set_operatorName(string); //modifier
	void enqueue_call(Call);
	
	//list of accessors
	string get_number();
	string get_operatorName();
	
	Call get_call();
	Call get_next_call();
	void print_details();
};


