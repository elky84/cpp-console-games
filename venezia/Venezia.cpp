//*****************************************************************
//	venezia Ver 0.1
//	Made by 'k-net 9th' Jae-Dong
//	E-Mail: pjd@kw.ac.kr
//*****************************************************************

#include "stdafx.h"
#include <conio.h>
#include <string.h>
//***********************************
//상수선언
//***********************************
#define WORD_FILENAME "WORD.KOR"
//***********************************
//구조체선언
//***********************************
struct STAGE{
	int delay;
	int frequency;	//0~99까지의 임의의수중 0에서 몇개까지의 숫자일때 문제가 출제되는지 결정
};
struct STAGE_WORD{
	int is_empty;	//비었으면 1 안비었으면 0;
	int x;
	int y;
	int len;
	char *str;		//
};


enum { 
	
		BLACK,      /*  0 : 까망 */ 
		DARK_BLUE,    /*  1 : 어두운 파랑 */ 
		DARK_GREEN,    /*  2 : 어두운 초록 */ 
		DARK_SKY_BLUE,  /*  3 : 어두운 하늘 */ 
		DARK_RED,    /*  4 : 어두운 빨강 */ 
		DARK_VOILET,  /*  5 : 어두운 보라 */ 
		DARK_YELLOW,  /*  6 : 어두운 노랑 */ 
		GRAY,      /*  7 : 회색 */ 
		DARK_GRAY,    /*  8 : 어두운 회색 */ 
		BLUE,      /*  9 : 파랑 */ 
		GREEN,      /* 10 : 초록 */ 
		SKY_BLUE,    /* 11 : 하늘 */ 
		RED,      /* 12 : 빨강 */ 
		VOILET,      /* 13 : 보라 */ 
		YELLOW,      /* 14 : 노랑 */ 	
		WHITE,      /* 15 : 하양 */ 
		
}; 

//***********************************
//전역변수 선언
//***********************************
char word[3000][9];
int total_word;		//단어의 총 수 
char input_buf[100];
static int input_buf_index;	//입력 버퍼의 인덱스 
int score;
int life;
int level;
int correct_word;	//정확히 맞춘 단어의 개수, 레벨업을 할때 사용
struct STAGE level_data[8];
struct STAGE_WORD stage_worddata[20];

//*********************
//함수 proto type 선언
//*********************
int gotoxy(int x,int y);
void SetColor(int color);
int init();	//파일로부터 단어를 불러들이고 각종 변수초기화
int show_stage();	//스테이지의 시작을 출력
int show_gameover();
int show_logo();
int show_word();		//화면에 진행중인 단어를 표시
int show_stat();		//게임상의 점수와 라이프표시를 갱신
int input_data();
int show_gameframe();  //게임틀 출력
int next_step_word();	//단어가 한칸씩내려옴
int make_word();
int strike_check_str();	//단어가 바닥에 닿았는지 검사.
int check_str();		//입력한 단어가 화면에 있는 단어와 일치한지 검사

int main(int argc, char* argv[])
{

	int tmp1;
	int i;
	if(init())
		return 1;	//파일오픈에러로 프로그램 종료



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
			if(tmp1==32 || tmp1== 13)	//스페이스를 눌렀을때
			{
				input_buf[input_buf_index-1] = NULL;
				check_str();
				input_buf_index=0;
				input_buf[0]=NULL;
				gotoxy(33,21);
				printf("                ");
			}
			if(tmp1==8)	// 빽 스페이스를 눌렀을때
			{
				input_buf_index--;
				input_buf_index--;
				if(input_buf_index>0)
					input_buf_index--;
				if((input_buf_index>1) && (input_buf[input_buf_index]>127))	//한글일 경우 한바이트를 더삭제
					input_buf_index--;
				
				if(input_buf_index <0)
					input_buf_index=0;
				gotoxy(33,21);
				printf("                ");
				fflush(stdout);
			}
			
		}
		
		if(i%level_data[level].delay==0)	//단어를 화면상에서 한칸씩내림
		{
			next_step_word();
			if( (rand()%100)<(level_data[level].frequency) )	//레벨에따른 단어생성 확률로 단어를 만들어낼지 결정
			{
				make_word();
				
			}
			strike_check_str();	//바닥에 내려온 단어를검사
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

	//파일로부터 단어 읽어들이기
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

	//랜덤 seed값 넣기
	srand((unsigned)time(NULL));  

	//각종변수 초기화
	score=0;
	life=9;
	level=0;
	input_buf_index=0;
	correct_word=0;
	level_data[0].delay=140;		//각 스테이지마다 난이도를 조절할수 있다.
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

	make_word();	//시작하자마자 화면에 단어를 하나 만듬
	return 0;
}

