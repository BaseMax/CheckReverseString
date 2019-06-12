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
#include <cstring>
// #include <algorithm>
using namespace std;

// reverse
string flip(string input) {
	// reverse(input.begin(), input.end());
	int length = input.length(); 
	for(int index = 0; index < length / 2; index++)
		swap(input[index], input[length - index - 1]); 
	return input;
}

void flip2(string& input) {
	int length = input.length(); 
	for(int index = 0; index < length / 2; index++)
		swap(input[index], input[length - index - 1]); 
}

char* flip3(char *input) {
	size_t length = strlen(input);
	char* temp = (char*) malloc(sizeof(char) * length + 1);
	int counter = 0;
	for(int index = length - 1; index >= 0; index--, counter++)
		temp[counter] = input[index];
	temp[counter + 1] = '\0';
	return temp;
}

char* flip4(const char *input) {
	size_t length = strlen(input);
	char* temp = (char*) malloc(sizeof(char) * (length + 1));
	if(temp) {
		size_t counter = 0;
		while(length > 0) {
			length--;
			temp[counter] = input[length]; 
			counter++;
		}
		temp[counter] = '\0';
	}
	return temp;
}

char* flip5(char *input) {
	size_t length = strlen(input);
	size_t index = 0;
	while (length > index) {
		char tmp = input[--length];
		input[len] = input[index];
		input[index++] = tmp;
	}
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
	// cout << flip(input) << " (" << ((result == true) ? "TRUE" : "FALSE") << ")\n";
	flip2(input);
	cout << input << " (" << ((result == true) ? "TRUE" : "FALSE") << ")\n";
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
