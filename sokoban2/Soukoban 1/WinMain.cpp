#include <windows.h>
#include <stdio.h>
#include "resource.h"

#define CXSCREEN	400	// �۾����� ����ũ��.
#define CYSCREEN	400 // �۾����� ����ũ��.

#define NSTAGE		3	// �������� ����.
#define XSTAGE		0	// �������� ���� ������ġ.
#define YSTAGE		40	// �������� ���� ������ġ.
#define NXTILE		21	// �������� ���� Ÿ�� ����.
#define NYTILE		18	// �������� ���� Ÿ�� ����.
#define CXTILE		20	// �������� Ÿ�� ���� ũ��.
#define CYTILE		20	// �������� Ÿ�� ���� ũ��.

#define NBITMAP		8	// ��Ʈ�� �̹��� ����.

// ��Ʈ�� ������ ���� ����ü.
struct BitmapInfo
{
	int iIndex;			// ���ҽ��� �ε��� ��ȣ.
	char ch;			// ��Ʈ�ʰ� ����� ����.
	HDC hMemDC;			// ��Ʈ���� ��� �޸�DC
	HBITMAP hBitmap;	// ��Ʈ�� ��ü.
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

// �÷��̾ ������ ���븦 ���� ����ü.
#define NTRACK	1000	// Ʈ�� ����.
#define NSLICE	100		// �뷮 �ʰ��� �պκ��� �ڸ� ����.
struct TrackInfo
{
	char bValid:2;		// ��ȿ�� ���������� ����.
	char x:2;			// �������� ������ ��ġ.
	char y:2;			// �������� ������ ��ġ.
	char bWithLoad:2;	// ���� �Բ� ������ ����.
} aTrackInfo[NTRACK];

// �Լ� ���� ����.
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void InitGame();	// ���� �ʱ�ȭ.
void ReleaseGame();	// ���� ����.
void SetGame();		// ���� �����ϱ�.
void ChangeStage(int Num);	// �������� �ٲٱ�.
void DrawStage();	// ���� �������� �׸���.
void DrawState();	// ���� ���� �����ֱ�.
void DrawPlayer();	// �÷��̾� �׸���.
void Move(UINT Key);	// ������ ó��.
bool GameOverMsg();	// ���� ���� �޽���.
bool IsFull();		// â�� ���� �� á���� �˻�.
void EraseLoad(int X, int Y);	// �� �����.
void Undo();	// �������.
void Redo();	// �����.
int GetBitmapIdx(int X, int Y);	// �̵� ���⿡ ���� ��Ʈ�� �ε��� ���.

// ��Ʈ�� ���� ã��.
// Column ��
#define BI_INDEX	0	// �ε����� �������� ã��.
#define BI_CHAR		1	// ���ڸ� �������� ã��.
BitmapInfo * GetBitmapInfo(int Column, ULONG Data);

// ���� �������� ����.
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

// ���� �������� �������� ����.
char aPlayStage[NYTILE][NXTILE];

int px, py;	// �÷��̾� ���� ��ġ.
int iDir;	// �÷��̾� ���� ����.
int iStage; // ���� ��������.
int nMove;	// ������ ȸ��.
int nTotMove;	// �� ������ ȸ��.
int iTrackIdx;	// ���� Ʈ�� ��ġ.

// �پ��� ������ ���� ����.
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
		// �۾������� ��ȿȭ.
		BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);

		// �׸��� �۾�.
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

// ���� �ʱ�ȭ.
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

// ���� ����.
void ReleaseGame()
{
	for(i=0; i<NBITMAP; ++i)
	{
		DeleteDC(aBitmapInfo[i].hMemDC);
		DeleteObject(aBitmapInfo[i].hBitmap);
	}
}

// ���� ����.
void SetGame()
{
	iStage = 0;
	nTotMove = 0;
	ChangeStage(iStage);
}

// �������� �ٲٱ�.
void ChangeStage(int Num)
{
	// ������ Ƚ�� �ʱ�ȭ.
	nMove = 0;

	// ���� �ʱ�ȭ.
	iDir = IDB_PLAYERLEFT;

	// Ʈ�� �ʱ�ȭ.
	iTrackIdx = 0;
	aTrackInfo[0].bValid = false;

	// �������� ����.
	memcpy(aPlayStage, aStage[Num], sizeof(aStage[0]));

	for(x=0; x<NXTILE-1; ++x)
		for(y=0; y<NYTILE; ++y)
			if(aPlayStage[y][x] == '@')
			{
				// ���� ������������ �÷��̾� ����.
				aPlayStage[y][x] = ' ';

				// �÷��̾� ��ǥ ����.
				px = x;
				py = y;

				return;
			}
}

