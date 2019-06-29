// tttDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ttt.h"
#include "tttDlg.h"
#include "Ctrl.h"
#include "newgamedlg.h"
#include "InitNewGame.h"
#include "onlinedlg.h"
#include <string.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTttDlg dialog

CTttDlg::CTttDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTttDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTttDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTttDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTttDlg)
	DDX_Control(pDX, IDC_STATIC_TITLE3, m_title3);
	DDX_Control(pDX, IDC_STATIC_TITLE2, m_title2);
	DDX_Control(pDX, IDC_STATIC_TITLE1, m_title1);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_bn_new);
	DDX_Control(pDX, IDC_BUTTON_START, m_bn_start);
	DDX_Control(pDX, IDC_BUTTON_SOLVE, m_bn_solve);
	DDX_Control(pDX, IDC_BUTTON_CHECK, m_bn_check);
	DDX_Control(pDX, IDC_BUTTON_HIDDEN, m_hidden);
	DDX_Control(pDX, IDC_EDIT9_9, m_99);
	DDX_Control(pDX, IDC_EDIT9_8, m_98);
	DDX_Control(pDX, IDC_EDIT9_7, m_97);
	DDX_Control(pDX, IDC_EDIT9_6, m_96);
	DDX_Control(pDX, IDC_EDIT9_5, m_95);
	DDX_Control(pDX, IDC_EDIT9_4, m_94);
	DDX_Control(pDX, IDC_EDIT9_3, m_93);
	DDX_Control(pDX, IDC_EDIT9_2, m_92);
	DDX_Control(pDX, IDC_EDIT9_1, m_91);
	DDX_Control(pDX, IDC_EDIT8_9, m_89);
	DDX_Control(pDX, IDC_EDIT8_8, m_88);
	DDX_Control(pDX, IDC_EDIT8_7, m_87);
	DDX_Control(pDX, IDC_EDIT8_6, m_86);
	DDX_Control(pDX, IDC_EDIT8_5, m_85);
	DDX_Control(pDX, IDC_EDIT8_4, m_84);
	DDX_Control(pDX, IDC_EDIT8_3, m_83);
	DDX_Control(pDX, IDC_EDIT8_2, m_82);
	DDX_Control(pDX, IDC_EDIT8_1, m_81);
	DDX_Control(pDX, IDC_EDIT7_9, m_79);
	DDX_Control(pDX, IDC_EDIT7_8, m_78);
	DDX_Control(pDX, IDC_EDIT7_7, m_77);
	DDX_Control(pDX, IDC_EDIT7_6, m_76);
	DDX_Control(pDX, IDC_EDIT7_5, m_75);
	DDX_Control(pDX, IDC_EDIT7_4, m_74);
	DDX_Control(pDX, IDC_EDIT7_3, m_73);
	DDX_Control(pDX, IDC_EDIT7_1, m_71);
	DDX_Control(pDX, IDC_EDIT7_2, m_72);
	DDX_Control(pDX, IDC_EDIT6_9, m_69);
	DDX_Control(pDX, IDC_EDIT6_8, m_68);
	DDX_Control(pDX, IDC_EDIT6_7, m_67);
	DDX_Control(pDX, IDC_EDIT6_6, m_66);
	DDX_Control(pDX, IDC_EDIT6_5, m_65);
	DDX_Control(pDX, IDC_EDIT6_4, m_64);
	DDX_Control(pDX, IDC_EDIT6_3, m_63);
	DDX_Control(pDX, IDC_EDIT6_2, m_62);
	DDX_Control(pDX, IDC_EDIT6_1, m_61);
	DDX_Control(pDX, IDC_EDIT5_9, m_59);
	DDX_Control(pDX, IDC_EDIT5_8, m_58);
	DDX_Control(pDX, IDC_EDIT5_7, m_57);
	DDX_Control(pDX, IDC_EDIT5_6, m_56);
	DDX_Control(pDX, IDC_EDIT5_5, m_55);
	DDX_Control(pDX, IDC_EDIT5_4, m_54);
	DDX_Control(pDX, IDC_EDIT5_3, m_53);
	DDX_Control(pDX, IDC_EDIT5_2, m_52);
	DDX_Control(pDX, IDC_EDIT5_1, m_51);
	DDX_Control(pDX, IDC_EDIT4_9, m_49);
	DDX_Control(pDX, IDC_EDIT4_8, m_48);
	DDX_Control(pDX, IDC_EDIT4_7, m_47);
	DDX_Control(pDX, IDC_EDIT4_6, m_46);
	DDX_Control(pDX, IDC_EDIT4_5, m_45);
	DDX_Control(pDX, IDC_EDIT4_4, m_44);
	DDX_Control(pDX, IDC_EDIT4_3, m_43);
	DDX_Control(pDX, IDC_EDIT4_2, m_42);
	DDX_Control(pDX, IDC_EDIT4_1, m_41);
	DDX_Control(pDX, IDC_EDIT3_9, m_39);
	DDX_Control(pDX, IDC_EDIT3_8, m_38);
	DDX_Control(pDX, IDC_EDIT3_7, m_37);
	DDX_Control(pDX, IDC_EDIT3_6, m_36);
	DDX_Control(pDX, IDC_EDIT3_5, m_35);
	DDX_Control(pDX, IDC_EDIT3_4, m_34);
	DDX_Control(pDX, IDC_EDIT3_3, m_33);
	DDX_Control(pDX, IDC_EDIT3_2, m_32);
	DDX_Control(pDX, IDC_EDIT3_1, m_31);
	DDX_Control(pDX, IDC_EDIT2_9, m_29);
	DDX_Control(pDX, IDC_EDIT2_5, m_25);
	DDX_Control(pDX, IDC_EDIT2_8, m_28);
	DDX_Control(pDX, IDC_EDIT2_7, m_27);
	DDX_Control(pDX, IDC_EDIT2_6, m_26);
	DDX_Control(pDX, IDC_EDIT2_4, m_24);
	DDX_Control(pDX, IDC_EDIT2_3, m_23);
	DDX_Control(pDX, IDC_EDIT2_2, m_22);
	DDX_Control(pDX, IDC_EDIT2_1, m_21);
	DDX_Control(pDX, IDC_EDIT1_9, m_19);
	DDX_Control(pDX, IDC_EDIT1_8, m_18);
	DDX_Control(pDX, IDC_EDIT1_7, m_17);
	DDX_Control(pDX, IDC_EDIT1_6, m_16);
	DDX_Control(pDX, IDC_EDIT1_5, m_15);
	DDX_Control(pDX, IDC_EDIT1_4, m_14);
	DDX_Control(pDX, IDC_EDIT1_3, m_13);
	DDX_Control(pDX, IDC_EDIT1_2, m_12);
	DDX_Control(pDX, IDC_EDIT1_1, m_11);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTttDlg, CDialog)
	//{{AFX_MSG_MAP(CTttDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_SETFOCUS(IDC_EDIT1_1, OnSetfocusEdit11)
	ON_WM_KEYDOWN()
	ON_EN_KILLFOCUS(IDC_EDIT1_1, OnKillfocusEdit11)
	ON_EN_KILLFOCUS(IDC_EDIT1_2, OnKillfocusEdit12)
	ON_EN_SETFOCUS(IDC_EDIT1_2, OnSetfocusEdit12)
	ON_BN_CLICKED(IDC_BUTTON_HIDDEN, OnButtonHidden)
	ON_EN_SETFOCUS(IDC_EDIT1_3, OnSetfocusEdit13)
	ON_EN_SETFOCUS(IDC_EDIT1_4, OnSetfocusEdit14)
	ON_EN_SETFOCUS(IDC_EDIT1_5, OnSetfocusEdit15)
	ON_EN_SETFOCUS(IDC_EDIT1_6, OnSetfocusEdit16)
	ON_EN_SETFOCUS(IDC_EDIT1_7, OnSetfocusEdit17)
	ON_EN_SETFOCUS(IDC_EDIT1_8, OnSetfocusEdit18)
	ON_EN_SETFOCUS(IDC_EDIT1_9, OnSetfocusEdit19)
	ON_EN_SETFOCUS(IDC_EDIT2_1, OnSetfocusEdit21)
	ON_EN_SETFOCUS(IDC_EDIT2_2, OnSetfocusEdit22)
	ON_EN_SETFOCUS(IDC_EDIT2_3, OnSetfocusEdit23)
	ON_EN_SETFOCUS(IDC_EDIT2_4, OnSetfocusEdit24)
	ON_EN_SETFOCUS(IDC_EDIT2_5, OnSetfocusEdit25)
	ON_EN_SETFOCUS(IDC_EDIT2_6, OnSetfocusEdit26)
	ON_EN_SETFOCUS(IDC_EDIT2_7, OnSetfocusEdit27)
	ON_EN_SETFOCUS(IDC_EDIT2_8, OnSetfocusEdit28)
	ON_EN_SETFOCUS(IDC_EDIT2_9, OnSetfocusEdit29)
	ON_EN_SETFOCUS(IDC_EDIT3_1, OnSetfocusEdit31)
	ON_EN_SETFOCUS(IDC_EDIT3_2, OnSetfocusEdit32)
	ON_EN_SETFOCUS(IDC_EDIT3_3, OnSetfocusEdit33)
	ON_EN_SETFOCUS(IDC_EDIT3_4, OnSetfocusEdit34)
	ON_EN_SETFOCUS(IDC_EDIT3_5, OnSetfocusEdit35)
	ON_EN_SETFOCUS(IDC_EDIT3_6, OnSetfocusEdit36)
	ON_EN_SETFOCUS(IDC_EDIT3_7, OnSetfocusEdit37)
	ON_EN_SETFOCUS(IDC_EDIT3_8, OnSetfocusEdit38)
	ON_EN_SETFOCUS(IDC_EDIT3_9, OnSetfocusEdit39)
	ON_EN_SETFOCUS(IDC_EDIT4_1, OnSetfocusEdit41)
	ON_EN_SETFOCUS(IDC_EDIT4_2, OnSetfocusEdit42)
	ON_EN_SETFOCUS(IDC_EDIT4_3, OnSetfocusEdit43)
	ON_EN_SETFOCUS(IDC_EDIT4_4, OnSetfocusEdit44)
	ON_EN_SETFOCUS(IDC_EDIT4_5, OnSetfocusEdit45)
	ON_EN_SETFOCUS(IDC_EDIT4_6, OnSetfocusEdit46)
	ON_EN_SETFOCUS(IDC_EDIT4_7, OnSetfocusEdit47)
	ON_EN_SETFOCUS(IDC_EDIT4_8, OnSetfocusEdit48)
	ON_EN_SETFOCUS(IDC_EDIT4_9, OnSetfocusEdit49)
	ON_EN_SETFOCUS(IDC_EDIT5_1, OnSetfocusEdit51)
	ON_EN_SETFOCUS(IDC_EDIT5_2, OnSetfocusEdit52)
	ON_EN_SETFOCUS(IDC_EDIT5_3, OnSetfocusEdit53)
	ON_EN_SETFOCUS(IDC_EDIT5_4, OnSetfocusEdit54)
	ON_EN_SETFOCUS(IDC_EDIT5_5, OnSetfocusEdit55)
	ON_EN_SETFOCUS(IDC_EDIT5_6, OnSetfocusEdit56)
	ON_EN_SETFOCUS(IDC_EDIT5_7, OnSetfocusEdit57)
	ON_EN_SETFOCUS(IDC_EDIT5_8, OnSetfocusEdit58)
	ON_EN_SETFOCUS(IDC_EDIT5_9, OnSetfocusEdit59)
	ON_EN_SETFOCUS(IDC_EDIT6_1, OnSetfocusEdit61)
	ON_EN_SETFOCUS(IDC_EDIT6_2, OnSetfocusEdit62)
	ON_EN_SETFOCUS(IDC_EDIT6_3, OnSetfocusEdit63)
	ON_EN_SETFOCUS(IDC_EDIT6_4, OnSetfocusEdit64)
	ON_EN_SETFOCUS(IDC_EDIT6_5, OnSetfocusEdit65)
	ON_EN_SETFOCUS(IDC_EDIT6_6, OnSetfocusEdit66)
	ON_EN_SETFOCUS(IDC_EDIT6_7, OnSetfocusEdit67)
	ON_EN_SETFOCUS(IDC_EDIT6_8, OnSetfocusEdit68)
	ON_EN_SETFOCUS(IDC_EDIT6_9, OnSetfocusEdit69)
	ON_EN_SETFOCUS(IDC_EDIT7_1, OnSetfocusEdit71)
	ON_EN_SETFOCUS(IDC_EDIT7_2, OnSetfocusEdit72)
	ON_EN_SETFOCUS(IDC_EDIT7_3, OnSetfocusEdit73)
	ON_EN_SETFOCUS(IDC_EDIT7_4, OnSetfocusEdit74)
	ON_EN_SETFOCUS(IDC_EDIT7_5, OnSetfocusEdit75)
	ON_EN_SETFOCUS(IDC_EDIT7_6, OnSetfocusEdit76)
	ON_EN_SETFOCUS(IDC_EDIT7_7, OnSetfocusEdit77)
	ON_EN_SETFOCUS(IDC_EDIT7_8, OnSetfocusEdit78)
	ON_EN_SETFOCUS(IDC_EDIT7_9, OnSetfocusEdit79)
	ON_EN_SETFOCUS(IDC_EDIT8_1, OnSetfocusEdit81)
	ON_EN_SETFOCUS(IDC_EDIT8_2, OnSetfocusEdit82)
	ON_EN_SETFOCUS(IDC_EDIT8_3, OnSetfocusEdit83)
	ON_EN_SETFOCUS(IDC_EDIT8_4, OnSetfocusEdit84)
	ON_EN_SETFOCUS(IDC_EDIT8_5, OnSetfocusEdit85)
	ON_EN_SETFOCUS(IDC_EDIT8_6, OnSetfocusEdit86)
	ON_EN_SETFOCUS(IDC_EDIT8_7, OnSetfocusEdit87)
	ON_EN_SETFOCUS(IDC_EDIT8_8, OnSetfocusEdit88)
	ON_EN_SETFOCUS(IDC_EDIT8_9, OnSetfocusEdit89)
	ON_EN_SETFOCUS(IDC_EDIT9_1, OnSetfocusEdit91)
	ON_EN_SETFOCUS(IDC_EDIT9_2, OnSetfocusEdit92)
	ON_EN_SETFOCUS(IDC_EDIT9_3, OnSetfocusEdit93)
	ON_EN_SETFOCUS(IDC_EDIT9_4, OnSetfocusEdit94)
	ON_EN_SETFOCUS(IDC_EDIT9_5, OnSetfocusEdit95)
	ON_EN_SETFOCUS(IDC_EDIT9_6, OnSetfocusEdit96)
	ON_EN_SETFOCUS(IDC_EDIT9_7, OnSetfocusEdit97)
	ON_EN_SETFOCUS(IDC_EDIT9_8, OnSetfocusEdit98)
	ON_EN_SETFOCUS(IDC_EDIT9_9, OnSetfocusEdit99)
	ON_EN_KILLFOCUS(IDC_EDIT1_3, OnKillfocusEdit13)
	ON_EN_KILLFOCUS(IDC_EDIT1_4, OnKillfocusEdit14)
	ON_EN_KILLFOCUS(IDC_EDIT1_5, OnKillfocusEdit15)
	ON_EN_KILLFOCUS(IDC_EDIT1_6, OnKillfocusEdit16)
	ON_EN_KILLFOCUS(IDC_EDIT1_7, OnKillfocusEdit17)
	ON_EN_KILLFOCUS(IDC_EDIT1_8, OnKillfocusEdit18)
	ON_EN_KILLFOCUS(IDC_EDIT1_9, OnKillfocusEdit19)
	ON_EN_KILLFOCUS(IDC_EDIT2_1, OnKillfocusEdit21)
	ON_EN_KILLFOCUS(IDC_EDIT2_2, OnKillfocusEdit22)
	ON_EN_KILLFOCUS(IDC_EDIT2_3, OnKillfocusEdit23)
	ON_EN_KILLFOCUS(IDC_EDIT2_4, OnKillfocusEdit24)
	ON_EN_KILLFOCUS(IDC_EDIT2_5, OnKillfocusEdit25)
	ON_EN_KILLFOCUS(IDC_EDIT2_6, OnKillfocusEdit26)
	ON_EN_KILLFOCUS(IDC_EDIT2_7, OnKillfocusEdit27)
	ON_EN_KILLFOCUS(IDC_EDIT2_8, OnKillfocusEdit28)
	ON_EN_KILLFOCUS(IDC_EDIT2_9, OnKillfocusEdit29)
	ON_EN_KILLFOCUS(IDC_EDIT3_1, OnKillfocusEdit31)
	ON_EN_KILLFOCUS(IDC_EDIT3_2, OnKillfocusEdit32)
	ON_EN_KILLFOCUS(IDC_EDIT3_3, OnKillfocusEdit33)
	ON_EN_KILLFOCUS(IDC_EDIT3_4, OnKillfocusEdit34)
	ON_EN_KILLFOCUS(IDC_EDIT3_5, OnKillfocusEdit35)
	ON_EN_KILLFOCUS(IDC_EDIT3_6, OnKillfocusEdit36)
	ON_EN_KILLFOCUS(IDC_EDIT3_7, OnKillfocusEdit37)
	ON_EN_KILLFOCUS(IDC_EDIT3_8, OnKillfocusEdit38)
	ON_EN_KILLFOCUS(IDC_EDIT3_9, OnKillfocusEdit39)
	ON_EN_KILLFOCUS(IDC_EDIT4_1, OnKillfocusEdit41)
	ON_EN_KILLFOCUS(IDC_EDIT4_2, OnKillfocusEdit42)
	ON_EN_KILLFOCUS(IDC_EDIT4_3, OnKillfocusEdit43)
	ON_EN_KILLFOCUS(IDC_EDIT4_4, OnKillfocusEdit44)
	ON_EN_KILLFOCUS(IDC_EDIT4_5, OnKillfocusEdit45)
	ON_EN_KILLFOCUS(IDC_EDIT4_6, OnKillfocusEdit46)
	ON_EN_KILLFOCUS(IDC_EDIT4_7, OnKillfocusEdit47)
	ON_EN_KILLFOCUS(IDC_EDIT4_8, OnKillfocusEdit48)
	ON_EN_KILLFOCUS(IDC_EDIT4_9, OnKillfocusEdit49)
	ON_EN_KILLFOCUS(IDC_EDIT5_1, OnKillfocusEdit51)
	ON_EN_KILLFOCUS(IDC_EDIT5_2, OnKillfocusEdit52)
	ON_EN_KILLFOCUS(IDC_EDIT5_3, OnKillfocusEdit53)
	ON_EN_KILLFOCUS(IDC_EDIT5_4, OnKillfocusEdit54)
	ON_EN_KILLFOCUS(IDC_EDIT5_5, OnKillfocusEdit55)
	ON_EN_KILLFOCUS(IDC_EDIT5_6, OnKillfocusEdit56)
	ON_EN_KILLFOCUS(IDC_EDIT5_7, OnKillfocusEdit57)
	ON_EN_KILLFOCUS(IDC_EDIT5_8, OnKillfocusEdit58)
	ON_EN_KILLFOCUS(IDC_EDIT5_9, OnKillfocusEdit59)
	ON_EN_KILLFOCUS(IDC_EDIT6_1, OnKillfocusEdit61)
	ON_EN_KILLFOCUS(IDC_EDIT6_2, OnKillfocusEdit62)
	ON_EN_KILLFOCUS(IDC_EDIT6_3, OnKillfocusEdit63)
	ON_EN_KILLFOCUS(IDC_EDIT6_4, OnKillfocusEdit64)
	ON_EN_KILLFOCUS(IDC_EDIT6_5, OnKillfocusEdit65)
	ON_EN_KILLFOCUS(IDC_EDIT6_6, OnKillfocusEdit66)
	ON_EN_KILLFOCUS(IDC_EDIT6_7, OnKillfocusEdit67)
	ON_EN_KILLFOCUS(IDC_EDIT6_8, OnKillfocusEdit68)
	ON_EN_KILLFOCUS(IDC_EDIT6_9, OnKillfocusEdit69)
	ON_EN_KILLFOCUS(IDC_EDIT7_1, OnKillfocusEdit71)
	ON_EN_KILLFOCUS(IDC_EDIT7_2, OnKillfocusEdit72)
	ON_EN_KILLFOCUS(IDC_EDIT7_3, OnKillfocusEdit73)
	ON_EN_KILLFOCUS(IDC_EDIT7_4, OnKillfocusEdit74)
	ON_EN_KILLFOCUS(IDC_EDIT7_5, OnKillfocusEdit75)
	ON_EN_KILLFOCUS(IDC_EDIT7_6, OnKillfocusEdit76)
	ON_EN_KILLFOCUS(IDC_EDIT7_7, OnKillfocusEdit77)
	ON_EN_KILLFOCUS(IDC_EDIT7_8, OnKillfocusEdit78)
	ON_EN_KILLFOCUS(IDC_EDIT7_9, OnKillfocusEdit79)
	ON_EN_KILLFOCUS(IDC_EDIT8_1, OnKillfocusEdit81)
	ON_EN_KILLFOCUS(IDC_EDIT8_2, OnKillfocusEdit82)
	ON_EN_KILLFOCUS(IDC_EDIT8_3, OnKillfocusEdit83)
	ON_EN_KILLFOCUS(IDC_EDIT8_4, OnKillfocusEdit84)
	ON_EN_KILLFOCUS(IDC_EDIT8_5, OnKillfocusEdit85)
	ON_EN_KILLFOCUS(IDC_EDIT8_6, OnKillfocusEdit86)
	ON_EN_KILLFOCUS(IDC_EDIT8_7, OnKillfocusEdit87)
	ON_EN_KILLFOCUS(IDC_EDIT8_8, OnKillfocusEdit88)
	ON_EN_KILLFOCUS(IDC_EDIT8_9, OnKillfocusEdit89)
	ON_EN_KILLFOCUS(IDC_EDIT9_1, OnKillfocusEdit91)
	ON_EN_KILLFOCUS(IDC_EDIT9_2, OnKillfocusEdit92)
	ON_EN_KILLFOCUS(IDC_EDIT9_3, OnKillfocusEdit93)
	ON_EN_KILLFOCUS(IDC_EDIT9_4, OnKillfocusEdit94)
	ON_EN_KILLFOCUS(IDC_EDIT9_5, OnKillfocusEdit95)
	ON_EN_KILLFOCUS(IDC_EDIT9_6, OnKillfocusEdit96)
	ON_EN_KILLFOCUS(IDC_EDIT9_7, OnKillfocusEdit97)
	ON_EN_KILLFOCUS(IDC_EDIT9_8, OnKillfocusEdit98)
	ON_EN_KILLFOCUS(IDC_EDIT9_9, OnKillfocusEdit99)
	ON_BN_CLICKED(IDC_BUTTON_SOLVE, OnButtonSolve)
	ON_BN_CLICKED(IDC_BUTTON_NEW, OnButtonNew)
	ON_BN_CLICKED(IDC_BUTTON_EDIT, OnButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON_START, OnButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_CHECK, OnButtonCheck)
	ON_BN_CLICKED(IDC_BUTTON_ONLINE, OnButtonOnline)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTttDlg message handlers

