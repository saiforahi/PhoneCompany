#include "Customer.h"
#include <iostream>

Customer::Customer()
{
	currentPos = numbers.begin();
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
	while (hasNextNumber())
	{
		getNextNumber().print_details();
	}
	reset_number_list();
}
