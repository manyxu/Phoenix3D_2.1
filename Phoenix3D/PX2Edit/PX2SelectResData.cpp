// PX2SelectResData.cpp

#include "PX2SelectResData.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
SelectResData::SelectResData(SelectResType type) :
mSelectResType(type)
{
}
//----------------------------------------------------------------------------
SelectResData::~SelectResData()
{
}
//----------------------------------------------------------------------------
SelectResData::SelectResType SelectResData::GetSelectResType() const
{
	return mSelectResType;
}
//----------------------------------------------------------------------------