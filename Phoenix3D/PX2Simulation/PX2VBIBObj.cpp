// PX2VBIBObj.cpp

#include "PX2VBIBObj.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
VBIBManager::VBIBManager() :
mUBIBTable(512)
{
}
//----------------------------------------------------------------------------
VBIBManager::~VBIBManager()
{
}
//----------------------------------------------------------------------------
void VBIBManager::Clear()
{
	mUBIBTable.Clear();
}
//----------------------------------------------------------------------------
void VBIBManager::AddVBIB(const std::string &texPackFilename, VertexBuffer *vb,
	IndexBuffer *ib)
{
	VBIBObj obj;
	obj.IsValued = true;
	obj.mVB = vb;
	obj.mIB = ib;
	mUBIBTable.Insert(texPackFilename.c_str(), obj);
}
//----------------------------------------------------------------------------
VBIBObj &VBIBManager::GetVBID(const std::string &texPackFilename)
{
	UBIBTable::Element *ele = mUBIBTable.Find(texPackFilename.c_str());
	if (ele)
		return ele->value;

	return mNotValied;
}
//----------------------------------------------------------------------------