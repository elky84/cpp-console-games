#include "Library.h"

void gotoxy(int x, int y)

{	

	COORD pos={x,y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 

 }

void SetColor(int color, int bgcolor) 

{

	color &= 0xf;

	bgcolor &= 0xf;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);

}

int Factorial(int n) {
	double sum = 1;
	while(n > 1) {
		sum = sum * n;
		n--;
	}
	return sum;
}

int Permutation(int a, int b) {
	unsigned int sum;

	sum = (int) Factorial(a) / Factorial(a-b);

	return sum;
}

int Combination(int a, int b) {
	unsigned int sum;

	sum = (int) Permutation(a,b) / Factorial(b);

	return sum;
}

int H_Combination(int a, int b) {
	int sum;

	sum = Combination(a+b-1,b);

	return sum;
}

int P_Permutation(int a, int b) {
	int sum;

	sum = (int) pow((float)a,(float)b);

	return sum;
}