/****************************************************
 *					CTotalTime Header				*
 *					by: Don Sheck					*
 *													*
 *	Contains class definitions for the CTotalTime	*
 *	class.											*
 ****************************************************/

#if !defined(AFX_TOTALTIME_H__42A4CE8D_4D86_4D6C_907A_9FFEFF823468__INCLUDED_)
#define AFX_TOTALTIME_H__42A4CE8D_4D86_4D6C_907A_9FFEFF823468__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTotalTime  
{
public:
	int getTime();
	bool addTime(int,int,int);
	CTotalTime();
	virtual ~CTotalTime();
	bool setTime(int,int,int);
private:
	int m_nSec;
	int m_nMin;
	int m_nHour;
};

#endif // !defined(AFX_TOTALTIME_H__42A4CE8D_4D86_4D6C_907A_9FFEFF823468__INCLUDED_)
