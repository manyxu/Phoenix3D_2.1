/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PropertyPage.cpp
*
*/

#include "PX2PropertyPage.hpp"
#include "PX2PropertyGrid.hpp"
#include "PX2EventWorld.hpp"

using namespace PX2Editor;
using namespace PX2;

PropertyPage::PropertyPage (PropertyGrid *parent, std::string name)
	:
mParent(parent),
	mName(name)
{
	mPage = mParent->mPropGridManager->AddPage(name.c_str());
}
//-----------------------------------------------------------------------------
PropertyPage::~PropertyPage ()
{
	for (int i=0; i<(int)mProperties.size(); i++)
	{
		EventWorld::GetSingleton().GoOut(mProperties[i]);
	}
}
//-----------------------------------------------------------------------------
void PropertyPage::Clear ()
{
	for (int i=0; i<(int)mProperties.size(); i++)
	{
		EventWorld::GetSingleton().GoOut(mProperties[i]);
	}
	mProperties.clear();
	mPage->Clear();
}
//-----------------------------------------------------------------------------
Property *PropertyPage::AddProperty (const std::string &name,
	const std::string &tag,	Property::PropertyType type, void *data, 
	bool enable, const std::vector<std::string> *enums)
{
	Property *prop = new0 Property(this, name, tag, type, data, enable, enums);
	return prop;
}
//-----------------------------------------------------------------------------
Property *PropertyPage::GetProperty (const std::string &name)
{
	for (int i=0; i<(int)mProperties.size(); i++)
	{
		if (name == mProperties[i]->GetName())
			return mProperties[i];
	}

	return 0;
}
//-----------------------------------------------------------------------------
bool PropertyPage::HasProperty (wxPGProperty *prop)
{
	for (int i=0; i<(int)mProperties.size(); i++)
	{
		if (prop == mProperties[i]->mProperty)
			return true;
	}

	return false;
}
//-----------------------------------------------------------------------------
void PropertyPage::AddProperty (Property *prop)
{
	mProperties.push_back(prop);
}
//-----------------------------------------------------------------------------
void PropertyPage::RemoveProperty (const std::string &name)
{
	std::vector<PropertyPtr>::iterator it = mProperties.begin();
	for (; it!=mProperties.end(); it++)
	{
		if ((*it)->GetName() == name)
		{
			mPage->DeleteProperty((*it)->GetWxProperty());
			*it = 0;
			mProperties.erase(it);

			return;
		}
	}
}
//-----------------------------------------------------------------------------
void PropertyPage::OnPropertyGridChange (wxPropertyGridEvent &event)
{
	for (int i=0; i<(int)mProperties.size(); i++)
	{
		mProperties[i]->OnChange(event);
	}
}
//-----------------------------------------------------------------------------
void PropertyPage::OnPropertyGridChanging (wxPropertyGridEvent &event)
{
	for (int i=0; i<(int)mProperties.size(); i++)
	{
		mProperties[i]->OnChanging(event);
	}
}
//-----------------------------------------------------------------------------
void PropertyPage::OnPropertyGridSelect (wxPropertyGridEvent &event)
{
	PX2_UNUSED(event);
}
//-----------------------------------------------------------------------------