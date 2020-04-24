// Menu.h : main header file for the MENU application
//

#if !defined(AFX_MENU_H__4521A8B5_F642_44BF_885A_06FF07BCB7E1__INCLUDED_)
#define AFX_MENU_H__4521A8B5_F642_44BF_885A_06FF07BCB7E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMenuApp:
// See Menu.cpp for the implementation of this class
//

class CMenuApp : public CWinApp
{
public:
	CMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMenuApp)
	afx_msg void OnAppAbout();
	afx_msg void OnTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MENU_H__4521A8B5_F642_44BF_885A_06FF07BCB7E1__INCLUDED_)
