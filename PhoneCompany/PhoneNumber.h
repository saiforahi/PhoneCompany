#pragma once
#include "Call.h"
#include <string>
#include <queue>
#include <functional>
using namespace std;


struct comparision
{
	bool operator()(Call c, Call v)
	{
		if (c.get_relationship() > v.get_relationship())
			return true;
		else if (c.get_relationship() == v.get_relationship())
		{
			if (c.get_relationship() < v.get_relationship())
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
	void print_details();
};


