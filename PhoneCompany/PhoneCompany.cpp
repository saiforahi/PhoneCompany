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
	Customer A("Shinha","Azad", number1, "Abul Kalam Azad", "Belly","18842013333","BK023594","112453567","Dhaka","Bogra","Married","Nurzahan Azad","5 ft 5 inches","60 kg","Black","black","spot on left arm",12,1,1964);
	Customer B("Nurzahan", "Azad", number5, "Nannu", "Monoara", "19728014444", "BL253676", "115732987", "Bogra", "Joypurhat", "Married", "Shinha Azad", "5 ft 3 inches", "65 kg", "Black", "Gray", "11 fingers",8,2,1974);
	Customer C("Rehab", "Liton", number9, "Liton", "Bepary", "19945017777", "BZ032599", "131043267", "Dhaka", "Tripoli", "Married", "Shaif Azad Rahi", "5 ft 5 inches", "55 kg", "Black", "black", "Dimple", 5, 6, 1992);
	Customer D("Naima", "Esha", number13, "Shinha Azad", "Nurzahan Azad", "19987098888", "BM023366", "191053333", "Dhaka", "Bogra", "Single", "Not Applicable", "5 ft 3 inches", "55 kg", "Black", "Black", "BookWorm", 11, 2, 1998);
	
	database.insert_customer(A);
	database.insert_customer(B);
	database.insert_customer(C);
	database.insert_customer(D);

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
	
	
	Person P1("Irfan", "Khan","XXXXXXXXXXX");
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
	Person P23("Nasima","Akhter","KKKKKKKKKKK");
	Person P24("Liton", "Bepary","EEEEEEEEEEE");
	Person P25("Aiman", "Akash", "NNNNNNNNNNN");
	Person P26("Osama", "Shishir", "11111111111");
	Person P27("Neyamot", "Ali", "22222222222");
	Person P28("Shaikot", "Hasan", "33333333333");
	Person P29("Moinul", "Mahmud", "19921083512");
	Person P30("Shawrid", "Shams", "19921083512");
	Call call1("01671919344", "Robi",number1.get_number(),number1.get_operatorName(),P1, Subordinate, 4250);
	Call call2("01XXXXXXXXX","GP",number2.get_number(), number2.get_operatorName(), P2, Parent, 5250);
	Call call2("01XXXXXXXXX", "GP", number2.get_number(), number2.get_operatorName(), P2, Parent, 5250);
	number1.enqueue_call(call1);
	number1.enqueue_call(call2);
	number1.enqueue_call(call3);
	Call demo = number1.get_call();
	cout << "\n\npoped call's relationship:\t" << demo.get_relationship() << endl;
	cout << "poped call's duration:\t" << demo.get_duration() << endl;
	cout << "poped call's relationship:\t" << demo.get_caller().get_name() << endl;
	return 0;
}

