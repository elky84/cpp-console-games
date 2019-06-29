// NewGameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttt.h"
#include "NewGameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewGameDlg dialog


CNewGameDlg::CNewGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CNewGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CNewGameDlg)
	m_diff = -1;
	//}}AFX_DATA_INIT
}


void CNewGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CNewGameDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_diff);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CNewGameDlg, CDialog)
	//{{AFX_MSG_MAP(CNewGameDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNewGameDlg message handlers

void CNewGameDlg::OnRadio1() //초급
{
	// TODO: Add your control notification handler code here
	sel_menu=0;

}

void CNewGameDlg::OnRadio2() //중급
{
	// TODO: Add your control notification handler code here
	sel_menu=1;
}

void CNewGameDlg::OnRadio3() //상급
{
	// TODO: Add your control notification handler code here
	sel_menu=2;
}

void CNewGameDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
