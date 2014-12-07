// myCAD.h : main header file for the MYCAD application
//

#if !defined(AFX_MYCAD_H__7B5488A1_E139_4C0D_9175_E65FEC13B5FD__INCLUDED_)
#define AFX_MYCAD_H__7B5488A1_E139_4C0D_9175_E65FEC13B5FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyCADApp:
// See myCAD.cpp for the implementation of this class
//

class CMyCADApp : public CWinApp
{
public:
	CMyCADApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCADApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyCADApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCAD_H__7B5488A1_E139_4C0D_9175_E65FEC13B5FD__INCLUDED_)
