#include "Library.h"

void main() {
	SetConsoleTitle(TEXT("Math RPG :: ���и����� [ ver 6 . 0  ]"));

	/*Ŀ�� ������ ����*/
	static HANDLE hOut;
	CONSOLE_CURSOR_INFO cInfo;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cInfo.dwSize = 100;
	cInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &cInfo);
	
	ShowMenu();
	SetMapID(0);
	system("mode con:cols=115 lines=30");
	DrawMap();
	ShowState();
	gotoxy(82,1); printf("���� ��ġ : �ʵ� ����");
	DrawPlayer();
	SetConsoleTitle(TEXT("Math RPG :: ���и����� [ ver 6 . 0 ]"));
	while(TRUE) {
		MovePlayer();
	}
}