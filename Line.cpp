// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "myCAD.h"
#include "Line.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLine::CLine()
{
}

CLine::~CLine()
{

}

void CLine::OnDraw(CDC *pDC)
{

    CPen* pOldPen;
   
    pOldPen = (CPen*)pDC->SelectObject(&m_Pen);
   
    pDC->MoveTo(m_posBegin);
    pDC->LineTo(m_posEnd);

    pDC->SelectObject(pOldPen);

}

void CLine::OnLButtonDown(UINT nFlags, CPoint point)
{

    m_posBegin = point;

}

void CLine::OnLButtonUp(UINT nFlags, CPoint point)
{
    m_posEnd = point;
}


void CLine::OnMouseMove(UINT nFlags, CPoint point)
{
    m_posEnd = point;
}