#include "Library.h"

Player Me;

void MovePlayer() {
	int x = Me.GetX();
	int y = Me.GetY();
	int MapID = GetMapID();

	SetColor(BLACK,BLACK);
	gotoxy(0,25);
	char ch = getche();
	gotoxy(0,25);
	printf("  ");

	Me.SetBeforeX(x);
	Me.SetBeforeY(y);

	switch(ch) {
	case UP:
		if(y > 1) {
			if(GetMapEntry(MapID,x,y-1) < 5) {
				Me.SetY(y-1);
			}
		}
		else if(MapID == 1) {
			SetMapID(0);
			Me.SetY(18);
			DrawMap();
		}
		else if(MapID == 2) {
			SetMapID(1);
			Me.SetY(18);
			ClearMonster(1,MONSTER);
			MakeMob(1,20);
			DrawMap();
		}
		else if(MapID == 6) {
			SetMapID(5);
			Me.SetY(18);
			DrawMap();
		}
		else if(MapID == 7) {
			SetMapID(6);
			Me.SetY(18);
			ClearMonster(6,MONSTER);
			MakeMob(6,20);
			DrawMap();
		}
		else if(MapID == 5) {
			SetMapID(8);
			Me.SetY(18);
			DrawMap();
		}
		else if(MapID == 9) {
			SetMapID(11);
			Me.SetY(18);
			ClearMonster(11,MONSTER);
			MakeMob(11,20);
			DrawMap();
		}
		else if(MapID == 10) {
			SetMapID(12);
			Me.SetY(18);
			ClearMonster(12,MONSTER);
			MakeMob(12,20);
			DrawMap();
		}
		else if(MapID == 8) {
			SetMapID(13);
			Me.SetY(18);
			ClearMonster(13,MONSTER);
			MakeMob(13,20);
			DrawMap();
		}
		else if(MapID == 13) {
			SetMapID(14);
			Me.SetY(18);
			ClearMonster(14,MONSTER);
			MakeMob(14,20);
			DrawMap();
		}
		break;
	case DOWN:
		if(y < 18) {
			if(GetMapEntry(MapID,x,y+1) < 5) {
				Me.SetY(y+1);
			}
		}
		else if(MapID == 0) {
			SetMapID(1);
			Me.SetY(1);
			ClearMonster(1,MONSTER);
			MakeMob(1,20);
			DrawMap();
		}
		else if(MapID == 1) {
			SetMapID(2);
			Me.SetY(1);
			ClearMonster(2,MONSTER);
			MakeMob(2,20);
			DrawMap();
		}
		else if(MapID == 5) {
			SetMapID(6);
			Me.SetY(1);
			ClearMonster(6,MONSTER);
			MakeMob(6,20);
			DrawMap();
		}
		else if(MapID == 6) {
			SetMapID(7);
			Me.SetY(1);
			ClearMonster(7,MONSTER);
			MakeMob(7,20);
			DrawMap();
		}
		else if(MapID == 8) {
			SetMapID(5);
			Me.SetY(1);
			DrawMap();
		}
		else if(MapID == 11) {
			SetMapID(9);
			Me.SetY(1);
			ClearMonster(9,MONSTER);
			MakeMob(9,20);
			DrawMap();
		}
		else if(MapID == 12) {
			SetMapID(10);
			Me.SetY(1);
			ClearMonster(10,MONSTER);
			MakeMob(10,20);
			DrawMap();
		}
		else if(MapID == 13) {
			SetMapID(8);
			Me.SetY(1);
			DrawMap();
		}
		else if(MapID == 14) {
			SetMapID(13);
			Me.SetY(1);
			ClearMonster(13,MONSTER);
			MakeMob(13,20);
			DrawMap();
		}
		break;
	case LEFT:
		if(x > 1) {
			if(GetMapEntry(MapID,x-1,y)< 5) {
				Me.SetX(x-1);
			}
		}
		else if(MapID == 1) {
			SetMapID(3);
			Me.SetX(38);
			ClearMonster(3,MONSTER);
			MakeMob(3,20);
			DrawMap();
		}
		else if(MapID == 4) {
			SetMapID(1);
			Me.SetX(38);
			ClearMonster(1,MONSTER);
			MakeMob(1,20);
			DrawMap();
		}
		else if(MapID == 5) {
			SetMapID(0);
			Me.SetX(38);
			DrawMap();
		}
		else if(MapID == 9) {
			SetMapID(8);
			Me.SetX(38);
			DrawMap();
		}
		else if(MapID == 10) {
			SetMapID(9);
			Me.SetX(38);
			ClearMonster(9,MONSTER);
			MakeMob(9,20);
			DrawMap();
		}
		else if(MapID == 8) {
			SetMapID(15);
			Me.SetX(38);
			ClearMonster(15,MONSTER);
			MakeMob(15,20);
			DrawMap();
		}
		else if(MapID == 15) {
			SetMapID(16);
			Me.SetX(38);
			ClearMonster(16,MONSTER);
			MakeMob(16,20);
			DrawMap();
		}
		break;
	case RIGHT:
		if(x < 38) {
			if(GetMapEntry(MapID,x+1,y) < 5) {
				Me.SetX(x+1);
			}
		}
		else if(MapID == 1) {
			SetMapID(4);
			Me.SetX(1);
			ClearMonster(4,MONSTER);
			MakeMob(4,20);
			DrawMap();
		}
		else if(MapID == 3) {
			SetMapID(1);
			Me.SetX(1);
			ClearMonster(1,MONSTER);
			MakeMob(1,20);
			DrawMap();
		}
		else if(MapID == 0 ) {
			SetMapID(5);
			Me.SetX(1);
			DrawMap();
		}
		else if(MapID == 15 ) {
			SetMapID(8);
			Me.SetX(1);
			DrawMap();
		}
		else if(MapID == 16) {
			SetMapID(15);
			Me.SetX(1);
			ClearMonster(15,MONSTER);
			MakeMob(15,20);
			DrawMap();
		}
		else if(MapID == 9) {
			SetMapID(10);
			Me.SetX(1);
			ClearMonster(10,MONSTER);
			MakeMob(10,20);
			DrawMap();
		}
		else if(MapID == 8) {
			SetMapID(9);
			Me.SetX(1);
			ClearMonster(9,MONSTER);
			MakeMob(9,20);
			DrawMap();
		}
		break;
	case SPACE:
		CheckNPC(x,y);
		CheckMob(MapID,x,y);
		break;
	case ESC:
		ShowMenuESC();
		break;
	default:
		break;
	}
	Me.ErasePlayer();
	Me.DrawPlayer();
}