BOOL CTttDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_bn_check.EnableWindow(FALSE);	//����üũ���� ��Ȱ��
	m_bn_solve.EnableWindow(FALSE);	//����Ǯ�̹��� ��Ȱ��
	m_bn_start.EnableWindow(FALSE);	//���۹��� ��Ȱ��

	mode = 0;	//���� ��带 �ʱ���� ����

	srand(time(NULL));	//���������������� seed�� �Է�
	
	InitNewGame();	//���������Ҷ� ���� �Լ� ��ĭ ����� ����
	
	for(i=1;i<=BOARD_SIZE;i++)
	{
		for(j=1;j<=BOARD_SIZE;j++)
		{
			for(k=0;k<=BOARD_SIZE;k++)
			{
			
				mat[i][j][k]=FALSE;
			}
		}
	}

	mat_size = (BOARD_SIZE+1)*(BOARD_SIZE+1)*(BOARD_SIZE+1);	//mat_idx�� ũ�⸦ ����

	mat_ed[1][1]=&m_11;
	mat_ed[1][2]=&m_12;
	mat_ed[1][3]=&m_13;
	mat_ed[1][4]=&m_14;
	mat_ed[1][5]=&m_15;
	mat_ed[1][6]=&m_16;
	mat_ed[1][7]=&m_17;
	mat_ed[1][8]=&m_18;
	mat_ed[1][9]=&m_19;
	mat_ed[2][1]=&m_21;
	mat_ed[2][2]=&m_22;
	mat_ed[2][3]=&m_23;
	mat_ed[2][4]=&m_24;
	mat_ed[2][5]=&m_25;
	mat_ed[2][6]=&m_26;
	mat_ed[2][7]=&m_27;
	mat_ed[2][8]=&m_28;
	mat_ed[2][9]=&m_29;
	mat_ed[3][1]=&m_31;
	mat_ed[3][2]=&m_32;
	mat_ed[3][3]=&m_33;
	mat_ed[3][4]=&m_34;
	mat_ed[3][5]=&m_35;
	mat_ed[3][6]=&m_36;
	mat_ed[3][7]=&m_37;
	mat_ed[3][8]=&m_38;
	mat_ed[3][9]=&m_39;
	mat_ed[4][1]=&m_41;
	mat_ed[4][2]=&m_42;
	mat_ed[4][3]=&m_43;
	mat_ed[4][4]=&m_44;
	mat_ed[4][5]=&m_45;
	mat_ed[4][6]=&m_46;
	mat_ed[4][7]=&m_47;
	mat_ed[4][8]=&m_48;
	mat_ed[4][9]=&m_49;
	mat_ed[5][1]=&m_51;
	mat_ed[5][2]=&m_52;
	mat_ed[5][3]=&m_53;
	mat_ed[5][4]=&m_54;
	mat_ed[5][5]=&m_55;
	mat_ed[5][6]=&m_56;
	mat_ed[5][7]=&m_57;
	mat_ed[5][8]=&m_58;
	mat_ed[5][9]=&m_59;
	mat_ed[6][1]=&m_61;
	mat_ed[6][2]=&m_62;
	mat_ed[6][3]=&m_63;
	mat_ed[6][4]=&m_64;
	mat_ed[6][5]=&m_65;
	mat_ed[6][6]=&m_66;
	mat_ed[6][7]=&m_67;
	mat_ed[6][8]=&m_68;
	mat_ed[6][9]=&m_69;
	mat_ed[7][1]=&m_71;
	mat_ed[7][2]=&m_72;
	mat_ed[7][3]=&m_73;
	mat_ed[7][4]=&m_74;
	mat_ed[7][5]=&m_75;
	mat_ed[7][6]=&m_76;
	mat_ed[7][7]=&m_77;
	mat_ed[7][8]=&m_78;
	mat_ed[7][9]=&m_79;
	mat_ed[8][1]=&m_81;
	mat_ed[8][2]=&m_82;
	mat_ed[8][3]=&m_83;
	mat_ed[8][4]=&m_84;
	mat_ed[8][5]=&m_85;
	mat_ed[8][6]=&m_86;
	mat_ed[8][7]=&m_87;
	mat_ed[8][8]=&m_88;
	mat_ed[8][9]=&m_89;
	mat_ed[9][1]=&m_91;
	mat_ed[9][2]=&m_92;
	mat_ed[9][3]=&m_93;
	mat_ed[9][4]=&m_94;
	mat_ed[9][5]=&m_95;
	mat_ed[9][6]=&m_96;
	mat_ed[9][7]=&m_97;
	mat_ed[9][8]=&m_98;
	mat_ed[9][9]=&m_99;

	Dis_EditBox();	//��ĭ�� Read-only�� ��ȯ
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTttDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTttDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}

	//mat�ȿ� ����ִ� data�� ��ĭ�� ä��� ���
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(mat[i+1][j+1][0] != 0)
			{
				SetDlgItemInt(IDC_EDIT1_1+(i*10)+j, mat[i+1][j+1][0]);
				//IDC_EDIT1_1+(i*10)+j�κ��� �̸� resource.h������ ȭ���� ĭ��
				//resource�� ����� ���� ������
			}
			else
			{
				SetDlgItemText(IDC_EDIT1_1+(i*10)+j,"");
			}
		}
	}
	
	

	
	
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTttDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTttDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}





