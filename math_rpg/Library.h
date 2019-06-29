
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include "Map.h"
#include "Menu.h"
#include "Player.h"
#include "GameHost.h"
#include "NPC.h"
#include "Item.h"
#include "Mob.h"

#ifndef _LIBRARY_H_
#define _LIBRARY_H_

#define LEFT 75 
#define RIGHT 77 
#define UP  72 
#define DOWN 80 
#define SPACE 32
#define ESC 27

#define MAX_X 40
#define MAX_Y 20

void gotoxy(int x, int y);
void SetColor(int color, int bgcolor);
int Factorial(int n);
int Permutation(int a, int b);
int Combination(int a, int b);
int H_Combination(int a, int b);
int P_Permutation(int a, int b);

enum {
  BLACK,		 /*  0 : 까망 */
  DARK_BLUE,	 /*  1 : 어두운 파랑 */
  DARK_GREEN,	 /*  2 : 어두운 초록 */
  DARK_SKY_BLUE, /*  3 : 어두운 하늘 */
  DARK_RED,		 /*  4 : 어두운 빨강 */
  DARK_VIOLET,	 /*  5 : 어두운 보라 */
  DARK_YELLOW,	 /*  6 : 어두운 노랑 */
  GRAY,			 /*  7 : 회색 */
  DARK_GRAY,	 /*  8 : 어두운 회색 */
  BLUE,		  	 /*  9 : 파랑 */
  GREEN,		 /* 10 : 초록 */
  SKY_BLUE,		 /* 11 : 하늘 */
  RED,			 /* 12 : 빨강 */
  VIOLET,		 /* 13 : 보라 */
  YELLOW,		 /* 14 : 노랑 */
  WHITE			 /* 15 : 하양 */
};

enum {
	DIRT,		/* 0 : 흙 */
	GRASS,		/* 1 : 풀 */
	STONE,		/* 2 : 돌 */
	WATER,		/* 3 : 물 */
	MONSTER,	/* 4 : 몬스터 */
	NPC,		/* 5 : NPC */
	WALL		/* 6 : 벽 */
};

#endif