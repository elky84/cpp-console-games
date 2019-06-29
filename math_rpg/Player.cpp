#include "Library.h"

Player::Player() {
	X = 2, Y = 3;
	BeforeX = 2, BeforeY = 3;
	MaxExp = 10; Exp = 0;
	MaxHp = 50; Hp = 50;
	Level = 1;
	money = 0;
	strcpy(Job,"자연수");
	for(int i = 0; i < 10; i++) {
		itemList[i] = ' ';
	}
	for(int i = 0; i < 20; i++) {
		questList[i] = 0;
	}
}

Player::~Player() {
}

void Player::DrawPlayer() {
	gotoxy(X*2,Y);
	SetColor(YELLOW,DARK_GREEN);
	printf("★");
}

void Player::ErasePlayer() {
	gotoxy(BeforeX*2,BeforeY);
	SetColor(WHITE,BLACK);
	ShowMap(GetMapID(),BeforeX,BeforeY);
}

void Player::CheckState() {
	while(Exp >= MaxExp) {
		Exp		-=	MaxExp;
		Level	+=	1;
		MaxExp	=	(double)(10 * pow(1.2,Level-1));
		MaxHp	=	(double)(50 * pow(1.1,Level-1));
		Hp		=	MaxHp;
		Talk_System("아싸 레벨업!! 올ㅋ");
		ShowState();
	}
	MaxExp	=	(double)(10 * pow(1.2,Level-1));
	MaxHp	=	(double)(50 * pow(1.1,Level-1));
	if(Hp < 1) {
		Talk_System("체력이 부족해 사망! 마을에서 부활하고 경험치가 초기화됩니다.");
		SetMapID(0);
		SetX(2); SetY(3);
		Hp = MaxHp;
		Exp = 0;
		DrawMap();
	}
	ShowState();
		
}

void Player :: PrintName() {
	printf("%s",name);
}

void Player :: PrintJob() {
	printf("%s",Job);
}