/**
*
* @Name : CheckReverseString/main.cpp
* @Version : 1.0
* @Programmer : Max
* @Date : 2018-07-13
* @Released under : https://github.com/BaseMax/CheckReverseString/blob/master/LICENSE
* @Repository : https://github.com/BaseMax/CheckReverseString
*
**/
#include <iostream>
// #include <algorithm>
using namespace std;

// reverse
// void flip(string& str) 
string flip(string input) {
	// reverse(input.begin(), input.end());
	int length = input.length(); 
	for(int index = 0; index < length / 2; index++)
		swap(input[index], input[length - index - 1]); 
	return input;
}

void check(string input) {
	const unsigned int size=input.length();
	const unsigned int middle=size / 2;
	bool result=true;
	if(input.empty()) {
		result=false;
	}
	cout << size << endl;
	for(int index=0; index<middle; index++) {
		if(input[index] == input[size-1-index]) {
			// result=true;
			continue;
		}
		else {
			result=false;
			break;
		}
	}
	cout << flip(input) << " (" << ((result == true) ? "TRUE" : "FALSE") << ")\n";
}

int main(int argc, char const *argv[]) {
	string value;
	cout << "Enter your value:\n";
	while(true) {
		cout << "> ";
		cin >> value;
		check(value);
		if(value == "exit") {
			break;
		}
		// check(name);
	}
	return 0;
}
