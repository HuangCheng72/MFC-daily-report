// DailySubmit.h : main header file for the DAILYSUBMIT application
//

#if !defined(AFX_DAILYSUBMIT_H__D5BFBAA5_CFD9_4237_B40B_2A8360E6D1B7__INCLUDED_)
#define AFX_DAILYSUBMIT_H__D5BFBAA5_CFD9_4237_B40B_2A8360E6D1B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

extern CDatabase db;
extern CString ID;

/////////////////////////////////////////////////////////////////////////////
// CDailySubmitApp:
// See DailySubmit.cpp for the implementation of this class
//

class CDailySubmitApp : public CWinApp
{
public:
	CDailySubmitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDailySubmitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDailySubmitApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAILYSUBMIT_H__D5BFBAA5_CFD9_4237_B40B_2A8360E6D1B7__INCLUDED_)
