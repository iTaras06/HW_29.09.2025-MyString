#pragma once
#include <iostream>
using namespace std;
class MyString
{
	char* str;
	int length;
	static int count;

public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	~MyString();
	MyString(const MyString& obj);
	MyString(MyString&& obj);
	bool MyStrStr(const char* str);
	void Input();
	void Print()const;
	void Print()
	{
		cout << "Print\n";
	}
	void MyStrcpy(MyString& obj);
	int MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	static void PrintCount();


	MyString operator+ (const char* b);
	MyString operator+ (MyString& obj);
	MyString operator- (const char ch);


	MyString& operator++ ();
	MyString operator++(int);
	MyString& operator-- ();
	MyString operator--(int);
	MyString& operator+= (const char* obj);
	MyString& operator+=(const MyString& obj);
	MyString& operator-= (const char* b);
	bool operator== (MyString& obj);
	bool operator> (MyString& obj);

	MyString& operator=(const MyString& obj);
	MyString& operator=(MyString&& obj);


	int GetLength()const;

	char operator[](int index)
	{
		if (index >= 0 && index < length)
		{
			return str[index];
		}
		throw exception("index error");
	}

	friend ostream& operator<<(ostream& os, MyString& obj);
	friend istream& operator>>(istream& is, MyString& obj);
};