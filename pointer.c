#include <stdio.h>

void swapString(char* firstItem, char* lastItem){
	if(firstItem > lastItem) {
		return;
	}
	char temp = *firstItem;
	*firstItem=*lastItem;
	*lastItem=temp;
	swapString(firstItem+1, lastItem -1);
}

int main() {
	char input[4]="Hey!";
	swapString(&input[0], &input[3]);
	printf("%s", input);
	return 0;
}
