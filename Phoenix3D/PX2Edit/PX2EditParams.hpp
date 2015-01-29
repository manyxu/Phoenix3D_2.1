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

		//编辑器主题颜色类型
		enum ThemeType
		{
			THEME_BLUE,
			THEME_DARK,
			THEME_TINT
		};

		struct Theme
		{
			ThemeType type;
			Float3 inactiveColor;
			Float3 activeColor;
			Float3 backColor;
			Float3 tabBackColor;
		};
		void ThemeChange(ThemeType type);
		//ThemeType GetThemeType();
		void SetCurTheme(Theme theme);
		Theme GetCurTheme();
		std::map<int, Theme> GetThemes();
		
	public:
		float GridSize;
	protected:
		ThemeType mThemeType;
		Theme mCurTheme;
		std::map<int, Theme> mThemes;	
	};

	PX2_REGISTER_STREAM(EditParams);
	typedef Pointer0<EditParams> EditParamsPtr;
}

#endif