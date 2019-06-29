#include <windows.h>
#include <stdio.h>
#include "resource.h"

#define CXSCREEN	400	// 작업영역 가로크기.
#define CYSCREEN	400 // 작업영역 세로크기.

#define NSTAGE		3	// 스테이지 개수.
#define XSTAGE		0	// 스테이지 수평 시작위치.
#define YSTAGE		40	// 스테이지 수직 시작위치.
#define NXTILE		21	// 스테이지 가로 타일 개수.
#define NYTILE		18	// 스테이지 세로 타일 개수.
#define CXTILE		20	// 스테이지 타일 수평 크기.
#define CYTILE		20	// 스테이지 타일 수직 크기.

#define NBITMAP		8	// 비트맵 이미지 개수.

// 비트맵 저장을 위한 구조체.
struct BitmapInfo
{
	int iIndex;			// 리소스의 인덱스 번호.
	char ch;			// 비트맵과 연결된 문자.
	HDC hMemDC;			// 비트맵이 담김 메모리DC
	HBITMAP hBitmap;	// 비트맵 객체.
} aBitmapInfo[NBITMAP] = 
{
	{IDB_EMPTY, ' ', NULL, NULL},
	{IDB_LOAD, 'O', NULL, NULL},
	{IDB_STORE, '.', NULL, NULL},
	{IDB_WALL, '#', NULL, NULL},
	{IDB_PLAYERUP, '@', NULL, NULL},
	{IDB_PLAYERRIGHT, '@', NULL, NULL},
	{IDB_PLAYERDOWN, '@', NULL, NULL},
	{IDB_PLAYERLEFT, '@', NULL, NULL},
};

// 플레이어가 움직인 자취를 위한 구조체.
#define NTRACK	1000	// 트랙 개수.
#define NSLICE	100		// 용량 초과시 앞부분을 자를 개수.
struct TrackInfo
{
	char bValid:2;		// 유효한 정보인지의 여부.
	char x:2;			// 수평으로 움직인 수치.
	char y:2;			// 수직으로 움직인 수치.
	char bWithLoad:2;	// 짐과 함께 움직인 여부.
} aTrackInfo[NTRACK];

// 함수 원형 선언.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void InitGame();	// 게임 초기화.
void ReleaseGame();	// 게임 해제.
void SetGame();		// 게임 셋팅하기.
void ChangeStage(int Num);	// 스테이지 바꾸기.
void DrawStage();	// 현재 스테이지 그리기.
void DrawState();	// 현재 상태 보여주기.
void DrawPlayer();	// 플레이어 그리기.
void Move(UINT Key);	// 움직임 처리.
bool GameOverMsg();	// 게임 오버 메시지.
bool IsFull();		// 창고에 짐이 다 찼는지 검사.
void EraseLoad(int X, int Y);	// 짐 지우기.
void Undo();	// 실행취소.
void Redo();	// 재실행.
int GetBitmapIdx(int X, int Y);	// 이동 방향에 따른 비트맵 인덱스 얻기.

// 비트맵 정보 찾기.
// Column 값
#define BI_INDEX	0	// 인덱스를 기준으로 찾기.
#define BI_CHAR		1	// 문자를 기준으로 찾기.
BitmapInfo * GetBitmapInfo(int Column, ULONG Data);

// 게임 스테이지 정보.
char aStage[NSTAGE][NYTILE][NXTILE] = 
{
	{
		"####################",
		"####################",
		"####################",
		"#####   ############",
		"#####O  ############",
		"#####  O############",
		"###  O O ###########",
		"### # ## ###########",
		"#   # ## #####  ..##",
		"# O  O   @      ..##",
		"##### ### ####  ..##",
		"#####     ##########",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################"
	},
	{
		"####################",
		"####################",
		"####################",
		"####################",
		"####..  #     ######",
		"####..  # O  O  ####",
		"####..  #O####  ####",
		"####..    @ ##  ####",
		"####..  # #  O #####",
		"######### ##O O ####",
		"###### O  O O O ####",
		"######    #     ####",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################"
	},
	{
		"####################",
		"####################",
		"####################",
		"####################",
		"##########     @####",
		"########## O#O #####",
		"########## O  O#####",
		"###########O O #####",
		"########## O # #####",
		"##....  ## O  O  ###",
		"###...    O  O   ###",
		"##....  ############",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################",
		"####################"
	},
};

