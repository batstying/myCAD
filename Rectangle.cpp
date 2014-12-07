// Rectangle.cpp: implementation of the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "myCAD.h"
#include "Rectangle.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRectangle::CRectangle()
{
}

CRectangle::~CRectangle()
{
    
}

void  CRectangle::OnDraw(CDC* pDC)
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
    pDC->Rectangle(&rect);
    
    pDC->SelectObject(pOldBrush);
    pDC->SelectObject(pOldPen);
    
    //pDC->Draw3dRect(rect, RGB(0, 0, 0), RGB(0, 0, 0));
}



void CRectangle::OnLButtonDown(UINT nFlags, CPoint point)
{
    
    m_posBegin = point;
    
}

void CRectangle::OnLButtonUp(UINT nFlags, CPoint point)
{
    m_posEnd = point;
}


void CRectangle::OnMouseMove(UINT nFlags, CPoint point)
{
    m_posEnd = point;
}
