#pragma comment(lib,"msimg32.lib")
#include "myUtility.h"
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <float.h>

#pragma warning(disable:4996)

//------------------------------------------------------------------------------
// MyBaseMap
//------------------------------------------------------------------------------

MYBASEMAP::MYBASEMAP(HDC _hdc)
{
	hdc = _hdc;
}

void MYBASEMAP::baseMode()
{
	// 맵핑모드를 잠시 좌상단으로 설정한다.
	SetWindowOrgEx(hdc, 0, 0, &winOrg);
	SetViewportOrgEx(hdc, 0, 0, &viewOrg);
	SetWindowExtEx(hdc, 1, 1, &winExt);
	SetViewportExtEx(hdc, 1, 1, &viewExt);
	mapMode = SetMapMode(hdc, MM_TEXT);
}

void MYBASEMAP::resumeMode()
{
	// 맵핑모드를 원래대로 돌려 놓는다.
	SetMapMode(hdc, mapMode);
	SetWindowOrgEx(hdc, winOrg.x, winOrg.y, NULL);
	SetViewportOrgEx(hdc, viewOrg.x, viewOrg.y, NULL);
	SetWindowExtEx(hdc, winExt.cx, winExt.cy, NULL);
	SetViewportExtEx(hdc, viewExt.cx, viewExt.cy, NULL);
}

//------------------------------------------------------------------------------
// MyXForm
//------------------------------------------------------------------------------

MYXFORM::MYXFORM()
{
}

MYXFORM::MYXFORM(
		float e11, float e12,
		float e21, float e22,
		float dx, float dy)
{
	setForm(e11, e12, e21, e22, dx, dy);
}

MYXFORM MYXFORM::setForm(
		float e11, float e12,
		float e21, float e22,
		float dx, float dy)
{
	eM11 = e11;
	eM12 = e12;
	eM21 = e21;
	eM22 = e22;
	eDx = dx;
	eDy = dy;

	return *this;
}

MYXFORM MYXFORM::setBase()
{
	return setForm(1, 0, 0, 1, 0, 0);
}

MYXFORM MYXFORM::setMove(float x, float y)
{
	return setForm(1, 0, 0, 1, x, y);
}

MYXFORM MYXFORM::setScale(float x, float y)
{
	return setForm(x, 0, 0, y, 0, 0);
}

MYXFORM MYXFORM::setRot(float angle)
{
	return setForm( cos(angle), sin(angle), -sin(angle), cos(angle), 0, 0 );
}

MYXFORM MYXFORM::operator *(const MYXFORM &other) const
{
	return MYXFORM(
		(eM11 * other.eM11) + (eM12 * other.eM21),
		(eM11 * other.eM12) + (eM12 * other.eM22),
		(eM21 * other.eM11) + (eM22 * other.eM21),
		(eM21 * other.eM12) + (eM22 * other.eM22),
		(eDx * other.eM11) + (eDy * other.eM21) + (1 * other.eDx),
		(eDx * other.eM12) + (eDy * other.eM22) + (1 * other.eDy) );
}

//------------------------------------------------------------------------------
// MyBmp
//------------------------------------------------------------------------------

MYBMP::MYBMP()
{
	hBmp = NULL; 
}

MYBMP::~MYBMP()
{
	cleanup();
}

void MYBMP::cleanup()
{
	if(hBmp)
		DeleteObject(hBmp);
	hBmp = NULL;
}

void MYBMP::loadBmp(HINSTANCE hInst, DWORD idBmp)
{	
	BITMAP	bmp;

	cleanup();

	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(idBmp));
	if(!hBmp)
		myBreakPoint();
		
	GetObject(hBmp, sizeof(bmp), &bmp);
	cxBmp = bmp.bmWidth;
	cyBmp = bmp.bmHeight;

	crKey = 0;
	nxSprites = 1;
	nySprites = 1;
	cxSprites = cxBmp;
	cySprites = cyBmp;
}

void MYBMP::loadBmp(
		HINSTANCE hInst, DWORD idBmp,
		DWORD nxSpr, DWORD nySpr, COLORREF colorKey)
{
	loadBmp(hInst, idBmp);

	crKey = colorKey;
	nxSprites = nxSpr;
	nySprites = nySpr;
	cxSprites = cxBmp / nxSprites;
	cySprites = cyBmp / nySprites;
};

void MYBMP::drawBmp(HDC hdc, int x, int y) const
{
	if(!hBmp)
		myBreakPoint();

	HDC		hMemDC;
	HBITMAP hOldBmp;

	hMemDC = CreateCompatibleDC(hdc);
	hOldBmp = (HBITMAP)SelectObject(hMemDC, hBmp);

	BitBlt(hdc, x, y, cxBmp, cyBmp, hMemDC, 0, 0, SRCCOPY);

	SelectObject(hMemDC, hOldBmp);
	DeleteDC(hMemDC);
}

void MYBMP::drawBmp(
		HDC hdc, const MYXFORM *pXForm,
		DWORD xIdx, DWORD yIdx, bool bUseColorKey) const
{
	if(!hBmp)
		myBreakPoint();

	if(xIdx >= nxSprites || yIdx >= nySprites)
		myBreakPoint();

	HDC			hBitDC;
	HBITMAP		hOldBmp;
	int			x, y, cx, cy;

	SetGraphicsMode(hdc, GM_ADVANCED);
	SetWorldTransform(hdc, pXForm);

	hBitDC	= CreateCompatibleDC(hdc);
	hOldBmp = (HBITMAP)SelectObject(hBitDC, hBmp);

	// 그림의 한 스프라이트 지점과 크기 구하기.
	x	= xIdx * cxSprites;
	y	= yIdx * cySprites;
	cx	= x + cxSprites;
	cy  = y + cySprites;

	if(bUseColorKey)
	{
		TransparentBlt(
			hdc, -(int)(cxSprites/2), -(int)(cxSprites/2), cxSprites, cxSprites,
			hBitDC, x, y, cx, cy, crKey);
	}
	else
	{
		StretchBlt(
			hdc, -(int)(cxSprites/2), -(int)(cxSprites/2), cxSprites, cxSprites,
			hBitDC, x, y, cx, cy, SRCCOPY);
	}

	SelectObject(hBitDC, hBmp);
	DeleteDC(hBitDC);

	SetWorldTransform(hdc, &MYXFORM(1,0,0,1,0,0));
	SetGraphicsMode(hdc, GM_COMPATIBLE);
}