void CTttDlg::CountRenNum()
{
	int tmp;
	//rem���� 9���ʱ�ȭ
	for(i=1;i<=9;i++)
	{
		 rem_num[i]=9;
	}

	//rem���� ���
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			tmp = mat[i][j][0];
			rem_num[tmp]--;
		}
	}
}

void CTttDlg::OnButtonHidden() 
{
	// TODO: Add your control notification handler code here

	CTttDlg::CountRenNum();
	//ȭ�鿡 ���

	for(i=0;i<9;i++)
	{
		
		SetDlgItemInt(IDC_EDIT_REM_1 + i, rem_num[i+1]  );
	}

	int out=0;	//���߷����� Ż���Ҷ� ���
	for(i=1;(i<=9)&&(out==0);i++)	//���� ��Ŀ���� ��� ��ġ���� ã��
	{
		for(j=1;(j<=9)&&(out==0);j++)
		{
			if(mat_ed[i][j] ==cur_ed)
				out= 1;
		}
	}

	if(out ==0)	//������Ŀ���� EditBox�� ������ ����
		return;
	
	if(mode ==2)		//���� ��尡 �����϶��� hidden��ư�� ������ ����ĭ���� �Ѿ
	{
		
		i--;	//�ٹٲ��� �Ǵ°��� ��������
		if(j==10)	//������ĭ�̸� �����ٷ� �Ѿ
		{
			j=1;
			i++;
		}
		if(i==10)	//���������̸� ó�� �ٷ� �Ѿ
		{
			i=1;
			m_hidden.SetFocus();	//�������� ������ ĭ�϶��� ��Ŀ���� �ٸ� ���Ͽ� ����
			Invalidate();			//ȭ��������
		}
		else{
			mat_ed[i][j]->SetFocus();
		}
	}
	
}



