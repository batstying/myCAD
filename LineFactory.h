// LineFactory.h: interface for the CLineFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEFACTORY_H__D732BE63_5584_4B45_AD44_D23CFF180BE7__INCLUDED_)
#define AFX_LINEFACTORY_H__D732BE63_5584_4B45_AD44_D23CFF180BE7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Factroy.h"
#include "LineFactory.h"
#include "Line.h"

class CLineFactory : public CFactroy  
{
public:
	CLineFactory();
	virtual ~CLineFactory();

    virtual IShape* CreateShape();

};

#endif // !defined(AFX_LINEFACTORY_H__D732BE63_5584_4B45_AD44_D23CFF180BE7__INCLUDED_)