//------------------------------------------------------------------------------
// MyRect
//------------------------------------------------------------------------------

void MYRECT::setRect(LONG l, LONG t, LONG r, LONG b)
{
	left	= l;
	top		= t;
	right	= r;
	bottom	= b;
}

void MYRECT::setSize(LONG x, LONG y, LONG w, LONG h)
{
	left	= x;
	top		= y;
	right	= x + w;
	bottom	= y + h;
}

LONG MYRECT::width(bool bAbs) const
{
	return bAbs==true ? myAbs(right-left) : right-left;
}

LONG MYRECT::height(bool bAbs) const
{
	return bAbs==true ? myAbs(bottom-top) : bottom-top;
}

POINT MYRECT::center(LONG *px, LONG *py) const
{
	POINT pt;

	pt.x = (left + right) / 2;
	pt.y = (top + bottom) / 2;
	if(px)	*px = pt.x;
	if(py)	*py = pt.y;

	return pt;
}

//------------------------------------------------------------------------------
// MyTimeLap
//------------------------------------------------------------------------------

MYTIMELAP::MYTIMELAP()
{
	bStart = false;
	tmTotalPaused = 0;
}

void MYTIMELAP::start()
{
	if(bStart)
		return;

	bStart = true;
	bPause = false;
	QueryPerformanceCounter((LARGE_INTEGER *)&tmLatest);
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	if(freq == 0)
		myBreakPoint();
}

void MYTIMELAP::pause()
{
	if(bPause)
		return;

	bPause = true;
	QueryPerformanceCounter((LARGE_INTEGER *)&tmPaused);
}

// 현재 시간부터 최신의 시간까지의 간격을 초단위로 조사
double MYTIMELAP::lap()
{
	INT64	now;
	double	gap;

	if(!bStart)
		myBreakPoint();

	QueryPerformanceCounter((LARGE_INTEGER *)&now);

	if(bPause)
	{
		tmTotalPaused += now - tmPaused;
		bPause = false;
	}

	// 시스템 시간은 언제나 흘러가기 때문에
	// 우리가 원하는 현재 시간은, 멈춤 시간만큼 빼야한다.
	now -= tmTotalPaused;

	gap = (double)(now - tmLatest);
	gap /= (double)freq;
	tmLatest = now;

	return gap;
}

//------------------------------------------------------------------------------
// MyBackBuf
//------------------------------------------------------------------------------

MYBACKBUF::MYBACKBUF()
{
	hBmp = NULL;
}

MYBACKBUF::~MYBACKBUF()
{
	cleanup();
}

void MYBACKBUF::setBuf(HDC hdc, LONG width, LONG height)
{
	cleanup();
	
	rect.left	= 0;
	rect.top	= 0;
	rect.right	= width;
	rect.bottom	= height;

	hBmp		= CreateCompatibleBitmap(hdc, width, height);
	hMemDC		= CreateCompatibleDC(hdc);
	SelectObject(hMemDC, hBmp);
}


void MYBACKBUF::setBuf(HWND hwnd, LONG width, LONG height)
{
	HDC hdc;

	hdc = GetDC(hwnd);
	setBuf(hdc, width, height);
	ReleaseDC(hwnd, hdc);
}

void MYBACKBUF::setBuf(HWND hwnd)
{
	HDC hdc;
	RECT crt;

	hdc = GetDC(hwnd);
	GetClientRect(hwnd, &crt);
	setBuf(hdc, crt.right, crt.bottom);
	ReleaseDC(hwnd, hdc);
}

void MYBACKBUF::initChk() const
{
	if(hBmp == NULL)
		myBreakPoint();
}

void MYBACKBUF::setCoordSys(MYCOORDSYS coordSys)
{
	initChk();

	LONG width, height;

	if(coordSys >= 1 && coordSys <= 5)
	{
		SetMapMode(hMemDC, MM_ANISOTROPIC);
		SetWindowExtEx(hMemDC, 1, 1, NULL);
		SetViewportExtEx(hMemDC, 1, -1, NULL);
	}

	width	= rect.width(true);
	height	= rect.height(true);

	switch(coordSys)
	{
	case MY_COORD_DESCARTES:
		SetViewportOrgEx(hMemDC, width/2, height/2, NULL);
		rect.left	= -(width / 2);
		rect.top	= height / 2;
		rect.right	= width / 2;
		rect.bottom	= -(height / 2);
		break;

	case MY_COORD_QUADRANT_1:
		SetViewportOrgEx(hMemDC, 0, height, NULL);
		rect.left	= 0;
		rect.top	= height;
		rect.right	= width;
		rect.bottom	= 0;
		break;

	case MY_COORD_QUADRANT_2:
		SetViewportOrgEx(hMemDC, width, height, NULL);
		rect.left	= -width;
		rect.top	= height;
		rect.right	= 0;
		rect.bottom	= 0;
		break;

	case MY_COORD_QUADRANT_3:
		SetViewportOrgEx(hMemDC, width, 0, NULL);
		rect.left	= -width;
		rect.top	= 0;
		rect.right	= 0;
		rect.bottom	= -height;
		break;

	case MY_COORD_QUADRANT_4:
		rect.left	= 0;
		rect.top	= 0;
		rect.right	= width;
		rect.bottom	= -height;
		break;

	case MY_COORD_TEXT:
		SetMapMode(hMemDC, MM_TEXT);
		SetWindowExtEx(hMemDC, 1, 1, NULL);
		SetViewportExtEx(hMemDC, 1, 1, NULL);
		rect.setRect(0, 0, width, height);
		break;
	}
}

