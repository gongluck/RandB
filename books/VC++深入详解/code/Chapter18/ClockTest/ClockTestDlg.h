// ClockTestDlg.h : header file
//

#if !defined(AFX_CLOCKTESTDLG_H__64E2A00D_8F50_455D_BA84_E25DD3A6136A__INCLUDED_)
#define AFX_CLOCKTESTDLG_H__64E2A00D_8F50_455D_BA84_E25DD3A6136A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CClockTestDlg dialog
#include "clock.h"
class CClockTestDlg : public CDialog
{
// Construction
public:
	CClockTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CClockTestDlg)
	enum { IDD = IDD_CLOCKTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CClockTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnClickClockctrl1();
	afx_msg void OnNewMinuteClockctrl1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CClock m_clock;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKTESTDLG_H__64E2A00D_8F50_455D_BA84_E25DD3A6136A__INCLUDED_)
