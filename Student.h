/****************************************************
 *					CStudent Header					*
 *					by: Don Sheck					*
 *													*
 *	Contains class definitions for the CStudent		*
 *	class.											*
 ****************************************************/

#if !defined(AFX_STUDENT_H__E3DC5E6D_F95B_48D0_9FB8_3EA7485F4A5D__INCLUDED_)
#define AFX_STUDENT_H__E3DC5E6D_F95B_48D0_9FB8_3EA7485F4A5D__INCLUDED_

#include "TotalTime.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <string>
#include <iostream>

using namespace std;

class CStudent  
{
public:
	CString getTotalTime();
	bool setTotalTime(int,int,int);
	bool setAccess(int);
	CString getPassword() const;
	CString getUsername() const;
	int getAccess() const;
	bool setPassword(CString);
	bool setUsername(CString);
	CTimeSpan getSessionTime();
	bool logout();
	void login();
	CStudent();
	virtual ~CStudent();

private:
	CTotalTime m_TotalTime;
	CTime m_CStartTime;
	int m_nAccess;
	CString m_Password;
	CString m_Username;

friend ostream& operator<<(ostream&,CStudent&);
};

#endif // !defined(AFX_STUDENT_H__E3DC5E6D_F95B_48D0_9FB8_3EA7485F4A5D__INCLUDED_)