// �������� �׸���.
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

// ���� ���� �����ֱ�.
void DrawState()
{
	char szStage[256];
	char szMove[256];
	char szTotMove[256];
	HDC hDC;
	TEXTMETRIC tm;
	int gap; // ���� ������ ����.
	
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

// �÷��̾� �׸���.
void DrawPlayer()
{
	HDC hDC = GetDC(g_hWnd);
	BitBlt(hDC, px*CXTILE+XSTAGE, py*CYTILE+YSTAGE, CXTILE, CYTILE,
		GetBitmapInfo(BI_INDEX, iDir)->hMemDC, 0, 0, SRCCOPY);
	ReleaseDC(g_hWnd, hDC);
}

// �̵�.
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

		// ������ ���� ����.
		aTrackInfo[iTrackIdx].bValid = true;
		aTrackInfo[iTrackIdx].x = x;
		aTrackInfo[iTrackIdx].y = y;
		aTrackInfo[iTrackIdx].bWithLoad = bPush;
		aTrackInfo[++iTrackIdx].bValid = false;

		// Ʈ�� �뷮 �ʰ��Ǹ� ������ �����Ͽ� ������ Ȯ���Ѵ�.
		if(iTrackIdx == NTRACK-1)
		{
			// �������� ����.
			for(i=0; i<NTRACK-NSLICE; ++i)
				aTrackInfo[i] = aTrackInfo[i+NSLICE];

			// ���� �κ��� ��ȿȭ.
			for(i=NTRACK-NSLICE; i<NTRACK; ++i)
				aTrackInfo[i].bValid = false;

			// �ε����� �������� ��ġ.
			iTrackIdx -= NSLICE;
		}

		InvalidateRect(g_hWnd, NULL, FALSE);
	}
}

// ���� ���� �޽���.
bool GameOverMsg()
{
	char msg[256];

	sprintf(msg, "�����մϴ�!!\n�� ������ Ƚ�� : %d\n�ٽ� �����Ͻðڽ��ϱ�?", nTotMove);
	return MessageBox(g_hWnd, msg, "GameOver", MB_YESNO | MB_ICONINFORMATION) == IDYES;
}

// â�� ȭ���� �� á���� �˻�.
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

// �� �����.
void EraseLoad(int X, int Y)
{
	if(aStage[iStage][Y][X]	== '.')
		aPlayStage[Y][X] = '.';
	else
		aPlayStage[Y][X] = ' ';
}

// �������.
void Undo()
{
	if(iTrackIdx > 0)
	{
		iTrackIdx--;

		// ���� ���.
		x = aTrackInfo[iTrackIdx].x;
		y = aTrackInfo[iTrackIdx].y;

		// ���� ���� ��ġ��.
		if(aTrackInfo[iTrackIdx].bWithLoad)
		{
			EraseLoad(px+x, py+y);
			aPlayStage[py][px] = 'O';
		}

		// �÷��̾ ���� ��ġ��.
		px -= x;
		py -= y;

		// ���� �ٲٱ�.
		iDir = GetBitmapIdx(x, y);

		InvalidateRect(g_hWnd, NULL, FALSE);
	}
}

// �����.
void Redo()
{
	if(aTrackInfo[iTrackIdx].bValid)
	{
		// ���� ���.
		x = aTrackInfo[iTrackIdx].x;
		y = aTrackInfo[iTrackIdx].y;

		// �÷��̾ ���� ��ġ��.
		px += x;
		py += y;

		// ���� ���� ��ġ��.
		if(aTrackInfo[iTrackIdx].bWithLoad)
		{
			EraseLoad(px, py);
			aPlayStage[py+y][px+x] = 'O';
		}

		// ���� �ٲٱ�.
		iDir = GetBitmapIdx(x, y);

		iTrackIdx++;
		InvalidateRect(g_hWnd, NULL, FALSE);
	}
}

// �̵� ���⿡ ���� ��Ʈ�� �ε��� ���.
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

// ��Ʈ�� ���� ã��.
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