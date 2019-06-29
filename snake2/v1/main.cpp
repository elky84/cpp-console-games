#include <stdio.h>
#include <conio.h>
#include <time.h>
#include "turboc.h"

struct ELEMENT {
	int x, y;
	char ch;
};

////////////////////////////////////////////////////////////
// Game
////////////////////////////////////////////////////////////
void InitEnvironment();
void InitGame();
void ProcKey();

////////////////////////////////////////////////////////////
// Snake
////////////////////////////////////////////////////////////
#define MAXSNAKELEN 1024
enum { UP, LEFT, DOWN, RIGHT };
struct {
	ELEMENT Body[MAXSNAKELEN];
	int CurLen; // Current Length
	int AddLen; // Add Length
	int Dir;	// Direction
	int Frame, Stay;
}Snake;

void InitSnake(int len, int x, int y, int Direction);
void AddTail();
void Moving();
bool CollisionTest();
void DrawSnake();

////////////////////////////////////////////////////////////
// Item
////////////////////////////////////////////////////////////
ELEMENT Item;

void InitItem();
void DrawItem();


////////////////////////////////////////////////////////////
// Maps
////////////////////////////////////////////////////////////
char Maps[][25][81] = {
	"vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	">                                                                              <",
	"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^",
};
int NumMaps;
int CurMap;

void InitMap();
void DrawMap();

////////////////////////////////////////////////////////////
// Main
////////////////////////////////////////////////////////////
void main()
{
	InitEnvironment();
	InitGame();

	DrawMap();
	DrawItem();

	for(;;) {
		ProcKey();
		AddTail();
		Moving();
		DrawSnake();
		if(CollisionTest()) { break; }
		Sleep(10);
	}

	getch();
}

void InitEnvironment()
{
	curtype(HIDE);
	srand((unsigned)time(NULL));
}

void InitGame()
{
	InitMap();
	InitItem();
	InitSnake(3, 5, 2, RIGHT);
}

void ProcKey()
{
	if(kbhit()) {
		int ch = getch();
		if(ch == 0xE0 || ch == 0x00) {
			ch = getch();
			// UP
			if(ch == 72) {
				if(Snake.Dir != DOWN) { 
					Snake.Dir = UP;
					Snake.Stay = 1;
					// Stay 값을 1로 해주지않으면 문제가 발생한다.
					// Stay 값을 주석으로 처리해 버리면 어떻게 되는지
					// 예를 들어 설명해 보겠다.

					// 오른쪽으로 가고있는 중인데 윗방향 키를 눌렀지만
					// 아직 프레임이 1이 되지 않아 움직이지 않았다.
					// 하지만 방향은 윗방향으로 진행되어 있다고 기억하고 있으므로
					// 왼쪽방향키를 누를경우 이를 아무런 이상없이 받아들인다.
					// 마침내 프레임이 제로가 되어 움직일 타이밍이 되었을 때
					// 현재 방향이 왼쪽으로 되어있어 반대방향으로 움직이게 된다.
				}
			}
			// DOWN
			if(ch == 80) {
				if(Snake.Dir != UP) {
					Snake.Dir = DOWN;
					Snake.Stay = 1;
				}
			}
			// LEFT
			if(ch == 75) {
				if(Snake.Dir != RIGHT) { 
					Snake.Dir = LEFT;
					Snake.Stay = 1;
				}
			}
			// RIGHT
			if(ch == 77) {
				if(Snake.Dir != LEFT) {
					Snake.Dir = RIGHT;
					Snake.Stay = 1;
				}
			}
		}
	}
}

void InitSnake(int len, int x, int y, int Direction)
{
	int i;

	Snake.Dir = Direction;
	Snake.CurLen = len;
	Snake.Frame = Snake.Stay = 10;

	// Head
	Snake.Body[0].ch = '@';
	Snake.Body[0].x = x;
	Snake.Body[0].y = y;

	// Body
	for(i=1; i<len-1; ++i) {
		Snake.Body[i].ch = '#';
		Snake.Body[i].x = x-i;
		Snake.Body[i].y = y;
	}

	// Tail
	Snake.Body[i].ch = ' ';
	Snake.Body[i].x = x-i;
	Snake.Body[i].y = y;
}

void AddTail()
{
	/*if(Snake.AddLen) {
		Snake.Body[Snake.CurLen-1].ch = '#';
		Snake.Body[Snake.CurLen].ch = ' ';
		++Snake.CurLen;
		Snake.AddLen = Snake.AddLen-1 > 0 ? Snake.AddLen-1 : 0;
	}*/

	int i;
	int x, y;
	int LinkPos;

	if(Snake.AddLen) {
		x = Snake.Body[Snake.CurLen-1].x;
		y = Snake.Body[Snake.CurLen-1].y;
		LinkPos = Snake.CurLen-1;
		Snake.CurLen = Snake.CurLen + Snake.AddLen;
		for(i=LinkPos; i<Snake.CurLen-1; ++i) {
			Snake.Body[i].ch = '#';
			Snake.Body[i].x = x;
			Snake.Body[i].y = y;
		}
		Snake.Body[Snake.CurLen-1].ch = ' ';
		Snake.Body[Snake.CurLen-1].x = x;
		Snake.Body[Snake.CurLen-1].y = y;

		Snake.AddLen = 0;
	}
}

void Moving()
{
	int i;

	if(--Snake.Stay <= 0) {
		Snake.Stay = Snake.Frame;

		for(i=Snake.CurLen-1; i>0; --i) {
			Snake.Body[i].x = Snake.Body[i-1].x;
			Snake.Body[i].y = Snake.Body[i-1].y;
		}

		if(Snake.Dir == UP) { --Snake.Body[0].y; }
		else if(Snake.Dir == DOWN) { ++Snake.Body[0].y; }
		else if(Snake.Dir == LEFT) { --Snake.Body[0].x; }
		else if(Snake.Dir == RIGHT) { ++Snake.Body[0].x; }
	}
}

bool CollisionTest()
{
	if(Maps[CurMap][Snake.Body[0].y][Snake.Body[0].x] != ' ') {
		return true;
	}

	if(getchxy(Snake.Body[0].x, Snake.Body[0].y) == '#') {
		return true;
	}

	if(Item.x == Snake.Body[0].x && Item.y == Snake.Body[0].y) {
		Snake.AddLen += Item.ch - '0';
		InitItem();
		DrawItem();
	}

	return false;
}

void DrawSnake()
{
	int i;

	for(i=0; i<Snake.CurLen; ++i) {
		gotoxy(Snake.Body[i].x, Snake.Body[i].y);
		putch(Snake.Body[i].ch);
	}
}

void InitItem()
{
	int x, y;

	do {
		x = rand() % 79 + 1;
		y = rand() % 23 + 1;
	} while(getchxy(x, y) != ' ');

	Item.x = x;
	Item.y = y;
	Item.ch = rand() % ('9'-'0') + '1';
}

void DrawItem()
{
	gotoxy(Item.x, Item.y);
	putch(Item.ch);
}

void InitMap()
{
	NumMaps = sizeof(Maps) / sizeof(Maps[0]);
	CurMap = 0;
}

void DrawMap()
{
	int y;
	for(y=0; y<25; ++y) {
		printf(Maps[CurMap][y]);
	}
	gotoxy(0, 0);
}