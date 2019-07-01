#include <iostream>
using namespace std;

void recursion() {
	char character;
	cin.get(character); // scanf("...", &character);
	if(character != '\n') {
		recursion();
	}
	cout << character; // printf("...", character);
}

int main() {
	recursion();
	return 0;
}

