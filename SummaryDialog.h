#if !defined(AFX_SUMMARYDIALOG_H__4BA9D65A_81A1_4745_A6EA_DF473D977CFF__INCLUDED_)
#define AFX_SUMMARYDIALOG_H__4BA9D65A_81A1_4745_A6EA_DF473D977CFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SummaryDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSummaryDialog dialog

class CSummaryDialog : public CDialog
{
// Construction
public:
	virtual BOOL OnInitDialog();
	CSummaryDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSummaryDialog)
	enum { IDD = IDD_SUMMARY };
	CString	m_ReportData;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSummaryDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSummaryDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUMMARYDIALOG_H__4BA9D65A_81A1_4745_A6EA_DF473D977CFF__INCLUDED_)
