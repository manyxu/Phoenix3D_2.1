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
	:
	mThemeType(THEME_BLUE)
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

			//CurTheme
			XMLNode curThemeNode = themeNode.GetChild("CurTheme");
			if (!curThemeNode.IsNull())
			{
				ThemeType themeType = (ThemeType)curThemeNode.AttributeToInt("ThemeType");
				mCurTheme.type = themeType;

				std::string colorStr = curThemeNode.AttributeToString("inactiveColor");
				StringTokenizer stk(colorStr, ",");
				Float3 color = Float3::MakeColor(
					StringHelp::StringToInt(stk[0]),
					StringHelp::StringToInt(stk[1]),
					StringHelp::StringToInt(stk[2])); 
				mCurTheme.inactiveColor = color;

				colorStr = curThemeNode.AttributeToString("activeColor");
				StringTokenizer stk1(colorStr, ",");
				color = Float3::MakeColor(
					StringHelp::StringToInt(stk1[0]),
					StringHelp::StringToInt(stk1[1]),
					StringHelp::StringToInt(stk1[2]));
				mCurTheme.activeColor = color;

				colorStr = curThemeNode.AttributeToString("backColor");
				StringTokenizer stk2(colorStr, ",");
				color = Float3::MakeColor(
					StringHelp::StringToInt(stk2[0]),
					StringHelp::StringToInt(stk2[1]),
					StringHelp::StringToInt(stk2[2]));
				mCurTheme.backColor = color;

				colorStr = curThemeNode.AttributeToString("tabBackColor");
				StringTokenizer stk3(colorStr, ",");
				color = Float3::MakeColor(
					StringHelp::StringToInt(stk3[0]),
					StringHelp::StringToInt(stk3[1]),
					StringHelp::StringToInt(stk3[2]));
				mCurTheme.tabBackColor = color;		
			}
			//All Theme
			int themeNum = themeNode.AttributeToInt("themeNum");
			for (int i = 0; i < themeNum; i++)
			{
				std::string nodeName = "Theme" + StringHelp::IntToString(i);
				XMLNode themeNode = themeNode.GetChild(nodeName.c_str());
				if (!themeNode.IsNull())
				{
					Theme theme;
					theme.type = (ThemeType)themeNode.AttributeToInt("ThemeType");

					std::string colorStr = themeNode.AttributeToString("inactiveColor");
					StringTokenizer stk(colorStr, ",");
					Float3 color = Float3::MakeColor(
						StringHelp::StringToInt(stk[0]),
						StringHelp::StringToInt(stk[1]),
						StringHelp::StringToInt(stk[2]));
					theme.inactiveColor = color;

					colorStr = themeNode.AttributeToString("activeColor");
					StringTokenizer stk1(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk1[0]),
						StringHelp::StringToInt(stk1[1]),
						StringHelp::StringToInt(stk1[2]));
					theme.activeColor = color;

					colorStr = themeNode.AttributeToString("backColor");
					StringTokenizer stk2(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk2[0]),
						StringHelp::StringToInt(stk2[1]),
						StringHelp::StringToInt(stk2[2]));
					theme.backColor = color;

					colorStr = themeNode.AttributeToString("tabBackColor");
					StringTokenizer stk3(colorStr, ",");
					color = Float3::MakeColor(
						StringHelp::StringToInt(stk3[0]),
						StringHelp::StringToInt(stk3[1]),
						StringHelp::StringToInt(stk3[2]));
					theme.tabBackColor = color;

					mThemes[i] = theme;

				}
			}
			//if (!generalNode.IsNull())
			//{
			//	name = generalNode.AttributeToString("name");
			//	width = generalNode.AttributeToInt("width");
			//	height = generalNode.AttributeToInt("height");
			//	std::string colorStr = generalNode.AttributeToString("color");
			//	StringTokenizer stk(colorStr, ",");
			//	Float4 color = Float4::MakeColor(
			//		StringHelp::StringToInt(stk[0]),
			//		StringHelp::StringToInt(stk[1]),
			//		StringHelp::StringToInt(stk[2]),
			//		StringHelp::StringToInt(stk[3]));

			//	SetName(name);
			//	SetSize(Sizef((float)width, (float)height));
			//	SetBackgroundColor(color);
			//}

			//// scene
			//XMLNode sceneNode = rootNode.GetChild("scene");
			//if (!sceneNode.IsNull())
			//{
			//	sceneFilename = sceneNode.AttributeToString("filename");
			//	SetSceneFilename(sceneFilename);
			//}

			//// language
			//XMLNode languageNode = rootNode.GetChild("language");

			//// publish
			//XMLNode publishNode = rootNode.GetChild("publish");

			//// setting
			//XMLNode settingNode = rootNode.GetChild("setting");

			//// split file names
			//std::string outPath;
			//std::string outBaseName;
			//std::string outExt;
			//StringHelp::SplitFullFilename(filename, outPath, outBaseName, outExt);

			//// ui
			//mUIFilename = outPath + outBaseName + "_ui.px2obj";
		}
	}
	else
	{
		return false;
	}
	return true;
}
//-----------------------------------------------------------------------------
void EditParams::ThemeChange(ThemeType type)
{
	//mThemeType = type;
	std::map<int, Theme>::iterator it = mThemes.begin();

	for (; it != mThemes.end(); it++)
	{
		if (it->second.type == type)
		{
			SetCurTheme(it->second);
		}
	}

	Event *event = EditEventSpace::CreateEventX(EditEventSpace::EditThemeChange);
	EventWorld::GetSingleton().BroadcastingLocalEvent(event);
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

	std::vector<std::string> themeType;
	themeType.push_back("THEME_BLUE");
	themeType.push_back("THEME_DARK");
	themeType.push_back("THEME_TINT");
	AddPropertyEnum("Edit_ThemeType", (int)mThemeType, themeType);
}
//-----------------------------------------------------------------------------
void EditParams::OnPropertyChanged(const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);
	if ("Edit_ThemeType" == obj.Name)
	{
		ThemeChange((ThemeType)(*Any_Cast<int>(&obj.Data)));
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