int CTttDlg::expect_count(char *count, int *solve)
{
	int cnt=0;	//���ڸ� ���� ����
	int i;
	for(i=1;i<=9;i++)
	{

		if( *(count+i) != TRUE)
		{
			cnt++;
			*solve = i;
		}
	}
	return cnt;

}

int CTttDlg::empty_count()		//count�迭�� ����.
{
	int i;
	for(i=0;i<=9;i++)
		count[i] = FALSE;
	return 0;
}

int CTttDlg::fill_blank()
{
	for(o=0;o<100;o++)
	{
		empty_count();
		for(l=0;l<=6;l+=3)	//���簢 ��ȩĭ( 3X3 )�� ������ ���� 3�� ����
		{
			for(m=0;m<=6;m+=3)
			{
				for(i=1;i<=3;i++)
				{
					for(j=1;j<=3;j++)
					{
						if(count[ mat[l+i][m+j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
							count[ mat[l+i][m+j][0] ] = TRUE;
						else
						{
							if( mat[l+i][m+j][0] !=0 )
							{
								
								return -1;
							}
						}
					}
					for(j=1;j<=3;j++)
					{
						if(mat[l+i][m+j][0] ==0)
							for(n=1;n<=9;n++)
								if(count[n] == TRUE)	//mat�󿡼� �ߺ����� TRUE�� �ǵ��� count
									//���� TRUE�� �����ؼ� �Է�
									mat[l+i][m+j][n] = TRUE ;
								
					}
				}
				empty_count();	//���簢�� �� �˻����� ���� �˻����� 
				//�迭�� �ʱ�ȭ
			}
		}
		//������ �˻�
		empty_count();
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				if(count[ mat[i][j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
					count[ mat[i][j][0] ] = TRUE;
				else
				{
					if( mat[i][j][0] != 0 )
					{
						
						return -1;
					}
				}
			}
			for(j=1;j<=9;j++)
			{
				if(mat[i][j][0] ==0)
					for(n=1;n<=9;n++)
						if(count[n] == TRUE)
							mat[i][j][n] = TRUE ;
						
			}
			empty_count();
		}
		
		
		//������ �˻�
		empty_count();
		for(j=1;j<=9;j++)
		{
			for(i=1;i<=9;i++)
			{
				if(count[ mat[i][j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
					count[ mat[i][j][0] ] = TRUE;
				else
				{
					if( mat[i][j][0] != 0 )
					{
						
						return -1;
					}
				}
			}
			for(i=1;i<=9;i++)
			{
				if(mat[i][j][0] ==0)
					for(n=1;n<=9;n++)
						if(count[n] == TRUE)
							mat[i][j][n] = TRUE ;
						
			}
			empty_count();
		}
		
		for(i=1;i<=BOARD_SIZE;i++)	//rem_num�迭�� �ʱ�ȭ
			rem_num_tmp[i]=rem_num[i];
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				n=expect_count(&(mat[i][j][0]),&solve);
				
				if(n==1)
				{
					mat[i][j][0] = solve;	//������ �迭�� �Է�
					CheckOutNum(i,j, solve);	//�׽�Ʈ���ڵ�*********
					
					
					rem_num_tmp[solve]--;
				}
				
				
			}
		}
		
}
return 0;
}

void CTttDlg::OnButtonSolve() 
{
	int i;
	// TODO: Add your control notification handler code here
	mode =3;	//���� ��带 ���ӳ����� ����
	int rtn_value;
	for(i=0;i<100;i++)
		rtn_value = fill_blank();

	if(rtn_value == -1)
	{
		MessageBox("�Է°��� �߸� �Ǿ����ϴ�.");
		return ;
	}
	else
	{		//����� ���������� ��������
		Invalidate();
	}

	MatToTmp(1,1);
	
	if( CheckSolution() !=0 )	//�ܼ�������� �ذ��� �ȵɰ�� ��޸��� �����
	{
		//MessageBox("��޸��� �����");
		rtn_value = ExpertSolve(0);
	}
	
	
}

void CTttDlg::OnButtonNew() 
{
	
	CNewGameDlg dlg;
	dlg.sel_menu=0;
	m_title1.ShowWindow(SW_HIDE);	//Ÿ��Ʋ ���ڸ� ����
	m_title2.ShowWindow(SW_HIDE);
	m_title3.ShowWindow(SW_HIDE);
	
	
	if(dlg.DoModal() == IDOK)
	{
		if( MakeNewGame(dlg.sel_menu) != 0)
		{
			MessageBox("�� ������ ����µ� �����߽��ϴ�.");
			return ;
		}
		
			
		switch(dlg.sel_menu) {
		case 0:
			//MessageBox("�ʱ�����������");
			break;
		case 1:
			//MessageBox("�߱�����������");
			break;
		case 2:
			//MessageBox("�������������");
			break;
		default:
			dlg.sel_menu=0;
			
		}
		if((0<=dlg.sel_menu) && (dlg.sel_menu<=2))
		{
			m_bn_check.EnableWindow(TRUE);	//����üũ���� Ȱ��
			m_bn_solve.EnableWindow(TRUE);	//����Ǯ�̹��� Ȱ��
			m_bn_start.EnableWindow(TRUE);	//���۹��� Ȱ��
		}
		Invalidate();
			
	}
		
	m_hidden.SetFocus();	//hidden��ư���� ��Ŀ���� ����
}

void CTttDlg::OnButtonEdit() 
{
	// TODO: Add your control notification handler code here
	int i,j;
	// TODO: Add your control notification handler code here
	
	CTttDlg::OnInitDialog();
	mode = 2;	//�����带 ���� ���� ����
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			mat_ed[i][j]->Clear();
			mat_ed[i][j]->SetReadOnly(FALSE);
			mat_readonly[i][j] = 0;
		}
	}
	mat_ed[1][1]->SetFocus();	//ù��°ĭ���� ��Ŀ���̴�

	m_bn_check.EnableWindow(FALSE);	//����üũ���� ��Ȱ��
	m_bn_solve.EnableWindow(FALSE);	//����Ǯ�̹��� ��Ȱ��
	m_bn_start.EnableWindow(TRUE);	//���۹��� Ȱ��
	
	
	m_title1.ShowWindow(SW_HIDE);	//Ÿ��Ʋ ���ڸ� ����
	m_title2.ShowWindow(SW_HIDE);
	m_title3.ShowWindow(SW_HIDE);
	Invalidate();
}

void CTttDlg::OnButtonStart() 
{
	
	mode = 1;	//�����带 ������ ���� ����
	// TODO: Add your control notification handler code here
	m_bn_check.EnableWindow(TRUE);
	m_bn_solve.EnableWindow(TRUE);
	Trans_EditBox();
}

int CTttDlg::Trans_EditBox()//�������� �Է��� ���� �б����� EditBox�� ��ȯ�Ͽ� �ش�.
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			if(mat[i][j][0] != 0)
			{
				mat_ed[i][j]->SetReadOnly();
				mat_readonly[i][j]=1;
			}else{
				mat_readonly[i][j]=0;
			}

			
		}
	}
	return 0;
}

