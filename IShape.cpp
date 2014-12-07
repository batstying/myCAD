// IShape.cpp: implementation of the IShape class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "myCAD.h"
#include "IShape.h"
#include "Line.h"
#include "Rectangle.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

IShape::IShape()
       :m_posBegin(0,0),m_posEnd(0,0)
{

}

IShape::~IShape()
{
}

CPoint IShape::getBeginPos()
{
    return m_posBegin;
}

CPoint IShape::getEndPos()
{
    return m_posEnd;
}

bool IShape::setBeginPos(const CPoint& posBegin)
{
    m_posBegin = posBegin;
    
    return true;
}

bool IShape::setEndPos(const CPoint& posEnd)
{
    m_posEnd = posEnd;
    
    return true;
}

const CPen* IShape::getPen()
{
    return &m_Pen; 
}

const CBrush* IShape::getBrush()
{
    return &m_Brush; 
}

bool IShape::setPen(int nPenStyle, int nWidth, COLORREF crColor)
{   
    m_Pen.CreatePen(nPenStyle, nWidth, crColor);

    return true;
}

bool IShape::setBrush(const LOGBRUSH* lo)
{

    // ... and initialize it with the LOGBRUSH.
    m_Brush.CreateBrushIndirect(lo);

    return true;
}