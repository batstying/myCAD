; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyCADView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "myCAD.h"
LastPage=0

ClassCount=6
Class1=CMyCADApp
Class2=CMyCADDoc
Class3=CMyCADView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CPenWidth
Resource3=IDD_PENWIDTH

[CLS:CMyCADApp]
Type=0
HeaderFile=myCAD.h
ImplementationFile=myCAD.cpp
Filter=N

[CLS:CMyCADDoc]
Type=0
HeaderFile=myCADDoc.h
ImplementationFile=myCADDoc.cpp
Filter=N

[CLS:CMyCADView]
Type=0
HeaderFile=myCADView.h
ImplementationFile=myCADView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=IDM_BRU_NULL


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_BRU_SOLID
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=myCAD.cpp
ImplementationFile=myCAD.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=IDM_LINE
Command18=IDM_RECTANGLE
Command19=IDM_ELLIPSE
Command20=IDM_PENWidth
Command21=IDM_PEN_SOLID
Command22=IDM_PEN_DOT
Command23=IDM_PEN_DASH
Command24=IDM_PEN_NULL
Command25=IDM_PENCOLOR
Command26=IDM_BRU_SOLID
Command27=IDM_BRU_PATTERN
Command28=IDM_BRU_NULL
Command29=IDM_BRUSHCOLOR
CommandCount=29

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_PENWIDTH]
Type=1
Class=CPenWidth
ControlCount=2
Control1=IDC_EDIT1,edit,1350639744
Control2=IDOK,button,1342242816

[CLS:CPenWidth]
Type=0
HeaderFile=PenWidth.h
ImplementationFile=PenWidth.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

