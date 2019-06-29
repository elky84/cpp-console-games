// OnlineSocket.cpp : implementation file
//

#include "stdafx.h"
#include "ttt.h"
#include "OnlineSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COnlineSocket

COnlineSocket::COnlineSocket()
{
}

COnlineSocket::~COnlineSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(COnlineSocket, CSocket)
	//{{AFX_MSG_MAP(COnlineSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// COnlineSocket member functions

void COnlineSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class

	CSocket::OnReceive(nErrorCode);
}
