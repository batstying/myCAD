// Rectangle.h: interface for the CRectangle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTANGLE_H__4F7BBA9A_603B_44A1_9526_EE1A4CAD3EE1__INCLUDED_)
#define AFX_RECTANGLE_H__4F7BBA9A_603B_44A1_9526_EE1A4CAD3EE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IShape.h"

class CRectangle  :public IShape
{
public:
	CRectangle();
	virtual ~CRectangle();
    virtual void OnDraw(CDC* pDc);
    virtual void OnLButtonDown(UINT nFlags, CPoint point);
    virtual void OnLButtonUp(UINT nFlags, CPoint point);
    virtual void OnMouseMove(UINT nFlags, CPoint point);

//     CPoint    getBeginPos();
//     CPoint    getEndPos();
//     CPen*      getPen();
//     CBrush*    getBrush();
// 
//     bool    setBeginPos(const CPoint& posBegin);
//     bool    setEndPos(const CPoint& posEnd);
//     bool    setPen(CPen* pen);
//     bool    setBrush(CBrush* brush);
// 
// private:    
//     CPoint m_posBegin;
//     CPoint m_posEnd;
//     CPen*   m_pPen;
//     CBrush* m_pBrush;

};

#endif // !defined(AFX_RECTANGLE_H__4F7BBA9A_603B_44A1_9526_EE1A4CAD3EE1__INCLUDED_)
