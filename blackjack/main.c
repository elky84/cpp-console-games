#include<stdio.h>
#include<stdlib.h>
#include<time.h>

char main_screen=0;
int bat=0;
int one=0;
int game_c=0;
char con=0;
int money=10000;
int player=0;
int dealer=0;
int turn=0;
void game(void);
void manual(void);
void total(void);

int main(void)
{
	srand(time(NULL));
	do{
		system("mode con:lines=8 cols=45");
		system("cls");
		printf("┌────────┐\n");
		printf("│ Black Jack v1.3│\n");
		printf("└────────┘\n");
		printf("[1] 게임 시작	[2] 게임 방법	[3] 종료 \n");
		printf("> ");
		scanf(" %c",&main_screen);

		if(main_screen=='1')
			game();
		else if(main_screen=='2')
			manual();
		else if(main_screen=='3')
			exit(0);
	}while(main_screen!='1' && main_screen!='2' && main_screen!='3');
}

void game(void)
{
	int deck[52];
	int c1=4;
	int c2=4;
	int c3=4;
	int c4=4;
	int c5=4;
	int c6=4;
	int c7=4;
	int c8=4;
	int c9=4;
	int c10=4;
	int c11=4;	// J
	int c12=4;	// Q
	int c13=4;	// K
	int hit=0;
	turn=1;
	do{
		system("cls");
		printf("┌────────┐\n");
		printf("│ Black Jack v1.3│\n");
		printf("└────────┘\n");
		printf("갖고있는 돈 : %d$ \n",money);
		printf("얼마를 거시겠습니까?[10$이상] : ");
		scanf("%d",&bat);
	}while(bat<10 || bat>money);

	/* 카드 섞기 */ 
	srand(time(NULL));
	int i;
	int c;
	for(i=0; i<52; i++)
	{
		int k=1;
		while(k)
		{
			c=rand()%13;
			switch(c)
			{
				case 1:
					if(c1)
					{
						deck[i]=1;
						c1--;
						k=0;
					}
					else
						continue;
					break;

				case 2:
					if(c2)
					{
						deck[i]=2;
						c2--;
						k=0;
					}
					else
						continue;
					break;

				case 3:
					if(c3)
					{
						deck[i]=3;
						c3--;
						k=0;
					}
					else
						continue;
					break;

				case 4:
					if(c4)
					{
						deck[i]=4;
						c4--;
						k=0;
					}
				else
					continue;
				break;

			case 5:
				if(c5)
				{
					deck[i]=5;
					c5--;
					k=0;
				}
				else
					continue;
				break;

			case 6:
				if(c6)
				{
					deck[i]=6;
					c6--;
					k=0;
				}
				else 
					continue;
				break;

			case 7:
				if(c7)
				{
					deck[i]=7;
					c7--;
					k=0;
				}
				else 
					continue;
				break;

			case 8:
				if(c8)
				{
					deck[i]=8;
					c8--;
					k=0;
				}
				else
					continue;
				break;

			case 9:
				if(c9)
				{	
					deck[i]=9;
					c9--;
					k=0;
				}
				else
					continue;
				break;

			case 10:
				if(c10)
				{
					deck[i]=10;
					c10--;
					k=0;
				}
				else
					continue;
				break;

			case 11:
				if(c11)
				{
					deck[i]=11;
					c11--;
					k=0;
				}
				else
					continue;
				break;

			case 12:
				if(c12)
				{
					deck[i]=12;
					c12--;
					k=0;
				}
				else
					continue;
				break;

			default:
				if(c13)
				{
					deck[i]=13;
					c13--;
					k=0;
				}
				else
					continue;	
			}	
		}
	}
	/*카드 섞기 끝*/ 

	system("cls");
		
	if(turn==1)
	{
		/* 딜러 선빵 */
		 
		switch(deck[i])
		{
			case 1:
				if(dealer<11)
				{
					dealer+=11;
					one=11;
				}
				else
				{
					dealer+=1;
					one=1;
				}
				break;
					
			case 2:
				dealer+=2;
				one=2;
				break;
	
			case 3:
				dealer+=3;
				one=3;
				break;

			case 4:
				dealer+=4;
				one=4;
				break;
				
			case 5:
				dealer+=5;
				one=5;
				break;

			case 6:
				dealer+=6;
				one=6;
				break;

			case 7:
				dealer+=7;
				one=7;
				break;

			case 8:
				dealer+=8;
				one=8;
				break;

			case 9:
				dealer+=9;
				one=9;
				break;

			case 10:
				dealer+=10;
				one=10;
				break;
			
			case 11:
				dealer+=10;
				one=11;
				break;
				
			case 12:
				dealer+=10;
				one=12;
				break;
			
			default:
				dealer+=10;
				one=13;
		}
		/* 딜러 선빵 끝*/ 
		i--;
		/* 딜러 두번째 빵 */ 
		switch(deck[i])
		{
			case 1:
				if(dealer<11)
					dealer+=11;
				else
					dealer+=1;
				break;
				
			case 2:
				dealer+=2;
				break;

			case 3:
				dealer+=3;
				break;

			case 4:
				dealer+=4;
				break;
				
			case 5:
				dealer+=5;
				break;

			case 6:
				dealer+=6;
				break;
	
			case 7:
				dealer+=7;
				break;

			case 8:
				dealer+=8;
				break;

			case 9:
				dealer+=9;
				break;

			default:
				dealer+=10;
		}
		/*딜러 두번째 빵 끝 */
		i--; 
		/* 플에이어 선빵 */ 
		switch(deck[i])
		{
			case 1:
				do{
					system("cls");
					printf("에이스[A]를 뽑으셨습니다. \n");
					printf("[1] 11로 한다\n");
					printf("[2] 1로 한다\n");
					printf("> "); scanf("%c",&con);
				}while(con != '1' && con != '2');
			
				if(con == '1')
					player+=11;
				else
					player+=1;
				break;
				
			case 2:
				player+=2;
				break;

			case 3:
				player+=3;
				break;

			case 4:
				player+=4;
				break;
			
			case 5:
				player+=5;
				break;

			case 6:
				player+=6;
				break;
	
			case 7:
				player+=7;
				break;

			case 8:
				player+=8;
				break;

			case 9:
				player+=9;
				break;

			default:
				player+=10;				
		}
		/* 플레이어 선빵 끝*/
		i--; 
		/* 플레이어 두 번째 빵*/
		switch(deck[i])
		{
			case 1:
				do{
					system("cls");
					printf("에이스[A]를 뽑으셨습니다. \n");
					printf("[1] 11로 한다\n");
					printf("[2] 1로 한다\n");
					printf("> "); scanf("%c",&con);
				}while(con != '1' && con != '2');
				
				if(con == '1')
					player+=11;
				else
					player+=1;
				break;
					
			case 2:
				player+=2;
				break;

			case 3:
				player+=3;
				break;

			case 4:
				player+=4;
				break;
			
			case 5:
				player+=5;
				break;

			case 6:
				player+=6;
				break;
	
			case 7:
				player+=7;
				break;

			case 8:
				player+=8;
				break;

			case 9:
				player+=9;
				break;

			default:
				player+=10;				
		}
		/* 플레이어 두 번째 빵 끝 */
		i--; 
	}
	
	for(; i>=0; i--)
	{
		if(turn==1)
		{turn--;}
		else
		{
			switch(deck[i])
			{
				case 1:
					if(dealer<11)
						dealer+=11;
					else
						dealer+=1;
					break;
				
				case 2:
					dealer+=2;
					break;

				case 3:
					dealer+=3;
					break;

				case 4:
					dealer+=4;
					break;
				
				case 5:
					dealer+=5;
					break;

				case 6:
					dealer+=6;
					break;
	
				case 7:
					dealer+=7;
					break;

				case 8:
					dealer+=8;
					break;

				case 9:
					dealer+=9;
					break;

				default:
					dealer+=10;
			}
		
			switch(deck[i])
			{
				case 1:
					do{
						system("cls");
						printf("에이스[A]를 뽑으셨습니다. \n");
						printf("[1] 11로 한다\n");
						printf("[2] 1로 한다\n");
						printf("> "); scanf("%c",&con);
					}while(con != '1' && con != '2');
				
					if(con == '1')
						player+=11;
					else
						player+=1;
					break;
					
				case 2:
					player+=2;
					break;
	
				case 3:
					player+=3;
					break;

				case 4:
					player+=4;
					break;
			
				case 5:
					player+=5;
					break;

				case 6:
					player+=6;
					break;
	
				case 7:
					player+=7;
					break;

				case 8:
					player+=8;
					break;

				case 9:
					player+=9;
					break;

				default:
					player+=10;				
			}
		}
			
		do{
			system("cls");
				
			if(player == 21 && dealer ==21)
			{
				printf("Player & Dealer 블랙잭! \n");
				system("pause");
				total();
			}
			else if(player == 21)
			{
				printf("Player 블랙잭! \n");
				system("pause");
				total();
			}
			else if(dealer == 21)
			{
				printf("Dealer 블랙잭! \n");
				system("pause");
				total();
			}
			else if(dealer>21 && player>21)
			{
				printf("Player & Dealer Bust! \n");
				system("pause");
				total();
			}
			else if(player>21)
			{
				printf("Player Bust! \n");
				system("pause");
				total();
			}
			else if(dealer>21)
			{
				printf("Dealer Bust! \n");
				system("pause");
				total();
			}
		
			printf("딜러의 카드 : ");
			switch(one)
			{
				case 1 : 
					printf("A \n");
					break;

				case 2:
					printf("2 \n");
					break;

				case 3:
					printf("3 \n");
					break;

				case 4:
					printf("4 \n");
					break;

				case 5:
					printf("5 \n");
					break;
				
				case 6:
					printf("6 \n");
					break;

				case 7:
					printf("7 \n");
					break;

				case 8:
					printf("8 \n");
					break;

				case 9:
					printf("9 \n");
					break;

				case 10 :
					printf("10 \n");
					break;
				
				case 11:
					printf("J \n");
					break;
				
				case 12:
					printf("Q \n");
					break;
					
				default:
					printf("K \n");
			}
				printf("점수 : %d \n",player);
				printf("[1] Hit	[2] Stand \n");
				printf("> ");
				scanf("%d",&hit);
		}while(hit<1 || hit>2);

		if(hit==1)
			continue;
		else
			total();
	}
}

