//////////////////////////////////////////////////////////////////////
// turboc.cpp
//////////////////////////////////////////////////////////////////////
#include "turboc.h"

void curtype(CURSORTYPE CursorType)
{
	CONSOLE_CURSOR_INFO CurInfo;

	switch(CursorType) {
		case NOCURSOR:
			CurInfo.bVisible = FALSE;
			CurInfo.dwSize = 1;
			break;

		case NORMALCURSOR:
			CurInfo.bVisible = TRUE;
			CurInfo.dwSize = 20;
			break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void gotoxy(int x, int y)
{
	COORD cur = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
}

int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO BufInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &BufInfo);
	return BufInfo.dwCursorPosition.Y;
}

int getchxy(int x, int y)
{
	COORD cur = {x, y};
	TCHAR ch;
	DWORD dwRead;

	ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), &ch, 1, cur, &dwRead);
	return ch;
}