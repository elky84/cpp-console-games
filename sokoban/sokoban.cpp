//*****************************************************************
//	Sokoban Ver 0.1
//	Made by Jae-Dong
//	E-Mail: pjd@kw.ac.kr
//	Blog: rabe.egloos.com
//*****************************************************************

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>
#include <string.h>
//*********************************
//상수 선언
//*********************************
#define STAGE_DATA_FILE "sokoban.dat"
#define MAX_STAGE 200
#define EXT_KEY			0xffffffe0	//확장키 인식값 
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
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

//*********************************
//구조체 선언
//*********************************
typedef struct _stage{		
	char	map[20][20];
	int pos_x;	//캐릭터의 x좌표
	int pos_y;
}STAGE;

//*********************************
//전역변수선언
//*********************************
int g_pos_x,g_pos_y;	//현재 캐릭터의 좌표값
int g_stage;	//현재 스테이지 번호 1부터 시작
int g_max_stage;	//최대 스테이지 번호 1부터 시작
int g_step=1;	//움직인 횟수
STAGE rev_stage[2000];	//되돌리기 기능을 위한 임시저장 영역의 포인터정보
STAGE stage_data[MAX_STAGE];	//스테이지 최초정보 저장


//*********************************
//함수 선언
//*********************************
int init();					//각종변수 초기화
void logo();			//시작로고
int show_stage(STAGE *p_stage,int all_load);	//stage를 화면에 출력 all_load가 1이면 벽도 출력
int gotoxy(int x,int y);	//커서옮기기
int check_success(STAGE *p_stage); //스테이지를 끝냈는지 검사
int show_frame(int start_col,int all_load);	//화면 오른쪽의 상태창출력 all_load가 1이면 모두출력 0이면 변수만출력
int show_success();

void SetColor(int color);	//색표현

