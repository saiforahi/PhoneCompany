#include "Customer.h"
#include <iostream>

Customer::Customer()
{
	currentPos = numbers.begin();
}

Customer::Customer(string givenFirstName,  string givenLastName, PhoneNumber firstNumber, string givenFatherName, string givenMotherName, string givenNID, string givenPassportNo, string givenDrivingLicense, string givenPresentAddress, string givenPermanentAddress, string givenMaritalStatus, string givenSpouseName, string givenHeight, string givenWeight, string givenHairColor, string givenEyeColor, string givenSpecialMark, int givenDayOfBirth, int givenMonthOfBirth, int givenYearOfBirth)
{
	set_name(givenFirstName, givenLastName);
	set_dateOfBirth(givenDayOfBirth,givenMonthOfBirth,givenYearOfBirth);
	set_fatherName(givenFatherName);
	set_motherName(givenMotherName);
	set_NID(givenNID);
	set_passportNo(givenPassportNo);
	set_drivingLicense(givenDrivingLicense);
	set_presentAddress(givenPresentAddress);
	set_permanentAddress(givenPermanentAddress);
	set_presentAddress(givenPresentAddress);
	set_maritalStatus(givenMaritalStatus);
	set_spouseName(givenSpouseName);
	set_height(givenHeight);
	set_weight(givenWeight);
	set_hairColor(givenHairColor);
	set_eyeColor(givenEyeColor);
	set_specialMark(givenSpecialMark);
	add_number(firstNumber);
}


Customer::~Customer()
{
	make_empty();
}

void Customer::add_number(PhoneNumber givenNumber)
{
	if (!is_Full())
	{
		bool result = false;
		PhoneNumber dummy = get_phoneNumber(givenNumber, result);
		if (result == false)
		{
			numbers.push_front(givenNumber);
		}
		else
		{
			cout << "\nThis phone number is already added to this customer" << endl;
		}
	}
	else
	{
		cout << "Out of limit!" << endl;
	}
}

void Customer::reset_number_list()
{
	currentPos = numbers.begin();
}

void Customer::make_empty()
{
	numbers.clear();
	reset_number_list();
}

void Customer::delete_number(PhoneNumber numberToDelete)
{
	if (!numbers.empty())
	{
		auto marker = numbers.begin();
		for (; marker != numbers.end(); marker++)
		{
			if (marker->get_number() == numberToDelete.get_number() && marker->get_operatorName() == numberToDelete.get_operatorName())
			{
				numbers.erase(marker);
				break;
			}
		}
	}
}

void Customer::change_operatorName(PhoneNumber numberToChangeOperator)
{
	if (!is_Empty())
	{
		auto marker = numbers.begin();
		for (; marker != numbers.end(); marker++)
		{
			if (marker->get_number() == numberToChangeOperator.get_number())
			{
				marker->set_operatorName(numberToChangeOperator.get_operatorName());
				break;
			}
		}
	}
}

void Customer::enqueue_new_call(Call newCall)
{
	if (!is_Empty())
	{
		auto marker = numbers.begin();
		for (; marker != numbers.end(); marker++)
		{
			if (marker->get_number() == newCall.get_reciever_number() && marker->get_operatorName() == newCall.get_reciever_operator())
			{
				marker->enqueue_call(newCall);
				break;
			}
		}
	}
}

void Customer::dequeue_call(PhoneNumber numberToDequeueCall)
{
	if (!numbers.empty())
	{
		auto marker = numbers.begin();
		for (; marker != numbers.end(); marker++)
		{
			if (marker->get_number() == numberToDequeueCall.get_number() && marker->get_operatorName() == numberToDequeueCall.get_operatorName())
			{
				marker->dequeue_call();
				break;
			}
		}
	}
}


bool Customer::is_Full()
{
	return numbers.size() >= MAX_SIZE;
}

PhoneNumber Customer::get_phoneNumber(PhoneNumber givenNumber, bool& found)
{
	found = false;
	if (!numbers.empty())
	{

		auto marker = numbers.begin();
		for (; marker != numbers.end(); marker++)
		{
			if (marker->get_number() == givenNumber.get_number() && marker->get_operatorName() == givenNumber.get_operatorName())
			{
				found = true;
				return *marker;
			}
		}
		return givenNumber;
	}
	return givenNumber;
}

bool Customer::is_Empty()
{
	return numbers.empty();
}

bool Customer::hasNextNumber()
{
	return currentPos != numbers.end();
}

PhoneNumber Customer::getNextNumber()
{
	if (hasNextNumber())
	{
		PhoneNumber numberToReturn = *currentPos;
		currentPos++;
		return numberToReturn;
	}
}

int Customer::get_length()
{
	return numbers.size();
}

void Customer::print_details()
{
	reset_number_list();
	cout << "\n\tPrinting details for customer " << get_name() << endl;
	cout << "\n\tNID:\t" << get_NID() << "\t\ttotal " << get_length() << " numbers\n" << endl;
	cout << "\tFather:\t" << get_fatherName() << endl;
	cout << "\tMother:\t" << get_motherName()<< endl;
	cout << "\tMarital Status:\t" << get_maritalStatus() << endl;
	cout << "\tSpouse:\t" << get_spouseName() << endl;
	cout << "\tpresent Address:\t" << get_presentAddress() << endl;
	cout << "\tPermanent Address:\t" << get_permanentAddress() << endl;
	while (hasNextNumber())
	{
		getNextNumber().print_details();
		cout << "\n" << endl;
	}
	reset_number_list();
}

