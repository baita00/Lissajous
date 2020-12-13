// TestLissajous.h : main header file for the TESTLISSAJOUS application
//

#if !defined(AFX_TESTLISSAJOUS_H__1E89E689_13E5_44DF_89C9_6B2885ED68D7__INCLUDED_)
#define AFX_TESTLISSAJOUS_H__1E89E689_13E5_44DF_89C9_6B2885ED68D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousApp:
// See TestLissajous.cpp for the implementation of this class
//

class CTestLissajousApp : public CWinApp
{
public:
	CTestLissajousApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLissajousApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestLissajousApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLISSAJOUS_H__1E89E689_13E5_44DF_89C9_6B2885ED68D7__INCLUDED_)
