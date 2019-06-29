//*****************************************************************
//	HEXA Ver 0.1
//	Made by 'k-net 9th' Jae-Dong
//	E-Mail: pjd@kw.ac.kr
//*****************************************************************
#include "stdafx.h"
#include <conio.h>
#include <string.h>
//*********************************
//����ü ����
//*********************************
struct STAGE{		//�� �������������� ���̵� ����
	int	speed;	//���ڰ� �������� �ӵ��� ������
	int triple_rate;		//3���� ���� ����� ������ Ȯ�� 0~99  , 99�� 100%�� ����, �Ϲ����� Ȯ���� 3��
	int clear_block;
};

//*********************************
//��� ����
//*********************************
#define EXT_KEY			0xffffffe0	//Ȯ��Ű �νİ� 
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define KEY_SPACE		0x20
#define ABS_X			6
#define ABS_Y			2

enum { 
	BLACK,      /*  0 : ��� */ 
		DARK_BLUE,    /*  1 : ��ο� �Ķ� */ 
		DARK_GREEN,    /*  2 : ��ο� �ʷ� */ 
		DARK_SKY_BLUE,  /*  3 : ��ο� �ϴ� */ 
		DARK_RED,    /*  4 : ��ο� ���� */ 
		DARK_VOILET,  /*  5 : ��ο� ���� */ 
		DARK_YELLOW,  /*  6 : ��ο� ��� */ 
		GRAY,      /*  7 : ȸ�� */ 
		DARK_GRAY,    /*  8 : ��ο� ȸ�� */ 
		BLUE,      /*  9 : �Ķ� */ 
		GREEN,      /* 10 : �ʷ� */ 
		SKY_BLUE,    /* 11 : �ϴ� */ 
		RED,      /* 12 : ���� */ 
		VOILET,      /* 9 : ���� */ 
		YELLOW,      /* 10 : ��� */ 	
		WHITE,      /* 15 : �Ͼ� */ 	
}; 

//*********************************
//������������
//*********************************
int cur_block[3];
int next_block[3];
int cur_x,cur_y;
int level;
int blocks;
int max_combo;
double score;
int total_block[21][10];	//����:����:��� 
struct STAGE stage_data[8];
//*********************************
//�Լ� ����
//*********************************
int gotoxy(int x,int y);	//Ŀ���ű��
void SetColor(int color);	//��ǥ��
int init();					//�������� �ʱ�ȭ
int show_cur_block(int* shape,int x,int y);	//���� �������� ��ǥ��
int show_next_block(int* shape);		//�������� �� ǥ��
int make_new_block(int* shape);
int show_gameover();
int show_total_block();	//�׿����ִ� ���� ȭ�鿡 ǥ���Ѵ�.
int show_gamestat();
int strike_check(int x,int y);
int move_down(int* x,int* y);
int find_fair(int combo);		//¦�� �´°��� ã��
int ani_del_block(int block_arr[21][10]);		//���� ���� ã������ �ִϸ��̼�
int del_block(int block_arr[21][10],int combo);		//���� ���� ã������ �ִϸ��̼�
int input_data();
int show_logo();


