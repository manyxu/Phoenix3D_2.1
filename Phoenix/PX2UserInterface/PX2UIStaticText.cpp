/*
*
* 文件名称	：	PX2StaticText.cpp
*
*/

#include "PX2UIStaticText.hpp"
#include "PX2UIManager.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2FontManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, TriMesh, UIStaticText, 6);
PX2_IMPLEMENT_STREAM(UIStaticText);
PX2_IMPLEMENT_FACTORY(UIStaticText);
PX2_IMPLEMENT_DEFAULT_NAMES(TriMesh, UIStaticText);

//----------------------------------------------------------------------------
UIStaticText::UIStaticText ()
	:
mFontType(FT_FREETYPE)
{
	SetName("UIStaticText");

	SetRenderLayer(Renderable::RL_UI);

	mTextAligns = TEXTALIGN_LEFT|TEXTALIGN_VCENTER;
	mRectUseage = RU_NONE;
	mFontStyle = FES_NORMAL;
	mDrawStyle = FD_NORMAL;
	mBorderShadowColor = Float3::BLACK;
	mShadowBorderSize = 1.0f;
	mIsDoubleSide = false;
	mOffset = Float2::ZERO;
	mSpace = Float2::ZERO;
	mIsAutoWarp = false;
	mIsDoCharTranslate = true;
	mFontScale = 1.0f;

	SetVertexFormat(UIManager::GetSingleton().GetVertexFormat());

	mMtl = new0 UIMaterial();
	mMtl->GetPixelShader()->SetCoordinate(0, 0, Shader::SC_CLAMP);
	mMtl->GetPixelShader()->SetCoordinate(0, 1, Shader::SC_CLAMP);

	mFontFilename = "Data/fonts/heiti.ttf";
	mFontStyle = 0;
	mFontWidth = 24;
	mFontHeight = 24;

	mText = "DefaultText";
	SetColor(Float3::BLACK);

	mIsNeedReCreateFont = true;
	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
UIStaticText::~UIStaticText ()
{
}
//----------------------------------------------------------------------------
void UIStaticText::SetFont (const std::string &fontFilename, int fontWidth,
	int fontHeight,	unsigned int fontStyle)
{
	mFontType = FT_FREETYPE;
	mFontFilename = fontFilename;
	mFontWidth = fontWidth;
	mFontHeight = fontHeight;
	mFontStyle = fontStyle;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetFontBimMap (const std::string &fontFilename)
{
	mFontType = FT_BITMAP;
	mFontFilename = fontFilename;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetText (const std::string &text)
{
	if (mText == text)
		return;

	mText = text;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetKey (const std::string &key)
{
	mKey = key;

	if (PX2_LM.HasValue(key))
	{
		const std::string &tex = PX2_LM.GetValue(key);
		SetText(tex);
	}
}
//----------------------------------------------------------------------------
void UIStaticText::SetFontStyle (int style)
{
	if (mFontStyle == style)
		return;

	mFontStyle = style;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetDrawStyle (int style)
{
	if (style == mDrawStyle)
		return;

	mDrawStyle = style;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetAligns (int aligns)
{
	if (mTextAligns == aligns)
		return;

	mTextAligns = aligns;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
int UIStaticText::GetHAlign () const
{
	if (mTextAligns & TEXTALIGN_LEFT)
		return TEXTALIGN_LEFT;
	else if (mTextAligns & TEXTALIGN_HCENTER)
		return TEXTALIGN_HCENTER;
	else if (mTextAligns & TEXTALIGN_RIGHT)
		return TEXTALIGN_RIGHT;

	return 0;
}
//----------------------------------------------------------------------------
int UIStaticText::GetVAlign () const
{
	if (mTextAligns & TEXTALIGN_TOP)
		return TEXTALIGN_TOP;
	else if (mTextAligns & TEXTALIGN_VCENTER)
		return TEXTALIGN_VCENTER;
	else if (mTextAligns & TEXTALIGN_BOTTOM)
		return TEXTALIGN_BOTTOM;

	return 0;
}
//----------------------------------------------------------------------------
void UIStaticText::SetBorderShadowColor (const Float3 &color)
{
	if (mBorderShadowColor == color)
		return;

	mBorderShadowColor = color;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetShadowBorderSize (float size)
{
	if (mShadowBorderSize == size)
		return;

	mShadowBorderSize = size;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetRectUseage (RectUseage useage)
{
	if (mRectUseage == useage)
		return;

	mRectUseage = useage;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetRect (const Rectf &rect)
{
	if (mRect == rect)
		return;

	mRect = rect;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetOffset (const Float2 &offset)
{
	mOffset = offset;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetSpace (const Float2 &space)
{
	mSpace = space;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetAutoWarp (bool warp)
{
	if (mIsAutoWarp == warp)
		return;

	mIsAutoWarp = warp;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetDoCharTranslate (bool doTranslate)
{
	if (mIsDoCharTranslate == doTranslate)
		return;

	mIsDoCharTranslate = doTranslate;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetFontScale (float scale)
{
	if (mFontScale == scale)
		return;

	mFontScale = scale;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetColor (const Float3 &color)
{
	if (GetColor() == color)
		return;

	TriMesh::SetColor(color);

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetAlpha (float alpha)
{
	if (GetAlpha() == alpha)
		return;

	TriMesh::SetAlpha(alpha);

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetFontWidthHeight (int width, int height)
{
	if ((width==mFontWidth && height==mFontHeight) || width<=0 || width>512 ||
		height<=0 || height>=512)
		return;

	mFontWidth = width;
	mFontHeight = height;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetFontWidth (int width)
{
	if (width == mFontWidth || width<=0 || width>512)
		return;

	mFontWidth = width;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetFontHeight (int height)
{
	if (height == mFontHeight || height<=0 || height>512)
		return;

	mFontHeight = height;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIStaticText::SetDoubleSide (bool d)
{
	if (mIsDoubleSide == d)
		return;

	mIsDoubleSide = d;

	if (d)
	{
		mMtl = UIManager::GetSingleton().GetUIMaterialDoubleSide();
	}
	else
	{
		mMtl = UIManager::GetSingleton().GetUIMaterial();
	}

	Texture2D *tex = mFont->GetTexture();

	mMtlInst = mMtl->CreateInstance(tex);
	SetMaterialInstance(mMtlInst);
}
//----------------------------------------------------------------------------
void UIStaticText::UpdateWorldData (double applicationTime)
{
	TriMesh::UpdateWorldData(applicationTime);

	if (mIsNeedReCreateFont)
	{
		ReCreateFont();
	}

	if (mIsNeedReCreate)
	{
		ReCreate();
	}

	if (mMtl)
	{
		mMtl->GetPixelShader()->SetCoordinate(0, 0, Shader::SC_CLAMP);
		mMtl->GetPixelShader()->SetCoordinate(0, 1, Shader::SC_CLAMP);
	}

	mFontTex = mFont->GetTexture();
}
//----------------------------------------------------------------------------
void UIStaticText::ReCreateFont ()
{
	if (FT_FREETYPE == mFontType)
	{
		mFont = PX2_FM.CreateTypeFont(mFontWidth, mFontHeight,
			mFontFilename.c_str(), CCT_UTF8, mFontStyle);
	}
	else if (FT_BITMAP == mFontType)
	{
		mFont = PX2_FM.CreateBitmapFont(mFontWidth, mFontHeight, 
			mFontFilename.c_str(), CCT_UTF8);
	}

	ReCreate();

	mIsNeedReCreateFont = false;
}
//----------------------------------------------------------------------------
void UIStaticText::ReCreate ()
{
	if (RU_NONE == mRectUseage)
	{
		PX2_FM.RenderText(this, mFont,
			mText.c_str(), mDrawStyle, mOffset[0], mOffset[1], mSpace, Float4(mColor[0], 
			mColor[1], mColor[2], mAlpha), mBorderShadowColor, mShadowBorderSize, 
			mFontScale, mIsDoCharTranslate, 0.0f);
	}
	else if (RU_CLIP == mRectUseage)
	{
		PX2_FM.RenderText(this, mFont, mText.c_str(),
			mDrawStyle, mRect, mSpace, mOffset[0], mOffset[1],
			mIsAutoWarp, Float4(mColor[0], mColor[1], mColor[2], mAlpha),
			mBorderShadowColor, mShadowBorderSize, mFontScale,
			mIsDoCharTranslate);
	}
	else if (RU_ALIGNS == mRectUseage)
	{
		PX2_FM.RenderText(this, mFont, mText.c_str(),
			mDrawStyle, mTextAligns, mRect, mSpace,
			Float4(mColor[0], mColor[1], mColor[2], mAlpha),
			mBorderShadowColor, mShadowBorderSize, mFontScale,
			mIsDoCharTranslate);
	}

	mFontTex = mFont->GetTexture();

	if (mMtlInst)
	{
		mMtlInst->SetPixelTexture(0, "gDiffuseSampler", mFontTex);
	}
	else
	{
		mMtlInst = mMtl->CreateInstance(mFontTex);
		SetMaterialInstance(mMtlInst);
	}

	if (Renderer::IsOneBind(GetVertexBuffer()) || Renderer::IsOneBind(GetIndexBuffer()))
	{
		Renderer::UpdateAll(GetVertexBuffer());
		Renderer::UpdateAll(GetIndexBuffer());
	}

	mIsNeedReCreate = false;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void UIStaticText::RegistProperties ()
{
	TriMesh::RegistProperties();

	AddPropertyClass("UIStaticText");

	std::vector<std::string> fontTypes;
	fontTypes.push_back("FT_FREETYPE");
	fontTypes.push_back("FT_BITMAP");
	AddPropertyEnum("FontType", GetFontType(), fontTypes, false);

	int fontWidth = 0;
	int fontHeight = 0;
	GetFont()->GetFontSize(fontWidth, fontHeight);

	AddProperty("FontResPath", PT_STRINGBUTTON, GetFont()->GetFontFilename());
	AddProperty("FontBitmap", PT_STRINGBUTTON, GetFont()->GetFontFilename());
	AddProperty("FontWidth", PT_INT, fontWidth);
	AddProperty("FontHeight", PT_INT, fontHeight);
	AddProperty("FontScale", PT_FLOAT, GetFontScale());
	AddProperty("Text", PT_STRING, GetText());
	AddProperty("Key", PT_STRING, GetKey());

	AddProperty("IsItalic", PT_BOOL, IsItalic());
	AddProperty("IsUnderLine", PT_BOOL, IsUnderLine());
	AddProperty("IsDoubleSide", PT_BOOL, IsDoubleSide());

	std::vector<std::string> drawStyles;
	drawStyles.push_back("FD_NORMAL");
	drawStyles.push_back("FD_SHADOW");
	drawStyles.push_back("FD_BORDER");
	AddPropertyEnum("DrawStyle", GetDrawStyle(), drawStyles);
	AddProperty("BorderShadowColor", PT_COLOR3FLOAT3, GetBorderShadowColor());
	AddProperty("BorderShadowSize", PT_FLOAT, GetShadowBorderSize());

	std::vector<std::string> rectUseages;
	rectUseages.push_back("RU_NONE");
	rectUseages.push_back("RU_ALIGNS");
	rectUseages.push_back("RU_CLIP");
	AddPropertyEnum("RectUseage", (int)GetRectUseage(), rectUseages);
	AddProperty("Rect", PT_RECT, GetRect());
	AddProperty("Offset", PT_FLOAT2, GetOffset());
	AddProperty("Space", PT_FLOAT2, GetSpace());

	int hAlign = GetHAlign();
	int vAlign = GetVAlign();
	int hAlignLast = 0;
	int vAlignLast = 0;

	if (hAlign & TEXTALIGN_LEFT)
	{
		hAlignLast = 0;
	}
	else if (hAlign & TEXTALIGN_HCENTER)
	{
		hAlignLast = 1;
	}
	else if (hAlign & TEXTALIGN_RIGHT)
	{
		hAlignLast = 2;
	}

	if (vAlign & TEXTALIGN_TOP)
	{
		vAlignLast = 0;
	}
	else if (vAlign & TEXTALIGN_VCENTER)
	{
		vAlignLast = 1;
	}
	else if (vAlign & TEXTALIGN_BOTTOM)
	{
		vAlignLast = 2;
	}

	std::vector<std::string> hAligns;
	hAligns.push_back("TEXTALIGN_LEFT");
	hAligns.push_back("TEXTALIGN_HCENTER");
	hAligns.push_back("TEXTALIGN_RIGHT");
	AddPropertyEnum("HAlign", hAlignLast, hAligns);

	std::vector<std::string> vAligns;
	vAligns.push_back("TEXTALIGN_TOP");
	vAligns.push_back("TEXTALIGN_VCENTER");
	vAligns.push_back("TEXTALIGN_BOTTOM");
	AddPropertyEnum("VAlign", vAlignLast, vAligns);

	AddProperty("AutoWarp", PT_BOOL, IsAutoWarp());
	AddProperty("DoCharTranslate", PT_BOOL, IsDoCharTranslate());
}
//----------------------------------------------------------------------------
void UIStaticText::OnPropertyChanged (const PropertyObject &obj)
{
	TriMesh::OnPropertyChanged(obj);

	if ("FontResPath" == obj.Name)
	{
		SetFont(PX2_ANY_AS(obj.Data, std::string), mFontWidth, mFontHeight,
			GetFontStyle());
	}
	else if ("FontBitmap" == obj.Name)
	{
		SetFontBimMap(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("FontWidth" == obj.Name)
	{
		SetFontWidth(PX2_ANY_AS(obj.Data, int));
	}
	else if ("FontHeight" == obj.Name)
	{
		SetFontHeight(PX2_ANY_AS(obj.Data, int));
	}
	else if ("FontScale" == obj.Name)
	{
		SetFontScale(PX2_ANY_AS(obj.Data, float));
	}
	else if ("Text" == obj.Name)
	{
		SetText(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("Key" == obj.Name)
	{
		SetKey(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("IsItalic" == obj.Name)
	{
		int fontStyle = FES_NORMAL;

		bool isIta = PX2_ANY_AS(obj.Data, bool);

		if (isIta)
		{
			fontStyle |= FES_ITALIC;
		}

		if (IsUnderLine())
		{
			fontStyle |= FES_UNDERLINE;
		}

		SetFontStyle(fontStyle);
	}
	else if ("IsUnderLine" == obj.Name)
	{
		int fontStyle = FES_NORMAL;

		bool isUnderLine = PX2_ANY_AS(obj.Data, bool);

		if (IsItalic())
		{
			fontStyle |= FES_ITALIC;
		}

		if (isUnderLine)
		{
			fontStyle |= FES_UNDERLINE;
		}

		SetFontStyle(fontStyle);
	}
	else if ("DrawStyle" == obj.Name)
	{
		SetDrawStyle(PX2_ANY_AS(obj.Data, int));
	}
	else if ("BorderShadowColor" == obj.Name)
	{
		SetBorderShadowColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("BorderShadowSize" == obj.Name)
	{
		SetShadowBorderSize(PX2_ANY_AS(obj.Data, float));
	}
	else if ("RectUseage" == obj.Name)
	{
		SetRectUseage((RectUseage)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Rect" == obj.Name)
	{
		SetRect(PX2_ANY_AS(obj.Data, Rectf));
	}
	else if ("Offset" == obj.Name)
	{
		SetOffset(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("Space" == obj.Name)
	{
		SetSpace(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("HAlign" == obj.Name)
	{
		int aligns = 0;

		int val = PX2_ANY_AS(obj.Data, int);

		if (0 == val)
			aligns |= TEXTALIGN_LEFT;
		else if (1 == val)
			aligns |= TEXTALIGN_HCENTER;
		else if (2 == val)
			aligns |= TEXTALIGN_RIGHT;

		aligns |= GetVAlign();

		SetAligns(aligns);
	}
	else if ("VAlign" == obj.Name)
	{
		int aligns = 0;
		aligns |= GetHAlign();

		int val = PX2_ANY_AS(obj.Data, int);

		if (0 == val)
			aligns |= TEXTALIGN_TOP;
		else if (1 == val)
			aligns |= TEXTALIGN_VCENTER;
		else if (2 == val)
			aligns |= TEXTALIGN_BOTTOM;

		SetAligns(aligns);
	}
	else if ("AutoWarp" == obj.Name)
	{
		SetAutoWarp(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("DoCharTranslate" == obj.Name)
	{
		SetDoCharTranslate(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIStaticText::UIStaticText (LoadConstructor value)
	:
TriMesh(value),
mFontType(FT_FREETYPE)
{

	mTextAligns = TEXTALIGN_LEFT|TEXTALIGN_VCENTER;
	mRectUseage = RU_NONE;
	mFontStyle = FES_NORMAL;
	mDrawStyle = FD_NORMAL;
	mBorderShadowColor = Float3::BLACK;
	mShadowBorderSize = 1.0f;
	mIsDoubleSide = false;
	mOffset = Float2::ZERO;
	mSpace = Float2::ZERO;
	mIsAutoWarp = false;
	mIsDoCharTranslate = true;
	mFontScale = 1.0f;

	mFontStyle = 0;
	mFontWidth = 32;
	mFontHeight = 32;

	mIsNeedReCreateFont = true;
	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIStaticText::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	int readedVersion = GetReadedVersion();

	source.ReadString(mText);
	if (1 <= readedVersion)
	{
		source.ReadString(mKey);
	}

	if (3 <= readedVersion)
	{
		source.ReadEnum(mRectUseage);
		source.Read(mTextAligns);
	}

	source.Read(mFontStyle);
	source.Read(mDrawStyle);

	if (2 <= readedVersion)
	{
		source.ReadAggregate(mBorderShadowColor);
		source.Read(mShadowBorderSize);
	}

	if (readedVersion <= 1)
	{
		Float3 color;
		float alpha;
		source.ReadAggregate(color);
		source.Read(alpha);
	}

	source.ReadString(mFontFilename);
	source.Read(mFontWidth);
	source.Read(mFontHeight);
	if (2 <= readedVersion)
	{
		source.ReadAggregate(mRect);
		source.ReadAggregate(mOffset);
		source.ReadBool(mIsAutoWarp);
		source.ReadBool(mIsDoCharTranslate);
		source.Read(mFontScale);
	}
	source.ReadBool(mIsDoubleSide);
	source.ReadPointer(mMtl);
	source.ReadPointer(mMtlInst);

	if (readedVersion <= 3)
	{
		source.ReadPointer(mFontTex);
	}

	if (5 <= readedVersion)
	{
		source.ReadEnum(mFontType);
	}

	if (6 <= readedVersion)
	{
		source.ReadAggregate(mSpace);
	}

	PX2_END_DEBUG_STREAM_LOAD(UIStaticText, source);
}
//----------------------------------------------------------------------------
void UIStaticText::Link (InStream& source)
{
	TriMesh::Link(source);

	source.ResolveLink(mMtl);
	source.ResolveLink(mMtlInst);

	int readedVersion = GetReadedVersion();
	if (readedVersion <= 3)
	{
		source.ResolveLink(mFontTex);
	}
}
//----------------------------------------------------------------------------
void UIStaticText::PostLink ()
{
	TriMesh::PostLink();

	//if (FT_FREETYPE == mFontType)
	//{
	//	mFont = PX2_FM.CreateTypeFont(mFontWidth, mFontHeight, 
	//		mFontFilename.c_str(), CCT_UTF8, mFontStyle);
	//}
	//else
	//{
	//	mFont = PX2_FM.CreateBitmapFont(mFontWidth, mFontHeight,
	//		mFontFilename.c_str(), CCT_UTF8);
	//}

	if (mMtl)
	{
		mMtl->GetPixelShader()->SetCoordinate(0, 0, Shader::SC_CLAMP);
		mMtl->GetPixelShader()->SetCoordinate(0, 1, Shader::SC_CLAMP);
	}
}
//----------------------------------------------------------------------------
bool UIStaticText::Register (OutStream& target) const
{
	if (TriMesh::Register(target))
	{
		target.Register(mMtl);
		target.Register(mMtlInst);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIStaticText::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriMesh::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteString(mText);
	target.WriteString(mKey);
	target.WriteEnum(mRectUseage);
	target.Write(mTextAligns);
	target.Write(mFontStyle);
	target.Write(mDrawStyle);
	target.WriteAggregate(mBorderShadowColor);
	target.Write(mShadowBorderSize);
	target.WriteString(mFontFilename);
	target.Write(mFontWidth);
	target.Write(mFontHeight);
	target.WriteAggregate(mRect);
	target.WriteAggregate(mOffset);
	target.WriteBool(mIsAutoWarp);
	target.WriteBool(mIsDoCharTranslate);
	target.Write(mFontScale);
	target.WriteBool(mIsDoubleSide);
	target.WritePointer(mMtl);
	target.WritePointer(mMtlInst);
	target.WriteEnum(mFontType);
	target.WriteAggregate(mSpace);

	PX2_END_DEBUG_STREAM_SAVE(UIStaticText, target);
}
//----------------------------------------------------------------------------
int UIStaticText::GetStreamingSize (Stream &stream) const
{
	int size = TriMesh::GetStreamingSize(stream);

	int readedVersion = GetReadedVersion();

	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_STRINGSIZE(mText);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		if (1 <= readedVersion)
		{
			size += PX2_STRINGSIZE(mKey);
		}
	}
	else
	{
		size += PX2_STRINGSIZE(mKey);
	}

	if (Stream::ST_IN == stream.GetStreamType())
	{
		if (3 <= readedVersion)
		{
			size += PX2_ENUMSIZE(mRectUseage);
			size += sizeof(mTextAligns);
		}
	}
	else
	{
		size += PX2_ENUMSIZE(mRectUseage);
		size += sizeof(mTextAligns);
	}

	size += sizeof(mFontStyle);
	size += sizeof(mDrawStyle);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		if (readedVersion >= 2)
		{
			size += sizeof(mBorderShadowColor);
			size += sizeof(mShadowBorderSize);
		}
		
		if (readedVersion <= 1)
		{
			Float3 color = Float3::ZERO;
			float alpha = 0.0f;
			size += sizeof(color);
			size += sizeof(alpha);
			PX2_UNUSED(alpha);
			PX2_UNUSED(color);
		}
	}
	else
	{
		size += sizeof(mBorderShadowColor);
		size += sizeof(mShadowBorderSize);
	}

	size += PX2_STRINGSIZE(mFontFilename);
	size += sizeof(mFontWidth);
	size += sizeof(mFontHeight);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		if (2 <= readedVersion)
		{
			size += sizeof(mRect);
			size += sizeof(mOffset);
			size += PX2_BOOLSIZE(mIsAutoWarp);
			size += PX2_BOOLSIZE(mIsDoCharTranslate);
			size += sizeof(mFontScale);
		}
	}
	else
	{
		size += sizeof(mRect);
		size += sizeof(mOffset);
		size += PX2_BOOLSIZE(mIsAutoWarp);
		size += PX2_BOOLSIZE(mIsDoCharTranslate);
		size += sizeof(mFontScale);
	}

	size += PX2_BOOLSIZE(mIsDoubleSide);
	size += PX2_POINTERSIZE(mMtl);
	size += PX2_POINTERSIZE(mMtlInst);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		if (readedVersion <= 3)
		{
			size += PX2_POINTERSIZE(mFontTex);
		}
	}
	else
	{
		// empty
	}

	if (Stream::ST_IN == stream.GetStreamType())
	{
		if (5 <= readedVersion)
		{
			size += PX2_ENUMSIZE(mFontType);
		}

		if (6 <= readedVersion)
		{
			size += sizeof(mSpace);
		}
	}
	else
	{
		size += PX2_ENUMSIZE(mFontType);
		size += sizeof(mSpace);
	}

	return size;
}
//----------------------------------------------------------------------------