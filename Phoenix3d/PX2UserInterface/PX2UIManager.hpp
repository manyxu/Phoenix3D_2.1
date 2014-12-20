/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIManager.hpp
*
*/

#ifndef PX2UIMANAGER_HPP
#define PX2UIMANAGER_HPP

#include "PX2UIPre.hpp"
#include "PX2UIMaterial.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2UIView.hpp"
#include "PX2Singleton.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Node.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIStaticText.hpp"
#include "PX2UIScoreStaticText.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIRangeFrame.hpp"
#include "PX2UIButton.hpp"
#include "PX2UICheckButton.hpp"
#include "PX2UIProgressBar.hpp"
#include "PX2UIEditBox.hpp"
#include "PX2FontManager.hpp"
#include "PX2IMEDispatcher.hpp"

namespace PX2
{

	class UIManager : public Singleton<UIManager>, public EventHandler
	{
	public:
		UIManager ();
		~UIManager ();

		void Clear ();

		VertexFormat *GetVertexFormat ();
		VertexFormat *GetVertexFormatUV3 ();
		VertexFormat *GetVertexFormatUser ();
		UIMaterial *GetUIMaterial ();
		UIMaterial *GetUIMaterialDoubleSide ();
		Texture2DMaterial *GetMaterialUser ();
		UIView *GetDefaultView ();

		void AddUIView (const std::string &name, UIView *view);
		void RemoveUIView (const std::string &name);
		std::map<std::string, UIViewPtr> &GetUIViews ();
		UIView *GetUIView (std::string name);

		UIPicBox *CreateUIPicBox (const APoint &localPos, const std::string &texFilename="");
		UIPicBox *CreateUIPicBox (const APoint &localPos, const std::string &texPack, 
			const std::string &eleName);
		UIStaticText *CreateUIStaticText (const APoint &localPos);
		UIScoreStaticText *CreateUIScoreStaticText (const APoint &localPos);
		UIFrame *CreateUIFrame (const APoint &localPos);
		UIRangeFrame *CreateUIRangeFrame (const APoint &localPos);
		UIButton *CreateUIButton (const APoint &localPos);
		UIProgressBar *CreateProgressBar (const APoint &localPos);
		UIEditBox *CreateUIEditBox (const APoint &localPos);
		UICheckButton *CreateUICheckButton (const APoint &localPos);

		virtual void DoExecute (Event *event);

	protected:
		VertexFormatPtr mVertexFormat;
		VertexFormatPtr mVertexFormatUV3;
		UIMaterialPtr mUIMaterial;
		UIMaterialPtr mUIMaterialDoubleSide;
		UIViewPtr mDefaultView;
		std::map<std::string, UIViewPtr> mUIViews;
	};

#include "PX2UIManager.inl"

#define PX2_UIM UIManager::GetSingleton()

}

#endif