int CTttDlg::Dis_EditBox()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			mat_ed[i][j]->SetReadOnly(TRUE);		
		}
	}
	return 0;

}


void CTttDlg::OnButtonCheck() 
{
	// TODO: Add your control notification handler code here

	if( CheckSolution() == 0 )	//�����϶�
		MessageBox("�����Դϴ�.");
	else		//�����϶�
		MessageBox("�����Դϴ�.");
}


int CTttDlg::CheckSolution()	//�ԷµȰ��� ���� �´��� �˻�	0�������ϸ� �°� -1�� Ʋ��
{
	int i,j,l,m;

	for(i=1;i<=9;i++)	//��ĭ( 0 ) �� �ִ��� �˻�
		for(j=1;j<=9;j++)
			if(mat[i][j][0] == 0)	//��ĭ�� ������ ������ �ƴ϶�� �Ǵ�
				return -1;
	empty_count();
	for(l=0;l<=6;l+=3)	//���簢 ��ȩĭ( 3X3 )�� ������ ���� 3�� ����
	{
		for(m=0;m<=6;m+=3)
		{
			for(i=1;i<=3;i++)
			{
				for(j=1;j<=3;j++)
				{
					if(count[ mat[l+i][m+j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
						count[ mat[l+i][m+j][0] ] = TRUE;
					else
					{
						if( mat[l+i][m+j][0] !=0 )
						{
							
							return -1;
						}
					}
				}
				
			}
			empty_count();	//���簢�� �� �˻����� ���� �˻����� 
			//�迭�� �ʱ�ȭ
		}
	}
	//������ �˻�
	empty_count();
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			if(count[ mat[i][j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
				count[ mat[i][j][0] ] = TRUE;
			else
			{
				if( mat[i][j][0] != 0 )
				{
					
					return -1;
				}
			}
		}
		
		empty_count();
	}
	
	
	//������ �˻�
	empty_count();
	for(j=1;j<=9;j++)
	{
		for(i=1;i<=9;i++)
		{
			if(count[ mat[i][j][0] ] == FALSE)	//count�迭�ȿ� �ߺ��� �ִ��� �˻�
				count[ mat[i][j][0] ] = TRUE;
			else
			{
				if( mat[i][j][0] != 0 )
				{
					
					return -1;
				}
			}
		}
		
		empty_count();
	}
	return 0;
	
}

int CTttDlg::TmpToMat(int y, int x)	//���ڰ��� �����ġ���� �� �ڸ� �����Ұ��� ����
{
	int i,j,k,seq=0;
	for(i=y;i<=9;i++)	//mat_tmp�� mat�� ����
	{
		if(seq ==0)
		{
			j=x;
			seq=1;
		}
		else
		{
			j=1;
		}
		for(j=x;j<=9;j++)
		{
			for(k=1;k<=9;k++)
			{
				mat[i][j][k] = mat_tmp[i][j][k];
			}
		}
	}
	return 0;
}

int CTttDlg::MatToTmp(int y, int x)	//���ڰ��� �����ġ���� �� �ڸ� �����Ұ��� ����
{
	int i,j,k,seq=0;
	for(i=y;i<=9;i++)	//mat_tmp�� mat�� ����
	{
		if(seq ==0)
		{
			j=x;
			seq=1;
		}
		else
		{
			j=1;
		}
		for(;j<=9;j++)
		{
			for(k=1;k<=9;k++)
			{
				mat_tmp[i][j][k] = mat[i][j][k];
			}
		}
	}
	return 0;

}

int CTttDlg::ExpertSolve(int index)
{
	int i,j,k;
	for(i=1;i<=9;i++)	
	{	
		for(j=1;j<=9;j++)
		{
			if(mat[i][j][0] != 0)	//����ĭ�� ��ĭ(0)�� �ƴϸ� �Ѿ
			{

				continue;
			}

			for(k=1;k<=9;k++)
			{
				
				if( mat[i][j][k] == FALSE)	//ĭ�� ���ڰ� �ְų� ��ĭ�� �ĺ����ڰ� ������ if�� ����
				{
					
					MatToIdx(index);	//������ ���¸� ���

					mat[i][j][0] = k; //mat�ȿ� ���� ���ڸ� �Է���
					CheckOutNum(i,j,k);
					//fill_blank();
					
							

					if( ExpertSolve(index+1) == 0)
					{
						//MessageBox("��� ��������");
						return 0;
					}
					
					mat_idx[index][i][j][k] = TRUE;	//���� �Էµ� ���ڸ� �ĺ����� ����
					IdxToMat(index);	//�Է��� �߸��Ǿ� ����Ѱ��� �ҷ���

					
					

				}
				
				
			}
			if(k==10)
			{
				mat[i][j][0]=0;

				return -1;
			}
			
		}
	}
	
	//MessageBox("��Ȯ��");
	//return 0;
	if(CheckSolution() ==0)		//���� �´��� Ȯ����
	{
		Invalidate();
		return 0;
	}
	
	

	return -1;	//���� Ʋ��

}

int CTttDlg::CheckOutNum(int y, int x, int num)
{
	int i,j,k,l;
	
	
	for(i=1;i<=9;i++)
	{
		if( i !=x )		//�ڱ��ڽ��� �������°� ����
			mat[y][i][num] = TRUE;
		if( i !=y)	//�ڱ��ڽ��� �������°� ����
			mat[i][x][num] = TRUE;
	}
	k= (y-1)%3;
	i= y-k;
	k=i+2;
	for(;i<=k;i++)
	{
		l= (x-1)%3;
		j= x-l;
		l= j+2;
		for(;j<=l;j++)
		{
			if((i!=y)&&(j!=x))
				mat[i][j][num] = TRUE;
		}
	}
	return 0;
	
}

int CTttDlg::MatToIdx(int index)
{
	memcpy(mat_idx[index],mat,mat_size);
	/*
	int i,j,k;
	for(i=1;i<=9;i++)	//mat_tmp�� mat�� ����
	{
		for(j=1;j<=9;j++)
		{
			for(k=1;k<=9;k++)
			{
				mat_idx[index][i][j][k] = mat[i][j][k];
			}
		}
	}
	*/
	return 0;
}

int CTttDlg::IdxToMat(int index)
{
	memcpy(mat,mat_idx[index],mat_size);
	/*
	int i,j,k;
	for(i=1;i<=9;i++)	//mat_tmp�� mat�� ����
	{
		
		for(j=1;j<=9;j++)
		{
			for(k=1;k<=9;k++)
			{
				mat[i][j][k] = mat_idx[index][i][j][k];
			}
		}
	}
	*/
	return 0;

}



int CTttDlg::MakeNewGame(int diff)
{
	int i,j,k;
	int random_num=0;	//�������ڸ� ����Ͽ� ���� ����
	int out=0;
	srand(time(NULL)); 
	
	random_num=0;

	//EditBox�� ������ ����� Ȱ��ȭ�Ѵ�
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			mat_ed[i][j]->Clear();
			mat_ed[i][j]->SetReadOnly(FALSE);
		}
	}

	//mat�迭�� ������ �����
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				mat[i][j][k] = 0;
			}
		}
	}

	//count�迭�� ������ �Է�
	MakeCountRandom(0);
	

	//count�� ����ִ� �������� mat�� ���ι迭�� �ִ� �۾�
	
	for(i=1;i<=9;i++)	
	{
		mat[1][i][0] = count[i];
	}

	//count�迭�� ������ �Է�
	MakeCountRandom(mat[1][1][0]);

	//count�� ����ִ� �������� mat�� ���ι迭�� �ִ� �۾�
	for(i=6;i<=9;i++)//3x3�迭���� ���ڿ� ���ι迭�� ������ �浹�������� 4�����Է�
	{
		mat[i][1][0] = count[i];
	}

	
	OnButtonSolve();	//�������� �־��� mat�迭�� ������ ĭ�� Ǯ� ä��.
	//ExpertSolve(1);
	
	//�ٸ������ ���ӿ� ��ĭ�� ����� �۾�
	random_num = rand() % 5;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			for(k=0;k<=9;k++)
			{
				if(k==0)
				{
					if(mat_new[diff][random_num][i][j] == '0')
						mat[i][j][0]=0;
				}else{
					mat[i][j][k]=0;
				}
				
			}
		}
	}

	OnButtonStart();	//start������ ���� ���ڰ� �� ĭ�� Read-Only�� ��ȯ

	return 0;

}

