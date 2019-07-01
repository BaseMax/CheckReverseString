// https://github.com/BaseMax/CheckReverseString
#include <stdio.h>

#define swapItem(firstItem,secondItem) \
	firstItem^=secondItem;\
	secondItem^=firstItem;\
	firstItem^=secondItem;

char *reverse0(char* input) {
	char* firstItem = input;
	char *lastItem = input;
	char tempItem;
	while(*lastItem)
		lastItem++;
	while(lastItem-- > firstItem) {
		tempItem  = *firstItem; 
		*firstItem++ = *lastItem;  
		*lastItem =  tempItem;
	}
	return input;
}
void reverse1(char *input) {
	// TODO: Check 0xF, 0xE, 0xC, 0xD
	char *temp = input;
	while(temp && *temp) // != NULL
		temp++;
	temp--;
	while(input < temp) {
		*input = *input ^ *temp;
		*temp = *input ^ *temp;
		*input = *input ^ *temp;
		input++;
		temp--;
	}
}

char* reverse2(char* input) {
	char tempItem;
	char* firstItem = input;
	char* lastItem = input;
	while(*lastItem)
		lastItem++;
	while(lastItem > firstItem) {
		lastItem--;
		tempItem  = *firstItem; 
		*firstItem++ = *lastItem;  
		*lastItem =  tempItem;
	}
	return input;
}

char* reverse3(char* input) {
	char tempItem;
	char* firstItem = input;
	char* lastItem = input;
	while(*lastItem)
		lastItem++;
	while(lastItem-- > firstItem) {
		tempItem  = *firstItem; 
		*firstItem++ = *lastItem;  
		*lastItem =  tempItem;
	}
	return input;
}

void reverse4(char *input) {
	char *temp = input;
	while(temp && *temp) // != NULL
		temp++;
	for(temp--; input < temp; input++, temp--) {
		*input = *input ^ *temp;
		*temp = *input ^ *temp;
		*input = *input ^ *temp;
	}
}

void reverse5(char *input) {
	char *temp = input;
	while(temp && *temp) // != NULL
		temp++;
	for(temp--; input < temp; input++, temp--) {
		swapItem(*input, *temp);
	}
}

void reverse6(char *input) {
	char *tempItem = input;
	reverse5(input);
	while(tempItem && *tempItem)
		++tempItem;
	while(input < --tempItem) {
		char character=(*tempItem & 0xF0) >> 4;
		switch(character) {
			//four bytes
			case 0xF:
			{
				swapItem(*(tempItem-0), *(tempItem-3));
				swapItem(*(tempItem-1), *(tempItem-2));
				tempItem -= 3;
			}
			break;
			// 3 bytes
			case 0xE:
			{
				swapItem(*(tempItem-0), *(tempItem-2));
				tempItem -= 2;
			}
			break;
			// 2 bytes
			case 0xC:
			case 0xD:
			{
				swapItem(*(tempItem-0), *(tempItem-1));
				tempItem--;
			}
			break;
		}
	}
}

int main() {
	// char input1[20]="Hey! سلام";
	char input1[20]="Hey!";
	printf("%s\n", input1);
	reverse1(input1);
	reverse2(input1);
	reverse3(input1);
	reverse4(input1);
	reverse5(input1);
	reverse0(input1);
	printf("%s\n", input1);
	////////////////////////////
	char input2[20]="Hey! سلام";
	printf("%s\n", input2);
	reverse6(input2);
	printf("%s\n", input2);
	////////////////////////////
	return 0;
}
