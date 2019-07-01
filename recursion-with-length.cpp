#include <stdio.h>
#include <string.h>

void recursion(char *input) {
	int length=strlen(input);
	if(length<2)
		return;
	char temp=input[length-1];
	input[length-1]=0;
	recursion(input+1);
	input[length-1]=input[0];
	input[0]=temp;
}

int main() {
	char input[4]="Hey!";
	recursion(input);
	printf("%s", input);
	return 0;
}
