// TestLissajousView.cpp : implementation of the CTestLissajousView class
//

#include "stdafx.h"
#include "TestLissajous.h"

#include "TestLissajousDoc.h"
#include "TestLissajousView.h"

#include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousView

IMPLEMENT_DYNCREATE(CTestLissajousView, CView)

BEGIN_MESSAGE_MAP(CTestLissajousView, CView)
	//{{AFX_MSG_MAP(CTestLissajousView)
	ON_WM_CREATE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousView construction/destruction

CTestLissajousView::CTestLissajousView()
{
	// TODO: add construction code here
	a = 2.0;
	b = 2.0;
	p = 3.0;
	q = 2.0;
	phi = myPi/4.0;
	num = 720;

	cr = RGB(128, 192, 224);
	width = 1;
	style = PS_SOLID;

	timerID = 0;
	running = false;
	cur = 0;
	timerInterval = 50;
}	

CTestLissajousView::~CTestLissajousView()
{
}

BOOL CTestLissajousView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousView drawing

void CTestLissajousView::OnDraw(CDC* pDC)
{
	CTestLissajousDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousView printing

BOOL CTestLissajousView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTestLissajousView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTestLissajousView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousView diagnostics

#ifdef _DEBUG
void CTestLissajousView::AssertValid() const
{
	CView::AssertValid();
}

void CTestLissajousView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestLissajousDoc* CTestLissajousView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestLissajousDoc)));
	return (CTestLissajousDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousView message handlers

int CTestLissajousView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_chartWnd.Attach(m_hWnd, kTypeXY);
	m_chartWnd.GetChart()->SetOptimalXExtend(true);
	m_chartWnd.GetChart()->SetOptimalYExtend(true);
	m_chartWnd.GetChart()->SetTitle(_T("李萨如图形"));
	CreateLissajous();

	m_chartWnd.GetChart()->SetDefMainString(_T("基于CChart的李萨如图形绘制工具"));
	m_chartWnd.GetChart()->SetDefSubString(_T("CChart作者官方作品\n欢迎访问CChart小栈\nwww.cchart.net"));
	
	return 0;
}

void	CTestLissajousView::CreateLissajous()
{
	CreateEmpty();
	double tt, x, y;
	for(size_t i=0; i<=num; ++i)
	{
		tt = i*2.0*myPi/num;
		x = a*sin(p*tt);
		y = b*sin(q*tt+phi);
		m_chartWnd.GetChart()->AddPoint2D(x, y);
	}
	m_chartWnd.GetChart()->SetStaticRange(false);
	
//	m_chartWnd.ReDraw();
}

void	CTestLissajousView::CreateEmpty()
{
	m_chartWnd.GetChart()->ClrAllData();
	m_chartWnd.GetChart()->AddCurve();
	m_chartWnd.GetChart()->SetDataColor(cr, 0);
	m_chartWnd.GetChart()->SetDataLineSize(width, 0);
	m_chartWnd.GetChart()->SetDataLineStyle(style, 0);
	m_chartWnd.GetChart()->SetDataTitle(_T("李萨如曲线"), 0);
}

void	CTestLissajousView::CreateAnimation()
{
	CreateEmpty();
	m_chartWnd.GetChart()->SetMarkLastPoint(true, 0);
	m_chartWnd.GetChart()->SetMarkerFill(true, 0);
	m_chartWnd.GetChart()->SetDataMaxPoints(num+1, 0);
	
	double X, Y;
	double xe = ceil(b)==a?1.0:0.0;
	double ye = ceil(b)==b?1.0:0.0;
	X = ceil(a)+xe;
	Y = ceil(b)+ye;
	m_chartWnd.GetChart()->SetPlotRange(-X, X, -Y, Y);
	m_chartWnd.GetChart()->SetStaticRange(true);
}

void CTestLissajousView::SwitchTimer()
{
	if(timerID>0)
	{
		if(running)
		{
			KillTimer(timerID);
		}
		else
		{
			SetTimer(timerID, timerInterval, NULL);
		}
		running = !running;
	}
}

void CTestLissajousView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

	if(!running)return;

	double tt, x, y;
	tt = cur*2.0*myPi/num;
	x = a*sin(p*tt);
	y = b*sin(q*tt+phi);
	m_chartWnd.GetChart()->AddPoint2D(x, y);
	m_chartWnd.ReDraw();

	cur++;
	
	//CView::OnTimer(nIDEvent);
}

void CTestLissajousView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	SwitchTimer();
	
	CView::OnLButtonDown(nFlags, point);
}
