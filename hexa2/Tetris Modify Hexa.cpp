#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>

/* Game */
int score;
int level;

void InitGame();
void SetGame();
void ClearGame();
void DrawInterface();
void DrawScore();
void CheckLevel();

/* Board */
#define BX 5
#define BY 1
#define BW 10
#define BH 20

int board[BW+2][BH+2];

void InitBoard();
void DrawBoard();
void CheckLine();

/* Tiles */
enum {EMPTY, B1, B2, B3, B4, B5, B6, B7, WALL};
char* tiles[] = {". ", "¡Ú", "¡Ü", "¡ß", "¡á", "¡ã", "¢¾", "¢À", "¡à"};
const int nTile = sizeof(tiles) / sizeof(tiles[0]);

/* Brick */
int brick[3];
int nbrick[3];

int nx, ny;
int stay, frame;
int nCreated;

bool CreateBrick();
void NewBrick(int* brick);
int CheckAround(int x, int y);
bool SinkBrick();
void DrawBrick(bool bShow);
void CheckSpeedUp();
void RotateBrick();
void DrawNextBrick();
void DrawBrickBox();

/* Key Process */
bool ProcKey();

/* Turbo C */
void gotoxy(int x, int y);
enum {HIDE, NORMAL};
void curtype(int type);

void main()
{
	InitGame();
	// Game start
	for(;;) {
		SetGame();
		system("cls");
		DrawBoard();
		DrawBrickBox();
		DrawInterface();
		// Brick create
		for(;;) {
			CheckLevel();
			if(!CreateBrick()) { break; }
			DrawNextBrick();
			DrawBrick(true);
			// Brick fall down
			for(;;) {
				if(ProcKey()) { break; }
				if(SinkBrick()) { break; }
				Sleep(10);
			}
			CheckSpeedUp();
			CheckLevel();
		}
		system("cls");
		gotoxy(34, 12);
		puts("G A M E  O V E R");
		gotoxy(25, 14);
		puts("If you want restart press 'y'");
		if(tolower(getch()) != 'y') { break; }
	}
	ClearGame();
}

void NewBrick(int* brick)
{
	do {
		for(int i=0; i<3; ++i)
			brick[i] = rand() % (level+2) + 1;
	} while(brick[0] == brick[1] && brick[1] == brick[2]);
}

void InitGame()
{
	srand((unsigned)time(NULL));
	curtype(HIDE);
}

void SetGame()
{
	score = 0;
	frame = 50;
	level = 1;
	nCreated = 0;
	NewBrick(nbrick);
	InitBoard();
}

void ClearGame()
{
	curtype(NORMAL);
	system("cls");
}

void DrawInterface()
{
	gotoxy(5, 0);
	printf("Lvel %d", level);
	gotoxy(30, 2);
	puts("¡è : Rotate your brick");
	gotoxy(30, 3);
	puts("¡ç : Move left");
	gotoxy(30, 4);
	puts("¡æ : Move right");
	gotoxy(30, 5);
	puts("¡é : Move down");	
	gotoxy(30, 6);
	puts("P : Pause");
	gotoxy(30, 7);
	puts("Q : Quit Game");
	gotoxy(30, 8);
	puts("Spacebar : Immediately fall in bottom");
	gotoxy(30, 9);
	puts("Page Up,Down : Change tile concept");
	DrawScore();
}

void DrawScore()
{
	gotoxy(5, 23);
	printf("Score : %-3d", score);
}

void CheckLevel()
{
	if(level < nTile-4) {
		if(score >= 1000*level*level) {
			++level;
			gotoxy(5, 0);
			printf("Level %d", level);
		}
	}
}

void InitBoard()
{
	int x, y;
	
	for(x=0; x<BW+2; ++x) {
		for(y=0; y<BH+2; ++y) {
			board[x][y] = (x==0 || y==0 || x==BW+1 || y==BH+1) ? WALL : EMPTY;
		}
	}
}

void DrawBoard()
{
	int x, y;

	for(x=0; x<BW+2; ++x) {
		for(y=0; y<BH+2; ++y) {
			gotoxy(BX+x*2, BY+y);
			puts(tiles[board[x][y]]);
		}
	}
}

