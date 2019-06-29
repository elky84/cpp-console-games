// Created date:	2012-04-10
// made by:			L.G.H

#pragma once
#include <windows.h>

#define MY_PI				3.1415926
#define MY_TWOPI			6.2831852
#define MY_EPSILON			0.0001

#define MY_RGB_RED			RGB(255,0,0)
#define MY_RGB_GREEN		RGB(0,255,0)
#define MY_RGB_BLUE			RGB(0,0,255)
#define MY_RGB_WHITE		RGB(255,255,255)
#define MY_RGB_YELLOW		RGB(255,255,0)
#define MY_RGB_CYAN			RGB(0,255,255)
#define MY_RGB_MAGENTA		RGB(255,0,255)
#define MY_RGB_BLACK		RGB(0,0,0)

// MyLengthUnit
enum MYLENGTHUNIT
{
	MY_LENGTH_MM		= 0,	// Milimeter
	MY_LENGTH_CM		= 1,	// Centimeter
	MY_LENGTH_M			= 2,	// Meter
	MY_LENGTH_KM		= 3,	// Kilometer
	MY_LENGTH_IN		= 4,	// Inch
	MY_LENGTH_FT		= 5,	// Feet
	MY_LENGTH_YD		= 6,	// Yard
	MY_LENGTH_MILE		= 7,	// Mile
};

// MyAngleUnit
enum MYANGLEUNIT
{
	MY_ANGLE_D		= 0,	// Degree
	MY_ANGLE_R		= 1,	// Radian
};

// MyCoordSys
enum MYCOORDSYS
{
	MY_COORD_DESCARTES			= 1,
	MY_COORD_QUADRANT_1			= 2,
	MY_COORD_QUADRANT_2			= 3,
	MY_COORD_QUADRANT_3			= 4,
	MY_COORD_QUADRANT_4			= 5,
	MY_COORD_TEXT				= 6			
};

// MyDefList
struct MYDEFLIST
{
	DWORD id;
	TCHAR *pszText;
};

// MyDefDesc
struct MYDEFDESC
{
	DWORD id;
	TCHAR *pszCap;
	TCHAR *pszDesc;
};

// MyPoint
template <typename TYPE = int>
struct MYPOINT
{
	TYPE x, y;
};

typedef BOOL (*MYFINDFILEPROC)(TCHAR *pFilePath);

//------------------------------------------------------------------------------
// Macro Functions
//------------------------------------------------------------------------------

#ifdef _DEBUG
#define myBreakPoint()		__asm { int 3 }
#else
#define myBreakPoint()
#endif

#define myAbs(a)			((a)>0 ? (a) : -(a))
#define myMax(a,b)			((a)>(b) ? (a) : (b))
#define myMin(a,b)			((a)<(b) ? (a) : (b))

#define myRand(f,n)			((f) % (n))
#define myRand2(f,a,b)		((f) % ((b)-(a)+1) + (a))

#define myBitStat(n,b)		(((n) & (b)) != 0)
#define myBitOn(n,b)		((n) |= (b))
#define myBitOff(n,b)		((n) &= ~(b))
#define myBitTog(n,b)		((n) ^= (b))

#define myBitToByte(b,u)	((((b)+((u)<<3)-1) & ~(((u)<<3)-1)) >> 3)

#define myArryCnt(n)		(sizeof(n)/sizeof(n[0]))
#define mySwap(T,a,b)		{ T t=a; a=b; b=t; }
//#define mySwap(a,b)		{ a ^= b ^= a ^= b; }

//------------------------------------------------------------------------------
// MyArray2D
//------------------------------------------------------------------------------



//------------------------------------------------------------------------------
// MyBaseMap
//------------------------------------------------------------------------------

class MYBASEMAP
{
	HDC		hdc;
	int		mapMode;
	POINT	winOrg, viewOrg;
	SIZE	winExt, viewExt;

public:
	MYBASEMAP(HDC hdc);
	void baseMode();
	void resumeMode();
};

//------------------------------------------------------------------------------
// MyXForm
//------------------------------------------------------------------------------

struct MYXFORM : public XFORM
{
public:
	MYXFORM();
	MYXFORM(float e11, float e12, float e21, float e22, float dx, float dy);

	MYXFORM setForm(float e11, float e12, float e21, float e22, float dx, float dy);
	MYXFORM setBase();
	MYXFORM setMove(float x, float y);
	MYXFORM	setScale(float x, float y);
	MYXFORM setRot(float angle);

