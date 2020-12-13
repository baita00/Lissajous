// CmdFormView.cpp : implementation file
//

#include "stdafx.h"
#include "TestLissajous.h"
#include "TestLissajousDoc.h"
#include "TestLissajousView.h"
#include "CmdFormView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCmdFormView

IMPLEMENT_DYNCREATE(CCmdFormView, CFormView)

CCmdFormView::CCmdFormView()
	: CFormView(CCmdFormView::IDD)
{
	//{{AFX_DATA_INIT(CCmdFormView)
	m_fA = 2.0;
	m_fB = 2.0;
	m_fP = 3.0;
	m_fQ = 2.0;
	m_fPhi = 0.25;
	m_nWidth = 1;
	m_nNum = 0;
	m_nInterval = 0;
	//}}AFX_DATA_INIT
}

CCmdFormView::~CCmdFormView()
{
}

void CCmdFormView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCmdFormView)
	DDX_Control(pDX, IDC_VISIT, m_ctrlVisit);
	DDX_Control(pDX, IDC_CCHART, m_ctrlCChart);
	DDX_Control(pDX, IDC_COMBO_LINESTYLE, m_ctrlComboLinestyle);
	DDX_Text(pDX, IDC_EDIT_A, m_fA);
	DDX_Text(pDX, IDC_EDIT_B, m_fB);
	DDX_Text(pDX, IDC_EDIT_P, m_fP);
	DDX_Text(pDX, IDC_EDIT_Q, m_fQ);
	DDX_Text(pDX, IDC_EDIT_PHI, m_fPhi);
	DDX_Text(pDX, IDC_EDIT_LINESIZE, m_nWidth);
	DDX_Text(pDX, IDC_EDIT_NUM, m_nNum);
	DDX_Text(pDX, IDC_EDIT_TIMERINTERVAL, m_nInterval);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCmdFormView, CFormView)
	//{{AFX_MSG_MAP(CCmdFormView)
	ON_BN_CLICKED(IDC_BUTTON_DRAW, OnButtonDraw)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_CURVECOLOR, OnButtonCurvecolor)
	ON_BN_CLICKED(IDC_BUTTON_ANIMATE, OnButtonAnimate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCmdFormView diagnostics

#ifdef _DEBUG
void CCmdFormView::AssertValid() const
{
	CFormView::AssertValid();
}

void CCmdFormView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
CTestLissajousDoc* CCmdFormView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestLissajousDoc)));
	return (CTestLissajousDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCmdFormView message handlers

void CCmdFormView::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();

	m_ctrlVisit.SetTextColor(RGB(0,0,255))
		.SetBkColor(RGB(0,0,0))
		.FlashBackground(TRUE)
		.SetLinkCursor(AfxGetApp()->LoadCursor(IDC_HAND));
	m_ctrlCChart.SetLink(TRUE)
		.SetTextColor(RGB(0,0,255))
		.SetFontUnderline(TRUE)
		.SetLinkCursor(AfxGetApp()->LoadCursor(IDC_HAND));

	CTestLissajousDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CTestLissajousView *pLissajousView = pDoc->GetTestLissajousView();

	m_fA = pLissajousView->a;
	m_fB = pLissajousView->b;
	m_fP = pLissajousView->p;
	m_fQ = pLissajousView->q;
	m_fPhi = pLissajousView->phi/myPi;
	m_nWidth = pLissajousView->width;
	m_nNum = pLissajousView->num;
	m_nInterval = pLissajousView->timerInterval;
	
	// TODO: Add your specialized code here and/or call the base class
	m_ctrlComboLinestyle.InsertString(0, _T("实线 ____________"));
	m_ctrlComboLinestyle.InsertString(1, _T("虚划线 _ _ _ _ _ _"));
	m_ctrlComboLinestyle.InsertString(2, _T("虚点线 . . . . . ."));
	m_ctrlComboLinestyle.InsertString(3, _T("划点线 _ . _ . _"));
	m_ctrlComboLinestyle.InsertString(4, _T("划点点线 _ . . _ . ."));
	m_ctrlComboLinestyle.SetCurSel(pLissajousView->style);

	UpdateData(FALSE);
}

bool CCmdFormView::PutParams()
{
	UpdateData(TRUE);
	
	if(m_fA<=0.0 || m_fB<=0.0 || m_fQ<=0.0 || m_fQ<=0.0)
	{
		MessageBox(_T("输入方程参数有误!"));
		return false;
	}
	
	CTestLissajousDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CTestLissajousView *pLissajousView = pDoc->GetTestLissajousView();
	
	pLissajousView->a = m_fA;
	pLissajousView->b = m_fB;
	pLissajousView->p = m_fP;
	pLissajousView->q = m_fQ;
	pLissajousView->phi = m_fPhi*myPi;
	
	pLissajousView->width = m_nWidth;
	pLissajousView->style = m_ctrlComboLinestyle.GetCurSel();
	pLissajousView->num = m_nNum;
	
	pLissajousView->timerInterval = m_nInterval;

	return true;
}

void CCmdFormView::OnButtonDraw() 
{
	// TODO: Add your control notification handler code here
	CTestLissajousDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CTestLissajousView *pLissajousView = pDoc->GetTestLissajousView();

	if(!PutParams())return;

	if(pLissajousView->running)
	{
		pLissajousView->KillTimer(pLissajousView->timerID);
		pLissajousView->cur = 0;
		pLissajousView->running = false;
	}
	pLissajousView->timerID = 0;

	pLissajousView->CreateLissajous();

	pDoc->UpdateAllViews(NULL);
}

void CCmdFormView::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	CTestLissajousDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CTestLissajousView *pLissajousView = pDoc->GetTestLissajousView();
	pLissajousView->m_chartWnd.GetChart()->EmptySingleData(0);
	pLissajousView->m_chartWnd.ReDraw();

	if(!pLissajousView->running)pLissajousView->timerID=0;
}

void CCmdFormView::OnButtonCurvecolor() 
{
	// TODO: Add your control notification handler code here
	CTestLissajousDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	
	CTestLissajousView *pLissajousView = pDoc->GetTestLissajousView();
	COLORREF color = pLissajousView->m_chartWnd.GetChart()->GetDataColor(0);

	CColorDialog colorDlg(color); 
	
    if (IDOK == colorDlg.DoModal())
    {   
        color = colorDlg.GetColor();
		pLissajousView->cr = color;

		if(pLissajousView->m_chartWnd.GetChart()->GetPlotDataCount()>0)
		{
			pLissajousView->m_chartWnd.GetChart()->SetDataColor(color, 0);
			pLissajousView->m_chartWnd.ReDraw();
		}
	}
}

void CCmdFormView::OnButtonAnimate() 
{
	// TODO: Add your control notification handler code here
	CTestLissajousDoc *pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CTestLissajousView *pLissajousView = pDoc->GetTestLissajousView();

	if(!PutParams())return;

	pLissajousView->CreateAnimation();

	pLissajousView->timerInterval = m_nInterval;

	pLissajousView->timerID = pLissajousView->SetTimer(1, pLissajousView->timerInterval, NULL);
	pLissajousView->running = true;
}
