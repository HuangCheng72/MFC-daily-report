; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=MainDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DailySubmit.h"

ClassCount=4
Class1=CDailySubmitApp
Class2=CDailySubmitDlg
Class3=CAboutDlg

ResourceCount=4
Resource1=IDD_DAILYSUBMIT_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Class4=MainDlg
Resource4=IDD_MAINDLG

[CLS:CDailySubmitApp]
Type=0
HeaderFile=DailySubmit.h
ImplementationFile=DailySubmit.cpp
Filter=N

[CLS:CDailySubmitDlg]
Type=0
HeaderFile=DailySubmitDlg.h
ImplementationFile=DailySubmitDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=CDailySubmitDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=DailySubmitDlg.h
ImplementationFile=DailySubmitDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DAILYSUBMIT_DIALOG]
Type=1
Class=CDailySubmitDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631552
Control4=IDC_EDIT2,edit,1350631584
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC1,static,1073872896
Control7=IDC_STATIC2,static,1073872896
Control8=IDC_EDIT3,edit,1082196096
Control9=IDC_EDIT4,edit,1082196096
Control10=IDC_BUTTON1,button,1342242816

[DLG:IDD_MAINDLG]
Type=1
Class=MainDlg
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350633600
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT3,edit,1350631552
Control10=IDC_EDIT4,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_EDIT5,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_EDIT6,edit,1350631552
Control15=IDC_STATIC,button,1342177287
Control16=IDC_LIST3,SysListView32,1350631425
Control17=IDC_BUTTON1,button,1342242816

[CLS:MainDlg]
Type=0
HeaderFile=MainDlg.h
ImplementationFile=MainDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

