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
		printf("��������������������\n");
		printf("�� Black Jack v1.3��\n");
		printf("��������������������\n");
		printf("[1] ���� ����	[2] ���� ���	[3] ���� \n");
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
		printf("��������������������\n");
		printf("�� Black Jack v1.3��\n");
		printf("��������������������\n");
		printf("�����ִ� �� : %d$ \n",money);
		printf("�󸶸� �Žðڽ��ϱ�?[10$�̻�] : ");
		scanf("%d",&bat);
	}while(bat<10 || bat>money);

	/* ī�� ���� */ 
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
	/*ī�� ���� ��*/ 

	system("cls");
		
	if(turn==1)
	{
		/* ���� ���� */
		 
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
		/* ���� ���� ��*/ 
		i--;
		/* ���� �ι�° �� */ 
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
		/*���� �ι�° �� �� */
		i--; 
		/* �ÿ��̾� ���� */ 
		switch(deck[i])
		{
			case 1:
				do{
					system("cls");
					printf("���̽�[A]�� �����̽��ϴ�. \n");
					printf("[1] 11�� �Ѵ�\n");
					printf("[2] 1�� �Ѵ�\n");
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
		/* �÷��̾� ���� ��*/
		i--; 
		/* �÷��̾� �� ��° ��*/
		switch(deck[i])
		{
			case 1:
				do{
					system("cls");
					printf("���̽�[A]�� �����̽��ϴ�. \n");
					printf("[1] 11�� �Ѵ�\n");
					printf("[2] 1�� �Ѵ�\n");
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
		/* �÷��̾� �� ��° �� �� */
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
						printf("���̽�[A]�� �����̽��ϴ�. \n");
						printf("[1] 11�� �Ѵ�\n");
						printf("[2] 1�� �Ѵ�\n");
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
				printf("Player & Dealer ����! \n");
				system("pause");
				total();
			}
			else if(player == 21)
			{
				printf("Player ����! \n");
				system("pause");
				total();
			}
			else if(dealer == 21)
			{
				printf("Dealer ����! \n");
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
		
			printf("������ ī�� : ");
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
				printf("���� : %d \n",player);
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
		printf("���º� \n");

	else if(turn == 1 && player == 21)
	{
		if(player == dealer)
		{
			printf("���º� \n");
		}
		else
		{
			printf("�÷��̾� ��! \n");
			money+=bat*1.5;
		}
	}

	else if(player>dealer)
	{
		if(player>21 && dealer<=21)
		{
			printf("���� ��! \n");
			money-=bat;
		}

		else if(player>21 && dealer>21)
		{
			if(player>dealer)
			{
				printf("���� ��! \n");
				money-=bat;
			}
			else if(player<dealer)
			{
				printf("�÷��̾� ��! \n");
				money+=bat;
			}
		}

		else if(player == 21 || player>dealer)
		{
			printf("�÷��̾� ��! \n");
			money+=bat;
		}
	}

	else if(player<dealer)
	{
		if(dealer>21 && player<=21)
		{
			printf("�÷��̾� ��! \n");
			money+=bat;
		}

		else if(dealer>21 && player>21)
		{
			if(dealer>player)
			{
				printf("�÷��̾� ��! \n");
				money+=bat;
			}
			if(dealer<player)
			{
				printf("���� ��! \n");
				money-=bat;
			}
		}

		else if(dealer==21 || dealer>player)
		{
			printf("���� ��! \n");
			money-=bat;
		}
	}
	system("pause");
	if(money<=0)
	{
		system("cls");
		printf("���� �� �����̽��ϴ�. \n");
		system("pause");
		money=10000;
		main();
	}

	do{
		system("cls");
		printf("����Ͻðڽ��ϱ�?(Y/N) \n");
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
	printf("�� �� �� \n");
	printf("\n");
	printf("1.������ �Ѵ�.(10�޷� �̻�) \n");
	printf("2.���� 21�� �ǰų� ���ڰ� �������� 21�� ������ �̱�ϴ� \n");
	printf("3.21�� �Ǹ� ������ �˴ϴ�. \n");
	system("pause");
	system("cls");
	printf("4.ī�带 �� �ް������ 'Hit'�� ��Ĩ�ϴ�. �׸��ް� ������ 'Stand'�� ��Ĩ�ϴ�. \n");
	printf("5.������ ���ڰ� 16���ϸ� ī�带 �̰� 17�̻��̸� ī�带 ���� �ʽ��ϴ�. \n");
	printf("6.21�� ������ Bust�˴ϴ�. Bust�� �Ǹ� ���ϴ�. \n");
	system("pause");
	system("cls");
	printf("7.������ �÷��̾� �Ѵ� Bust �Ǹ� 21�� ����� ���� �̱�ϴ�. \n");
	printf("8.������ �÷��̾� ���ڰ� ������ ���ϴ�. \n");
	printf("9.A�� 1 �Ǵ� 11�� ����ϰ� J,Q,K�� 10���� ����մϴ�. \n");
	system("pause");
	system("cls");
	printf("10.ù �Ͽ� �� ���� �Ǹ� ���� ���� 1.5�踦 �޽��ϴ�. \n");
	system("pause");
	game();
}