void total(void)
{
	system("cls");
	printf("Player = %d \n",player);
	printf("Dealer = %d \n",dealer);

	if(player == dealer)
		printf("무승부 \n");

	else if(turn == 1 && player == 21)
	{
		if(player == dealer)
		{
			printf("무승부 \n");
		}
		else
		{
			printf("플레이어 승! \n");
			money+=bat*1.5;
		}
	}

	else if(player>dealer)
	{
		if(player>21 && dealer<=21)
		{
			printf("딜러 승! \n");
			money-=bat;
		}

		else if(player>21 && dealer>21)
		{
			if(player>dealer)
			{
				printf("딜러 승! \n");
				money-=bat;
			}
			else if(player<dealer)
			{
				printf("플레이어 승! \n");
				money+=bat;
			}
		}

		else if(player == 21 || player>dealer)
		{
			printf("플레이어 승! \n");
			money+=bat;
		}
	}

	else if(player<dealer)
	{
		if(dealer>21 && player<=21)
		{
			printf("플레이어 승! \n");
			money+=bat;
		}

		else if(dealer>21 && player>21)
		{
			if(dealer>player)
			{
				printf("플레이어 승! \n");
				money+=bat;
			}
			if(dealer<player)
			{
				printf("딜러 승! \n");
				money-=bat;
			}
		}

		else if(dealer==21 || dealer>player)
		{
			printf("딜러 승! \n");
			money-=bat;
		}
	}
	system("pause");
	if(money<=0)
	{
		system("cls");
		printf("돈을 다 잃으셨습니다. \n");
		system("pause");
		money=10000;
		main();
	}

	do{
		system("cls");
		printf("계속하시겠습니까?(Y/N) \n");
		printf("> ");
		scanf(" %c",&con);
	}while(con != 'y' && con !='Y' && con!='N' && con!='n');

	if(con == 'y' || con == 'Y')
		game();
	if(con == 'N' || con == 'n')
		main();
}

