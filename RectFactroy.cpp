// RectFactroy.cpp: implementation of the CRectFactroy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "myCAD.h"
#include "RectFactroy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRectFactroy::CRectFactroy()
{

}

CRectFactroy::~CRectFactroy()
{

}

IShape* CRectFactroy::CreateShape()
{
    return new CRectangle();
}
