#pragma once
#include <string>
#include <queue>
using namespace std;
class PhoneNumber
{
private:
	string number, operatorName;
	priority_queue<int> calls;
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