int main(int argc, char* argv[])
{
	int i;
	char keytemp;
	int is_gameover;
	int shape_tmp;
	int blank_block[3]={0,0,0};
	int return_tmp;
	show_logo();
	while(1)
	{
		gotoxy(77,23);		//ȭ�� �ܻ��� ���ֱ� ����
		printf("  \b\b");
		input_data();
		init();
		for(i=1;1;i++)
		{
			gotoxy(77,23);		//ȭ�� �ܻ��� ���ֱ� ����
			printf(" \b");

			if(kbhit())
			{
				keytemp = getche();
				if(keytemp == EXT_KEY)
				{
					keytemp = getche();
					show_cur_block(blank_block,cur_x,cur_y);	//�̵��ϱ��� ��ġ�� �� ����������
					switch(keytemp)
					{
					case KEY_UP:		//ȸ���ϱ�
						shape_tmp = cur_block[2];
						cur_block[2] = cur_block[1];
						cur_block[1] = cur_block[0];
						cur_block[0] = shape_tmp;
						
						break;
					case KEY_LEFT:		//�������� �̵�
						if(cur_x>1)
						{
							if(total_block[cur_y+2][cur_x-1] == 0)
								cur_x--;
						}
						break;
					case KEY_RIGHT:		//���������� �̵�
						if(cur_x<8)
						{
							if(total_block[cur_y+2][cur_x+1] ==0)
								cur_x++;
						}
						break;
					case KEY_DOWN:		//�Ʒ��� �̵�
						return_tmp = move_down(&cur_x,&cur_y);
						if(return_tmp == 1 )		//���� �ٴڿ� �������
						{
							if( (cur_y<0) && (total_block[cur_y+3][cur_x] != 0))
							{
								is_gameover=1;
							}else{
								
								find_fair(0);
								show_total_block();
								show_gamestat();
							}
						}
						break;
					}
				}
				if(keytemp == KEY_SPACE )	//�����̽��ٸ� ��������
				{
					return_tmp = 0;
					while(return_tmp == 0)
						return_tmp = move_down(&cur_x,&cur_y);
					
					if( (cur_y<0) && (total_block[cur_y+3][cur_x] != 0))
					{
						is_gameover=1;
					}else{
						
						find_fair(0);
						show_total_block();
						show_gamestat();
					}
					
				}
				
				show_cur_block(cur_block,cur_x,cur_y);
			}
			
			if(i%stage_data[level].speed == 0)
			{
				if(blocks>stage_data[level].clear_block)
					if(level <7)
					{
						level++;
						blocks = 0;
					}
				show_cur_block(blank_block,cur_x,cur_y);	//�̵��ϱ��� ��ġ�� �� ����������
				return_tmp = move_down(&cur_x,&cur_y);		//���� �̵��Ѵ�.
				
				if(return_tmp == 1 )		//���� �ٴڿ� �������	
				{
					if( (cur_y<0) && (total_block[cur_y+3][cur_x] != 0))
					{
						is_gameover=1;
					}else{
						
						find_fair(0);
						show_total_block();
						show_gamestat();
					}
				}
				show_cur_block(cur_block,cur_x,cur_y);
			}
			if(is_gameover == 1)
			{
				show_gameover();
				SetColor(GRAY);
				break;
			}
			Sleep(13);
		}
	}
	return 0;
}

int gotoxy(int x,int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); 
	COORD pos; 
	pos.Y=y;
	pos.X=x;
	SetConsoleCursorPosition(hConsole, pos); 
	return 0;
}

void SetColor(int color) 

{ 
	static HANDLE std_output_handle=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(std_output_handle, color); 
	
} 

int init()
{
	int i,j;
	cur_x = 4;
	cur_y = -2;
	blocks = 0;
	stage_data[0].speed = 40;
	stage_data[0].clear_block = 60;
	stage_data[0].triple_rate = 8; 
	stage_data[1].speed = 37;
	stage_data[1].clear_block = 70;
	stage_data[1].triple_rate = 7; 
	stage_data[2].speed = 33;
	stage_data[2].clear_block = 75;
	stage_data[2].triple_rate = 6; 
	stage_data[3].speed = 30;
	stage_data[3].clear_block = 80;
	stage_data[3].triple_rate = 4; 
	stage_data[4].speed = 27;
	stage_data[4].clear_block = 90;
	stage_data[4].triple_rate = 2; 
	stage_data[5].speed = 22;
	stage_data[5].clear_block = 100;
	stage_data[5].triple_rate = 1; 
	stage_data[6].speed = 18;
	stage_data[6].clear_block = 110;
	stage_data[6].triple_rate = 1; 
	stage_data[7].speed = 10;
	stage_data[7].clear_block = 99999;
	stage_data[7].triple_rate = 1; 
	for(i=0;i<21;i++)
		for(j=0;j<10;j++)
			total_block[i][j] = 0;
	for(i=0;i<21;i++)
	{
		total_block[i][0] = 9;
		total_block[i][9] = 9;
	}
	for(i=0;i<10;i++)
	{
		total_block[20][i] = 9;
	}
	//���� seed�� �ֱ�
	srand((unsigned)time(NULL));

	make_new_block(cur_block);
	make_new_block(next_block);
	show_total_block();
	show_next_block(next_block);
	show_gamestat();
	
	return 0;
}

