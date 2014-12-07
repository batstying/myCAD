// myCADView.h : interface of the CMyCADView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYCADVIEW_H__0ED480C6_8D50_43AA_8C82_F25233689B28__INCLUDED_)
#define AFX_MYCADVIEW_H__0ED480C6_8D50_43AA_8C82_F25233689B28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// #include "Line.h"
// #include "Rectangle.h"
#include "IShape.h"
#include "LineFactory.h"
#include "RectFactroy.h"
#include "EllFactroy.h"

class CMyCADView : public CView
{
protected: // create from serialization only
	CMyCADView();
	DECLARE_DYNCREATE(CMyCADView)

// Attributes
public:
    int m_nPenStyle;
    int m_nBruStyle;
	CMyCADDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyCADView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyCADView();
    void InitPenAndBrush();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    HCURSOR m_hCur;
    IShape*  m_pShape;
    BOOL    m_isDraw;
    CFactroy* m_pFactory;

    COLORREF m_penColor; //»­±ÊÑÕÉ«
    int m_nPenIndex;//»­±ÊÑùÊ½
    int m_nWidth; //»­±Ê¿í¶È
    
    LOGBRUSH m_logBrush;//Ë¢×ÓÊôÐÔ


// Generated message map functions
protected:
	//{{AFX_MSG(CMyCADView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLine();
	afx_msg void OnRectangle();
	afx_msg void OnEllipse();
	afx_msg void OnPENWidth();
	afx_msg void OnPenSolid();
	afx_msg void OnPenNull();
	afx_msg void OnPenDot();
	afx_msg void OnUpdatePenSolid(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePenNull(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePenDot(CCmdUI* pCmdUI);
	afx_msg void OnPenDash();
	afx_msg void OnUpdatePenDash(CCmdUI* pCmdUI);
	afx_msg void OnPencolor();
	afx_msg void OnBrushcolor();
	afx_msg void OnBruSolid();
	afx_msg void OnUpdateBruSolid(CCmdUI* pCmdUI);
	afx_msg void OnBruPattern();
	afx_msg void OnUpdateBruPattern(CCmdUI* pCmdUI);
	afx_msg void OnBruNull();
	afx_msg void OnUpdateBruNull(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in myCADView.cpp
inline CMyCADDoc* CMyCADView::GetDocument()
   { return (CMyCADDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCADVIEW_H__0ED480C6_8D50_43AA_8C82_F25233689B28__INCLUDED_)