void SetCharName(char _name[]) {
	Me.SetName(_name);
}

void ShowState() {
	SetColor(SKY_BLUE,BLACK);
	gotoxy(82,3);	printf("이름 : "); Me.PrintName(); printf("            ");
	gotoxy(82,5);	printf("직업 : "); Me.PrintJob(); printf("            ");
	gotoxy(82,7);	printf("레벨 : %d  ",Me.GetLevel());
	gotoxy(82,9);	printf("체력 : %.0f / %.0f  ",Me.GetHp(),Me.GetMaxHp());
	gotoxy(82,11);	printf("경험치 : %.0f / %.0f  ",Me.GetExp(),Me.GetMaxExp());
	gotoxy(82,13);	printf("보유 아이템 : ");
	gotoxy(82,15);	printf("%c   %c   %c   %c   %c",GetItemEntry(0), GetItemEntry(1), GetItemEntry(2), GetItemEntry(3), GetItemEntry(4));
	gotoxy(82,17);	printf("%c   %c   %c   %c   %c",GetItemEntry(5), GetItemEntry(6), GetItemEntry(7), GetItemEntry(8), GetItemEntry(9));
	gotoxy(82,19);	printf("코인 : %.0f", Me.GetMoney());
}

void EarnExp(double n) {
	Me.SetExp(n);
	Me.CheckState();
	ShowState();
}

void PrintMyName() {
	Me.PrintName();
}

void SubHp(double n) {
	Me.SubHp(n);
	Me.CheckState();
	ShowState();
}