int CTttDlg::RandomCheck(char count[],int random_num)
{
	int i;
	for(i=1;i<=9;i++)
	{
		if(count[i]==random_num)
			return -1;	//�ߺ��� �ִ°����� ����
	}
	return 0;	//�ߺ��� ���°����� ����

}

int CTttDlg::MakeCountRandom(int not_num)
{
	int i=1,random_num;
	//count�迭�� ������ �Է�
	empty_count();
	if(not_num !=0)
	{
		i=4;
		count[1] = not_num;
	}
	while(1)
	{
		
		if(i==10)
			break;
		
		random_num = (rand() % 9) + 1;
		
		
		while(RandomCheck(count,random_num) != 0)
		{
			random_num = (rand() % 9) + 1;
		}
		
		count[i] = random_num;
		
		i++;
		
	}
	return 0;

}

void CTttDlg::OnButtonOnline() 
{
	// TODO: Add your control notification handler code here

	m_title1.ShowWindow(SW_HIDE);	//Ÿ��Ʋ ���ڸ� ����
	m_title2.ShowWindow(SW_HIDE);	//made by jaedong
	m_title3.ShowWindow(SW_HIDE);
	
	COnlineDlg on_dlg;
	
		
	if(on_dlg.DoModal() == IDOK)
	{
				
		
		
		//EditBox�� ������ ����� Ȱ��ȭ�Ѵ�
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				mat_ed[i][j]->Clear();
				mat_ed[i][j]->SetReadOnly(FALSE);
			}
		}
		
		//mat�迭�� ������ �����
		int index=0;	//�ٿ���� �������� �ε����� ����
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=9;j++)
			{
				for(k=0;k<=9;k++)
				{
					if(k==0)
					{
						mat[i][j][k] = on_dlg.totalData.GetAt(index)-0x30;
						index++;
					}else{
						mat[i][j][k] = 0;
					}
				}
			}
		}


			m_bn_check.EnableWindow(TRUE);	//����üũ���� Ȱ��
			m_bn_solve.EnableWindow(TRUE);	//����Ǯ�̹��� Ȱ��
			m_bn_start.EnableWindow(TRUE);	//���۹��� Ȱ��

		Invalidate();
		
	}
	OnButtonStart();
	m_bn_start.EnableWindow(FALSE);
	m_hidden.SetFocus();	//hidden��ư���� ��Ŀ���� ����
}

