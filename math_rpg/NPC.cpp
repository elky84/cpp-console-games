#include "Library.h"

int questList[20] = {0,};

void CheckNPC(int x, int y) {
	int mapID = GetMapID();
	if(GetMapEntry(mapID, x, y-1) == NPC)
		ChatNPC(mapID,x,y-1);
	if(GetMapEntry(mapID, x, y+1) == NPC)
		ChatNPC(mapID,x,y+1);
	if(GetMapEntry(mapID, x-1, y) == NPC)
		ChatNPC(mapID,x-1,y);
	if(GetMapEntry(mapID, x+1, y) == NPC)
		ChatNPC(mapID,x+1,y);
	if(x == 1 && y == 1)	// ġƮ
		ChatNPC(mapID,x,y);
}

void Talk_NPC(char name[], char chat[]) {
	SetColor(SKY_BLUE,BLACK);
	gotoxy(1,21);
	printf("%s : %s", name, chat);
	system("pause>nul");
	gotoxy(1,21);
	printf("                                                                                             ");
	SetColor(WHITE,BLACK);
}

void Talk_Player(char chat[]) {
	SetColor(GREEN,BLACK);
	gotoxy(1,21);
	PrintMyName(); printf(" : %s", chat);
	system("pause>nul");
	gotoxy(1,21);
	printf("                                                                                             ");
	SetColor(WHITE,BLACK);
}

void Talk_System(char chat[]) {
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("�ȳ� : %s", chat);
	system("pause>nul");
	gotoxy(1,21);
	printf("                                                                                             ");
}

void Talk_Mob(char chat[]) {
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%s", chat);
	getche();
	gotoxy(1,21);
	printf("                                                                                             ");
}

