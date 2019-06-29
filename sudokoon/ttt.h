// ttt.h : main header file for the TTT application
//

#if !defined(AFX_TTT_H__6B7E7BC9_EA84_44D2_BD24_D050553B53F4__INCLUDED_)
#define AFX_TTT_H__6B7E7BC9_EA84_44D2_BD24_D050553B53F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols


/////////////////////////////////////////////////////////////////////////////
// CTttApp:
// See ttt.cpp for the implementation of this class
//

class CTttApp : public CWinApp
{
public:
	CTttApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTttApp)
	public:
	
	
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTttApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTT_H__6B7E7BC9_EA84_44D2_BD24_D050553B53F4__INCLUDED_)
