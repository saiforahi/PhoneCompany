#include <iostream>
#include "Customer.h"
#include "KomKothaKoiben.h"
#include "Call.h"
using namespace std;
int main()
{
	KomKothaKoiben database;
	PhoneNumber number1("01737552558", "GP");
	PhoneNumber number2("01854440588", "ROBI");
	PhoneNumber number3("01556307506", "TELETALK");
	PhoneNumber number4("01416471608", "KomKothaKoiben");
	Customer A("Shinha","Azad", number1, "Abul Kalam Azad", "Belly","18842013333","BK023594","112453567","Dhaka","Bogra","Married","Nurzahan Azad","5 ft 5 inches","60 kg","Black","black","spot on left arm");
	Customer B("Nurzahan", "Azad", number2, "Nannu", "Monoara", "19728014444", "BL253676", "115732987", "Bogra", "Joypurhat", "Married", "Shinha Azad", "5 ft 3 inches", "65 kg", "Black", "Gray", "11 fingers");

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

	//database.print_database();
	Person p1("saif", "rahi");
	Person p2("Naim", "Esha");
	Person p3("Rehab", "Jenny");
	Person p4("Nurzahan", "Azad");
	Call call1(number10.get_number(), number10.get_operatorName(),p4, Parent, 4250);
	Call call2(number2.get_number(), number2.get_operatorName(), p2, Parent, 5250);
	Call call3(number3.get_number(), number3.get_operatorName(), p3, Sibling, 3250);
	number1.enqueue_call(call1);
	number1.enqueue_call(call2);
	number1.enqueue_call(call3);
	Call demo = number1.get_call();
	cout << "\n\npoped call's relationship:\t" << demo.get_relationship() << endl;
	cout << "poped call's duration:\t" << demo.get_duration() << endl;
	cout << "poped call's relationship:\t" << demo.get_caller().get_name() << endl;
	return 0;
}

