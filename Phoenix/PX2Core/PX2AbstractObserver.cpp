/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AbstractObserver.cpp
*
*/

#include "PX2AbstractObserver.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
AbstractObserver::AbstractObserver()
{
}
//----------------------------------------------------------------------------
AbstractObserver::AbstractObserver(const AbstractObserver& observer)
{
	PX2_UNUSED(observer);
}
//----------------------------------------------------------------------------
AbstractObserver::~AbstractObserver()
{
}
//----------------------------------------------------------------------------
AbstractObserver& AbstractObserver::operator = (
	const AbstractObserver& observer)
{
	PX2_UNUSED(observer);
	return *this;
}
//----------------------------------------------------------------------------