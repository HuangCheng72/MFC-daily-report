// DailySubmitDlg.h : header file
//

#if !defined(AFX_DAILYSUBMITDLG_H__84D009F3_5F8A_484E_BE91_5756EAC638F2__INCLUDED_)
#define AFX_DAILYSUBMITDLG_H__84D009F3_5F8A_484E_BE91_5756EAC638F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDailySubmitDlg dialog

class CDailySubmitDlg : public CDialog
{
// Construction
public:
	CDailySubmitDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDailySubmitDlg)
	enum { IDD = IDD_DAILYSUBMIT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CString m_Name;
	CString m_Pwd;
	CString m_TrueName;
	CString m_StudentID;
	CString m_strDSN;
	CEdit m_Edit3;
	CEdit m_Edit4;
	CStatic m_Static1;
	CStatic m_Static2;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDailySubmitDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDailySubmitDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAILYSUBMITDLG_H__84D009F3_5F8A_484E_BE91_5756EAC638F2__INCLUDED_)
