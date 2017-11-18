; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSummaryDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Student Logger.h"

ClassCount=4
Class1=CStudentLoggerApp
Class2=CStudentLoggerDlg
Class3=CAboutDlg

ResourceCount=5
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_STUDENTLOGGER_DIALOG
Class4=CSummaryDialog
Resource4=IDD_SUMMARY
Resource5=IDR_MENU1

[CLS:CStudentLoggerApp]
Type=0
HeaderFile=Student Logger.h
ImplementationFile=Student Logger.cpp
Filter=N
LastObject=IDC_REPORTLIST

[CLS:CStudentLoggerDlg]
Type=0
HeaderFile=Student LoggerDlg.h
ImplementationFile=Student LoggerDlg.cpp
Filter=D
LastObject=CStudentLoggerDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=Student LoggerDlg.h
ImplementationFile=Student LoggerDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_STUDENTLOGGER_DIALOG]
Type=1
Class=CStudentLoggerDlg
ControlCount=7
Control1=IDC_USERNAME,edit,1350631552
Control2=IDC_PASSWORD,edit,1350631584
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_LOGIN,button,1342242816
Control6=IDC_LOGINTIME,edit,1350633601
Control7=IDC_STATIC,static,1342308354

[MNU:IDR_MENU1]
Type=1
Class=CStudentLoggerDlg
Command1=ID_FILE_EXIT
Command2=ID_EDIT_VIEWELAPSEDTIME
Command3=ID_EDIT_VIEWSUMMARYREPORT
CommandCount=3

[DLG:IDD_SUMMARY]
Type=1
Class=CSummaryDialog
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_REPORT,edit,1350639684

[CLS:CSummaryDialog]
Type=0
HeaderFile=SummaryDialog.h
ImplementationFile=SummaryDialog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_REPORT
VirtualFilter=dWC

