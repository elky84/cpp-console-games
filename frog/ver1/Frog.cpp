#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "console.h"

#define MAX 256

// 길(Lane)에대한 구조체
struct LANE {
	int y;			// y 위치
	int arWait[10];	// 차가 나타날 대기시간 목록
	char* pShape;	// 모양
	int nFrame;		// 속도
	int Delta;		// 방향
	int WaitIdx;	// 대기시간 목록중 선택한 값
	int nStay;		// 대기시간에 대한 카운트
};

struct CAR {
	bool bExist;	// 존재 유무
	int x, y;		// 현재 좌표
	char* pShape;	// 모양
	int nFrame;		// 프레임
	int nStay;		// 프레임에 대한 카운트
	int Delta;		// 방향
};

LANE L[8] = {
	{4,{200,250,300},"OOOOOO",25,-1,},
	{5,{150,200,},"MMMM",23,1,},
	{6,{200,150,180,},"OOO",23,-1,},
	{7,{150,300,180,},"MMM",20,1,},

	{9,{200,250,350,},"Sonata",4,-1,},
	{10,{150,150,100,},"Matiz",15,1,},
	{11,{200,},"Verna",8,-1,},
	{12,{180,200,},"Morning",10,1,},
};
CAR C[MAX];
int fx, fy;
bool bMoved;
bool bGoals[5];
int nLife;
bool GameOver;

void MakeCar();
void MoveCar(bool bDraw = true);
void DrawBkg();
void ClipOut(int x, int y, char* pShape);
void ProcKey();
void MoveFrog(int key);
int CheckFrog();
void Flicker();

void main()
{
	int i;
	int Res;

	srand((unsigned)time(NULL));

	for(;1;) {
		system("cls");

		nLife = 3;
		for(i=0; i<5; ++i) { bGoals[i] = false; }
		i = 2000 + rand() % 1000;
		for(i=0; i<2000 + rand() % 1000; ++i) {
			MakeCar();
			MoveCar(false);
		}

		for(;2;) {
			fx=30; fy=14;
			gotoxy(fx, fy); putch('F');
			DrawBkg();

			for(;3;) {
				MakeCar();
				ProcKey();
				MoveCar();
				
				if(bMoved) {
					gotoxy(fx, fy); putch('F');
					bMoved = false;
				}

				Res = CheckFrog();
				if(Res == 1) {
					if(--nLife <= 0) { 
						gotoxy(27, 7); printf("Failed");
						Sleep(1500);
						GameOver = true;
					}
					break;
				} else if(Res == 2) {
					if(bGoals[0]*bGoals[1]*bGoals[2]*bGoals[3]*bGoals[4]) {
						gotoxy(23, 7); printf("Congratulation!");
						Sleep(1500);
						GameOver = true;
					}
					break;
				}

				Sleep(10);
			}
			if(GameOver) { 
				GameOver = false;
				break;
			}
		}
	}
}

void MakeCar()
{
	int i,j;

	for(i=0; i<8; ++i) {
		if(++L[i].nStay == L[i].arWait[L[i].WaitIdx]) {
			L[i].nStay = 0;
			++L[i].WaitIdx;
			if(L[i].arWait[L[i].WaitIdx] == 0) {
				L[i].WaitIdx = 0;
			}
			for(j=0; j<MAX; ++j) {
				if(!C[j].bExist) {
					C[j].bExist = true;
					C[j].y = L[i].y;
					C[j].pShape = L[i].pShape;
					C[j].nFrame = C[j].nStay = L[i].nFrame;
					C[j].Delta = L[i].Delta;

					if(L[i].Delta == 1) {
						C[j].x = -10;
					} else {
						C[j].x = 60;
					}
					break;
				}
			}
		}
	}
}

