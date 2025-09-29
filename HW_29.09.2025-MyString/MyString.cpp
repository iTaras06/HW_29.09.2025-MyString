#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString()
{
	length = 80;
	str = new char[length] {};
	count++;
}
MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
	count++;
}
MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
	count++;
}
MyString::~MyString()
{
	delete[]str;
	length = 0;
	count--;
}
MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	count++;
}

void MyString::Print()const
{
	cout << str << endl;
}

bool MyString::MyStrStr(const char* str)
{
	const char* s = strstr(this->str, str);
	if (s != nullptr)
	{
		return true;
	}
	return false;
}

void MyString::Input()
{
	cout << "\nEnter string: ";
	cin.getline(str, length);
}

void MyString::MyStrcpy(MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
}

MyString::MyString(MyString&& obj)
{
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = 0;
	cout << "Move constructor!!\n";

	count++;
}

int MyString::MyChr(char c)
{
	char* cha = strchr(this->str, c);
	if (cha != nullptr)
	{
		return cha - this->str;
	}
	return -1;
}

int MyString::MyStrLen()
{
	return strlen(str);
}

void MyString::MyStrCat(MyString& b)
{
	int new_length = length + b.length;
	char* new_str = new char[new_length + 1];
	strcpy_s(new_str, new_length + 1, str);
	strcat_s(new_str, new_length + 1, b.str);
	delete[] str;
	str = new_str;
	length = new_length;

}

void MyString::MyDelChr(char c)
{
	int count = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] == c)
		{
			count++;
		}
	}
	if (count == 0) return;
	int new_length = length - count;
	char* new_str = new char[new_length + 1];
	int j = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] != c)
		{
			new_str[j] = str[i];
			j++;
		}
	}
	delete[] str;
	str = new_str;
	length = new_length;
}
int MyString::MyStrCmp(MyString& b)
{
	return strcmp(str, b.str);
}

void MyString::PrintCount()
{
	cout << "Count => " << count << endl;
}
int MyString::count = 0;



MyString MyString::operator+ (const char* b)
{
	MyString res(length + 1 + strlen(b) + 1);
	strcpy_s(res.str, length + 1, str);
	strcat_s(res.str, length + strlen(b) + 2, b);
	return res;
}

MyString MyString::operator+ (MyString& obj)
{
	MyString res(length + 1 + strlen(obj.str) + 1);
	strcpy_s(res.str, length + 1, str);
	strcat_s(res.str, length + strlen(obj.str) + 2, obj.str);
	return res;
}

MyString MyString::operator- (const char ch)
{
	int count = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] == ch)
		{
			count++;
		}
	}
	if (count == 0) return 0;
	int new_length = length - count;
	char* new_str = new char[new_length + 1];
	int j = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] != ch)
		{
			new_str[j] = str[i];
			j++;
		}
	}
	return new_str;
}



//MyString& MyString::operator++() // ++a
//{
//	char* new_str = new char[length + 2]; // +1 для символа, +1 для '\0'
//	strcpy_s(new_str, length + 1, str);
//	new_str[length] = '!';   // добавляем символ
//	new_str[length + 1] = '\0';
//
//	delete[] str;
//	str = new_str;
//	length++;
//	return *this;
//}


MyString MyString::operator++(int) // a++
{
	// добавляется пробел ' ' в конец строки

	MyString temp(*this);
	char* new_str = new char[length + 2]; // +1 для пробела, +1 для '\0'
	strcpy_s(new_str, length + 1, str);
	new_str[length] = ' ';
	new_str[length + 1] = '\0';

	delete[] str;
	str = new_str;
	length++;

	return temp; // вернуть старое значение
}



//MyString& MyString::operator-- () // --a
//{
//		
//		str[length - 1] = '\0'; // обрезаем последний символ
//		length--;
//		
//	return *this;
//}


MyString MyString::operator--(int) // a--
{
	// удаляется последний символ в строке

	MyString temp(*this); // сохранить копию

	str[length - 1] = '\0';
	length--;

	return temp; // вернуть старое значение
}


MyString& MyString::operator+=(const char* s)
{
	int add_len = strlen(s);
	char* new_str = new char[length + add_len + 1];
	strcpy_s(new_str, length + 1, str);
	strcat_s(new_str, length + add_len + 1, s);

	delete[] str;
	str = new_str;
	length += add_len;

	return *this;
}

MyString& MyString::operator+=(const MyString& obj)
{
	int new_length = length + obj.length;
	char* new_str = new char[new_length + 1];

	strcpy_s(new_str, length + 1, str);              // копируем текущую строку
	strcat_s(new_str, new_length + 1, obj.str);    // добавляем строку из объекта

	delete[] str;
	str = new_str;
	length = new_length;

	return *this;
}


MyString& MyString::operator-=(const char* s)
{
	// удалить из строки подстроку

	int s_len = strlen(s);
	//if (s_len == 0) return *this;

	char* pstr;
	while ((pstr = strstr(str, s)) != nullptr)
	{
		int new_len = length - s_len;
		char* new_str = new char[new_len + 1];

		int prefix_len = pstr - str;
		strncpy_s(new_str, new_len + 1, str, prefix_len);
		new_str[prefix_len] = '\0';
		strcat_s(new_str, new_len + 1, pstr + s_len);

		delete[] str;
		str = new_str;
		length = new_len;
	}
	return *this;
}


bool MyString::operator==(MyString& obj)
{
	return strcmp(str, obj.str) == 0;
}

bool MyString::operator>(MyString& obj)
{
	return strcmp(str, obj.str) > 0;
}

MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (str != nullptr)
	{
		delete[] str;
	}
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = obj.length;
	cout << "Copy =\n";
	return *this;
}


MyString& MyString::operator=(MyString&& obj)
{
	if (str != nullptr)
	{
		delete[] str;
	}
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = 0;

	return *this;
}
int MyString::GetLength()const
{
	return length;
}

ostream& operator<<(ostream& os, MyString& obj)
{
	os << obj.str;
	return os;
}
istream& operator>>(istream& is, MyString& obj)
{
	char buf[50];
	is.getline(buf, 50);
	delete[] obj.str;
	obj.length = strlen(buf);
	obj.str = new char[obj.length + 1];
	strcpy_s(obj.str, obj.length + 1, buf);
	return is;
}