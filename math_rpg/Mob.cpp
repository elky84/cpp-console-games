#include "Library.h"

int count_Mixed = 0;
int count_Func1 = 0;
int count_Func2 = 0;
int count_Comb = 0;
int count_HComb = 0;
int count_Differ1 = 0;
int count_Differ2 = 0;
int count_Integ1 = 0;
int count_Integ2 = 0;
long long MasterKey = 999999999;

void SetMasterKey(int n) {
	MasterKey = n;
}

void MakeMob(int mapID,int number) {

	int x,y;
	int count = 0;
	srand((unsigned int)time(NULL));

	while(count < number) {
		x = rand() % 37 + 1;
		y = rand() % 17 + 1;

		if(GetMapEntry(mapID,x,y) < 5) {
			SetMapEntry(mapID,x,y,MONSTER);
			count++;
		}
	}
}

void ClearMonster(int ID, int entry) {
	for(int i = 1; i < 19; i++) {
		for(int j = 1; j < 39; j++) {
			if(GetMapEntry(ID, j, i) == entry) {
				SetMapEntry(ID, j, i, GRASS);
			}
		}
	}
}

void CheckMob(int ID, int x, int y) {
	if(GetMapEntry(ID, x, y) == MONSTER) {
		FightMob(ID, x, y);
	}
}