int make_word()
{
	int i;
	for(i=0;i<20;i++)
	{
		if(stage_worddata[i].is_empty)
		{
			stage_worddata[i].is_empty=0;	//빈공간이 아님을 알림
			stage_worddata[i].str = word[rand()%total_word];	//랜덤으로 게임상에 넣을 단어를 생성
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

			//잔상지우기
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
				
				//잔상지우기
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
	printf("┏━━━━━━━━━━━━━━━━┓");
	gotoxy(25,9);
	printf("┃********************************┃");
	gotoxy(25,10);
	printf("┃*           GAME OVER          *┃");
	gotoxy(25,11);
	printf("┃********************************┃");
	gotoxy(25,12);
	printf("┗━━━━━━━━━━━━━━━━┛");
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
			printf("■");
		else
			printf("□");
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

		if(strcmp(input_buf,stage_worddata[i].str) == 0)	//화면에있는 단어를 제대로 쳤을경우
		{
					
			stage_worddata[i].is_empty=1;
			score += (stage_worddata[i].len*10)+(rand()%10);
			gotoxy(stage_worddata[i].x,stage_worddata[i].y);
			printf("%*s",stage_worddata[i].len," ");
			show_stat();
			
			correct_word++;	//정확히맞춘단어의 개수
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
		printf("━");

	gotoxy(0,24);
	for(i=0;i<78;i+=2)
		printf("━");

	gotoxy(31,20);
	printf("┏━━━━━━━━┓");
	gotoxy(31,21);
	printf("┃                ┃");
	gotoxy(31,22);
	printf("┗━━━━━━━━┛");

	gotoxy(32,23);
	for(i=0;i<9;i++)
	{
		if(i<life)
			printf("■");
		else
			printf("□");
	}
	return 0;
}

int show_logo()
{
	int i,j,k=0;
	char intro_text[31][50]={"","","","","","당신은 베네치아를 아십니까?",
							"아름다운 물의도시 베니스가 있는",
							"이탈리아 북부의 베네치아",
							"시인들에게는 아름다운 노래를",
							"철할자들에게는 깊은 사색을 그리고",
							"연인들에게는 달콤한 사랑을 낳게한곳...",
							"서기2020년",
							"오랜세월 바닷물에의한 침식과 부식으로",
							"다른 건물들은 자취를 감추고, 화려했던",
							"추억과 마지막희망을 안은채 하나의",
							"탑만이 물위에 남아 있습니다. 그런데,",
							"이 베네치아의 하늘에",
							"'바이러스 군단'이 나타납니다.",
							"하늘에서 떨어지는 이 바이러스들은",
							"물속에 떨어지거나 탑에 떨어지는순간",
							"탑을 지탱하고 있던 벽돌이",
							"하나씩 하나씩 깨뜨려 집니다.",
							"탑을 지탱하고 있던 벽돌이 모두 깨어지면",
							"우리의 사랑과 희망을 지닌 마지막 탑마져",
							"물속으로 사라지고 말것입니다.",
							"'베네치아를 사수하라'",
							"이제 베네치아를 지킬 마지막 소임이 바로",
							"당신의 손에 쥐어져 있습니다.",
							"바이러스를 막아 부디 베네치아를 무사히",
							"지켜 주십시오.",
							"행운을 빕니다!"};
	gotoxy(13,3);
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━┓");
	Sleep(500);
	gotoxy(13,4);
	printf("┃┃  ┃┃┃  ┃    ┃┃  ━┻━━┃ ↙━↘ ┃  ┃");
	Sleep(500);
	gotoxy(13,5);
	printf("┃┣━┫┫┃  ┃    ┫┃      ↙  ┃ ┃  ┃ ┣  ┃");
	Sleep(500);
	gotoxy(13,6);
	printf("┃┃  ┃┃┃  ┃    ┃┃    ↙↘  ┃ ┃  ┃ ┃  ┃");
	Sleep(500);
	gotoxy(13,7);
	printf("┃┗━┛┃┃  ┗━━┃┃  ↙    ↘┃ ↘━↙ ┃  ┃");
	Sleep(500);
	gotoxy(13,8);
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━┛");
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
	printf("┏━━━━━━━━━━━┓");
	gotoxy(28,9);
	printf("┃       level %2d       ┃",level+1);
	gotoxy(28,10);
	printf("┗━━━━━━━━━━━┛");
	Sleep(1000);
	//fflush(stdin);
	
	return 0;
}
int input_data()
{
	int i;
	gotoxy(10,3);
	printf("시작 난이도를 설정해주세요[1-8]:");
	scanf("%d",&i);
	level = i-1;
	system("cls");
	return 0;
}