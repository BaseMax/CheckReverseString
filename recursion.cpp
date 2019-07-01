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
	while(true) {
		cout << "> ";
		recursion();
		cout << "\n";
	}
	return 0;
}

