#include <conio.h>
#include <stdio.h>
#include "turboc.h"

#define putchxy(x, y, ch) { gotoxy(x, y); putch(ch); }

#define QS 1920

void InitStage(int stage);
void ProcKey();
bool MoveSnake();
void Wait();

COORD Snake[QS];
COORD Now;
int x, y;
int HeadIdx, TailIdx;
int IncTail;
int Multi;
int Stage;
enum { LEFT=75, RIGHT=77, UP=72, DOWN=80 };
int Dir;
int Speed;
int MaxItem;
int Life;

void main()
{
	int ch;
	int eatedItem;

	Life = 5;
	for(;;) {
		InitStage(Stage);
		gotoxy(0, 23); printf("Stage : %d", Stage+1);
		gotoxy(15, 23); printf("Life : %d", Life);

		for(eatedItem = 0; MaxItem > eatedItem; ++eatedItem) {		
			gotoxy(25, 23);
			printf("Length : %3d", 2);
			gotoxy(40, 23);
			printf("Rest : %d", MaxItem - eatedItem);
			do {
				x = rand() % 80;
				y = rand() % 22;
			} while(getchxy(x, y) != ' ');
			gotoxy(x, y);
			putch(rand() % ('9'-'0') + '1');

			if(eatedItem == 0) {
				ch = getch();
				if(ch == 0xE0 || ch == 0x00) {
					getch();
				} else {
					if(tolower(ch) == 'p') {
						Stage = Stage - 1 < 0  ? 4 : Stage - 1;
						break;
					} else if(tolower(ch) == 'n') {
						Stage = Stage + 1 > 4 ? 0 : Stage + 1;
						break;
					} else if(ch == 27) {
						exit(0);
					}
				}
			}

			if(MoveSnake()) {
				if(--Life == 0) {
					printf("게임이 끝났습니다.");
					return;
				}
				Sleep(1500);
				break;
			}
		}
		if(MaxItem == eatedItem) {
			gotoxy(20, 12);
			if(++Stage >= 5) {
				printf("모든 판을 클리어 했습니다.");
				Wait();
				break;
			} else {
				printf("축하합니다, 다음판으로 이동합니다");
				Wait();
			}
		}
	}
}

void InitStage(int stage)
{
	int i;

	Snake[0].X = 5;
	Snake[0].Y = 3;

	Snake[1].X = 6;
	Snake[1].Y = 3;

	Snake[2].X = 7;
	Snake[2].Y = 3;

	HeadIdx = 2;
	TailIdx = 0;

	Now.X = 7;
	Now.Y = 3;

	IncTail = 0;

	Dir = RIGHT;

	system("cls");

	gotoxy(5, 3);
	puts("##S");

	for(i=0; i<23; ++i) {
		putchxy(0, i, 'M');
		putchxy(79, i, 'M');
	}

	for(i=0; i<80; ++i) {
		putchxy(i, 0, 'M');
		putchxy(i, 22, 'M');
	}

	if(stage == 0) {
		Multi = 3;
		Speed = 100;
		MaxItem = 5;
		for(i=19; i<=59; ++i) {
			putchxy(i, 10, 'M');
		}
	} else if(stage == 1) {
		Multi = 5;
		Speed = 80;
		MaxItem = 6;
		for(i=20; i<=60; ++i) {
			putchxy(i, 5, 'M');
			putchxy(i, 16, 'M');
		}
	} else if(stage == 2) {
		Multi = 7;
		Speed = 60;
		MaxItem = 7;
		for(i=6; i<=14; ++i) {
			putchxy(40, i, 'M');
		}
		for(i=20; i<=60; ++i) {
			putchxy(i, 10, 'M');
		}
	} else if(stage == 3) {
		Multi = 9;
		Speed = 40;
		MaxItem = 8;
		for(i=20; i<=60; ++i) {
			if(i<=35 || i>=45) {
				putchxy(i, 6, 'M');
				putchxy(i, 15, 'M');
			}
		}
		for(i=6; i<=15; ++i) {
			putchxy(20, i, 'M');
			putchxy(60, i, 'M');
		}
	} else if(stage == 4) {
		Multi = 10;
		Speed = 20;
		MaxItem = 10;
	}	
}

void ProcKey()
{
	if(!kbhit()) { return; }

	int ch = getch();
	if(ch == 0xE0) {
		ch = getch();
		switch(ch) {
		case LEFT:
			if(Dir != RIGHT) { Dir = LEFT; }
			break;

		case RIGHT:
			if(Dir != LEFT) { Dir = RIGHT; }
			break;

		case UP:
			if(Dir != DOWN) { Dir = UP; }
			break;

		case DOWN:
			if(Dir != UP) { Dir = DOWN; }
			break;
		}
	} else {
		switch(ch) {
		case 'q':
			exit(0);

		case ' ':
			Wait();
			break;
		}
	}
}

bool MoveSnake()
{
	int headch;
	int prev;
	int len;

	for(;;) {
		len = HeadIdx - TailIdx;
		if(len < 0) { len += QS; }
		gotoxy(25, 23);
		printf("Length : %3d", len);

		ProcKey();		
		if(Dir == LEFT) {
			--Now.X;
		} else if(Dir == RIGHT) {
			++Now.X;
		} else if(Dir == UP) {
			--Now.Y;
		} else if(Dir = DOWN) {
			++Now.Y;
		}

		if(IncTail == 0) {
			TailIdx = TailIdx + 1 >= QS ? 0 : TailIdx + 1;
		} else {
			--IncTail;
		}

		HeadIdx = HeadIdx + 1 >= QS ? 0 : HeadIdx + 1;
		Snake[HeadIdx] = Now;
		headch = getchxy(Now.X, Now.Y);
		putchxy(Now.X, Now.Y, 'S');
		prev = HeadIdx - 1 < 0 ? QS-1 : HeadIdx - 1;
		putchxy(Snake[prev].X, Snake[prev].Y, '#');
		prev = TailIdx - 1 < 0 ? QS-1 : TailIdx - 1;
		putchxy(Snake[prev].X, Snake[prev].Y, ' ');

		if(headch != ' ') { break; }

		Sleep(Speed);
	}

	if(headch == '#' || headch == 'M') {
		return true;
	}

	IncTail = (headch - '0') * Multi;
	return false;
}

void Wait()
{
	int ch = getch();
	if(ch == 0xE0 || ch == 0x00) { getch(); }
	return;
}