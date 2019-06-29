#if !defined(AFX_ONLINEDLG_H__28FDD926_AD75_49F4_A286_2CCB2FED588B__INCLUDED_)
#define AFX_ONLINEDLG_H__28FDD926_AD75_49F4_A286_2CCB2FED588B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnlineDlg.h : header file
//
#include "onlinesocket.h"

/////////////////////////////////////////////////////////////////////////////
// COnlineDlg dialog

class COnlineDlg : public CDialog
{
// Construction
public:
	COnlineDlg(CWnd* pParent = NULL);   // standard constructor
	INT sel_diff;
	CString totalData;
	CString status_str;
// Dialog Data
	//{{AFX_DATA(COnlineDlg)
	enum { IDD = IDD_DIALOG_ONLINE };
	CButton	m_bn_download;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnlineDlg)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COnlineDlg)
	afx_msg void OnOnlineRadio1();
	afx_msg void OnOnlineRadio2();
	afx_msg void OnOnlineRadio3();
	afx_msg void OnOnlineRadio4();
	afx_msg void OnButtonOnlineDownload();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COnlineDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONLINEDLG_H__28FDD926_AD75_49F4_A286_2CCB2FED588B__INCLUDED_)
