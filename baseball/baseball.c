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
	srand(time(NULL));	//랜덤 시드값 입력

	while(choice != 'n')
	{
		
		try_count=1;
		while(1)	//중복된 숫자가 없도록 답안 숫자를 생성
		{
			for(i=0;i<3;i++)
				answer[i] = rand()%10 +0x30;	//생성값을 int형에서 아스키코드로 바이어싱해줌
			if( (answer[0] == answer[1]) || (answer[1] == answer[2]) || (answer[2] == answer[0]))
				continue;
			else
				break;
		}

		printf("숫자입력");
		while(1)
		{
			ball = 0;
			strike = 0;
			printf("\n%d번째시도 ->",try_count);
			scanf("%s",input);
			for(i=0;i<3;i++)	//답안숫자와 입력숫자와 같은 값의 숫자가 있는지 검사
				for(j=0;j<3;j++)
				{
					if( answer[i] == input[j])
					{
						ball++;
						if(i==j)
							strike++;
					}
				}
			ball -= strike;	//ball의 값에는 strike의 값이 중복되어 있으므로 strkie 값을 빼준다.
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
		printf("\n맞췄습니다.\n다시 하시겠습니까?(y/n)");
		fflush(stdin);	//입력스트림을 비워줌.
		scanf("%c",&choice);
	}

}