void ChatNPC(int ID, int x, int y) {
	char str[50];
	int num;

	if(ID == 0) {
		if(x==5 && y==2) {
			char nameNPC[] = "����";
			switch(questList[0]) {
			case 0:
				Talk_NPC(nameNPC,"����, ��� ���� �������� ������?");
				Talk_Player("....? �������ε�?");
				Talk_NPC(nameNPC,"���� 3�� �ʿ��ѵ� ���� ������ + �����ڹۿ� ���ŵ�");
				Talk_NPC(nameNPC,"�׷��ϱ� 1�� 2�� ������ ���� ������? �Ƹ� �� ���� ��Ű���� ����� �˰ž�");
				Talk_Player("�˾Ҿ�, ���� ������ �ٰ�");
				questList[0] = 1;
				break;
		
			case 1:
				Talk_NPC(nameNPC,"1�� 2�� ���Ϸ��� �� ���� ��Ű���� ������� ��");
				Talk_Player("�� (�ٷο��� �Ǵٸ� �༮���� ������)");
				break;
		
			case 2:
				Talk_Player("��, ���� 1�� 2�� �����Ծ�");
				Talk_NPC(nameNPC,"����! ��� �ʿ��� ������ �� + �����ڸ� �ٰ�");
				Talk_Player("��... ���� (�ƽ� ������ ����)");
				Talk_System("+ �����ڸ� �����.");
				Talk_System("����ġ�� 10 ȹ���ߴ�.");
				PopItem('1');
				PopItem('2');
				PushItem('+');
				ShowState();
				questList[0] = -1;
				EarnExp(10);
				break;
			case -1:
				Talk_NPC(nameNPC,"�ȳ�. ���δ� �ߵǰ���?");
				break;		
			}
		}
		if(x==10 && y==2) {
			char nameNPC[] = "��Ű";
			switch(questList[0]) {
			case 0:
				Talk_NPC(nameNPC,"���� ������ �༮�� ���������� ���� �� ����...");
				Talk_Player("(���� �ɾ ����� ����. �׳� ���������� ����)");
				break;

			case 1:
				Talk_Player("����, Ȥ�� 1�� 2�� ���� �� ������?");
				Talk_NPC(nameNPC,"1�� 2? �װŶ�� �� �� ������... Ȥ�� ����༮�� ��Ź�̾�?");
				Talk_Player("... ����");
				Talk_NPC(nameNPC,"�˾Ҿ�, �׷� �� ���ڵ��� �༮���� ������ �ֵ��� ��");
				Talk_Player("���� (�ٽ� ó�� �༮���� ������)");
				Talk_System("���� 1�� 2�� �����.");
				PushItem('1');
				PushItem('2');
				ShowState();
				questList[0]	=	2;
				break;
		
			case 2:
				Talk_NPC(nameNPC,"� �� ���ڵ��� �༮���� ������ �ֵ��� ��");
				Talk_Player("�˾Ҿ� (� ó�� �༮���� ������)");
				break;
			case -1:
				Talk_NPC(nameNPC,"�ȳ�!!");
				Talk_Player("�� �ȳ�!!");
				break;
			}
		}
		if(x==37 && y==5) {
			char nameNPC[] = "���";
			switch(questList[1]) {
			case 0:
				if(questList[0] == -1) {
					Talk_NPC(nameNPC,"����, �ű� �ڳ�");
					Talk_Player("����?");
					Talk_NPC(nameNPC,"���� ������� '-' �� ��򰡿� ����߷Ȱŵ�...");
					Talk_NPC(nameNPC,"�׷��� �ƹ����� ���͵��� �ֿ������� �� ����...");
					Talk_NPC(nameNPC,"Ȥ�� ã���شٸ� ���� ���ϰ� ��������");
					Talk_Player("���� �׷��� ��� ã��?");
					Talk_NPC(nameNPC,"�� ���� ���� �Ʒ������� �������� ��");
					Talk_Player("���� ���� �ݹ� ã�ƿ� (�Ʒ������� ������)");
					questList[1] = 1;
				}
				else {
					Talk_NPC(nameNPC,"�ɽ��ѵ� �� ��մ� �� ��������...");
					Talk_Player("......");
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"�Ʒ������� �������� ���͵��� ���ϰž�");
				Talk_Player("���� (� �Ʒ������� ������)");
				break;
			case 2:
				Talk_Player("��, ���� '-'�� ã�ƿԾ�");
				Talk_NPC(nameNPC,"���� ����! ���� �Ҿ���� '-'�� �¾�!");
				Talk_NPC(nameNPC,"�׷� ��ʸ� ��߰���?");
				EarnExp(20); Talk_System("����ġ�� 20 ȹ���ߴ�");
				PushItem('-'); Talk_System("'-'�� ȹ���ߴ�");
				Talk_NPC(nameNPC,"�� '-'�� ��ʷ� �ʿ��� �ֵ��� ����");
				Talk_Player("�ƽ�, ���� '+'�� '-'�� ��� ������ �Ǿ���!");
				questList[1] = -1;
				ShowState();
				CheckState();
				break;
			case -1:
				if(GetLevel() < 7) {
					Talk_NPC(nameNPC,"���� 7�� �Ǹ� �׶� ã�ƿ����� ��");
					Talk_Player("����. (���� 7���� ���͸� �������)");
				}
				break;
			}
			switch(questList[2]) {
			case 0:
				if(questList[1] == -1 && GetLevel() >= 7) {
					Talk_NPC(nameNPC,"�������� '-'�� ã����� �༮�̱���!");
					Talk_Player("��, �ȳ�? (���� �� ��Ű���°� �ƴϰ���...)");
					Talk_NPC(nameNPC,"Ȥ�� �ð��ȴٸ� �Ҿ���� '*'�� ã������ ������?");
					Talk_Player("�� �װ�..... (�ϱ� ������)");
					Talk_NPC(nameNPC,"�翬�� ������ �ε��ϰ� ���״ϱ�.. ����ġ 50 ����?");
					Talk_Player("���� �ٳ���ڽ��ϴ� ^^");
					Talk_NPC(nameNPC,"���� ��. �Ƹ� ������������ ���� �������� ���������� �����ž�");
					Talk_NPC(nameNPC,"�� �αٿ��� ����߷����� �Ƹ� ���͵��� ��ٺ��� ã���� �����ž�");
					Talk_Player("���� �ݹ� �ٳ��");
					Talk_NPC(nameNPC,"�׷� ����Ұ�");
					questList[2] = 1;
				}
				break;
			case 1:
				Talk_Player("���� ����� �߾���?");
				Talk_NPC(nameNPC,"���� �Ʒ��� ������������ ���� �Ʒ������� ���� ���������� �־�");
				Talk_NPC(nameNPC,"�ű⼭ �Ҿ�������ϱ� �Ƹ� ���͵��� ������ �����ž�");
				Talk_Player("�˾Ҿ� (� ������������ ������)");
				break;
			case 2:
				Talk_Player("��, ���� '*'�� ã�ƿԾ�");
				Talk_NPC(nameNPC,"����! �翬�� ������ ����߰���?");
				Talk_System("����ġ�� 50 ȹ���ߴ�");
				EarnExp(50);
				Talk_Player("(�ƽ� ���õ� ����Ҵ�! ��)");
				Talk_NPC(nameNPC,"�׸��� �� '*'�� ������ �� �ٰ�");
				Talk_System("������ '*'�� ȹ���ߴ�");
				PushItem('*');
				ShowState();
				questList[2] = -1;
				break;
			case -1:
				if(GetLevel() < 10) {
					Talk_NPC(nameNPC,"���� 10�� �Ǹ� ã�ƿ�");
					Talk_Player("����. (���� 10�� �ɶ����� ���͸� �������)");
				}
				break;
			}
			switch(questList[3]) {
			case 0:
				if(questList[2] == -1 && GetLevel() >= 10) {
					Talk_NPC(nameNPC,"����... �̹� �ѹ��� �� �����ָ� �ȵɱ�?");
					Talk_Player("��? ������ ���� �ٻ۵�...");
					Talk_NPC(nameNPC,"�̹� ����Ʈ�� ������ ��������Ʈ�� ���״ϱ�..");
					Talk_Player("����. Ȥ�� �̹��� '/'�� ��������°ž�?");
					Talk_NPC(nameNPC,"��ġ ë�� ��. �Ƹ� ���ϱ� ���Ϳ��Լ� ���� �� �����ž�");
					Talk_Player("���� �׷� �ٳ�ð�");
					Talk_NPC(nameNPC,"���� ��. �Ƹ� ������������ �������� ���� �����ž�");
					Talk_NPC(nameNPC,"�׷� ���� ��");
					questList[3] = 1;
				}
				break;
			case 1:
				Talk_Player("�ٵ� ���� ���ߵȴٰ� ����?");
				Talk_NPC(nameNPC,"���� �Ʒ��� ������������ �������� ���� ���� ������ �־�");
				Talk_NPC(nameNPC,"�ű⼭ �Ҿ�������ϱ� �Ƹ� ���͵��� ������ �����ž�");
				Talk_Player("�˾Ҿ� (� ���� �������� ������)");
				break;
			case 2:
				Talk_Player("��, ���� '/'�� ã�ƿԾ�");
				Talk_NPC(nameNPC,"����! ��� ����ġ�� �ٰ�");
				Talk_System("����ġ�� 100 ȹ���ߴ�");
				EarnExp(100);
				Talk_Player("(���� ��Ģ������ �������ߴ�!)");
				Talk_NPC(nameNPC,"�׸��� �� '/'�� ������ �� �ٰ�");
				Talk_System("������ '/'�� ȹ���ߴ�");
				PushItem('/');
				ShowState();
				questList[3] = -1;
				break;
			case -1:
				if(GetLevel() < 15) {
					Talk_NPC(nameNPC,"���� 15�� �Ǹ� ã�ƿ�. ��������Ʈ�� �ٰ�");
					Talk_Player("����. (���� 15�� �ɶ����� ���͸� �������)");
				}
				break;
			}
			switch(questList[4]) {
			case 0:
				if(questList[3] == -1 && GetLevel() >= 15) {
					Talk_Player("� ����������!");
					Talk_NPC(nameNPC,"�˾Ҿ�. �ʹ� ���θ��� ����");
					Talk_Player("���� 15�� �Ǹ� �������� �ְڴٸ�");
					Talk_NPC(nameNPC,"����, �׷� �������� �̼��� �����ϸ� ���������ٰ�");
					Talk_Player("�̼�? �װ� ����");
					Talk_NPC(nameNPC,"ȥ�ձ����� ���� ȥ�հ�� ���͸� 5���� ����");
					Talk_Player("ȥ�հ���̶�.... �˾Ҿ� �ѹ� �غ���");
					Talk_NPC(nameNPC,"�׷� ȭ���� ��");
					questList[4] = 1;
				}
				break;
			case 1:
				Talk_Player("�ٵ� ���� ���ߵȴٰ� ����?");
				Talk_NPC(nameNPC,"���� �Ʒ��� ������������ ���������� ���� ȥ�� ������ �־�");
				Talk_NPC(nameNPC,"�ű⼭ ȥ�հ�� ���� 5������ �����");
				Talk_Player("�˾Ҿ� (� ȥ�� �������� ������)");
				break;
			case 2:
				Talk_Player("5���� ����Ҿ�!");
				Talk_NPC(nameNPC,"�����߳�! �׷� ���������ٰ�");
				Talk_System("'����'�� �����ߴ�");
				SetMyJob("����");
				Talk_Player("�ƽ�! ���� �����ߴ�");
				Talk_NPC(nameNPC,"�׸��� ������ �ణ�� ����ġ�� �ٰ�");
				Talk_System("����ġ�� 200 ȹ���ߴ�");
				EarnExp(200);
				ShowState();
				questList[4] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"�ȳ�. �� ��Ÿ�� ������?");
				break;
			}

		}
		if(x == 2 && y == 15) {
			char nameNPC[] = "����";
			if(GetHp() == GetMaxHp()) {
				Talk_NPC(nameNPC,"�̹� ü���� �����ΰ�?");
			}
			else if(GetHp() < GetMaxHp()) {
				Talk_NPC(nameNPC,"ü���� �����ϱ���, ��ٷ��� �ݹ� ä���ٰ�");
				SetHpFull();
				ShowState();
				Talk_System("ü���� ȸ���Ǿ���");
			}
		}
		if(x == 1 && y == 1) {
			Talk_System("��ɾ �Է��ϼ���");
			gotoxy(1,21); scanf("%s %d", str, &num); fflush(stdin);
			gotoxy(1,21); printf("                                             ");
			if(strcmp(str,"Level") == 0) {
				SetLevel(num);
				CheckState();
				ShowState();
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				Talk_System("���� ġƮ�� ����Ǿ����ϴ�");
			}
			else if(strcmp(str,"Name") == 0) {
				Talk_System("�̸��� �Է��ϼ���");
				gotoxy(1,21); scanf("%s",str); fflush(stdin);
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				SetName(str);
				ShowState();
				Talk_System("�̸����� ġƮ�� ����Ǿ����ϴ�");
			}
			else if(strcmp(str,"MasterKey") == 0) {
				SetMasterKey(num);
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				ShowState();
				Talk_System("������Ű�� ����Ǿ����ϴ�");
			}
			else if(strcmp(str,"Coin") == 0) {
				SetMoney(num);
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				ShowState();
				Talk_System("���� ġƮ�� ����Ǿ����ϴ�");
			}
		}
	}
	else if(ID == 5) {
		if(x == 37 && y == 11) {
			srand((unsigned int)time(NULL));
			int luck = rand() % 5 + 1;
			char nameNPC[] = "����";
			int answer, betting;
			
			Talk_NPC(nameNPC,"������ �� ���� ������� �ʾ�?");
			Talk_NPC(nameNPC,"���� ���� ������ 1~5 ���� ���ڸ� ���߸� �� ���� 3�踦 �ٰ�");
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("�׷� �󸶸� �ɷ�?");
			gotoxy(1,23); scanf("%d",&betting); fflush(stdin);
			gotoxy(1,21);
			printf("                                                                                             ");
			gotoxy(1,23);
			printf("                                                                                             ");
			//
			if(GetMoney() < betting) {
				Talk_NPC(nameNPC,"�̾������� �ڳװ� ���� ���κ��� ū���� �� �� ����");
			}
			else {
				EarnMoney((-1)*betting);
				//
				SetColor(WHITE,BLACK);
				gotoxy(1,21);
				printf("���� ������ ���ڴ� �p�ϱ�? (1~5 ����)");
				gotoxy(1,23); scanf("%d",&answer); fflush(stdin);
				gotoxy(1,21);
				printf("                                                                                             ");
				gotoxy(1,23);
				printf("                                                                                             ");
				//
				if(answer == luck || answer == GetMasterKey()) {
					EarnMoney(betting*3);
					Talk_NPC(nameNPC,"����! �� ���� 3�踦 �����ٰ�");
				}
				else {
					Talk_NPC(nameNPC,"��! ���� ��ȸ�� �����غ�");
					//
					SetColor(WHITE,BLACK);
					gotoxy(1,21);
					printf("����� ���� ������ ���ڴ� %d �̿���!",luck);
					getche();
					gotoxy(1,21);
					printf("                                                                                             ");
					gotoxy(1,23);
					printf("                                                                                             ");
					//
				}
			}
		}
		if(x == 11 && y == 2) {
			char nameNPC[] = "�ҿ�";
			switch(questList[5]) {
			case 0:
				if(GetLevel() < 20 || questList[4] != -1) {
					Talk_NPC(nameNPC,"���� 20�� �Ǹ� ������ �� ���� �ʵ�� ����Ʈ�� �� ���� �;���");
					Talk_Player("(���� 20���� ��Ģ���� �������� ����� ����)");
				}
				else {
					Talk_NPC(nameNPC,"����, �ð��� ������ ���� �������� ������?");
					Talk_Player("�������ε� �׷�?");
					Talk_NPC(nameNPC,"�����տ� ���͵��� �ʹ� ���Ƽ� ���ʸ� ã���� ������ ����");
					Talk_NPC(nameNPC,"���� �Ʒ��ʿ� ������ ���͸� 10������ ����ٷ�?");
					Talk_Player("�ٵ� �� ���� ������ ����� �� �� �𸣴°�");
					Talk_NPC(nameNPC,"�׷� �̰� ������, ������ �ɰž�");
					PushItem('f');
					Talk_System("������ 'f'�� ȹ���ߴ�");
					Talk_Player("�˾Ҿ�, �ݹ� �ٳ�ð�");
					questList[5] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"������ ���͸� 10������ �����");
				Talk_NPC(nameNPC,"������ ���ʹ� ���� �Ʒ� ������ �������� �����־�");
				break;
			case 2:
				Talk_Player("������ ���� 10����, ��� ��ƿԾ�");
				Talk_NPC(nameNPC,"����! ���п� �ٽ� ���ʸ� ã���� �� �� �ְԉ��");
				Talk_NPC(nameNPC,"�̰� �� ������ ǥ�þ�");
				Talk_System("����ġ�� 400 ȹ���ߴ�");
				EarnExp(400);
				Talk_Player("�׷� ������ ��");
				questList[5] = -1;
				break;
			case -1:
				if(GetLevel() < 23) {
					Talk_NPC(nameNPC,"���� 23�� �Ǹ� �׶� ������ ��");
					Talk_Player("(���� 23�� �Ǹ� �ٽÿ���)");
				}
				break;
			}
			switch(questList[7]) {
			case 0:
				if(questList[5] == -1 && GetLevel() >= 23) {
					Talk_NPC(nameNPC,"���� �������� ������?");
					Talk_Player("����?");
					Talk_NPC(nameNPC,"������ ������ ���͵��� ���ʸ� ���� �Ծ������ �־�");
					Talk_NPC(nameNPC,"���� ������ ���� �Ʒ��ʿ� ������ ���͸� 10������ ����ٷ�?");
					Talk_Player("����. �ݹ� �ٳ�ð�");
					questList[7] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"������ ���͸� 10������ �����");
				Talk_NPC(nameNPC,"������ ���ʹ� ������ ���� �Ʒ� ������ �������� �����־�");
				break;
			case 2:
				Talk_Player("������ ���� 10������ ��� ������� ���� ���������ž�");
				Talk_NPC(nameNPC,"����! ���п� �ٽ� ���ʰ� �ڶ� �� �ְԉ��");
				Talk_NPC(nameNPC,"������ ǥ�÷� �̰� �ٰ�");
				Talk_System("����ġ�� 400 ȹ���ߴ�");
				EarnExp(400);
				Talk_Player("�׷� �� ������ ��");
				questList[7] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"�ȳ�. ���õ��� �ȶ��� ���̳�");
				break;
			}
		}
		if(x == 17 && y == 2) {
			char nameNPC[] = "����";
			switch(questList[6]) {
			case 0:
				if(GetLevel() < 20 || questList[4] != -1) {
					Talk_NPC(nameNPC,"���� 20�� �Ǹ� ������ �� ���� �ʵ�� ����Ʈ�� �� ���� �;���");
					Talk_Player("(���� 20���� ��Ģ���� �������� ����� ����)");
				}
				else {
					Talk_NPC(nameNPC,"����, ���� �������� �ʰھ�?");
					Talk_Player("�������ε�?");
					Talk_NPC(nameNPC,"�ҿ�� ���� �����տ� ���ʸ� ã���� ���ٰ�...");
					Talk_NPC(nameNPC,"�׸� ���ʹٱ��ϸ� �ΰ���� ����?");
					Talk_Player("�׷�����, �׷� ���� ã�ƴ� �ٰ�");
					Talk_NPC(nameNPC,"����, �Ƹ� �����Ʒ��� ������ ���͸� ��ٺ��� ã�� �� �����ž�");
					questList[6] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"������ ���͸� ��� ���ʹٱ��ϸ� ã����");
				Talk_NPC(nameNPC,"������ ���ʹ� ���� �Ʒ� ������ �������� �����־�");
				break;
			case 2:
				Talk_Player("�� �ٱ��ϰ� ����?");
				Talk_NPC(nameNPC,"�¾�! ã���༭ ���� ����");
				Talk_NPC(nameNPC,"�̰� �� ������ ǥ�þ�");
				Talk_System("����ġ�� 500 ȹ���ߴ�");
				EarnExp(500);
				Talk_Player("�׷� ���߿� ��");
				questList[6] = -1;
				break;
			case -1:
				if(GetLevel() < 23) {
					Talk_NPC(nameNPC,"���� 23�� �Ǹ� �׶� ������ ��");
					Talk_Player("(���� 23�� �Ǹ� �ٽÿ���)");
				}
				break;
			}
			switch(questList[8]) {
			case 0:
				if(questList[6] == -1 && GetLevel() >= 23) {
					Talk_NPC(nameNPC,"���� �������� ������?");
					Talk_Player("����?");
					Talk_NPC(nameNPC,"������ ������ ���͵��� ���� ���� ���� ������� ��°�� ���ѹ��Ⱦ�");
					Talk_NPC(nameNPC,"���� ������ ���� �Ʒ��ʿ� ������ ���͵鿡�Լ� ��ã�ƿ����� ������?");
					Talk_Player("�˾Ҿ�, ���� ã���ٰ�");
					questList[8] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"������ ���͸� ��� ���� ������� ã����");
				Talk_NPC(nameNPC,"������ ���ʹ� ������ ���� �Ʒ� ������ �������� �����־�");
				break;
			case 2:
				Talk_Player("��, ���� ���� ������� ��ã�ƿԾ�");
				Talk_NPC(nameNPC,"����! ���п� �ٽ� ������ ������ �� �ְ� �Ǿ���");
				Talk_NPC(nameNPC,"������ ǥ�÷� �̰� �ٰ�");
				Talk_System("������ 'P'�� ȹ���ߴ�");
				PushItem('P');
				Talk_System("����ġ�� 400 ȹ���ߴ�");
				EarnExp(400);
				SetMyJob("������");
				Talk_System("'������'�� �����ߴ�!");
				Talk_Player("��! ����!!");
				questList[8] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"�ȳ�. ���õ��� �ȶ��� ���̳�");
				break;
			}
		}
		if(x == 2 && y == 14) {
			char nameNPC[] = "����";
			if(GetHp() == GetMaxHp()) {
				Talk_NPC(nameNPC,"�̹� ü���� �����ΰ�?");
			}
			else if(GetHp() < GetMaxHp()) {
				Talk_NPC(nameNPC,"ü���� �����ϱ���, ��ٷ��� �ݹ� ä���ٰ�");
				SetHpFull();
				ShowState();
				Talk_System("ü���� ȸ���Ǿ���");
			}
		}
	}
	else if(ID == 8) {
		if(x == 2 && y == 6) {
			char nameNPC[] = "�̼�";
			switch(questList[17]) {
			case 0:
				if(GetLevel() < 35 || questList[16] != -1) {
					Talk_NPC(nameNPC,"���� 35�� �Ǹ� �ٽÿ�! �ٺ� �װڴµ� ���� ������ ����");
					Talk_Player("......(���� 35�� �Ǹ� �ٽÿ���)");
				}
				else {
					Talk_NPC(nameNPC,"��.. ¥����... �� �����ٷ�?");
					Talk_Player("....�������ε�?");
					Talk_NPC(nameNPC,"�� ���� ���͵鶧���� ¥������ ������ �ȵ�");
					Talk_NPC(nameNPC,"���� �ϱ� ���� ���͸� �� 10���� ������ ������� ���ٷ�?");
					Talk_Player("��.... �˾Ҿ�");
					questList[17] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"�ϱ� ���� ���� 10������ �����");
				Talk_NPC(nameNPC,"�ϱ� ���� ���ʹ� ���� ���� ���� ���� 1 ���� �����־�");
				break;
			case 2:
				Talk_Player("���� ������ ����?");
				Talk_NPC(nameNPC,"�� ���п�");
				Talk_NPC(nameNPC,"�׷��� ���������� ������ ��߰ڳ�");
				Talk_System("����ġ�� 5000 ȹ���ߴ�");
				EarnExp(5000);
				Talk_NPC(nameNPC,"�޾����� ���� �� �� �ٻڴϱ�");
				questList[17] = -1;
				break;
			case -1:
				if(GetLevel() < 38) {
					Talk_NPC(nameNPC,"���� 38�� �Ǹ� �ٽÿ�.");
					Talk_Player("(���� 38�� �Ǹ� �ٽÿ���)");
				}
				break;
			}
			switch(questList[18]) {
			case 0:
				if(GetLevel() >= 38) {
					Talk_NPC(nameNPC,"��Ű���� ������.. �ѹ��� �� ������");
					Talk_Player("....�̹��� �� �������ε�?");
					Talk_NPC(nameNPC,"���� ���͵��� ���ٸ鼭 �̰� ���� �����ش�� �־�;;");
					Talk_NPC(nameNPC,"���� ��� ���� ���� 10������ �����");
					Talk_Player("�� �׷����̶�� �����ֵ��� �ұ�");
					Talk_NPC(nameNPC,"�׷� ���� ���ٿ� �༮�� ������ ������ �Ҽ��� ���ŵ�");
					questList[18] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"��� ���� ���� 10������ �����");
				Talk_NPC(nameNPC,"��� ���� ���ʹ� ���� ���� 1 ���� ���� ���� 2 ���� �����־�");
				break;
			case 2:
				Talk_Player("�������� ����?");
				Talk_NPC(nameNPC,"�� �׷���");
				Talk_NPC(nameNPC,"�̰� �� �׳� ���� ������� �����ϰ� �޾�");
				Talk_System("����ġ�� 8000 ȹ���ߴ�");
				EarnExp(8000);
				Talk_System("'������'�� �����ߴ�!");
				SetMyJob("������");
				Talk_NPC(nameNPC,".... ������ �� ���..");
				questList[18] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"��..������ �ٻڴϱ�! ������ ��!");
				break;
			}
		}
		if(x == 37 && y == 4) {
			char nameNPC[] = "����";
			switch(questList[9]) {
				case 0:
					if(GetLevel() < 25 || questList[8] != -1) {
						Talk_NPC(nameNPC,"������ �ٻڴϱ� ���� 25�� �Ǹ� �׋� ��!! �翬�� �ߵ���� Ŭ���� ����?");
						Talk_Player("...(������ �ٻ� �� ����)");
					}
					else if(GetLevel() >= 25) {
						Talk_NPC(nameNPC,"���� ���ѵ� ���� ������");
						Talk_Player("�������� �׷��µ�?");
						Talk_NPC(nameNPC,"�Ǽ��� ���� ���� ������ ���� ��ó���� �Ҿ���Ȱŵ�");
						Talk_NPC(nameNPC,"�Ƹ� ���� �������� ����߸� �� ������ �� ã���ٷ�?");
						Talk_Player("���� �ݹ� ã�ƿð�, ��ٷ�");
						questList[9] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"���� ���͸� ��� ���� ������ ã����");
				Talk_NPC(nameNPC,"���� ���ʹ� ���� ������ ���� �������� �����־�");
				break;
			case 2:
				Talk_Player("��, �� ���� ������ �ϲ� ����?");
				Talk_NPC(nameNPC,"����! ���п� �ٽ� ������ ������ �� �ְ� �Ǿ���");
				Talk_NPC(nameNPC,"���� �ƴ����� ������ �ٰ�");
				Talk_System("����ġ�� 600 ȹ���ߴ�");
				EarnExp(600);
				Talk_Player("�׷� �� ������ ��");
				questList[9] = -1;
				break;
			case -1:
				if(GetLevel() < 28) {
						Talk_NPC(nameNPC,"������ �ٻڴϱ� ���� 28�� �Ǹ� �׋� ��");
						Talk_Player("...(�׻� �ٻ� �� ���ƺ��δ�)");
					}
				break;
			}
			switch(questList[10]) {
				case 0:
					if(questList[9] == -1 && GetLevel() >= 28) {
						Talk_NPC(nameNPC,"���� ���ѵ� ���� ������");
						Talk_Player("�̹��� �� �������� �׷��µ�?");
						Talk_NPC(nameNPC,"������ ã���� ���� �������� �Ϻκ��� �����Ǿ� �־�");
						Talk_NPC(nameNPC,"�̰� �Ƹ� �ߺ� ���� ���͵��� ���� ����. �̿� �ϴ°� ������ ã����");
						Talk_Player("����,, ���� �ݹ� ã�ƿð�");
						questList[10] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"�ߺ� ���� ���͸� ��� ������ ���� ������ ã����");
				Talk_NPC(nameNPC,"�ߺ� ���� ���ʹ� ���� ���� ���� �ߺ� ���� �������� �����־�");
				break;
			case 2:
				Talk_Player("��, �� ������ ���� ������ �ϲ� ����?");
				Talk_NPC(nameNPC,"����! ���п� �ٽ� ������ ������ �� �ְ� �Ǿ���");
				Talk_NPC(nameNPC,"���� �ƴ����� ������ �ٰ�");
				Talk_System("����ġ�� 1000 ȹ���ߴ�");
				EarnExp(1000);
				Talk_Player("�׷� �� ������ ��");
				questList[10] = -1;
				break;
			case -1:
					Talk_NPC(nameNPC,"�ٻ۵� ���� �׸� ����?");
				break;
			}
		}
		if(x == 37 && y == 13) {
			char nameNPC[] = "����";
			switch(questList[11]) {
				case 0:
					if(GetLevel() < 25 || questList[8] != -1) {
						Talk_NPC(nameNPC,"Zzzzzz.... ���� ����");
						Talk_Player("...(���� 25�� �Ǹ� �׶� �������� ���� ������ �ߵ���� Ŭ���� �ؾ��Ѵ�)");
					}
					else if(GetLevel() >= 25) {
						Talk_NPC(nameNPC,"��? ���� ���� �������~");
						Talk_Player("��? �������ε�");
						Talk_NPC(nameNPC,"�Ѽ� �ڰ� �������� ��⸦ ���͵��� ���� �Ծ������ ����");
						Talk_NPC(nameNPC,"���� ���� 20 ������ ȥ����!");
						Talk_Player("�� ��Ű���� ������... �׷��� �Ұ�");
						Talk_NPC(nameNPC,"�׸��� Ȥ�� �𸣴� �̰� ���������� ��");
						Talk_System("������ 'C'�� ȹ���ߴ�");
						PushItem('C');
						questList[11] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"���� ���� 20������ �����");
				Talk_NPC(nameNPC,"���� ���ʹ� ���� ���� ������ ���� �������� �����־�");
				break;
			case 2:
				Talk_Player("��, �������� �������?");
				Talk_NPC(nameNPC,"����, ����... �׷� �� �ٽ� �߰�.. ���� ����..");
				Talk_NPC(nameNPC,"zzz...��������...�̰�...�ٰ�....Zzzzz");
				Talk_System("����ġ�� 600 ȹ���ߴ�");
				EarnExp(600);
				Talk_Player("�׷� �� ������ ��");
				questList[11] = -1;
				break;
			case -1:
				if(GetLevel() < 28) {
						Talk_NPC(nameNPC,"�帣��...�����... Zzzz");
						Talk_Player("...(���ϰ� ���� ����. ���� 28�� �Ǹ� ��������)");
					}
				break;
			}
			switch(questList[12]) {
				case 0:
					if(questList[11] == -1 && GetLevel() >= 28) {
						Talk_NPC(nameNPC,"��! ������ �׳༮ �̱���");
						Talk_Player("�̹��� �� �������� �׷��µ�?");
						Talk_NPC(nameNPC,"���͵� ������ �ò������� ���� �߼��� ����");
						Talk_NPC(nameNPC,"�ߺ� ���� ���� 20 ������ ��ġ������ ������?");
						Talk_Player("�˾Ҿ�...");
						questList[12] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"�ߺ� ���� ���� 20������ �����");
				Talk_NPC(nameNPC,"�ߺ� ���� ���ʹ� ���� ���� ���� �ߺ� ���� �������� �����־�");
				break;
			case 2:
				Talk_Player("�� ��Ҿ�, ���� ������ �� �� �ְ���?");
				Talk_NPC(nameNPC,"Zzzzzzzzz.....");
				Talk_Player("����...?");
				Talk_NPC(nameNPC,"��! �´� ����... �����־�.... Zzzzz...");
				Talk_System("����ġ�� 1000 ȹ���ߴ�");
				EarnExp(1000);
				SetMyJob("�Ǽ�");
				Talk_System("'�Ǽ�'�� �����ߴ�!");
				Talk_Player("���鼭 ���������ִٴ�... ���� �����ϱ� ������...");
				questList[12] = -1;
				break;
			case -1:
					Talk_NPC(nameNPC,"Zzzzzzzzz......");
				break;
			}
		}
		if(x == 2 && y == 14) {
			char nameNPC[] = "����";
			if(GetHp() == GetMaxHp()) {
				Talk_NPC(nameNPC,"�̹� ü���� �����ΰ�?");
			}
			else if(GetHp() < GetMaxHp()) {
				Talk_NPC(nameNPC,"ü���� �����ϱ���, ��ٷ��� �ݹ� ä���ٰ�");
				SetHpFull();
				ShowState();
				Talk_System("ü���� ȸ���Ǿ���");
			}
		}
		if(x == 9 && y == 2) {
			char nameNPC[] = "����";
			switch(questList[13]) {
			case 0:
				if(GetLevel() < 30 || questList[12] != -1) {
					Talk_NPC(nameNPC,"���� 30�� �Ǹ� �ٽÿ�. ���� ������ ����� ������ ����Ʈ�� Ŭ���� �߰���? ����");
					Talk_Player("(���� 30�� �Ǹ� �ٽÿ���)");
				}
				else {
					Talk_NPC(nameNPC,"�ð� ������ ���� �����ٷ�?");
					Talk_Player("�������ε�?");
					Talk_NPC(nameNPC,"���� �̺� ������ ���ƴٴϴٰ� �����⸦ �Ҿ���Ȱŵ�");
					Talk_NPC(nameNPC,"�ϱ� �̺� ���͸� ��� �����⸦ ã�ƿ���");
					Talk_Player("����, ���� ������ �ٰ�");
					Talk_NPC(nameNPC,"�׸��� Ȥ�� �𸣴� �̰� ���������� ��");
					Talk_System("������ 'd'�� ȹ���ߴ�");
					PushItem('d');
					questList[13] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"�ϱ� �̺� ���͸� ��� �����⸦ ��ã����");
				Talk_NPC(nameNPC,"�ϱ� �̺� ���ʹ� ���� ���� �̺� ���� 1 ���� �����־�");
				break;
			case 2:
				Talk_Player("�� �����Ⱑ �ϲ� ����?");
				Talk_NPC(nameNPC,"��! ���� ã���ᱸ��");
				Talk_NPC(nameNPC,"��� ������ �̰� �ٰ�");
				Talk_System("����ġ�� 2000 ȹ���ߴ�");
				EarnExp(2000);
				Talk_Player("�׷� �ȳ�~");
				questList[13] = -1;
				break;
			case -1:
				if(GetLevel() < 33) {
					Talk_NPC(nameNPC,"���� 33�� �Ǹ� �ٽÿ�.");
					Talk_Player("(���� 33�� �Ǹ� �ٽÿ���)");
				}
				break;
			}
			switch(questList[14]) {
			case 0:
				if(GetLevel() >= 33) {
					Talk_NPC(nameNPC,"����, �ѹ��� �� �������� ������?");
					Talk_Player("�̹��� �������ε�?");
					Talk_NPC(nameNPC,"�����⿡ ����ִ� �ʸ��� ��� �������");
					Talk_NPC(nameNPC,"�ƹ����� �Ҿ������ �� ���͵��� ������������ ����");
					Talk_NPC(nameNPC,"��� �̺� ���͸� ��� ���� �ʸ��� ã�ƿ���");
					Talk_Player("����, �����ֵ��� ����");
					Talk_NPC(nameNPC,"�׷� ��Ź��~");
					questList[14] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"��� �̺� ���͸� ��� ���� �ʸ��� ��ã����");
				Talk_NPC(nameNPC,"��� �̺� ���ʹ� �̺� ���� 1 ���� �̺� ���� 2 ���� �����־�");
				break;
			case 2:
				Talk_Player("�� ���� �ʸ� ����?");
				Talk_NPC(nameNPC,"��! ���� ã���ᱸ��");
				Talk_NPC(nameNPC,"��� ������ �̰� �ٰ�");
				Talk_System("����ġ�� 4000 ȹ���ߴ�");
				EarnExp(4000);
				Talk_System("������ 's'�� ȹ���ߴ�");
				PushItem('s');
				Talk_Player("�׷� �ȳ�~");
				questList[14] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"�������� ������~");
				break;
			}
		}
		if(x == 24 && y == 2) {
			char nameNPC[] = "�ļ�";
			switch(questList[15]) {
			case 0:
				if(GetLevel() < 30 || questList[12] != -1) {
					Talk_NPC(nameNPC,"���� 30�� �Ǹ� �ٽÿ�. ���� ������ ����� ������ ����Ʈ�� Ŭ���� �߰���?");
					Talk_Player("(���� 30�� �Ǹ� �ٽÿ���)");
				}
				else {
					Talk_NPC(nameNPC,"�ð� ������ ���� �����ٷ�?");
					Talk_Player("�������ε�?");
					Talk_NPC(nameNPC,"������ �̺� ���͵� ������ �׸� �׸��µ� ������ �ȵ�");
					Talk_NPC(nameNPC,"�ϱ� �̺� ���� 10������ �����");
					Talk_Player("�˾Ҿ�, �ݹ� �ٳ����");
					questList[15] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"�ϱ� �̺� ���� 10������ �����");
				Talk_NPC(nameNPC,"�ϱ� �̺� ���ʹ� ���� ���� �̺� ���� 1 ���� �����־�");
				break;
			case 2:
				Talk_Player("���� ������ ����?");
				Talk_NPC(nameNPC,"����! ���п� �ٽ� �׸��� �׸� �� �ְڴ�");
				Talk_NPC(nameNPC,"�̰� ���� �ִ� �����̾�");
				Talk_System("����ġ�� 2000 ȹ���ߴ�");
				EarnExp(2000);
				Talk_Player("�׷� �ȳ�~");
				questList[15] = -1;
				break;
			case -1:
				if(GetLevel() < 33) {
					Talk_NPC(nameNPC,"���� 33�� �Ǹ� �ٽÿ�.");
					Talk_Player("(���� 33�� �Ǹ� �ٽÿ���)");
				}
				break;
			}
			switch(questList[16]) {
			case 0:
				if(GetLevel() >= 33) {
					Talk_NPC(nameNPC,"�̾��ѵ� �ѹ��� �� ������");
					Talk_Player("�̹��� �� �������ε�?");
					Talk_NPC(nameNPC,"�̺� ���͵��� ���� �׸� �׸��� ���� �̺��ع��Ⱦ�...�Ѥ�");
					Talk_NPC(nameNPC,"�ƹ����� ��ã�°� �Ұ����̰� ��� �༮���� ȥ������");
					Talk_NPC(nameNPC,"��� �̺� ���� 10������ �����");
					Talk_Player("����, �����ֵ��� ����");
					Talk_NPC(nameNPC,"�׷� ��Ź��~");
					questList[16] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"��� �̺� ���� 10������ �����");
				Talk_NPC(nameNPC,"��� �̺� ���ʹ� �̺� ���� 1 ���� �̺� ���� 2 ���� �����־�");
				break;
			case 2:
				Talk_Player("�������� ����?");
				Talk_NPC(nameNPC,"��! ����");
				Talk_NPC(nameNPC,"�̰� �׵��� �����Ѱſ� ���� �����̾�");
				Talk_System("����ġ�� 4000 ȹ���ߴ�");
				EarnExp(4000);
				Talk_System("'���Ҽ�'�� �����ߴ�!");
				SetMyJob("���Ҽ�");
				Talk_Player("�������! �����ߴ�!! ����!");
				questList[16] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"#@)#($&!(*&@$)(#$");
				Talk_Player("���༮�� �׻� �̻��� ���� �ϳ�....");
				break;
			}
		}
	}
}

int GetQuestList(int n) {
	return questList[n];
}

void SetQuestList(int n, int entry) {
	questList[n] = entry;
}