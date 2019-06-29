//*****************************************************************
//	venezia Ver 0.1
//	Made by 'k-net 9th' Jae-Dong
//	E-Mail: pjd@kw.ac.kr
//*****************************************************************

#include "stdafx.h"
#include <conio.h>
#include <string.h>
//***********************************
//�������
//***********************************
#define WORD_FILENAME "WORD.KOR"
//***********************************
//����ü����
//***********************************
struct STAGE{
	int delay;
	int frequency;	//0~99������ �����Ǽ��� 0���� ������� �����϶� ������ �����Ǵ��� ����
};
struct STAGE_WORD{
	int is_empty;	//������� 1 �Ⱥ������ 0;
	int x;
	int y;
	int len;
	char *str;		//
};


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
		VOILET,      /* 13 : ���� */ 
		YELLOW,      /* 14 : ��� */ 	
		WHITE,      /* 15 : �Ͼ� */ 
		
}; 

//***********************************
//�������� ����
//***********************************
char word[3000][9];
int total_word;		//�ܾ��� �� �� 
char input_buf[100];
static int input_buf_index;	//�Է� ������ �ε��� 
int score;
int life;
int level;
int correct_word;	//��Ȯ�� ���� �ܾ��� ����, �������� �Ҷ� ���
struct STAGE level_data[8];
struct STAGE_WORD stage_worddata[20];

//*********************
//�Լ� proto type ����
//*********************
int gotoxy(int x,int y);
void SetColor(int color);
int init();	//���Ϸκ��� �ܾ �ҷ����̰� ���� �����ʱ�ȭ
int show_stage();	//���������� ������ ���
int show_gameover();
int show_logo();
int show_word();		//ȭ�鿡 �������� �ܾ ǥ��
int show_stat();		//���ӻ��� ������ ������ǥ�ø� ����
int input_data();
int show_gameframe();  //����Ʋ ���
int next_step_word();	//�ܾ ��ĭ��������
int make_word();
int strike_check_str();	//�ܾ �ٴڿ� ��Ҵ��� �˻�.
int check_str();		//�Է��� �ܾ ȭ�鿡 �ִ� �ܾ�� ��ġ���� �˻�

int main(int argc, char* argv[])
{

	int tmp1;
	int i;
	if(init())
		return 1;	//���Ͽ��¿����� ���α׷� ����



	show_logo();
	input_data();
	show_gameframe();
	show_stage();
	system("cls");
	show_gameframe();
	show_stat();
	for(i=1;i>=0;i++)
	{
		
		if(kbhit())
		{
			tmp1 = getche();
			
			if(tmp1>127)
			{
				int tmp2;
				tmp2 = getche();
				input_buf[input_buf_index] = tmp1;
				input_buf[input_buf_index+1] = tmp2;
				input_buf[input_buf_index+2] = NULL;
				input_buf_index +=2;

				
			}else{
				input_buf[input_buf_index] = tmp1;
				input_buf_index++;
				input_buf[input_buf_index] = NULL;
			}
			if(tmp1==32 || tmp1== 13)	//�����̽��� ��������
			{
				input_buf[input_buf_index-1] = NULL;
				check_str();
				input_buf_index=0;
				input_buf[0]=NULL;
				gotoxy(33,21);
				printf("                ");
			}
			if(tmp1==8)	// �� �����̽��� ��������
			{
				input_buf_index--;
				input_buf_index--;
				if(input_buf_index>0)
					input_buf_index--;
				if((input_buf_index>1) && (input_buf[input_buf_index]>127))	//�ѱ��� ��� �ѹ���Ʈ�� ������
					input_buf_index--;
				
				if(input_buf_index <0)
					input_buf_index=0;
				gotoxy(33,21);
				printf("                ");
				fflush(stdout);
			}
			
		}
		
		if(i%level_data[level].delay==0)	//�ܾ ȭ��󿡼� ��ĭ������
		{
			next_step_word();
			if( (rand()%100)<(level_data[level].frequency) )	//���������� �ܾ���� Ȯ���� �ܾ ������ ����
			{
				make_word();
				
			}
			strike_check_str();	//�ٴڿ� ������ �ܾ�˻�
			show_word();
			if(life<=0)
			{
				show_gameover();
			}
			
			show_stat();
			
			
		}
		
		gotoxy(33,21);
		printf("%s",input_buf);
		gotoxy(33+input_buf_index,21);
		Sleep(10);
		gotoxy(78,0);
	}
	return 0;
}
int init()
{
	int i;
	FILE *fp;

	//���Ϸκ��� �ܾ� �о���̱�
	total_word=0;
	fp = fopen(WORD_FILENAME,"rt");
	
	if(fp == NULL)
	{
		printf("Word File Open ERROR!!");
		return 1;
	}
	for(i=0;i<3000;i++)
	{
		if(feof(fp))
		{
			word[i][0]=NULL;
			continue;
		}

		fscanf(fp,"%s",word[i]);
		total_word++;
	}
	fclose(fp);

	//���� seed�� �ֱ�
	srand((unsigned)time(NULL));  

	//�������� �ʱ�ȭ
	score=0;
	life=9;
	level=0;
	input_buf_index=0;
	correct_word=0;
	level_data[0].delay=140;		//�� ������������ ���̵��� �����Ҽ� �ִ�.
	level_data[0].frequency=60;
	level_data[1].delay=130;
	level_data[1].frequency=50;
	level_data[2].delay=110;
	level_data[2].frequency=43;
	level_data[3].delay=90;
	level_data[3].frequency=40;
	level_data[4].delay=80;
	level_data[4].frequency=40;
	level_data[5].delay=70;
	level_data[5].frequency=40;
	level_data[6].delay=60;
	level_data[6].frequency=40;
	level_data[7].delay=40;
	level_data[7].frequency=40;

	for(i=0;i<20;i++)
	{
		stage_worddata[i].is_empty=1;
	}

	make_word();	//�������ڸ��� ȭ�鿡 �ܾ �ϳ� ����
	return 0;
}

