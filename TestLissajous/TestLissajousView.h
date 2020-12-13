// TestLissajousView.h : interface of the CTestLissajousView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTLISSAJOUSVIEW_H__9D27DFAE_F2FB_4266_83E9_AFD3E89804B1__INCLUDED_)
#define AFX_TESTLISSAJOUSVIEW_H__9D27DFAE_F2FB_4266_83E9_AFD3E89804B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CChart/Chart.h"

#	if defined(_UNICODE) || defined(UNICODE)
#		pragma comment(lib,"CChart\\CChartu.lib")
#	else
#		pragma comment(lib,"CChart\\CChart.lib")
#	endif
using namespace NsCChart;

class CTestLissajousDoc;

const double myPi = 3.14159265358979324;

class CTestLissajousView : public CView
{
protected: // create from serialization only
	CTestLissajousView();
	DECLARE_DYNCREATE(CTestLissajousView)

// Attributes
public:
	CTestLissajousDoc* GetDocument();

	double a, b, p, q, phi;
	size_t num;

	COLORREF cr;
	int width, style;

	UINT timerID;
	bool running;
	int cur;
	int timerInterval;

	CChartWnd m_chartWnd;

// Operations
public:
	void	CreateLissajous();
	void	CreateEmpty();
	void	CreateAnimation();
	void	SwitchTimer();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLissajousView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestLissajousView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestLissajousView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestLissajousView.cpp
inline CTestLissajousDoc* CTestLissajousView::GetDocument()
   { return (CTestLissajousDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLISSAJOUSVIEW_H__9D27DFAE_F2FB_4266_83E9_AFD3E89804B1__INCLUDED_)
