#pragma once
#include "Call.h"
#include <string>
#include <queue>

using namespace std;


struct comparision
{
	bool operator()(Call call1, Call call2)
	{
		if (call1.get_relationship() > call2.get_relationship())
			return true;
		else if (call1.get_relationship() == call2.get_relationship())
		{
			if (call1.get_relationship() < call2.get_relationship())
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
	typedef priority_queue< Call, std::vector<Call>, comparision > queuedCalls;
	string number;
	string operatorName;
	queuedCalls calls;
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
	Call get_next_call();
	void print_details();
};


