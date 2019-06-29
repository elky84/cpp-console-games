#if !defined(AFX_NEWGAMEDLG_H__F9B4693F_6E45_49A0_981B_CF06AC448216__INCLUDED_)
#define AFX_NEWGAMEDLG_H__F9B4693F_6E45_49A0_981B_CF06AC448216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewGameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNewGameDlg dialog

class CNewGameDlg : public CDialog
{
// Construction
public:
	int sel_menu;
	CNewGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CNewGameDlg)
	enum { IDD = IDD_DIALOG_NEWGAME };
	int		m_diff;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CNewGameDlg)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWGAMEDLG_H__F9B4693F_6E45_49A0_981B_CF06AC448216__INCLUDED_)
