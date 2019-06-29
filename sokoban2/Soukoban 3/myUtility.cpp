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
	// ���θ�带 ��� �»������ �����Ѵ�.
	SetWindowOrgEx(hdc, 0, 0, &winOrg);
	SetViewportOrgEx(hdc, 0, 0, &viewOrg);
	SetWindowExtEx(hdc, 1, 1, &winExt);
	SetViewportExtEx(hdc, 1, 1, &viewExt);
	mapMode = SetMapMode(hdc, MM_TEXT);
}

void MYBASEMAP::resumeMode()
{
	// ���θ�带 ������� ���� ���´�.
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

	// �׸��� �� ��������Ʈ ������ ũ�� ���ϱ�.
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

// ���� �ð����� �ֽ��� �ð������� ������ �ʴ����� ����
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

	// �ý��� �ð��� ������ �귯���� ������
	// �츮�� ���ϴ� ���� �ð���, ���� �ð���ŭ �����Ѵ�.
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

	// 3���� ���������� �ŷ��� �� �ִ� ���� �����°�?

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

	// *�� ������ ������ ���� ���ڿ����� ����
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

		// ���� ����
		else if(*pWildcard == *pText || *pWildcard == '?')
		{
			// ���ڿ��� ���� �ƴҰ�� ������Ŵ
			// text: ""
			// wild: "?"
			if(*pText)
			{
				++pWildcard;		
				++pText;
			}
		}

		// �ٸ� ����
		else if(*pText)
		{
			// ���ڿ��� ���� �ƴҰ�� ������Ŵ
			// text: ""
			// wild: "A"
			pWildcard = wp;
			pText = tp++;
		}
	} while(*pText);
	// pText[0] == NULL �̶� pWildcard�� *��� ã�� ������
	// �����ϱ� ���� while���� ���ʿ� ��.

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
	// �и����� ������ ����
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
	// 180�� ������ ����.
	const static double unit[] =
	{
		180,				// Degree
		3.14159265358979,	// Radian
	};

	return value * unit[to] / unit[from];
}

