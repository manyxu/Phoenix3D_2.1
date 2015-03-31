// PX2UIText.cpp

#include "PX2UIText.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2FontManager.hpp"
#include "PX2ScriptManager.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, TriMesh, UIText);
PX2_IMPLEMENT_STREAM(UIText);
PX2_IMPLEMENT_FACTORY(UIText);
PX2_IMPLEMENT_DEFAULT_NAMES(TriMesh, UIText);

//----------------------------------------------------------------------------
UIText::UIText()
:
mFontType(FT_FREETYPE)
{
	SetVertexFormat(PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PCT1));

	MaterialInstance *mi = new0 MaterialInstance("Data/engine_mtls/font/font.px2obj",
		"font", false);
	SetMaterialInstance(mi);
	ShaderFloat *shaderFloat = mi->GetPixelConstant(0, "UVParam");
	(*shaderFloat)[0] = 1.0f;
	(*shaderFloat)[1] = 1.0f;

	_Init();
}
//----------------------------------------------------------------------------
UIText::~UIText()
{
}
//----------------------------------------------------------------------------
void UIText::_Init()
{
	SetRenderLayer(Renderable::RL_UI);
	
	mTextAligns = TEXTALIGN_LEFT | TEXTALIGN_VCENTER;
	mRectUseage = RU_NONE;
	mFontStyle = FES_NORMAL;
	mDrawStyle = FD_NORMAL;
	mBorderShadowColor = Float4(0.0f, 0.0f, 0.0f, 1.0f);
	mShadowBorderSize = 1.0f;
	mOffset = Float2::ZERO;
	mSpace = Float2::ZERO;
	mIsAutoWarp = false;
	mIsDoCharTranslate = true;
	mFontScale = 1.0f;

	mFontFilename = "Data/engine/arial.ttf";
	mFontStyle = 0;
	mFontWidth = 24;
	mFontHeight = 24;

	mText = "DefaultText";

	SetColor(Float3::WHITE);
	SetAlpha(1.0f);

	SetFontColor(Float3::BLACK);
	SetFontAlpha(1.0f);
	SetBorderShadowColor(Float3::BLACK);
	SetBorderShadowAlpha(1.0f);

	SetName("UIText");

	mIsNeedReCreateFont = true;
	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetFont(const std::string &fontFilename, int fontWidth,
	int fontHeight, unsigned int fontStyle)
{
	mFontType = FT_FREETYPE;
	mFontFilename = fontFilename;
	mFontWidth = fontWidth;
	mFontHeight = fontHeight;
	mFontStyle = fontStyle;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIText::SetFontBimMap(const std::string &fontFilename)
{
	mFontType = FT_BITMAP;
	mFontFilename = fontFilename;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIText::SetText(const std::string &text)
{
	if (mText == text)
		return;

	mText = text;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetKey(const std::string &key)
{
	if (mKey == key)
		return;

	mKey = key;

	if (PX2_LM.HasValue(key))
	{
		const std::string &tex = PX2_LM.GetValue(key);
		SetText(tex);
	}
}
//----------------------------------------------------------------------------
void UIText::SetFontStyle(int style)
{
	if (mFontStyle == style)
		return;

	mFontStyle = style;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetDrawStyle(int style)
{
	if (mDrawStyle == style)
		return;

	mDrawStyle = style;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetAligns(int aligns)
{
	if (mTextAligns == aligns)
		return;

	mTextAligns = aligns;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
int UIText::GetHAlign() const
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
int UIText::GetVAlign() const
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
void UIText::SetBorderShadowColor(const Float3 &color)
{
	mBorderShadowColor = MathHelp::Float3ToFloat4(color, mBorderShadowColor[3]);

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetBorderShadowAlpha(float alpha)
{
	mBorderShadowColor[3] = alpha;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetShadowBorderSize(float size)
{
	if (mShadowBorderSize == size)
		return;

	mShadowBorderSize = size;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetRectUseage(RectUseage useage)
{
	if (mRectUseage == useage)
		return;

	mRectUseage = useage;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetRect(const Rectf &rect)
{
	if (mRect == rect)
		return;

	mRect = rect;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetOffset(const Float2 &offset)
{
	if (mOffset == offset)
		return;

	mOffset = offset;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetSpace(const Float2 &space)
{
	if (mSpace == space)
		return;

	mSpace = space;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetAutoWarp(bool warp)
{
	if (mIsAutoWarp == warp)
		return;

	mIsAutoWarp = warp;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetDoCharTranslate(bool doTranslate)
{
	if (mIsDoCharTranslate == doTranslate)
		return;

	mIsDoCharTranslate = doTranslate;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetFontScale(float scale)
{
	if (mFontScale == scale)
		return;

	mFontScale = scale;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetColor(const Float3 &color)
{
	if (GetColor() == color)
		return;

	TriMesh::SetColor(color);
}
//----------------------------------------------------------------------------
void UIText::SetAlpha(float alpha)
{
	if (GetAlpha() == alpha)
		return;

	TriMesh::SetAlpha(alpha);
}
//----------------------------------------------------------------------------
void UIText::SetFontColor(const Float3 &color)
{
	mFontColor = MathHelp::Float3ToFloat4(color, mAlpha);

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetFontAlpha(float alpha)
{
	mFontColor[3] = alpha;

	mIsNeedReCreate = true;
}
//----------------------------------------------------------------------------
void UIText::SetFontWidthHeight(int width, int height)
{
	if ((width == mFontWidth && height == mFontHeight) ||
		width <= 0 || width > 512 ||
		height <= 0 || height >= 512)
		return;

	mFontWidth = width;
	mFontHeight = height;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIText::SetFontWidth(int width)
{
	if (width == mFontWidth || width <= 0 || width > 512)
		return;

	mFontWidth = width;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIText::SetFontHeight(int height)
{
	if (height == mFontHeight || height <= 0 || height > 512)
		return;

	mFontHeight = height;

	mIsNeedReCreateFont = true;
}
//----------------------------------------------------------------------------
void UIText::UpdateWorldData(double applicationTime, double elapsedTime)
{
	TriMesh::UpdateWorldData(applicationTime, elapsedTime);

	if (mIsNeedReCreateFont)
	{
		ReCreateFont();
	}

	if (mIsNeedReCreate)
	{
		ReCreate();
	}

	mFontTex = mFont->GetTexture();
}
//----------------------------------------------------------------------------
void UIText::ReCreateFont()
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
void UIText::ReCreate()
{
	if (RU_NONE == mRectUseage)
	{
		PX2_FM.RenderText(this, mFont,
			mText.c_str(), mDrawStyle, mOffset[0], mOffset[1], mSpace, 
			mFontColor, mBorderShadowColor, mShadowBorderSize,
			mFontScale, mIsDoCharTranslate, 0.0f);
	}
	else if (RU_CLIP == mRectUseage)
	{
		PX2_FM.RenderText(this, mFont, mText.c_str(),
			mDrawStyle, mRect, mSpace, mOffset[0], mOffset[1],
			mIsAutoWarp, mFontColor,
			mBorderShadowColor, mShadowBorderSize, mFontScale,
			mIsDoCharTranslate);
	}
	else if (RU_ALIGNS == mRectUseage)
	{
		PX2_FM.RenderText(this, mFont, mText.c_str(),
			mDrawStyle, mTextAligns, mRect, mSpace,
			mFontColor,
			mBorderShadowColor, mShadowBorderSize, mFontScale,
			mIsDoCharTranslate);
	}

	mFontTex = mFont->GetTexture();

	MaterialInstance *mtlInst = GetMaterialInstance();
	mtlInst->SetPixelTexture(0, "SamplerBase", mFontTex);

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
void UIText::RegistProperties()
{
	TriMesh::RegistProperties();

	AddPropertyClass("UIText");

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

	std::vector<std::string> drawStyles;
	drawStyles.push_back("FD_NORMAL");
	drawStyles.push_back("FD_SHADOW");
	drawStyles.push_back("FD_BORDER");
	AddPropertyEnum("DrawStyle", GetDrawStyle(), drawStyles);
	AddProperty("FontColor", PT_COLOR3FLOAT3, GetFontColor());
	AddProperty("FontAlpha", PT_FLOAT, GetFontAlpha());
	AddProperty("BorderShadowColor", PT_COLOR3FLOAT3, GetBorderShadowColor());
	AddProperty("BorderShadowAlpha", PT_FLOAT, GetBorderShadowAlpha());
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
void UIText::OnPropertyChanged(const PropertyObject &obj)
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
	else if ("FontColor" == obj.Name)
	{
		SetFontColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("FontAlpha" == obj.Name)
	{
		SetFontAlpha(PX2_ANY_AS(obj.Data, float));
	}
	else if ("BorderShadowColor" == obj.Name)
	{
		SetBorderShadowColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("BorderShadowAlpha" == obj.Name)
	{
		SetBorderShadowAlpha(PX2_ANY_AS(obj.Data, float));
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
UIText::UIText(LoadConstructor value)
:
TriMesh(value),
mFontType(FT_FREETYPE)
{
	_Init();
}
//----------------------------------------------------------------------------
void UIText::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadString(mText);
	source.ReadString(mKey);

	source.ReadEnum(mRectUseage);
	source.Read(mTextAligns);

	source.Read(mFontStyle);
	source.Read(mDrawStyle);

	source.ReadAggregate(mFontColor);
	source.ReadAggregate(mBorderShadowColor);
	source.Read(mShadowBorderSize);

	source.ReadString(mFontFilename);
	source.Read(mFontWidth);
	source.Read(mFontHeight);

	source.ReadAggregate(mRect);
	source.ReadAggregate(mOffset);
	source.ReadBool(mIsAutoWarp);
	source.ReadBool(mIsDoCharTranslate);
	source.Read(mFontScale);

	source.ReadEnum(mFontType);

	source.ReadAggregate(mSpace);

	PX2_END_DEBUG_STREAM_LOAD(UIText, source);
}
//----------------------------------------------------------------------------
void UIText::Link(InStream& source)
{
	TriMesh::Link(source);
}
//----------------------------------------------------------------------------
void UIText::PostLink()
{
	TriMesh::PostLink();
}
//----------------------------------------------------------------------------
bool UIText::Register(OutStream& target) const
{
	if (TriMesh::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIText::Save(OutStream& target) const
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
	target.WriteAggregate(mFontColor);
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
	target.WriteEnum(mFontType);
	target.WriteAggregate(mSpace);

	PX2_END_DEBUG_STREAM_SAVE(UIText, target);
}
//----------------------------------------------------------------------------
int UIText::GetStreamingSize(Stream &stream) const
{
	int size = TriMesh::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	size += PX2_STRINGSIZE(mText);
	size += PX2_STRINGSIZE(mKey);

	size += PX2_ENUMSIZE(mRectUseage);
	size += sizeof(mTextAligns);

	size += sizeof(mFontStyle);
	size += sizeof(mDrawStyle);

	size += sizeof(mFontColor);

	size += sizeof(mBorderShadowColor);
	size += sizeof(mShadowBorderSize);

	size += PX2_STRINGSIZE(mFontFilename);
	size += sizeof(mFontWidth);
	size += sizeof(mFontHeight);

	size += sizeof(mRect);
	size += sizeof(mOffset);
	size += PX2_BOOLSIZE(mIsAutoWarp);
	size += PX2_BOOLSIZE(mIsDoCharTranslate);
	size += sizeof(mFontScale);

	size += PX2_ENUMSIZE(mFontType);
	size += sizeof(mSpace);

	return size;
}
//----------------------------------------------------------------------------