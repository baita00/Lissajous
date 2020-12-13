// TestLissajousDoc.cpp : implementation of the CTestLissajousDoc class
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
// CTestLissajousDoc

IMPLEMENT_DYNCREATE(CTestLissajousDoc, CDocument)

BEGIN_MESSAGE_MAP(CTestLissajousDoc, CDocument)
	//{{AFX_MSG_MAP(CTestLissajousDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousDoc construction/destruction

CTestLissajousDoc::CTestLissajousDoc()
{
	// TODO: add one-time construction code here

}

CTestLissajousDoc::~CTestLissajousDoc()
{
}

BOOL CTestLissajousDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestLissajousDoc serialization

void CTestLissajousDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousDoc diagnostics

#ifdef _DEBUG
void CTestLissajousDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestLissajousDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestLissajousDoc commands

CTestLissajousView	*CTestLissajousDoc::GetTestLissajousView()
{
	POSITION pos = GetFirstViewPosition();
	CView* pView;
	while(pos != NULL)
	{
		pView = GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CTestLissajousView)))
		{
			return (CTestLissajousView*)pView;
		}
	}
	return NULL;
}

CCmdFormView	*CTestLissajousDoc::GetCmdFormView()
{
	POSITION pos = GetFirstViewPosition();
	CView* pView;
	while(pos != NULL)
	{
		pView = GetNextView(pos);
		if(pView->IsKindOf(RUNTIME_CLASS(CCmdFormView)))
		{
			return (CCmdFormView*)pView;
		}
	}
	return NULL;
}