	MYXFORM operator *(const MYXFORM &other) const;
};

//------------------------------------------------------------------------------
// MyBmp
//------------------------------------------------------------------------------

class MYBMP
{
protected:
	HBITMAP		hBmp;
	COLORREF	crKey;
	int			cxBmp, cyBmp;

	DWORD		nxSprites, nySprites;
	DWORD		cxSprites, cySprites;

public:
	MYBMP();
	~MYBMP();
	void cleanup();
	void loadBmp(HINSTANCE hInst, DWORD idBmp);
	void loadBmp(HINSTANCE hInst, DWORD idBmp, DWORD nxSprite, DWORD nySprite, COLORREF colorKey);
	void drawBmp(HDC hdc, int x, int y) const;
	void drawBmp(HDC hdc, const MYXFORM *pXForm, DWORD xIdx, DWORD yIdx, bool bUseColorKey=true) const;
};

//------------------------------------------------------------------------------
// MyRect
//------------------------------------------------------------------------------

class MYRECT : public RECT
{
public:
	void	setRect(LONG left, LONG top, LONG right, LONG bottom);
	void	setSize(LONG x, LONG y, LONG width, LONG height);

	LONG	width(bool bAbs=false) const;
	LONG	height(bool bAbs=false) const;
	POINT	center(LONG *px=NULL, LONG *py=NULL) const;
};

//------------------------------------------------------------------------------
// MyTimer
//------------------------------------------------------------------------------

class MYTIMER
{
public:
	double base;
	double elapse;

public:
	bool isIn();
	bool isOut();
	void operator +=(double tmDelta);
};

//------------------------------------------------------------------------------
// MyTimeLap
//------------------------------------------------------------------------------

class MYTIMELAP
{
protected:
	bool	bStart;
	bool	bPause;
	INT64	tmTotalPaused;
	INT64	tmPaused;
	INT64	tmLatest;
	INT64	freq;

public:
	MYTIMELAP();

	void	start();
	void	pause();
	double	lap();
};

//------------------------------------------------------------------------------
// MyBackBuf
//------------------------------------------------------------------------------

class MYBACKBUF
{
protected:
	HBITMAP		hBmp;
	HDC			hMemDC;
	MYRECT		rect;

private:
	void cleanup();

public:
	MYBACKBUF();
	~MYBACKBUF();

	void setBuf(HDC hdc, LONG width, LONG height);
	void setBuf(HWND hwnd, LONG width, LONG height);
	void setBuf(HWND hwnd);
	void initChk() const;

	void setCoordSys(MYCOORDSYS coordSys);
	void clear(DWORD color);
	void pasteTo(HDC hdc, LONG xClient=0, LONG yClient=0);

	// reading methode
	HDC		getDC() const;
	MYRECT	getRect() const;
};

//------------------------------------------------------------------------------
// MyVector
//------------------------------------------------------------------------------

// template <typename TYPE>
// class MyVector : public tagPoint<TYPE>

class MYVECTOR
{
public:
	double x, y, z;

public:
	explicit MYVECTOR(double x=0, double y=0, double z=0);
	MYVECTOR(const MYVECTOR &other);

	/* 일반적으로 자기값을 변경시키는 연산자는 레퍼런스를 리턴하고 
	 * 그렇지 않은 것은 값을 복사하여 넘겨준다 */

	// Unary
	MYVECTOR &	setCoord(double x=0, double y=0, double z=0);
	double		getNorm() const;
	MYVECTOR &	setNorm(double scalar);
	MYVECTOR	getUnit() const;
	MYVECTOR &	setUnit();
	MYVECTOR	operator -();

	MYVECTOR &	rotX(double radian);
	MYVECTOR &	rotY(double radian);
	MYVECTOR &	rotZ(double radian);

	// Binary
	bool			operator ==(const MYVECTOR &other) const;
	MYVECTOR &		operator =(const MYVECTOR &other);
	MYVECTOR		operator +(const MYVECTOR &other) const;
	MYVECTOR &		operator +=(const MYVECTOR &other);
	MYVECTOR		operator -(const MYVECTOR &other) const;
	MYVECTOR &		operator -=(const MYVECTOR &other);
	MYVECTOR		operator *(double scalar) const;
	friend MYVECTOR operator *(double scalar, const MYVECTOR &other);
	MYVECTOR &		operator *=(double scalar);
	MYVECTOR		operator /(double scalar) const;
	MYVECTOR &		operator /=(double scalar);

