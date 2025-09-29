#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	MyString obj1("Hello world");
	obj1.Print();

	MyString obj2 = obj1;
	obj2.Print();

	cout << obj1.MyStrStr("woy") << endl;
	cout << obj1.MyStrStr("wor") << endl;
	cout << obj1.MyStrStr("lo wo") << endl;
	cout << obj1.MyStrStr("wok") << endl;


	obj2.Input();
	obj2.Print();

	MyString obj3;
	obj3.MyStrcpy(obj1);
	obj3.Print();

	cout << obj1.MyChr('w') << endl;
	cout << obj1.MyChr('z') << endl;

	cout << obj1.MyStrLen() << endl;

	MyString obj4(". Ralph");
	obj1.MyStrCat(obj4);
	obj1.Print();

	obj1.MyDelChr('l');
	obj1.Print();

	cout << obj1.MyStrCmp(obj3) << endl;

	MyString obj5 = move(obj2);
	obj5.Print();


	MyString::PrintCount();
	MyString obj6;

	MyString::PrintCount();

	obj6.PrintCount();


	MyString obj7("Hello ");
	obj7.Print();

	MyString res1 = obj7 + "aiii_i";
	res1.Print();

	MyString obj8("world");
	MyString res2 = obj7 + obj8;
	res2.Print();

	MyString res3 = obj7 - 'l';
	res3.Print();
	cout << "\n\n";


	MyString a("Hello");
	MyString b("world");

	a++;
	a.Print();

	a--;
	a.Print();

	a += " world";
	a.Print();

	a += b;
	a.Print();


	a -= "lo";
	a.Print();

	cout << (a == b) << endl;
	cout << (a > b) << endl;


	MyString a1("Hello");
	a1.Print();
	MyString a2("world");
	a2.Print();
	a2 = a1;
	a2.Print();

	MyString a3("Hello");
	a3.Print();
	MyString a4("world");
	a4.Print();
	a4 = move(a3);
	a4.Print();


	MyString obj9("Hello world");
	obj9.Print();

	for (int i = 0; i < obj9.GetLength(); i++)
	{
		cout << obj9[i] << " ";
	}
	cout << endl;

	string str = "Hello world";
	for (int i = 0; i < str.length(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	const MyString OBJ("Test");
	OBJ.Print();

	MyString obj10;
	cout << "Enter string: ";
	cin >> obj10;
	cout << obj10 << endl;
}