void MoveCar(bool bDraw)
{
	int i;
	int tx;
	char tshape[32];

	for(i=0; i<MAX; ++i) {
		if(C[i].bExist && --C[i].nStay <= 0) {
			C[i].nStay = C[i].nFrame;
			if(fy == C[i].y && fx >= C[i].x && fx < C[i].x + (int)strlen(C[i].pShape)) {
				fx += C[i].Delta;
				bMoved = true;
			}
			C[i].x += C[i].Delta;

			if(C[i].x == 60) { C[i].bExist = false; }
			if(C[i].x == -10) { C[i].bExist = false; }

			if(bDraw) {
				if(C[i].Delta == 1) {
					wsprintf(tshape, " %s", C[i].pShape);
					tx = C[i].x - 1;
				} else if(C[i].Delta == -1){
					wsprintf(tshape, "%s ", C[i].pShape);
					tx = C[i].x;
				}

				ClipOut(tx, C[i].y, tshape);
			}
		}
	}
}

void DrawBkg()
{
	gotoxy(0, 1); puts("############################################################");
	gotoxy(0, 2); puts("############################################################");
	gotoxy(0, 3); puts("######### ######### ######### ######### ######### ##########");
	gotoxy(0, 8); puts("............................................................");
	gotoxy(0, 13); puts("............................................................");

	int i;
	for(i=0 ;i<5; ++i) {
		if(bGoals[i]) {
			gotoxy(9+i*10, 3); putch('F');
		}
	}

	for(i=0; i<nLife-1; ++i) {
		gotoxy(0+i, 18); printf("%c ", 'F');
	}
	if(i==0) { gotoxy(0, 18); putch(' '); }
}

void ClipOut(int x, int y, char* pShape)
{
	if(x < 0) {
		if(-x >= (int)strlen(pShape)) { return; }
		pShape += -x;
		x = 0;
	}

	for(; x<60 && *pShape; ++x, ++pShape) {
		gotoxy(x, y);
		putch(*pShape);
	}
}

void ProcKey()
{
	if(!kbhit()) { return; }

	int ch = getch();
	if(ch == 0xE0 || ch == 0x00) {
		ch = getch();
		switch(ch) {
		case 72:
		case 75:
		case 77:
		case 80:
			MoveFrog(ch);
			break;
		}
	} else {
		if(tolower(ch) == 27/*ESC*/) {
			exit(0);
		}
	}
}

void MoveFrog(int key)
{
	if(fy == 8 || fy == 13) {
		gotoxy(fx, fy); putch('.');
	} else {
		gotoxy(fx, fy); putch(' ');
	}

	if(key == 72 && fy > 3) { --fy; }
	else if(key == 75 && fx > 0) { --fx; }
	else if(key == 77 && fx < 59) { ++fx; }
	else if(key == 80 && fy < 16) { ++fy; }

	bMoved = true;
}

// Return value
// 0 : Nothing Happen
// 1 : Died
// 2 : Goal in
int CheckFrog()
{
	int i;

	if(fx < 0 || fx >= 60) {
		Flicker();
		return 1;
	}

	if(fy >= 4 && fy <= 7) {
		for(i=0; i<MAX; ++i) {
			if(C[i].bExist && C[i].y == fy) {
				if(fx >= C[i].x && fx < C[i].x + (int)strlen(C[i].pShape)) {
					return 0;
				}
			}
		}
		if(i == MAX) {
			Flicker();
			return 1;
		}
	} else if(fy >= 9 && fy <= 12) {
		for(i=0; i<MAX; ++i) {
			if(C[i].bExist && C[i].y == fy) {
				if(fx >= C[i].x && fx < C[i].x + (int)strlen(C[i].pShape)) {
					Flicker();
					return 1;
				}
			}
		}
	} else if(fy == 3) {
		if(fx % 10 == 9 && bGoals[fx/10] == false) {
			bGoals[fx/10] = true;
			return 2;
		} else {
			Flicker();
			return 1;
		}
	}

	return 0;
}

void Flicker()
{
	int i;
	for(i=0; i<4; ++i) {
		gotoxy(fx, fy); putch('F');
		Sleep(150);

		gotoxy(fx, fy); putch(' ');
		Sleep(150);
	}
}