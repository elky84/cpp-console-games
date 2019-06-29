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
					// Stay ���� 1�� ������������ ������ �߻��Ѵ�.
					// Stay ���� �ּ����� ó���� ������ ��� �Ǵ���
					// ���� ��� ������ ���ڴ�.

					// ���������� �����ִ� ���ε� ������ Ű�� ��������
					// ���� �������� 1�� ���� �ʾ� �������� �ʾҴ�.
					// ������ ������ ���������� ����Ǿ� �ִٰ� ����ϰ� �����Ƿ�
					// ���ʹ���Ű�� ������� �̸� �ƹ��� �̻���� �޾Ƶ��δ�.
					// ��ħ�� �������� ���ΰ� �Ǿ� ������ Ÿ�̹��� �Ǿ��� ��
					// ���� ������ �������� �Ǿ��־� �ݴ�������� �����̰� �ȴ�.
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