void FightMob(int ID, int x, int y) {
	switch(ID) {
	case 0:
		break;
	case 1:
		if(IsItem('+') == 1) {
			Fight_Add();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("������ �� �� ����. ����� ã�ƺ���");
			Talk_System("������ ����� ��Ű���Լ� ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	case 2:
		if(IsItem('-') == 1) {
			Fight_Sub();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("������ �� �� ����. ����� ã�ƺ���");
			Talk_System("������ ��ҿ��Լ� ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	case 3:
		if(IsItem('*') == 1) {
			Fight_Multi();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("������ �� �� ����. ����� ã�ƺ���");
			Talk_System("������ ��ҿ��Լ� ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	case 4:
		if(GetQuestList(4) != 0) {
			Fight_Mixed();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ȥ�� ����� �����ΰ� ����");
			Talk_System("������ �ҿ쿡�Լ� ����Ʈ�� ��������");
		}
		break;
	case 6:
		if(IsItem('f') == 1) {
			Fight_Func1();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ������ ����� �����ΰ� ����");
			Talk_System("������ ��ҿ��Լ� ��������Ʈ�� ��������");
		}
		break;
	case 7:
		if(IsItem('f') == 1) {
			Fight_Func2();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ������ ����� �����ΰ� ����");
			Talk_System("������ ��ҿ��Լ� ��������Ʈ�� ��������");
		}
		break;
	case 9:
		if(IsItem('P') == 1) {
			Fight_Permutation();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ���� ����� �����ΰ� ����");
			Talk_System("������ �������Լ� ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	case 10:
		if(IsItem('C') == 1) {
			Fight_Combination();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ���� ����� �����ΰ� ����");
			Talk_System("������ ���信�Լ� ����Ʈ�� ��������");
		}
		break;
	case 11:
		if(IsItem('P') == 1) {
			Fight_P_Permutation();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ���� ����� �����ΰ� ����");
			Talk_System("������ �������Լ� ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	case 12:
		if(IsItem('C') == 1) {
			Fight_H_Combination();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ���� ����� �����ΰ� ����");
			Talk_System("������ ���信�Լ� ����Ʈ�� ��������");
		}
		break;
	case 13:
		if(IsItem('d') == 1) {
			Fight_Differentiation1();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� �̺� ����� �����ΰ� ����");
			Talk_System("������ ���뿡�Լ� ����Ʈ�� ��������");
		}
		break;
	case 14:
		if(IsItem('d') == 1) {
			Fight_Differentiation2();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� �̺� ����� �����ΰ� ����");
			Talk_System("������ ���뿡�Լ� ����Ʈ�� ��������");
		}
		break;
	case 15:
		if(IsItem('s') == 1) {
			Fight_Integration1();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ���� ����� �����ΰ� ����");
			Talk_System("������ ������ ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	case 16:
		if(IsItem('s') == 1) {
			Fight_Integration2();
			SetMapEntry(ID, x, y, GRASS);
		}
		else {
			Talk_Player("���� ���� ����� �����ΰ� ����");
			Talk_System("������ ������ ����Ʈ�� �Ϸ��ϼ���");
		}
		break;
	default:
		break;
	}
}

void Fight_Add() {
	srand((unsigned int)time(NULL));
	int a = rand() % 100 + 1;
	int b = rand() % 100 + 1;
	int _Hp = rand() % 5 + 1;		// 1 ~ 5
	int answer = 0;
	int dropPoint = rand() % 10;
	int getExp = rand() % 5 + 3;	// 3 ~ 7
	int _money = rand() % 10 + 1;	// 1 ~ 10

	Talk_Mob("���ϱ� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%d + %d �� ���ΰ�?", a,b);
	gotoxy(1,23); scanf("%d",&answer); fflush(stdin);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if(answer == a + b || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(dropPoint < 5 && GetQuestList(1) == 1) {
			Talk_System("������ '-'�� ȹ���ߴ�!");
			SetQuestList(1,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Sub() {
	srand((unsigned int)time(NULL));
	int a = rand() % 100 + 1;
	int b = rand() % 100 + 1;
	int _Hp = rand() % 10 + 2;		// 2 ~ 9
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 5 + 5;	// 5 ~ 9
	int _money = rand() % 10 + 5;	// 5 ~ 14

	Talk_Mob("���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%d - %d �� ���ΰ�?", a,b); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if(answer == a - b || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(dropPoint < 5 && GetQuestList(2) == 1) {
			Talk_System("������ '*'�� ȹ���ߴ�!");
			Talk_Player("� ������ ������");
			SetQuestList(2,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Multi() {
	srand((unsigned int)time(NULL));
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	int _Hp = rand() % 10 + 10;		// 10 ~ 19
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 5 + 20;	// 20 ~ 25
	int _money = rand() % 10 + 10;	// 10 ~ 19

	Talk_Mob("���ϱ� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%d * %d �� ���ΰ�?", a,b); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if(answer == a * b || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(dropPoint < 5 && GetQuestList(3) == 1) {
			Talk_System("������ '/'�� ȹ���ߴ�!");
			Talk_Player("� ������ ������");
			SetQuestList(3,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Mixed() {
	srand((unsigned int)time(NULL));
	int a = rand() % 20 + 1;
	int b = rand() % 20 + 1;
	int c = rand() % 20 + 1;
	int d = rand() % 20 + 1;
	int _Hp = rand() % 10 + 20;		// 20 ~ 29
	int answer;
	int getExp = rand() % 5 + 30;	// 30 ~ 34
	int _money = rand() % 10 + 20;	// 20 ~ 29

	Talk_Mob("ȥ�տ��� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("(%d + %d) * (%d - %d) �� ���ΰ�?", a,b,c,d); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == ((a+b)*(c-d)) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(4) == 1) {
			count_Mixed++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : ȥ�հ�� ���� %d / 5 ���� ���",count_Mixed);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Mixed >= 5) {
				Talk_System("ȥ�հ�� ���� 5������ ��� ����ߴ�!");
				Talk_Player("� �����Ϸ� ���߰ڴ�!");
				SetQuestList(4,2);
			}
		}		
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Func1() {
	srand((unsigned int)time(NULL));
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	int c = rand() % 10 + 1;
	int _Hp = rand() % 10 + 30;		// 30 ~ 39
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 5 + 50;	// 50 ~ 55
	int _money = rand() % 10 + 30;	// 30 ~ 39

	Talk_Mob("������ ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%dx + %d���� x = %d�϶� ���� ���� ���ΰ�?", a,b,c); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == (a * c + b) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(5) == 1) {
			count_Func1++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : ������ ���� %d / 10 ���� ���",count_Func1);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Func1 >= 10) {
				Talk_System("������ ���� 10������ ��� ����ߴ�!");
				Talk_Player("� ������ �ҿ쿡�� ������");
				SetQuestList(5,2);
			}
		}
		if(dropPoint < 5 && GetQuestList(6) == 1) {
				Talk_System("������ '���� �ٱ���'�� ȹ���ߴ�!");
				Talk_Player("� ������ �������� ������");
				SetQuestList(6,2);
			}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Func2() {
	srand((unsigned int)time(NULL));
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	int c = rand() % 10 + 1;
	int d = rand() % 10 + 1;
	int _Hp = rand() % 10 + 40;		// 40 ~ 49
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 100;	// 100 ~ 109
	int _money = rand() % 10 + 50;	// 50 ~ 59

	Talk_Mob("������ ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%dx^2 + %dx + %d���� x = %d�϶� ���� ���� ���ΰ�?", a,b,c,d); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == (a*d*d + b*d + c) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(7) == 1) {
			count_Func2++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : ������ ���� %d / 10 ���� ���",count_Func2);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Func2 >= 10) {
				Talk_System("������ ���� 10������ ��� ����ߴ�!");
				Talk_Player("� ������ �ҿ쿡�� ������");
				SetQuestList(7,2);
			}
		}
		if(dropPoint < 5 && GetQuestList(8) == 1) {
				Talk_System("������ '���� �����'�� ȹ���ߴ�!");
				Talk_Player("� ������ �������� ������");
				SetQuestList(8,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Permutation() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 50;		// 50 ~ 69
	int a = rand() % 6 + 1;
	int b = rand() % 5 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 150;	// 150 ~ 159
	int _money = rand() % 10 + 70;	// 70 ~ 79

	while(a < b) {
		a = rand() % 6 + 1;
		b = rand() % 5 + 1;
	}

	Talk_Mob("���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("���� %dP%d �� ���ΰ�", a,b); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == Permutation(a,b) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(dropPoint < 5 && GetQuestList(9) == 1) {
				Talk_System("������ '���� ����'�� ȹ���ߴ�!");
				Talk_Player("� ������ ���ÿ��� ������");
				SetQuestList(9,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Combination() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 50;		// 50 ~ 69
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 160;	// 160 ~ 169
	int _money = rand() % 10 + 80;	// 80 ~ 89

	while(a < b) {
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
	}

	Talk_Mob("���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("���� %dC%d �� ���ΰ�", a,b); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == Combination(a,b) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(11) == 1) {
			count_Comb++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : ���� ���� %d / 20 ���� ���",count_Comb);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Comb >= 20) {
				Talk_System("���� ���� 20������ ��� ����ߴ�!");
				Talk_Player("� ������ ���信�� ������");
				SetQuestList(11,2);
			}
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_P_Permutation() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 60;		// 60 ~ 89
	int a = rand() % 5 + 1;
	int b = rand() % 4 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 150;	// 300 ~ 309
	int _money = rand() % 10 + 110;	// 110 ~ 119

	Talk_Mob("�ߺ� ���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("�ߺ� ���� %d��%d �� ���ΰ�", a,b); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == P_Permutation(a,b) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(dropPoint < 5 && GetQuestList(10) == 1) {
				Talk_System("������ '������ ���� ����'�� ȹ���ߴ�!");
				Talk_Player("� ������ ���ÿ��� ������");
				SetQuestList(10,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_H_Combination() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 60;		// 60 ~ 89
	int a = rand() % 5 + 1;
	int b = rand() % 5 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 150;	// 150 ~ 159
	int _money = rand() % 10 + 130;	// 130 ~ 139

	Talk_Mob("�ߺ� ���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("�ߺ� ���� %dH%d �� ���ΰ�", a,b); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == H_Combination(a,b) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(12) == 1) {
			count_HComb++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : �ߺ� ���� ���� %d / 20 ���� ���",count_HComb);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_HComb >= 20) {
				Talk_System("�ߺ� ���� ���� 20������ ��� ����ߴ�!");
				Talk_Player("� ������ ���信�� ������");
				SetQuestList(12,2);
			}
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Differentiation1() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 80;		// 80 ~ 109
	int a = rand() % 5 + 1;
	int b = rand() % 5 + 1;
	int c = rand() % 5 + 1;
	int d = rand() % 5 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 200;	// 200 ~ 209
	int _money = rand() % 20 + 180;	// 180 ~ 209

	Talk_Mob("�ϱ� �̺� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("f(x) = %dx^2 + %dx + %d �Լ����� x = %d �϶��� �����?", a,b,c,d); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == (2*a*d + b) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(15) == 1) {
			count_Differ1++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : �ϱ� �̺� ���� %d / 10 ���� ���",count_Differ1);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Differ1 >= 10) {
				Talk_System("�ϱ� �̺� ���� 10������ ��� ����ߴ�!");
				Talk_Player("� ������ �ļҿ��� ������");
				SetQuestList(15,2);
			}
		}
		if(dropPoint < 5 && GetQuestList(13) == 1) {
				Talk_System("������ '������'�� ȹ���ߴ�!");
				Talk_Player("� ������ ���뿡�� ������");
				SetQuestList(13,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Differentiation2() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 100;		// 100 ~ 119
	int a = rand() % 5 + 1;
	int b = rand() % 5 + 1;
	int c = rand() % 5 + 1;
	int d = rand() % 5 + 1;
	int e = rand() % 5 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 350;	// 350 ~ 359
	int _money = rand() % 20 + 230;	// 230 ~ 259

	Talk_Mob("��� �̺� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("f(x) = %dx^3 %dx^2 + %dx + %d �Լ����� x = %d �϶��� �����?", a,b,c,d,e); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == (3*a*e*e + 2*b*e + c) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(16) == 1) {
			count_Differ2++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : ��� �̺� ���� %d / 10 ���� ���",count_Differ2);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Differ2 >= 10) {
				Talk_System("��� �̺� ���� 10������ ��� ����ߴ�!");
				Talk_Player("� ������ �ļҿ��� ������");
				SetQuestList(16,2);
			}
		}
		if(dropPoint < 5 && GetQuestList(14) == 1) {
				Talk_System("������ '���� �ʸ�'�� ȹ���ߴ�!");
				Talk_Player("� ������ ���뿡�� ������");
				SetQuestList(14,2);
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Integration1() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 130;		// 130 ~ 149
	int a = (rand() % 2 + 1) * 2;
	int b = rand() % 5 + 1;
	int c = rand() % 5 + 1;
	int d = rand() % 5 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 10 + 700;	// 700 ~ 719
	int _money = rand() % 20 + 300;	// 300 ~ 329

	Talk_Mob("�ϱ� ���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("f(x) = %dx + %d ���� x = %d ���� x = %d ���� ������ ����?", a,b,c,d); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == ( a/2*(d*d - c*c) + b*(d-c) ) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(17) == 1) {
			count_Integ1++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : �ϱ� ���� ���� %d / 10 ���� ���",count_Integ1);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Integ1 >= 10) {
				Talk_System("�ϱ� ���� ���� 10������ ��� ����ߴ�!");
				Talk_Player("� ������ �̼ҿ��� ������");
				SetQuestList(17,2);
			}
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

void Fight_Integration2() {
	srand((unsigned int)time(NULL));
	int _Hp = rand() % 20 + 170;		// 170 ~ 189
	int a = (rand() % 2 + 1) * 3;
	int b = (rand() % 3 + 1) * 2;
	int c = rand() % 5 + 1;
	int d = rand() % 5 + 1;
	int e = rand() % 5 + 1;
	int answer;
	int dropPoint = rand() % 10;
	int getExp = rand() % 100 + 1000;	// 1000 ~ 1099
	int _money = rand() % 20 + 500;	// 500 ~ 519

	Talk_Mob("��� ���� ���Ͱ� ��Ÿ����!");
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("f(x) = %dx^2 + %dx + %d ���� x = %d ���� x = %d ���� ������ ����?", a,b,c,d,e); fflush(stdin);
	gotoxy(1,23); scanf("%d",&answer);
	gotoxy(1,21);
	printf("                                                                                             ");
	gotoxy(1,23);
	printf("                                                                                             ");
	if( answer == ( a/3*(e*e*e - d*d*d) + b/2*(e*e - b*b) + c*(e - d) ) || answer == MasterKey) {
		Talk_System("���� �����ƴ�!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("����ġ�� %d ȹ���Ͽ���", getExp);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnExp(getExp);
		//	
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d ������ ȹ���ߴ�", _money);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		EarnMoney(_money);
		//
		if(GetQuestList(18) == 1) {
			count_Integ2++;
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("����Ʈ : ��� ���� ���� %d / 10 ���� ���",count_Integ2);
			getche();
			gotoxy(1,21);
			printf("                                                                                             ");
			//
			if(count_Integ2 >= 10) {
				Talk_System("��� ���� ���� 10������ ��� ����ߴ�!");
				Talk_Player("� ������ �̼ҿ��� ������");
				SetQuestList(18,2);
			}
		}
	}
	else {
		Talk_System("������ �й��Ͽ���!");
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("%d %d %d",a/3*(e*e*e - d*d*d),b/2*(e*e - d*d),c*(e - d));
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
		//
		SetColor(WHITE,BLACK);
		gotoxy(1,21);
		printf("ü���� %d �޾Ҵ�", _Hp*2);
		getche();
		gotoxy(1,21);
		printf("                                                                                             ");
		SubHp(_Hp*2);
		//
	}
}

long long GetMasterKey(){return MasterKey;}