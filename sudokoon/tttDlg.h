// tttDlg.h : header file
//

#if !defined(AFX_TTTDLG_H__C1B461B1_7803_4581_8B17_8C5FDDFF2C97__INCLUDED_)
#define AFX_TTTDLG_H__C1B461B1_7803_4581_8B17_8C5FDDFF2C97__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define BOARD_SIZE 9

/////////////////////////////////////////////////////////////////////////////
// CTttDlg dialog

class CTttDlg : public CDialog
{
// Construction
public:
	int MakeCountRandom(int not_num);
	int RandomCheck(char count[],int random_num);
	int MakeNewGame(int diff);
	int InitNewGame();
	int IdxToMat(int index);
	int MatToIdx(int index);
	int CheckOutNum(int y,int x,int num);
	int ExpertSolve(int index);
	int MatToTmp(int y, int x);	//인자값은 어느위치부터 그 뒤를 복사할건지 설정
	int TmpToMat(int y, int x);	//인자값은 어느위치부터 그 뒤를 복사할건지 설정
	int CheckSolution();
	int Dis_EditBox();
	int Trans_EditBox();
	int fill_blank();	//-1반환시 게임이 성립되지 않는 에러 0은 정상
	int empty_count();
	int expect_count(char *count,int* solve);
	void CountRenNum();
	int i,j,k,l,m,n,o;	//임시변수들
	int solve;
	int mode; //0=아무것도아님 1=게임중 2=편집중 3=게임끝
	char count[10];

	//mat[가로][세로][임의의 수 대입을위한배열]
	char mat[BOARD_SIZE+1][BOARD_SIZE+1][BOARD_SIZE+1];
	char mat_idx[99][BOARD_SIZE+1][BOARD_SIZE+1][BOARD_SIZE+1];

	//새게임을 만들때 사용하는 배열
	char mat_new[3][5][10][10];	//[게임난이도 0~2][빈칸의랜덤모양 0~4][y좌표][x좌표]
	int mat_size;
	
	//빈칸에 숫자 입력시 임시적으로 저장하는 변수
	char mat_tmp[BOARD_SIZE+1][BOARD_SIZE+1][BOARD_SIZE+1];
	char rem_num[BOARD_SIZE+1];	//각 숫자마다 사용할수 있는 횟수를 저장
	char rem_num_tmp[BOARD_SIZE+1];
	CEdit *cur_ed;
	CEdit *mat_ed[BOARD_SIZE+1][BOARD_SIZE+1];

