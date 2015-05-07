// PX2EditParams.hpp

#ifndef PX2EDITORPARAMS_HPP
#define PX2EDITORPARAMS_HPP

#include "PX2EditPre.hpp"
#include "PX2Singleton.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Object.hpp"
#include "PX2Float3.hpp"

namespace PX2
{
	class Theme
	{
	public:
		Theme();
		~Theme();

		std::string Name;

		Float3 Color_Aui_Background;

		Float3 Color_Aui_CaptionBackground;
		Float3 Color_Aui_CaptionBackground_Active;
		Float3 Color_Aui_CaptionText;
		Float3 Color_Aui_CaptionText_Active;

		Float3 Color_Aui_Border;
		Float3 Color_Aui_BorderThin;
		Float3 Color_Aui_BorderThin_Center;

		Float3 Color_Aui_MenuBar_Background;

		Float3 Color_Aui_ToolBar_Background;
		Float3 Color_Aui_ToolBar_Border;

		Float3 Color_Aui_Toolbar_Separator;
		Float3 Color_Aui_Toolbar_Text;
		Float3 Color_Aui_Toolbar_Flow;
		Float3 Color_Aui_Toolbar_FlowBorder;

		Float3 Color_Aui_Tabbar;
		Float3 Color_Aui_Tabbar_Active;
		Float3 Color_Aui_TabbarBot_Active;
		Float3 Color_Aui_TabbarText;
		Float3 Color_Aui_TabbarText_Active;

		Float3 Color_Page_Background;
		Float3 Color_Page_Foreground;
	};
	typedef Pointer0<Theme> ThemePtr;

	class EditParams : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(EditParams);

	public:
		EditParams();
		~EditParams();

		bool Save(const std::string &filename);
		bool Load(const std::string &filename);

	protected:
		std::string mConfigFileName;

		// params
	public:
		float GridSize;
		bool IsShowGrid;

		// Theme
	public:
		void SetCurTheme(const std::string &typeStr);
		const std::string &GetCurThemeTypeStr() const;
		Theme *GetCurTheme();

	protected:
		Float3 StringToColorFloat3(const std::string &valStr);
		std::string ColorFloat3ToString(const Float3 &val);

		std::string mCurThemeStr;
		ThemePtr mCurTheme;
		std::map<std::string, ThemePtr> mThemesMap;
		std::vector<std::string> mThemesVec;
		int mCurThemeIndex;
	};

	PX2_REGISTER_STREAM(EditParams);
	typedef Pointer0<EditParams> EditParamsPtr;
}

#endif