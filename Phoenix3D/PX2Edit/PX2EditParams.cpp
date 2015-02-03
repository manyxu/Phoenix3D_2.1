/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EditorParams.cpp
*
*/

#include "PX2EditParams.hpp"
#include "PX2EditEventType.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2StringTokenizer.hpp"
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
	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();

			// Theme
			XMLNode themeNode = rootNode.GetChild("Theme");

			//All theme index
			int themeNum = themeNode.AttributeToInt("idxNum");
			for (int i = 0; i < themeNum; i++)
			{
				std::string nodeName = "Theme" + StringHelp::IntToString(i);

				if (0 == i)
				{
					nodeName = "CurTheme";
				}

				XMLNode themeInNode = themeNode.GetChild(nodeName.c_str());
				if (!themeInNode.IsNull())
				{
					Theme theme;
					theme.type = themeInNode.AttributeToString("ThemeType");

					std::string colorStr = themeInNode.AttributeToString("inactiveColor");
					StringTokenizer stk(colorStr, ",");
					Float3 color = Float3::MakeColor(
						StringHelp::StringToInt(stk[0]),
						StringHelp::StringToInt(stk[1]),
						StringHelp::StringToInt(stk[2]));
					theme.inactiveColor = color;

					colorStr = themeInNode.AttributeToString("activeColor");
					StringTokenizer stk1(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk1[0]),
						StringHelp::StringToInt(stk1[1]),
						StringHelp::StringToInt(stk1[2]));
					theme.activeColor = color;

					colorStr = themeInNode.AttributeToString("backColor");
					StringTokenizer stk2(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk2[0]),
						StringHelp::StringToInt(stk2[1]),
						StringHelp::StringToInt(stk2[2]));
					theme.backColor = color;

					colorStr = themeInNode.AttributeToString("tabBackColor");
					StringTokenizer stk3(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk3[0]),
						StringHelp::StringToInt(stk3[1]),
						StringHelp::StringToInt(stk3[2]));
					theme.tabBackColor = color;

					colorStr = themeInNode.AttributeToString("fontColor");
					StringTokenizer stk4(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk4[0]),
						StringHelp::StringToInt(stk4[1]),
						StringHelp::StringToInt(stk4[2]));
					theme.fontColor = color;

					colorStr = themeInNode.AttributeToString("captionColor");
					StringTokenizer stk5(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk5[0]),
						StringHelp::StringToInt(stk5[1]),
						StringHelp::StringToInt(stk5[2]));
					theme.captionColor = color;

					colorStr = themeInNode.AttributeToString("captionActColor");
					StringTokenizer stk6(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk6[0]),
						StringHelp::StringToInt(stk6[1]),
						StringHelp::StringToInt(stk6[2]));
					theme.captionActColor = color;

					colorStr = themeInNode.AttributeToString("toolBarColor");
					StringTokenizer stk7(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk7[0]),
						StringHelp::StringToInt(stk7[1]),
						StringHelp::StringToInt(stk7[2]));
					theme.toolBarColor = color;

					colorStr = themeInNode.AttributeToString("searchColor");
					StringTokenizer stk8(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk8[0]),
						StringHelp::StringToInt(stk8[1]),
						StringHelp::StringToInt(stk8[2]));
					theme.searchColor = color;

					if (0 == i)
					{
						mCurTheme = theme;
					}
					else
					{
						mThemes[i] = theme;
					}
				}
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}
//-----------------------------------------------------------------------------
void EditParams::ThemeChange(std::string type)
{
	//mThemeType = type;
	std::map<int, Theme>::iterator it = mThemes.begin();

	for (; it != mThemes.end(); it++)
	{
		if (it->second.type == type)
		{
			SetCurTheme(it->second);

			Event *event = EditEventSpace::CreateEventX(EditEventSpace::EditThemeChange);
			EventWorld::GetSingleton().BroadcastingLocalEvent(event);
		}
	}	
}
//-----------------------------------------------------------------------------
//EditParams::ThemeType EditParams::GetThemeType()
//{
//	return mThemeType;
//}
//-----------------------------------------------------------------------------
void EditParams::RegistProperties()
{
	Object::RegistProperties();

	AddPropertyClass("EditParams");
	mThemeTypes.clear();
	mThemeTypes.push_back("THEME_BLUE");
	mThemeTypes.push_back("THEME_DARK");
	mThemeTypes.push_back("THEME_TINT");
	int curTypeIdx = 0;
	Theme curTheme = GetCurTheme();
	std::vector<std::string>::iterator it = mThemeTypes.begin();
	for ( int i = 0; it != mThemeTypes.end(); it++)
	{
		if (*it == curTheme.type)
		{
			curTypeIdx = i;
		}
		i++;
	}
	AddPropertyEnum("Edit_ThemeType", curTypeIdx, mThemeTypes);
}
//-----------------------------------------------------------------------------
void EditParams::OnPropertyChanged(const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);
	if ("Edit_ThemeType" == obj.Name)
	{
		int curTypeIdx = *Any_Cast<int>(&obj.Data);
		ThemeChange(mThemeTypes[curTypeIdx]);
	}
}
//-----------------------------------------------------------------------------
void EditParams::SetCurTheme(Theme theme)
{
	mCurTheme = theme;
}
//-----------------------------------------------------------------------------
EditParams::Theme EditParams::GetCurTheme()
{
	return mCurTheme;
}
//-----------------------------------------------------------------------------
std::map<int, EditParams::Theme> EditParams::GetThemes()
{
	return mThemes;
}
//-----------------------------------------------------------------------------
