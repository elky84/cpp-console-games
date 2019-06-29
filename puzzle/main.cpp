#include <stdio.h>
#include <time.h>
#include <conio.h>
#include "turboc.h"

void InitEnvironment();
void InitGame();
void DrawGame();
bool CheckGame();
void Shuffle();
void ProcKey(int ch, bool bShuffleMode = false);

int nx, ny;
int ShuffleLevel;
int Board[5][5]; // Board[Y][X]

void main()
{
	InitEnvironment();
	InitGame();
	DrawGame();

	for(;;) {
		ProcKey(getch());
		DrawGame();
		if(CheckGame()) { break; }
	}
}

void InitEnvironment()
{
	curtype(NOCURSOR);
	srand((unsigned)time(NULL));
}

void InitGame()
{
	int i;
	int size = sizeof(Board) / sizeof(Board[0][0]);

	nx = sizeof(Board[0]) / sizeof(Board[0][0]) - 1;
	ny = sizeof(Board) / sizeof(Board[0]) - 1;
	ShuffleLevel = 50;

	for(i=0; i<size-1; ++i) {
		Board[0][i] = i+1;
	}

	Shuffle();
}

void DrawGame()
{
	int x, y;
	int width, height;

	width = sizeof(Board[0]) / sizeof(Board[0][0]);
	height = sizeof(Board) / sizeof(Board[0]);

	for(x=0; x<width; ++x) {
		for(y=0; y<height; ++y) {
			gotoxy(5+5*x, 3+3*y);
			if(Board[y][x] != 0) {
				printf("%2d", Board[y][x]);
			} else {
				printf("  ");
			}
		}
	}
}

bool CheckGame()
{
	int i;
	int size = sizeof(Board) / sizeof(Board[0][0]);

	for(i=0; i<size-1; ++i) {
		if(Board[0][i] != i+1) { return false; }
	}
	return true;
}

void Shuffle()
{
	int i;
	int Keys[] = {72, 75, 77, 80};

	for(i=0; i<ShuffleLevel; ++i) {
		ProcKey(Keys[rand() % 4], true);
	}
}

void ProcKey(int ch, bool bShuffleMode)
{
	if(ch == 0xE0 || ch == 0x00 || bShuffleMode) {
		if(!bShuffleMode) { ch = getch(); }

		// up arrow
		if(ch == 72) {
			int height = sizeof(Board) / sizeof(Board[0]);
			if(ny < height-1) {
				Board[ny][nx] = Board[ny+1][nx];
				Board[ny+1][nx] = 0;
				++ny;
			}
		}
		// down arrow
		if(ch == 80) {
			if(ny > 0) {
				Board[ny][nx] = Board[ny-1][nx];
				Board[ny-1][nx] = 0;
				--ny;
			}
		}

		// left arrow
		if(ch == 75) {
			int width = sizeof(Board[0]) / sizeof(Board[0][0]);
			if(nx < width-1) {
				Board[ny][nx] = Board[ny][nx+1];
				Board[ny][nx+1] = 0;
				++nx;
			}
		}

		// right arrow
		if(ch == 77) {
			if(nx > 0) {
				Board[ny][nx] = Board[ny][nx-1];
				Board[ny][nx-1] = 0;
				--nx;
			}
		}
	}
}