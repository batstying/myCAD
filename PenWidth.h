#if !defined(AFX_PENWIDTH_H__31A18F17_9984_40FD_9569_2CEBB789FE5F__INCLUDED_)
#define AFX_PENWIDTH_H__31A18F17_9984_40FD_9569_2CEBB789FE5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PenWidth.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPenWidth dialog

class CPenWidth : public CDialog
{
// Construction
public:
	CPenWidth(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPenWidth)
	enum { IDD = IDD_PENWIDTH };
	int		m_nWidth;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPenWidth)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPenWidth)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PENWIDTH_H__31A18F17_9984_40FD_9569_2CEBB789FE5F__INCLUDED_)
