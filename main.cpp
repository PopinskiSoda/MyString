#include <iostream>
#include <vector>
#include <algorithm>
#include "MyString.h"

using namespace std;

int main(int argc, char** argv) {
	
	vector<MyString> strs;
	MyString str;
	
	cout << "Enter your strings one by one. Enter empty string to stop.\n";
	while (true) {
		cin >> str;
		if (str.getLength() == 0) {
			break;
		}
		strs.push_back(MyString(str));
	}
	
	sort(strs.rbegin(), strs.rend());
	
	for (vector<MyString>::iterator it=strs.begin(); it!=strs.end(); ++it) {
		cout << *it << ' ';
	}
	
	return 0;
}
