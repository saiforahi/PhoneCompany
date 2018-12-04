#pragma once
#include <string>
#include "Person.h"
using namespace std;
enum relationship { spouse = 1, Child = 2, Parent = 3, Sibling = 4, Aunt = 5, Uncle = 5, Cousins = 6, Significant = 7, Friend = 8, Boss = 9, Subordinate = 10, Acquaintance = 11, Blocked = 12 };
class Call
{
	struct callerNumber {
		string number;
		string operatorName;
	};
	
private:
	callerNumber callFromNumber;
	Person caller;
	relationship relationshipType;
	int durationInSeconds = 0;
	int hours, minutes, seconds;
public:
	Call();
	Call(string,string, Person, relationship,int);//parameterized constructor
	
	string get_caller_number();//accessor
	string get_caller_operator();//accessor
	relationship get_relationship();//accessor
	string get_duration();//accessor
	int get_durationInSeconds();//accessor
	Person get_caller();//modifier
	void set_duration(int);//modifier
	void update_duration(int);//modifier
	void print_call();
	~Call();//destructor
};