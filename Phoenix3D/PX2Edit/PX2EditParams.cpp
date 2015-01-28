/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EditorParams.cpp
*
*/

#include "PX2EditParams.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Node, EditParams);
PX2_IMPLEMENT_STREAM(EditParams);
PX2_IMPLEMENT_FACTORY(EditParams);
PX2_IMPLEMENT_DEFAULT_NAMES(Node, EditParams);
PX2_IMPLEMENT_DEFAULT_STREAM(Node, EditParams);
//-----------------------------------------------------------------------------
EditParams::EditParams()
{
	GridSize = 400.0f;
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