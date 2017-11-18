/***********************************************************************************************
* Name:  CStudent
* Author:  Don Sheck
* Date Created:  March 28 2003
* Description:	This class contains all variables and functions required by a login account in
*				the student logger. It keeps track of the username, password, access level and 
*				times the user has logged into the system.
*             
*Change History
*==============
*Date         Author            Description
*----------   -------------     ---------------------------
*03/28/2003   Don Sheck		    Initial Specification
*03/30/2003	  Don Sheck			Imported into WinApp and modified getTime function
*04/07/2003	  Don Sheck			Final Release and Documentation
*
************************************************************************************************/
#include "stdafx.h"
#include "Student Logger.h"
#include "Student.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CStudent::CStudent()
{
	m_Username = "";
	m_Password = "";
	m_TotalTime.setTime(0,0,0);
	m_nAccess = 0;
}

CStudent::~CStudent()
{

}

/*
 *	login:
 *		IN: 
 *		OUT:
 *	This function is called when the user logs in to the system
 */
void CStudent::login()
{
	m_CStartTime = CTime::GetCurrentTime();
}

/*
 *	logout:
 *		IN: 
 *		OUT:
 *	This function is called when the user logs out of the system. It will set the logout time.
 */
bool CStudent::logout()
{
	// Get the elapsed time and add it to the total time
	CTime now = CTime::GetCurrentTime();
	CTimeSpan tspan = now - m_CStartTime;
	m_TotalTime.addTime(tspan.GetTotalHours(), tspan.GetTotalMinutes(), tspan.GetTotalSeconds());
	return true;
}

/*
 *	getSessionTime:
 *		IN: 
 *		OUT: Session time
 *	This function calculates the current elapsed time that the user has spent on the system
 *	and returns it as a CTimeSpan Object.
 */
CTimeSpan CStudent::getSessionTime()
{
	CTime current = CTime::GetCurrentTime();
	CTimeSpan session = current - m_CStartTime;
	return session;
}

/*
 *	setUsername:
 *		IN: CString user is the username that we want to set this account to.
 *		OUT:
 *	This function will change the username of this CStudent object
 */
bool CStudent::setUsername(CString user)
{
	m_Username = user;
	return true;
}

/*
 *	setPassword:
 *		IN: CString pass is the password we want to change this account to..
 *		OUT:
 *	This function will change the password of this CStudent object
 */
bool CStudent::setPassword(CString pass)
{
	m_Password = pass;
	return true;
}

/*
 *	getUsername:
 *		IN: 
 *		OUT: Returns the username of this account
 */
CString CStudent::getUsername() const
{
	return m_Username;
}

/*
 *	getPassword:
 *		IN: 
 *		OUT: Returns the password of this account
 */
CString CStudent::getPassword() const
{
	return m_Password;
}

/*
 *	setAccess:
 *		IN: nAccess is the access level that we want to set this account to. Valid settings 
 *			are 1 or 0.
 *		OUT: Returns true if the access was set
 */
bool CStudent::setAccess(int nAccess)
{
	if(nAccess == 1 || nAccess == 0)
	{
		m_nAccess = nAccess;
		return true;
	}
	else
		return false;
}

/*
 *	getAccess:
 *		IN: 
 *		OUT: Returns the access level of this account
 */
int CStudent::getAccess() const
{
	return m_nAccess;
}

/*
 *	setTotalTime:
 *		IN: hour, min and sec composes the time that we wish to set m_TotalTime to.
 *		OUT: Returns true if the time was set
 */
bool CStudent::setTotalTime(int hour, int min, int sec)
{
	if(m_TotalTime.setTime(hour, min, sec))
		return true;
	else
		return false;
}

/*
 *	operator <<:
 *		We are overloading the ostream operator here to make it easier to write a CStudent
 *		object to file
 */
ostream& operator <<(ostream &os,CStudent &student)
{
	int i;
	CString temp;
	
	temp = student.getUsername();
	for(i = 0; i < temp.GetLength(); i++)
		os << temp[i];
	os << "\t";

	temp = student.getPassword();
	for(i = 0; i < temp.GetLength(); i++)
		os << temp[i];
	os << "\t";

	os << student.getAccess() << "\t";
	int time = student.m_TotalTime.getTime();
	int hour, min, sec;

	hour = time / 10000;
	time -= hour * 10000;
	min = time / 100;
	time -= min * 100;
	sec = time;

	CString szTime;
	szTime.Format("%d\t%d\t%d",hour, min, sec);
	for(i = 0; i < szTime.GetLength(); i++)
		os << szTime[i];
	
	os << endl;
	return os;
}

/*
 *	getTotalTime:
 *		IN: 
 *		OUT: returns to the total time as a CString
 */
CString CStudent::getTotalTime()
{
	int time = m_TotalTime.getTime(); // get our time
	int hour, min, sec;

	// split the time up into its parts
	hour = time / 10000;
	time -= hour * 10000;
	min = time / 100;
	time -= min * 100;
	sec = time;

	// create and format the timeString
	CString timeString;
	timeString.Format("%d:%d:%d",hour,min,sec);

	return timeString;
}
