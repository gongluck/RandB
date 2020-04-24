// Menu2View.h : interface of the CMenu2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MENU2VIEW_H__5A2699DB_5392_4BEA_AA9A_E384FB803B5E__INCLUDED_)
#define AFX_MENU2VIEW_H__5A2699DB_5392_4BEA_AA9A_E384FB803B5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Menu2Doc.h"

class CMenu2View : public CView
{
protected: // create from serialization only
	CMenu2View();
	DECLARE_DYNCREATE(CMenu2View)

// Attributes
public:
	CMenu2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenu2View)
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
	CStringArray m_strArray;
	virtual ~CMenu2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMenu2View)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnPhone1();
	afx_msg void OnPhone2();
	afx_msg void OnPhone3();
	afx_msg void OnPhone4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_nIndex;
	CMenu m_menu;
	CString m_strLine;
};

#ifndef _DEBUG  // debug version in Menu2View.cpp
inline CMenu2Doc* CMenu2View::GetDocument()
   { return (CMenu2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU2VIEW_H__5A2699DB_5392_4BEA_AA9A_E384FB803B5E__INCLUDED_)