int input_data()
{
	int i=0;
	SetColor(GRAY);
	gotoxy(10,7);
	printf("����������<GAME KEY>������������");
	Sleep(10);
	gotoxy(10,8);
	printf("�� UP   : Rotate Block        ��");
	Sleep(10);
	gotoxy(10,9);
	printf("�� DOWN : Move One-Step Down  ��");
	Sleep(10);
	gotoxy(10,10);
	printf("�� SPACE: Move Bottom Down    ��");
	Sleep(10);
	gotoxy(10,11);
	printf("�� LEFT : Move Left           ��");
	Sleep(10);
	gotoxy(10,12);
	printf("�� RIGHT: Move Right          ��");
	Sleep(10);
	gotoxy(10,13);
	printf("��������������������������������");
	
	
	while(i<1 || i>8)
	{
		gotoxy(10,3);
		printf("Select Start level[1-8]:       \b\b\b\b\b\b\b");
		scanf("%d",&i);
	}
	
	
	level = i-1;
	system("cls");
	return 0;
}


int move_down(int* x,int* y)
{
	int j;
	if(total_block[*y+3][*x] != 0 )		//���� �ٴڿ� �������
	{
		for(j=0;j<3;j++)
			total_block[*y+j][*x] = cur_block[j];
		cur_block[0] = next_block[0];
		cur_block[1] = next_block[1];
		cur_block[2] = next_block[2];
		make_new_block(next_block);
		show_total_block();
		show_next_block(next_block);
		*x=4;
		*y=-2;
		return 1;
	}else{
		(*y)++;
		return 0;
	}
	
}

int show_cur_block(int* shape,int x,int y)
{
	int i;
	for(i=0;i<3;i++)
	{
		if(y+i <0)		//ȭ�� ������ ���� �������� ����
			continue;

		gotoxy( (x*2)+ABS_X , y+i+ABS_Y );
		printf("  \b\b");
		switch(shape[i])
		{
		case 0:
			SetColor(GRAY*16);
			printf("  ");
			break;
		case 1:
			SetColor(BLUE|WHITE*16);
			printf("��");
			break;
		case 2:
			SetColor(SKY_BLUE|WHITE*16);
			printf("��");
			break;
		case 3:
			SetColor(BLACK|WHITE*16);
			printf("��");
			break;
		case 4:
			SetColor(GREEN|WHITE*16);
			printf("��");
			break;
		case 5:
			SetColor(RED|WHITE*16);
			printf("��");
			break;
		}
	}
	return 0;
}
int show_next_block(int* shape)
{
	int i,j;
	//SetColor(((level+1)%6+1)|GRAY*16);
	for(i=2;i<7;i++)
	{
		gotoxy(28,i);
		for(j=0;j<5;j++)
		{
			if(i==2 || i==6 || j==0 || j==4)
			{
				SetColor(((level+1)%6+1));
				printf("��");				
			}else{
				SetColor(GRAY*16);
				printf("  ");
			}
			
		}
	}
	show_cur_block(shape,13,1);
	return 0;
}

int show_gamestat()
{
	static int printed_text=0;
	SetColor(GRAY);
	if(printed_text == 0)
	{
		gotoxy(29,7);
		printf("STAGE");
		
		gotoxy(29,9);
		printf("SCORE");
		
		gotoxy(29,12);
		printf("BLOCKS");

		gotoxy(29,15);
		printf("MAX COMBO");		
		
	}
	gotoxy(35,7);
	printf("%d",level+1);
	gotoxy(29,10);
	printf("%10d",(int)score);
	gotoxy(29,13);
	printf("%10d",stage_data[level].clear_block - blocks);
	gotoxy(29,16);
	printf("%10d",max_combo);
	return 0;
}

