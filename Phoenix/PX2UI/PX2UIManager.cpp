// PX2UIManager.cpp

#include "PX2UIManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
UIManager::UIManager()
{
	mDefaultUIView = new0 UIView();
	mUIViews["DefaultUIView"] = mDefaultUIView;
}
//----------------------------------------------------------------------------
UIManager::~UIManager()
{
}
//----------------------------------------------------------------------------
void UIManager::Clear()
{
	mDefaultUIView->Clear();

	std::map<std::string, UIViewPtr>::iterator it = mUIViews.begin();
	for (; it != mUIViews.end(); it++)
	{
		it->second->Clear();
	}
}
//----------------------------------------------------------------------------
bool UIManager::IsHasUIView(const std::string &name) const
{
	std::map<std::string, UIViewPtr>::const_iterator it = mUIViews.find(name);

	if (it == mUIViews.end())
		return false;

	return true;
}
//----------------------------------------------------------------------------
bool UIManager::AddUIView(const std::string &name, UIView *view)
{
	if (IsHasUIView(name))
	{
		assertion("view alread exist:%s", name.c_str());
		return false;
	}

	mUIViews[name] = view;

	return true;
}
//----------------------------------------------------------------------------
bool UIManager::RemoveUIView(const std::string &name)
{
	std::map<std::string, UIViewPtr>::iterator it = mUIViews.find(name);

	if (it == mUIViews.end())
	{
		mUIViews.erase(it);
	}

	return false;
}
//----------------------------------------------------------------------------