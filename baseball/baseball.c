//*****************************************************************
//	digit baseball
//	Made by 'k-net 9th' Jae-Dong
//	E-Mail: pjd@kw.ac.kr
//  Blog: rabe.egloos.com
//*****************************************************************

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
	int i,j;
	int ball,strike,try_count;
	char answer[4],input[4];
	char choice='y';	
	srand(time(NULL));	//���� �õ尪 �Է�

	while(choice != 'n')
	{
		
		try_count=1;
		while(1)	//�ߺ��� ���ڰ� ������ ��� ���ڸ� ����
		{
			for(i=0;i<3;i++)
				answer[i] = rand()%10 +0x30;	//�������� int������ �ƽ�Ű�ڵ�� ���̾������
			if( (answer[0] == answer[1]) || (answer[1] == answer[2]) || (answer[2] == answer[0]))
				continue;
			else
				break;
		}

		printf("�����Է�");
		while(1)
		{
			ball = 0;
			strike = 0;
			printf("\n%d��°�õ� ->",try_count);
			scanf("%s",input);
			for(i=0;i<3;i++)	//��ȼ��ڿ� �Է¼��ڿ� ���� ���� ���ڰ� �ִ��� �˻�
				for(j=0;j<3;j++)
				{
					if( answer[i] == input[j])
					{
						ball++;
						if(i==j)
							strike++;
					}
				}
			ball -= strike;	//ball�� ������ strike�� ���� �ߺ��Ǿ� �����Ƿ� strkie ���� ���ش�.
			if(strike)
				printf("%dS ",strike);
			if(ball)
				printf("%dB",ball);
			if((strike | ball)==0)
				printf("OUT");
			if(strike==3)
				break;
			try_count++;
		}
		printf("\n������ϴ�.\n�ٽ� �Ͻðڽ��ϱ�?(y/n)");
		fflush(stdin);	//�Է½�Ʈ���� �����.
		scanf("%c",&choice);
	}

}
