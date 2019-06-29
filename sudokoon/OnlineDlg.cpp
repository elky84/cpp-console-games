// OnlineDlg.cpp : implementation file
//

#include "stdafx.h"
#include <afxinet.h>
#include "ttt.h"
#include "OnlineDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnlineDlg dialog


COnlineDlg::COnlineDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COnlineDlg::IDD, pParent)
{
	EnableAutomation();
	sel_diff=1;

	//{{AFX_DATA_INIT(COnlineDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void COnlineDlg::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CDialog::OnFinalRelease();
}

void COnlineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COnlineDlg)
	DDX_Control(pDX, IDC_BUTTON_ONLINE_DOWNLOAD, m_bn_download);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COnlineDlg, CDialog)
	//{{AFX_MSG_MAP(COnlineDlg)
	ON_BN_CLICKED(IDC_ONLINE_RADIO1, OnOnlineRadio1)
	ON_BN_CLICKED(IDC_ONLINE_RADIO2, OnOnlineRadio2)
	ON_BN_CLICKED(IDC_ONLINE_RADIO3, OnOnlineRadio3)
	ON_BN_CLICKED(IDC_ONLINE_RADIO4, OnOnlineRadio4)
	ON_BN_CLICKED(IDC_BUTTON_ONLINE_DOWNLOAD, OnButtonOnlineDownload)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(COnlineDlg, CDialog)
	//{{AFX_DISPATCH_MAP(COnlineDlg)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IOnlineDlg to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {3892A158-586E-405A-9C91-71F7C77580FC}
static const IID IID_IOnlineDlg =
{ 0x3892a158, 0x586e, 0x405a, { 0x9c, 0x91, 0x71, 0xf7, 0xc7, 0x75, 0x80, 0xfc } };

BEGIN_INTERFACE_MAP(COnlineDlg, CDialog)
	INTERFACE_PART(COnlineDlg, IID_IOnlineDlg, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COnlineDlg message handlers

void COnlineDlg::OnOnlineRadio1() 
{
	// TODO: Add your control notification handler code here
	sel_diff=1;
}

void COnlineDlg::OnOnlineRadio2() 
{
	// TODO: Add your control notification handler code here
	sel_diff=2;
}

void COnlineDlg::OnOnlineRadio3() 
{
	// TODO: Add your control notification handler code here
	sel_diff=3;
}

void COnlineDlg::OnOnlineRadio4() 
{
	// TODO: Add your control notification handler code here
	sel_diff=4;
}

void COnlineDlg::OnButtonOnlineDownload() 
{
	INT random_num,random_num_max;
	CHAR buf[10];
	CInternetSession session;
	CHAR str_tmp[100];
	totalData = "";

	//버턴 잠금
	m_bn_download.EnableWindow(FALSE);

	status_str="";

	CString www_addr="HTTP://brlab.mireene.com/sudokoon/id.php?diff=";
	itoa(sel_diff,buf,10);
	www_addr.Insert(46,buf);

	status_str = status_str+"접속중.." + "\r\n";
	SetDlgItemText(IDC_EDIT_ONLINE_STATUS,status_str);
	CInternetFile* pFile = (CInternetFile*)session.OpenURL(www_addr);
	if(pFile)
	{
		CString strData;

		status_str = status_str+"접속성공" + "\r\n";
		SetDlgItemText(IDC_EDIT_ONLINE_STATUS,status_str);
		pFile->SetReadBufferSize(4096);
		while(pFile->ReadString(strData))
		{
			totalData = totalData + strData + "\r\n";
		}
		//SetDlgItemText(IDC_EDIT_ONLINE_STATUS,totalData);
		pFile->Close();
	}
	
	
	
	random_num_max = atoi(totalData);
	random_num = (rand()%random_num_max);
		
	itoa(random_num+1,buf,10);

	sprintf(str_tmp,"HTTP://brlab.mireene.com/sudokoon/game.php?diff=%d&id=%d",sel_diff,random_num);
	www_addr = str_tmp;

	status_str = status_str+"게임번호 :"+ buf ;	
	
	

	switch(sel_diff) {
	case 1:
		status_str = status_str+" 난이도: 초급"+"\r\n";
		break;
	case 2:
		status_str = status_str+" 난이도: 중급"+"\r\n";
		break;
	case 3:
		status_str = status_str+" 난이도: 상급"+"\r\n";
		break;
	case 4:
		status_str = status_str+" 난이도: 극악"+"\r\n";
		break;
	}
	SetDlgItemText(IDC_EDIT_ONLINE_STATUS,status_str);
	
	

	totalData="";
	pFile = (CInternetFile*)session.OpenURL(www_addr);
	if(pFile)
	{
		CString strData;
		pFile->SetReadBufferSize(4096);
		while(pFile->ReadString(strData))
		{
			totalData = totalData + strData + "\r\n";
		}
		//SetDlgItemText(IDC_EDIT_ONLINE_STATUS,totalData);
		pFile->Close();
		status_str = status_str+"다운로드 완료" + "\r\n";
		SetDlgItemText(IDC_EDIT_ONLINE_STATUS,status_str);
	}
	session.Close();
	status_str = status_str+"접속종료" + "\r\n";
	SetDlgItemText(IDC_EDIT_ONLINE_STATUS,status_str);
	
	//버턴 잠금 해제
	m_bn_download.EnableWindow(TRUE);
	
}

void COnlineDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}
