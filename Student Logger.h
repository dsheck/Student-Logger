// Student Logger.h : main header file for the STUDENT LOGGER application
//

#if !defined(AFX_STUDENTLOGGER_H__50C867EE_4B92_49A3_8E3A_4D82DB7134E2__INCLUDED_)
#define AFX_STUDENTLOGGER_H__50C867EE_4B92_49A3_8E3A_4D82DB7134E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStudentLoggerApp:
// See Student Logger.cpp for the implementation of this class
//

class CStudentLoggerApp : public CWinApp
{
public:
	CStudentLoggerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStudentLoggerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStudentLoggerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STUDENTLOGGER_H__50C867EE_4B92_49A3_8E3A_4D82DB7134E2__INCLUDED_)
