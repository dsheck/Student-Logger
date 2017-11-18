// TotalTime.cpp: implementation of the CTotalTime class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Student Logger.h"
#include "TotalTime.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTotalTime::CTotalTime()
{

}

CTotalTime::~CTotalTime()
{

}

/*
 *	setTime:
 *		IN: hour, min, sec is the time we are setting this object to
 *		OUT: returns true if the time variables are valid
 */
bool CTotalTime::setTime(int hour, int min, int sec)
{
	if(min < 60 && sec < 60)
	{
		m_nHour = hour;
		m_nMin = min;
		m_nSec = sec;
		return true;
	}
	else
		return false;
}

/*
 *	addTime:
 *		IN: hour, min and sec is the time components we are adding to this CTotalTime object
 *		OUT: Returns the username of this account
 */
bool CTotalTime::addTime(int hour, int min, int sec)
{
	if( (m_nSec + sec) >= 60 )
	{
		m_nSec = (m_nSec + sec) % 60;
		min++;
	}
	else
		m_nSec += sec;

	if( (m_nMin + min) >= 60 )
	{
		m_nMin = (m_nMin + min) % 60;
		hour++;
	}
	else
		m_nMin += min;

	m_nHour += hour;

	return true;
}

/*
 *	getTime:
 *		IN: 
 *		OUT: return the time as a single integer
 */
int CTotalTime::getTime()
{
	return ( (m_nHour * 10000) + (m_nMin * 100) + m_nSec);
}