// 현재 진행중인 스테이지 정보.
char aPlayStage[NYTILE][NXTILE];

int px, py;	// 플레이어 현재 위치.
int iDir;	// 플레이어 현재 방향.
int iStage; // 현재 스테이지.
int nMove;	// 움직인 회수.
int nTotMove;	// 총 움직인 회수.
int iTrackIdx;	// 현재 트랙 위치.

// 다양한 목적을 위한 변수.
int x, y, i, j, k;

HWND g_hWnd;
HINSTANCE g_hInst;

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
	TCHAR	szAppName[] = TEXT("Soukoban Game");
	HWND			hWnd;
	MSG				msg;
	WNDCLASS		wc;

	wc.style			= CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc		= WndProc;
	wc.cbClsExtra		= 0;
	wc.cbWndExtra		= 0;
	wc.hInstance		= hInstance;
	wc.hIcon			= LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor			= LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName		= NULL;
	wc.lpszClassName	= szAppName;

	g_hInst = hInstance;

	if(!RegisterClass(&wc))
	{
		MessageBox(NULL, TEXT("This program requires window NT!"),
			szAppName, MB_ICONERROR);
	}

	g_hWnd = hWnd = CreateWindow(szAppName, szAppName,
		WS_OVERLAPPED | WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, CXSCREEN, CYSCREEN,
		NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, iCmdShow);
	UpdateWindow(hWnd);

	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;

	switch(msg)
	{
	case WM_CREATE:
		InitGame();
		SetGame();
		return 0;

	case WM_KEYDOWN:
		switch(wParam)
		{
		case VK_LEFT:
		case VK_UP:
		case VK_RIGHT:
		case VK_DOWN:
			Move(wParam);
			if(IsFull())
			{
				if(++iStage < NSTAGE)
					ChangeStage(iStage);
				else
				{
					if(!GameOverMsg())
						DestroyWindow(g_hWnd);
					else
						SetGame();
				}
			}
			break;

		case 'Z':
			if(GetKeyState(VK_LCONTROL) & 0x8000)
				Undo();
			break;

		case 'Y':
			if(GetKeyState(VK_LCONTROL) & 0x8000)
				Redo();
			break;
		}		
		return 0;

	case WM_PAINT:
		// 작업영역을 유효화.
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);

		// 그리기 작업.
		DrawStage();
		DrawState();
		DrawPlayer();
		return 0;

	case WM_DESTROY:
		ReleaseGame();
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}

// 게임 초기화.
void InitGame()
{
	HDC hDC = GetDC(g_hWnd);
	for(i=0; i<NBITMAP; ++i)
	{
		aBitmapInfo[i].hBitmap = LoadBitmap(g_hInst, MAKEINTRESOURCE(aBitmapInfo[i].iIndex));
		aBitmapInfo[i].hMemDC = CreateCompatibleDC(hDC);
		SelectObject(aBitmapInfo[i].hMemDC, aBitmapInfo[i].hBitmap);
	}
	ReleaseDC(g_hWnd, hDC);
}

// 게임 해제.
void ReleaseGame()
{
	for(i=0; i<NBITMAP; ++i)
	{
		DeleteDC(aBitmapInfo[i].hMemDC);
		DeleteObject(aBitmapInfo[i].hBitmap);
	}
}

// 게임 셋팅.
void SetGame()
{
	iStage = 0;
	nTotMove = 0;
	ChangeStage(iStage);
}

