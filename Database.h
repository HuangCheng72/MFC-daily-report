// Database.h: interface for the Database class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DATABASE_H__FBF0CBA0_9916_494A_B09B_89C706F84A12__INCLUDED_)
#define AFX_DATABASE_H__FBF0CBA0_9916_494A_B09B_89C706F84A12__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPerson : public CRecordset
{
public:
	CPerson(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CPerson)

// Field/Param Data
	//{{AFX_FIELD(CPerson, CRecordset)
	CString	m_ID;
	CString	m_Pwd;
	CString	m_Name;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPerson)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CBasicInfo : public CRecordset
{
public:
	CBasicInfo(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBasicInfo)

// Field/Param Data
	//{{AFX_FIELD(CBasicInfo, CRecordset)
	CString	m_Name;
	CString	m_StudentID;
	CString	m_Cough;
	CString	m_Campus;
	CString	m_ID;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasicInfo)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

class CSubmit : public CRecordset
{
public:
	CSubmit(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CSubmit)

// Field/Param Data
	//{{AFX_FIELD(CBasicInfo, CRecordset)
	CString	m_NowTime;
	CString	m_BodyTemperature;
	CString	m_Cough;
	CString	m_Campus;
	CString	m_ID;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBasicInfo)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

#endif // !defined(AFX_DATABASE_H__FBF0CBA0_9916_494A_B09B_89C706F84A12__INCLUDED_)
