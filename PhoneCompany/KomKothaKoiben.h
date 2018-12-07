#pragma once
#include "Customer.h"
class KomKothaKoiben
{

private:
	list <Customer> customerList;
	list<Customer>::iterator currentPos;

public:
	KomKothaKoiben();
	~KomKothaKoiben();

	void insert_customer(Customer);//modifier
	void delete_customer(string);//modifier
	void make_empty();//modifier
	void add_new_number(string, PhoneNumber);//modifier
	void delete_number(string, PhoneNumber);//modifier
	void change_operatorName_of_customer(string, PhoneNumber);//modifier
	void reset_database();//modifier
	void customer_enqueueCall(string,Call);
	void customer_dequeueCall(string, PhoneNumber,Call&);
	void print_database();//accessors
	int get_length();//accessor
	bool is_empty();//accessor
	Customer get_customer(string, bool&);//accessor
	Customer getNextCustomer();//accessor
	bool hasNextCustomer();//accessor
};

