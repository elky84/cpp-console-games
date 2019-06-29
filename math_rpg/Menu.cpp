#include "Library.h"

int MenuOk = 1;
int IsMenuOk = 1;

void ShowMenu() {
	
	char ch;
	int select = 1;

	system("mode con: cols=50 lines=30");

	while(MenuOk == 1) {
		switch(select) {
		case 1:
			SetColor(SKY_BLUE,BLACK); gotoxy(10,5); printf("▷   게   임   시   작   ◁");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     게   임   방   법     ");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     불   러   오   기     ");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     제     작      자     ");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     게   임   종   료     ");
			break;
		case 2:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     게   임   시   작     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,9); printf("▷   게   임   방   법   ◁");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     불   러   오   기     ");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     제     작      자     ");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     게   임   종   료     ");
			break;
		case 3:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     게   임   시   작     ");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     게   임   방   법     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,13); printf("▷   불   러   오   기   ◁");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     제     작      자     ");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     게   임   종   료     ");
			break;
		case 4:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     게   임   시   작     ");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     게   임   방   법     ");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     불   러   오   기     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,17); printf("▷   제     작      자   ◁");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     게   임   종   료     ");
			break;
		case 5:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     게   임   시   작     ");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     게   임   방   법     ");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     불   러   오   기     ");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     제     작      자     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,21); printf("▷   게   임   종   료   ◁");
			break;
		default:
			break;
		}

		SetColor(0,0);
		gotoxy(5,5);
		ch = getche();
		gotoxy(5,5); printf("  ");

		switch(ch) {
		case UP:
			if(select > 1) { select--; }
			break;
		case DOWN:
			if(select < 5) { select++; }
			break;
		case SPACE:
			SelectMenu(select);
			break;
		default:
			break;
		}

		
	}
}

void SelectMenu(int _select) {
	char name[20];

	SetColor(WHITE,BLACK);

	switch(_select) {
	case 1:
		system("cls"); SetColor(SKY_BLUE,BLACK);
		gotoxy(5,10); printf("이름을 입력해 주세요");
		SetColor(WHITE,BLACK);
		gotoxy(5,15); scanf("%s",name); fflush(stdin);
		SetCharName(name);
		MenuOk = 0;
		break;
	case 2:
		system("cls"); SetColor(SKY_BLUE,BLACK);
		printf("[조작키]\n\n\n\n");
		printf("이동 : 방향키\n\n대화 및 기타조작 : 스페이스바\n\n메뉴보기 : ESC\n\n\n\n");
		SetColor(GREEN,BLACK);
		printf("[게임 방법]\n\n\n\n");
		printf("게임 시작을 선택하시면 이름을 입력하게 됩니다\n\n");
		printf("이름을 입력후 엔터를 누르시면 자동으로 시작합니다\n\n");
		printf("자세한 정보는 게임 안내를 선택해 주세요");
		getche();
		system("cls");
		break;
	case 3:
		system("cls"); SetColor(WHITE,BLACK);
		printf("\n불러오는 중입니다......\n\n");
		Load();
		MenuOk = 0;
		system("cls");
		break;
	case 4:
		system("cls"); SetColor(WHITE,BLACK);
		printf("[제작자]\n\n\n");
		printf("프로젝트 명 : Math RPG\n\n");
		printf("제작 : 이 도 현\n\n");
		printf("제작 언어 : C/C++ & API\n\n");
		printf("버전 [빌드] : 6 . 0 [build 20]\n\n");
		printf("제작 기간 : 12일차\n\n");
		printf("홈페이지 : waylight3.blog.me\n\n");
		printf("세계공부협회 : http://cafe.naver.com/dostudynow/ \n\n");
		printf("세계공부협회와 DreamMaker가 후원합니다!\n\n");
		printf("게임을 이용해주셔서 감사합니다");
		getche();
		system("cls");
		break;
	case 5:
		exit(0);
	default:
		exit(0);
		break;
	}
}

