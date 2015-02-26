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

//-----------------------------------------------------------------------------
// Theme
//-----------------------------------------------------------------------------
Theme::Theme()
{
	Name = "blue";

	Color_Aui_Background = Float3::MakeColor(41, 57, 85);

	Color_Aui_CaptionBackground = Float3::MakeColor(77, 96, 130);
	Color_Aui_CaptionBackground_Active = Float3::MakeColor(255, 242, 157);

	Color_Aui_Border = Float3::MakeColor(41, 57, 85);

	Color_Aui_BorderThin = Float3::MakeColor(142, 155, 188);
	Color_Aui_BorderThin_Center = Float3::MakeColor(41, 57, 85);

	Color_Aui_CaptionText = Float3::WHITE;
	Color_Aui_CaptionText_Active = Float3::BLACK;

	Color_Aui_MenuBar_Background = Float3::MakeColor(214, 219, 233);

	Color_Aui_ToolBar_Background = Float3::MakeColor(207, 214, 229);
	Color_Aui_Toolbar_PlainBackgound = Float3::MakeColor(255, 0, 0);
	Color_Aui_ToolBar_Border = Float3::MakeColor(220, 224, 236);
	Color_Aui_Toolbar_Separator = Float3::MakeColor(133, 145, 162);
	Color_Aui_Toolbar_Text = Float3::BLACK;
	Color_Aui_Toolbar_Flow = Float3::MakeColor(253, 244, 191);
	Color_Aui_Toolbar_FlowBorder = Float3::MakeColor(229, 195, 101);

	Color_Aui_Tabbar = Float3::MakeColor(54, 78, 111);
	Color_Aui_Tabbar_Active = Float3::MakeColor(255, 242, 157);
	Color_Aui_TabbarBot_Active = Float3::WHITE;
	Color_Aui_TabbarText = Float3::WHITE;
	Color_Aui_TabbarText_Active = Float3::BLACK;
}
//-----------------------------------------------------------------------------
Theme::~Theme()
{
}
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// EditParams
//-----------------------------------------------------------------------------
PX2_IMPLEMENT_RTTI(PX2, Object, EditParams);
PX2_IMPLEMENT_STREAM(EditParams);
PX2_IMPLEMENT_FACTORY(EditParams);
PX2_IMPLEMENT_DEFAULT_NAMES(Object, EditParams);
PX2_IMPLEMENT_DEFAULT_STREAM(Object, EditParams);
//-----------------------------------------------------------------------------
EditParams::EditParams()
{
	GridSize = 40.0f;

	mCurThemeStr = "Blue";
	mCurTheme = 0;
}
//-----------------------------------------------------------------------------
EditParams::~EditParams()
{
}
//-----------------------------------------------------------------------------
bool EditParams::Save(const std::string &filename)
{
	return true;
}
//-----------------------------------------------------------------------------
bool EditParams::Load(const std::string &filename)
{
	char *buffer = 0;
	int bufferSize = 0;
	if (PX2_RM.LoadBuffer(filename, bufferSize, buffer))
	{
		XMLData data;
		if (data.LoadBuffer(buffer, bufferSize))
		{
			XMLNode rootNode = data.GetRootNode();

			// params
			XMLNode paramsNode = rootNode.GetChild("params");
			GridSize = paramsNode.GetChild("gridsize").AttributeToFloat("val");

			// Theme
			XMLNode themesNode = rootNode.GetChild("themes");
			mCurThemeStr = themesNode.AttributeToString("curthemename");

			XMLNode themeChildNode = themesNode.IterateChild();
			while (!themeChildNode.IsNull())
			{
				Theme *theme = new0 Theme();

				theme->Name = themeChildNode.AttributeToString("name");

				XMLNode themeValNode = themeChildNode.IterateChild();
				while (!themeValNode.IsNull())
				{
					std::string themValName = themeValNode.GetName();

					if ("aui_backgournd" == themValName)
						theme->Color_Aui_Background = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_captionbackground" == themValName)
						theme->Color_Aui_CaptionBackground = StringToFloat3(themeValNode.AttributeToString("val"));
					else if ("aui_captionbackground_active" == themValName)
						theme->Color_Aui_CaptionBackground_Active = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_border" == themValName)
						theme->Color_Aui_Border = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_borderthin" == themValName)
						theme->Color_Aui_BorderThin = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_borderthin_center" == themValName)
						theme->Color_Aui_BorderThin_Center = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_menubar_background" == themValName)
						theme->Color_Aui_MenuBar_Background = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_toolbar_background" == themValName)
						theme->Color_Aui_ToolBar_Background = StringToFloat3(themeValNode.AttributeToString("val"));
					else if ("aui_toolbar_text" == themValName)
						theme->Color_Aui_Toolbar_Text = StringToFloat3(themeValNode.AttributeToString("val"));

					else if ("aui_tabbar" == themValName)
						theme->Color_Aui_Tabbar = StringToFloat3(themeValNode.AttributeToString("val"));
					else if ("aui_tabbar_active" == themValName)
						theme->Color_Aui_Tabbar_Active = StringToFloat3(themeValNode.AttributeToString("val"));
					else if ("aui_tabbartext" == themValName)
						theme->Color_Aui_TabbarText = StringToFloat3(themeValNode.AttributeToString("val"));
					else if ("aui_tabbartext_active" == themValName)
						theme->Color_Aui_TabbarText_Active = StringToFloat3(themeValNode.AttributeToString("val"));

					themeValNode = themeChildNode.IterateChild(themeValNode);
				}

				mThemesVec.push_back(theme->Name);
				mThemesMap[theme->Name] = theme;

				themeChildNode = rootNode.IterateChild(themeChildNode);
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
void EditParams::SetCurTheme(const std::string &typeStr)
{
	mCurThemeStr = typeStr;

	std::map<std::string, ThemePtr>::iterator it = mThemesMap.find(typeStr);
	if (it != mThemesMap.end())
	{
		mCurTheme = it->second;
	}
	else
	{
		mCurTheme = new0 Theme();
	}
}
//-----------------------------------------------------------------------------
const std::string &EditParams::GetCurThemeTypeStr() const
{
	return mCurThemeStr;
}
//-----------------------------------------------------------------------------
Theme *EditParams::GetCurTheme()
{
	return mCurTheme;
}
//-----------------------------------------------------------------------------
Float3 EditParams::StringToFloat3(const std::string &valStr)
{
	StringTokenizer stk(valStr, ",");
	Float3 color = Float3::MakeColor(
		StringHelp::StringToInt(stk[0]),
		StringHelp::StringToInt(stk[1]),
		StringHelp::StringToInt(stk[2]));

	return color;
}
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Property
//-----------------------------------------------------------------------------
void EditParams::RegistProperties()
{
	Object::RegistProperties();

	AddPropertyClass("EditParams");

	std::vector<std::string> themeTypes = mThemesVec;

	if (!themeTypes.empty())
	{
		AddPropertyEnum("ThemeType", 0, themeTypes);
	}
}
//-----------------------------------------------------------------------------
void EditParams::OnPropertyChanged(const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);
	if ("ThemeType" == obj.Name)
	{
	}
}
//-----------------------------------------------------------------------------