void MYBACKBUF::cleanup()
{
	if(hBmp)
		DeleteObject(hBmp);
	if(hMemDC)
		DeleteDC(hMemDC);
	
	hBmp = NULL;
}

void MYBACKBUF::clear(COLORREF color)
{	
	initChk();

	HBRUSH	hbr, hbrOld;

	hbr		= CreateSolidBrush(color);
	hbrOld	= (HBRUSH)SelectObject(hMemDC, hbr);
	FillRect(hMemDC, &rect, hbr);

	SelectObject(hMemDC, hbrOld);
	DeleteObject(hbr);
}

void MYBACKBUF::pasteTo(HDC hdc, LONG xClient, LONG yClient)
{
	initChk();
	StretchBlt(hdc, xClient, yClient, rect.width(true), rect.height(true),
		hMemDC, rect.left, rect.top, rect.width(), rect.height(), SRCCOPY);
}

HDC MYBACKBUF::getDC() const
{
	initChk();
	return hMemDC;
}

MYRECT MYBACKBUF::getRect() const
{
	initChk();
	return rect;
}

//------------------------------------------------------------------------------
// MyVector
//------------------------------------------------------------------------------

MYVECTOR::MYVECTOR(double _x, double _y, double _z)
{
	setCoord(_x, _y, _z);
}

MYVECTOR::MYVECTOR(const MYVECTOR &other)
{
	setCoord(other.x, other.y, other.z);	
}

MYVECTOR & MYVECTOR::setCoord(double _x, double _y, double _z)
{
	x = _x;
	y = _y;
	z = _z;

	return *this;
}

double MYVECTOR::getNorm() const
{
	return sqrt(x*x + y*y + z*z);
}

MYVECTOR & MYVECTOR::setNorm(double scalar)
{
	return this->setUnit() *= scalar;
}

MYVECTOR MYVECTOR::getUnit() const
{
	double norm;

	norm = getNorm();
	if(norm != 0)
		return MYVECTOR(x/norm, y/norm, z/norm);
	
	myBreakPoint();
	return MYVECTOR(x, y, z);
}

MYVECTOR & MYVECTOR::setUnit()
{
	return *this = getUnit();
}

MYVECTOR MYVECTOR::operator -()
{
	return MYVECTOR(x=-x, y=-y, z=-z);
}

MYVECTOR & MYVECTOR::rotX(double r)
{
	double ty, tz;
	MYVECTOR yAxis(sin(r), cos(r));
	MYVECTOR zAxis(cos(r), -sin(r));

	ty = dot(this, &yAxis);
	tz = dot(this, &zAxis);

	y = ty;
	z = tz;
	return *this;
}

MYVECTOR & MYVECTOR::rotY(double r)
{
	double tx, tz;
	MYVECTOR xAxis(sin(r), cos(r));
	MYVECTOR zAxis(cos(r), -sin(r));

	tx = dot(this, &xAxis);
	tz = dot(this, &zAxis);

	x = tx;
	z = tz;
	return *this;
}

MYVECTOR & MYVECTOR::rotZ(double r)
{
	double tx, ty;
	MYVECTOR xAxis(cos(r), -sin(r));
	MYVECTOR yAxis(sin(r), cos(r));

	tx = dot(this, &xAxis);
	ty = dot(this, &yAxis);

	x = tx;
	y = ty;
	return *this;
}

bool MYVECTOR::operator ==(const MYVECTOR &other) const
{
	if( myAbs(x - other.x) <= MY_EPSILON &&
		myAbs(y - other.y) <= MY_EPSILON &&
		myAbs(z - other.z) <= MY_EPSILON )
	{
		return true;
	}
	return false;
}

MYVECTOR & MYVECTOR::operator =(const MYVECTOR &other)
{
	x = other.x;
	y = other.y;
	z = other.z;

	return *this;
}

MYVECTOR MYVECTOR::operator +(const MYVECTOR &other) const
{
	return MYVECTOR(x+other.x, y+other.y, z+other.z);
}

MYVECTOR & MYVECTOR::operator +=(const MYVECTOR &other)
{
	return *this = *this + other;
}

MYVECTOR MYVECTOR::operator -(const MYVECTOR &other) const
{
	return MYVECTOR(x-other.x, y-other.y, z-other.z);
}

MYVECTOR & MYVECTOR::operator -=(const MYVECTOR &other)
{
	return *this = *this - other;
}

MYVECTOR MYVECTOR::operator *(double scalar) const
{
	return MYVECTOR(x*scalar, y*scalar, z*scalar);
}

MYVECTOR operator *(double scalar, const MYVECTOR &other)
{
	return other * scalar;
}

MYVECTOR & MYVECTOR::operator *=(double scalar)
{
	return *this = *this * scalar;
}

MYVECTOR MYVECTOR::operator /(double scalar) const
{
	if(scalar != 0.0)
		return MYVECTOR(x/scalar, y/scalar, z/scalar);

	myBreakPoint();
	return MYVECTOR(x, y, z);
}

MYVECTOR & MYVECTOR::operator /=(double scalar)
{
	return *this = *this / scalar;
}

double MYVECTOR::angleLow(const MYVECTOR *pa, const MYVECTOR *pb)
{
	double d;

	d = dot(&pa->getUnit(), &pb->getUnit());
	if(d > 1.0 || d < -1.0)
		myBreakPoint();

	if(d > 1.0)
		d = 1.0;
	else if(d < -1.0)
		d = -1.0;

	return acos(d);
}

double MYVECTOR::angleCCW(const MYVECTOR *pa, const MYVECTOR *pb)
{
	MYVECTOR	rot;
	double		angle;

	// 3차원 공간에서도 신뢰할 수 있는 값이 나오는가?

	angle = angleLow(pa, pb);
	rot	  = cross(pa, pb);
	if(rot.z < 0.0)
		angle = MY_TWOPI - angle;

	return angle;
}