	//에디트 박스가 read-only 상태인지를 저장하는 배열
	//문제의 수정을 방지하기위함.
	char mat_readonly[10][10];
	CTttDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTttDlg)
	enum { IDD = IDD_TTT_DIALOG };
	CStatic	m_title3;
	CStatic	m_title2;
	CStatic	m_title1;
	CButton	m_bn_new;
	CButton	m_bn_start;
	CButton	m_bn_solve;
	CButton	m_bn_check;
	CButton	m_hidden;
	CEdit	m_99;
	CEdit	m_98;
	CEdit	m_97;
	CEdit	m_96;
	CEdit	m_95;
	CEdit	m_94;
	CEdit	m_93;
	CEdit	m_92;
	CEdit	m_91;
	CEdit	m_89;
	CEdit	m_88;
	CEdit	m_87;
	CEdit	m_86;
	CEdit	m_85;
	CEdit	m_84;
	CEdit	m_83;
	CEdit	m_82;
	CEdit	m_81;
	CEdit	m_79;
	CEdit	m_78;
	CEdit	m_77;
	CEdit	m_76;
	CEdit	m_75;
	CEdit	m_74;
	CEdit	m_73;
	CEdit	m_71;
	CEdit	m_72;
	CEdit	m_69;
	CEdit	m_68;
	CEdit	m_67;
	CEdit	m_66;
	CEdit	m_65;
	CEdit	m_64;
	CEdit	m_63;
	CEdit	m_62;
	CEdit	m_61;
	CEdit	m_59;
	CEdit	m_58;
	CEdit	m_57;
	CEdit	m_56;
	CEdit	m_55;
	CEdit	m_54;
	CEdit	m_53;
	CEdit	m_52;
	CEdit	m_51;
	CEdit	m_49;
	CEdit	m_48;
	CEdit	m_47;
	CEdit	m_46;
	CEdit	m_45;
	CEdit	m_44;
	CEdit	m_43;
	CEdit	m_42;
	CEdit	m_41;
	CEdit	m_39;
	CEdit	m_38;
	CEdit	m_37;
	CEdit	m_36;
	CEdit	m_35;
	CEdit	m_34;
	CEdit	m_33;
	CEdit	m_32;
	CEdit	m_31;
	CEdit	m_29;
	CEdit	m_25;
	CEdit	m_28;
	CEdit	m_27;
	CEdit	m_26;
	CEdit	m_24;
	CEdit	m_23;
	CEdit	m_22;
	CEdit	m_21;
	CEdit	m_19;
	CEdit	m_18;
	CEdit	m_17;
	CEdit	m_16;
	CEdit	m_15;
	CEdit	m_14;
	CEdit	m_13;
	CEdit	m_12;
	CEdit	m_11;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTttDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTttDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSetfocusEdit11();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillfocusEdit11();
	afx_msg void OnKillfocusEdit12();
	afx_msg void OnSetfocusEdit12();
	afx_msg void OnButtonHidden();
	afx_msg void OnSetfocusEdit13();
	afx_msg void OnSetfocusEdit14();
	afx_msg void OnSetfocusEdit15();
	afx_msg void OnSetfocusEdit16();
	afx_msg void OnSetfocusEdit17();
	afx_msg void OnSetfocusEdit18();
	afx_msg void OnSetfocusEdit19();
	afx_msg void OnSetfocusEdit21();
	afx_msg void OnSetfocusEdit22();
	afx_msg void OnSetfocusEdit23();
	afx_msg void OnSetfocusEdit24();
	afx_msg void OnSetfocusEdit25();
	afx_msg void OnSetfocusEdit26();
	afx_msg void OnSetfocusEdit27();
	afx_msg void OnSetfocusEdit28();
	afx_msg void OnSetfocusEdit29();
	afx_msg void OnSetfocusEdit31();
	afx_msg void OnSetfocusEdit32();
	afx_msg void OnSetfocusEdit33();
	afx_msg void OnSetfocusEdit34();
	afx_msg void OnSetfocusEdit35();
	afx_msg void OnSetfocusEdit36();
	afx_msg void OnSetfocusEdit37();
	afx_msg void OnSetfocusEdit38();
	afx_msg void OnSetfocusEdit39();
	afx_msg void OnSetfocusEdit41();
	afx_msg void OnSetfocusEdit42();
	afx_msg void OnSetfocusEdit43();
	afx_msg void OnSetfocusEdit44();
	afx_msg void OnSetfocusEdit45();
	afx_msg void OnSetfocusEdit46();
	afx_msg void OnSetfocusEdit47();
	afx_msg void OnSetfocusEdit48();
	afx_msg void OnSetfocusEdit49();
	afx_msg void OnSetfocusEdit51();
	afx_msg void OnSetfocusEdit52();
	afx_msg void OnSetfocusEdit53();
	afx_msg void OnSetfocusEdit54();
	afx_msg void OnSetfocusEdit55();
	afx_msg void OnSetfocusEdit56();
	afx_msg void OnSetfocusEdit57();
	afx_msg void OnSetfocusEdit58();
	afx_msg void OnSetfocusEdit59();
	afx_msg void OnSetfocusEdit61();
	afx_msg void OnSetfocusEdit62();
	afx_msg void OnSetfocusEdit63();
	afx_msg void OnSetfocusEdit64();
	afx_msg void OnSetfocusEdit65();
	afx_msg void OnSetfocusEdit66();
	afx_msg void OnSetfocusEdit67();
	afx_msg void OnSetfocusEdit68();
	afx_msg void OnSetfocusEdit69();
	afx_msg void OnSetfocusEdit71();
	afx_msg void OnSetfocusEdit72();
	afx_msg void OnSetfocusEdit73();
	afx_msg void OnSetfocusEdit74();
	afx_msg void OnSetfocusEdit75();
	afx_msg void OnSetfocusEdit76();
	afx_msg void OnSetfocusEdit77();
	afx_msg void OnSetfocusEdit78();
	afx_msg void OnSetfocusEdit79();
	afx_msg void OnSetfocusEdit81();
	afx_msg void OnSetfocusEdit82();
	afx_msg void OnSetfocusEdit83();
	afx_msg void OnSetfocusEdit84();
	afx_msg void OnSetfocusEdit85();
	afx_msg void OnSetfocusEdit86();
	afx_msg void OnSetfocusEdit87();
	afx_msg void OnSetfocusEdit88();
	afx_msg void OnSetfocusEdit89();
	afx_msg void OnSetfocusEdit91();
	afx_msg void OnSetfocusEdit92();
	afx_msg void OnSetfocusEdit93();
	afx_msg void OnSetfocusEdit94();
	afx_msg void OnSetfocusEdit95();
	afx_msg void OnSetfocusEdit96();
	afx_msg void OnSetfocusEdit97();
	afx_msg void OnSetfocusEdit98();
	afx_msg void OnSetfocusEdit99();
	afx_msg void OnKillfocusEdit13();
	afx_msg void OnKillfocusEdit14();
	afx_msg void OnKillfocusEdit15();
	afx_msg void OnKillfocusEdit16();
	afx_msg void OnKillfocusEdit17();
	afx_msg void OnKillfocusEdit18();
	afx_msg void OnKillfocusEdit19();
	afx_msg void OnKillfocusEdit21();
	afx_msg void OnKillfocusEdit22();
	afx_msg void OnKillfocusEdit23();
	afx_msg void OnKillfocusEdit24();
	afx_msg void OnKillfocusEdit25();
	afx_msg void OnKillfocusEdit26();
	afx_msg void OnKillfocusEdit27();
	afx_msg void OnKillfocusEdit28();
	afx_msg void OnKillfocusEdit29();
	afx_msg void OnKillfocusEdit31();
	afx_msg void OnKillfocusEdit32();
	afx_msg void OnKillfocusEdit33();
	afx_msg void OnKillfocusEdit34();
	afx_msg void OnKillfocusEdit35();
	afx_msg void OnKillfocusEdit36();
	afx_msg void OnKillfocusEdit37();
	afx_msg void OnKillfocusEdit38();
	afx_msg void OnKillfocusEdit39();
	afx_msg void OnKillfocusEdit41();
	afx_msg void OnKillfocusEdit42();
	afx_msg void OnKillfocusEdit43();
	afx_msg void OnKillfocusEdit44();
	afx_msg void OnKillfocusEdit45();
	afx_msg void OnKillfocusEdit46();
	afx_msg void OnKillfocusEdit47();
	afx_msg void OnKillfocusEdit48();
	afx_msg void OnKillfocusEdit49();
	afx_msg void OnKillfocusEdit51();
	afx_msg void OnKillfocusEdit52();
	afx_msg void OnKillfocusEdit53();
	afx_msg void OnKillfocusEdit54();
	afx_msg void OnKillfocusEdit55();
	afx_msg void OnKillfocusEdit56();
	afx_msg void OnKillfocusEdit57();
	afx_msg void OnKillfocusEdit58();
	afx_msg void OnKillfocusEdit59();
	afx_msg void OnKillfocusEdit61();
	afx_msg void OnKillfocusEdit62();
	afx_msg void OnKillfocusEdit63();
	afx_msg void OnKillfocusEdit64();
	afx_msg void OnKillfocusEdit65();
	afx_msg void OnKillfocusEdit66();
	afx_msg void OnKillfocusEdit67();
	afx_msg void OnKillfocusEdit68();
	afx_msg void OnKillfocusEdit69();
	afx_msg void OnKillfocusEdit71();
	afx_msg void OnKillfocusEdit72();
	afx_msg void OnKillfocusEdit73();
	afx_msg void OnKillfocusEdit74();
	afx_msg void OnKillfocusEdit75();
	afx_msg void OnKillfocusEdit76();
	afx_msg void OnKillfocusEdit77();
	afx_msg void OnKillfocusEdit78();
	afx_msg void OnKillfocusEdit79();
	afx_msg void OnKillfocusEdit81();
	afx_msg void OnKillfocusEdit82();
	afx_msg void OnKillfocusEdit83();
	afx_msg void OnKillfocusEdit84();
	afx_msg void OnKillfocusEdit85();
	afx_msg void OnKillfocusEdit86();
	afx_msg void OnKillfocusEdit87();
	afx_msg void OnKillfocusEdit88();
	afx_msg void OnKillfocusEdit89();
	afx_msg void OnKillfocusEdit91();
	afx_msg void OnKillfocusEdit92();
	afx_msg void OnKillfocusEdit93();
	afx_msg void OnKillfocusEdit94();
	afx_msg void OnKillfocusEdit95();
	afx_msg void OnKillfocusEdit96();
	afx_msg void OnKillfocusEdit97();
	afx_msg void OnKillfocusEdit98();
	afx_msg void OnKillfocusEdit99();
	afx_msg void OnButtonSolve();
	afx_msg void OnButtonNew();
	afx_msg void OnButtonEdit();
	afx_msg void OnButtonStart();
	afx_msg void OnButtonCheck();
	afx_msg void OnButtonOnline();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TTTDLG_H__C1B461B1_7803_4581_8B17_8C5FDDFF2C97__INCLUDED_)