int main(int argc, char* argv[])
{
	int i;
	int is_changed=0;
	char keytemp;
	int stage_max_width=0;
	STAGE cur_stage;	//현재 화면에 표시되는 정보
	init();
	logo();
	gotoxy(12,12);
	printf("Input Start Stage[ 1 - %d ]:",g_max_stage);
	scanf("%d",&g_stage);
	g_stage--;

	if( g_stage <0)
		g_stage = 0 ;
	if( g_stage > g_max_stage)
		g_stage = g_max_stage ;

	SetColor(GRAY);
	cur_stage = stage_data[g_stage];
	rev_stage[0] = cur_stage;
	g_pos_x = cur_stage.pos_x;
	g_pos_y = cur_stage.pos_y;

	stage_max_width=show_stage(&cur_stage,1);
	show_frame(stage_max_width,1);
	for(i=1;1;i++)
	{
		if(kbhit())
		{
			keytemp = getche();
			if(keytemp == EXT_KEY)
			{
				keytemp = getche();
				switch(keytemp)
				{
				case KEY_UP:	//위로이동
					if(cur_stage.map[g_pos_y-1][g_pos_x] == '#')
						break;
					if(cur_stage.map[g_pos_y-1][g_pos_x] == ' ' || cur_stage.map[g_pos_y-1][g_pos_x] == '.')
					{
						g_pos_y--;
						is_changed=1;
						break;
					}
					if(cur_stage.map[g_pos_y-2][g_pos_x] == ' ' || cur_stage.map[g_pos_y-2][g_pos_x] == '.')
					{
						if(cur_stage.map[g_pos_y-2][g_pos_x] == ' ')
							cur_stage.map[g_pos_y-2][g_pos_x] = '$';
						else
							cur_stage.map[g_pos_y-2][g_pos_x] = '*';

						if(cur_stage.map[g_pos_y-1][g_pos_x] == '$')
							cur_stage.map[g_pos_y-1][g_pos_x] = ' ';
						else
							cur_stage.map[g_pos_y-1][g_pos_x] = '.';

						g_pos_y--;
						is_changed=1;
						break;
					}
					break;
				case KEY_LEFT:		//왼쪽으로 이동
					if(cur_stage.map[g_pos_y][g_pos_x-1] == '#')
						break;
					if(cur_stage.map[g_pos_y][g_pos_x-1] == ' ' || cur_stage.map[g_pos_y][g_pos_x-1] == '.')
					{
						g_pos_x--;
						is_changed=1;
						break;
					}
					if(cur_stage.map[g_pos_y][g_pos_x-2] == ' ' || cur_stage.map[g_pos_y][g_pos_x-2] == '.')
					{
						if(cur_stage.map[g_pos_y][g_pos_x-2] == ' ')
							cur_stage.map[g_pos_y][g_pos_x-2] = '$';
						else
							cur_stage.map[g_pos_y][g_pos_x-2] = '*';

						if(cur_stage.map[g_pos_y][g_pos_x-1] == '$')
							cur_stage.map[g_pos_y][g_pos_x-1] = ' ';
						else
							cur_stage.map[g_pos_y][g_pos_x-1] = '.';

						g_pos_x--;
						is_changed=1;
						break;
					}
					break;
				case KEY_RIGHT:		//오른쪽으로 이동
					if(cur_stage.map[g_pos_y][g_pos_x+1] == '#')
						break;
					if(cur_stage.map[g_pos_y][g_pos_x+1] == ' ' || cur_stage.map[g_pos_y][g_pos_x+1] == '.')
					{
						g_pos_x++;
						is_changed=1;
						break;
					}
					if(cur_stage.map[g_pos_y][g_pos_x+2] == ' ' || cur_stage.map[g_pos_y][g_pos_x+2] == '.')
					{
						if(cur_stage.map[g_pos_y][g_pos_x+2] == ' ')
							cur_stage.map[g_pos_y][g_pos_x+2] = '$';
						else
							cur_stage.map[g_pos_y][g_pos_x+2] = '*';

						if(cur_stage.map[g_pos_y][g_pos_x+1] == '$')
							cur_stage.map[g_pos_y][g_pos_x+1] = ' ';
						else
							cur_stage.map[g_pos_y][g_pos_x+1] = '.';

						g_pos_x++;
						is_changed=1;
						break;
					}
					break;
				case KEY_DOWN:		//아래로 이동
					if(cur_stage.map[g_pos_y+1][g_pos_x] == '#')
						break;
					if(cur_stage.map[g_pos_y+1][g_pos_x] == ' ' || cur_stage.map[g_pos_y+1][g_pos_x] == '.')
					{
						g_pos_y++;
						is_changed=1;
						break;
					}
					if(cur_stage.map[g_pos_y+2][g_pos_x] == ' ' || cur_stage.map[g_pos_y+2][g_pos_x] == '.')
					{
						if(cur_stage.map[g_pos_y+2][g_pos_x] == ' ')
							cur_stage.map[g_pos_y+2][g_pos_x] = '$';
						else
							cur_stage.map[g_pos_y+2][g_pos_x] = '*';

						if(cur_stage.map[g_pos_y+1][g_pos_x] == '$')
							cur_stage.map[g_pos_y+1][g_pos_x] = ' ';
						else
							cur_stage.map[g_pos_y+1][g_pos_x] = '.';

						g_pos_y++;
						is_changed=1;
						break;
					}
					break;
				}
			}else{
				if(keytemp == 32 )	//스페이스바를 눌렀을때 다시 시작
				{
					cur_stage = stage_data[g_stage];
					rev_stage[0] = cur_stage;
					g_pos_x = cur_stage.pos_x;
					g_pos_y = cur_stage.pos_y;
					g_step = 1;				
					is_changed = 1;
				}
				
				if(keytemp == 'R' || keytemp == 'r')	//되돌리기 기능
				{
					g_step -= 2;
					
					if(g_step <0)
						g_step = 0;
					
					cur_stage = rev_stage[g_step];
					g_pos_x = rev_stage[g_step].pos_x;
					g_pos_y = rev_stage[g_step].pos_y;
					is_changed = 1;
				}
				
				if(keytemp == 'N' || keytemp == 'n')
				{
					g_stage++;	//다음 stage로 넘어감
					
					if( g_stage > g_max_stage)
						g_stage--;
					g_step = 0;
					cur_stage = stage_data[g_stage];
					g_pos_x = cur_stage.pos_x;
					g_pos_y = cur_stage.pos_y;
					rev_stage[0] = cur_stage;
					stage_max_width=show_stage(&cur_stage,1);
					show_frame(stage_max_width,1);
				}
				if(keytemp == 'P' || keytemp == 'p')	//이전 stage로 넘어감
				{
					g_stage--;	//다음 stage로 넘어감
					
					if( g_stage < 0)
						g_stage=0;
					g_step = 0;
					cur_stage = stage_data[g_stage];
					g_pos_x = cur_stage.pos_x;
					g_pos_y = cur_stage.pos_y;
					rev_stage[0] = cur_stage;
					stage_max_width=show_stage(&cur_stage,1);
					show_frame(stage_max_width,1);
				}
			}
		}
		
		
		if(check_success(&cur_stage))
		{
			show_stage(&cur_stage,0);
			show_success();
			g_stage++;	//다음 stage로 넘어감
			
			if( g_stage >= g_max_stage)
				g_stage--;
			g_step = 0;
			cur_stage = stage_data[g_stage];
			g_pos_x = cur_stage.pos_x;
			g_pos_y = cur_stage.pos_y;
			rev_stage[0] = cur_stage;
			stage_max_width=show_stage(&cur_stage,1);
			show_frame(stage_max_width,1);
		}
		if(is_changed == 1)
		{
			rev_stage[g_step] = cur_stage;
			rev_stage[g_step].pos_x = g_pos_x;
			rev_stage[g_step].pos_y = g_pos_y;
			show_stage(&cur_stage,0);
			show_frame(stage_max_width,0);
			is_changed = 0;
			g_step++;
		}
		fflush(stdin);
		SetColor(BLACK);
		Sleep(15);
		
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
	FILE *fp;
	char buf[50];
	int stage_seq=-1;
	int row=0;
	int i,j;
	fp = fopen(STAGE_DATA_FILE,"r");
	while( !feof(fp))
	{
		fgets(buf,49,fp);
		if(buf[0] == ';')	//스테이지의 시작
		{
			for(i=0;i<20;i++)	//시작위치 찾기
			{
				for(j=0;j<20;j++)
				{
					if(	stage_data[stage_seq].map[i][j] == '@' || stage_data[stage_seq].map[i][j] == '+')
					{
						stage_data[stage_seq].pos_y = i;
						stage_data[stage_seq].pos_x = j;
						i=20;	//루프 탈출
						break;
					}

				}
			}
			row=0;
			stage_seq++;
			continue;
		}
		if(stage_seq >=0 && buf[0] != '\n')
		{
			strncpy(stage_data[stage_seq].map[row],buf,strlen(buf)-1);
		}
		row++;
	}
	for(i=0;i<stage_seq;i++)
	{
		if(stage_data[i].map[stage_data[i].pos_y][stage_data[i].pos_x] == '@')
			stage_data[i].map[stage_data[i].pos_y][stage_data[i].pos_x] = ' ';
		if(stage_data[i].map[stage_data[i].pos_y][stage_data[i].pos_x] == '+')
			stage_data[i].map[stage_data[i].pos_y][stage_data[i].pos_x] = '.';
	}
	g_max_stage = stage_seq;
	return 0;
}

int show_stage(STAGE *p_stage,int all_load)
{
	int i,j;
	int max_width=0;
	if( all_load ==1)
		system("cls");

	for(i=0;i<20;i++)
	{
		printf("  ");
		for(j=0;j<20;j++)
		{
			
			if( i == g_pos_y && j == g_pos_x )
			{
				gotoxy(j*2+2,i+2);
				SetColor(SKY_BLUE);
				printf("★");
			}
			else{
				switch(p_stage->map[i][j])
				{
				case '#':	//벽일때
					if(all_load == 1)
					{
						gotoxy(j*2+2,i+2);
						SetColor(WHITE);
						printf("▩");

						if( j >max_width)
							max_width = j;

					}
					break;
				//case '@':
				case '.':	//상자를 놓는 장소(현재 빈상태)
					SetColor(WHITE);
					gotoxy(j*2+2,i+2);
					printf("○");
					break;
				case '$':	//상자
					SetColor(RED);
					gotoxy(j*2+2,i+2);
					printf("●");
					break;
				//case '+':
				case '*':	//상자를 놓는 장소(현재 상자가 놓인 상태)
					SetColor(GREEN);
					gotoxy(j*2+2,i+2);
					printf("◎");
					break;
				case 0:
					if(all_load == 1)
					{
						gotoxy(j*2+2,i+2);
						printf("  ");
					}
					break;
				case ' ':	//공백
					gotoxy(j*2+2,i+2);
					printf("  ");
					break;
				}
			}

			

		}
		printf("\n");
	}
	return max_width*2+5;
}

void logo()
{
	int i;
	SetColor(WHITE*16);
	for(i=2;i<11;i++)
	{
		gotoxy(4,i);
		printf("                                                                          ");
		Sleep(50);
	}
	SetColor(BLUE*16);
	//첫째줄
	gotoxy(6,3);
	printf("          ");
	gotoxy(28,3);
	printf("    ");
	gotoxy(48,3);
	printf("    ");
	Sleep(50);

	//둘째줄
	gotoxy(6,4);
	printf("  ");
	gotoxy(14,4);
	printf("  ");
	gotoxy(28,4);
	printf("  ");
	gotoxy(48,4);
	printf("  ");
	Sleep(50);

	//셋째줄
	gotoxy(6,5);
	printf("  ");
	gotoxy(28,5);
	printf("  ");
	gotoxy(48,5);
	printf("  ");
	gotoxy(58,5);
	printf("        ");
	gotoxy(68,5);
	printf("  ");
	Sleep(50);

	//넷째줄
	gotoxy(6,6);
	printf("          ");
	gotoxy(18,6);
	printf("        ");
	gotoxy(28,6);
	printf("  ");
	gotoxy(32,6);
	printf("    ");
	gotoxy(38,6);
	printf("        ");
	gotoxy(48,6);
	printf("        ");
	gotoxy(64,6);
	printf("  ");
	gotoxy(68,6);
	printf("        ");
	Sleep(50);

	//다섯째줄
	gotoxy(14,7);
	printf("  ");
	gotoxy(18,7);
	printf("  ");
	gotoxy(24,7);
	printf("  ");
	gotoxy(28,7);
	printf("    ");
	gotoxy(38,7);
	printf("  ");
	gotoxy(44,7);
	printf("  ");
	gotoxy(48,7);
	printf("  ");
	gotoxy(54,7);
	printf("  ");
	gotoxy(58,7);
	printf("        ");
	gotoxy(68,7);
	printf("  ");
	gotoxy(74,7);
	printf("  ");
	Sleep(50);

	//여섯째줄
	gotoxy(6,8);
	printf("  ");
	gotoxy(14,8);
	printf("  ");
	gotoxy(18,8);
	printf("  ");
	gotoxy(24,8);
	printf("  ");
	gotoxy(28,8);
	printf("  ");
	gotoxy(32,8);
	printf("  ");
	gotoxy(38,8);
	printf("  ");
	gotoxy(44,8);
	printf("  ");
	gotoxy(48,8);
	printf("  ");
	gotoxy(54,8);
	printf("  ");
	gotoxy(58,8);
	printf("  ");
	gotoxy(64,8);
	printf("  ");
	gotoxy(68,8);
	printf("  ");
	gotoxy(74,8);
	printf("  ");
	Sleep(50);

	//일곱째줄
	gotoxy(6,9);
	printf("          ");
	gotoxy(18,9);
	printf("        ");
	gotoxy(28,9);
	printf("  ");
	gotoxy(34,9);
	printf("  ");
	gotoxy(38,9);
	printf("        ");
	gotoxy(48,9);
	printf("        ");
	gotoxy(58,9);
	printf("        ");
	gotoxy(68,9);
	printf("  ");
	gotoxy(74,9);
	printf("  ");
	Sleep(50);

	SetColor(GRAY);
	gotoxy(31,15);
	printf("Sokoban Ver 0.1");
	gotoxy(30,17);
	printf("Made By Jae-Dong");
	gotoxy(28,19);
	printf("http://rabe.egloos.com");
	SetColor(GRAY*16+DARK_VOILET);
	gotoxy(26,22);
	printf("  Please press Any Key~!  ");
	gotoxy(38,23);

	fflush(stdin);
	Sleep(1000);
	getche();
	system("cls");
}

int check_success(STAGE *p_stage)
{
	int i,j;
	for(i=0;i<20;i++)
	{
		for(j=0;j<20;j++)
		{
			if(p_stage->map[i][j] == '.' || p_stage->map[i][j] == '$')	//빈돌이나 빈구멍이 있을때
				return 0; //실패
		}
	}
	return 1;//성공
}

int show_frame(int start_col,int all_load)
{
	if(all_load ==1)
	{
		SetColor(WHITE);
		gotoxy(start_col,1);
		printf("┏━━━━━━━━┓");
		gotoxy(start_col,2);
		printf("┃ Sokoban Ver0.1 ┃");
		gotoxy(start_col,3);
		printf("┃Made by Jae-dong┃");
		gotoxy(start_col,4);
		printf("┃rabe.egloos.com ┃");
		gotoxy(start_col,5);
		printf("┣━━━━━━━━┫");
		gotoxy(start_col,6);
		printf("┃ Stage          ┃");
		gotoxy(start_col,7);
		printf("┃                ┃");
		gotoxy(start_col,8);
		printf("┃ Step  :        ┃");
		gotoxy(start_col,9);
		printf("┣━━━━━━━━┫");
		gotoxy(start_col,10);
		printf("┃      Help      ┃");
		gotoxy(start_col,11);
		printf("┃↑↓←→ : Move ┃");
		gotoxy(start_col,12);
		printf("┃ N : Next Stage ┃");
		gotoxy(start_col,13);
		printf("┃ P : Pre  Stage ┃");
		gotoxy(start_col,14);
		printf("┃ R : Rewind step┃");
		gotoxy(start_col,15);
		printf("┃ Space: Restart ┃");
		gotoxy(start_col,16);
		printf("┗━━━━━━━━┛");
	}
	SetColor(GREEN);
	gotoxy(start_col+9,6);
	printf("%3d/%-3d",g_stage+1,g_max_stage+1);
	SetColor(YELLOW);
	gotoxy(start_col+12,8);
	printf("%-4d",g_step-1);
	gotoxy(0,0);
	return 0;
}

int show_success()
{
	SetColor(VOILET);
	gotoxy(10,5);
	printf(" ┏━━━━━━━━━━┓");
	gotoxy(10,6);
	printf(" ┃********************┃");
	gotoxy(10,7);
	printf(" ┃  congratulation !  ┃");
	gotoxy(10,8);
	printf(" ┃********************┃");
	gotoxy(10,9);
	printf(" ┗━━━━━━━━━━┛");
	Sleep(2000);
	return 0;
}