/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Visitor.cpp
*
*/

#include "PX2Visitor.hpp"
#include "PX2Any.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
Vistor::Vistor ()
{
}
//----------------------------------------------------------------------------
Vistor::~Vistor ()
{
}
//----------------------------------------------------------------------------
void Vistor::Visit (Object *obj, const int info)
{
	PX2_UNUSED(obj);
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------
void Vistor::Visit (Object *obj, const std::string &info)
{
	PX2_UNUSED(obj);
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------
void Vistor::Visit (Object *obj, const Any &info)
{
	PX2_UNUSED(obj);
	PX2_UNUSED(info);
}
//----------------------------------------------------------------------------