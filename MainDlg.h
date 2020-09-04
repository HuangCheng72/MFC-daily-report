#if !defined(AFX_MAINDLG_H__32C2B366_5556_4642_BA96_1A1B20048100__INCLUDED_)
#define AFX_MAINDLG_H__32C2B366_5556_4642_BA96_1A1B20048100__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MainDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// MainDlg dialog

class MainDlg : public CDialog
{
// Construction
public:
	MainDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(MainDlg)
	enum { IDD = IDD_MAINDLG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CString m_TrueName;
	CString m_StudentID;
	CString m_Cough;
	CString m_Campus;
	CString m_Temperature;
	CEdit m_Edit1;
	CEdit m_Edit2;
	CEdit m_Edit4;
	CEdit m_Edit5;
	CEdit m_Edit6;
	CListCtrl	m_List3;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(MainDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(MainDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	virtual void Updateall();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINDLG_H__32C2B366_5556_4642_BA96_1A1B20048100__INCLUDED_)