// 스테이지 바꾸기.
void ChangeStage(int Num)
{
	// 움직인 횟수 초기화.
	nMove = 0;

	// 방향 초기화.
	iDir = IDB_PLAYERLEFT;

	// 트랙 초기화.
	iTrackIdx = 0;
	aTrackInfo[0].bValid = false;

	// 스테이지 복사.
	memcpy(aPlayStage, aStage[Num], sizeof(aStage[0]));

	for(x=0; x<NXTILE-1; ++x)
		for(y=0; y<NYTILE; ++y)
			if(aPlayStage[y][x] == '@')
			{
				// 현재 스테이지에서 플레이어 제거.
				aPlayStage[y][x] = ' ';

				// 플레이어 좌표 저장.
				px = x;
				py = y;

				return;
			}
}

// 스테이지 그리기.
void DrawStage()
{
	HDC hDC, hMemDC;
	char ch;

	hDC = GetDC(g_hWnd);
	for(x=0; x<NXTILE-1; ++x)
		for(y=0; y<NYTILE; ++y)
		{
			ch = aPlayStage[y][x];
			hMemDC = GetBitmapInfo(BI_CHAR, (ULONG)ch)->hMemDC;

			BitBlt(hDC,
				x * CXTILE + XSTAGE,
				y * CYTILE + YSTAGE,
				CXTILE, CYTILE, hMemDC,
				0, 0, SRCCOPY);
		}
	ReleaseDC(g_hWnd, hDC);
}

// 현재 상태 보여주기.
void DrawState()
{
	char szStage[256];
	char szMove[256];
	char szTotMove[256];
	HDC hDC;
	TEXTMETRIC tm;
	int gap; // 문장 사이의 간격.
	
	sprintf(szStage, "Stage : %d", iStage);
	sprintf(szMove, "Move : %d", nMove);
	sprintf(szTotMove, "Total Move : %d", nTotMove);

	hDC = GetDC(g_hWnd);
	SelectObject(hDC, GetStockObject(DEFAULT_GUI_FONT));
	GetTextMetrics(hDC, &tm);
	gap = tm.tmAveCharWidth * 5;
	y = YSTAGE / 2 - tm.tmHeight / 2;
	Rectangle(hDC, 0, 0, CXSCREEN, YSTAGE);
	TextOut(hDC, 10, y, szStage, strlen(szStage));
	TextOut(hDC, 10+gap + tm.tmAveCharWidth*strlen(szStage), y, szMove, strlen(szMove));
	TextOut(hDC, 10+gap*2 + tm.tmAveCharWidth*strlen(szStage) + tm.tmAveCharWidth*strlen(szMove),
		y, szTotMove, strlen(szTotMove));
	ReleaseDC(g_hWnd, hDC);
}

// 플레이어 그리기.
void DrawPlayer()
{
	HDC hDC = GetDC(g_hWnd);
	BitBlt(hDC, px*CXTILE+XSTAGE, py*CYTILE+YSTAGE, CXTILE, CYTILE,
		GetBitmapInfo(BI_INDEX, iDir)->hMemDC, 0, 0, SRCCOPY);
	ReleaseDC(g_hWnd, hDC);
}

// 이동.
void Move(UINT Dir)
{
	y = x = 0;
	switch(Dir)
	{
	case VK_LEFT:
		iDir = IDB_PLAYERLEFT;
		x = -1;
		break;

	case VK_UP:
		iDir = IDB_PLAYERUP;
		y = -1;
		break;

	case VK_RIGHT:
		iDir = IDB_PLAYERRIGHT;
		x = 1;
		break;

	case VK_DOWN:
		iDir = IDB_PLAYERDOWN;
		y = 1;
		break;
	}

	bool bPush = false;

	if(aPlayStage[py+y][px+x] != '#')
	{
		if(aPlayStage[py+y][px+x] == 'O')
		{
			if(aPlayStage[py+y*2][px+x*2] == ' ' ||
				aPlayStage[py+y*2][px+x*2] == '.')
			{
				EraseLoad(px+x, py+y);
				aPlayStage[py+y*2][px+x*2] = 'O';
				bPush = true;
			}
			else
				return;
		}
		px += x;
		py += y;
		nMove++;
		nTotMove++;

		// 움직인 자취 저장.
		aTrackInfo[iTrackIdx].bValid = true;
		aTrackInfo[iTrackIdx].x = x;
		aTrackInfo[iTrackIdx].y = y;
		aTrackInfo[iTrackIdx].bWithLoad = bPush;
		aTrackInfo[++iTrackIdx].bValid = false;

		// 트랙 용량 초과되면 앞쪽을 제거하여 공간을 확보한다.
		if(iTrackIdx == NTRACK-1)
		{
			// 앞쪽으로 당기기.
			for(i=0; i<NTRACK-NSLICE; ++i)
				aTrackInfo[i] = aTrackInfo[i+NSLICE];

			// 뒤쪽 부분은 무효화.
			for(i=NTRACK-NSLICE; i<NTRACK; ++i)
				aTrackInfo[i].bValid = false;

			// 인덱스도 앞쪽으로 위치.
			iTrackIdx -= NSLICE;
		}

		InvalidateRect(g_hWnd, NULL, FALSE);
	}
}

