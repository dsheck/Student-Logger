// Student LoggerDlg.h : header file
//

#if !defined(AFX_STUDENTLOGGERDLG_H__89EDD093_917A_4042_A10B_45A289D06F97__INCLUDED_)
#define AFX_STUDENTLOGGERDLG_H__89EDD093_917A_4042_A10B_45A289D06F97__INCLUDED_

#include "Student.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CStudentLoggerDlg dialog

class CStudentLoggerDlg : public CDialog
{
// Construction
public:
	CStudentLoggerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CStudentLoggerDlg)
	enum { IDD = IDD_STUDENTLOGGER_DIALOG };
	CButton	m_btnLogin;
	CString	m_szPassword;
	CString	m_szUsername;
	CString	m_LoginTime;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentLoggerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CStudentLoggerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLogin();
	afx_msg void OnFileExit();
	afx_msg void OnEditViewelapsedtime();
	afx_msg void OnEditViewsummaryreport();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void loadData();
	void endSessionLog();
	int m_nUserLogged;
	bool m_bLogged;
	int m_nNumUsers;
	CStudent *m_arUsers;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTLOGGERDLG_H__89EDD093_917A_4042_A10B_45A289D06F97__INCLUDED_)