int make_word()
{
	int i;
	for(i=0;i<20;i++)
	{
		if(stage_worddata[i].is_empty)
		{
			stage_worddata[i].is_empty=0;	//������� �ƴ��� �˸�
			stage_worddata[i].str = word[rand()%total_word];	//�������� ���ӻ� ���� �ܾ ����
			stage_worddata[i].len = strlen(stage_worddata[i].str);
			stage_worddata[i].y=2;
			stage_worddata[i].x=rand()%(80-stage_worddata[i].len);
			break;
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
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
	
} 
int strike_check_str()
{
	int i;
	for(i=0;i<20;i++)
	{
		if( (stage_worddata[i].is_empty==0) && (stage_worddata[i].y == 24) )
		{
			stage_worddata[i].is_empty=1;
			life--;

			//�ܻ������
			gotoxy(stage_worddata[i].x,23);
			printf("%*s",stage_worddata[i].len," ");
		}

		if( (stage_worddata[i].is_empty==0) && (stage_worddata[i].y == 20) )
		{
			if((stage_worddata[i].x< 51 && stage_worddata[i].x>=31) ||
				((stage_worddata[i].x+stage_worddata[i].len)< 51) && ((stage_worddata[i].x+stage_worddata[i].len)>=31))
			{
				
				stage_worddata[i].is_empty=1;
				life--;
				
				//�ܻ������
				gotoxy(stage_worddata[i].x,19);
				printf("%*s",stage_worddata[i].len," ");
			}
		}
	}
	return 0;
}
int show_gameover()
{
	gotoxy(25,8);
	printf("������������������������������������");
	gotoxy(25,9);
	printf("��********************************��");
	gotoxy(25,10);
	printf("��*           GAME OVER          *��");
	gotoxy(25,11);
	printf("��********************************��");
	gotoxy(25,12);
	printf("������������������������������������");
	return 0;
}

int show_word()
{
	int i;
	for(i=0;i<20;i++)
	{
		if(stage_worddata[i].is_empty == 0)
		{
			if(stage_worddata[i].y !=2)
			{
				gotoxy(stage_worddata[i].x,stage_worddata[i].y-1);
				printf("%*s",stage_worddata[i].len," ");
			}
		}
		
	}
	for(i=0;i<20;i++)
	{
		if(stage_worddata[i].is_empty == 0)
		{
			gotoxy(stage_worddata[i].x,stage_worddata[i].y);
			printf("%s",stage_worddata[i].str);
		}

	}
	return 0;
}

int next_step_word()
{
	int i;
	for(i=0;i<20;i++)
	{
		if(stage_worddata[i].is_empty == 0)
		{
			stage_worddata[i].y++;
		}
	}
	return 0;
}

int show_stat()
{
	int i;

	gotoxy(2,0);
	printf("stage - %d",level+1);
	gotoxy(58,0);
	printf("score - %10d",score);
	gotoxy(32,23);
	for(i=0;i<9;i++)
	{
		if(i<life)
			printf("��");
		else
			printf("��");
	}
	return 0;
}

int check_str()
{
	int i;

	for(i=0;i<20;i++)
	{
		if(stage_worddata[i].is_empty == 1)
			continue;

		if(strcmp(input_buf,stage_worddata[i].str) == 0)	//ȭ�鿡�ִ� �ܾ ����� �������
		{
					
			stage_worddata[i].is_empty=1;
			score += (stage_worddata[i].len*10)+(rand()%10);
			gotoxy(stage_worddata[i].x,stage_worddata[i].y);
			printf("%*s",stage_worddata[i].len," ");
			show_stat();
			
			correct_word++;	//��Ȯ������ܾ��� ����
			if((correct_word%20+(level*4)) ==0)
			{
				level++;
				score = (int)(score*1.1);
				show_stage();
				system("cls");
				show_gameframe();
				show_word();
			}
		}
	}

	return 0;
}

int show_gameframe()
{
	int i;
	gotoxy(0,1);
	for(i=0;i<80;i+=2)
		printf("��");

	gotoxy(0,24);
	for(i=0;i<78;i+=2)
		printf("��");

	gotoxy(31,20);
	printf("��������������������");
	gotoxy(31,21);
	printf("��                ��");
	gotoxy(31,22);
	printf("��������������������");

	gotoxy(32,23);
	for(i=0;i<9;i++)
	{
		if(i<life)
			printf("��");
		else
			printf("��");
	}
	return 0;
}

int show_logo()
{
	int i,j,k=0;
	char intro_text[31][50]={"","","","","","����� ����ġ�Ƹ� �ƽʴϱ�?",
							"�Ƹ��ٿ� ���ǵ��� ���Ͻ��� �ִ�",
							"��Ż���� �Ϻ��� ����ġ��",
							"���ε鿡�Դ� �Ƹ��ٿ� �뷡��",
							"ö���ڵ鿡�Դ� ���� ����� �׸���",
							"���ε鿡�Դ� ������ ����� �����Ѱ�...",
							"����2020��",
							"�������� �ٴ幰������ ħ�İ� �ν�����",
							"�ٸ� �ǹ����� ���븦 ���߰�, ȭ���ߴ�",
							"�߾�� ����������� ����ä �ϳ���",
							"ž���� ������ ���� �ֽ��ϴ�. �׷���,",
							"�� ����ġ���� �ϴÿ�",
							"'���̷��� ����'�� ��Ÿ���ϴ�.",
							"�ϴÿ��� �������� �� ���̷�������",
							"���ӿ� �������ų� ž�� �������¼���",
							"ž�� �����ϰ� �ִ� ������",
							"�ϳ��� �ϳ��� ���߷� ���ϴ�.",
							"ž�� �����ϰ� �ִ� ������ ��� ��������",
							"�츮�� ����� ����� ���� ������ ž����",
							"�������� ������� �����Դϴ�.",
							"'����ġ�Ƹ� ����϶�'",
							"���� ����ġ�Ƹ� ��ų ������ ������ �ٷ�",
							"����� �տ� ����� �ֽ��ϴ�.",
							"���̷����� ���� �ε� ����ġ�Ƹ� ������",
							"���� �ֽʽÿ�.",
							"����� ���ϴ�!"};
	gotoxy(13,3);
	printf("��������������������������������������������������");
	Sleep(500);
	gotoxy(13,4);
	printf("����  ������  ��    ����  ���������� �צ��� ��  ��");
	Sleep(500);
	gotoxy(13,5);
	printf("������������  ��    ����      ��  �� ��  �� ��  ��");
	Sleep(500);
	gotoxy(13,6);
	printf("����  ������  ��    ����    �ע�  �� ��  �� ��  ��");
	Sleep(500);
	gotoxy(13,7);
	printf("������������  ����������  ��    �٦� �٦��� ��  ��");
	Sleep(500);
	gotoxy(13,8);
	printf("��������������������������������������������������");
	gotoxy(13,9);
	printf(" Ver 0.1                         Made By Jae-Dong  ");

	gotoxy(27,20);
	printf("Please Press Any Key!");

	for(i=0;i>=0;i++)
	{
		if(i%40==0)
		{
			
			for(j=0;j<6;j++)
			{
				gotoxy(18,12+j);
				printf("                                                 ");
				gotoxy(18,12+j);
				printf("%s",intro_text[((k%31)+j)%31]);
			}
			k++;
		}
		if(kbhit())
			break;
		Sleep(30);
	}
	
	getche();
	system("cls");
	return 0;
}

int show_stage()
{
	gotoxy(28,8);
	printf("��������������������������");
	gotoxy(28,9);
	printf("��       level %2d       ��",level+1);
	gotoxy(28,10);
	printf("��������������������������");
	Sleep(1000);
	//fflush(stdin);
	
	return 0;
}
int input_data()
{
	int i;
	gotoxy(10,3);
	printf("���� ���̵��� �������ּ���[1-8]:");
	scanf("%d",&i);
	level = i-1;
	system("cls");
	return 0;
}