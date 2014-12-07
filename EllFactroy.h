// EllFactroy.h: interface for the CEllFactroy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELLFACTROY_H__D352DBE9_1885_4E79_AD78_D39BA2ED6824__INCLUDED_)
#define AFX_ELLFACTROY_H__D352DBE9_1885_4E79_AD78_D39BA2ED6824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Factroy.h"
#include "Ellipse.h"

class CEllFactroy : public CFactroy  
{
public:
	CEllFactroy();
	virtual ~CEllFactroy();

    virtual IShape* CreateShape();
};

#endif // !defined(AFX_ELLFACTROY_H__D352DBE9_1885_4E79_AD78_D39BA2ED6824__INCLUDED_)
