// PX2SelectResData.cpp

#include "PX2SelectResData.hpp"
#include "PX2Texture2D.hpp"
#include "PX2ResourceManager.hpp"
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
bool SelectResData::IsTheObjectTex() const
{
	if (RT_NORMAL == mSelectResType)
	{
		Texture2D *tex2D = DynamicCast<Texture2D>(TheObject);
		if (tex2D) return true;
	}
	else if (RT_TEXPACKELEMENT == mSelectResType)
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
Sizef SelectResData::GetTheObjectTexSize() const
{
	if (RT_NORMAL == mSelectResType)
	{
		Texture2D *tex2D = DynamicCast<Texture2D>(TheObject);
		if (tex2D)
			return Sizef((float)tex2D->GetWidth(), (float)tex2D->GetHeight());
	}
	else if (RT_TEXPACKELEMENT == mSelectResType)
	{
		const TexPackElement & texPackEle = PX2_RM.GetTexPackElement(
			ResPathname, EleName);
		return Sizef((float)texPackEle.W, (float)texPackEle.H);
	}

	return Sizef();
}
//----------------------------------------------------------------------------