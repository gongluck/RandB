// ClockPpg.cpp : Implementation of the CClockPropPage property page class.

#include "stdafx.h"
#include "Clock.h"
#include "ClockPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CClockPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CClockPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CClockPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CClockPropPage, "CLOCK.ClockPropPage.1",
	0x6490f70a, 0x17d8, 0x4310, 0xae, 0x5, 0xf9, 0xbb, 0x83, 0x8c, 0x2e, 0xb)


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage::CClockPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CClockPropPage

BOOL CClockPropPage::CClockPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CLOCK_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage::CClockPropPage - Constructor

CClockPropPage::CClockPropPage() :
	COlePropertyPage(IDD, IDS_CLOCK_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CClockPropPage)
	m_updateInterval = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage::DoDataExchange - Moves data between page and properties

void CClockPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CClockPropPage)
	DDP_Text(pDX, IDC_EDIT_INTERVAL, m_updateInterval, _T("Interval") );
	DDX_Text(pDX, IDC_EDIT_INTERVAL, m_updateInterval);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CClockPropPage message handlers
