/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FontManager.hpp
*
*/

#ifndef PX2FONTMANAGER_HPP
#define PX2FONTMANAGER_HPP

#include "PX2UnityPre.hpp"
#include "PX2FontDefine.hpp"
#include "PX2Font.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class FontManager : public Singleton<FontManager>
	{
	public:
		FontManager ();
		virtual ~FontManager();

		bool Initlize ();
		bool Terminate ();

		void DumpTex ();

		void Update ();
		void SetNeedUpdate();

		Font *GetDefaultFont ();

		Font *CreateTypeFont (int fontWidth, int fontHeight,
			const char *fontFilename, CharCodingType codingType,
			unsigned int fontExtStyle=FES_NORMAL);

		Font *CreateBitmapFont (int fontWidth, int fontHeight, const char *fontFilename,
			CharCodingType codingType);

		virtual void RenderText (TriMesh *mesh, Font *font, const char *text,
			unsigned int style, float x, float y, const Float2 &space, const Float4 &color,
			const Float3 &borderShadowColor, float shadowBorderSize, float scale=1.0f,
			bool doTransfer=false, float depth=0.0f);

		virtual void RenderText (TriMesh *mesh, Font *font, const char *text, 
			unsigned int style,	unsigned int align, Rectf &rect, const Float2 &space, 
			const Float4 &color, const Float3 &borderShadowColor, 
			float shadowBorderSize, float scale=1.0f,  bool doTransfer=false);

		virtual void RenderText (TriMesh *mesh, Font *font, const char *text, 
			unsigned int style,	Rectf &rect,  const Float2 &space, float offsetX, float offsetY, 
			bool autoWrap, const Float4 &color, const Float3 &borderShadowColor, 
			float shadowBorderSize, float scale=1.0f, bool doTransfer=false);

	protected:
		FontPtr mDefaultFont;
		std::vector<FontPtr> mFonts;
	};

#include "PX2FontManager.inl"

#define PX2_FM FontManager::GetSingleton()

}

#endif