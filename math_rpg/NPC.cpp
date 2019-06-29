#include "Library.h"

int questList[20] = {0,};

void CheckNPC(int x, int y) {
	int mapID = GetMapID();
	if(GetMapEntry(mapID, x, y-1) == NPC)
		ChatNPC(mapID,x,y-1);
	if(GetMapEntry(mapID, x, y+1) == NPC)
		ChatNPC(mapID,x,y+1);
	if(GetMapEntry(mapID, x-1, y) == NPC)
		ChatNPC(mapID,x-1,y);
	if(GetMapEntry(mapID, x+1, y) == NPC)
		ChatNPC(mapID,x+1,y);
	if(x == 1 && y == 1)	// 치트
		ChatNPC(mapID,x,y);
}

void Talk_NPC(char name[], char chat[]) {
	SetColor(SKY_BLUE,BLACK);
	gotoxy(1,21);
	printf("%s : %s", name, chat);
	system("pause>nul");
	gotoxy(1,21);
	printf("                                                                                             ");
	SetColor(WHITE,BLACK);
}

void Talk_Player(char chat[]) {
	SetColor(GREEN,BLACK);
	gotoxy(1,21);
	PrintMyName(); printf(" : %s", chat);
	system("pause>nul");
	gotoxy(1,21);
	printf("                                                                                             ");
	SetColor(WHITE,BLACK);
}

void Talk_System(char chat[]) {
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("안내 : %s", chat);
	system("pause>nul");
	gotoxy(1,21);
	printf("                                                                                             ");
}

void Talk_Mob(char chat[]) {
	SetColor(WHITE,BLACK);
	gotoxy(1,21);
	printf("%s", chat);
	getche();
	gotoxy(1,21);
	printf("                                                                                             ");
}

