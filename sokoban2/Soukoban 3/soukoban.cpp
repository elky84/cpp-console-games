#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <conio.h>
#include "myUtility.h"

void Gotoxy(int x, int y)
{
	COORD cur = { x, y };

	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), cur );
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO curInfo;

	curInfo.dwSize = sizeof(curInfo);
	curInfo.bVisible = false;

	SetConsoleCursorInfo( GetStdHandle(STD_OUTPUT_HANDLE), &curInfo );
}

bool ReadFile(
	const char *pszPath,
	char **ppBuf,
	int *pcbSize)
{
	std::ifstream in(pszPath);
	if(in == NULL)
	{
		return false;
	}

	in.seekg(0, std::ifstream::end);
	*pcbSize = static_cast<int>(in.tellg());
	in.seekg(0, std::ifstream::beg);
	*ppBuf = new char[*pcbSize];
	in.read(*ppBuf, *pcbSize);

	return true;
}

template <typename T>
class MYARRAY2D
{
protected:
public:
	T *pArray;
	int cnx;
	int cny;

public:

	MYARRAY2D()
	{
		pArray = NULL;
	}

	~MYARRAY2D()
	{
		cleanup();
	}

	void cleanup()
	{
		delete [] pArray;
		pArray = NULL;
	}

	void setSize(int xNum, int yNum)
	{
		cleanup();
		cnx = xNum;
		cny = yNum;
		pArray = new T[cnx * cny];
	}

	int getXNum()
	{
		return cnx;
	}

	int getYNum()
	{
		return cny;
	}

	int getEleNum()
	{
		return cnx * cny;
	}

	T& operator[](int index)
	{
		return pArray[index];
	}

	const T& operator[](int index) const
	{
		return pArray[index];
	}

	T& operator()(int x, int y)
	{
		return pArray[cnx * y + x];
	}

	const T& operator()(int x, int y) const
	{
		return pArray[cnx * y + x];
	}
};

enum OBJECT
{
	OBJ_EMPTY,
	OBJ_WALL,
	OBJ_LOAD,
	OBJ_PLAYER,
};

class STAGE
{
protected:
	MYARRAY2D<OBJECT>	m_map;
	MYARRAY2D<bool>		m_goals;
	int					m_cnSize;
	int					m_width, m_height;

	void setSize(const char *pMapData)
	{
		int i;
		int x, y;

		x = y = 0;
		m_width = 0;
		m_height = 0;

		for(i=0; i<m_cnSize; ++i)
		{
			if(pMapData[i] == '\n')
			{
				m_width = max(m_width, x);
				m_height++;
				x = 0;
			}
			else if( strchr(" .oOpP#", pMapData[i]) )
			{
				x++;
			}
			else
			{
				// '\r'과 같이 필요없는 데이터는 건너뛴다.
			}
		}

		// 맵끝에 줄바꿈이 없을 경우 높이가 하나 추가가 안되기 때문에
		// 그 라인에 데이터가 하나라도 있다면 하나 더 추가해 준다.
		if(x != 0)
		{
			m_width = max(m_width, x);
			m_height++;
		}

		m_map.setSize(m_width, m_height);
		m_goals.setSize(m_width, m_height);
	}

public:
	void loadStage(const char *pszPath)
	{
		char	*pMap;
		int		x, y;
		OBJECT	obj;
		bool	bGoal;

		ReadFile(pszPath, &pMap, &m_cnSize);
		setSize(pMap);

		// 존재하지 않는 부분은 공백으로 채워 넣기위해 전부 공백으로 초기화.
		for(int x=0; x<m_width; ++x)
		{
			for(int y=0; y<m_height; ++y)
			{
				m_map(x,y) = OBJ_EMPTY;
				m_goals(x,y) = false;
			}
		}

		x = y = 0;
		for(int i=0; i<m_cnSize; ++i)
		{
			bGoal = false;

			switch(pMap[i])
			{
			case ' ':
				obj = OBJ_EMPTY;
				break;

			case '#':
				obj = OBJ_WALL;
				break;

			case 'o':
				obj = OBJ_LOAD;
				break;

			case 'O':
				obj = OBJ_LOAD;					
				bGoal = true;
				break;

			case '.':
				obj = OBJ_EMPTY;
				bGoal = true;
				break;

			case 'p':
				obj = OBJ_PLAYER;
				break;

			case 'P':
				obj = OBJ_PLAYER;
				bGoal = true;
				break;

			case '\n':
				x = 0;
				y++;

			default:
				// 필요없는 데이터는 건너뛴다.
				continue;
			}

			m_map(x,y) = obj;
			m_goals(x,y) = bGoal;
			x++;
		}
	}

