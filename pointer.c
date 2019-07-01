#include <stdio.h>

void swapSting(char* firstItem, char* lastItem){
	if(firstItem > lastItem) {
		return;
	}
	char temp = *firstItem;
	*firstItem=*lastItem;
	*lastItem=temp;
	swapSting(firstItem+1, lastItem -1);
}

int main() {
	char input[4]="Hey!";
	swapSting(&input[0], &input[3]);
	printf("%s", input);
	return 0;
}
