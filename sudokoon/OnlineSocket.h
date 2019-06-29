#if !defined(AFX_ONLINESOCKET_H__01DA2A19_0CAC_4EB2_9E80_A240A001BDEF__INCLUDED_)
#define AFX_ONLINESOCKET_H__01DA2A19_0CAC_4EB2_9E80_A240A001BDEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OnlineSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// COnlineSocket command target

class COnlineSocket : public CSocket
{
// Attributes
public:
	

// Operations
public:
	COnlineSocket();
	virtual ~COnlineSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnlineSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(COnlineSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONLINESOCKET_H__01DA2A19_0CAC_4EB2_9E80_A240A001BDEF__INCLUDED_)
