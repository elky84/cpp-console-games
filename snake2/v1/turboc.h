//////////////////////////////////////////////////////////////////////
// turboc.h
//////////////////////////////////////////////////////////////////////
#pragma once
#include <windows.h>

typedef enum {NOCURSOR, NORMALCURSOR} CURSORTYPE;
void curtype(CURSORTYPE CursorType);
void gotoxy(int x, int y);
int wherex();
int wherey();
int getchxy(int x, int y);