// 게임 오버 메시지.
bool GameOverMsg()
{
	char msg[256];

	sprintf(msg, "축하합니다!!\n총 움직인 횟수 : %d\n다시 시작하시겠습니까?", nTotMove);
	return MessageBox(g_hWnd, msg, "GameOver", MB_YESNO | MB_ICONINFORMATION) == IDYES;
}

// 창고에 화물이 다 찼는지 검사.
bool IsFull()
{
	for(x=0; x<NXTILE; ++x)
		for(y=0; y<NYTILE; ++y)
			if(aStage[iStage][y][x] == '.' &&
				aPlayStage[y][x] != 'O')
			{
				return false;
			}

	return true;
}

// 짐 지우기.
void EraseLoad(int X, int Y)
{
	if(aStage[iStage][Y][X]	== '.')
		aPlayStage[Y][X] = '.';
	else
		aPlayStage[Y][X] = ' ';
}

// 실행취소.
void Undo()
{
	if(iTrackIdx > 0)
	{
		iTrackIdx--;

		// 방향 얻기.
		x = aTrackInfo[iTrackIdx].x;
		y = aTrackInfo[iTrackIdx].y;

		// 짐을 이전 위치로.
		if(aTrackInfo[iTrackIdx].bWithLoad)
		{
			EraseLoad(px+x, py+y);
			aPlayStage[py][px] = 'O';
		}

		// 플레이어를 이전 위치로.
		px -= x;
		py -= y;

		// 방향 바꾸기.
		iDir = GetBitmapIdx(x, y);

		InvalidateRect(g_hWnd, NULL, FALSE);
	}
}

// 재실행.
void Redo()
{
	if(aTrackInfo[iTrackIdx].bValid)
	{
		// 방향 얻기.
		x = aTrackInfo[iTrackIdx].x;
		y = aTrackInfo[iTrackIdx].y;

		// 플레이어를 이후 위치로.
		px += x;
		py += y;

		// 짐을 이후 위치로.
		if(aTrackInfo[iTrackIdx].bWithLoad)
		{
			EraseLoad(px, py);
			aPlayStage[py+y][px+x] = 'O';
		}

		// 방향 바꾸기.
		iDir = GetBitmapIdx(x, y);

		iTrackIdx++;
		InvalidateRect(g_hWnd, NULL, FALSE);
	}
}

// 이동 방향에 따른 비트맵 인덱스 얻기.
int GetBitmapIdx(int X, int Y)
{
	if(X == -1)
		return IDB_PLAYERLEFT;
	else if(X == 1)
		return IDB_PLAYERRIGHT;
	else if(Y == -1)
		return IDB_PLAYERUP;
	else
		return IDB_PLAYERDOWN;
}

// 비트맵 정보 찾기.
BitmapInfo * GetBitmapInfo(int Column, ULONG Data)
{
	for(i=0; i<NBITMAP; ++i)
	{
		switch(Column)
		{
		case BI_INDEX:
			if(aBitmapInfo[i].iIndex == (int)Data)
				return aBitmapInfo + i;
			break;

		case BI_CHAR:
			if(aBitmapInfo[i].ch == (char)Data)
				return aBitmapInfo + i;
			break;

		default:
			return NULL;
		}
	}
	return NULL;
}