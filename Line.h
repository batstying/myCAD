// Line.h: interface for the CLine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINE_H__7D7841F2_42D6_4F31_B210_C16B4BCF5F4F__INCLUDED_)
#define AFX_LINE_H__7D7841F2_42D6_4F31_B210_C16B4BCF5F4F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "IShape.h"

class CLine  :public IShape
{
public:
	CLine();
	virtual ~CLine();
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

#endif // !defined(AFX_LINE_H__7D7841F2_42D6_4F31_B210_C16B4BCF5F4F__INCLUDED_)