double MYVECTOR::dot(const MYVECTOR *pa, const MYVECTOR *pb)
{
	return (pa->x * pb->x) + (pa->y * pb->y) + (pa->z * pb->z);
}

MYVECTOR MYVECTOR::cross(const MYVECTOR *pa, const MYVECTOR *pb)
{
	return MYVECTOR( 
		(pa->y * pb->z) - (pa->z * pb->y),
		(pa->z * pb->x) - (pa->x * pb->z),
		(pa->x * pb->y) - (pa->y * pb->x) );
}

//------------------------------------------------------------------------------
// MyGeometry
//------------------------------------------------------------------------------

MYGEOMETRY::MYGEOMETRY()
{
	pVerts	= NULL;
}

MYGEOMETRY::MYGEOMETRY(int num)
{
	pVerts = NULL;
	init(num);
}

MYGEOMETRY::~MYGEOMETRY()
{
	cleanup();
}

void MYGEOMETRY::init(UINT n)
{
	if(pVerts)
		cleanup();

	pVerts	= new MYVECTOR[n];
	num		= n;
}

void MYGEOMETRY::cleanup()
{
	if(pVerts)
	{
		delete [] pVerts;
		pVerts = NULL;
	}
}

UINT MYGEOMETRY::getNum() const
{
	return num;
}

MYVECTOR MYGEOMETRY::getCenter() const
{
	MYVECTOR center;

	for(UINT i=0; i<num; ++i)
	{
		center.x += pVerts[i].x;
		center.y += pVerts[i].y;
	}

	center.x /= num;
	center.y /= num;
	return center;
}

MYVECTOR & MYGEOMETRY::operator [](UINT idx)
{
	if(pVerts == NULL || idx >= num)
		myBreakPoint();

	return pVerts[idx];
}

const MYVECTOR & MYGEOMETRY::operator [](UINT idx) const
{
	MYGEOMETRY *pMy;

	pMy = (MYGEOMETRY *)this;
	return (*pMy)[idx];
}

//------------------------------------------------------------------------------
// Global Functions
//------------------------------------------------------------------------------

bool MySwap(void *in_pa, void *in_pb, int cbSize)
{
	int i;
	unsigned char *pa = (unsigned char *)in_pa;
	unsigned char *pb = (unsigned char *)in_pb;
	unsigned char tmp;

	if(pa==NULL || pb==NULL)
		return false;

	for(i=0; i<cbSize; ++i)
	{
		tmp = pa[i];
		pa[i] = pb[i];
		pb[i] = tmp;
	}

	return true;
}

// "", "" true
// "*", "" true
// "?", "" false
BOOL MyWildcard(
		const TCHAR *pWildcard,
		const TCHAR *pText)
{
	const TCHAR *wp, *tp;

	if(!pWildcard || !pText)
		return FALSE;

	// *를 만나기 전까지 같은 문자열인지 점검
	while(*pText && *pWildcard != '*')
	{
		if(*pWildcard != *pText && *pWildcard != '?')
			return FALSE;
		++pWildcard;
		++pText;
	}

	do
	{
		if(*pWildcard == '*')
		{
			if(!*++pWildcard)
				return TRUE;
			wp = pWildcard;
			tp = pText + 1;
		}

		// 같은 문자
		else if(*pWildcard == *pText || *pWildcard == '?')
		{
			// 문자열이 끝이 아닐경우 증가시킴
			// text: ""
			// wild: "?"
			if(*pText)
			{
				++pWildcard;		
				++pText;
			}
		}

		// 다른 문자
		else if(*pText)
		{
			// 문자열이 끝이 아닐경우 증가시킴
			// text: ""
			// wild: "A"
			pWildcard = wp;
			pText = tp++;
		}
	} while(*pText);
	// pText[0] == NULL 이라도 pWildcard가 *라면 찾은 것으로
	// 판정하기 위해 while문을 뒤쪽에 둠.

	return !*pWildcard;
}

/* 2012-04-27 deleted
// GetPointCenter
tagPoint MyGetPointCenter(
		const tagPoint *pPointList,
		int count)
{
	int i;
	double xAccum, yAccum;
	tagPoint ptCenter;

	xAccum = yAccum = 0;
	for(i=0; i<count; ++i)
	{
		xAccum += pPointList[i].x;
		yAccum += pPointList[i].y;
	}

	ptCenter.x = xAccum / count;
	ptCenter.y = yAccum / count;

	return ptCenter;
}
*/

// LengthConvert
double MyLengthConvert(
		double value,
		MYLENGTHUNIT from,
		MYLENGTHUNIT to)
{
	// 밀리미터 단위로 통일
	const static double unit[] =
	{
		1,			// Milimeter
		0.1,		// Centimeter
		0.001,		// Meter
		0.000001,	// Kilometer
		0.03937,	// Inch
		0.003281,	// Feet
		0.001094,	// Yard
		6.2137e-7,	// Mile
	};

	return value * unit[to] / unit[from];
}

double MyAngleConvert(
		double value,
		MYANGLEUNIT from,
		MYANGLEUNIT to)
{
	// 180도 단위로 통일.
	const static double unit[] =
	{
		180,				// Degree
		3.14159265358979,	// Radian
	};

	return value * unit[to] / unit[from];
}

// 클라이언트 영역에 알맞에 윈도우 크기를 조절한다.
BOOL MySetClientRect(HWND hWnd, int cxClient, int cyClient)
{
	RECT rect;
	LONG_PTR style, exStyle;

	style = GetWindowLongPtr(hWnd, GWL_STYLE);
	exStyle = GetWindowLongPtr(hWnd, GWL_EXSTYLE);
	SetRect(&rect, 0, 0, cxClient, cyClient);
	AdjustWindowRectEx(&rect, style, GetMenu(hWnd)!=NULL, exStyle);

	if(style & WS_VSCROLL)
		rect.right += GetSystemMetrics(SM_CXVSCROLL);
	if(style & WS_HSCROLL)
		rect.bottom += GetSystemMetrics(SM_CYHSCROLL);

	return SetWindowPos(
		hWnd, NULL, 0, 0,
		rect.right - rect.left,
		rect.bottom - rect.top,
		SWP_NOZORDER | SWP_NOMOVE);
}

