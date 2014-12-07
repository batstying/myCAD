// Ellipse.h: interface for the CEllipse class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLIPSE_H__486D2EA4_A8A4_43C0_A6ED_9D33BF9FEA67__INCLUDED_)
#define AFX_ELLIPSE_H__486D2EA4_A8A4_43C0_A6ED_9D33BF9FEA67__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IShape.h"

class CEllipse : public IShape  
{
public:
	CEllipse();
	virtual ~CEllipse();
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

#endif // !defined(AFX_ELLIPSE_H__486D2EA4_A8A4_43C0_A6ED_9D33BF9FEA67__INCLUDED_)
