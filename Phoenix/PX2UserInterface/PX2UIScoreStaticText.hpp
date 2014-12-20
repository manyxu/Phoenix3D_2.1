/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIScoreStaticText.hpp
*
*/

#ifndef PX2UISCORESTATICTEXT_HPP
#define PX2UISCORESTATICTEXT_HPP

#include "PX2UIPre.hpp"
#include "PX2UIStaticText.hpp"
#include "PX2UIScoreStaticTextCtrl.hpp"

namespace PX2
{

	class UIScoreStaticText : public UIStaticText
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIScoreStaticText);

	public:
		UIScoreStaticText ();
		virtual ~UIScoreStaticText ();

		void SetNumAnimInit (int num);
		void SetNumAnim (int num);

		void SetNum (int num);
		int GetNum () const;

		UIScoreStaticTextCtrl *GetScoreStaticTextCtrl ();

	protected:
		int mNum;
		UIScoreStaticTextCtrlPtr mSSTCtrl;
	};

	PX2_REGISTER_STREAM(UIScoreStaticText);
	typedef Pointer0<UIScoreStaticText> UIScoreStaticTextPtr;
#include "PX2UIScoreStaticText.inl"

}

#endif