	static double	angleLow(const MYVECTOR *pa, const MYVECTOR *pb);
	static double	angleCCW(const MYVECTOR *pa, const MYVECTOR *pb);
	static double	dot(const MYVECTOR *pa, const MYVECTOR *pb);
	static MYVECTOR cross(const MYVECTOR *pa, const MYVECTOR *pb);
};

//------------------------------------------------------------------------------
// MyGeometry
//------------------------------------------------------------------------------

class MYGEOMETRY
{
protected:
	MYVECTOR	*pVerts;
	UINT		num;
	
public:
	MYGEOMETRY();
	MYGEOMETRY(int num);
	~MYGEOMETRY();

	void init(UINT num);
	void cleanup();

	UINT		getNum() const;
	MYVECTOR	getCenter() const;

	MYVECTOR &			operator [](UINT index);
	const MYVECTOR &	operator [](UINT index) const;
};

//------------------------------------------------------------------------------
// Global Functions
//------------------------------------------------------------------------------

bool MySwap(void *pa, void *pb, int cbSize);
BOOL MyWildcard(const TCHAR *pWildcard, const TCHAR *pText);
double MyLengthConvert(double value, MYLENGTHUNIT from, MYLENGTHUNIT to);
double MyAngleConvert(double value, MYANGLEUNIT from, MYANGLEUNIT to);

// window
BOOL MySetClientRect(HWND hWnd, int cxClient, int cyClient);
POINT MyGetRectCenter(RECT &rect, int *px=NULL, int *py=NULL);
POINT MyGetClientCenter(HWND hWnd, int *px=NULL, int *py=NULL);

// File
//unsigned long myBitToByte(unsigned long bit, unsigned long cbUnit);
int MyFindFile(const TCHAR *pPath, BOOL bSubDir, MYFINDFILEPROC pFindFileProc);
int MyFindFile(const TCHAR *pFolder, const TCHAR *const *pFiles, BOOL bSubDir, MYFINDFILEPROC pFindFileProc);
bool MySaveData(void *pData, DWORD cbSize, const TCHAR *pszPath);

// Time
DWORD MyGetAbsDay(SYSTEMTIME st);
DWORD MyGetAbsSec(SYSTEMTIME st);
void MyAbsDayToSysTime(DWORD dwAbsDay, SYSTEMTIME *pSysTime);
void MyAbsSecToSysTime(DWORD dwAbsSec, SYSTEMTIME *pSysTime);
int MyGetDayOfWeek(int year, int month, int day);
int MyGetMonthEnd(int year, int month);
void MyGetBootTime(SYSTEMTIME *pBootTime);

// Bitmap
void MyTransparentBlt(HDC hdc, int x, int y, HBITMAP hBitmap, COLORREF colorKey);
bool MyLoadDIB(TCHAR *pszPath, BITMAPFILEHEADER **ppFileHeader, BITMAPINFOHEADER **ppInfoHeader, RGBQUAD **ppRgbQuad, void **ppRaster);
bool MyMakeDDB(HDC hdc, TCHAR *pszDIBPath, HBITMAP *pOut);
void MyDrawDDB(HDC hdc, HBITMAP hBitmap, int x, int y);
bool MyConvertToDIB(HBITMAP hDDB, BITMAPFILEHEADER **ppFileHeader);

// Output
void MyMemView(void *pAddr, int cbSize, int byteGroupSize=0);
void MyTrace(const TCHAR *pszFormat, ...);
void MyFloatView(float f);

//------------------------------------------------------------------------------
// Template Functions body
//------------------------------------------------------------------------------
namespace my
{
// start namespace my

template <typename TYPE>
MYPOINT<TYPE> GetPtCenter(
		const MYPOINT<TYPE> *pPointList,
		UINT count)
{
	UINT			i;
	TYPE			xAccum, yAccum;
	MYPOINT<TYPE>	center;

	xAccum = yAccum = 0;
	for(i=0; i<count; ++i)
	{
		xAccum += pPointList[i].x;
		yAccum += pPointList[i].y;
	}

	center.x = xAccum / count;
	center.y = yAccum / count;

	return center;
}

// end namespace my
}