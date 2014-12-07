// RectFactroy.h: interface for the CRectFactroy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECTFACTROY_H__686AC01A_52E8_44ED_B54D_2AB1EF27D277__INCLUDED_)
#define AFX_RECTFACTROY_H__686AC01A_52E8_44ED_B54D_2AB1EF27D277__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Factroy.h"
#include "Rectangle.h"

class CRectFactroy : public CFactroy  
{
public:
	CRectFactroy();
	virtual ~CRectFactroy();

    virtual IShape* CreateShape();

};

#endif // !defined(AFX_RECTFACTROY_H__686AC01A_52E8_44ED_B54D_2AB1EF27D277__INCLUDED_)
