#include "KomKothaKoiben.h"
#include <iostream>
using namespace std;

KomKothaKoiben::KomKothaKoiben()
{
	currentPos = customerList.begin();
}


KomKothaKoiben::~KomKothaKoiben()
{
	make_empty();
}

void KomKothaKoiben::insert_customer(Customer newCustomer)
{
	if (newCustomer.get_length() > 0)
	{
		if (customerList.size() == 0)
		{
			customerList.push_front(newCustomer);
		}
		else
		{
			bool found = false;
			Customer check = get_customer(newCustomer.get_NID(), found);
			if (!found)
			{
				auto sorter = customerList.begin();
				bool done = false;
				for (; sorter != customerList.end(); sorter++)
				{
					if (sorter->get_length() >= newCustomer.get_length())
					{
						customerList.insert(sorter, newCustomer);
						done = true;
						break;
					}
				}
				if (!done)
					customerList.push_back(newCustomer);
			}
			else
			{
				cout << "Customer alreday exists, request is denied" << endl;
			}
		}
	}
}

void KomKothaKoiben::delete_customer(string givenNID)
{
	if (!customerList.empty())
	{
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				customerList.erase(marker);
				break;
			}
		}
	}
}

void KomKothaKoiben::add_new_number(string givenNID, PhoneNumber newNumber)
{
	if (!customerList.empty())
	{
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				Customer customerToUpdate = *marker;
				customerToUpdate.add_number(newNumber);
				delete_customer(customerToUpdate.get_NID());
				insert_customer(customerToUpdate);
				break;
			}
		}
	}
}

void KomKothaKoiben::delete_number(string givenNID, PhoneNumber numberToDelete)
{
	if (!customerList.empty())
	{
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				Customer customerToUpdate = *marker;
				customerToUpdate.delete_number(numberToDelete);
				if (customerToUpdate.get_length() == 0)
				{
					delete_customer(customerToUpdate.get_NID());
					break;
				}
				else
				{
					delete_customer(customerToUpdate.get_NID());
					insert_customer(customerToUpdate);
					break;
				}
			}
		}
	}
}

void KomKothaKoiben::change_operatorName_of_customer(string givenNID, PhoneNumber numberToUpdate)
{
	if (!customerList.empty())
	{
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				marker->change_operatorName(numberToUpdate);
				break;
			}
		}
	}
}

void KomKothaKoiben::print_database()
{
	auto marker = customerList.begin();
	cout << "\n\nKomKothaKoiben ForwardList Database:\t\t total customers " << get_length() << endl;
	for (; marker != customerList.end(); marker++)
	{
		marker->print_details();
	}
}

Customer KomKothaKoiben::get_customer(string givenNID, bool& found)
{
	if (!customerList.empty())
	{
		found = false;
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				found = true;
				return *marker;
			}
		}
		return Customer();
	}
}

void KomKothaKoiben::make_empty()
{
	customerList.clear();
	reset_database();
}

void KomKothaKoiben::reset_database()
{
	currentPos = customerList.begin();
}

void KomKothaKoiben::customer_enqueueCall(string givenNID, Call newCall)
{
	if (!customerList.empty())
	{
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				marker->enqueue_new_call(newCall);
				break;
			}
		}
	}
}

void KomKothaKoiben::customer_dequeueCall(string givenNID, PhoneNumber givenPhoneNumber,Call & dequeuedCallFromCustomer)
{
	if (!customerList.empty())
	{
		auto marker = customerList.begin();
		for (; marker != customerList.end(); marker++)
		{
			if (marker->get_NID() == givenNID)
			{
				marker->dequeue_call(givenPhoneNumber, dequeuedCallFromCustomer);
				break;
			}
		}
	}
}

int KomKothaKoiben::get_length()
{
	return customerList.size();
}

bool KomKothaKoiben::is_empty()
{
	return customerList.empty();
}

Customer KomKothaKoiben::getNextCustomer()
{
	if (currentPos != customerList.end())
	{
		Customer customerToReturn = *currentPos;
		currentPos++;
		return customerToReturn;
	}
}

bool KomKothaKoiben::hasNextCustomer()
{
	return currentPos != customerList.end();
}