void ChatNPC(int ID, int x, int y) {
	char str[50];
	int num;

	if(ID == 0) {
		if(x==5 && y==2) {
			char nameNPC[] = "와쿠";
			switch(questList[0]) {
			case 0:
				Talk_NPC(nameNPC,"저기, 잠깐 나좀 도와주지 않을레?");
				Talk_Player("....? 무슨일인데?");
				Talk_NPC(nameNPC,"내가 3이 필요한데 지금 가진게 + 연산자밖에 없거든");
				Talk_NPC(nameNPC,"그러니까 1과 2를 가져다 주지 않을레? 아마 내 옆에 우키에게 물어보면 알거야");
				Talk_Player("알았어, 내가 가져다 줄게");
				questList[0] = 1;
				break;
		
			case 1:
				Talk_NPC(nameNPC,"1과 2를 구하려면 내 옆에 우키에게 물어보도록 해");
				Talk_Player("응 (바로옆에 또다른 녀석에게 가보자)");
				break;
		
			case 2:
				Talk_Player("자, 여기 1과 2를 가져왔어");
				Talk_NPC(nameNPC,"고마워! 대신 너에게 선물로 이 + 연산자를 줄게");
				Talk_Player("아... 고마워 (아싸 땡잡음 ㅋㅋ)");
				Talk_System("+ 연산자를 얻었다.");
				Talk_System("경험치를 10 획득했다.");
				PopItem('1');
				PopItem('2');
				PushItem('+');
				ShowState();
				questList[0] = -1;
				EarnExp(10);
				break;
			case -1:
				Talk_NPC(nameNPC,"안녕. 공부는 잘되가지?");
				break;		
			}
		}
		if(x==10 && y==2) {
			char nameNPC[] = "우키";
			switch(questList[0]) {
			case 0:
				Talk_NPC(nameNPC,"역시 개발자 녀석은 귀차니즘이 심한 것 같군...");
				Talk_Player("(말을 걸어도 대답이 없다. 그냥 지나가도록 하자)");
				break;

			case 1:
				Talk_Player("저기, 혹시 1과 2를 구할 수 있을까?");
				Talk_NPC(nameNPC,"1과 2? 그거라면 줄 수 있지만... 혹시 와쿠녀석의 부탁이야?");
				Talk_Player("... ㅇㅇ");
				Talk_NPC(nameNPC,"알았어, 그럼 이 숫자들을 녀석에게 가져다 주도록 해");
				Talk_Player("고마워 (다시 처음 녀석에게 가보자)");
				Talk_System("숫자 1과 2를 얻었다.");
				PushItem('1');
				PushItem('2');
				ShowState();
				questList[0]	=	2;
				break;
		
			case 2:
				Talk_NPC(nameNPC,"어서 이 숫자들을 녀석에게 가져다 주도록 해");
				Talk_Player("알았어 (어서 처음 녀석에게 가보자)");
				break;
			case -1:
				Talk_NPC(nameNPC,"안녕!!");
				Talk_Player("응 안녕!!");
				break;
			}
		}
		if(x==37 && y==5) {
			char nameNPC[] = "노소";
			switch(questList[1]) {
			case 0:
				if(questList[0] == -1) {
					Talk_NPC(nameNPC,"어이, 거기 자네");
					Talk_Player("ㅇㅇ?");
					Talk_NPC(nameNPC,"내가 방금전에 '-' 를 어딘가에 떨어뜨렸거든...");
					Talk_NPC(nameNPC,"그런데 아무레도 몬스터들이 주워가버린 것 같아...");
					Talk_NPC(nameNPC,"혹시 찾아준다면 내가 후하게 보상하지");
					Talk_Player("ㅇㅋ 그런데 어디서 찾음?");
					Talk_NPC(nameNPC,"저 길을 따라 아래쪽으로 내려가면 됨");
					Talk_Player("ㅇㅇ 내가 금방 찾아옴 (아래쪽으로 가보자)");
					questList[1] = 1;
				}
				else {
					Talk_NPC(nameNPC,"심심한데 뭐 재밌는 일 없으려나...");
					Talk_Player("......");
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"아래쪽으로 내려가면 몬스터들이 보일거야");
				Talk_Player("ㅇㅇ (어서 아래쪽으로 가보자)");
				break;
			case 2:
				Talk_Player("자, 여기 '-'를 찾아왔어");
				Talk_NPC(nameNPC,"오오 고마워! 내가 잃어버린 '-'가 맞아!");
				Talk_NPC(nameNPC,"그럼 답례를 줘야겠지?");
				EarnExp(20); Talk_System("경험치를 20 획득했다");
				PushItem('-'); Talk_System("'-'를 획득했다");
				Talk_NPC(nameNPC,"이 '-'는 답례로 너에게 주도록 하지");
				Talk_Player("아싸, 이제 '+'와 '-'를 모두 가지게 되었다!");
				questList[1] = -1;
				ShowState();
				CheckState();
				break;
			case -1:
				if(GetLevel() < 7) {
					Talk_NPC(nameNPC,"레벨 7이 되면 그때 찾아오도록 해");
					Talk_Player("ㅇㅇ. (레벨 7까지 몬스터를 사냥하자)");
				}
				break;
			}
			switch(questList[2]) {
			case 0:
				if(questList[1] == -1 && GetLevel() >= 7) {
					Talk_NPC(nameNPC,"지난번에 '-'를 찾아줬던 녀석이구나!");
					Talk_Player("아, 안녕? (설마 또 시키려는건 아니겠지...)");
					Talk_NPC(nameNPC,"혹시 시간된다면 잃어버린 '*'도 찾아주지 않을래?");
					Talk_Player("아 그게..... (하기 싫은데)");
					Talk_NPC(nameNPC,"당연히 보상은 두둑하게 줄테니까.. 경험치 50 정도?");
					Talk_Player("당장 다녀오겠습니다 ^^");
					Talk_NPC(nameNPC,"고마워 ㅋ. 아마 덧셈구역에서 좀더 내려가면 뺄셈구역이 있을거야");
					Talk_NPC(nameNPC,"그 부근에서 떨어뜨렸으니 아마 몬스터들을 잡다보면 찾을수 있을거야");
					Talk_Player("ㅇㅋ 금방 다녀옴");
					Talk_NPC(nameNPC,"그럼 기대할게");
					questList[2] = 1;
				}
				break;
			case 1:
				Talk_Player("어디로 가라고 했었지?");
				Talk_NPC(nameNPC,"마을 아래쪽 덧셈구역에서 좀더 아래쪽으로 가면 뺄셈구역이 있어");
				Talk_NPC(nameNPC,"거기서 잃어버렸으니까 아마 몬스터들이 가지고 있을거야");
				Talk_Player("알았어 (어서 뺄셈구역으로 가보자)");
				break;
			case 2:
				Talk_Player("자, 여기 '*'를 찾아왔어");
				Talk_NPC(nameNPC,"고마워! 당연히 보상을 해줘야겠지?");
				Talk_System("경험치를 50 획득했다");
				EarnExp(50);
				Talk_Player("(아싸 오늘도 땡잡았다! ㅋ)");
				Talk_NPC(nameNPC,"그리고 이 '*'는 선물로 너 줄게");
				Talk_System("아이템 '*'를 획득했다");
				PushItem('*');
				ShowState();
				questList[2] = -1;
				break;
			case -1:
				if(GetLevel() < 10) {
					Talk_NPC(nameNPC,"레벨 10이 되면 찾아와");
					Talk_Player("ㅇㅇ. (레벨 10이 될때까지 몬스터를 사냥하자)");
				}
				break;
			}
			switch(questList[3]) {
			case 0:
				if(questList[2] == -1 && GetLevel() >= 10) {
					Talk_NPC(nameNPC,"저기... 이번 한번만 더 도와주면 안될까?");
					Talk_Player("음? 지금은 조금 바쁜데...");
					Talk_NPC(nameNPC,"이번 퀘스트만 끝나면 전직퀘스트를 줄테니까..");
					Talk_Player("좋아. 혹시 이번엔 '/'를 가져오라는거야?");
					Talk_NPC(nameNPC,"눈치 챘네 ㅋ. 아마 곱하기 몬스터에게서 얻을 수 있을거야");
					Talk_Player("ㅇㅋ 그럼 다녀올게");
					Talk_NPC(nameNPC,"고마워 ㅋ. 아마 덧셈구역에서 왼쪽으로 가면 있을거야");
					Talk_NPC(nameNPC,"그럼 힘내 ㅋ");
					questList[3] = 1;
				}
				break;
			case 1:
				Talk_Player("근데 어디로 가야된다고 했지?");
				Talk_NPC(nameNPC,"마을 아래쪽 덧셈구역에서 왼쪽으로 가면 곱셈 구역이 있어");
				Talk_NPC(nameNPC,"거기서 잃어버렸으니까 아마 몬스터들이 가지고 있을거야");
				Talk_Player("알았어 (어서 곱셈 구역으로 가보자)");
				break;
			case 2:
				Talk_Player("자, 여기 '/'를 찾아왔어");
				Talk_NPC(nameNPC,"고마워! 대신 경험치를 줄게");
				Talk_System("경험치를 100 획득했다");
				EarnExp(100);
				Talk_Player("(이제 사칙연산을 마스터했다!)");
				Talk_NPC(nameNPC,"그리고 이 '/'는 선물로 너 줄게");
				Talk_System("아이템 '/'를 획득했다");
				PushItem('/');
				ShowState();
				questList[3] = -1;
				break;
			case -1:
				if(GetLevel() < 15) {
					Talk_NPC(nameNPC,"레벨 15이 되면 찾아와. 전직퀘스트를 줄게");
					Talk_Player("ㅇㅇ. (레벨 15가 될때까지 몬스터를 사냥하자)");
				}
				break;
			}
			switch(questList[4]) {
			case 0:
				if(questList[3] == -1 && GetLevel() >= 15) {
					Talk_Player("어서 전직시켜줘!");
					Talk_NPC(nameNPC,"알았어. 너무 서두르지 말라구");
					Talk_Player("레벨 15가 되면 전직시켜 주겠다며");
					Talk_NPC(nameNPC,"좋아, 그럼 내가내는 미션을 성공하면 전직시켜줄게");
					Talk_Player("미션? 그게 뭔데");
					Talk_NPC(nameNPC,"혼합구역에 가서 혼합계산 몬스터를 5마리 잡고와");
					Talk_Player("혼합계산이라.... 알았어 한번 해보지");
					Talk_NPC(nameNPC,"그럼 화이팅 ㅋ");
					questList[4] = 1;
				}
				break;
			case 1:
				Talk_Player("근데 어디로 가야된다고 했지?");
				Talk_NPC(nameNPC,"마을 아래쪽 덧셈구역에서 오른쪽으로 가면 혼합 구역이 있어");
				Talk_NPC(nameNPC,"거기서 혼합계산 몬스터 5마리를 잡아줘");
				Talk_Player("알았어 (어서 혼합 구역으로 가보자)");
				break;
			case 2:
				Talk_Player("5마리 다잡았어!");
				Talk_NPC(nameNPC,"수고했네! 그럼 전직시켜줄게");
				Talk_System("'정수'로 전직했다");
				SetMyJob("정수");
				Talk_Player("아싸! 드디어 전직했다");
				Talk_NPC(nameNPC,"그리고 선물로 약간의 경험치를 줄게");
				Talk_System("경험치를 200 획득했다");
				EarnExp(200);
				ShowState();
				questList[4] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"안녕. 그 헤어스타일 좋은데?");
				break;
			}

		}
		if(x == 2 && y == 15) {
			char nameNPC[] = "구우";
			if(GetHp() == GetMaxHp()) {
				Talk_NPC(nameNPC,"이미 체력이 만땅인걸?");
			}
			else if(GetHp() < GetMaxHp()) {
				Talk_NPC(nameNPC,"체력이 부족하구나, 기다려봐 금방 채워줄게");
				SetHpFull();
				ShowState();
				Talk_System("체력이 회복되었다");
			}
		}
		if(x == 1 && y == 1) {
			Talk_System("명령어를 입력하세요");
			gotoxy(1,21); scanf("%s %d", str, &num); fflush(stdin);
			gotoxy(1,21); printf("                                             ");
			if(strcmp(str,"Level") == 0) {
				SetLevel(num);
				CheckState();
				ShowState();
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				Talk_System("레벨 치트가 적용되었습니다");
			}
			else if(strcmp(str,"Name") == 0) {
				Talk_System("이름을 입력하세요");
				gotoxy(1,21); scanf("%s",str); fflush(stdin);
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				SetName(str);
				ShowState();
				Talk_System("이름변경 치트가 적용되었습니다");
			}
			else if(strcmp(str,"MasterKey") == 0) {
				SetMasterKey(num);
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				ShowState();
				Talk_System("마스터키가 변경되었습니다");
			}
			else if(strcmp(str,"Coin") == 0) {
				SetMoney(num);
				gotoxy(0,21); printf("                                             ");
				gotoxy(0,22); printf("                                             ");
				gotoxy(0,23); printf("                                             ");
				ShowState();
				Talk_System("코인 치트가 적용되었습니다");
			}
		}
	}
	else if(ID == 5) {
		if(x == 37 && y == 11) {
			srand((unsigned int)time(NULL));
			int luck = rand() % 5 + 1;
			char nameNPC[] = "로토";
			int answer, betting;
			
			Talk_NPC(nameNPC,"코인을 더 많이 벌고싶지 않아?");
			Talk_NPC(nameNPC,"만일 내가 생각한 1~5 사이 숫자를 맞추면 건 돈의 3배를 줄게");
			//
			SetColor(WHITE,BLACK);
			gotoxy(1,21);
			printf("그럼 얼마를 걸래?");
			gotoxy(1,23); scanf("%d",&betting); fflush(stdin);
			gotoxy(1,21);
			printf("                                                                                             ");
			gotoxy(1,23);
			printf("                                                                                             ");
			//
			if(GetMoney() < betting) {
				Talk_NPC(nameNPC,"미안하지만 자네가 가진 코인보다 큰돈은 걸 수 없어");
			}
			else {
				EarnMoney((-1)*betting);
				//
				SetColor(WHITE,BLACK);
				gotoxy(1,21);
				printf("내가 생각한 숫자는 몆일까? (1~5 사이)");
				gotoxy(1,23); scanf("%d",&answer); fflush(stdin);
				gotoxy(1,21);
				printf("                                                                                             ");
				gotoxy(1,23);
				printf("                                                                                             ");
				//
				if(answer == luck || answer == GetMasterKey()) {
					EarnMoney(betting*3);
					Talk_NPC(nameNPC,"정답! 건 돈의 3배를 돌려줄게");
				}
				else {
					Talk_NPC(nameNPC,"땡! 다음 기회에 도전해봐");
					//
					SetColor(WHITE,BLACK);
					gotoxy(1,21);
					printf("참고로 내가 생각한 숫자는 %d 이였어!",luck);
					getche();
					gotoxy(1,21);
					printf("                                                                                             ");
					gotoxy(1,23);
					printf("                                                                                             ");
					//
				}
			}
		}
		if(x == 11 && y == 2) {
			char nameNPC[] = "소우";
			switch(questList[5]) {
			case 0:
				if(GetLevel() < 20 || questList[4] != -1) {
					Talk_NPC(nameNPC,"레벨 20이 되면 오도록 해 물론 초등마을 퀘스트도 다 깨고 와야지");
					Talk_Player("(레벨 20까지 사칙연산 구역에서 사냥을 하자)");
				}
				else {
					Talk_NPC(nameNPC,"저기, 시간이 있으면 나좀 도와주지 않을래?");
					Talk_Player("무슨일인데 그래?");
					Talk_NPC(nameNPC,"마을앞에 몬스터들이 너무 많아서 약초를 찾으러 갈수가 없어");
					Talk_NPC(nameNPC,"마을 아래쪽에 일차식 몬스터를 10마리만 잡아줄래?");
					Talk_Player("근데 난 아직 일차식 계산을 할 줄 모르는걸");
					Talk_NPC(nameNPC,"그럼 이걸 가져가, 도움이 될거야");
					PushItem('f');
					Talk_System("아이템 'f'를 획득했다");
					Talk_Player("알았어, 금방 다녀올게");
					questList[5] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"일차식 몬스터를 10마리만 잡아줘");
				Talk_NPC(nameNPC,"일차식 몬스터는 마을 아래 일차식 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("일차식 몬스터 10마리, 모두 잡아왔어");
				Talk_NPC(nameNPC,"고마워! 덕분에 다시 약초를 찾으러 갈 수 있게됬어");
				Talk_NPC(nameNPC,"이건 내 정성의 표시야");
				Talk_System("경험치를 400 획득했다");
				EarnExp(400);
				Talk_Player("그럼 다음에 봐");
				questList[5] = -1;
				break;
			case -1:
				if(GetLevel() < 23) {
					Talk_NPC(nameNPC,"레벨 23이 되면 그때 오도록 해");
					Talk_Player("(레벨 23이 되면 다시오자)");
				}
				break;
			}
			switch(questList[7]) {
			case 0:
				if(questList[5] == -1 && GetLevel() >= 23) {
					Talk_NPC(nameNPC,"나좀 도와주지 않을래?");
					Talk_Player("뭔데?");
					Talk_NPC(nameNPC,"마을앞 이차식 몬스터들이 약초를 전부 먹어버리고 있어");
					Talk_NPC(nameNPC,"마을 일차식 구역 아래쪽에 이차식 몬스터를 10마리만 잡아줄래?");
					Talk_Player("ㅇㅋ. 금방 다녀올게");
					questList[7] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"이차식 몬스터를 10마리만 잡아줘");
				Talk_NPC(nameNPC,"이차식 몬스터는 일차식 구역 아래 이차식 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("이차식 몬스터 10마리를 모두 잡았으니 이제 걱정없을거야");
				Talk_NPC(nameNPC,"고마워! 덕분에 다시 약초가 자랄 수 있게됬어");
				Talk_NPC(nameNPC,"고마움의 표시로 이걸 줄게");
				Talk_System("경험치를 400 획득했다");
				EarnExp(400);
				Talk_Player("그럼 또 다음에 봐");
				questList[7] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"안녕. 오늘따라 똑똑해 보이네");
				break;
			}
		}
		if(x == 17 && y == 2) {
			char nameNPC[] = "세지";
			switch(questList[6]) {
			case 0:
				if(GetLevel() < 20 || questList[4] != -1) {
					Talk_NPC(nameNPC,"레벨 20이 되면 오도록 해 물론 초등마을 퀘스트도 다 깨고 와야지");
					Talk_Player("(레벨 20까지 사칙연산 구역에서 사냥을 하자)");
				}
				else {
					Talk_NPC(nameNPC,"저기, 나좀 도와주지 않겠어?");
					Talk_Player("무슨일인데?");
					Talk_NPC(nameNPC,"소우랑 같이 마을앞에 약초를 찾으러 갔다가...");
					Talk_NPC(nameNPC,"그만 약초바구니를 두고왔지 뭐야?");
					Talk_Player("그렇구나, 그럼 내가 찾아다 줄게");
					Talk_NPC(nameNPC,"고마워, 아마 마을아래에 일차식 몬스터를 잡다보면 찾을 수 있을거야");
					questList[6] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"일차식 몬스터를 잡고 약초바구니를 찾아줘");
				Talk_NPC(nameNPC,"일차식 몬스터는 마을 아래 일차식 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("이 바구니가 맞지?");
				Talk_NPC(nameNPC,"맞아! 찾아줘서 정말 고마워");
				Talk_NPC(nameNPC,"이건 내 정성의 표시야");
				Talk_System("경험치를 500 획득했다");
				EarnExp(500);
				Talk_Player("그럼 나중에 봐");
				questList[6] = -1;
				break;
			case -1:
				if(GetLevel() < 23) {
					Talk_NPC(nameNPC,"레벨 23이 되면 그때 오도록 해");
					Talk_Player("(레벨 23이 되면 다시오자)");
				}
				break;
			}
			switch(questList[8]) {
			case 0:
				if(questList[6] == -1 && GetLevel() >= 23) {
					Talk_NPC(nameNPC,"나좀 도와주지 않을래?");
					Talk_Player("뭔데?");
					Talk_NPC(nameNPC,"마을앞 이차식 몬스터들이 내가 만든 약초 농축액을 병째로 삼켜버렸어");
					Talk_NPC(nameNPC,"마을 일차식 구역 아래쪽에 이차식 몬스터들에게서 되찾아와주지 않을래?");
					Talk_Player("알았어, 내가 찾아줄게");
					questList[8] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"이차식 몬스터를 잡고 약초 농축액을 찾아줘");
				Talk_NPC(nameNPC,"이차식 몬스터는 일차식 구역 아래 이차식 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("자, 여기 약초 농축액을 되찾아왔어");
				Talk_NPC(nameNPC,"고마워! 덕분에 다시 연구를 진행할 수 있게 되었어");
				Talk_NPC(nameNPC,"고마움의 표시로 이걸 줄게");
				Talk_System("아이템 'P'를 획득했다");
				PushItem('P');
				Talk_System("경험치를 400 획득했다");
				EarnExp(400);
				SetMyJob("유리수");
				Talk_System("'유리수'로 전직했다!");
				Talk_Player("오! 고마워!!");
				questList[8] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"안녕. 오늘따라 똑똑해 보이네");
				break;
			}
		}
		if(x == 2 && y == 14) {
			char nameNPC[] = "구우";
			if(GetHp() == GetMaxHp()) {
				Talk_NPC(nameNPC,"이미 체력이 만땅인걸?");
			}
			else if(GetHp() < GetMaxHp()) {
				Talk_NPC(nameNPC,"체력이 부족하구나, 기다려봐 금방 채워줄게");
				SetHpFull();
				ShowState();
				Talk_System("체력이 회복되었다");
			}
		}
	}
	else if(ID == 8) {
		if(x == 2 && y == 6) {
			char nameNPC[] = "이소";
			switch(questList[17]) {
			case 0:
				if(GetLevel() < 35 || questList[16] != -1) {
					Talk_NPC(nameNPC,"레벨 35가 되면 다시와! 바빠 죽겠는데 괜히 말걸지 말고");
					Talk_Player("......(레벨 35가 되면 다시오자)");
				}
				else {
					Talk_NPC(nameNPC,"아.. 짜증나... 좀 도와줄래?");
					Talk_Player("....무슨일인데?");
					Talk_NPC(nameNPC,"저 적분 몬스터들때문에 짜증나서 연구가 안돼");
					Talk_NPC(nameNPC,"가서 하급 적분 몬스터를 한 10마리 정도만 때려잡고 와줄레?");
					Talk_Player("뭐.... 알았어");
					questList[17] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"하급 적분 몬스터 10마리만 잡아줘");
				Talk_NPC(nameNPC,"하급 적분 몬스터는 마을 왼쪽 적분 구역 1 에서 볼수있어");
				break;
			case 2:
				Talk_Player("이제 조용해 졌지?");
				Talk_NPC(nameNPC,"뭐 덕분에");
				Talk_NPC(nameNPC,"그래도 수고했으니 보상은 줘야겠네");
				Talk_System("경험치를 5000 획득했다");
				EarnExp(5000);
				Talk_NPC(nameNPC,"받았으면 빨리 가 난 바쁘니까");
				questList[17] = -1;
				break;
			case -1:
				if(GetLevel() < 38) {
					Talk_NPC(nameNPC,"레벨 38이 되면 다시와.");
					Talk_Player("(레벨 38이 되면 다시오자)");
				}
				break;
			}
			switch(questList[18]) {
			case 0:
				if(GetLevel() >= 38) {
					Talk_NPC(nameNPC,"내키지는 않지만.. 한번만 더 도와줘");
					Talk_Player("....이번엔 또 무슨일인데?");
					Talk_NPC(nameNPC,"적분 몬스터들이 날뛰면서 이것 저것 적분해대고 있어;;");
					Talk_NPC(nameNPC,"가서 상급 적분 몬스터 10마리만 잡아줘");
					Talk_Player("뭐 그런일이라면 도와주도록 할까");
					Talk_NPC(nameNPC,"그럼 빨리 갔다와 녀석들 때문에 연구를 할수가 없거든");
					questList[18] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"상급 적분 몬스터 10마리만 잡아줘");
				Talk_NPC(nameNPC,"상급 적분 몬스터는 적분 구역 1 왼쪽 적분 구역 2 에서 볼수있어");
				break;
			case 2:
				Talk_Player("이정도면 됬지?");
				Talk_NPC(nameNPC,"뭐 그렇네");
				Talk_NPC(nameNPC,"이건 뭐 그냥 선물 정도라고 생각하고 받아");
				Talk_System("경험치를 8000 획득했다");
				EarnExp(8000);
				Talk_System("'수학자'로 전직했다!");
				SetMyJob("수학자");
				Talk_NPC(nameNPC,".... 다음에 또 놀러와..");
				questList[18] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"지..지금은 바쁘니까! 다음에 와!");
				break;
			}
		}
		if(x == 37 && y == 4) {
			char nameNPC[] = "가시";
			switch(questList[9]) {
				case 0:
					if(GetLevel() < 25 || questList[8] != -1) {
						Talk_NPC(nameNPC,"지금은 바쁘니까 레벨 25가 되면 그떄 와!! 당연히 중등마을은 클리어 했지?");
						Talk_Player("...(굉장히 바쁜 것 같다)");
					}
					else if(GetLevel() >= 25) {
						Talk_NPC(nameNPC,"지금 급한데 나좀 도와줘");
						Talk_Player("뭐때문에 그러는데?");
						Talk_NPC(nameNPC,"실수로 내가 연구 일지를 마을 근처에서 잃어버렸거든");
						Talk_NPC(nameNPC,"아마 순열 구역에서 떨어뜨린 것 같은데 좀 찾아줄래?");
						Talk_Player("내가 금방 찾아올게, 기다려");
						questList[9] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"순열 몬스터를 잡고 연구 일지를 찾아줘");
				Talk_NPC(nameNPC,"순열 몬스터는 마을 오른쪽 순열 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("자, 이 연구 일지가 니꺼 맞지?");
				Talk_NPC(nameNPC,"고마워! 덕분에 다시 연구를 진행할 수 있게 되었어");
				Talk_NPC(nameNPC,"별건 아니지만 보상을 줄게");
				Talk_System("경험치를 600 획득했다");
				EarnExp(600);
				Talk_Player("그럼 또 다음에 봐");
				questList[9] = -1;
				break;
			case -1:
				if(GetLevel() < 28) {
						Talk_NPC(nameNPC,"지금은 바쁘니까 레벨 28가 되면 그떄 와");
						Talk_Player("...(항상 바쁜 것 같아보인다)");
					}
				break;
			}
			switch(questList[10]) {
				case 0:
					if(questList[9] == -1 && GetLevel() >= 28) {
						Talk_NPC(nameNPC,"지금 급한데 나좀 도와줘");
						Talk_Player("이번엔 또 뭐때문에 그러는데?");
						Talk_NPC(nameNPC,"저번에 찾아준 연구 일지에서 일부분이 누락되어 있어");
						Talk_NPC(nameNPC,"이건 아마 중복 순열 몬스터들이 뜯어간것 같아. 이왕 하는거 끝까지 찾아줘");
						Talk_Player("에휴,, 내가 금방 찾아올게");
						questList[10] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"중복 순열 몬스터를 잡고 찢어진 연구 일지를 찾아줘");
				Talk_NPC(nameNPC,"중복 순열 몬스터는 순열 구역 위쪽 중복 순열 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("자, 이 찢어진 연구 일지가 니꺼 맞지?");
				Talk_NPC(nameNPC,"고마워! 덕분에 다시 연구를 진행할 수 있게 되었어");
				Talk_NPC(nameNPC,"별건 아니지만 보상을 줄게");
				Talk_System("경험치를 1000 획득했다");
				EarnExp(1000);
				Talk_Player("그럼 또 다음에 봐");
				questList[10] = -1;
				break;
			case -1:
					Talk_NPC(nameNPC,"바쁜데 말좀 그만 걸지?");
				break;
			}
		}
		if(x == 37 && y == 13) {
			char nameNPC[] = "우토";
			switch(questList[11]) {
				case 0:
					if(GetLevel() < 25 || questList[8] != -1) {
						Talk_NPC(nameNPC,"Zzzzzz.... 음냐 음냐");
						Talk_Player("...(레벨 25가 되면 그때 깨워보자 물론 그전에 중등마을을 클리어 해야한다)");
					}
					else if(GetLevel() >= 25) {
						Talk_NPC(nameNPC,"음? 저기 나좀 도와줘어~");
						Talk_Player("응? 무슨일인데");
						Talk_NPC(nameNPC,"한숨 자고 먹으려던 고기를 몬스터들이 전부 먹어버린것 같아");
						Talk_NPC(nameNPC,"조합 몬스터 20 마리만 혼내줘!");
						Talk_Player("뭐 내키지는 않지만... 그렇게 할게");
						Talk_NPC(nameNPC,"그리고 혹시 모르니 이걸 가져가도록 해");
						Talk_System("아이템 'C'를 획득했다");
						PushItem('C');
						questList[11] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"조합 몬스터 20마리만 잡아줘");
				Talk_NPC(nameNPC,"조합 몬스터는 순열 구역 오른쪽 조합 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("자, 이정도면 충분하지?");
				Talk_NPC(nameNPC,"으응, 고마워... 그럼 난 다시 잘게.. 음냐 음냐..");
				Talk_NPC(nameNPC,"zzz...보상으로...이걸...줄게....Zzzzz");
				Talk_System("경험치를 600 획득했다");
				EarnExp(600);
				Talk_Player("그럼 또 다음에 봐");
				questList[11] = -1;
				break;
			case -1:
				if(GetLevel() < 28) {
						Talk_NPC(nameNPC,"드르렁...쿠우우울... Zzzz");
						Talk_Player("...(심하게 잠든것 같다. 레벨 28이 되면 깨워보자)");
					}
				break;
			}
			switch(questList[12]) {
				case 0:
					if(questList[11] == -1 && GetLevel() >= 28) {
						Talk_NPC(nameNPC,"아! 저번에 그녀석 이구나");
						Talk_Player("이번엔 또 뭐때문에 그러는데?");
						Talk_NPC(nameNPC,"몬스터들 때문에 시끄러워서 잠을 잘수가 없어");
						Talk_NPC(nameNPC,"중복 조합 몬스터 20 마리만 퇴치해주지 않을래?");
						Talk_Player("알았어...");
						questList[12] = 1;
					}
					break;
			case 1:
				Talk_NPC(nameNPC,"중복 조합 몬스터 20마리만 잡아줘");
				Talk_NPC(nameNPC,"중복 조합 몬스터는 조합 구역 위쪽 중복 조합 구역에서 볼수있어");
				break;
			case 2:
				Talk_Player("다 잡았어, 이제 조용히 잘 수 있겠지?");
				Talk_NPC(nameNPC,"Zzzzzzzzz.....");
				Talk_Player("저기...?");
				Talk_NPC(nameNPC,"아! 맞다 보상... 여기있어.... Zzzzz...");
				Talk_System("경험치를 1000 획득했다");
				EarnExp(1000);
				SetMyJob("실수");
				Talk_System("'실수'로 전직했다!");
				Talk_Player("졸면서 전직시켜주다니... 뭔가 찝찝하긴 하지만...");
				questList[12] = -1;
				break;
			case -1:
					Talk_NPC(nameNPC,"Zzzzzzzzz......");
				break;
			}
		}
		if(x == 2 && y == 14) {
			char nameNPC[] = "구우";
			if(GetHp() == GetMaxHp()) {
				Talk_NPC(nameNPC,"이미 체력이 만땅인걸?");
			}
			else if(GetHp() < GetMaxHp()) {
				Talk_NPC(nameNPC,"체력이 부족하구나, 기다려봐 금방 채워줄게");
				SetHpFull();
				ShowState();
				Talk_System("체력이 회복되었다");
			}
		}
		if(x == 9 && y == 2) {
			char nameNPC[] = "나대";
			switch(questList[13]) {
			case 0:
				if(GetLevel() < 30 || questList[12] != -1) {
					Talk_NPC(nameNPC,"레벨 30이 되면 다시와. 물론 그전에 우토와 가시의 퀘스트를 클리어 했겠지? ㅎㅎ");
					Talk_Player("(레벨 30이 되면 다시오자)");
				}
				else {
					Talk_NPC(nameNPC,"시간 있으면 나좀 도와줄레?");
					Talk_Player("무슨일인데?");
					Talk_NPC(nameNPC,"내가 미분 구역을 돌아다니다가 사진기를 잃어버렸거든");
					Talk_NPC(nameNPC,"하급 미분 몬스터를 잡고 사진기를 찾아와줘");
					Talk_Player("좋아, 내가 가져다 줄게");
					Talk_NPC(nameNPC,"그리고 혹시 모르니 이걸 가져가도록 해");
					Talk_System("아이템 'd'를 획득했다");
					PushItem('d');
					questList[13] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"하급 미분 몬스터를 잡고 사진기를 되찾아줘");
				Talk_NPC(nameNPC,"하급 미분 몬스터는 마을 위쪽 미분 구역 1 에서 볼수있어");
				break;
			case 2:
				Talk_Player("이 사진기가 니꺼 맞지?");
				Talk_NPC(nameNPC,"아! 고마워 찾아줬구나");
				Talk_NPC(nameNPC,"대신 선물로 이걸 줄게");
				Talk_System("경험치를 2000 획득했다");
				EarnExp(2000);
				Talk_Player("그럼 안녕~");
				questList[13] = -1;
				break;
			case -1:
				if(GetLevel() < 33) {
					Talk_NPC(nameNPC,"레벨 33이 되면 다시와.");
					Talk_Player("(레벨 33이 되면 다시오자)");
				}
				break;
			}
			switch(questList[14]) {
			case 0:
				if(GetLevel() >= 33) {
					Talk_NPC(nameNPC,"저기, 한번만 더 도와주지 않을래?");
					Talk_Player("이번엔 무슨일인데?");
					Talk_NPC(nameNPC,"사진기에 들어있던 필름이 모두 사라졌어");
					Talk_NPC(nameNPC,"아무래도 잃어버렸을 때 몬스터들이 가져가버린것 같아");
					Talk_NPC(nameNPC,"상급 미분 몬스터를 잡고 사진 필름을 찾아와줘");
					Talk_Player("좋아, 도와주도록 하지");
					Talk_NPC(nameNPC,"그럼 부탁해~");
					questList[14] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"상급 미분 몬스터를 잡고 사진 필름을 되찾아줘");
				Talk_NPC(nameNPC,"상급 미분 몬스터는 미분 구역 1 위쪽 미분 구역 2 에서 볼수있어");
				break;
			case 2:
				Talk_Player("이 사진 필름 맞지?");
				Talk_NPC(nameNPC,"아! 고마워 찾아줬구나");
				Talk_NPC(nameNPC,"대신 선물로 이걸 줄게");
				Talk_System("경험치를 4000 획득했다");
				EarnExp(4000);
				Talk_System("아이템 's'를 획득했다");
				PushItem('s');
				Talk_Player("그럼 안녕~");
				questList[14] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"지난번엔 고마웠어~");
				break;
			}
		}
		if(x == 24 && y == 2) {
			char nameNPC[] = "냐소";
			switch(questList[15]) {
			case 0:
				if(GetLevel() < 30 || questList[12] != -1) {
					Talk_NPC(nameNPC,"레벨 30이 되면 다시와. 물론 그전에 우토와 가시의 퀘스트를 클리어 했겠지?");
					Talk_Player("(레벨 30이 되면 다시오자)");
				}
				else {
					Talk_NPC(nameNPC,"시간 있으면 나좀 도와줄레?");
					Talk_Player("무슨일인데?");
					Talk_NPC(nameNPC,"저놈의 미분 몬스터들 때문에 그림 그리는데 집중이 안돼");
					Talk_NPC(nameNPC,"하급 미분 몬스터 10마리만 잡아줘");
					Talk_Player("알았어, 금방 다녀오지");
					questList[15] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"하급 미분 몬스터 10마리만 잡아줘");
				Talk_NPC(nameNPC,"하급 미분 몬스터는 마을 위쪽 미분 구역 1 에서 볼수있어");
				break;
			case 2:
				Talk_Player("이제 조용해 졌지?");
				Talk_NPC(nameNPC,"고마워! 덕분에 다시 그림을 그릴 수 있겠다");
				Talk_NPC(nameNPC,"이건 내가 주는 선물이야");
				Talk_System("경험치를 2000 획득했다");
				EarnExp(2000);
				Talk_Player("그럼 안녕~");
				questList[15] = -1;
				break;
			case -1:
				if(GetLevel() < 33) {
					Talk_NPC(nameNPC,"레벨 33이 되면 다시와.");
					Talk_Player("(레벨 33이 되면 다시오자)");
				}
				break;
			}
			switch(questList[16]) {
			case 0:
				if(GetLevel() >= 33) {
					Talk_NPC(nameNPC,"미안한데 한번만 더 도와줘");
					Talk_Player("이번엔 또 무슨일인데?");
					Talk_NPC(nameNPC,"미분 몬스터들이 내가 그린 그림을 전부 미분해버렸어...ㅡㅡ");
					Talk_NPC(nameNPC,"아무레도 되찾는건 불가능이고 대신 녀석들을 혼내주줘");
					Talk_NPC(nameNPC,"상급 미분 몬스터 10마리만 잡아줘");
					Talk_Player("좋아, 도와주도록 하지");
					Talk_NPC(nameNPC,"그럼 부탁해~");
					questList[16] = 1;
				}
				break;
			case 1:
				Talk_NPC(nameNPC,"상급 미분 몬스터 10마리만 잡아줘");
				Talk_NPC(nameNPC,"상급 미분 몬스터는 미분 구역 1 위쪽 미분 구역 2 에서 볼수있어");
				break;
			case 2:
				Talk_Player("이정도면 됬지?");
				Talk_NPC(nameNPC,"아! 고마워");
				Talk_NPC(nameNPC,"이건 그동안 수고한거에 대한 보상이야");
				Talk_System("경험치를 4000 획득했다");
				EarnExp(4000);
				Talk_System("'복소수'로 전직했다!");
				SetMyJob("복소수");
				Talk_Player("우오오오! 전직했다!! 고마워!");
				questList[16] = -1;
				break;
			case -1:
				Talk_NPC(nameNPC,"#@)#($&!(*&@$)(#$");
				Talk_Player("저녀석은 항상 이상한 말만 하네....");
				break;
			}
		}
	}
}

int GetQuestList(int n) {
	return questList[n];
}

void SetQuestList(int n, int entry) {
	questList[n] = entry;
}