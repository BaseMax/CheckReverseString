#include <iostream>
using namespace std;

void recursion() {
	char character;
	cin.get(character); // scanf("...", &character);
	if(character != '\n') {
		recursion();
	}
	// else { /* Done! */ }
	cout << character; // printf("...", character);
}

int main() {
	while(true) {
		cout << "> "; // printf("> ");
		recursion();
		cout << "\n"; // printf("\n");
	}
	return 0;
}

