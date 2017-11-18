// Student LoggerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Student Logger.h"
#include "Student LoggerDlg.h"
#include "SummaryDialog.h"

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentLoggerDlg dialog

CStudentLoggerDlg::CStudentLoggerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CStudentLoggerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CStudentLoggerDlg)
	m_szPassword = _T("");
	m_szUsername = _T("");
	m_LoginTime = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentLoggerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStudentLoggerDlg)
	DDX_Control(pDX, IDC_LOGIN, m_btnLogin);
	DDX_Text(pDX, IDC_PASSWORD, m_szPassword);
	DDX_Text(pDX, IDC_USERNAME, m_szUsername);
	DDX_Text(pDX, IDC_LOGINTIME, m_LoginTime);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CStudentLoggerDlg, CDialog)
	//{{AFX_MSG_MAP(CStudentLoggerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	ON_COMMAND(ID_FILE_EXIT, OnFileExit)
	ON_COMMAND(ID_EDIT_VIEWELAPSEDTIME, OnEditViewelapsedtime)
	ON_COMMAND(ID_EDIT_VIEWSUMMARYREPORT, OnEditViewsummaryreport)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStudentLoggerDlg message handlers

BOOL CStudentLoggerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	loadData();
	CMenu* pMainMenu = GetMenu();
	CMenu* pEditMenu = pMainMenu->GetSubMenu(1);
	
	pEditMenu->EnableMenuItem(ID_EDIT_VIEWELAPSEDTIME, MF_DISABLED | MF_GRAYED);
	pEditMenu->EnableMenuItem(ID_EDIT_VIEWSUMMARYREPORT, MF_DISABLED | MF_GRAYED);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CStudentLoggerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CStudentLoggerDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CStudentLoggerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CStudentLoggerDlg::OnLogin() 
{
	UpdateData(true);

	bool found = false;
	int i, j;

	// open our log file
	ofstream logFile;
	logFile.open("logfile.txt", ios::app);
	logFile.seekp(0, ios::end);
	
	CMenu* pMainMenu = GetMenu();
	CMenu* pEditMenu = pMainMenu->GetSubMenu(1);
	
	if(m_bLogged)
	{		
		pEditMenu->EnableMenuItem(ID_EDIT_VIEWELAPSEDTIME, MF_DISABLED | MF_GRAYED);
		pEditMenu->EnableMenuItem(ID_EDIT_VIEWSUMMARYREPORT, MF_DISABLED | MF_GRAYED);
		
		GetDlgItem(IDC_LOGIN)->SetWindowText("Login");
		GetDlgItem(IDC_USERNAME)->EnableWindow(true);
		GetDlgItem(IDC_PASSWORD)->EnableWindow(true);
		
		endSessionLog();
		
		return;
	}
	
	for(i = 0; i < m_nNumUsers; i++)
	{
		if(m_szUsername == m_arUsers[i].getUsername() && m_szPassword == m_arUsers[i].getPassword())
		{
			// Password and username match a user in the records
			found = true;
			m_bLogged = true;
			m_arUsers[i].login();
			m_nUserLogged = i;
			
			if(m_arUsers[i].getAccess() == 1)
				pEditMenu->EnableMenuItem(ID_EDIT_VIEWSUMMARYREPORT, MF_ENABLED);
			pEditMenu->EnableMenuItem(ID_EDIT_VIEWELAPSEDTIME, MF_ENABLED);

			CTime time = CTime::GetCurrentTime();
			m_LoginTime = time.Format( "%B %d, %Y %H:%M:%S" );
			
			CString log = time.Format( "%A %B %d %H:%M:%S %Y" );
			
			for(j = 0; j < m_szUsername.GetLength(); j++)
				logFile << m_szUsername[j];
			logFile << "   ";

			for(j = 0; j < log.GetLength(); j++)
				logFile << log[j];
			logFile << "   ";

			// Clear text boxes
			m_szUsername = "";
			m_szPassword = "";

			GetDlgItem(IDC_LOGIN)->SetWindowText("Logout");
			GetDlgItem(IDC_USERNAME)->EnableWindow(false);
			GetDlgItem(IDC_PASSWORD)->EnableWindow(false);

			MessageBox("You are logged in.", "Logged In");
			// break out of for loop
			break;
		}
	}
	
	if(!found)
		MessageBox("Incorrect Username and/or Password","Bad Login");

	UpdateData(false);

}

void CStudentLoggerDlg::OnFileExit() 
{
	// Call inherited Exit function
	// write information back out to file
	int i;
	ofstream outfile("logins.txt", ios::out);
	if(!outfile)
	{
		MessageBox("File could not be opened for write", "Error on Write");
		return;
	}

	if(m_bLogged)
	{
		m_arUsers[m_nUserLogged].logout();
		endSessionLog();
	}

	outfile << m_nNumUsers << endl;
	for(i = 0; i < m_nNumUsers; i++)
	{
		outfile << m_arUsers[i];
	}

	outfile.close();
	OnOK();	
}

void CStudentLoggerDlg::OnEditViewelapsedtime() 
{
	if(!m_bLogged)
	{
		MessageBox("You must be logged in first.","Not Logged In");
	}
	else
	{
		CTimeSpan time = m_arUsers[m_nUserLogged].getSessionTime();
		CString timeString = time.Format("%H:%M:%S");
		MessageBox(CString("Elapsed Time: ")+timeString, "Session Time");	
	}
}

void CStudentLoggerDlg::endSessionLog()
{
	ofstream logFile;
	int j;
	logFile.open("logfile.txt", ios::app);

	m_bLogged = false; // logout
	m_arUsers[m_nUserLogged].logout();
	
	CTimeSpan session = m_arUsers[m_nUserLogged].getSessionTime();
	CString sesStr = session.Format( "%H:%M:%S");
	
	for(j = 0; j < sesStr.GetLength(); j++)
		logFile << sesStr[j];
	logFile << "   ";
		
	sesStr = m_arUsers[m_nUserLogged].getTotalTime();
	for(j = 0; j < sesStr.GetLength(); j++)
		logFile << sesStr[j];
	logFile << endl;

	logFile.close();
}

void CStudentLoggerDlg::OnEditViewsummaryreport() 
{
	//MessageBox("Not Implemented Yet", "Not Implemented");
	CSummaryDialog summary;
	summary.DoModal();
}

void CStudentLoggerDlg::loadData()
{
	m_bLogged = false;
	ifstream logins;
	logins.open("logins.txt");
	
	int access, hour, min, sec, i;
	logins >> m_nNumUsers;
	if(!logins)
		cerr << "Error: logins.txt could not be opened" << endl;

	m_arUsers = new CStudent[m_nNumUsers];
	char* user;
	char* pass;

	i = 0;
	while(i < m_nNumUsers && !logins.eof())
	{
		user = new char[30];
		pass = new char[30];

		logins >> user >> pass >> access >> hour >> min >> sec;

		m_arUsers[i].setUsername(CString(user));
		m_arUsers[i].setPassword(CString(pass));
		m_arUsers[i].setAccess(access);
		if(!m_arUsers[i].setTotalTime(hour, min, sec))
			MessageBox("Time not set", "ERROR");

		i++;
		delete[] user;
		delete[] pass;
	}

	//CWnd
	
	logins.close();
}
