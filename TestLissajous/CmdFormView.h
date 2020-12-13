#if !defined(AFX_CMDFORMVIEW_H__6FC95772_CF45_468E_AEBA_CA43D836E359__INCLUDED_)
#define AFX_CMDFORMVIEW_H__6FC95772_CF45_468E_AEBA_CA43D836E359__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CmdFormView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCmdFormView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include <vector>
using namespace std;

#include "Label.h"

class CTestLissajousDoc;

class CCmdFormView : public CFormView
{
protected:
	CCmdFormView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCmdFormView)

// Form Data
public:
	//{{AFX_DATA(CCmdFormView)
	enum { IDD = IDD_CMDFORM };
	CLabel	m_ctrlVisit;
	CLabel	m_ctrlCChart;
	CComboBox	m_ctrlComboLinestyle;
	double	m_fA;
	double	m_fB;
	double	m_fP;
	double	m_fQ;
	double	m_fPhi;
	int		m_nWidth;
	int		m_nNum;
	int		m_nInterval;
	//}}AFX_DATA

// Attributes
public:
	CTestLissajousDoc* GetDocument();

// Operations
public:
	bool	PutParams();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmdFormView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCmdFormView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CCmdFormView)
	afx_msg void OnButtonDraw();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonCurvecolor();
	afx_msg void OnButtonAnimate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BetatronView.cpp
inline CTestLissajousDoc* CCmdFormView::GetDocument()
{ return (CTestLissajousDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMDFORMVIEW_H__6FC95772_CF45_468E_AEBA_CA43D836E359__INCLUDED_)
