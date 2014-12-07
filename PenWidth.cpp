// PenWidth.cpp : implementation file
//

#include "stdafx.h"
#include "myCAD.h"
#include "PenWidth.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPenWidth dialog


CPenWidth::CPenWidth(CWnd* pParent /*=NULL*/)
	: CDialog(CPenWidth::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPenWidth)
	m_nWidth = 1;
	//}}AFX_DATA_INIT
}


void CPenWidth::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPenWidth)
	DDX_Text(pDX, IDC_EDIT1, m_nWidth);
	DDV_MinMaxInt(pDX, m_nWidth, 1, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPenWidth, CDialog)
	//{{AFX_MSG_MAP(CPenWidth)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPenWidth message handlers
