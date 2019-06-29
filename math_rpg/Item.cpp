#include "Library.h"

char itemList[10] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};

int PushItem(char c) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if(itemList[i] == ' ') {
			itemList[i]	=	c;
			i	=	20;
		}
	}
	ShowState();
	if(i != 21) {
		return -1;
	}
	return 0;
}

int PopItem(char c) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if(itemList[i] == c) {
			itemList[i]	=	' ';
			i	=	20;
		}
	}
	ShowState();
	if(i != 21) {
		return -1;
	}
	return 0;
}

char GetItemEntry(int n) {
	return itemList[n];
}

int IsItem(char c) {
	int i;
	for (i = 0; i < 10; i++) {
		if(itemList[i] == c) {
			return 1;
		}
	}
	return 0;
}