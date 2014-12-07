// EllFactroy.cpp: implementation of the CEllFactroy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "myCAD.h"
#include "EllFactroy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEllFactroy::CEllFactroy()
{

}

CEllFactroy::~CEllFactroy()
{

}

IShape* CEllFactroy::CreateShape()
{
    return new CEllipse();
}
