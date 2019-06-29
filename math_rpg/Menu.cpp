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
			SetColor(SKY_BLUE,BLACK); gotoxy(10,5); printf("��   ��   ��   ��   ��   ��");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     ��     ��      ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     ��   ��   ��   ��     ");
			break;
		case 2:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     ��   ��   ��   ��     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,9); printf("��   ��   ��   ��   ��   ��");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     ��     ��      ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     ��   ��   ��   ��     ");
			break;
		case 3:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     ��   ��   ��   ��     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,13); printf("��   ��   ��   ��   ��   ��");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     ��     ��      ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     ��   ��   ��   ��     ");
			break;
		case 4:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     ��   ��   ��   ��     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,17); printf("��   ��     ��      ��   ��");
			SetColor(WHITE,BLACK); gotoxy(10,21); printf("     ��   ��   ��   ��     ");
			break;
		case 5:
			SetColor(WHITE,BLACK); gotoxy(10,5); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,9); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,13); printf("     ��   ��   ��   ��     ");
			SetColor(WHITE,BLACK); gotoxy(10,17); printf("     ��     ��      ��     ");
			SetColor(SKY_BLUE,BLACK); gotoxy(10,21); printf("��   ��   ��   ��   ��   ��");
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
		gotoxy(5,10); printf("�̸��� �Է��� �ּ���");
		SetColor(WHITE,BLACK);
		gotoxy(5,15); scanf("%s",name); fflush(stdin);
		SetCharName(name);
		MenuOk = 0;
		break;
	case 2:
		system("cls"); SetColor(SKY_BLUE,BLACK);
		printf("[����Ű]\n\n\n\n");
		printf("�̵� : ����Ű\n\n��ȭ �� ��Ÿ���� : �����̽���\n\n�޴����� : ESC\n\n\n\n");
		SetColor(GREEN,BLACK);
		printf("[���� ���]\n\n\n\n");
		printf("���� ������ �����Ͻø� �̸��� �Է��ϰ� �˴ϴ�\n\n");
		printf("�̸��� �Է��� ���͸� �����ø� �ڵ����� �����մϴ�\n\n");
		printf("�ڼ��� ������ ���� �ȳ��� ������ �ּ���");
		getche();
		system("cls");
		break;
	case 3:
		system("cls"); SetColor(WHITE,BLACK);
		printf("\n�ҷ����� ���Դϴ�......\n\n");
		Load();
		MenuOk = 0;
		system("cls");
		break;
	case 4:
		system("cls"); SetColor(WHITE,BLACK);
		printf("[������]\n\n\n");
		printf("������Ʈ �� : Math RPG\n\n");
		printf("���� : �� �� ��\n\n");
		printf("���� ��� : C/C++ & API\n\n");
		printf("���� [����] : 6 . 0 [build 20]\n\n");
		printf("���� �Ⱓ : 12����\n\n");
		printf("Ȩ������ : waylight3.blog.me\n\n");
		printf("���������ȸ : http://cafe.naver.com/dostudynow/ \n\n");
		printf("���������ȸ�� DreamMaker�� �Ŀ��մϴ�!\n\n");
		printf("������ �̿����ּż� �����մϴ�");
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
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,3); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   ��     ��      ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   ��   ��   ��   ��   ");
			break;
		case 2:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   ��   ��   ��   ��   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,6); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   ��     ��      ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   ��   ��   ��   ��   ");
			break;
		case 3:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   ��   ��   ��   ��   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,9); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   ��     ��      ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   ��   ��   ��   ��   ");
			break;
		case 4:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   ��   ��   ��   ��   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,12); printf("   ��     ��      ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,15); printf("   ��   ��   ��   ��   ");
			break;
		case 5:
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,3); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,6); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,9); printf("   ��   ��   ��   ��   ");
			SetColor(WHITE,DARK_SKY_BLUE); gotoxy(29,12); printf("   ��     ��      ��   ");
			SetColor(SKY_BLUE,DARK_SKY_BLUE); gotoxy(29,15); printf("   ��   ��   ��   ��   ");
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
		gotoxy(26,3); printf("[����Ű]\n\n\n\n");
		gotoxy(26,5); printf("�̵� : ����Ű");
		gotoxy(26,7); printf("��ȭ �� ���� : �����̽���");
		gotoxy(26,9); printf("�޴����� : ESC");
		gotoxy(26,11); printf("�ڼ��� ������ Ȩ������ ����");
		getche();
		LoadNewMenu();
		break;
	case 3:
		LoadNewMenu(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("�������Դϴ�......");
		Save(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,5); printf("������ �Ϸ�Ǿ����ϴ�!");
		gotoxy(26,7); printf("�ƹ�Ű�� ������ ����˴ϴ�.");
		getche();
		LoadNewMenu();
		break;
	case 4:
		LoadNewMenu(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("[������]");
		gotoxy(26,5); printf("������Ʈ �� : Math RPG");
		gotoxy(26,7); printf("���� : �� �� ��");
		gotoxy(26,9); printf("���� ��� : C/C++ & API");
		gotoxy(26,11); printf("���� [����] : 6 . 0 [build 20]");
		gotoxy(26,13); printf("���� �Ⱓ : 12����");
		gotoxy(26,15); printf("Ȩ������ : waylight3.blog.me");;
		getche();
		LoadNewMenu();
		break;
	case 5:
		LoadNewMenu(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,3); printf("�������Դϴ�......");
		Save(); SetColor(WHITE,DARK_SKY_BLUE);
		gotoxy(26,5); printf("������ �Ϸ�Ǿ����ϴ�!");
		gotoxy(26,7); printf("�ƹ�Ű�� ������ ����˴ϴ�.");
		getche();
		exit(0);
	default:
		break;
	}
}

void LoadNewMenu() {
	SetColor(WHITE,DARK_SKY_BLUE);
	gotoxy(23,1);  printf("������������������������������������");
	gotoxy(23,2);  printf("��                                ��");
	gotoxy(23,3);  printf("��                                ��"); // 3
	gotoxy(23,4);  printf("��                                ��");
	gotoxy(23,5);  printf("��                                ��");
	gotoxy(23,6);  printf("��                                ��"); // 6
	gotoxy(23,7);  printf("��                                ��");
	gotoxy(23,8);  printf("��                                ��");
	gotoxy(23,9);  printf("��                                ��"); // 9
	gotoxy(23,10); printf("��                                ��");
	gotoxy(23,11); printf("��                                ��");
	gotoxy(23,12); printf("��                                ��"); // 12
	gotoxy(23,13); printf("��                                ��");
	gotoxy(23,14); printf("��                                ��");
	gotoxy(23,15); printf("��                                ��"); // 15
	gotoxy(23,16); printf("��                                ��");
	gotoxy(23,17); printf("������������������������������������");
}