POINT MyGetRectCenter(
		RECT *pRect,
		int *px/*=NULL*/,
		int *py/*=NULL*/)
{
	POINT ptCenter;

	ptCenter.x = ((*pRect).right - (*pRect).left) / 2;
	ptCenter.y = ((*pRect).bottom - (*pRect).top) / 2;

	if(px) *px = ptCenter.x;
	if(py) *py = ptCenter.y;

	return ptCenter;
}

POINT MyGetClientCenter(HWND hWnd, int *px/*=NULL*/, int *py/*=NULL*/)
{
	RECT rcClient;

	GetClientRect(hWnd, &rcClient);
	return MyGetRectCenter(&rcClient, px, py);
}

// cbUnit: 0x0000 0001 ~ 0x2000 0000 = 1, 2, 4, 8, ...
unsigned long MyBitToByte(
		unsigned long bit,
		unsigned long cbUnit)
{
	return (bit+(cbUnit<<3)-1 & ~((cbUnit<<3)-1)) >> 3;
}

int MyFindFile(
		const TCHAR *pPath,
		BOOL bSubDir,
		MYFINDFILEPROC pFindFileProc)
{
	HANDLE				hSearch;
	WIN32_FIND_DATA		wfd;
	BOOL				bResult = TRUE;

	static int			cFile;
	static BOOL			bContinue = TRUE;

	TCHAR				szDrive[_MAX_DRIVE];
	TCHAR				szDir[_MAX_DIR];
	TCHAR				szFName[_MAX_FNAME];
	TCHAR				szExt[_MAX_EXT];

	TCHAR				szNewPath[_MAX_PATH];
	TCHAR				szAllPath[_MAX_PATH];


	_tsplitpath(pPath, szDrive, szDir, szFName, szExt);
	wsprintf(szAllPath, TEXT("%s%s*.*"), szDrive, szDir);

	hSearch = FindFirstFile(szAllPath, &wfd);
	if(hSearch == INVALID_HANDLE_VALUE)
		return cFile;

	// 모든 파일 검색
	while(bResult)
	{
		// 폴더일 경우
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if(bSubDir
				&& lstrcmp( wfd.cFileName, TEXT(".") )
				&& lstrcmp( wfd.cFileName, TEXT("..") ))
			{
				wsprintf(szNewPath, TEXT("%s%s%s\\%s%s"),
					szDrive, szDir, wfd.cFileName, szFName, szExt);
				MyFindFile(szNewPath, bSubDir, pFindFileProc);
			}
		}

		// 파일일 경우
		else
		{	
			TCHAR file[_MAX_FNAME];
			TCHAR ext[_MAX_EXT];
			TCHAR *pWC = NULL;

			_tsplitpath(wfd.cFileName, NULL, NULL, file, ext);

			// 확장자의 .은 제외
			pWC = szExt + (szExt[0] == 0 ? 0 : 1);

			// 파일 이름이 같을 경우
			// ext[0]==0?(ext):(ext+1) -> 확장자의 .은 제외
			if( MyWildcard(szFName, file) &&
				( MyWildcard(pWC, ext[0]==0?(ext):(ext+1)) ) )
			{
				++cFile;
				wsprintf(szNewPath, TEXT("%s%s%s"),	szDrive, szDir, wfd.cFileName);

				if(pFindFileProc && pFindFileProc(szNewPath) == FALSE)
				{
					bContinue = FALSE;
					break;
				}
			}
		}

		if(!bContinue)
			break;

		bResult = FindNextFile(hSearch, &wfd);
	}

	FindClose(hSearch);
	return cFile;
}

