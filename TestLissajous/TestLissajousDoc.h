// TestLissajousDoc.h : interface of the CTestLissajousDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTLISSAJOUSDOC_H__C6FEC400_6A47_47DF_86C7_A54861A1ED9F__INCLUDED_)
#define AFX_TESTLISSAJOUSDOC_H__C6FEC400_6A47_47DF_86C7_A54861A1ED9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTestLissajousView;
class CCmdFormView;

class CTestLissajousDoc : public CDocument
{
protected: // create from serialization only
	CTestLissajousDoc();
	DECLARE_DYNCREATE(CTestLissajousDoc)

// Attributes
public:

// Operations
public:
	CTestLissajousView	*GetTestLissajousView();
	CCmdFormView	*GetCmdFormView();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestLissajousDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestLissajousDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestLissajousDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTLISSAJOUSDOC_H__C6FEC400_6A47_47DF_86C7_A54861A1ED9F__INCLUDED_)
