// SummaryDialog.cpp : implementation file
//

#include "stdafx.h"
#include "Student Logger.h"
#include "SummaryDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSummaryDialog dialog


CSummaryDialog::CSummaryDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSummaryDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSummaryDialog)
	m_ReportData = _T("");
	//}}AFX_DATA_INIT
}


void CSummaryDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSummaryDialog)
	DDX_Text(pDX, IDC_REPORT, m_ReportData);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSummaryDialog, CDialog)
	//{{AFX_MSG_MAP(CSummaryDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSummaryDialog message handlers

BOOL CSummaryDialog::OnInitDialog()
{
	ifstream report;
	report.open("logfile.txt", ios::in);

	char* line;
	int i = 0;
	
	while(!report.eof())
	{
		line = new char[128];
		report >> line;
		m_ReportData = m_ReportData  + CString(line) + CString("   ");
		delete[] line;
		i++;
		if(i == 8)
		{
			m_ReportData += CString("\t\t");
			i = 0;
		}
	}

	UpdateData(false);

	report.close();
	return TRUE;
}
