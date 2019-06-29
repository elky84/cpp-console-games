// sudoku.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define BOARD_SIZE 9
int prt_mat(int ve,int ho,int y,int x);
int empty_count(char count[10]);	//ī��Ʈ �迭�� �ʱ�ȭ(���� �ߺ��� Ȯ��)
int expect_count(char *count,int* solve);	//���ڸ� ���ɼ����� ������ ī��Ʈ

char mat[BOARD_SIZE+1][BOARD_SIZE+1][BOARD_SIZE+1];
char rem_num[BOARD_SIZE+1];	//�� ���ڸ��� ����Ҽ� �ִ� Ƚ���� ����
char rem_num_tmp[BOARD_SIZE+1];

int main(int argc, char* argv[])
{
	
	char count[10];
	int i,j,k,l,m,n,o;
	int solve;	//��ĭ�� ���ɼ���(��)�� 1��(����)�϶��� �׼��ڰ�(��)
	char tmp;
	


	
				

	printf("\nSudokun Ver0.01  Made By Rabe\n(http://rabe.egloos.com)\n");
	
	while(1)
	{
		
		for(i=0;i<=BOARD_SIZE;i++)	//mat�迭�� �ʱ�ȭ
			for(j=0;j<=BOARD_SIZE;j++)
				for(k=0;k<=BOARD_SIZE;k++)
					mat[i][j][k]=0;

		for(i=1;i<=BOARD_SIZE;i++)	//rem_num�迭�� �ʱ�ȭ
			rem_num[i]=BOARD_SIZE;
		
		printf("insert sudoku\n");
		for(i=1;i<=9;i++)	//������ �Է¹޴� �κ�
		{
			for(j=1;j<=9;j++)
			{
				fflush(stdin);
				printf("(x=%d y=%d)->",j,i);
				tmp = getch();
				mat[i][j][0] = (tmp - 0x30);
				printf("%c\t",mat[i][j][0]+0x30);
				rem_num[tmp - 0x30]--;
				prt_mat(9,9,i,j);
			}
		}
		
		for(o=0;o<=100000;o++)	//10������ 2��~ 3������ �ɸ��� Ƚ����
		{
			empty_count(count);
			for(l=0;l<=6;l+=3)	//���簢 ��ȩĭ( 3X3 )�� ������ ���� 3�� ����
			{
				for(m=0;m<=6;m+=3)
				{
					for(i=1;i<=3;i++)
					{
						for(j=1;j<=3;j++)
						{
							if(count[ mat[l+i][m+j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
								count[ mat[l+i][m+j][0] ] = TRUE;
							else
							{
								if( mat[l+i][m+j][0] !=0 )
								{
									printf("\nGame Error!! %d\nNever Success!\n",o);	//������ �������� ����
																						//������,������,�Ǵ� 3X3���ھȿ�
																						//�ߺ��Ǵ� ���ڰ� ������
									return 1;
								}
							}
						}
						for(j=1;j<=3;j++)
						{
							if(mat[l+i][m+j][0] ==0)
								for(n=1;n<=9;n++)
									if(count[n] == TRUE)	//mat�󿡼� �ߺ����� TRUE�� �ǵ��� count
										//���� TRUE�� �����ؼ� �Է�
										mat[l+i][m+j][n] = TRUE ;
									
						}
					}
					empty_count(count);	//���簢�� �� �˻����� ���� �˻����� 
					//�迭�� �ʱ�ȭ
				}
			}
			//������ �˻�
			empty_count(count);
			for(i=1;i<=9;i++)
			{
				for(j=1;j<=9;j++)
				{
					if(count[ mat[i][j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
						count[ mat[i][j][0] ] = TRUE;
					else
					{
						if( mat[i][j][0] != 0 )
						{
							printf("\nGame Error!! 2\nNever Success!\n");	//������ �������� ����
							return 1;
						}
					}
				}
				for(j=1;j<=9;j++)
				{
					if(mat[i][j][0] ==0)
						for(n=1;n<=9;n++)
							if(count[n] == TRUE)
								mat[i][j][n] = TRUE ;
							
				}
				empty_count(count);
			}
			
			
			//������ �˻�
			empty_count(count);
			for(j=1;j<=9;j++)
			{
				for(i=1;i<=9;i++)
				{
					if(count[ mat[i][j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
						count[ mat[i][j][0] ] = TRUE;
					else
					{
						if( mat[i][j][0] != 0 )
						{
							printf("\nGame Error!! 3\nNever Success!\n");	//������ �������� ����
							return 1;
						}
					}
				}
				for(i=1;i<=9;i++)
				{
					if(mat[i][j][0] ==0)
						for(n=1;n<=9;n++)
							if(count[n] == TRUE)
								mat[i][j][n] = TRUE ;
							
				}
				empty_count(count);
			}

			for(i=1;i<=BOARD_SIZE;i++)	//rem_num�迭�� �ʱ�ȭ
				rem_num_tmp[i]=rem_num[i];
			for(i=1;i<=9;i++)
			{
				for(j=1;j<=9;j++)
				{
					n=expect_count(&(mat[i][j][0]),&solve);
					
					if(n==1)
					{
						mat[i][j][0] = solve;	//������ �迭�� �Է�
						//printf("\n\n  insert mat[%d][%d] in %d \n",i,j,solve);

						rem_num_tmp[solve]--;
					}
					
					//printf("=  %d  =\n",n);
				}
			}
	}
	
	prt_mat(9,9,5,5);
	
	printf("Please Any Key to Reset\n");
	getch();
	}
	
	return 0;
}

int prt_mat(int ve,int ho,int y,int x)	//�迭�� ���
{
	int i,j;
	printf("\n");
	for(i=1;i<=ve;i++)
	{
		for(j=1;j<=ho;j++)
		{

			if(i==y&&j==x)
				printf("<%c>",(char)(mat[i][j][0]+0x30));
			else	
				printf("%c  ",(char)(mat[i][j][0]+0x30));

			
			if( j%3==0 )
				printf("  ");
		}
		if( i%3==0 )
			printf("\n\n\n");
		else
			printf("\n");
	}

	//rem_num�迭�� ���
	printf("\n");

	for(i=1;i<=BOARD_SIZE;i++)
		printf("%d:%d ",i,rem_num[i]);
	printf("\n");
	for(i=1;i<=BOARD_SIZE;i++)
		printf("%d:%d ",i,rem_num_tmp[i]);

	printf("\n");
	return 0;
	
}

int empty_count(char count[10])
{
	int i;
	for(i=0;i<=9;i++)
		count[i] = FALSE;
	return 0;
}

int expect_count(char *count,int* solve)
{
	int cnt=0;	//���ڸ� ���� ����
	int i;
	for(i=1;i<=9;i++)
	{
		//printf("%d  %d \t",count[0],*(count+i) );
		if( *(count+i) != TRUE)
		{
			cnt++;
			*solve = i;
		}
	}
	return cnt;
}

