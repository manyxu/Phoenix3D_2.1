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

		void SaveCurTheme();

		//编辑器主题颜色类型
		std::vector<std::string> mThemeTypes;
		struct Theme
		{
			std::string type;
			Float3 inactiveColor;
			Float3 activeColor;
			Float3 backColor;
			Float3 tabBackColor;
			Float3 fontColor;
			Float3 captionColor;
			Float3 captionActColor;
			Float3 tabFontColor;
			Float3 tabFontActColor;
			Float3 toolBarColor;
			Float3 toolBarHightlightColor;
			Float3 searchColor;
		};
		void ThemeChange(std::string type);
		//ThemeType GetThemeType();
		void SetCurTheme(Theme theme);
		Theme GetCurTheme();
		std::map<int, Theme> GetThemes();
		
	public:
		float GridSize;
	protected:
		Theme mCurTheme;
		std::map<int, Theme> mThemes;	
	};

	PX2_REGISTER_STREAM(EditParams);
	typedef Pointer0<EditParams> EditParamsPtr;
}

#endif