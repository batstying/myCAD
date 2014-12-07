// Ellipse.cpp: implementation of the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "myCAD.h"
#include "Ellipse.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEllipse::CEllipse()
{

}

CEllipse::~CEllipse()
{

}

void  CEllipse::OnDraw(CDC* pDC)
{
    CRect rect;
    rect.top = m_posBegin.y;
    rect.left = m_posBegin.x;
    rect.right = m_posEnd.x;
    rect.bottom = m_posEnd.y;
    
    CBrush* pOldBrush;
    CPen* pOldPen;
    
    pOldBrush = (CBrush*)pDC->SelectObject(&m_Brush);
    pOldPen = (CPen*)pDC->SelectObject(&m_Pen);
    pDC->Ellipse(&rect);
    
    pDC->SelectObject(pOldBrush);
    pDC->SelectObject(pOldPen);

}

void CEllipse::OnLButtonDown(UINT nFlags, CPoint point)
{
    
    m_posBegin = point;
    
}

void CEllipse::OnLButtonUp(UINT nFlags, CPoint point)
{
    m_posEnd = point;
}


void CEllipse::OnMouseMove(UINT nFlags, CPoint point)
{
    m_posEnd = point;
}
