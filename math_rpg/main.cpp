#include "Library.h"

void main() {
	SetConsoleTitle(TEXT("Math RPG :: 수학몽시향 [ ver 6 . 0  ]"));

	/*커서 깜빡임 제거*/
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
	gotoxy(82,1); printf("현재 위치 : 초등 마을");
	DrawPlayer();
	SetConsoleTitle(TEXT("Math RPG :: 수학몽시향 [ ver 6 . 0 ]"));
	while(TRUE) {
		MovePlayer();
	}
}