int make_new_block(int* shape)
{
	int i;
	int rtn_tmp;
	rtn_tmp = rand()%100;
	if(stage_data[level].triple_rate > rtn_tmp)	//Ʈ���� Ȯ���� Ʈ������ ���ö�
	{
		rtn_tmp = rand()%5+1;
		shape[0] = rtn_tmp;
		shape[1] = rtn_tmp;
		shape[2] = rtn_tmp;
		return 0;
	}
	for(i=0;i<3;i++)
	{
		shape[i] = rand()%5+1;
	}
	return 0;
}

int show_gameover()
{
	SetColor(RED);
	gotoxy(15,8);
	printf("������������������������������");
	gotoxy(15,9);
	printf("��**************************��");
	gotoxy(15,10);
	printf("��*        GAME OVER       *��");
	gotoxy(15,11);
	printf("��**************************��");
	gotoxy(15,12);
	printf("������������������������������");
	fflush(stdin);
	Sleep(1000);
	
	getche();
	system("cls");
	
	return 0;
}

int show_total_block()
{
	int i,j;
	for(i=0;i<21;i++)
	{
		for(j=0;j<10;j++)
		{
			gotoxy(j*2+ABS_X,i+ABS_Y);
			switch(total_block[i][j])
			{
			case 0:
				SetColor(GRAY|GRAY*16);
				printf("  ");
				break;
			case 1:
				SetColor(BLUE|DARK_GRAY*16);
				printf("��");
				break;
			case 2:
				SetColor(SKY_BLUE|DARK_GRAY*16);
				printf("��");
				break;
			case 3:
				SetColor(BLACK|DARK_GRAY*16);
				printf("��");
				break;
			case 4:
				SetColor(GREEN|DARK_GRAY*16);
				printf("��");
				break;
			case 5:
				SetColor(RED|DARK_GRAY*16);
				printf("��");
				break;
			case 9:
				SetColor(((level %6) +1)*16);
				printf("  ");
				break;
			}
		}
	}
	
	return 0;
}

int find_fair(int combo)
{
	int fair_num=0;
	int i=0,j=1,k=0,l=1;
	int tmp_shape;
	int tmp_x,tmp_y;
	int fair_arr[21][10];
	int is_del_block = 0;

	for(i=0;i<21;i++)		//fair_arr �ʱ�ȭ
		for(j=0;j<10;j++)
			fair_arr[i][j] = 0;
	
	for(i=0;i<20;i++)			//����
	{
		for(j=1;j<9;j++)		//����
		{
			tmp_shape = total_block[i][j];

			if(tmp_shape == 0)	//��ĭ�ϰ�� �������� ����ĭ���� �ű�
				continue;
			
			for(k=0;k<4;k++)	//����
			{
				tmp_y = i;
				tmp_x = j;
				fair_num = 0;
				for(l=1;l<5;l++)	//����
				{
					switch(k)
					{
					case 0:		//���������� ���� �Ʒ� �밢�� ������
						tmp_y++;
						tmp_x--;
						break;
					case 1:		//���������� �Ʒ� ����
						tmp_y++;
						break;
					case 2:		//���������� ������ �Ʒ� �밢�� ����
						tmp_y++;
						tmp_x++;
						break;
					case 3:		//���������� ������ ����
						tmp_x++;
						break;
					}
					if(tmp_x <1 || tmp_x >12 || tmp_y > 20)
						break;
					if(total_block[tmp_y][tmp_x] == tmp_shape)
						fair_num++;
					else
						break;
				}
				if(fair_num >=2)
				{
					is_del_block =1;
					tmp_y = i;
					tmp_x = j;
					for(l=0;l<=fair_num;l++)
					{
						fair_arr[tmp_y][tmp_x] = 1;
						switch(k)
						{
						case 0:		//���������� ���� �Ʒ� �밢�� ������
							tmp_y++;
							tmp_x--;
							break;
						case 1:		//���������� �Ʒ� ����
							tmp_y++;
							break;
						case 2:		//���������� ������ �Ʒ� �밢�� ����
							tmp_y++;
							tmp_x++;
							break;
						case 3:		//���������� ������ ����
							tmp_x++;
							break;
						}
					}
				}
	
			}
		}
	}
	if(is_del_block == 1)	//3���̻��� ���޾� ������
	{
		combo++;
		ani_del_block(fair_arr);
		del_block(fair_arr,combo);
		show_total_block();

		if(combo > max_combo)
			max_combo = combo;

		find_fair(combo);
		return 1;
	}
	return 0;
}