void CheckLine()
{
	int x, y;
	int ty;
	int t, i;
	bool bRemove;
	bool mark[BW+2][BH+2];
	int cnt;
	int combo;
	int scoreTable[7] = {0, 12, 36, 108, 232, 332, 683};

	cnt = 0;
	combo = 0;
	for(;;) {
		bRemove = 0;
		memset(mark, 0, sizeof(mark));

		for(y=1; y<BH+1; ++y) {
			for(x=1; x<BW+1; ++x) {
				t = board[x][y];
				if(t == EMPTY) { continue; }

				// -
				if(board[x-1][y]==t && board[x+1][y]==t) {
					bRemove = true;
					for(i=-1; i<=1; ++i) {
						mark[x+i][y] = true;
					}
				}

				// |
				if(board[x][y-1]==t && board[x][y+1]==t) {
					bRemove = true;
					for(i=-1; i<=1; ++i) {
						mark[x][y+i] = true;
					}
				}

				// \ 
				if(board[x-1][y-1]==t && board[x+1][y+1]==t) {
					bRemove = true;
					for(i=-1; i<=1; ++i) {
						mark[x+i][y+i] = true;
					}
				}

				// /
				if(board[x+1][y-1]==t && board[x-1][y+1]==t) {
					bRemove = true;
					for(i=-1; i<=1; ++i) {
						mark[x-i][y+i] = true;
					}
				}
			}
		}

		if(!bRemove) {
			break;
		} else {
			++combo;
		}

		
		switch(combo) {
		case 2:
			gotoxy(7*2, 9);
			puts("Double");
			break;

		case 3:
			gotoxy(7*2, 9);
			puts("Trilple");
			break;

		case 4:
			gotoxy(8*2, 9);
			puts("Quad");
			break;

		case 5:
			gotoxy(7*2, 9);
			puts("Quintuple!");
			break;

		case 6:
			gotoxy(6*2, 9);
			puts("Sextuple!");
			break;

		case 7:
			gotoxy(5*2, 9);
			puts("Septuple!!");
			break;
		}

		for(i=0; i<6; ++i) {
			for(y=1; y<BH+1; ++y) {
				for(x=1; x<BW+1; ++x) {
					if(mark[x][y]) {
						gotoxy(BX+x*2, BY+y);
						puts(i%2 ? tiles[board[x][y]] : tiles[EMPTY]);
					}
				}
			}
			Sleep(150);
		}

		for(y=1; y<BH+1; ++y) {
			for(x=1; x<BW+1; ++x) {
				if(mark[x][y]) {
					for(ty=y; ty>1; --ty) {
						board[x][ty] = board[x][ty-1];
					}
					board[x][1] = EMPTY;
					++cnt;
				}
			}
		}
		DrawBoard();
	}
	
	score += scoreTable[min(cnt/3, 6)] * (combo==1 ? 1 : combo);
	DrawScore();
	if(combo>=2) { DrawBoard(); }
}

int CheckAround(int x, int y)
{
	int i;
	int tile = EMPTY;
	for(i=0; i<3; ++i)
		tile = max(tile, board[x][y+i]);
	return tile;
}

bool SinkBrick()
{
	if(CheckAround(nx, ny+1) != EMPTY) {
		int i;
		for(i=0; i<3; ++i) {
			board[nx][ny+i] = brick[i];
		}
		CheckLine();
		return true;
	}

	if(--stay <= 0) {
		stay = frame;
		DrawBrick(false);
		++ny;
		DrawBrick(true);
	}
	return false;
}

void CheckSpeedUp()
{
	frame += (nCreated % 5 == 0) * (frame <= 7 ? 0 : -1 );
}

void RotateBrick()
{
	int i, t;
	t = brick[0];
	for(i=0; i<2; ++i) {
		brick[i] = brick[i+1];
	}
	brick[2] = t;
}

void DrawBrick(bool bShow)
{
	int i;
	for(i=0; i<3; ++i) {
		gotoxy(BX + nx * 2, BY + ny + i);
		puts(tiles[bShow ? brick[i] : EMPTY]);
	}
}

void DrawNextBrick()
{
	int x = 34;
	int y = 16;
	int i;
	for(i=0; i<3; ++i) {
		gotoxy(x, y+i);
		puts(tiles[nbrick[i]]);
	}
}

void DrawBrickBox()
{
	int x, y;

	gotoxy(30, 13);
	puts("Next Brick");

	for(x=30; x<=38; x+=2) {
		for(y=14; y<=20; ++y) {
			gotoxy(x, y);
			puts(tiles[x==30 || x==38 || y==14 || y==20 ? WALL : EMPTY]);
		}
	}
}

bool CreateBrick()
{
	nx = (BW+1) / 2;
	ny = 1;

	if(CheckAround(nx, ny) != EMPTY) {
		return false;
	}

	memcpy(brick, nbrick, sizeof(nbrick));
	stay = frame;
	++nCreated;
	NewBrick(nbrick);

	return true;
}

bool ProcKey()
{
	if(kbhit()) {
		int ch = getch();
		if(ch == 0xE0 || ch == 0x00) {
			ch = getch();
			switch(ch) {
			case 73: // page up
				break;
			case 81: // page down
				break;
			case 75: // left arrow
				if(CheckAround(nx-1, ny) == EMPTY) {
					DrawBrick(false);
					--nx;
					DrawBrick(true);
				}
				break;
			case 77: // right arrow
				if(CheckAround(nx+1, ny) == EMPTY) {
					DrawBrick(false);
					++nx;
					DrawBrick(true);
				}
				break;
			case 80: // down arrow
				stay = 1;
				break;
			case 72: // up arrow
				RotateBrick();
				DrawBrick(true);
				break;
			}
		} else {
			switch(tolower(ch))
			{
			case ' ':
				while(stay=1, SinkBrick()==false) {;}
				return true;
			case 'p':
				// Display Bricks
				system("cls");
				gotoxy(36, 12);
				puts("P A U S E");
				getch();
				// Restore Display
				system("cls");
				DrawBoard();
				DrawBrick(true);
				DrawBrickBox();
				DrawNextBrick();
				DrawInterface();
				break;
			case 'q':
				ClearGame();
				exit(0);
			}
		}
	}
	return false;
}
void gotoxy(int x, int y)
{
	COORD cur = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

void curtype(int type)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch(type)
	{
	case HIDE:
		CurInfo.bVisible = FALSE;
		CurInfo.dwSize = 1;
		break;

	case NORMAL:
		CurInfo.bVisible = TRUE;
		CurInfo.dwSize = 20;
		break;
	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}