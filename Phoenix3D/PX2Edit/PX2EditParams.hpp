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

		Float3 Color_AuiMenuBar_Background;

		Float3 Color_AuiToolBar_Background;
		Float3 Color_AuiToolbar_PlainBackgound;
		Float3 Color_AuiToolBar_Border;

		Float3 Color_AuiToolbar_Separator;
		Float3 Color_AuiToolbar_Text;
		Float3 Color_AuiToolbar_Flow;
		Float3 Color_AuiToolbar_FlowBorder;

		Float3 Color_AuiTabbar;
		Float3 Color_AuiTabbar_Active;
		Float3 Color_AuiTabbarBot_Active;
		Float3 Color_AuiTabbarText;
		Float3 Color_AuiTabbarText_Active;
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

		bool Save(std::string filename);
		bool Load(std::string filename);

		// params
	public:
		float GridSize;

		// Theme
	public:
		void SetCurTheme(const std::string &typeStr);
		const std::string &GetCurThemeTypeStr() const;
		Theme *GetCurTheme();

	protected:
		std::string mCurThemeStr;
		ThemePtr mCurTheme;
		std::map<std::string, ThemePtr> mThemesMap;
		std::vector<std::string> mThemesVec;
	};

	PX2_REGISTER_STREAM(EditParams);
	typedef Pointer0<EditParams> EditParamsPtr;
}

#endif