#include <windows.h>
#include <stdio.h>
#include <conio.h>

const char *gStage =
	"########"
	"# ..Op #"
	"# oo   #"
	"#      #"
	"########";
const int gWidth = 8;
const int gHeight = 5;
const int gSize = gWidth * gHeight;

enum OBJECT {
	SPACE,
	WALL,
	PLAYER,
	GOAL_PLAYER,
	LOAD,
	GOAL_LOAD,
	GOAL,
	UNKNOWN
};
const char gObjects[] = " #pPoO.";

void gotoxy(SHORT x, SHORT y);
void InitStage(OBJECT **ppStage);
void DrawStage(OBJECT *pStage);
void UpdateStage(OBJECT *pStage, char ch);
bool CheckClear(OBJECT *pStage);

void main()
{
	char ch;
	OBJECT *pStage;

	InitStage(&pStage);
	while(true) {
		gotoxy(0,0);
		DrawStage(pStage);

		ch = getch();
		UpdateStage(pStage, ch);

		if(CheckClear(pStage)) {
			gotoxy(0,0);
			DrawStage(pStage);
			break;
		}
	}
	printf("Congratulate!! \n");
	delete [] pStage;
	pStage = NULL;
}

void gotoxy(SHORT x, SHORT y)
{
	COORD cur = {x, y};

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void InitStage(OBJECT **ppStage)
{
	int i;
	const char *p = gStage;
	OBJECT obj;

	*ppStage = new OBJECT[gWidth * gHeight];

	i = 0;
	while(*p) {
		switch(*p) {
		case ' ': obj=SPACE;	break;
		case '#': obj=WALL;		break;
		case 'p': obj=PLAYER;	break;
		case 'P': obj=GOAL_PLAYER;	break;
		case '.': obj=GOAL;		break;
		case 'o': obj=LOAD;		break;
		case 'O': obj=GOAL_LOAD;	break;
		default:  obj=UNKNOWN;	break;
		}
		
		if(obj != UNKNOWN) {
			(*ppStage)[i] = obj;
			++i;
		}
		++p;
	};

}

void DrawStage(OBJECT *pStage) {

	int i;

	for(i=0; i<gSize; ++i) {
		printf("%c", gObjects[ pStage[i] ]);
		if((i+1) % gWidth == 0) {
			printf("\n");
		}
	}
}

void UpdateStage(OBJECT *pStage, char ch) {

	int p, x, y;
	int tp, tx, ty;
	int dx=0, dy=0;

	switch(ch) {
	case 'A':
	case 'a': dx = -1; break;

	case 'D':
	case 'd': dx = 1; break;

	case 'W':
	case 'w': dy = -1; break;

	case 'S':
	case 's': dy = 1; break;

	default: return;
	}

	for(p=0; p<gSize; ++p) {
		if(pStage[p] == PLAYER || pStage[p] == GOAL_PLAYER) {
			break;
		}
	}

	if(p == gSize) {
		return;
	}

	x = p % gWidth;
	y = p / gWidth;

	tx = x + dx;
	ty = y + dy;
	tp = ty * gWidth + tx;

	if(pStage[tp] == SPACE || pStage[tp] == GOAL) {
		pStage[tp] = pStage[tp] == GOAL ? GOAL_PLAYER : PLAYER;
		pStage[p] = pStage[p] == GOAL_PLAYER ? GOAL : SPACE;
	}
	else if(pStage[tp] == LOAD || pStage[tp] == GOAL_LOAD) {		
		int tx2 = tx + dx;
		int ty2 = ty + dy;
		int tp2 = ty2 * gWidth + tx2;

		if(pStage[tp2] == SPACE || pStage[tp2] == GOAL) {
			pStage[tp2] = pStage[tp2] == GOAL ? GOAL_LOAD : LOAD;
			pStage[tp]	= pStage[tp] == GOAL_LOAD ? GOAL_PLAYER : PLAYER;
			pStage[p]	= pStage[p] == GOAL_PLAYER ? GOAL : SPACE;
		}
	}
}

bool CheckClear(OBJECT *pStage) {
	int i;

	for(i=0; i<gSize; ++i) {
		if(pStage[i] == LOAD) {
			break;
		}
	}

	if(i == gSize) {
		return true;
	}
	return false;
}