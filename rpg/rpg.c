//---------------------------------------------------------------------------

#include <stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>

#pragma hdrstop

#include <tchar.h>
//---------------------------------------------------------------------------

#pragma argsused
int _tmain(int argc, _TCHAR* argv[])
{
	int level;
	int mlevel;
	int co;
	int monster;
	int lev;
	int hp;
	int mhp;
	int exp;
	int getexp;
	int defense;
	int mobdefense;
	int gold;
	int getgold;
	int str;
	int dex;
	int store1;
	int store2;
	int weapon;
	int armor;
	int item;
	int quest;
	int q;
	int starting;
	int q2;
	int mobhp;
	int mobmhp;
	int menu;
	int npc1;
	int npc2;
	int attack; // 기본공격력
	int randattack; // 기본공격력 랜덤
	int a;
	int b;
	int c;
	int d;
	int e;
	int f;
	int g;
	int h;
	int i;
	int choose;
	int mobattack;
	int randa;
	int potion;
	int load;
	int savelevel;
	int saveexp;
	int saveweapon;
	int savearmor;
	int savegold;
	int jobs;
	int job;
	int skill;
	int sp;
	int twoattack;
	int threeattack;
	int killattack;
	int shot;
    int firebomb;
    int killing;
    int skillc;

	printf("[1.시작하기]\n[2.불러오기]\n[3.종료하기]\n");
	scanf("%d",&a);

	if(a == 1)
	{
		system("cls");
		Sleep(2000);
		printf("게임을 불러옵니다.\n");
		Sleep(1000);
		system("cls");
		printf("게임을 불러옵니다..\n");
		Sleep(1000);
		system("cls");
		printf("게임을 불러옵니다...\n");
		Sleep(1000);
		system("cls");
		printf("게임을 불러옵니다....\n");
		Sleep(1000);
		system("cls");
		printf("게임을 불러옵니다.....\n");
		Sleep(1000);
		system("cls");
		Sleep(1000);
		level = 1;
		hp = 100;
		mhp = 100;
		str = 10;
		dex = 10;
		exp = 0;
		weapon = 0;
		armor = 0;
		gold = 2000;
		b = 1;
		a = 0;
		f = 0;
		lev = 0;
		potion = 0;
		starting = 0;
		job = 0;
		sp = 0;
	}
	else
	{
		void exit();
	}

	if(a == 2)
    {
         printf("[저장했을 때 얻은 코드를 입력해주세요]\n");
         scanf("%d",&load);

         if(load == 151)
         {
           	level = 1;
       		hp = 100;
   	        mhp = 100;
		    str = 10;
		    dex = 10;
		    exp = 0;
		    weapon = 0;
	     	armor = 0;
     	    gold = 2000;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 0;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 142)
         {
            level = 2;
       		hp = 150;
   	        mhp = 150;
		    str = 10;
		    dex = 10;
		    exp = 100;
		    gold = 2100;
		    weapon = 0;
	     	armor = 0;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 0;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 133)
         {
            level = 3;
            hp = 200;
   	        mhp = 200;
		    str = 10;
		    dex = 10;
		    exp = 400;
		    gold = 2300;
		    weapon = 0;
	     	armor = 0;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 1;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 124)
         {
            level = 4;
            hp = 300;
   	        mhp = 300;
		    str = 10;
		    dex = 10;
		    exp = 800;
		    gold = 2500;
		    weapon = 0;
	     	armor = 0;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 2;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 115)
         {
            level = 5;
            hp = 450;
   	        mhp = 450;
		    str = 10;
		    dex = 10;
		    exp = 1500;
		    gold = 3000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 1;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 3;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 106)
         {
            level = 6;
            hp = 650;
   	        mhp = 650;
		    str = 10;
		    dex = 10;
		    exp = 2200;
		    gold = 3500;
		    weapon = 0;
	     	armor = 0;
	     	sp = 2;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 4;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 97)
         {
            level = 7;
            hp = 900;
   	        mhp = 900;
		    str = 10;
		    dex = 10;
		    exp = 3000;
		    gold = 4000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 3;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 5;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 88)
         {
            level = 8;
            hp = 1200;
   	        mhp = 1200;
		    str = 10;
		    dex = 10;
		    exp = 4000;
		    gold = 5000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 4;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 6;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 79)
         {
            level = 9;
            hp = 1600;
   	        mhp = 1600;
		    str = 10;
		    dex = 10;
		    exp = 5500;
		    gold = 6000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 5;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 7;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 610)
         {
            level = 10;
            hp = 2000;
   	        mhp = 2000;
		    str = 10;
		    dex = 10;
		    exp = 7000;
		    gold = 7000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 6;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 8;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 511)
         {
            level = 11;
            hp = 2500;
   	        mhp = 2500;
		    str = 10;
		    dex = 10;
		    exp = 9000;
		    gold = 8000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 7;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 9;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 412)
         {
            level = 12;
            hp = 3000;
   	        mhp = 3000;
		    str = 10;
		    dex = 10;
		    exp = 12000;
		    gold = 9000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 8;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 10;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 313)
         {
            level = 13;
            hp = 3500;
   	        mhp = 3500;
		    str = 10;
		    dex = 10;
		    exp = 18000;
		    gold = 10000;
		    weapon = 0;
	     	armor = 0;
	     	sp = 9;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 11;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 214)
         {
            hp = 4000;
   	        mhp = 4000;
            level = 14;
		    exp = 30000;
		    gold = 12500;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 10;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 12;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 115)
         {
            hp = 4500;
   	        mhp = 4500;
            level = 15;
		    exp = 50000;
		    gold = 15000;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 11;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 13;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 2116)
         {
            hp = 5000;
   	        mhp = 5000;
            level = 16;
		    exp = 80000;
		    gold = 18000;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 12;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 14;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 2217)
         {
            hp = 6000;
   	        mhp = 6000;
            level = 17;
		    exp = 120000;
		    gold = 20000;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 13;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 15;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 2318)
         {
            hp = 8000;
   	        mhp = 8000;
            level = 18;
		    exp = 160000;
		    gold = 22000;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 14;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 16;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 2419)
         {
            hp = 10000;
   	        mhp = 10000;
            level = 19;
		    exp = 200000;
		    gold = 25000;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 15;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 17;
      		potion = 0;
       	    starting = 0;
         }

         if(load == 2520)
         {
            hp = 15000;
   	        mhp = 15000;
            level = 20;
		    exp = 25000;
		    gold = 30000;
			str = 10;
		    dex = 10;
		    weapon = 0;
	     	armor = 0;
	     	sp = 16;
	       	b = 1;
        	a = 0;
        	f = 0;
        	lev = 18;
      		potion = 0;
       	    starting = 0;
         }
    }

	while(b == 1)
	{
 	//레벨 1 고블린
	while(f == 1)
	{
		printf("[고블린 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");
			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 30+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[고블린에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[고블린에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[고블린에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
									  system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 40+1;
			getexp = rand() % 40+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold,getexp);
			gold += getgold;
			exp += getexp;
			if(q == 1)
			{
				if(q2 < 5)
				{
					q2 += 1;
					printf("퀘스트 : [%d / 5]\n",q2);
				}
			}
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

 	//레벨 2 고블린투척병
	while(f == 2)
	{
		printf("[고블린투척병 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 50+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[고블린투척병에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[고블린투척병에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[고블린투척병에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 70+1;
			getexp = rand() % 80+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold,getexp);
			gold += getgold;
			exp += getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 3 고블린십장
	while(f == 3)
	{
		printf("[고블린십장 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 80+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[고블린십장에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[고블린십장에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[고블린십장에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 100+1;
			getexp = rand() % 120+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold,getexp);
			gold += getgold;
			exp += getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 3 코볼트
	while(f == 4)
	{
		printf("[코볼트 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 80+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[코볼트에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[코볼트에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[코볼트에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 120+1;
			getexp = rand() % 130+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+50,getexp+50);
			gold += 50+getgold;
			exp += 50+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 5 코볼트전투병
	while(f == 5)
	{
		printf("[코볼트전투병 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			if(weapon == 0){randattack = rand() % str+1;}
			mobhp -= randattack + str;
			mobattack = rand() % 100+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[코볼트전투병에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[코볼트전투병에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[코볼트전투병에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 150+1;
			getexp = rand() % 140+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+60,getexp+60);
			gold += 60+getgold;
			exp += 60+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 6 코볼트부대장
	while(f == 6)
	{
		printf("[코볼트부대장 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 150+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[코볼트부대장에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[코볼트부대장에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[코볼트부대장에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 200+1;
			getexp = rand() % 180+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+150,getexp+150);
			gold += 150+getgold;
			exp += 150+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 7 코볼트대장
	while(f == 7)
	{
		printf("[코볼트대장 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[1]공격\n[2]도망\n[3]포션\n[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 170+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[코볼트대장에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[코볼트대장에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[코볼트대장에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 250+1;
			getexp = rand() % 200+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+200,getexp+200);
			gold += 200+getgold;
			exp += 200+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 5 마력이 약한 요정
	while(f == 8)
	{
		printf("[마력이 약한 요정 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 220+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[마력이 약한 요정에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[마력이 약한 요정에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[마력이 약한 요정에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 300+1;
			getexp = rand() % 250+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+250,getexp+250);
			gold += 250+getgold;
			exp += 250+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 6 마력이 강한 요정
	while(f == 9)
	{
		printf("[마력이 강한 요정 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 300+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[마력이 강한 요정에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[마력이 강한 요정에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[마력이 강한 요정에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 350+1;
			getexp = rand() % 300+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold,getexp);
			gold += getgold;
			exp += getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 7 흑요정
	while(f == 10)
	{
		printf("[흑요정 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 450+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[흑요정에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[흑요정에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[흑요정에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 400+1;
			getexp = rand() % 320+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+500,getexp+500);
			gold += 500+getgold;
			exp += 500+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	//레벨 8 흑요정왕
	while(f == 11)
	{
		printf("[흑요정왕 체력 : %d / %d]\n",mobhp,mobmhp);
		printf("[나의 체력 : %d / %d]\n",hp,mhp);
		printf("[포션 개수 : %d]\n",potion);
		printf("[1]공격\n[2]도망\n[3]포션\n"); if(job >= 1){printf("[4]스킬\n");}
		scanf("%d",&choose);

		if(choose == 1)
		{
			system("cls");
			printf("[공격하였다]\n");

			Sleep(2000);
			randattack = rand() % str+1;
			mobhp -= randattack + str;
			mobattack = rand() % 600+1;
			if(mobattack-dex >= 0)
			{
			hp -= mobattack - dex;
            }
			printf("[흑요정왕에게 %d의 데미지를 주었다!]\n",randattack+str);
			Sleep(1000);
			printf("[흑요정왕에게 %d의 피해를 입었다!]\n",mobattack-dex);
            Sleep(1000);
			system("cls");
		}

		if(choose == 2)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[흑요정왕에게서 도망쳤다]\n");
			Sleep(2000);
			printf("[쿨타임 10초]\n");
			Sleep(10000);
			system("cls");
		}

		if(choose == 3)
		{
			if(potion >= 1)
			{
				system("cls");
				printf("[포션을 사용하였습니다]\n");

				Sleep(2000);

				if(level == 1)
				{
					hp = 100;
					mhp = 100;
				}

				if(level == 2)
				{
					hp = 150;
					mhp = 150;
				}

				if(level == 3)
				{
					hp = 200;
					mhp = 200;
				}

				if(level == 4)
				{
					hp = 300;
					mhp = 300;
				}

				if(level == 5)
				{
					hp = 450;
					mhp = 450;
				}

				if(level == 6)
				{
					hp = 650;
					mhp = 650;
				}

				if(level == 7)
				{
					hp = 900;
					mhp = 900;
				}

				if(level == 8)
				{
					hp = 1200;
					mhp = 1200;
				}

				if(level == 9)
				{
					hp = 1600;
					mhp = 1600;
				}

				if(level == 10)
				{
					hp = 2000;
					mhp = 2000;
				}

				if(level == 11)
				{
					hp = 2500;
					mhp = 2500;
				}

				if(level == 12)
				{
					hp = 3000;
					mhp = 3000;
				}

				if(level == 13)
				{
					hp = 3500;
					mhp = 3500;
				}

				if(level == 14)
				{
					hp = 4000;
					mhp = 4000;
				}

				if(level == 15)
				{
					hp = 4500;
					mhp = 4500;
				}

				if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

				system("cls");
				potion -= 1;
			}
			else
			{
				system("cls");
				printf("[포션이 없습니다]\n");
				Sleep(2000);
				system("cls");
			}
		}

		if(choose == 4)
		{
                  if(job == 1 || job == 2)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(twoattack == 1){printf("[1]이단콤보 - hp 200 소모\n");}
                         if(threeattack == 1){printf("[2]삼단가르기 - hp 1500 소모\n");}
                         if(killattack == 1){printf("[3]파멸의흔적 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(twoattack != 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack != 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(twoattack == 1 && threeattack == 1 && killattack == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[이중 콤보 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*2);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[삼단 가르기 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[파멸의흔적 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("파!\n");
                                      Sleep(500);
                                      printf("멸!\n");
                                      Sleep(500);
                                      printf("의!\n");
                                      Sleep(500);
                                      printf("흔!\n");
                                      Sleep(500);
                                      printf("적!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*20 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*20);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }

                  if(job == 3 || job == 4)
                  {
                         system("cls");
                         printf("[사용할 스킬을 고르세요]\n");
                         if(shot == 1){printf("[1]더블샷 - hp 200 소모\n");}
                         if(firebomb == 1){printf("[2]파이어 봄 - hp 1500 소모\n");}
                         if(killing == 1){printf("[3]킬링 애로우 - hp 10000 소모\n");}
                         printf("[4]나가기\n");
                         scanf("%d",&skillc);

                         if(shot != 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb != 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing != 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[잘못된 선택입니다]\n");
                                      printf("[패널티 10초]\n");
                                      Sleep(10000);
                                      system("cls");
                                      }
                         }

                         if(shot == 1 && firebomb == 1 && killing == 1)
                         {
                                      if(skillc == 1)
                                      {
                                      system("cls");
                                      printf("[더블 샷 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
                                      hp -= 200;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*2 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 2)
                                      {
                                      system("cls");
                                      printf("[파이어 봄 발동!]\n");
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*4 + str;
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 1500;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*4);
			                          Sleep(1000);
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }

                                      if(skillc == 3)
                                      {
                                      system("cls");
                                      printf("[킬링애로우 발동!]\n");
                                      Sleep(2000);
                                      system("cls");
                                      printf("킬!\n");
                                      Sleep(500);
                                      printf("링!\n");
                                      Sleep(500);
                                      printf("애!\n");
                                      Sleep(500);
                                      printf("로!\n");
                                      Sleep(500);
                                      printf("우!\n");
                                      Sleep(500);
                                      Sleep(2000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(100);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack/2 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str/2);
			                          Sleep(1000);
			                          printf("[마지막 이닷!]\n");
                                      Sleep(1000);
                                      randattack = rand() % str+1;
			                          mobhp -= randattack*10 + str;
			                          printf("[%d의 데미지를 주었다!]\n",randattack+str*10);
			                          Sleep(1000);
			                          mobattack = rand() % 50+1;
			                          if(mobattack-dex >= 0)
			                          {
			                          hp -= mobattack - dex;
                                      }
                                      hp -= 10000;
			                          printf("[%d의 피해를 입었다!]\n",mobattack-dex);
                                      Sleep(1000);
			                          system("cls");
                                      }
                         }
                  }
  }

        if(job == 0)
        {
		if(choose != 1 && choose != 2 && choose != 3)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }
        else
        {
        if(choose != 1 && choose != 2 && choose != 3 && choose != 4)
		{
            f = 0;
			system("cls");
			printf("[잘못된 선택이므로 패널티를 받고 되돌아갑니다]\n");
			printf("[패널티 골드 대량 감소]\n");
			gold -= gold/2;
			Sleep(2000);
			system("cls");
		}
        }

		if(mobhp <= 0)
		{
            f = 0;
			system("cls");
			Sleep(2000);
			printf("[승리하였습니다]");
			getgold = rand() % 500+1;
			getexp = rand() % 500+1;
			printf("[골드 + %d / 경험치 + %d 획득]\n",getgold+4000,getexp+4000);
			gold += 4000+getgold;
			exp += 4000+getexp;
			Sleep(2000);
			system("cls");
		}

		if(hp <= 0)
		{
              system("cls");
              Sleep(1000);
              printf("[당신은 죽었습니다]");
              Sleep(1000);
              system("cls");
              f = 0;
        }
	}

	if(f <= 1)
	{
		printf("[LEVEL : %d]\n",level);
		printf("[HP : %d / %d]\n",hp,mhp);
		printf("[EXP : %d]\n",exp);
		printf("[GOLD : %d]\n",gold);
		if(weapon == 0){printf("[WEAPON : 맨손]\n");} if(weapon == 1){printf("[WEAPON : 허름한검]\n");}if(weapon == 2){printf("[WEAPON : 쓸만한검]\n");}if(weapon == 3){printf("[WEAPON : 브론즈소드]\n");}if(weapon == 4){printf("[WEAPON : 아이언소드]\n");}if(weapon == 5){printf("[WEAPON : 아만다디움소드]\n");}
		if(armor == 0){printf("[ARMOR : 허름한옷]\n\n");}if(armor == 1){printf("[ARMOR : 평상복]\n\n");}if(armor == 2){printf("[ARMOR : 허름한 갑옷]\n\n");}if(armor == 3){printf("[ARMOR : 쓸만한갑옷]\n\n");}if(armor == 4){printf("[ARMOR : 철갑옷]\n\n");}
		printf("[STR : %d]\n",str);
		printf("[DEX : %d]\n\n",dex);
		if(job == 1){printf("[JOB : 전사]\n\n");} if(job == 2){printf("[JOB : 파이터]\n\n");} if(job == 3){printf("[JOB : 궁수]\n\n");} if(job == 4){printf("[JOB : 헌터]\n\n");}

		printf("[1]던전입장\n");
		printf("[2]무기상점\n");
		printf("[3]방어구상점\n");
		printf("[4]포션구입\n");
		printf("[5]여관\n");
		printf("[6]퀘스트\n");
		printf("[7]전직하기\n");
		printf("[8]저장하기\n");
		if(job >= 1){printf("[9]스킬찍기\n");}
		scanf("%d",&menu);
    }

		//레벨 업
		if(exp >= 100)
		{
			if(lev == 0)
			{
				level = 2;
				lev += 1;
				hp = 150;
				mhp = 150;
			}
		}
		if(exp >= 400)
		{
			if(lev == 1)
			{
				level = 3;
				lev += 1;
				hp = 200;
				mhp = 200;
			}
		}
		if(exp >= 800)
		{
			if(lev == 2)
			{
				level = 4;
				lev += 1;
				hp = 300;
				mhp = 300;
			}
		}
		if(exp >= 1500)
		{
			if(lev == 3)
			{
				level = 5;
				lev += 1;
				hp = 450;
				mhp = 450;
				sp += 1;
			}
		}
		if(exp >= 2200)
		{
			if(lev == 4)
			{
				level = 6;
				lev += 1;
				hp = 650;
				mhp = 650;
				sp += 1;
			}
		}
		if(exp >= 3000)
		{
			if(lev == 5)
			{
				level = 7;
				lev += 1;
				hp = 900;
				mhp = 900;
				sp += 1;
			}
		}
		if(exp >= 4000)
		{
			if(lev == 6)
			{
				level = 8;
				lev += 1;
				hp = 1200;
				mhp = 1200;
				sp += 1;
			}
		}
		if(exp >= 5500)
		{
			if(lev == 7)
			{
				level = 9;
				lev += 1;
				hp = 1600;
				mhp = 1600;
				sp += 1;
			}
		}
		if(exp >= 7000)
		{
			if(lev == 8)
			{
				level = 10;
				lev += 1;
				hp = 2000;
				mhp = 2000;
				sp += 1;
			}
		}
		if(exp >= 9000)
		{
			if(lev == 9)
			{
				level = 11;
				lev += 1;
				hp = 2500;
				mhp = 2500;
				sp += 1;
			}
		}
		if(exp >= 12000)
		{
			if(lev == 10)
			{
				level = 12;
				lev += 1;
				hp = 3000;
				mhp = 3000;
				sp += 1;
			}
		}
		if(exp >= 18000)
		{
			if(lev == 11)
			{
				level = 13;
				lev += 1;
				hp = 3500;
				mhp = 3500;
				sp += 1;
			}
		}
		if(exp >= 30000)
		{
			if(lev == 12)
			{
				level = 14;
				lev += 1;
				hp = 4000;
				mhp = 4000;
				sp += 1;
			}
		}
		if(exp >= 50000)
		{
			if(lev == 13)
			{
				level = 15;
				lev += 1;
				hp = 4500;
				mhp = 4500;
				sp += 1;
			}
		}
		if(exp >= 80000)
		{
			if(lev == 14)
			{
				level = 16;
				lev += 1;
				hp = 5000;
				mhp = 5000;
				sp += 1;
			}
		}
		if(exp >= 120000)
		{
			if(lev == 15)
			{
				level = 17;
				lev += 1;
				hp = 6000;
				mhp = 6000;
				sp += 1;
			}
		}
		if(exp >= 160000)
		{
			if(lev == 16)
			{
				level = 18;
				lev += 1;
				hp = 8000;
				mhp = 8000;
				sp += 1;
			}
		}
		if(exp >= 200000)
		{
			if(lev == 17)
			{
				level = 19;
				lev += 1;
				hp = 10000;
				mhp = 10000;
				sp += 1;
			}
		}
		if(exp >= 250000)
		{
			if(lev == 18)
			{
				level = 20;
				lev += 1;
				hp = 15000;
				mhp = 15000;
				sp += 1;
			}
		}
		//레벨 업 끝

		//던전입장
		if(menu == 1)
		{
			system("cls");
			Sleep(1000);
			printf("[던전을 선택해주세요]\n\n");
			printf("[1]고블린의 숲 <1~2>\n");
			printf("[2]코볼트 유적지 <2~5>\n");
			printf("[3]요정의 숲 <5~8>\n");
			printf("[4]나가기\n");
			scanf("%d",&c);

			//[LV1~LV2]고블린의숲
			if(c == 1)
			{
             	monster = rand() % 3+1;
				system("cls");
				printf("던전 입장 중...");
				Sleep(2500);
				if(monster == 1){printf("[고블린이 나타났습니다! - LV 0]\n");}if(monster == 2){printf("[고블린투척병이 나타났습니다! - LV 1]\n");}if(monster == 3){printf("[고블린십장이 나타났습니다! - LV 2]\n");}
				printf("[1]싸운다\n[2]도망친다\n");
				scanf("%d",&e);

				//싸우자
				if(e == 1)
				{
					//레벨1 고블린
					if(monster == 1)
					{
                      	mobhp = 50;
	                   	mobmhp = 50;
	                   	menu = 0;
						f = 1;
					}

					//레벨2 고블린투척병
					else if(monster == 2)
					{
                        mobhp = 80;
	                   	mobmhp = 80;
                        menu = 0;
						f = 2;
					}

					//레벨3 고블린십장
					else if(monster == 3)
					{
                        mobhp = 130;
	                   	mobmhp = 130;
                        menu = 0;
						f = 3;
					}
				}

				//도망치자
				if(e == 2)
				{
					system("cls");
					printf("[도망쳤다]\n");
					Sleep(2000);
					printf("[쿨타임 10초]\n");
					Sleep(10000);
					system("cls");
				}

				if(e != 1 && e != 2)
				{
					system("cls");
					printf("[잘못 선택하였습니다]\n");
					Sleep(1000);
					printf("[쿨타임 10초]\n");
					Sleep(10000);
					system("cls");
				}
			}
			//고블린의 숲 끝

			//[LV2~LV5]코볼트 유적지
			if(c == 2)
			{
               	monster = rand() % 4+1;
				system("cls");
				printf("던전 입장 중...");
				Sleep(2500);
				if(monster == 1){printf("[코볼트 나타났습니다! - LV 2]\n");}if(monster == 2){printf("[코볼트전투병이 나타났습니다! - LV 3]\n");}if(monster == 3){printf("[코볼트부대장이 나타났습니다!- LV 4]\n");}if(monster == 4){printf("[코볼트대장이 나타났습니다!- LV 5]\n");}
				printf("[1]싸운다\n[2]도망친다\n");
				scanf("%d",&e);

				//싸우자
				if(e == 1)
				{
					//레벨3 코볼트
					if(monster == 1)
					{
                      	mobhp = 150;
	                   	mobmhp = 150;
	                   	menu = 0;
						f = 4;
					}

					//레벨5 코볼트전투병
					else if(monster == 2)
					{
                        mobhp = 200;
	                   	mobmhp = 200;
                        menu = 0;
						f = 5;
					}

					//레벨6 코볼트부대장
					else if(monster == 3)
					{
                        mobhp = 240;
	                   	mobmhp = 240;
                        menu = 0;
						f = 6;
					}

					//레벨7 코볼트대장
					else if(monster == 4)
					{
                        mobhp = 270;
	                   	mobmhp = 270;
                        menu = 0;
						f = 7;
					}
				}

				//도망치자
				if(e == 2)
				{
					system("cls");
					printf("[도망쳤다]\n");
					Sleep(2000);
					printf("[쿨타임 10초]\n");
					Sleep(10000);
					system("cls");
				}

				if(e != 1 && e != 2)
				{
					system("cls");
					printf("[잘못 선택하였습니다]\n");
					Sleep(1000);
					printf("[쿨타임 10초]\n");
					Sleep(10000);
					system("cls");
				}
			}
			//코볼트 유적지 끝

			//[LV5~LV8]요정의 숲
			if(c == 3)
			{
               	monster = rand() % 4+1;
				system("cls");
				printf("던전 입장 중...");
				Sleep(2500);
				if(monster == 1){printf("[마력이 약한 요정이 나타났습니다! - LV 5]\n");}if(monster == 2){printf("[마력이 강한 요정이 나타났습니다! - LV 6]\n");}if(monster == 3){printf("[흑요정이 나타났습니다!- LV 7]\n");}if(monster == 4){printf("[흑요정왕이 나타났습니다!- LV 8]\n");}
				printf("[1]싸운다\n[2]도망친다\n");
				scanf("%d",&e);

				//싸우자
				if(e == 1)
				{
					//레벨5 마력이 약한 요정
					if(monster == 1)
					{
                      	mobhp = 400;
	                   	mobmhp = 400;
	                   	menu = 0;
						f = 8;
					}

					//레벨6 마력이 강한 요정
					else if(monster == 2)
					{
                        mobhp = 640;
	                   	mobmhp = 640;
                        menu = 0;
						f = 9;
					}

					//레벨7 흑요정
					else if(monster == 3)
					{
                        mobhp = 900;
	                   	mobmhp = 900;
                        menu = 0;
						f = 10;
					}

					//레벨8 흑요정왕
					else if(monster == 4)
					{
                        mobhp = 1500;
	                   	mobmhp = 1500;
                        menu = 0;
						f = 11;
					}
				}

				//도망치자
				if(e == 2)
				{
					system("cls");
					printf("[도망쳤다]\n");
					Sleep(2000);
					printf("[쿨타임 10초]\n");
					Sleep(10000);
					system("cls");
				}

				if(e != 1 && e != 2)
				{
					system("cls");
					printf("[잘못 선택하였습니다]\n");
					Sleep(1000);
					printf("[쿨타임 10초]\n");
					Sleep(10000);
					system("cls");
				}
			}
			//요정의 숲 끝

			if(c == 4)
			{
				system("cls");
			}

			//던전입구에서 나가기
			if(c != 1 && c != 2 && c != 3 && c != 4)
			{
				system("cls");
				printf("[잘못 선택하였습니다]\n");
				Sleep(2000);
				system("cls");
			}
			//끝
		}

		//무기상점
		if(menu == 2)
		{
			system("cls");
			Sleep(1000);
			printf("[무기상점 입장중.]\r");
			Sleep(1000);
			printf("[무기상점 입장중..]\r");
			Sleep(1000);
			printf("[무기상점 입장중...]\r");
			Sleep(1000);

			npc1 = rand() % 3+1;
			if(npc1 == 1){printf("[무기상인 : 어서오시게나.]\n");} if(npc1 == 2){printf("[무기상인 : 내 가게 무기는 최고의 무기들만 있지]\n");} if(npc1 == 3){printf("[무기상인 : 만약 돈이 없다면 썩 꺼지게나.]\n");}
			printf("[1]허름한검<1레벨> - 1000골드\n");
			printf("[2]쓸만한검<3레벨> - 2500골드\n");
			printf("[3]브론즈소드<5레벨> - 3800골드\n");
			printf("[4]아이언소드<8레벨> - 5200골드\n");
			printf("[5]아만다디움소드<10레벨> - 7500골드\n");
			printf("[6]나가기\n");
			scanf("%d",&store1);

			if(store1 == 1)
			{
				if(gold >= 1000)
				{
					if(level >= 1)
					{
					system("cls");
					printf("[무기구입중...]\n");
					Sleep(3000);
					printf("[무기상인 : 사줘서 고맙네. 잘가게나 친구!]\n");
					gold -= 1000;
					str = 15;
					weapon = 1;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[무기상인 : 돈없으면 이가게에서 당장 나가!]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store1 == 2)
			{
				if(gold >= 2500)
				{
					if(level >= 3)
					{
					system("cls");
					printf("[무기구입중...]\n");
					Sleep(3000);
					printf("[무기상인 : 사줘서 고맙네. 잘가게나 친구!]\n");
					gold -= 2500;
					str = 21;
					weapon = 2;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[무기상인 : 돈없으면 이가게에서 당장 나가!]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store1 == 3)
			{
				if(gold >= 3800)
				{
					if(level >= 5)
					{
					system("cls");
					printf("[무기구입중...]\n");
					Sleep(3000);
					printf("[무기상인 : 사줘서 고맙네. 잘가게나 친구!]\n");
					gold -= 3800;
					str = 30;
					weapon = 3;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[무기상인 : 돈없으면 이가게에서 당장 나가!]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store1 == 4)
			{
				if(gold >= 5200)
				{
					if(level >= 8)
					{
					system("cls");
					printf("[무기구입중...]\n");
					Sleep(3000);
					printf("[무기상인 : 사줘서 고맙네. 잘가게나 친구!]\n");
					gold -= 5200;
					str = 38;
					weapon = 4;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[무기상인 : 돈없으면 이가게에서 당장 나가!]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store1 == 5)
			{
				if(gold >= 7500)
				{
					if(level >= 10)
					{
					system("cls");
					printf("[무기구입중...]\n");
					Sleep(3000);
					printf("[무기상인 : 사줘서 고맙네. 잘가게나 친구!]\n");
					gold -= 7500;
					str = 45;
					weapon = 5;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[무기상인 : 돈없으면 이가게에서 당장 나가!]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store1 == 6)
			{
				system("cls");
			}

			if(store1 != 1 && store1 != 2 && store1 != 3 && store1 != 4 && store1 != 5 && store1 != 6)
			{
				system("cls");
				printf("[잘못된 선택입니다]\n");
				system("cls");
			}
		}
		//무기 상점 끝

		//방어구상점
		if(menu == 3)
		{
			system("cls");
			Sleep(1000);
			printf("[방어구상점 입장중.]\r");
			Sleep(1000);
			printf("[방어구상점 입장중..]\r");
			Sleep(1000);
			printf("[방어구상점 입장중...]\r");
			Sleep(1000);

			npc2 = rand() % 3+1;
			if(npc2 == 1){printf("[방어구상인 : 어서오세요~]\n");} if(npc2 == 2){printf("[방어구상인 : 저희 가게는 최고의 방어구를 자랑한답니다]\n");} if(npc2 == 3){printf("[방어구상인 : 만약 돈이 없다면 나가주세요]\n");}
			printf("[1]평상복<1레벨> - 3000골드\n");
			printf("[2]허름한 갑옷<3레벨> - 5500골드\n");
			printf("[3]쓸만한 갑옷<5레벨> - 9000골드\n");
			printf("[4]철 갑옷<8레벨> - 12000골드\n");
			printf("[5]나가기\n");
			scanf("%d",&store2);

			if(store2 == 1)
			{
				if(gold >= 3000)
				{
					if(level >= 1)
					{
					system("cls");
					printf("[방어구구입중...]\n");
					Sleep(3000);
					printf("[방어구상인 : 고맙습니다. 안녕히가세요~]\n");
					gold -= 3000;
					dex = 15;
					armor = 1;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[방어구상인 : 돈이 부족하시네요]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store2 == 2)
			{
				if(gold >= 5500)
				{
					if(level >= 3)
					{
					system("cls");
					printf("[방어구구입중...]\n");
					Sleep(3000);
					printf("[방어구상인 : 고맙습니다. 안녕히가세요~]\n");
					gold -= 5500;
					dex = 21;
					armor = 2;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[방어구상인 : 돈이 부족하시네요]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store2 == 3)
			{
				if(gold >= 9000)
				{
					if(level >= 5)
					{
					system("cls");
					printf("[방어구구입중...]\n");
					Sleep(3000);
					printf("[방어구상인 : 고맙습니다. 안녕히가세요~]\n");
					gold -= 9000;
					dex = 30;
					armor = 3;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[방어구상인 : 돈이 부족하시네요]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store2 == 4)
			{
				if(gold >= 12000)
				{
					if(level >= 8)
					{
					system("cls");
					printf("[방어구구입중...]\n");
					Sleep(3000);
					printf("[방어구상인 : 고맙습니다. 안녕히가세요~]\n");
					gold -= 12000;
					dex = 35;
					armor = 4;
					Sleep(2000);
					system("cls");
					}
					else
					{
						system("cls");
						printf("[레벨이 맞지 않습니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
				else
				{
					system("cls");
					printf("[방어구상인 : 돈이 부족하시네요]\n");
					Sleep(2000);
					system("cls");
				}
			}

			if(store2 == 5)
			{
				system("cls");
			}

			if(store2 != 1 && store2 != 2 && store2 != 3 && store2 != 4 && store2 != 5)
			{
				system("cls");
				printf("[잘못된 선택입니다]\n");
				system("cls");
			}
		}
		//방어구 상점 끝

		//포션상점
		if(menu == 4)
		{
			system("cls");
			printf("[포션을 구입하시겠습니까?]\n");
			printf("[1]1개 - 200골드\n");
			printf("[2]5개 = 900골드\n");
			printf("[3]나가기\n");
			scanf("%d",&h);

			if(h == 1)
			{
                if(potion <= 5)
                {
				if(gold >= 200)
				{
					system("cls");
					printf("[포션 1개를 구입하였습니다]");
					potion += 1;
					gold -= 200;
					Sleep(2000);
					system("cls");
				}
				else
				{
					system("cls");
					printf("[돈이 부족합니다]");
					Sleep(2000);
					system("cls");
				}
                }
                else
                {
                    system("cls");
                    printf("[5개 이상 소지시 구입이 불가능 합니다]\n");
                    Sleep(2000);
                    system("cls");
                }
			}

			if(h == 2)
			{
                if(potion <= 5)
                {
				if(gold >= 900)
				{
					system("cls");
					printf("[포션 5개를 구입하였습니다]");
					potion += 5;
					gold -= 900;
					Sleep(2000);

					if(potion > 5)
					{
                              potion = 5;
                    }
               		system("cls");
				}
				else
				{
					system("cls");
					printf("[돈이 부족합니다]");
					Sleep(2000);
					system("cls");
				}
                }
                else
                {
                    system("cls");
                    printf("[5개 이상 소지시 구입이 불가능 합니다]\n");
                    Sleep(2000);
                    system("cls");
                }
			}

			if(h == 3)
			{
			}

			if(h == 1 && h == 2 && h == 3)
			{
				system("cls");
				printf("[잘못입력하셨습니다]");
				Sleep(2000);
				system("cls");
			}
		}
		//포션 상점 끝

		//여관 입장
		if(menu == 5)
		{
			system("cls");
			printf("[여관에 오신 것을 환영합니다]");
			Sleep(2000);
			system("cls");
			printf("[쉬는중...]");
			Sleep(2000);
			system("cls");

            if(level == 1)
            {
                hp = 100;
                mhp = 100;
            }

			if(level == 2)
			{
				hp = 150;
				mhp = 150;
			}

			if(level == 3)
			{
				hp = 200;
				mhp = 200;
			}

			if(level == 4)
			{
				hp = 300;
				mhp = 300;
			}

			if(level == 5)
			{
				hp = 450;
				mhp = 450;
			}

			if(level == 6)
			{
				hp = 650;
				mhp = 650;
			}

			if(level == 7)
			{
				hp = 900;
				mhp = 900;
			}

			if(level == 8)
			{
				hp = 1200;
				mhp = 1200;
			}

			if(level == 9)
			{
				hp = 1600;
				mhp = 1600;
			}

			if(level == 10)
			{
				hp = 2000;
				mhp = 2000;
			}

			if(level == 11)
			{
				hp = 2500;
				mhp = 2500;
			}

			if(level == 12)
			{
				hp = 3000;
				mhp = 3000;
			}

			if(level == 13)
			{
				hp = 3500;
				mhp = 3500;
			}

			if(level == 14)
			{
				hp = 4000;
				mhp = 4000;
			}

			if(level == 15)
			{
				hp = 4500;
				mhp = 4500;
			}

			if(level == 16)
			{
				hp = 5000;
				mhp = 5000;
			}

			if(level == 17)
			{
				hp = 6000;
				mhp = 6000;
			}

			if(level == 18)
			{
				hp = 8000;
				mhp = 8000;
			}

			if(level == 19)
			{
				hp = 10000;
				mhp = 10000;
			}

			if(level == 20)
			{
				hp = 20000;
				mhp = 20000;
			}

			printf("[체력이 회복되었습니다]\n");
			Sleep(2000);
			system("cls");
		}
		//여관 끝

		if(menu == 6)
		{
			system("cls");
			printf("[퀘스트 목록]\n");
			printf("[1]고블린 5마리 처치\n");
			printf("=보상 - 300골드 50경험치=\n");
			printf("[2]나가기\n");
			scanf("%d",&quest);

			if(quest == 1)
			{
				if(q2 == 5)
				{
					system("cls");
					printf("[퀘스트를 완료하였습니다]\n");
					Sleep(2000);
					printf("[300 골드 50 경험치 획득]\n");
					gold += 300;
					exp += 50;
					q = 0;
					q2 = 0;
					starting == 0;
				}
				else
				{
					if(starting == 0)
					{
						system("cls");
						printf("[퀘스트를 (다시)받으시겠습니까?]\n");
						printf("[1]네\n[2]아니요\n");
						scanf("%d",&co);

						if(co == 1)
						{
							starting = 1;
							q = 1; // 1번퀘스트
							q2 = 0; // 잡은 횟수 초기화
							printf("[퀘스트가 시작되었습니다]\n");
							Sleep(2000);
							system("cls");
						}

						if(co == 2)
						{
							system("cls");
						}

						if(co == 1 && co == 2)
						{
							system("cls");
							printf("[잘못입력하셨습니다]\n");
							Sleep(2000);
							system("cls");
						}
					}
					else
					{
						system("cls");
						printf("[다른 퀘스트가 진행 중입니다]\n");
						Sleep(2000);
						system("cls");
					}
				}
			}

			if(quest == 2)
			{
			}

			if(quest == 1 && quest == 2)
			{
				system("cls");
				printf("[잘못입력하셨습니다]\n");
				Sleep(2000);
				system("cls");
			}
        }

        if(menu == 7)
        {
                system("cls");
                printf("[무엇으로 전직하시겠습니까?]\n");
                printf("[1]전사 - 1차전직[5레벨]\n[2]파이터 - 각성[20레벨]\n[3]궁수 - 1차전직[5레벨]\n[4]헌터 - 각성[20레벨]\n");
                scanf("%d",&jobs);

                if(jobs == 1)
                {
                        if(level >= 5)
                        {
                                 system("cls");
                                 printf("[전사로 전직하였습니다]\n");
                                 job = 1;
                                 Sleep(2000);
                                 printf("[스킬을 찍으실 수 있습니다]\n");
                        }
                        else
                        {
                            system("cls");
                            printf("[레벨이 맞지 않습니다]\n");
                            Sleep(2000);
                            system("cls");
                        }
                }

                if(jobs == 2)
                {
                        if(level >= 20)
                        {
							if(job == 1)
							{
                                 system("cls");
                                 printf("[파이터로 각성하였습니다]\n");
                                 job = 2;
                                 Sleep(2000);
                                 printf("[각성스킬을 찍으실 수 있습니다]\n");
							}
							else
							{
								 system("cls");
								 printf("[전직을 먼저 해주세요]\n");
								 Sleep(2000);
								 system("cls");
							}
                        }
                        else
                        {
                            system("cls");
                            printf("[레벨이 맞지 않습니다]\n");
                            Sleep(2000);
                            system("cls");
                        }
                }

                if(jobs == 3)
                {
                        if(level >= 5)
                        {
                                 system("cls");
                                 printf("[궁수로 전직하였습니다]\n");
                                 job = 3;
                                 Sleep(2000);
                                 printf("[스킬을 찍으실 수 있습니다]\n");
                        }
                        else
                        {
                            system("cls");
                            printf("[레벨이 맞지 않습니다]\n");
                            Sleep(2000);
                            system("cls");
                        }
                }

                if(jobs == 4)
                {
                        if(level >= 20)
                        {
							if(job == 3)
							{
                                 system("cls");
                                 printf("[헌터로 각성하였습니다]\n");
                                 job = 4;
                                 Sleep(2000);
                                 printf("[각성스킬을 찍으실 수 있습니다]\n");
							}
							else
							{
								 system("cls");
								 printf("[전직을 먼저 해주세요]\n");
								 Sleep(2000);
								 system("cls");
							}
                        }
                        else
                        {
                            system("cls");
                            printf("[레벨이 맞지 않습니다]\n");
                            Sleep(2000);
                            system("cls");
                        }
                }

                if(jobs == 1 && jobs == 2 && jobs == 3 && jobs == 4)
                {
                        system("cls");
                        printf("[잘못선택하셨습니다]");
                        Sleep(2000);
                        system("cls");
                }
        }
        if(menu == 8)
        {
                if(level == 1)
                {
                         savelevel = 15;
                         saveexp = 1;
                }

                if(level == 2)
                {
                         savelevel = 14;
                         saveexp = 2;
                }

                if(level == 3)
                {
                         savelevel = 13;
                         saveexp = 3;
                }

                if(level == 4)
                {
                         savelevel = 12;
                         saveexp = 4;
                }

                if(level == 5)
                {
                         savelevel = 11;
                         saveexp = 5;
                }

                if(level == 6)
                {
                         savelevel = 10;
                         saveexp = 6;
                }

                if(level == 7)
                {
                         savelevel = 9;
                         saveexp = 7;
                }

                if(level == 8)
                {
                         savelevel = 8;
                         saveexp = 8;
                }

                if(level == 9)
                {
                         savelevel = 7;
                         saveexp = 9;
                }

                if(level == 10)
                {
                         savelevel = 6;
                         saveexp = 10;
                }

                if(level == 11)
                {
                         savelevel = 5;
                         saveexp = 11;
                }

                if(level == 12)
                {
                         savelevel = 4;
                         saveexp = 12;
                }

                if(level == 13)
                {
                         savelevel = 3;
                         saveexp = 13;
                }

                if(level == 14)
                {
                         savelevel = 2;
                         saveexp = 14;
                }

                if(level == 15)
                {
                         savelevel = 1;
                         saveexp = 15;
                }

                if(level == 16)
                {
                         savelevel = 21;
                         saveexp = 16;
                }

                if(level == 17)
                {
                         savelevel = 22;
                         saveexp = 17;
                }

                if(level == 18)
                {
                         savelevel = 23;
                         saveexp = 18;
                }

                if(level == 19)
                {
                         savelevel = 24;
                         saveexp = 19;
                }

                if(level == 20)
                {
                         savelevel = 25;
                         saveexp = 20;
                }

                system("cls");
                printf("[저장중...]\n");
                Sleep(2000);
                printf("[코드번호 : %d%d]\n",savelevel,saveexp);
                printf("[20초 후 꺼집니다]");
                Sleep(20000);
                break;
        }
		//스킬찍기
		if(menu == 9)
		{
			if(jobs == 1 || jobs == 2)
			{
                    system("cls");
                    printf("[무슨 스킬을 찍으시겠습니까?]\n");
                    printf("[SP : %d]\n",sp);
                    printf("[GOLD : %d]\n",gold);
                    printf("[1]이단콤보 <SP 3 , GOLD 2000>\n");
                    printf("[2]삼단가르기 <SP 5 , GOLD 5000>\n");
                    printf("[3]파멸의흔적 - 각성 <SP 7 , GOLD 20000>\n");
                    scanf("%d",&skill);

                    if(skill == 1)
                    {
                             if(sp >= 3)
                             {
                                   if(gold >= 2000)
                                   {
                                           system("cls");
                                           printf("[스킬을 배웠습니다]\n");
                                           twoattack = 1;
                                           sp -= 3;
                                           gold -= 2000;
                                           Sleep(2000);
                                           system("cls");
                                   }
                                   else
                                   {
                                       system("cls");
                                       printf("[골드가 부족합니다]\n");
                                       Sleep(2000);
                                       system("cls");
                                   }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[스킬포인트가 부족합니다]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                    }

                    if(skill == 2)
                    {
                             if(twoattack == 1)
                             {
                             if(sp >= 5)
                             {
                                   if(gold >= 5000)
                                   {
                                           system("cls");
                                           printf("[스킬을 배웠습니다]\n");
                                           threeattack = 1;
                                           sp -= 5;
                                           gold -= 5000;
                                           Sleep(2000);
                                           system("cls");
                                   }
                                   else
                                   {
                                       system("cls");
                                       printf("[골드가 부족합니다]\n");
                                       Sleep(2000);
                                       system("cls");
                                   }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[스킬포인트가 부족합니다]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[이전 스킬먼저 찍어주세요]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                    }

                    if(skill == 3)
                    {
                             if(threeattack == 1)
                             {
                             if(sp >= 7)
                             {
                                   if(gold >= 20000)
                                   {
                                           system("cls");
                                           printf("[스킬을 배웠습니다]\n");
                                           killattack = 1;
                                           sp -= 7;
                                           gold -= 20000;
                                           Sleep(2000);
                                           system("cls");
                                   }
                                   else
                                   {
                                       system("cls");
                                       printf("[골드가 부족합니다]\n");
                                       Sleep(2000);
                                       system("cls");
                                   }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[스킬포인트가 부족합니다]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[이전 스킬먼저 찍어주세요]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                    }

                    if(skill == 1 && skill == 2 && skill == 3)
                    {
                             system("cls");
                             printf("[잘못된선택입니다]\n");
                             Sleep(2000);
                             system("cls");
                    }
            }

            if(jobs == 3 || jobs == 4)
			{
                    system("cls");
                    printf("[무슨 스킬을 찍으시겠습니까?]\n");
                    printf("[SP : %d]\n",sp);
                    printf("[GOLD : %d]\n",gold);
                    printf("[1]더블샷 <SP 3 , GOLD 2000>\n");
                    printf("[2]파이어 봄 <SP 5 , GOLD 5000>\n");
                    printf("[3]킬링 애로우 - 각성 <SP 7 , GOLD 20000>\n");
                    scanf("%d",&skill);

                    if(skill == 1)
                    {
                             if(sp >= 3)
                             {
                                   if(gold >= 2000)
                                   {
                                           system("cls");
                                           printf("[스킬을 배웠습니다]\n");
                                           shot = 1;
                                           sp -= 3;
                                           gold -= 2000;
                                           Sleep(2000);
                                           system("cls");
                                   }
                                   else
                                   {
                                       system("cls");
                                       printf("[골드가 부족합니다]\n");
                                       Sleep(2000);
                                       system("cls");
                                   }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[스킬포인트가 부족합니다]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                    }

                    if(skill == 2)
                    {
                             if(shot == 1)
                             {
                             if(sp >= 5)
                             {
                                   if(gold >= 5000)
                                   {
                                           system("cls");
                                           printf("[스킬을 배웠습니다]\n");
                                           firebomb = 1;
                                           sp -= 5;
                                           gold -= 5000;
                                           Sleep(2000);
                                           system("cls");
                                   }
                                   else
                                   {
                                       system("cls");
                                       printf("[골드가 부족합니다]\n");
                                       Sleep(2000);
                                       system("cls");
                                   }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[스킬포인트가 부족합니다]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[이전 스킬먼저 찍어주세요]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                    }

                    if(skill == 3)
                    {
                             if(firebomb == 1)
                             {
                             if(sp >= 7)
                             {
                                   if(gold >= 20000)
                                   {
                                           system("cls");
                                           printf("[스킬을 배웠습니다]\n");
                                           killing = 1;
                                           sp -= 7;
                                           gold -= 20000;
                                           Sleep(2000);
                                           system("cls");
                                   }
                                   else
                                   {
                                       system("cls");
                                       printf("[골드가 부족합니다]\n");
                                       Sleep(2000);
                                       system("cls");
                                   }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[스킬포인트가 부족합니다]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                             }
                             else
                             {
                                 system("cls");
                                 printf("[이전 스킬먼저 찍어주세요]\n");
                                 Sleep(2000);
                                 system("cls");
                             }
                    }

                    if(skill == 1 && skill == 2 && skill == 3)
                    {
                             system("cls");
                             printf("[잘못된선택입니다]\n");
                             Sleep(2000);
                             system("cls");
                    }
            }
		}
		//스킬찍기끝

        if(jobs == 0)
        {
		        if(menu == 1 && menu == 2 && menu == 3 && menu == 4 && menu == 5 && menu == 6 && menu == 7 && menu == 8)
		        {
			            system("cls");
			            printf("[잘못입력하셨습니다]");
			            Sleep(2000);
			            system("cls");
                }
        }
        else
        {
                if(menu == 1 && menu == 2 && menu == 3 && menu == 4 && menu == 5 && menu == 6 && menu == 7 && menu == 8 && menu == 9)
		        {
			            system("cls");
			            printf("[잘못입력하셨습니다]");
			            Sleep(2000);
			            system("cls");
                }
        }
}
	return 0;
}
//---------------------------------------------------------------------------
