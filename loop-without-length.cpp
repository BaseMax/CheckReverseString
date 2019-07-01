#include <stdio.h>

#define swapItem(firstItem,secondItem) \
	firstItem^=secondItem;\
	secondItem^=firstItem;\
	firstItem^=secondItem;

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
