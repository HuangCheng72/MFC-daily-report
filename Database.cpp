// Database.cpp: implementation of the Database class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DailySubmit.h"
#include "Database.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC(CPerson, CRecordset)

CPerson::CPerson(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CPerson)
	m_ID = _T("");
	m_Pwd = _T("");
	m_Name = _T("");
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CPerson::GetDefaultConnect()
{
	return _T("ODBC;DSN=Data");
}

CString CPerson::GetDefaultSQL()
{
	return _T("[Person]");
}

void CPerson::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CPerson)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[Pwd]"), m_Pwd);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	//}}AFX_FIELD_MAP
}

#ifdef _DEBUG
void CPerson::AssertValid() const
{
	CRecordset::AssertValid();
}

void CPerson::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}

#endif


IMPLEMENT_DYNAMIC(CBasicInfo, CRecordset)

CBasicInfo::CBasicInfo(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBasicInfo)
	m_Name = _T("");
	m_StudentID = _T("");
	m_Cough = _T("");
	m_Campus = _T("");
	m_ID = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}
CString CBasicInfo::GetDefaultConnect()
{
	return _T("ODBC;DSN=Data");
}

CString CBasicInfo::GetDefaultSQL()
{
	return _T("[BasicInformation]");
}

void CBasicInfo::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBasicInfo)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[StudentID]"), m_StudentID);
	RFX_Text(pFX, _T("[Cough]"), m_Cough);
	RFX_Text(pFX, _T("[Campus]"), m_Campus);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	//}}AFX_FIELD_MAP
}

#ifdef _DEBUG
void CBasicInfo::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBasicInfo::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif


IMPLEMENT_DYNAMIC(CSubmit, CRecordset)

CSubmit::CSubmit(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CSubmit)
	m_NowTime = _T("");
	m_BodyTemperature = _T("");
	m_Cough = _T("");
	m_Campus = _T("");
	m_ID = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CSubmit::GetDefaultConnect()
{
	return _T("ODBC;DSN=Data");
}

CString CSubmit::GetDefaultSQL()
{
	return _T("[Submit]");
}

void CSubmit::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CSubmit)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[NowTime]"), m_NowTime);
	RFX_Text(pFX, _T("[BodyTemperature]"), m_BodyTemperature);
	RFX_Text(pFX, _T("[Cough]"), m_Cough);
	RFX_Text(pFX, _T("[Campus]"), m_Campus);
	RFX_Text(pFX, _T("[ID]"), m_ID);
	//}}AFX_FIELD_MAP
}


#ifdef _DEBUG
void CSubmit::AssertValid() const
{
	CRecordset::AssertValid();
}

void CSubmit::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}

#endif