#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;

class MyString {
	
	private:
		static const int DEFAULT_ARRAY_SIZE;
		int arraySize;
		int length;
		char *value;
		
	public:
		MyString();
		MyString(const MyString& copy);
		MyString(const char *value);
		~MyString();
		
		void setValue(const char *value);
		void getValue(char *buffer) const;
		int getLength() const;
		int getArraySize() const;
		int getDefaultArraySize() const;
		
		MyString& operator=(const MyString& other);
		MyString operator+(const MyString& other);
		bool operator>(const MyString& other);
		bool operator<(const MyString& other);
		bool operator==(const MyString& other);
		friend ostream& operator<<(ostream& os, const MyString& str);
		friend istream& operator>>(istream& is, MyString& str);
};

#endif