int ani_del_block(int block_arr[21][10])
{
	int i,j,k;

	for(k=0;k<6;k++)
	{
		for(i=0;i<21;i++)
		{
			for(j=1;j<9;j++)
			{
				if(block_arr[i][j] == 0)
					continue;
				
				gotoxy(j*2+ABS_X,i+ABS_Y);
				switch(total_block[i][j])
				{
				case 1:
					SetColor(BLUE|(DARK_GRAY+(k%2))*16);
					printf("��");
					break;
				case 2:
					SetColor(SKY_BLUE|(DARK_GRAY+(k%2))*16);
					printf("��");
					break;
				case 3:
					SetColor(BLACK|(DARK_GRAY+(k%2))*16);
					printf("��");
					break;
				case 4:
					SetColor(GREEN|(DARK_GRAY+(k%2))*16);
					printf("��");
					break;
				case 5:
					SetColor(RED|(DARK_GRAY+(k%2))*16);
					printf("��");
					break;
				}
				
				
				Sleep(24);
			}
			
		}
		
	}
	return 0;
}

int del_block(int block_arr[21][10],int combo)
{
	int i,j,k;
	int block_num=0;		//���ִ� ���� ����
	for(i=19;i>=0;i--)
	{
		for(j=1;j<9;j++)
		{

			if(block_arr[i][j] == 1)
			{
				total_block[i][j]=0;
				block_num++;
				blocks++;
				
			}

		}
	}
	for(i=0;i<20;i++)
	{
		for(j=1;j<9;j++)
		{
			if(total_block[i][j] != 0)
				continue;
			
			for(k=i;k>=0;k--)	//������� ������� ���� �ִ� ������ ä���.
			{
				if(k==0)
				{
					total_block[k][j] = 0;
					
				}else{
					total_block[k][j] = total_block[k-1][j];
					
				}
			}
			
		}
	}

	//���� ���
	score += combo*1.3*(block_num*12);
	return 0;
}
int show_logo()
{
	int i,j;
	int cur_color=0;
	gotoxy(13,3);
	printf("��������������������������������������������������");
	Sleep(100);
	gotoxy(13,4);
	printf("����      ��  �ڡڡڡڡ�  ��      ��     �ڡ�   ��");
	Sleep(100);
	gotoxy(13,5);
	printf("����      ��  ��            ��  ��     ��    �� ��");
	Sleep(100);
	gotoxy(13,6);
	printf("���ڡڡڡڡ�  �ڡڡڡڡ�      ��      �ڡڡڡڡڦ�");
	Sleep(100);
	gotoxy(13,7);
	printf("����      ��  ��            ��  ��    ��      �ڦ�");
	Sleep(100);
	gotoxy(13,8);
	printf("����      ��  �ڡڡڡڡ�  ��      ��  ��      �ڦ�");
	Sleep(100);
	gotoxy(13,9);
	printf("��������������������������������������������������");
	gotoxy(13,10);
	printf(" Ver 0.1                         Made By Jae-Dong  ");
	
	
	gotoxy(28,20);
	printf("Please Press Any Key~!");
	
	for(i=0;i>=0;i++)
	{
		if(i%8==0)
		{
			gotoxy(20,19);
			for(j=0;j<37;j++)
			{
				SetColor((cur_color+j)%16*16);
				printf(" ");
				//cur_color = (cur_color+j)%16;
			}
			if(cur_color >0)
				cur_color--;
			else
				cur_color = 15;
			//Sleep(100);
		}
		if(kbhit())
			break;
		Sleep(10);
	}
	
	getche();
	SetColor(GRAY);
	system("cls");
	
	return 0;
}