BOOL CTttDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if( pMsg->message == WM_MOUSEWHEEL )
		
    {
		
        SendMessage( pMsg->message, (WPARAM) pMsg->wParam, (LPARAM) pMsg->lParam );
		

		int out=0;	//���߷����� Ż���Ҷ� ���
		for(i=1;(i<=9)&&(out==0);i++)	//���� ��Ŀ���� ��� ��ġ���� ã��
		{
			for(j=1;(j<=9)&&(out==0);j++)
			{
				if(mat_ed[i][j] ==cur_ed)
					out= 1;
			}
		}

		if(out ==0)	//������Ŀ���� EditBox�� ������
			return CDialog::PreTranslateMessage(pMsg);
		
		if(mat_readonly[i-1][j-1]==1)	//read-onlyĭ���� ���� �Է���.
			return CDialog::PreTranslateMessage(pMsg);
		
		if( (INT)pMsg->wParam >0 ){

			//MessageBox("Wheel UP!");
			if( mat[i-1][j-1][0] == 9)
				mat[i-1][j-1][0]=0;
			else
				mat[i-1][j-1][0]++;


		}else{

			//MessageBox("Wheel Down....");
			if( mat[i-1][j-1][0] == 0)
				mat[i-1][j-1][0]=9;
			else
				mat[i-1][j-1][0]--;

		}
		
		SetDlgItemInt(mat_ed[i-1][j-1]->GetDlgCtrlID(),mat[i-1][j-1][0]);
	
		//InvalidateRect(lpRect_tmp,TRUE);
		
		
		
    }
	return CDialog::PreTranslateMessage(pMsg);
}
