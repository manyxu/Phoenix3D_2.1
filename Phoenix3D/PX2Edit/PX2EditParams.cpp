/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EditorParams.cpp
*
*/

#include "PX2EditParams.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, EditParams);
PX2_IMPLEMENT_STREAM(EditParams);
PX2_IMPLEMENT_FACTORY(EditParams);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, EditParams);
PX2_IMPLEMENT_DEFAULT_STREAM(Object, EditParams);
//-----------------------------------------------------------------------------
EditParams::EditParams()
{
	GridSize = 40;
}
//-----------------------------------------------------------------------------
EditParams::~EditParams()
{
}
//-----------------------------------------------------------------------------
bool EditParams::Save(std::string filename)
{
	return true;
}
//-----------------------------------------------------------------------------
bool EditParams::Load(std::string filename)
{
	return true;
}
//-----------------------------------------------------------------------------