void manual(void)
{
	system("cls");
	printf("블랙 잭 룰 \n");
	printf("\n");
	printf("1.베팅을 한다.(10달러 이상) \n");
	printf("2.먼저 21이 되거나 숫자가 딜러보다 21에 가까우면 이깁니다 \n");
	printf("3.21이 되면 블랙잭이 됩니다. \n");
	system("pause");
	system("cls");
	printf("4.카드를 더 받고싶으면 'Hit'를 외칩니다. 그만받고 싶으면 'Stand'를 외칩니다. \n");
	printf("5.딜러는 숫자가 16이하면 카드를 뽑고 17이상이면 카드를 뽑지 않습니다. \n");
	printf("6.21을 넘으면 Bust됩니다. Bust가 되면 집니다. \n");
	system("pause");
	system("cls");
	printf("7.딜러와 플레이어 둘다 Bust 되면 21에 가까운 쪽이 이깁니다. \n");
	printf("8.딜러와 플레이어 숫자가 같으면 비깁니다. \n");
	printf("9.A는 1 또는 11로 계산하고 J,Q,K는 10으로 계산합니다. \n");
	system("pause");
	system("cls");
	printf("10.첫 턴에 블랙 잭이 되면 베팅 금의 1.5배를 받습니다. \n");
	system("pause");
	game();
}
