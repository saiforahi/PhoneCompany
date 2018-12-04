#include <iostream>
#include "Customer.h"
#include "KomKothaKoiben.h"
#include "Call.h"
using namespace std;
int main()
{
	/*KomKothaKoiben database;
	Customer customerSaif, customerNaima, customerAzad, customerRikta;
	PhoneNumber number1("01737552558", "GP");
	PhoneNumber number2("01854440588", "ROBI");
	PhoneNumber number3("01556307506", "TELETALK");
	PhoneNumber number4("01416471608", "KomKothaKoiben");
	PhoneNumber number5("01786490167", "GP");
	PhoneNumber number6("01999900439", "banglalink");
	PhoneNumber number7("01856561345", "robi");
	PhoneNumber number8("01555555608", "teletalk");
	PhoneNumber number9("01416444664", "KomKothaKoiben");
	PhoneNumber number10("01937554058", "banglalink");
	PhoneNumber number11("01711000151", "GP");
	PhoneNumber number12("01929676123", "banglalink");
	PhoneNumber number13("01898763245", "robi");
	PhoneNumber number14("01508988766", "teletalk");
	PhoneNumber number15("01400111222", "KomKothaKoiben");
	PhoneNumber number16("01969337634", "banglalink");

	customerSaif.set_name("shaif", "rahi");
	customerSaif.set_NID("19921234567");
	customerSaif.add_number(number1);
	customerSaif.add_number(number2);

	customerNaima.set_name("Naim", "Esha");
	customerNaima.set_NID("20003496103");
	customerNaima.add_number(number3);
	customerNaima.add_number(number4);
	customerNaima.add_number(number8);
	customerNaima.add_number(number9);

	customerAzad.set_name("Shinha", "Azad");
	customerAzad.set_NID("19611264535");
	customerAzad.add_number(number3);
	customerAzad.add_number(number4);
	customerAzad.add_number(number5);
	customerAzad.add_number(number2);
	customerAzad.add_number(number1);
	customerAzad.add_number(number8);

	customerRikta.set_name("Nurzahan", "Rikta");
	customerRikta.set_NID("19746536271");
	customerRikta.add_number(number8);

	//operating database actions
	
	database.insert_customer(customerSaif);
	database.insert_customer(customerNaima);

	database.print_database();

	bool result = false;
	Customer customerToUpdate = database.get_customer(customerNaima.get_NID(), result);
	if (result)
	{
		database.add_new_number(customerToUpdate.get_NID(), number1);
	}
	cout << "\n\nafter adding a number to existing customer......." << endl;
	database.print_database();
	cout << "\nInserting another new customer in database....." << endl;
	database.insert_customer(customerAzad);
	cout << "\n\nafter adding a customer to database......." << endl;
	database.print_database();
	cout << "\n\nadding five more new customers into database......." << endl;
	database.insert_customer(customerRikta);
	
	cout << "\n\nafter adding ......." << endl;
	database.print_database();
	cout << "\n\nDeleting phone numbers of Customer NAIMA ......." << endl;
	bool search = false;
	Customer customerToDeleteNumber = database.get_customer(customerNaima.get_NID(), search);
	if (search)
	{
		customerToDeleteNumber.reset_number_list();
		for (int index = 0; index < customerToDeleteNumber.get_length(); index++)
		{
			database.delete_number(customerToDeleteNumber.get_NID(), customerToDeleteNumber.getNextNumber());
		}
	}

	//cout << "\n\nafter deleting all numbers of customer NAIMA ......" << endl;

	//database.print_database();*/
	PhoneNumber number1("01737552558", "GP");
	Person p1("saif", "rahi");
	Call call1(number1.get_number(),p1.get_name(),spouse);
	
	number1.enqueue_call(call1);
	Call demo = number1.get_call();
	cout << "\n\ntop call's relationship:\t" << demo.get_relationship() << endl;
	return 0;
}

