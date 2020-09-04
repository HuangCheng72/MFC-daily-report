// MainDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DailySubmit.h"
#include "MainDlg.h"
#include "Database.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// MainDlg dialog
extern CDatabase db;
extern CString ID;
CString strtime;
MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialog(MainDlg::IDD, pParent)
{
	
	//{{AFX_DATA_INIT(MainDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	CBasicInfo rsBasicInfo(&db);
	rsBasicInfo.m_strFilter="ID='"+ID+"'";
	rsBasicInfo.Open();
	m_TrueName = rsBasicInfo.m_Name;
	m_StudentID = rsBasicInfo.m_StudentID;
	m_Cough = rsBasicInfo.m_Cough;
	m_Campus = rsBasicInfo.m_Campus;
	rsBasicInfo.Close();
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	strtime.Format("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek);
}


void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Control(pDX, IDC_EDIT6, m_Edit6);
	DDX_Control(pDX, IDC_LIST3, m_List3);
	DDX_Text(pDX, IDC_EDIT1, m_StudentID);
	DDX_Text(pDX, IDC_EDIT2, m_TrueName);
	DDX_Text(pDX, IDC_EDIT3, m_Temperature);
	DDX_Text(pDX, IDC_EDIT4, m_Campus);
	DDX_Text(pDX, IDC_EDIT5, m_Cough);
	DDX_Text(pDX, IDC_EDIT6, strtime);
	//{{AFX_DATA_MAP(MainDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(MainDlg, CDialog)
	//{{AFX_MSG_MAP(MainDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// MainDlg message handlers

void MainDlg::OnOK() 
{
	UpdateData();
	if(m_Temperature.IsEmpty())
	{
		MessageBox("请填写当前体温再提交！","提示");
	}
	else
	{
		CString strSql = _T("insert into Submit(NowTime,BodyTemperature,Cough,Campus,ID) values('"+strtime+"','"+m_Temperature+"','"+m_Cough+"','"+m_Campus+"','"+ID+"')");
		db.ExecuteSQL(strSql);
		strSql = _T("update BasicInformation set Cough='"+m_Cough+"' where ID='"+ID+"'");
		db.ExecuteSQL(strSql);
		strSql = _T("update BasicInformation set Campus='"+m_Campus+"' where ID='"+ID+"'");
		db.ExecuteSQL(strSql);
		MessageBox("填报成功！","提示");
		Updateall();
	}
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

BOOL MainDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	UpdateData();
	m_List3.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	m_List3.InsertColumn(0,"序号",LVCFMT_LEFT,50);
	m_List3.InsertColumn(1,"学号",LVCFMT_LEFT,110);
	m_List3.InsertColumn(2,"姓名",LVCFMT_LEFT,110);
	m_List3.InsertColumn(3,"填报时间",LVCFMT_LEFT,110);
	m_List3.InsertColumn(4,"体温",LVCFMT_LEFT,80);
	m_List3.InsertColumn(5,"是否咳嗽",LVCFMT_LEFT,80);
	m_List3.InsertColumn(6,"所在校区",LVCFMT_LEFT,100);
	Updateall();
	
	return true;
}
void MainDlg::Updateall()
{
	CSubmit rs(&db);
	rs.m_strFilter = "ID='"+ID+"'";
	rs.Open();
	m_List3.DeleteAllItems();
	int i=0;
	while (!rs.IsEOF()) {
		CString strID;
		strID.Format("%d",i);
		m_List3.InsertItem(i,"");
		m_List3.SetItemText(i,0,strID);
		m_List3.SetItemText(i,1,m_StudentID);
		m_List3.SetItemText(i,2,m_TrueName);
		m_List3.SetItemText(i,3,rs.m_NowTime);
		m_List3.SetItemText(i,4,rs.m_BodyTemperature);
		m_List3.SetItemText(i,5,rs.m_Cough);
		m_List3.SetItemText(i,6,rs.m_Campus);
		rs.MoveNext();
		i++;
	}
	rs.Close();
	m_List3.SetBkColor(RGB(240,247,233));
	m_List3.SetTextBkColor(RGB(240,247,233));
	CBasicInfo rsBasicInfo(&db);
	rsBasicInfo.m_strFilter="ID='"+ID+"'";
	rsBasicInfo.Open();
	m_TrueName = rsBasicInfo.m_Name;
	m_StudentID = rsBasicInfo.m_StudentID;
	m_Cough = rsBasicInfo.m_Cough;
	m_Campus = rsBasicInfo.m_Campus;
	rsBasicInfo.Close();
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	strtime.Format("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d",sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek);
	UpdateData();
}

void MainDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	Updateall();
}
