
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
  BLACK,		 /*  0 : ��� */
  DARK_BLUE,	 /*  1 : ��ο� �Ķ� */
  DARK_GREEN,	 /*  2 : ��ο� �ʷ� */
  DARK_SKY_BLUE, /*  3 : ��ο� �ϴ� */
  DARK_RED,		 /*  4 : ��ο� ���� */
  DARK_VIOLET,	 /*  5 : ��ο� ���� */
  DARK_YELLOW,	 /*  6 : ��ο� ��� */
  GRAY,			 /*  7 : ȸ�� */
  DARK_GRAY,	 /*  8 : ��ο� ȸ�� */
  BLUE,		  	 /*  9 : �Ķ� */
  GREEN,		 /* 10 : �ʷ� */
  SKY_BLUE,		 /* 11 : �ϴ� */
  RED,			 /* 12 : ���� */
  VIOLET,		 /* 13 : ���� */
  YELLOW,		 /* 14 : ��� */
  WHITE			 /* 15 : �Ͼ� */
};

enum {
	DIRT,		/* 0 : �� */
	GRASS,		/* 1 : Ǯ */
	STONE,		/* 2 : �� */
	WATER,		/* 3 : �� */
	MONSTER,	/* 4 : ���� */
	NPC,		/* 5 : NPC */
	WALL		/* 6 : �� */
};

#endif