// pFiles 끝에 끝을 나타내는 NULL을 넣어준다.
int MyFindFile(
		const TCHAR *pFolder,
		const TCHAR *const *pFiles,
		BOOL bSubDir,
		MYFINDFILEPROC pFindFileProc)
{
	HANDLE				hSearch;
	WIN32_FIND_DATA		wfd;
	BOOL				bResult = TRUE;

	static int			cFile;
	static BOOL			bContinue = TRUE;

	TCHAR				szDir[_MAX_DIR];
	TCHAR				szPath[_MAX_PATH];
	TCHAR				szNewPath[_MAX_PATH];

	// 폴더 경로 복사
	lstrcpy(szDir, pFolder);

	// 폴더명 끝에 \가 붙어있지 않으면 붙여줌
	if( szDir[ lstrlen(szDir)-1 ] != '\\' )
		lstrcat(szDir, TEXT("\\"));

	// 모든 폴더와 파일을 검색하기
	wsprintf(szPath, TEXT("%s%s"), szDir, TEXT("*.*"));

	hSearch = FindFirstFile(szPath, &wfd);
	if(hSearch == INVALID_HANDLE_VALUE)
		return cFile;

	// 모든 파일 검색
	while(bResult)
	{
		// 폴더일 경우.
		if(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		{
			if( bSubDir
				&& lstrcmp(wfd.cFileName, TEXT("."))
				&& lstrcmp(wfd.cFileName, TEXT("..")) )
			{
				wsprintf(szNewPath, TEXT("%s%s"), szDir, wfd.cFileName);
				MyFindFile(szNewPath, pFiles, bSubDir, pFindFileProc);
			}
		}

		// 파일일 경우
		else
		{	
			int i;
			TCHAR szSrchFile[_MAX_FNAME];
			TCHAR szScanFile[_MAX_FNAME];
			TCHAR szSrchExt[_MAX_EXT];
			TCHAR szScanExt[_MAX_EXT];
			TCHAR *pWC;
			TCHAR *pExt;

			_tsplitpath(wfd.cFileName, NULL, NULL, szScanFile, szScanExt);

			// 확장자의 .은 제외
			pExt = szScanExt + (szScanExt[0] == 0 ? 0 : 1);

			// 등록된 파일명 중 매치되는 것이 있는지 검사
			for(i=0; pFiles[i]; ++i)
			{
				_tsplitpath(pFiles[i], NULL, NULL, szSrchFile, szSrchExt);
				
				// 확장자의 .은 제외
				pWC = szSrchExt + (szSrchExt[0] == 0 ? 0 : 1);

				if(MyWildcard(szSrchFile, szScanFile) && MyWildcard(pWC, pExt))
				{
					wsprintf(szNewPath, TEXT("%s%s"), szDir, wfd.cFileName);
					if(pFindFileProc && pFindFileProc(szNewPath) == FALSE)
						bContinue = FALSE;

					++cFile;
					break;
				}
			}
		}

		if(!bContinue)
			break;

		bResult = FindNextFile(hSearch, &wfd);
	}

	FindClose(hSearch);
	return cFile;
}

bool SaveData(void *pData, DWORD cbSize, const TCHAR *pszPath)
{
	HANDLE hFile;
	DWORD cbWritten;

	hFile = CreateFile(
		pszPath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL, NULL);

	if(hFile == INVALID_HANDLE_VALUE)
		return false;

	WriteFile(hFile, pData, cbSize, &cbWritten, NULL);
	CloseHandle(hFile);

	return true;
}

// 1601년 1월 1일 부터 지난간 날을 조사
DWORD MyGetAbsDay(SYSTEMTIME st)
{
	FILETIME	fileTime;
	INT64		absTime;

	// 절대 날자로 바꾸기 위해 날자 아래 단위들은 버린다
	st.wDayOfWeek		= 0;
	st.wHour			= 0;
	st.wMinute			= 0;
	st.wSecond			= 0;
	st.wMilliseconds	= 0;

	SystemTimeToFileTime(&st, &fileTime);

	// 절대 시간으로 바꾸기
	absTime = ((INT64)fileTime.dwHighDateTime << 32) + fileTime.dwLowDateTime;

	// FILETIME 의 단위는 1 / 10,000,000 초이다.
	// 그래서 하루 단위로 바꾸러면 864,000,000,000 로 나눈다.
	absTime /= 860000000000;

	return (DWORD)absTime;
}

// 1970년 1월 1일 1초부터 지나간 초를 조사
// 1970년 ~ 2106년 까지 가능
DWORD MyGetAbsSec(SYSTEMTIME st)
{
	FILETIME	ft;
	INT64		absSec;

	SystemTimeToFileTime(&st, &ft);
	absSec = ((INT64)ft.dwHighDateTime << 32) + ft.dwLowDateTime;

	// 1970년 - 1601년 = 11,636,784,000초
	// FILETIME의 단위 = 1 / 10,000,000 초
	absSec = absSec / 10000000 - 11636784000;

	return (DWORD)absSec;
}

// 절대 날을 시스템 타임 타입으로 바꾸기
void MyAbsDayToSysTime(DWORD dwAbsDay, SYSTEMTIME *pSysTime)
{
	INT64			absTime;
	FILETIME		fileTime;

	absTime = (INT64)dwAbsDay * 864000000000;
	fileTime.dwHighDateTime	= (DWORD)(absTime >> 32);
	fileTime.dwLowDateTime	= (DWORD)(absTime & 0xFFFFFFFF);
	FileTimeToSystemTime(&fileTime, pSysTime);
}

// 절대 초를 시스템 타임 타입으로 바꾸기
void MyAbsSecToSysTime(DWORD dwAbsSec, SYSTEMTIME *pSysTime)
{
	INT64		absTime;
	FILETIME	ft;

	// 1970년에서 시작하는 초단위를
	// 1601년에서 시작하는 1 / 10,000,000 초 단위 만들기
	absTime = (dwAbsSec + 11636784000) * 10000000;

	ft.dwHighDateTime	= (DWORD)(absTime >> 32);
	ft.dwLowDateTime	= (DWORD)(absTime & 0xFFFFFFFF);
	FileTimeToSystemTime(&ft, pSysTime);
}

// 날짜를 건네주면 요일을 조사한다
// 0 = 일요일
// 6 = 토요일
int MyGetDayOfWeek(int year, int month, int day)
{
	SYSTEMTIME		st;
	FILETIME		ft;

	memset(&st, 0, sizeof(st));
	st.wYear	= year;
	st.wMonth	= month;
	st.wDay		= day;

	SystemTimeToFileTime(&st, &ft);
	FileTimeToSystemTime(&ft, &st);

	return st.wDayOfWeek;
}

// 한 달에 포함되어 있는 날 수를 구한다
int MyGetMonthEnd(int year, int month)
{
	const static int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int lastDay;

	lastDay = days[month];
	if( month==2 && (year%4==0 && year%100!=0 || year%400==0) )
		lastDay = 29;

	return lastDay;
}

// 부팅 시각을 조사한다
void MyGetBootTime(SYSTEMTIME *pBootTime)
{
	SYSTEMTIME stNowTime;

	DWORD	dwNowAbsSec;
	DWORD	dwEllipse;

	dwEllipse = GetTickCount() / 1000;
	GetLocalTime(&stNowTime);
	dwNowAbsSec = MyGetAbsSec(stNowTime);
	MyAbsSecToSysTime(dwNowAbsSec - dwEllipse, pBootTime);
}

// 컬러키로 지정된 부분은 투명하게 처리하여 보여진다.
void MyTransparentBlt(HDC hdc, int x, int y, HBITMAP in_hBitmap, COLORREF colorKey)
{
	BITMAP bitmap;
	COLORREF color;

	HBITMAP hBitKey;	// 컬러키 마스크. (컬러키=0, 객체=1)
	HBITMAP hBitObj;	// 객체 마스크. (컬러키=1, 객체=0)
	HBITMAP hBitWork;	// 비트 연산을 작업 하기위한 공간.

	HBITMAP bitKeyOld;
	HBITMAP bitObjOld;
	HBITMAP bitWorkOld;
	
	HDC		hdcImg;		// 입력된 비트맵을 위한 dc.
	HDC		hdcWork;	// 이미지들을 조합하기 위한 dc.
	HDC		hdcKey;		// 컬러키 마스크의 dc.
	HDC		hdcObj;		// 객체 마스크의 dc.

	POINT	ptSize; // 이미지 크기.

	hdcImg = CreateCompatibleDC(hdc);
	SelectObject(hdcImg, in_hBitmap);
	GetObject(in_hBitmap, sizeof(BITMAP), &bitmap);
	ptSize.x = bitmap.bmWidth;
	ptSize.y = bitmap.bmHeight;
	DPtoLP(hdcImg, &ptSize,1);

	hdcKey		= CreateCompatibleDC(hdc);
	hdcObj		= CreateCompatibleDC(hdc);
	hdcWork		= CreateCompatibleDC(hdc);

	// 단색(모노크롬)으로 비트맵 생성.
	hBitKey		= CreateBitmap(ptSize.x, ptSize.y, 1, 1, NULL);
	// 단색(모노크롬)으로 비트맵 생성.
	hBitObj		= CreateBitmap(ptSize.x, ptSize.y, 1, 1, NULL); 
	// 현재 장치와 호환되는 비트맵을 생성.
	hBitWork	= CreateCompatibleBitmap(hdc, ptSize.x, ptSize.y);
	
	bitKeyOld	= (HBITMAP) SelectObject(hdcKey, hBitKey);
	bitObjOld	= (HBITMAP) SelectObject(hdcObj, hBitObj);
	bitWorkOld	= (HBITMAP) SelectObject(hdcWork, hBitWork);

	SetMapMode(hdcImg, GetMapMode(hdc));

	// 배경을 빨강색으로 해주면 컬러->단색 으로 변환할 때
	// 빨강색을 1로써, 그 외의 색은 0으로 인식하여 단색으로 변환한다.
	color = SetBkColor(hdcImg, colorKey);
	BitBlt(hdcObj, 0, 0, ptSize.x, ptSize.y, hdcImg, 0, 0, SRCCOPY); 
	SetBkColor(hdcImg, color);

	// 컬러키 마스크 얻기.
	BitBlt(hdcKey, 0, 0, ptSize.x, ptSize.y, hdcObj, 0, 0, NOTSRCCOPY);

	// 화면 dc 내용을 작업 dc로 복사한다.
	BitBlt(hdcWork, 0, 0, ptSize.x, ptSize.y, hdc, x, y, SRCCOPY);

	// 컬러키 부분의 이미지 얻기.
	BitBlt(hdcWork, 0, 0, ptSize.x, ptSize.y, hdcObj, 0, 0, SRCAND);

	// 객체 부분의 이미지 얻기.
	BitBlt(hdcImg, 0, 0, ptSize.x, ptSize.y, hdcKey, 0, 0, SRCAND);

	// 컬러키 부분의 배경이미지와 객체 이미지를 더한다.
	BitBlt(hdcWork, 0, 0, ptSize.x, ptSize.y, hdcImg, 0, 0, SRCPAINT);

	// 화면에다가 필터된 비트맵을 뿌려준다.
	BitBlt(hdc, x, y, ptSize.x, ptSize.y, hdcWork, 0, 0, SRCCOPY);

	DeleteObject(SelectObject(hdcKey, bitKeyOld));
	DeleteObject(SelectObject(hdcObj, bitObjOld));
	DeleteObject(SelectObject(hdcWork, bitWorkOld));
	
	DeleteDC(hdcKey);
	DeleteDC(hdcObj);
	DeleteDC(hdcWork);
	DeleteDC(hdcImg);
}

// DIB(Device Independent Bitmap) 이미지 불러오기
bool MyLoadDIB(
		TCHAR *pszPath,
		BITMAPFILEHEADER **ppFileHeader,
		BITMAPINFOHEADER **ppInfoHeader,
		RGBQUAD **ppRgbQuad,
		void **ppRaster)
{
	HANDLE		hFile;
	DWORD		cbSize;
	DWORD		cbReaded;

	if(pszPath == NULL || ppFileHeader == NULL)
		return false;

	hFile = CreateFile(
		pszPath, GENERIC_READ, 0, NULL, OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL, NULL);
	if(hFile == INVALID_HANDLE_VALUE)
		return false;

	cbSize = GetFileSize(hFile, NULL);

	// BMP 정보 읽어오기.
	(*ppFileHeader) = (BITMAPFILEHEADER *)malloc(cbSize);
	ReadFile(hFile, (*ppFileHeader), cbSize, &cbReaded, NULL);

	CloseHandle(hFile);

	// InfoHeader 정보 시작지점.
	if(ppInfoHeader)
	{
		(*ppInfoHeader) = 
			(BITMAPINFOHEADER *)
			((BYTE *)(*ppFileHeader) + sizeof(BITMAPFILEHEADER));
	}

	// RGBQuad 정보 시작지점.
	if(ppRgbQuad)
	{
		(*ppRgbQuad) = 
			(RGBQUAD *)
			( (BYTE *)(*ppFileHeader) + 
				sizeof(BITMAPFILEHEADER) + 
				sizeof(BITMAPINFOHEADER) );
	}

	// 실제 비트정보 (레스터, Raster) 시작지점.
	if(ppRaster)
	{
		(*ppRaster) = 
			(BYTE *)(*ppFileHeader) + 
			(*ppFileHeader)->bfOffBits;
	}

	return true;
}

// DIB로 부터 DDB를 만들어 낸다.
bool MyMakeDDB(HDC hdc, TCHAR *pszDIBPath, HBITMAP *pOut)
{
	BITMAPFILEHEADER *pFileHdr;
	BITMAPINFOHEADER *pInfoHdr;
	void *pRaster;

	if(!MyLoadDIB(pszDIBPath, &pFileHdr, &pInfoHdr, NULL, &pRaster))
		return false;

	// DIB로 부터 DDB를 만들어 낸다.
	*pOut = CreateDIBitmap(
		hdc, pInfoHdr, CBM_INIT, pRaster,
		(BITMAPINFO *)pInfoHdr, DIB_RGB_COLORS);
	
	free(pFileHdr);
	return true;
}

// DDB를 dc로 그린다.
void MyDrawDDB(HDC hdc, HBITMAP hBitmap, int x, int y)
{
	HDC hdcMem;
	BITMAP bit;
	HBITMAP hbitOld;
	int cx, cy;

	hdcMem = CreateCompatibleDC(hdc);
	hbitOld = (HBITMAP)SelectObject(hdcMem, hBitmap);

	GetObject(hBitmap, sizeof(bit), &bit);
	cx = bit.bmWidth;
	cy = bit.bmHeight;

	BitBlt(
		hdc, x, y, cx, cy,
		hdcMem, 0, 0, SRCCOPY);

	SelectObject(hdcMem, hbitOld);
	DeleteDC(hdcMem);
}

bool ConvertToDIB(
		HBITMAP hDDB,
		BITMAPFILEHEADER **ppFileHeader)
{
	BITMAP bm;
	BITMAPFILEHEADER	fh;
	BITMAPINFOHEADER	ih;

	int paletteSize;

	if(ppFileHeader == NULL)
		return false;

	// InfoHeader를 만든다.
	GetObject(hDDB, sizeof(bm), &bm);
	ih.biSize			= sizeof(ih);
	ih.biWidth			= bm.bmWidth;
	ih.biHeight			= bm.bmHeight;
	ih.biPlanes			= 1;
	ih.biBitCount		= bm.bmPlanes * bm.bmBitsPixel;
	ih.biCompression	= BI_RGB;
	ih.biSizeImage		= 0;
	ih.biXPelsPerMeter	= 0;
	ih.biYPelsPerMeter	= 0;
	ih.biClrUsed		= 0;
	ih.biClrImportant	= 0;
	
	// RGBQuad(팔레트) 크기 구하기. 256색 이상이면 팔레트는 사용되지 않는다.
	paletteSize = (ih.biBitCount > 8 ? 0 : 1 << ih.biBitCount) * sizeof(RGBQUAD);

	// 비트맵의 크기 구하기. Raster 데이터는 DWORD단위로 정렬된다.
	ih.biSizeImage = myBitToByte(bm.bmWidth * bm.bmHeight * ih.biBitCount, 4);

	// FileHeader를 만든다.
	fh.bfType		= 0x4D42;
	fh.bfSize		= sizeof(fh) + sizeof(ih) + paletteSize + ih.biSizeImage;
	fh.bfReserved1	= 0;
	fh.bfReserved2	= 0;
	fh.bfOffBits	= sizeof(fh) + sizeof(ih) + paletteSize;

	// 메모리를 할당한다.
	(*ppFileHeader) = (BITMAPFILEHEADER *)malloc(
		sizeof(fh) + sizeof(ih) + paletteSize + ih.biSizeImage);

	if(*ppFileHeader == NULL)
		return false;

	// FileHeader 를 출력.
	memcpy((*ppFileHeader), &fh, sizeof(fh));

	// InfoHeader 를 출력.
	memcpy((char *)(*ppFileHeader) + sizeof(fh), &ih, sizeof(ih));
	
	HDC hdc;
	hdc = GetDC(NULL);

	// Raster 데이터를 출력.
	GetDIBits(
		hdc, hDDB, 0, bm.bmHeight,
		(char *)(*ppFileHeader) + sizeof(fh) + sizeof(ih) + paletteSize,
		(BITMAPINFO *)((char *)(*ppFileHeader) + sizeof(fh)),
		DIB_RGB_COLORS);

	ReleaseDC(NULL, hdc);

	return true;
}

// Output창으로 메모리 내용을 16진수로 덤프.
void MyMemView(void *pAddr, int cbSize, int byteGroupSize/*=0*/)
{
	BYTE *p = (BYTE *)pAddr;
	TCHAR szHex[4];

	for(int i=0; i<cbSize; ++i)
	{
		wsprintf(szHex, TEXT("%02X "), *(p+i));
		OutputDebugString(szHex);

		if(byteGroupSize && (i+1) % byteGroupSize == 0)
			OutputDebugString(TEXT("\n"));
	}
	OutputDebugString(TEXT("\n"));
}

// Output 창으로 메시지 출력.
void MyTrace(const TCHAR *pszFormat, ...)
{
	TCHAR szBuf[256];
	va_list ap;

	va_start(ap, pszFormat);
	//wvsprintf(szBuf, pszFormat, ap);
	_vstprintf(szBuf, pszFormat, ap);
	OutputDebugString(szBuf);
}


// float 형을 2진수 형태로 Output창으로 보여준다.
void FloatView(float f)
{
	unsigned t;
	TCHAR bin[35], temp[35], str[256];

	// 비트를 다루기 쉽도록 정수형 변수에 대입.
	t = *(unsigned *)&f;
	_itot(t, bin, 2);

	// 비트들 사이에 공백을 주기위해 temp에 bin를 잠시 저장.
	for(int i=0; i<35; ++i)
		temp[i] = '0';
	lstrcpy(temp + 32 - lstrlen(bin), bin);

	// 공백문자를 삽입.
	bin[0] = temp[0];
	bin[1] = ' ';
	lstrcpyn(bin+2, temp+1, 9);
	bin[10] = ' ';
	lstrcpy(bin+11, temp+9);
	
	int b;
	double mantissa;

	// 가수부 계산하기.
	b = t & 0x007FFFFF;
	mantissa = 0.0;
	for(int i=0; i<23; ++i)
	{
		if((b >> (22-i) & 0x01) == 1)
			mantissa += pow(2.0,-(i+1));
	}
	// 2의 0승은 항상 생략되므로 더해준다.
	mantissa += 1.0;

	// 지수부 계산하기.
	b = t & 0x7F800000;
	b >>= 23;
	b -= 127;

	_stprintf(str, TEXT("%f [%s] %f * 2^%d\n"),	f, bin, mantissa, b);
	OutputDebugString(str);
}