	void drawStage()
	{
		int x, y;
		char ch;

		for(y=0; y<m_height; ++y)
		{
			for(x=0; x<m_width; ++x)
			{
				switch(m_map(x,y))
				{
				case OBJ_EMPTY:
					ch = m_goals(x,y) ? '.' : ' ';
					break;
					
				case OBJ_WALL:
					ch = '#';
					break;

				case OBJ_LOAD:
					ch = m_goals(x,y) ? 'O' : 'o';
					break;

				case OBJ_PLAYER:
					ch = m_goals(x,y) ? 'P' : 'p';
					break;
				}

				Gotoxy(x, y);
				printf("%c", ch);
			}
		}
	}

	void updateStage(char chKey)
	{
		int x, y;		// iterate x,y
		int px, py;		// player x,y
		int dx, dy;		// delta x,y

		dx = 0;
		dy = 0;
		chKey = chKey >= 'a' ? 'A' + chKey - 'a' : chKey;

		switch(chKey)
		{
		case 'A':
			dx = -1;
			break;

		case 'D':
			dx = 1;
			break;

		case 'W':
			dy = -1;
			break;

		case 'S':
			dy = 1;
			break;

		default:
			return;
		}

		// 플레이어 위치찾기.
		for(x=0; x<m_map.getXNum(); ++x)
		{
			for(y=0; y<m_map.getYNum(); ++y)
			{
				if(m_map(x, y) == OBJ_PLAYER)
				{
					px = x;
					py = y;
				}
			}
		}

		// 이동하기.
		if(m_map(px+dx, py+dy) == OBJ_EMPTY)
		{
			m_map(px+dx, py+dy) = OBJ_PLAYER;
			m_map(px, py) = OBJ_EMPTY;
		}
		else if(m_map(px+dx, py+dy) == OBJ_LOAD &&
			m_map(px+dx*2, py+dy*2) == OBJ_EMPTY)
		{
			m_map(px+dx*2, py+dy*2) = OBJ_LOAD;
			m_map(px+dx, py+dy) = OBJ_PLAYER;
			m_map(px, py) = OBJ_EMPTY;
		}
	}

	bool isCleared()
	{
		int x, y;
				
		for(x=0; x<m_map.getXNum(); ++x)
		{
			for(y=0; y<m_map.getYNum(); ++y)
			{
				if(m_goals(x,y) && m_map(x,y) == OBJ_EMPTY)
				{
					return false;
				}
			}
		}

		return true;
	}
};

void main()
{
	const int max = 2;

	int i;
	STAGE stage[max];
	char ch;
	
	for(i=0; i<max; ++i)
	{
		char str[256];

		sprintf(str, "stage%d.txt", i+1);
		stage[i].loadStage(str);
	}

	HideCursor();

	for(i=0; i<max;)
	{
		stage[i].drawStage();
		ch = getch();
		stage[i].updateStage(ch);
		if(stage[i].isCleared())
		{
			stage[i].drawStage();
			printf("Congratulate!! go to next stage\n");
			getch();
			system("cls");
			i++;
		}
	}

	getch();
}