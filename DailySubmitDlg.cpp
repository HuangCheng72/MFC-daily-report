// DailySubmitDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DailySubmit.h"
#include "DailySubmitDlg.h"
#include "Database.h"
#include "MainDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CDatabase db;
extern CString ID;
bool show = false;
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDailySubmitDlg dialog

CDailySubmitDlg::CDailySubmitDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDailySubmitDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDailySubmitDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_Name = _T("");
	m_Pwd = _T("");
	m_TrueName = _T("");
	m_StudentID = _T("");
	m_strDSN = _T("");
	CString strDriver="MICROSOFT ACCESS DRIVER (*.mdb)";
	CString strFile="Data.mdb";
	m_strDSN="Driver={Microsoft Access Driver(*.mdb)};Dbq=Data.mdb;Uid=;Pwd=;";
	m_strDSN.Format("ODBC;DRIVER={%s};UID=;PWD=;DBQ=%s",strDriver,strFile);
	if (!db.Open(NULL,FALSE,FALSE,m_strDSN)) {
		MessageBox("数据库打开失败!","出错");
		return;
	}
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDailySubmitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_STATIC1, m_Static1);
	DDX_Control(pDX, IDC_STATIC2, m_Static2);
	DDX_Text(pDX, IDC_EDIT1, m_Name);
	DDX_Text(pDX, IDC_EDIT2, m_Pwd);
	DDX_Text(pDX, IDC_EDIT3, m_StudentID);
	DDX_Text(pDX, IDC_EDIT4, m_TrueName);
	//{{AFX_DATA_MAP(CDailySubmitDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDailySubmitDlg, CDialog)
	//{{AFX_MSG_MAP(CDailySubmitDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDailySubmitDlg message handlers

BOOL CDailySubmitDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDailySubmitDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDailySubmitDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDailySubmitDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDailySubmitDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData();
	CString strCount;
	CRecordset rs(&db);
	rs.Open(CRecordset::forwardOnly,
		"select COUNT(Name) as COUNT from Person where Name='"
		+m_Name+"' and Pwd='"
		+m_Pwd+"'");
	rs.GetFieldValue("COUNT",strCount);
	rs.Close();
	if (strCount!="1") {
		MessageBox("请确认用户名和密码是否正确,注意大小写!","登录失败");
		rs.Close();
	}
	else
	{
		rs.Open(CRecordset::forwardOnly,
		"select ID from Person where Name='"
		+m_Name+"' and Pwd='"
		+m_Pwd+"'");
		rs.GetFieldValue("ID",ID);
		rs.Close();
		EndDialog(IDOK);
	}
	//CDialog::OnOK();
}

void CDailySubmitDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if(show)
	{
		UpdateData();
		CString strCount;
		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly,
			"select COUNT(Name) as COUNT from Person where Name='"
			+m_Name+"' and Pwd='"
			+m_Pwd+"'");
		rs.GetFieldValue("COUNT",strCount);
		rs.Close();
		if (strCount!="0") 
		{
			MessageBox("该用户已存在!","注册失败");
		}
		else
		{
			rs.Open(CRecordset::forwardOnly,
			_T("select COUNT(*) as COUNT from Person"));
			rs.GetFieldValue("COUNT",strCount);
			CString strSql = _T("insert into Person(Name,Pwd,ID) values('"+m_Name+"','"+m_Pwd+"','"+strCount+"')");
			db.ExecuteSQL(strSql);
			strSql = _T("insert into BasicInformation(Name,StudentID,Cough,Campus,ID) values('"+m_TrueName+"','"+m_StudentID+"','否','九龙湖校区','"+strCount+"')");
			db.ExecuteSQL(strSql);
			rs.Close();
			MessageBox("注册成功!快去登录吧!","注册成功");
			m_Static1.ShowWindow(SW_HIDE);
			m_Static2.ShowWindow(SW_HIDE);
			m_Edit3.ShowWindow(SW_HIDE);
			m_Edit4.ShowWindow(SW_HIDE);
			show = false;
		}
		rs.Close();
	}
	else
	{
		m_Static1.ShowWindow(SW_SHOW);
		m_Static2.ShowWindow(SW_SHOW);
		m_Edit3.ShowWindow(SW_SHOW);
		m_Edit4.ShowWindow(SW_SHOW);
		show = true;
	}
}