void Load() {
	FILE* fp = fopen("C:\\MathRPG\\account.bin","rb");
	Player Me1;
	int readCount;

	int X, Y;
	int BeforeX, BeforeY;
	int lastblock;
	char name[20];
	double MaxHp;
	double Hp;
	double MaxExp;
	double Exp;
	double money;
	int Level;
	char Job[20];

	if(fp == NULL) {
		printf("\n파일을 불러오는 도중 에러가 발생하였습니다.\n");
		printf("파일을 저장하는 도중 에러가 발생하였습니다.\n\n");
		printf("C:\\MathRPG\\account.bin 파일이 존재하지 않거나 손상되었습니다.");
		getch();
		exit(-1);
	}

	readCount = fread((void*)&Me1,sizeof(Me1),1,fp);

	X = Me1.GetX(); Y = Me1.GetY();
	BeforeX = Me1.GetBeforeX(); BeforeY = Me1.GetBeforeY();
	lastblock = Me1.GetLastblock();
	strcpy(name,Me1.GetName());
	MaxHp = Me1.GetMaxHp();
	MaxExp = Me1.GetMaxExp();
	Hp = Me1.GetHp();
	Exp = Me1.GetExp();
	Level = Me1.GetLevel();
	money = Me1.GetMoney();
	strcpy(Job,Me1.GetJob());

	Me.SetX(X); Me.SetY(Y);
	Me.SetBeforeX(BeforeX); Me.SetBeforeY(BeforeY);
	Me.SetLastblock(lastblock);
	Me.SetName(name);
	Me.SetMaxHp(MaxHp);
	Me.SetMaxExp(MaxExp);
	Me.SetHp(Hp);
	Me.SetExp(Exp);
	Me.SetLevel(Level);
	Me.SetMoney(money);
	Me.SetMyJob(Job);
	for(int i = 0; i < 10; i++) {
		PushItem(Me1.GetItemList(i));
	}
	for(int i = 0; i < 20; i++) {
		SetQuestList(i,Me1.GetQuestList(i));
	}
}

void Save() {
	FILE* fp = fopen("C:\\MathRPG\\account.bin","wb");
	Player Me1;
	int readCount;

	if(fp == NULL) {
		system("cls");
		printf("파일을 저장하는 도중 에러가 발생하였습니다.\n\n");
		printf("C:\\MathRPG\\account.bin 파일이 존재하지 않거나 손상되었습니다.");
		getch();
		exit(-1);
	}

	Me1.SetX(Me.GetX()); Me.SetY(Me.GetY());
	Me1.SetBeforeX(Me.GetBeforeX()); Me.SetBeforeY(Me.GetBeforeY());
	Me1.SetLastblock(Me.GetLastblock());
	Me1.SetName(Me.GetName());
	Me1.SetMaxHp(Me.GetMaxHp());
	Me1.SetMaxExp(Me.GetMaxExp());
	Me1.SetHp(Me.GetHp());
	Me1.SetExp(Me.GetExp());
	Me1.SetLevel(Me.GetLevel());
	Me1.SetMyJob(Me.GetJob());
	Me1.SetMoney(Me.GetMoney());
	for(int i = 0; i < 10; i++) {
		Me1.SetItemList(i,GetItemEntry(i));
	}
	for(int i = 0; i < 20; i++) {
		Me1.SetQuestList(i,GetQuestList(i));
	}

	readCount = fwrite((void*)&Me1,sizeof(Me1),1,fp);
}

void CheckState(){Me.CheckState();}

double GetHp(){return Me.GetHp();}

double GetMaxHp(){return Me.GetMaxHp();}

double GetExp(){return Me.GetExp();}

double GetMaxExp(){return Me.GetMaxExp();}

void SetHpFull(){Me.SetHpFull();}

void SetLevel(int n){Me.SetLevel(n);}

void SetName(char* _name){Me.SetName(_name);}

int GetLevel(){return Me.GetLevel();}

void SetMyJob(const char* str){Me.SetMyJob(str);}

void DrawPlayer(){Me.DrawPlayer();}

void EarnMoney(double n){Me.EarnMoney(n); ShowState();}

void SetMoney(double n){Me.SetMoney(n);}

double GetMoney(){return Me.GetMoney();}