void ShowMenuESC() {

	int select = 1;
	char ch;

	IsMenuOk = 1;
	LoadNewMenu();

	while(IsMenuOk == 1) {
		switch(select) {
		case 1:
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,3); printf("   계   속   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   게   임   방   법   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   저   장   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   제     작      자   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   게   임   종   료   ");
			break;
		case 2:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   계   속   하   기   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,6); printf("   게   임   방   법   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   저   장   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   제     작      자   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   게   임   종   료   ");
			break;
		case 3:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   계   속   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   게   임   방   법   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,9); printf("   저   장   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   제     작      자   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   게   임   종   료   ");
			break;
		case 4:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   계   속   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   게   임   방   법   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   저   장   하   기   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,12); printf("   제     작      자   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   게   임   종   료   ");
			break;
		case 5:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   계   속   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   게   임   방   법   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   저   장   하   기   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   제     작      자   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,15); printf("   게   임   종   료   ");
			break;
		default:
			break;
		}

		SetColor(0,0);
		gotoxy(82,25);
		ch = getche();
		gotoxy(82,25); printf("  ");

		switch(ch) {
		case UP:
			if(select > 1) { select--; }
			break;
		case DOWN:
			if(select < 5) { select++; }
			break;
		case SPACE:
			SelectMenuESC(select);
			break;
		case ESC:
			IsMenuOk = 0;
		default:
			break;
		}

		
	}
	DrawMap();
	ShowState();

}

void SelectMenuESC(int select) {
	SetColor(WHITE,BLACK);

	switch(select) {
	case 1:
		IsMenuOk = 0;
		break;
	case 2:
		LoadNewMenu(); SetColor(SKY_BLUE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("[조작키]\n\n\n\n");
		gotoxy(26,5); printf("이동 : 방향키");
		gotoxy(26,7); printf("대화 및 조작 : 스페이스바");
		gotoxy(26,9); printf("메뉴보기 : ESC");
		gotoxy(26,11); printf("자세한 내용은 홈페이지 참고");
		getche();
		LoadNewMenu();
		break;
	case 3:
		LoadNewMenu(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("저장중입니다......");
		Save(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,5); printf("저장이 완료되었습니다!");
		gotoxy(26,7); printf("아무키나 누르면 종료됩니다.");
		getche();
		LoadNewMenu();
		break;
	case 4:
		LoadNewMenu(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("[제작자]");
		gotoxy(26,5); printf("프로젝트 명 : Math RPG");
		gotoxy(26,7); printf("제작 : 이 도 현");
		gotoxy(26,9); printf("제작 언어 : C/C++ & API");
		gotoxy(26,11); printf("버전 [빌드] : 6 . 0 [build 20]");
		gotoxy(26,13); printf("제작 기간 : 12일차");
		gotoxy(26,15); printf("홈페이지 : waylight3.blog.me");;
		getche();
		LoadNewMenu();
		break;
	case 5:
		LoadNewMenu(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("저장중입니다......");
		Save(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,5); printf("저장이 완료되었습니다!");
		gotoxy(26,7); printf("아무키나 누르면 종료됩니다.");
		getche();
		exit(0);
	default:
		break;
	}
}

void LoadNewMenu() {
	SetColor(WHITE,DARK_SKY_BLUE);
	gotoxy(23,1);  printf("┌────────────────┐");
	gotoxy(23,2);  printf("│                                │");
	gotoxy(23,3);  printf("│                                │"); // 3
	gotoxy(23,4);  printf("│                                │");
	gotoxy(23,5);  printf("│                                │");
	gotoxy(23,6);  printf("│                                │"); // 6
	gotoxy(23,7);  printf("│                                │");
	gotoxy(23,8);  printf("│                                │");
	gotoxy(23,9);  printf("│                                │"); // 9
	gotoxy(23,10); printf("│                                │");
	gotoxy(23,11); printf("│                                │");
	gotoxy(23,12); printf("│                                │"); // 12
	gotoxy(23,13); printf("│                                │");
	gotoxy(23,14); printf("│                                │");
	gotoxy(23,15); printf("│                                │"); // 15
	gotoxy(23,16); printf("│                                │");
	gotoxy(23,17); printf("└────────────────┘");
}