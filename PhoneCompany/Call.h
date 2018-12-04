#pragma once
#include <string>
using namespace std;
enum relationship { spouse = 1, Child = 2, Parent = 3, Sibling = 4, Aunt = 5, Uncle = 5, Cousins = 6, Significant = 7, Friend = 8, Boss = 9, Subordinate = 10, Acquaintance = 11, Blocked = 12 };
class Call
{
	struct callerNumber {
		string number;
		string operatorName;
	};

	struct caller {
		string name;
		string fatherName, motherName;
		string NID, passportNo, drivingLicenseNo;
		string presentAddress, permanentAddress;        //fields of person class
		string maritalStatus, spouseName;
		string height, weight, hairColor, eyeColor;
		string specialMark;
	};
	
private:
	callerNumber callFromNumber;
	caller fromPerson;
	relationship relationshipType;
	int durationInSeconds = 0;
	int hours, minutes, seconds;
public:
	Call();
	Call(string,string, string,string, relationship,int);//parameterized constructor
	
	string get_caller_number();
	string get_caller_operator();
	relationship get_relationship();
	string get_duration();

	~Call();//destructor
};