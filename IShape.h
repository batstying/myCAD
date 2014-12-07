// IShape.h: interface for the IShape class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ISHAPE_H__BFD08B16_656E_4BAA_BD14_6726CC997A10__INCLUDED_)
#define AFX_ISHAPE_H__BFD08B16_656E_4BAA_BD14_6726CC997A10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IShape  
{
public:
	IShape();
	virtual ~IShape();

    virtual void OnDraw(CDC* pDC) = 0;
    virtual void OnLButtonDown(UINT nFlags, CPoint point) = 0;
    virtual void OnLButtonUp(UINT nFlags, CPoint point) = 0;
    virtual void OnMouseMove(UINT nFlags, CPoint point) = 0;

    CPoint    getBeginPos();
    CPoint    getEndPos();
    const CPen*      getPen();
    const CBrush*    getBrush();
    
    bool    setBeginPos(const CPoint& posBegin);
    bool    setEndPos(const CPoint& posEnd);
    bool    setPen(int nPenStyle, int nWidth, COLORREF crColor);
    bool    setBrush(const LOGBRUSH* lo);
    
protected:    
    CPoint m_posBegin;
    CPoint m_posEnd;
    CPen   m_Pen;
    CBrush m_Brush;    

};

#endif // !defined(AFX_ISHAPE_H__BFD08B16_656E_4BAA_BD14_6726CC997A10__INCLUDED_)
