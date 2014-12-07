// Factroy.h: interface for the CFactroy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACTROY_H__FC8420C8_4BA1_4C23_A3AC_AA35A00556F7__INCLUDED_)
#define AFX_FACTROY_H__FC8420C8_4BA1_4C23_A3AC_AA35A00556F7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "IShape.h"

class CFactroy  
{
public:
	CFactroy();
	virtual ~CFactroy();
    virtual IShape* CreateShape() = 0;

};

#endif // !defined(AFX_FACTROY_H__FC8420C8_4BA1_4C23_A3AC_AA35A00556F7__INCLUDED_)
