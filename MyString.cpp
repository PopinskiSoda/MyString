#include "MyString.h"
#include <iostream>

void myStrcpy(const char *src, char *dest) {
	
	while(*src) {
		*(dest++) = *(src++);
	}
	
	*(dest++) = '\0';
}

int myStrlen(const char *str) {
	int length = 0;
	
	while(*(str++)) {			// Переход к следующему символу в массиве
		length++;	
	};
	
	return length;
}

void myStrcat(char *dest, const char *src) {
	
	while (*dest) {
		dest++;
	}
	
	while (*src) {
		*(dest++) = *(src++);
	}
	
	*(dest++) = '\0';
}

int myStrcmp(const char *str1, const char *str2) {
	
	while(*str1 && *str2) {
		if (*str1 != *str2) {
			break;
		}
		str1++;
		str2++;
	}
	
	if (*str1 > *str2) {
		return 1;
	}
	if (*str1 < *str2) {
		return -1;
	}
	return 0;
}

const int MyString::DEFAULT_ARRAY_SIZE = 16;

MyString::MyString() {
	
	this->value = new char[this->DEFAULT_ARRAY_SIZE];
	this->arraySize = this->DEFAULT_ARRAY_SIZE;
	this->length = 0;
	
	*(this->value) = '\0';
}

MyString::MyString(const MyString& copy) {
	
	this->arraySize = copy.arraySize;
	this->length = copy.length;
	this->value = new char[arraySize];
	myStrcpy(copy.value, this->value);
}

MyString::MyString(const char *value) {
	
	this->value = NULL;
	this->setValue(value);
}

MyString::~MyString() {
	
	delete this->value;
}

void MyString::setValue(const char *value) {
	
	int arraySize = this->DEFAULT_ARRAY_SIZE;
	int length = myStrlen(value);
	
	while(length >= arraySize) {
		arraySize *= 2;
	}
	
	delete this->value;
	
	this->length = length;
	this->arraySize = arraySize;
	this->value = new char[arraySize];
	
	myStrcpy(value, this->value);
}

void MyString::getValue(char *buffer) const {
	myStrcpy(this->value, buffer);
}

int MyString::getLength() const {
	
	return this->length;
}

int MyString::getArraySize() const {
	
	return this->arraySize;
}

int MyString::getDefaultArraySize() const {
	
	return this->DEFAULT_ARRAY_SIZE;
}

MyString& MyString::operator=(const MyString& other) {
	
	this->length = other.length;
	this->arraySize = other.arraySize;
	
	delete this->value;
	this->value = new char[this->arraySize];
	myStrcpy(other.value, this->value);
	
	return *this;
}

MyString MyString::operator+(const MyString& other) {
	
	int length = this->length + other.length;
	int arraySize = this->arraySize;
	
	while(length >= arraySize) {
		arraySize*=2;
	}
	
	char *value = new char[arraySize];
	myStrcpy(this->value, value);
	myStrcat(value, other.value);
	
	MyString str(value);
	delete value;
	
	return str;
}

bool MyString::operator>(const MyString& other) {
	
	return(myStrcmp(this->value, other.value) > 0);
}

bool MyString::operator<(const MyString& other) {
	
	return(myStrcmp(this->value, other.value) < 0);
}

bool MyString::operator==(const MyString& other) {
	
	return(myStrcmp(this->value, other.value) == 0);
}

ostream& operator<<(ostream& os, const MyString& str) {
	
	char *value = new char[str.getArraySize()];
	str.getValue(value);
	os << value;
	delete value;
	
	return os;
}

istream& operator>>(istream& is, MyString& str) {
	
	int arraySize = str.getDefaultArraySize();
	int length = 0;
	char *buffer = new char[arraySize];
	
	char ch;
	
	while ( (ch = cin.get()) != '\n') {
		
		buffer[length] = ch;
		length++;
		
		if (length >= arraySize) {
		
			arraySize *= 2;
			
			char *newBuffer = new char[arraySize];
			myStrcpy(buffer, newBuffer);
			delete buffer;
			buffer = newBuffer;
		}
	}
	
	buffer[length] = '\0';
	
	str.setValue(buffer);
	delete buffer;
	
	return is;
}
