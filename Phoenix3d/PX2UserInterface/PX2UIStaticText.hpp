/*
*
* 文件名称	：	PX2UIStaticText.hpp
*
*/

#ifndef PX2UISTATICTEXT_HPP
#define PX2UISTATICTEXT_HPP

#include "PX2UIPre.hpp"
#include "PX2Font.hpp"
#include "PX2UIMaterial.hpp"

namespace PX2
{

	class UIStaticText : public TriMesh
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIStaticText);

	public:
		UIStaticText ();
		virtual ~UIStaticText ();

		enum FontType
		{
			FT_FREETYPE,
			FT_BITMAP,
			FT_MAXTYPE
		};
		FontType GetFontType () const;

		void SetFont (const std::string &fontFilename, int fontWidth,
			int fontHeight,	unsigned int fontStyle=FES_NORMAL);
		void SetFontBimMap (const std::string &fontFilename);
		Font *GetFont ();

		virtual void SetText (const std::string &text);
		const std::string &GetText () const;

		void SetKey (const std::string &key);
		const std::string &GetKey () const;

		// FES_NORMAL
		// FES_ITALIC
		// FES_UNDERLINE
		void SetFontStyle (int style);
		int GetFontStyle () const;
		bool IsItalic () const;
		bool IsUnderLine () const;

		// FD_NORMAL 0
		// FD_SHADOW 1
		// FD_BORDER 2
		void SetDrawStyle (int style);
		int GetDrawStyle () const;

		void SetBorderShadowColor (const Float3 &color);
		const Float3 &GetBorderShadowColor () const;
		void SetShadowBorderSize (float size);
		float GetShadowBorderSize () const;

		enum RectUseage
		{
			RU_NONE,
			RU_ALIGNS,
			RU_CLIP
		};
		void SetRectUseage (RectUseage useage);
		RectUseage GetRectUseage () const;

		void SetRect (const Rectf &rect);
		const Rectf &GetRect () const;
		void SetOffset (const Float2 &offset);
		const Float2 &GetOffset () const;
		void SetSpace (const Float2 &space); // 列间距,和行间距
		const Float2 &GetSpace () const;

		// TEXTALIGN_LEFT
		// TEXTALIGN_HCENTER
		// TEXTALIGN_RIGHT
		// TEXTALIGN_TOP
		// TEXTALIGN_VCENTER
		// TEXTALIGN_BOTTOM
		void SetAligns (int aligns);
		int GetAligns () const;
		int GetHAlign () const;
		int GetVAlign () const;

		// 使用自动换行(保持单词完整)
		void SetAutoWarp (bool warp);
		bool IsAutoWarp () const;

		void SetDoCharTranslate (bool doTranslate);
		bool IsDoCharTranslate () const;

		void SetFontScale (float scale);
		float GetFontScale () const;

		virtual void SetColor (const Float3 &color);
		virtual void SetAlpha (float alpha);

		void SetFontWidthHeight (int width, int height);
		void SetFontWidth (int width);
		int GetFontWidth ();
		void SetFontHeight (int height);
		int GetFontHeight ();

		void SetDoubleSide (bool d);
		bool IsDoubleSide ();

	protected:
		virtual void UpdateWorldData (double applicationTime);

		void ReCreateFont ();
		void ReCreate ();

		std::string mText;
		std::string mKey;
		RectUseage mRectUseage;
		int mTextAligns;
		int mFontStyle;
		int mDrawStyle;	
		Float3 mBorderShadowColor;
		float mShadowBorderSize;
		std::string mFontFilename;
		int mFontWidth;
		int mFontHeight;
		Rectf mRect;
		Float2 mOffset;
		Float2 mSpace;
		bool mIsAutoWarp;
		bool mIsDoCharTranslate;
		bool mIsDoubleSide;
		float mFontScale;
		UIMaterialPtr mMtl;
		MaterialInstancePtr mMtlInst;
		Texture2DPtr mFontTex;

		FontType mFontType;
		
		FontPtr mFont;
		bool mIsNeedReCreate;
		bool mIsNeedReCreateFont;
	};

	PX2_REGISTER_STREAM(UIStaticText);
	typedef Pointer0<UIStaticText> UIStaticTextPtr;
#include "PX2UIStaticText.inl"

}

#endif