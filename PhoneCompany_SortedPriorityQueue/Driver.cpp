#include <iostream>
#include "Customer.h"
#include "KomKothaKoiben.h"
#include "Call.h"
using namespace std;
int main()
{
	//declaring 30 persons 

	Person P1("Irfan", "Khan", "XXXXXXXXXXX");
	Person P2("Fahim", "Uddin", "YYYYYYYYYYY");
	Person P3("Tayeba", "Ayub", "AAAAAAAAAAA");
	Person P4("Mehedy", "Hasan", "MMMMMMMMMMM");
	Person P5("Happy", "sadia", "PPPPPPPPPPP");
	Person P6("Nurnahar", "Jhorna", "QQQQQQQQQQQ");
	Person P7("Amena", "Begum", "TTTTTTTTTTT");
	Person P8("Karnain", "Shibli", "GGGGGGGGGGG");
	Person P9("Julfikar", "Azad", "SSSSSSSSSSS");
	Person P10("Monoara", "Begum", "JJJJJJJJJJJ");
	Person P11("Sadrul", "Anam", "LLLLLLLLLLL");
	Person P12("Shihab", "Anam", "UUUUUUUUUUU");
	Person P13("Hira", "mama", "WWWWWWWWWWW");
	Person P14("Panna", "Vai", "RRRRRRRRRRR");
	Person P15("Tapu", "Tapu", "IIIIIIIIIII");
	Person P16("saif", "rahi", "OOOOOOOOOOO");
	Person P17("Rakib", "Hasan", "BBBBBBBBBBB");
	Person P18("Munna", "bhai", "CCCCCCCCCCC");
	Person P19("Shahad", "Abdullah", "ZZZZZZZZZZZ");
	Person P20("Salauddin", "Kashif", "FFFFFFFFFFF");
	Person P21("Shahida", "Nasir", "DDDDDDDDDDD");
	Person P22("Digital", "Hujur", "HHHHHHHHHHH");
	Person P23("Nasima", "Akhter", "KKKKKKKKKKK");
	Person P24("Liton", "Bepary", "EEEEEEEEEEE");
	Person P25("Aiman", "Akash", "NNNNNNNNNNN");
	Person P26("Osama", "Shishir", "11111111111");
	Person P27("Neyamot", "Ali", "22222222222");
	Person P28("Shaikot", "Hasan", "33333333333");
	Person P29("Moinul", "Mahmud", "19921083512");
	Person P30("Shawrid", "Shams", "19921083512");

	//declaring 16 different phone numbers
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

	//declaring database for phone company
	KomKothaKoiben database;

	Customer A("Shinha", "Azad", number1, "Abul Kalam Azad", "Belly", "18842013333", "BK023594", "112453567", "Dhaka", "Bogra", "Married", "Nurzahan Azad", "5 ft 5 inches", "60 kg", "Black", "black", "spot on left arm", 12, 1, 1964);
	Customer B("Nurzahan", "Azad", number5, "Nannu", "Monoara", "19728014444", "BL253676", "115732987", "Bogra", "Joypurhat", "Married", "Shinha Azad", "5 ft 3 inches", "65 kg", "Black", "Gray", "11 fingers", 8, 2, 1974);
	Customer C("Rehab", "Liton", number9, "Liton", "Bepary", "19945017777", "BZ032599", "131043267", "Dhaka", "Tripoli", "Married", "Shaif Azad Rahi", "5 ft 5 inches", "55 kg", "Black", "black", "Dimple", 5, 6, 1992);
	Customer D("Naima", "Esha", number13, "Shinha Azad", "Nurzahan Azad", "19987098888", "BM023366", "191053333", "Dhaka", "Bogra", "Single", "Not Applicable", "5 ft 3 inches", "55 kg", "Black", "Black", "BookWorm", 11, 2, 1998);

	database.insert_customer(A);
	database.insert_customer(B);
	database.insert_customer(C);
	database.insert_customer(D);

	//adding different numbers to existing customers
	database.add_new_number(A.get_NID(), number2);
	database.add_new_number(A.get_NID(), number3);
	database.add_new_number(A.get_NID(), number4);

	database.add_new_number(B.get_NID(), number6);
	database.add_new_number(B.get_NID(), number7);
	database.add_new_number(B.get_NID(), number8);

	database.add_new_number(C.get_NID(), number10);
	database.add_new_number(C.get_NID(), number11);
	database.add_new_number(C.get_NID(), number12);

	database.add_new_number(D.get_NID(), number14);
	database.add_new_number(D.get_NID(), number15);
	database.add_new_number(D.get_NID(), number16);


	//declaring 20 call object for Customer B
	Call call1("01671919344", "Robi", "01999900439", "banglalink", "19728014444", P1, Subordinate, 4250);
	Call call2("01XXXXXXXXX", "GP", "01999900439", "banglalink", "19728014444", P2, Friend, 5250);
	Call call3("01XXXXXXXXX", "GP", "01999900439", "banglalink", "19728014444", P1, Subordinate, 1000);
	Call call4("01XXXXXXXXX", "GP", "01999900439", "banglalink", "19728014444", P3, Spouse, 16534);
	Call call5("01XXXXXXXXX", "GP", "01999900439", "banglalink", "19728014444", P3, Child, 209864);

	Call call6("01XXXXXXXXX", "GP", "01856561345", "robi", "19728014444", P4, Boss, 23982);
	Call call7("01XXXXXXXXX", "GP", "01856561345", "robi", "19728014444", P5, Relatives, 28496);
	Call call8("01XXXXXXXXX", "GP", "01856561345", "robi", "19728014444", P6, Parent, 26372);
	Call call9("01XXXXXXXXX", "GP", "01856561345", "robi", "19728014444", P6, Parent, 18725);
	Call call10("01XXXXXXXXX", "GP", "01856561345", "robi", "19728014444", P7, Sibling, 9853);
	Call call11("01XXXXXXXXX", "GP", "01555555608", "teletalk", "19728014444", P6, Parent, 12250);
	Call call12("01XXXXXXXXX", "GP", "01555555608", "teletalk", "19728014444", P6, Parent, 13250);
	Call call13("01XXXXXXXXX", "GP", "01555555608", "teletalk", "19728014444", P7, Sibling, 12250);
	Call call14("01XXXXXXXXX", "GP", "01555555608", "teletalk", "19728014444", P6, Parent, 73632);
	Call call15("01XXXXXXXXX", "GP", "01555555608", "teletalk", "19728014444", P20, Blocked, 9873);

	Call call16("01XXXXXXXXX", "GP", "01786490167", "GP", "19728014444", P3, Spouse, 12250);
	Call call17("01XXXXXXXXX", "GP", "01786490167", "GP", "19728014444", P19, Blocked, 12250);
	Call call18("01XXXXXXXXX", "GP", "01786490167", "GP", "19728014444", P14, Acquaintance, 1250);
	Call call19("01XXXXXXXXX", "GP", "01786490167", "GP", "19728014444", P14, Acquaintance, 16750);
	Call call20("01XXXXXXXXX", "GP", "01786490167", "GP", "19728014444", P7, Sibling, 19730);


	//declaring 20 call object for Customer C
	Call call21("01671919344", "Robi", "01937554058", "banglalink", "19945017777", P1, Parent, 4250);
	Call call22("01XXXXXXXXX", "banglalink", "01937554058", "banglalink", "19945017777", P2, Parent, 5250);
	Call call23("01XXXXXXXXX", "teletalk", "01937554058", "banglalink", "19945017777", P1, Subordinate, 1000);
	Call call24("01XXXXXXXXX", "teletalk", "01937554058", "banglalink", "19945017777", P3, Spouse, 16534);
	Call call25("01XXXXXXXXX", "GP", "01937554058", "banglalink", "19945017777", P3, Child, 209864);
	Call call26("01XXXXXXXXX", "teletalk", "01711000151", "GP", "19945017777", P4, Boss, 23982);
	Call call27("01XXXXXXXXX", "teletalk", "01711000151", "GP", "19945017777", P5, Relatives, 28496);
	Call call28("01XXXXXXXXX", "GP", "01711000151", "GP", "19945017777", P6, Subordinate, 26372);
	Call call29("01XXXXXXXXX", "GP", "01711000151", "GP", "19945017777", P6, Parent, 18725);
	Call call30("01XXXXXXXXX", "banglalink", "01711000151", "GP", "19945017777", P7, Sibling, 9853);//
	Call call31("01XXXXXXXXX", "teletalk", "01929676123", "banglalink", "19945017777", P6, Parent, 2422422);
	Call call32("01XXXXXXXXX", "banglalink", "01929676123", "banglalink", "19945017777", P6, Parent, 242424);
	Call call33("01XXXXXXXXX", "GP", "01929676123", "banglalink", "19945017777", P7, Sibling, 12250);
	Call call34("01XXXXXXXXX", "01929676123", "banglalink", "teletalk", "19945017777", P6, Parent, 73632);
	Call call35("01XXXXXXXXX", "GP", "01929676123", "banglalink", "19945017777", P20, Blocked, 9873);
	Call call36("01XXXXXXXXX", "banglalink", "01416444664", "KomKothaKoiben", "19945017777", P3, Spouse, 3444435);
	Call call37("01XXXXXXXXX", "Robi", "01416444664", "KomKothaKoiben", "19945017777", P19, Blocked, 35352);
	Call call38("01XXXXXXXXX", "Robi", "01416444664", "KomKothaKoiben", "19945017777", P14, Acquaintance, 24422);
	Call call39("01XXXXXXXXX", "banglalink", "01416444664", "KomKothaKoiben", "19945017777", P14, Acquaintance, 434384);
	Call call40("01XXXXXXXXX", "Robi", "01416444664", "KomKothaKoiben", "19945017777", P7, Sibling, 20085);

	//adding calls to customer B 
	database.customer_enqueueCall("19728014444", call1);
	database.customer_enqueueCall("19728014444", call2);
	database.customer_enqueueCall("19728014444", call3);
	database.customer_enqueueCall("19728014444", call4);
	database.customer_enqueueCall("19728014444", call5);
	database.customer_enqueueCall("19728014444", call6);
	database.customer_enqueueCall("19728014444", call7);
	database.customer_enqueueCall("19728014444", call8);
	database.customer_enqueueCall("19728014444", call9);
	database.customer_enqueueCall("19728014444", call10);
	database.customer_enqueueCall("19728014444", call11);
	database.customer_enqueueCall("19728014444", call12);
	database.customer_enqueueCall("19728014444", call13);
	database.customer_enqueueCall("19728014444", call14);
	database.customer_enqueueCall("19728014444", call15);
	database.customer_enqueueCall("19728014444", call16);
	database.customer_enqueueCall("19728014444", call17);
	database.customer_enqueueCall("19728014444", call18);
	database.customer_enqueueCall("19728014444", call19);
	database.customer_enqueueCall("19728014444", call20);

	//adding calls to customer C
	database.customer_enqueueCall("19945017777", call21);
	database.customer_enqueueCall("19945017777", call22);
	database.customer_enqueueCall("19945017777", call23);
	database.customer_enqueueCall("19945017777", call24);
	database.customer_enqueueCall("19945017777", call25);
	database.customer_enqueueCall("19945017777", call26);
	database.customer_enqueueCall("19945017777", call27);
	database.customer_enqueueCall("19945017777", call28);
	database.customer_enqueueCall("19945017777", call29);
	database.customer_enqueueCall("19945017777", call30);
	database.customer_enqueueCall("19945017777", call31);
	database.customer_enqueueCall("19945017777", call32);
	database.customer_enqueueCall("19945017777", call33);
	database.customer_enqueueCall("19945017777", call34);
	database.customer_enqueueCall("19945017777", call35);
	database.customer_enqueueCall("19945017777", call36);
	database.customer_enqueueCall("19945017777", call37);
	database.customer_enqueueCall("19945017777", call38);
	database.customer_enqueueCall("19945017777", call39);
	database.customer_enqueueCall("19945017777", call40);
	database.print_database();
	return 0;
}