// Ŭ���̾�Ʈ ������ �˸¿� ������ ũ�⸦ �����Ѵ�.
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

	// ��� ���� �˻�
	while(bResult)
	{
		// ������ ���
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

		// ������ ���
		else
		{	
			TCHAR file[_MAX_FNAME];
			TCHAR ext[_MAX_EXT];
			TCHAR *pWC = NULL;

			_tsplitpath(wfd.cFileName, NULL, NULL, file, ext);

			// Ȯ������ .�� ����
			pWC = szExt + (szExt[0] == 0 ? 0 : 1);

			// ���� �̸��� ���� ���
			// ext[0]==0?(ext):(ext+1) -> Ȯ������ .�� ����
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

// pFiles ���� ���� ��Ÿ���� NULL�� �־��ش�.
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

	// ���� ��� ����
	lstrcpy(szDir, pFolder);

	// ������ ���� \�� �پ����� ������ �ٿ���
	if( szDir[ lstrlen(szDir)-1 ] != '\\' )
		lstrcat(szDir, TEXT("\\"));

	// ��� ������ ������ �˻��ϱ�
	wsprintf(szPath, TEXT("%s%s"), szDir, TEXT("*.*"));

	hSearch = FindFirstFile(szPath, &wfd);
	if(hSearch == INVALID_HANDLE_VALUE)
		return cFile;

	// ��� ���� �˻�
	while(bResult)
	{
		// ������ ���.
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

		// ������ ���
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

			// Ȯ������ .�� ����
			pExt = szScanExt + (szScanExt[0] == 0 ? 0 : 1);

			// ��ϵ� ���ϸ� �� ��ġ�Ǵ� ���� �ִ��� �˻�
			for(i=0; pFiles[i]; ++i)
			{
				_tsplitpath(pFiles[i], NULL, NULL, szSrchFile, szSrchExt);
				
				// Ȯ������ .�� ����
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

// 1601�� 1�� 1�� ���� ������ ���� ����
DWORD MyGetAbsDay(SYSTEMTIME st)
{
	FILETIME	fileTime;
	INT64		absTime;

	// ���� ���ڷ� �ٲٱ� ���� ���� �Ʒ� �������� ������
	st.wDayOfWeek		= 0;
	st.wHour			= 0;
	st.wMinute			= 0;
	st.wSecond			= 0;
	st.wMilliseconds	= 0;

	SystemTimeToFileTime(&st, &fileTime);

	// ���� �ð����� �ٲٱ�
	absTime = ((INT64)fileTime.dwHighDateTime << 32) + fileTime.dwLowDateTime;

	// FILETIME �� ������ 1 / 10,000,000 ���̴�.
	// �׷��� �Ϸ� ������ �ٲٷ��� 864,000,000,000 �� ������.
	absTime /= 860000000000;

	return (DWORD)absTime;
}

// 1970�� 1�� 1�� 1�ʺ��� ������ �ʸ� ����
// 1970�� ~ 2106�� ���� ����
DWORD MyGetAbsSec(SYSTEMTIME st)
{
	FILETIME	ft;
	INT64		absSec;

	SystemTimeToFileTime(&st, &ft);
	absSec = ((INT64)ft.dwHighDateTime << 32) + ft.dwLowDateTime;

	// 1970�� - 1601�� = 11,636,784,000��
	// FILETIME�� ���� = 1 / 10,000,000 ��
	absSec = absSec / 10000000 - 11636784000;

	return (DWORD)absSec;
}

// ���� ���� �ý��� Ÿ�� Ÿ������ �ٲٱ�
void MyAbsDayToSysTime(DWORD dwAbsDay, SYSTEMTIME *pSysTime)
{
	INT64			absTime;
	FILETIME		fileTime;

	absTime = (INT64)dwAbsDay * 864000000000;
	fileTime.dwHighDateTime	= (DWORD)(absTime >> 32);
	fileTime.dwLowDateTime	= (DWORD)(absTime & 0xFFFFFFFF);
	FileTimeToSystemTime(&fileTime, pSysTime);
}

// ���� �ʸ� �ý��� Ÿ�� Ÿ������ �ٲٱ�
void MyAbsSecToSysTime(DWORD dwAbsSec, SYSTEMTIME *pSysTime)
{
	INT64		absTime;
	FILETIME	ft;

	// 1970�⿡�� �����ϴ� �ʴ�����
	// 1601�⿡�� �����ϴ� 1 / 10,000,000 �� ���� �����
	absTime = (dwAbsSec + 11636784000) * 10000000;

	ft.dwHighDateTime	= (DWORD)(absTime >> 32);
	ft.dwLowDateTime	= (DWORD)(absTime & 0xFFFFFFFF);
	FileTimeToSystemTime(&ft, pSysTime);
}

// ��¥�� �ǳ��ָ� ������ �����Ѵ�
// 0 = �Ͽ���
// 6 = �����
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

// �� �޿� ���ԵǾ� �ִ� �� ���� ���Ѵ�
int MyGetMonthEnd(int year, int month)
{
	const static int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int lastDay;

	lastDay = days[month];
	if( month==2 && (year%4==0 && year%100!=0 || year%400==0) )
		lastDay = 29;

	return lastDay;
}

// ���� �ð��� �����Ѵ�
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

// �÷�Ű�� ������ �κ��� �����ϰ� ó���Ͽ� ��������.
void MyTransparentBlt(HDC hdc, int x, int y, HBITMAP in_hBitmap, COLORREF colorKey)
{
	BITMAP bitmap;
	COLORREF color;

	HBITMAP hBitKey;	// �÷�Ű ����ũ. (�÷�Ű=0, ��ü=1)
	HBITMAP hBitObj;	// ��ü ����ũ. (�÷�Ű=1, ��ü=0)
	HBITMAP hBitWork;	// ��Ʈ ������ �۾� �ϱ����� ����.

	HBITMAP bitKeyOld;
	HBITMAP bitObjOld;
	HBITMAP bitWorkOld;
	
	HDC		hdcImg;		// �Էµ� ��Ʈ���� ���� dc.
	HDC		hdcWork;	// �̹������� �����ϱ� ���� dc.
	HDC		hdcKey;		// �÷�Ű ����ũ�� dc.
	HDC		hdcObj;		// ��ü ����ũ�� dc.

	POINT	ptSize; // �̹��� ũ��.

	hdcImg = CreateCompatibleDC(hdc);
	SelectObject(hdcImg, in_hBitmap);
	GetObject(in_hBitmap, sizeof(BITMAP), &bitmap);
	ptSize.x = bitmap.bmWidth;
	ptSize.y = bitmap.bmHeight;
	DPtoLP(hdcImg, &ptSize,1);

	hdcKey		= CreateCompatibleDC(hdc);
	hdcObj		= CreateCompatibleDC(hdc);
	hdcWork		= CreateCompatibleDC(hdc);

	// �ܻ�(���ũ��)���� ��Ʈ�� ����.
	hBitKey		= CreateBitmap(ptSize.x, ptSize.y, 1, 1, NULL);
	// �ܻ�(���ũ��)���� ��Ʈ�� ����.
	hBitObj		= CreateBitmap(ptSize.x, ptSize.y, 1, 1, NULL); 
	// ���� ��ġ�� ȣȯ�Ǵ� ��Ʈ���� ����.
	hBitWork	= CreateCompatibleBitmap(hdc, ptSize.x, ptSize.y);
	
	bitKeyOld	= (HBITMAP) SelectObject(hdcKey, hBitKey);
	bitObjOld	= (HBITMAP) SelectObject(hdcObj, hBitObj);
	bitWorkOld	= (HBITMAP) SelectObject(hdcWork, hBitWork);

	SetMapMode(hdcImg, GetMapMode(hdc));

	// ����� ���������� ���ָ� �÷�->�ܻ� ���� ��ȯ�� ��
	// �������� 1�ν�, �� ���� ���� 0���� �ν��Ͽ� �ܻ����� ��ȯ�Ѵ�.
	color = SetBkColor(hdcImg, colorKey);
	BitBlt(hdcObj, 0, 0, ptSize.x, ptSize.y, hdcImg, 0, 0, SRCCOPY); 
	SetBkColor(hdcImg, color);

	// �÷�Ű ����ũ ���.
	BitBlt(hdcKey, 0, 0, ptSize.x, ptSize.y, hdcObj, 0, 0, NOTSRCCOPY);

	// ȭ�� dc ������ �۾� dc�� �����Ѵ�.
	BitBlt(hdcWork, 0, 0, ptSize.x, ptSize.y, hdc, x, y, SRCCOPY);

	// �÷�Ű �κ��� �̹��� ���.
	BitBlt(hdcWork, 0, 0, ptSize.x, ptSize.y, hdcObj, 0, 0, SRCAND);

	// ��ü �κ��� �̹��� ���.
	BitBlt(hdcImg, 0, 0, ptSize.x, ptSize.y, hdcKey, 0, 0, SRCAND);

	// �÷�Ű �κ��� ����̹����� ��ü �̹����� ���Ѵ�.
	BitBlt(hdcWork, 0, 0, ptSize.x, ptSize.y, hdcImg, 0, 0, SRCPAINT);

	// ȭ�鿡�ٰ� ���͵� ��Ʈ���� �ѷ��ش�.
	BitBlt(hdc, x, y, ptSize.x, ptSize.y, hdcWork, 0, 0, SRCCOPY);

	DeleteObject(SelectObject(hdcKey, bitKeyOld));
	DeleteObject(SelectObject(hdcObj, bitObjOld));
	DeleteObject(SelectObject(hdcWork, bitWorkOld));
	
	DeleteDC(hdcKey);
	DeleteDC(hdcObj);
	DeleteDC(hdcWork);
	DeleteDC(hdcImg);
}

// DIB(Device Independent Bitmap) �̹��� �ҷ�����
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

	// BMP ���� �о����.
	(*ppFileHeader) = (BITMAPFILEHEADER *)malloc(cbSize);
	ReadFile(hFile, (*ppFileHeader), cbSize, &cbReaded, NULL);

	CloseHandle(hFile);

	// InfoHeader ���� ��������.
	if(ppInfoHeader)
	{
		(*ppInfoHeader) = 
			(BITMAPINFOHEADER *)
			((BYTE *)(*ppFileHeader) + sizeof(BITMAPFILEHEADER));
	}

	// RGBQuad ���� ��������.
	if(ppRgbQuad)
	{
		(*ppRgbQuad) = 
			(RGBQUAD *)
			( (BYTE *)(*ppFileHeader) + 
				sizeof(BITMAPFILEHEADER) + 
				sizeof(BITMAPINFOHEADER) );
	}

	// ���� ��Ʈ���� (������, Raster) ��������.
	if(ppRaster)
	{
		(*ppRaster) = 
			(BYTE *)(*ppFileHeader) + 
			(*ppFileHeader)->bfOffBits;
	}

	return true;
}

// DIB�� ���� DDB�� ����� ����.
bool MyMakeDDB(HDC hdc, TCHAR *pszDIBPath, HBITMAP *pOut)
{
	BITMAPFILEHEADER *pFileHdr;
	BITMAPINFOHEADER *pInfoHdr;
	void *pRaster;

	if(!MyLoadDIB(pszDIBPath, &pFileHdr, &pInfoHdr, NULL, &pRaster))
		return false;

	// DIB�� ���� DDB�� ����� ����.
	*pOut = CreateDIBitmap(
		hdc, pInfoHdr, CBM_INIT, pRaster,
		(BITMAPINFO *)pInfoHdr, DIB_RGB_COLORS);
	
	free(pFileHdr);
	return true;
}

// DDB�� dc�� �׸���.
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

	// InfoHeader�� �����.
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
	
	// RGBQuad(�ȷ�Ʈ) ũ�� ���ϱ�. 256�� �̻��̸� �ȷ�Ʈ�� ������ �ʴ´�.
	paletteSize = (ih.biBitCount > 8 ? 0 : 1 << ih.biBitCount) * sizeof(RGBQUAD);

	// ��Ʈ���� ũ�� ���ϱ�. Raster �����ʹ� DWORD������ ���ĵȴ�.
	ih.biSizeImage = myBitToByte(bm.bmWidth * bm.bmHeight * ih.biBitCount, 4);

	// FileHeader�� �����.
	fh.bfType		= 0x4D42;
	fh.bfSize		= sizeof(fh) + sizeof(ih) + paletteSize + ih.biSizeImage;
	fh.bfReserved1	= 0;
	fh.bfReserved2	= 0;
	fh.bfOffBits	= sizeof(fh) + sizeof(ih) + paletteSize;

	// �޸𸮸� �Ҵ��Ѵ�.
	(*ppFileHeader) = (BITMAPFILEHEADER *)malloc(
		sizeof(fh) + sizeof(ih) + paletteSize + ih.biSizeImage);

	if(*ppFileHeader == NULL)
		return false;

	// FileHeader �� ���.
	memcpy((*ppFileHeader), &fh, sizeof(fh));

	// InfoHeader �� ���.
	memcpy((char *)(*ppFileHeader) + sizeof(fh), &ih, sizeof(ih));
	
	HDC hdc;
	hdc = GetDC(NULL);

	// Raster �����͸� ���.
	GetDIBits(
		hdc, hDDB, 0, bm.bmHeight,
		(char *)(*ppFileHeader) + sizeof(fh) + sizeof(ih) + paletteSize,
		(BITMAPINFO *)((char *)(*ppFileHeader) + sizeof(fh)),
		DIB_RGB_COLORS);

	ReleaseDC(NULL, hdc);

	return true;
}

// Outputâ���� �޸� ������ 16������ ����.
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

// Output â���� �޽��� ���.
void MyTrace(const TCHAR *pszFormat, ...)
{
	TCHAR szBuf[256];
	va_list ap;

	va_start(ap, pszFormat);
	//wvsprintf(szBuf, pszFormat, ap);
	_vstprintf(szBuf, pszFormat, ap);
	OutputDebugString(szBuf);
}


// float ���� 2���� ���·� Outputâ���� �����ش�.
void FloatView(float f)
{
	unsigned t;
	TCHAR bin[35], temp[35], str[256];

	// ��Ʈ�� �ٷ�� ������ ������ ������ ����.
	t = *(unsigned *)&f;
	_itot(t, bin, 2);

	// ��Ʈ�� ���̿� ������ �ֱ����� temp�� bin�� ��� ����.
	for(int i=0; i<35; ++i)
		temp[i] = '0';
	lstrcpy(temp + 32 - lstrlen(bin), bin);

	// ���鹮�ڸ� ����.
	bin[0] = temp[0];
	bin[1] = ' ';
	lstrcpyn(bin+2, temp+1, 9);
	bin[10] = ' ';
	lstrcpy(bin+11, temp+9);
	
	int b;
	double mantissa;

	// ������ ����ϱ�.
	b = t & 0x007FFFFF;
	mantissa = 0.0;
	for(int i=0; i<23; ++i)
	{
		if((b >> (22-i) & 0x01) == 1)
			mantissa += pow(2.0,-(i+1));
	}
	// 2�� 0���� �׻� �����ǹǷ� �����ش�.
	mantissa += 1.0;

	// ������ ����ϱ�.
	b = t & 0x7F800000;
	b >>= 23;
	b -= 127;

	_stprintf(str, TEXT("%f [%s] %f * 2^%d\n"),	f, bin, mantissa, b);
	OutputDebugString(str);
}