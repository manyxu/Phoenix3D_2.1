/*
*
* 文件名称	：	PX2UIPicBox.cpp
*
*/

#include "PX2UIPicBox.hpp"
#include "PX2Renderer.hpp"
#include "PX2UIManager.hpp"
#include "PX2UIFrame.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2DynamicBufferManager.hpp"
#include "PX2Material.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, TriMesh, UIPicBox, 6);
PX2_IMPLEMENT_STREAM(UIPicBox);
PX2_IMPLEMENT_FACTORY(UIPicBox);

//----------------------------------------------------------------------------
UIPicBox::UIPicBox (const std::string &filename)
	:
mPicBoxType(PBT_MAX_TYPE),
mIsDynamic(false),
mAnchorPoint(0.5f, 0.5f),
mSize(128, 64),
mCornerSize(6, 6),
mUV0(0.0f, 0.0f),
mUV1(1.0f, 0.0f),
mUV2(0.0f, 1.0f),
mUV3(1.0f, 1.0f),
mUVScale(1.0f, 1.0f),
mColor(Float4::WHITE),
mIsBufferNeedUpdate(true),
mTexMode(TM_TEX),
mTexturePathname(filename),
mIsUseAddedMask(false),
mLastAddedAppTime(0.0f),
mAddedTextureFilename("Data/engine/liuGuang.png"),
mAddedTextureColor(Float4::WHITE),
mAddedTextureUVSpeed(Float2::ZERO),
mAddedTextureUVSRepeat(Float2::UNIT),
mAddedTextureAlphaSpeed(0.0f),
mMaskTextureFilename("Data/engine/qiu.png"),
mMaskTextureAlpha(1.0f),
mMaskTextureAlphaSpeed(0.0f),
mIsUseDark(false),
mIsMtlNeedUpdate(true)
{
	_Init();

	SetTexMode(TM_TEX);
	SetTexture(mTexturePathname);

	mIsBufferNeedUpdate = true;
	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(
		mTexturePathname));
	if (tex)
		SetSize((float)tex->GetWidth(), (float)tex->GetHeight());
}
//----------------------------------------------------------------------------
UIPicBox::UIPicBox (const std::string &packName, const std::string &eleName)
	:
mPicBoxType(PBT_MAX_TYPE),
mIsDynamic(false),
mAnchorPoint(0.5f, 0.5f),
mSize(128, 64),
mCornerSize(6, 6),
mUV0(0.0f, 0.0f),
mUV1(1.0f, 0.0f),
mUV2(0.0f, 1.0f),
mUV3(1.0f, 1.0f),
mUVScale(1.0f, 1.0f),
mColor(Float4::WHITE),
mIsBufferNeedUpdate(true),
mTexMode(TM_TEX),
mIsUseAddedMask(false),
mLastAddedAppTime(0.0f),
mAddedTextureFilename("Data/engine/liuGuang.png"),
mAddedTextureColor(Float4::WHITE),
mAddedTextureUVSpeed(Float2::ZERO),
mAddedTextureUVSRepeat(Float2::UNIT),
mAddedTextureAlphaSpeed(0.0f),
mMaskTextureFilename("Data/engine/qiu.png"),
mMaskTextureAlpha(1.0f),
mMaskTextureAlphaSpeed(0.0f),
mIsUseDark(false),
mIsMtlNeedUpdate(true)
{
	_Init();

	SetTexMode(TM_TEXPACK_ELE);
	SetTexture(packName, eleName);
	SetSize((float)mPackEle.W, (float)mPackEle.H);
}
//----------------------------------------------------------------------------
UIPicBox::~UIPicBox ()
{
}
//----------------------------------------------------------------------------
void UIPicBox::SetPicBoxType (PicBoxType type)
{
	mPicBoxType = type;

	ReCreateVBuffer();

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetDynamic (bool dyn)
{
	mIsDynamic = dyn;
	SetPicBoxType(mPicBoxType);
}
//----------------------------------------------------------------------------
void UIPicBox::SetAnchorPoint (float anchX, float anchZ)
{
	SetAnchorPoint(Float2(anchX, anchZ));
}
//----------------------------------------------------------------------------
void UIPicBox::SetAnchorPoint (Float2 anchor)
{
	mAnchorPoint = anchor;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetSize (float width, float height)
{
	mSize.Width = width;
	mSize.Height = height;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetSize (const Sizef &size)
{
	mSize = size;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetWidth (float width)
{
	mSize.Width = width;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetHeight (float height)
{
	mSize.Height = height;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::MakeSizeWithTex ()
{
	if (!mTexturePackName.empty() && !mElementName.empty())
	{
		mSize.Width = (float)mPackEle.W;
		mSize.Height = (float)mPackEle.H;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetColor (const Float3 &color)
{
	TriMesh::SetColor(color);

	mColor[0] = color[0];
	mColor[1] = color[1];
	mColor[2] = color[2];

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetAlpha (float alpha)
{
	TriMesh::SetAlpha(alpha);

	mColor[3] = alpha;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVScaleX (float xScale)
{
	mUVScale[0] = xScale;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVScaleY (float yScale)
{
	mUVScale[1] = yScale;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVScale (Float2 uvScale)
{
	mUVScale = uvScale;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexMode (TexMode mode)
{
	mTexMode = mode;
}
//----------------------------------------------------------------------------
UIPicBox::TexMode UIPicBox::GetTexMode () const
{
	return mTexMode;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexture (Texture2D *tex)
{
	mTexturePackName = "";
	mElementName = "";

	if (mIsUseDark)
	{
		if (!mUIMtlInstDark)
		{
			mUIMtlInstDark = mUIMtlDark->CreateInstance(tex, mDarkScaleFloat);
		}
		else
		{
			mUIMtlInstDark->SetPixelTexture(0, "gDiffuseSampler", tex);
		}

		SetMaterialInstance(mUIMtlInstDark);
	}
	else
	{
		if (!mUIMtlInst)
		{
			mUIMtlInst = mUIMtl->CreateInstance(tex);
		}
		else
		{
			mUIMtlInst->SetPixelTexture(0, "gDiffuseSampler", tex);
		}

		SetMaterialInstance(mUIMtlInst);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexture (const std::string &filename)
{
	mTexturePackName = "";
	mElementName = "";

	mTexMode = TM_TEX;

	mUV0 = Float2(0.0f, 0.0f);
	mUV1 = Float2(1.0f, 0.0f);
	mUV2 = Float2(0.0f, 1.0f);
	mUV3 = Float2(1.0f, 1.0f);

	mTexturePathname = filename;

	ReCreateVBuffer();

	mIsMtlNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexture (const std::string &texPackName, 
	const std::string &eleName)
{
	mTexMode = TM_TEXPACK_ELE;

	ResourceManager::GetSingleton().AddTexPack(texPackName);
	mPackEle = 
		ResourceManager::GetSingleton().GetTexPackElement(texPackName, eleName);

	if (!mPackEle.IsValid())
		return;

	Object *obj = ResourceManager::GetSingleton().BlockLoad(
		mPackEle.ImagePathFull);
	Texture2D *tex = DynamicCast<Texture2D>(obj);

	if (tex)
	{
		mElementName = eleName;
		mTexturePackName = texPackName;
		mTexturePathname = tex->GetResourcePath();

		float u0 = (float)mPackEle.X/(float)mPackEle.TexWidth;
		float u1 = (float)(mPackEle.X+mPackEle.W)/(float)mPackEle.TexWidth;
		float v0 = (float)(mPackEle.TexHeight-mPackEle.Y-mPackEle.H)/(float)mPackEle.TexHeight;
		float v1 = (float)(mPackEle.TexHeight-mPackEle.Y)/(float)mPackEle.TexHeight;

		if (PBT_NORMAL == mPicBoxType)
		{
			if (!mPackEle.Rolated)
			{
				mUV0 = Float2(u0, v0);
				mUV1 = Float2(u1, v0);
				mUV2 = Float2(u0, v1);
				mUV3 = Float2(u1, v1);
			}
			else
			{
				mUV0 = Float2(u0, v1);
				mUV1 = Float2(u0, v0);
				mUV2 = Float2(u1, v1);
				mUV3 = Float2(u1, v0);
			}
		}
		else
		{
			mUV0 = Float2(u0, v0);
			mUV1 = Float2(u1, v0);
			mUV2 = Float2(u0, v1);
			mUV3 = Float2(u1, v1);
		}
		
		ReCreateVBuffer();

		mIsMtlNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
Texture2D *UIPicBox::GetTexture ()
{
	return DynamicCast<Texture2D>(ResourceManager::GetSingleton().BlockLoad(
		mTexturePathname));
}
//----------------------------------------------------------------------------
void UIPicBox::SetDoubleSide (bool d)
{
	if (mUIMtl)
	{
		mUIMtl->GetCullProperty(0, 0)->Enabled = !d;
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::IsDoubleSide () const
{
	if (mUIMtl)
	{
		return (!mUIMtl->GetCullProperty(0, 0)->Enabled);
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUseAlphaTest (bool use)
{
	if (mIsUseDark)
	{
		if (mUIMtlDark)
		{
			if (use)
			{
				mUIMtlDark->GetAlphaProperty(0, 0)->BlendEnabled = false;
				mUIMtlDark->GetAlphaProperty(0, 0)->CompareEnabled = true;
				mUIMtlDark->GetAlphaProperty(0, 0)->Reference = 0.25f;

				mUIMtlDark->GetDepthProperty(0, 0)->Enabled = true;
				mUIMtlDark->GetDepthProperty(0, 0)->Writable = true;
				mUIMtlDark->GetDepthProperty(0, 0)->Compare = DepthProperty::CM_LEQUAL;
			}
			else
			{
				mUIMtlDark->GetAlphaProperty(0, 0)->BlendEnabled = true;
				mUIMtlDark->GetAlphaProperty(0, 0)->CompareEnabled = false;

				mUIMtlDark->GetDepthProperty(0, 0)->Enabled = true;
				mUIMtlDark->GetDepthProperty(0, 0)->Writable = false;
				mUIMtlDark->GetDepthProperty(0, 0)->Compare = DepthProperty::CM_LEQUAL;
			}
		}
	}
	else
	{
		if (mUIMtl)
		{
			if (use)
			{
				mUIMtl->GetAlphaProperty(0, 0)->BlendEnabled = false;
				mUIMtl->GetAlphaProperty(0, 0)->CompareEnabled = true;
				mUIMtl->GetAlphaProperty(0, 0)->Reference = 0.25f;

				mUIMtl->GetDepthProperty(0, 0)->Enabled = true;
				mUIMtl->GetDepthProperty(0, 0)->Writable = true;
				mUIMtl->GetDepthProperty(0, 0)->Compare = DepthProperty::CM_LEQUAL;
			}
			else
			{
				mUIMtl->GetAlphaProperty(0, 0)->BlendEnabled = true;
				mUIMtl->GetAlphaProperty(0, 0)->CompareEnabled = false;

				mUIMtl->GetDepthProperty(0, 0)->Enabled = true;
				mUIMtl->GetDepthProperty(0, 0)->Writable = false;
				mUIMtl->GetDepthProperty(0, 0)->Compare = DepthProperty::CM_LEQUAL;
			}
		}
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::IsUseAlphaText () const
{
	if (mUIMtl)
	{
		return (!mUIMtl->GetAlphaProperty(0, 0)->BlendEnabled);
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetFliterPoint (bool point)
{
	if (mUIMtl)
	{
		if (point)
		{
			mUIMtl->GetPixelShader()->SetFilter(0, Shader::SF_NEAREST);
		}
		else
		{
			mUIMtl->GetPixelShader()->SetFilter(0, Shader::SF_LINEAR);
		}
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::IsFliterPoint () const
{
	if (mUIMtl)
	{
		return (Shader::SF_NEAREST==mUIMtl->GetPixelShader()->GetFilter(0));
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUseClamp (bool clamp)
{
	if (mUIMtl)
	{
		if (clamp)
		{
			mUIMtl->GetPixelShader()->SetCoordinate(0, 0, Shader::SC_CLAMP);
			mUIMtl->GetPixelShader()->SetCoordinate(0, 1, Shader::SC_CLAMP);
		}
		else
		{
			mUIMtl->GetPixelShader()->SetCoordinate(0, 0, Shader::SC_REPEAT);
			mUIMtl->GetPixelShader()->SetCoordinate(0, 1, Shader::SC_REPEAT);
		}
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::IsUseClamp () const
{
	if (mUIMtl)
	{
		return (Shader::SC_CLAMP==mUIMtl->GetPixelShader()->GetCoordinate(0, 0));
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerSize (float width, float height)
{
	mCornerSize.Width = width;
	mCornerSize.Height = height;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerSize (const Sizef &size)
{
	mCornerSize = size;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerWidth (float width)
{
	mCornerSize.Width = width;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerHeight (float height)
{
	mCornerSize.Height = height;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetUseDark (bool use)
{
	mIsUseDark = use;

	mIsMtlNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetDarkValue (float darkValue)
{
	mDarkParam[0] = darkValue;
	mDarkScaleFloat->SetRegister(0, mDarkParam);
}
//----------------------------------------------------------------------------
float UIPicBox::GetDarkValue () const
{
	return mDarkParam[0];
}
//----------------------------------------------------------------------------
void UIPicBox::SetUseAddedMask (bool use)
{
	mIsUseAddedMask = use;

	ReCreateVBuffer();
	
	mIsMtlNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetAddedTexture (const std::string &filename)
{
	mAddedTextureFilename = filename;

	mIsMtlNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetAddedTextureUVSpeed (const Float2 &uv)
{
	mAddedTextureUVSpeed = uv;
}
//----------------------------------------------------------------------------
void UIPicBox::SetAddedTextureUVRepeat (const Float2 &repeat)
{
	mAddedTextureUVSRepeat = repeat;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetAddedTextureColor (const Float3 &color)
{
	mAddedTextureColor[0] = color[0];
	mAddedTextureColor[1] = color[1];
	mAddedTextureColor[2] = color[2];

	mAddedColorFloat->SetRegister(0, mAddedTextureColor);
}
//----------------------------------------------------------------------------
void UIPicBox::SetAddedTextureAlpha (float alpha)
{
	mAddedTextureColor[3] = alpha;

	mAddedColorFloat->SetRegister(0, mAddedTextureColor);
}
//----------------------------------------------------------------------------
void UIPicBox::SetAddedTextureAlphaSpeed (float speed)
{
	mAddedTextureAlphaSpeed = speed;
}
//----------------------------------------------------------------------------
void UIPicBox::SetMaskTexture (const std::string &filename)
{
	mMaskTextureFilename = filename;

	mIsMtlNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetMaskTextureAlpha (float alpha)
{
	mMaskTextureAlpha = alpha;

	ReCreateVBuffer();
}
//----------------------------------------------------------------------------
void UIPicBox::SetMaskTextureAlphaSpeed (float speed)
{
	mMaskTextureAlphaSpeed = speed;
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateBuffers (float elapsedTime)
{
	UpdateVertexBuffer(elapsedTime);
	UpdateIndexBuffer();
}
//----------------------------------------------------------------------------
void UIPicBox::_Init ()
{
	SetName("UIPicBox");	
	SetRenderLayer(Renderable::RL_UI);

	SetPicBoxType(PBT_NORMAL);

	mUIMtl = new0 UIMaterial();

	// added mask
	mUIMtlUV3 = new0 UIMaterialUV3();
	mAddedColorFloat = new0 ShaderFloat(1);

	// dark
	mDarkParam = Float4::WHITE;
	mUIMtlDark = new0 UIMaterialDark();
	mDarkScaleFloat = new0 ShaderFloat(1);
	mDarkScaleFloat->SetRegister(0, mDarkParam);

	mAddedUV0 = Float2::ZERO;
	mAddedUV1 = Float2(1.0f, 0.0f);
	mAddedUV2 = Float2(0.0f, 1.0f);
	mAddedUV3 = Float2(1.0f, 1.0f);
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateWorldData (double applicationTime)
{
	TriMesh::UpdateWorldData(applicationTime);

	if (0.0f == mLastAddedAppTime)
	{
		mLastAddedAppTime = (float)applicationTime;
	}

	float elapsedTime = (float)applicationTime - mLastAddedAppTime;
	mLastAddedAppTime = (float)applicationTime;

	if (Float2::ZERO != mAddedTextureUVSpeed)
		mIsBufferNeedUpdate = true;

	if (mIsBufferNeedUpdate)
	{
		UpdateBuffers(elapsedTime);

		mIsBufferNeedUpdate = false;
	}

	if (mIsMtlNeedUpdate)
	{
		UpdateMtl();

		mIsMtlNeedUpdate = false;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateVertexBuffer (float elapsedTime)
{
	float anchorWidth = mAnchorPoint[0]*mSize.Width;
	float anchorHeight = mAnchorPoint[1]*mSize.Height;

	if (PBT_NORMAL == mPicBoxType)
	{
		VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

		vba.Position<Float3>(0) = Float3(0.0f-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.Position<Float3>(1) = Float3(mSize.Width-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.Position<Float3>(2) = Float3(0.0f-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.Position<Float3>(3) = Float3(mSize.Width-anchorWidth, 0.0f, mSize.Height-anchorHeight);

		vba.Color<Float4>(0, 0) = mColor;
		vba.Color<Float4>(0, 1) = mColor;
		vba.Color<Float4>(0, 2) = mColor;
		vba.Color<Float4>(0, 3) = mColor;
		vba.TCoord<Float2>(0, 0)[0] = mUV0[0] * mUVScale[0];
		vba.TCoord<Float2>(0, 0)[1] = mUV0[1] * mUVScale[1];
		vba.TCoord<Float2>(0, 1)[0] = mUV1[0] * mUVScale[0];
		vba.TCoord<Float2>(0, 1)[1] = mUV1[1] * mUVScale[1];
		vba.TCoord<Float2>(0, 2)[0] = mUV2[0] * mUVScale[0];
		vba.TCoord<Float2>(0, 2)[1] = mUV2[1] * mUVScale[1];
		vba.TCoord<Float2>(0, 3)[0] = mUV3[0] * mUVScale[0];
		vba.TCoord<Float2>(0, 3)[1] = mUV3[1] * mUVScale[1];

		if (mIsUseAddedMask)
		{
			Float2 uv0 = Float2::ZERO;
			Float2 uv1 = Float2(1.0f, 0.0f);
			Float2 uv2 = Float2(0.0f, 1.0f);
			Float2 uv3 = Float2(1.0f, 1.0f);

			Float2 moveUV;
			moveUV[0] = mAddedTextureUVSpeed[0] * elapsedTime;
			moveUV[1] = mAddedTextureUVSpeed[1] * elapsedTime;

			mAddedUV0[0] += moveUV[0];
			mAddedUV0[1] += moveUV[1];

			mAddedUV1[0] += moveUV[0];
			mAddedUV1[1] += moveUV[1];

			mAddedUV2[0] += moveUV[0];
			mAddedUV2[1] += moveUV[1];

			mAddedUV3[0] += moveUV[0];
			mAddedUV3[1] += moveUV[1];

			vba.TCoord<Float2>(1, 0)[0] = mAddedUV0[0] * mAddedTextureUVSRepeat[0];
			vba.TCoord<Float2>(1, 0)[1] = mAddedUV0[1] * mAddedTextureUVSRepeat[1];
			vba.TCoord<Float2>(1, 1)[0] = mAddedUV1[0] * mAddedTextureUVSRepeat[0];
			vba.TCoord<Float2>(1, 1)[1] = mAddedUV1[1] * mAddedTextureUVSRepeat[1];
			vba.TCoord<Float2>(1, 2)[0] = mAddedUV2[0] * mAddedTextureUVSRepeat[0];
			vba.TCoord<Float2>(1, 2)[1] = mAddedUV2[1] * mAddedTextureUVSRepeat[1];
			vba.TCoord<Float2>(1, 3)[0] = mAddedUV3[0] * mAddedTextureUVSRepeat[0];
			vba.TCoord<Float2>(1, 3)[1] = mAddedUV3[1] * mAddedTextureUVSRepeat[1];

			vba.TCoord<Float2>(2, 0)[0] = uv0[0];
			vba.TCoord<Float2>(2, 0)[1] = uv0[1];
			vba.TCoord<Float2>(2, 1)[0] = uv1[0];
			vba.TCoord<Float2>(2, 1)[1] = uv1[1];
			vba.TCoord<Float2>(2, 2)[0] = uv2[0];
			vba.TCoord<Float2>(2, 2)[1] = uv2[1];
			vba.TCoord<Float2>(2, 3)[0] = uv3[0];
			vba.TCoord<Float2>(2, 3)[1] = uv3[1];
		}
	}
	else if (PBT_NINE == mPicBoxType)
	{
		float texWidth = 32;
		float texHeight = 32;

		Texture2D *tex = DynamicCast<Texture2D>(
			ResourceManager::GetSingleton().BlockLoad(mTexturePathname));

		if (tex)
		{
			texWidth = (float)tex->GetWidth();
			texHeight = (float)tex->GetHeight();
		}

		float cornerWidth = mCornerSize.Width;
		float cornerHeight = mCornerSize.Height;

		float widthPerc = 1.0f;
		if (mSize.Width < mCornerSize.Width*2.0f)
		{
			widthPerc = mSize.Width/(mCornerSize.Width*2.0f);
		}
		cornerWidth *= widthPerc;

		float heightPerc = 1.0f;
		if (mSize.Height < mCornerSize.Height*2.0f)
		{
			heightPerc = mSize.Height/(mCornerSize.Height*2.0f);
		}
		cornerHeight *= heightPerc;

		float corW = cornerWidth/texWidth;
		float corH = cornerHeight/texHeight;

		float u0 = mUV0[0];
		float u1 = mUV0[0] + corW;
		float u2 = mUV1[0] - corW;
		float u3 = mUV1[0];
		float v0 = mUV0[1];
		float v1 = mUV0[1] + corH;
		float v2 = mUV2[1] - corH;
		float v3 = mUV2[1];

		Float2 uv[16];
		if (!mPackEle.Rolated)
		{
			uv[0] = Float2(u0, v0);
			uv[1] = Float2(u1, v0);
			uv[2] = Float2(u2, v0);
			uv[3] = Float2(u3, v0);
			uv[4] = Float2(u0, v1);
			uv[5] = Float2(u1, v1);
			uv[6] = Float2(u2, v1);
			uv[7] = Float2(u3, v1);
			uv[8] = Float2(u0, v2);
			uv[9] = Float2(u1, v2);
			uv[10] = Float2(u2, v2);
			uv[11] = Float2(u3, v2);
			uv[12] = Float2(u0, v3);
			uv[13] = Float2(u1, v3);
			uv[14] = Float2(u2, v3);
			uv[15] = Float2(u3, v3);
		}
		else
		{
			uv[0] = Float2(u0, v3);
			uv[1] = Float2(u0, v2);
			uv[2] = Float2(u0, v1);
			uv[3] = Float2(u0, v0);

			uv[4] = Float2(u1, v3);
			uv[5] = Float2(u1, v2);
			uv[6] = Float2(u1, v1);
			uv[7] = Float2(u1, v0);

			uv[8] = Float2(u2, v3);
			uv[9] = Float2(u2, v2);
			uv[10] = Float2(u2, v1);
			uv[11] = Float2(u2, v0);

			uv[12] = Float2(u3, v3);
			uv[13] = Float2(u3, v2);
			uv[14] = Float2(u3, v1);
			uv[15] = Float2(u3, v0);
		}

		VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

		vba.Position<Float3>(0) = Float3(0.0f-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, 0) = uv[0];
		vba.Position<Float3>(1) = Float3(cornerWidth-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, 1) = uv[1];
		vba.Position<Float3>(2) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, 2) = uv[2];
		vba.Position<Float3>(3) = Float3(mSize.Width-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, 3) = uv[3];
		vba.Position<Float3>(4) = Float3(0.0f-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 4) = uv[4];
		vba.Position<Float3>(5) = Float3(cornerWidth-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 5) = uv[5];
		vba.Position<Float3>(6) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 6) = uv[6];
		vba.Position<Float3>(7) = Float3(mSize.Width-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 7) = uv[7];
		vba.Position<Float3>(8) = Float3(0.0f-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 8) = uv[8];
		vba.Position<Float3>(9) = Float3(cornerWidth-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 9) = uv[9];
		vba.Position<Float3>(10) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 10) = uv[10];
		vba.Position<Float3>(11) = Float3(mSize.Width-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, 11) = uv[11];
		vba.Position<Float3>(12) = Float3(0.0f-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, 12) = uv[12];
		vba.Position<Float3>(13) = Float3(cornerWidth-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, 13) = uv[13];
		vba.Position<Float3>(14) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, 14) = uv[14];
		vba.Position<Float3>(15) = Float3(mSize.Width-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, 15) = uv[15];

		if (mIsUseAddedMask)
		{
			float corW = cornerWidth/mSize.Width;
			float corH = cornerHeight/mSize.Height;

			Float2 uv0 = Float2::ZERO;
			Float2 uv1 = Float2(1.0f, 0.0f);
			Float2 uv2 = Float2(0.0f, 1.0f);
			Float2 uv3 = Float2(1.0f, 1.0f);

			float u0 = uv0[0];
			float u1 = uv0[0] + corW;
			float u2 = uv1[0] - corW;
			float u3 = uv1[0];
			float v0 = uv0[1];
			float v1 = uv0[1] + corH;
			float v2 = uv2[1] - corH;
			float v3 = uv2[1];

			Float2 uv[16];
			uv[0] = Float2(u0, v0);
			uv[1] = Float2(u1, v0);
			uv[2] = Float2(u2, v0);
			uv[3] = Float2(u3, v0);
			uv[4] = Float2(u0, v1);
			uv[5] = Float2(u1, v1);
			uv[6] = Float2(u2, v1);
			uv[7] = Float2(u3, v1);
			uv[8] = Float2(u0, v2);
			uv[9] = Float2(u1, v2);
			uv[10] = Float2(u2, v2);
			uv[11] = Float2(u3, v2);
			uv[12] = Float2(u0, v3);
			uv[13] = Float2(u1, v3);
			uv[14] = Float2(u2, v3);
			uv[15] = Float2(u3, v3);

			vba.TCoord<Float2>(1, 0) = uv[0];
			vba.TCoord<Float2>(1, 1) = uv[1];
			vba.TCoord<Float2>(1, 2) = uv[2];
			vba.TCoord<Float2>(1, 3) = uv[3];
			vba.TCoord<Float2>(1, 4) = uv[4];
			vba.TCoord<Float2>(1, 5) = uv[5];
			vba.TCoord<Float2>(1, 6) = uv[6];
			vba.TCoord<Float2>(1, 7) = uv[7];
			vba.TCoord<Float2>(1, 8) = uv[8];
			vba.TCoord<Float2>(1, 9) = uv[9];
			vba.TCoord<Float2>(1, 10) = uv[10];
			vba.TCoord<Float2>(1, 11) = uv[11];
			vba.TCoord<Float2>(1, 12) = uv[12];
			vba.TCoord<Float2>(1, 13) = uv[13];
			vba.TCoord<Float2>(1, 14) = uv[14];
			vba.TCoord<Float2>(1, 15) = uv[15];

			vba.TCoord<Float2>(2, 0) = uv[0];
			vba.TCoord<Float2>(2, 1) = uv[1];
			vba.TCoord<Float2>(2, 2) = uv[2];
			vba.TCoord<Float2>(2, 3) = uv[3];
			vba.TCoord<Float2>(2, 4) = uv[4];
			vba.TCoord<Float2>(2, 5) = uv[5];
			vba.TCoord<Float2>(2, 6) = uv[6];
			vba.TCoord<Float2>(2, 7) = uv[7];
			vba.TCoord<Float2>(2, 8) = uv[8];
			vba.TCoord<Float2>(2, 9) = uv[9];
			vba.TCoord<Float2>(2, 10) = uv[10];
			vba.TCoord<Float2>(2, 11) = uv[11];
			vba.TCoord<Float2>(2, 12) = uv[12];
			vba.TCoord<Float2>(2, 13) = uv[13];
			vba.TCoord<Float2>(2, 14) = uv[14];
			vba.TCoord<Float2>(2, 15) = uv[15];
		}

		vba.Color<Float4>(0, 0) = mColor;
		vba.Color<Float4>(0, 1) = mColor;
		vba.Color<Float4>(0, 2) = mColor;
		vba.Color<Float4>(0, 3) = mColor;
		vba.Color<Float4>(0, 4) = mColor;
		vba.Color<Float4>(0, 5) = mColor;
		vba.Color<Float4>(0, 6) = mColor;
		vba.Color<Float4>(0, 7) = mColor;
		vba.Color<Float4>(0, 8) = mColor;
		vba.Color<Float4>(0, 9) = mColor;
		vba.Color<Float4>(0, 10) = mColor;
		vba.Color<Float4>(0, 11) = mColor;
		vba.Color<Float4>(0, 12) = mColor;
		vba.Color<Float4>(0, 13) = mColor;
		vba.Color<Float4>(0, 14) = mColor;
		vba.Color<Float4>(0, 15) = mColor;
	}
	
	UpdateModelSpace(GU_MODEL_BOUND_ONLY);

	if (!IsUseShareBuffers() && Renderer::IsOneBind(GetVertexBuffer()))
	{
		Renderer::UpdateAll(GetVertexBuffer());
	}
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateDynBuffers (float elapsedTime)
{
	PX2_UNUSED(elapsedTime);

	float anchorWidth = mAnchorPoint[0]*mSize.Width;
	float anchorHeight = mAnchorPoint[1]*mSize.Height;

	if (PBT_NORMAL == mPicBoxType)
	{
		DBObject_V *objV = PX2_DBM.AllocVertexBuffer(4);
		SetShareDBObject_V(objV);
		DBObject_I *objI = PX2_DBM.AllocIndexBuffer(6);
		SetShareDBObject_I(objI);

		VertexBufferAccessor vba(GetVertexFormat(), objV->Buf);

		vba.Position<Float3>(objV->Offset+0) = Float3(0.0f-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.Position<Float3>(objV->Offset+1) = Float3(mSize.Width-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.Position<Float3>(objV->Offset+2) = Float3(0.0f-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.Position<Float3>(objV->Offset+3) = Float3(mSize.Width-anchorWidth, 0.0f, mSize.Height-anchorHeight);

		vba.Color<Float4>(0, objV->Offset+0) = mColor;
		vba.Color<Float4>(0, objV->Offset+1) = mColor;
		vba.Color<Float4>(0, objV->Offset+2) = mColor;
		vba.Color<Float4>(0, objV->Offset+3) = mColor;
		vba.TCoord<Float2>(0, objV->Offset+0)[0] = mUV0[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset+0)[1] = mUV0[1] * mUVScale[1];
		vba.TCoord<Float2>(0, objV->Offset+1)[0] = mUV1[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset+1)[1] = mUV1[1] * mUVScale[1];
		vba.TCoord<Float2>(0, objV->Offset+2)[0] = mUV2[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset+2)[1] = mUV2[1] * mUVScale[1];
		vba.TCoord<Float2>(0, objV->Offset+3)[0] = mUV3[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset+3)[1] = mUV3[1] * mUVScale[1];

		unsigned short *indices = (unsigned short*)objI->Buf->GetData();
		indices += objI->Offset;

		unsigned short v0 = (unsigned short)(objV->Offset+0);
		unsigned short v1 = (unsigned short)(objV->Offset+1);
		unsigned short v2 = (unsigned short)(objV->Offset+2);
		unsigned short v3 = (unsigned short)(objV->Offset+3);

		*indices++ = v0;
		*indices++ = v1;
		*indices++ = v2;
		*indices++ = v1;
		*indices++ = v3;
		*indices++ = v2;
	}
	else if (PBT_NINE == mPicBoxType)
	{
		float texWidth = 32;
		float texHeight = 32;

		Texture2D *tex = DynamicCast<Texture2D>(
			ResourceManager::GetSingleton().BlockLoad(mTexturePathname));

		if (tex)
		{
			texWidth = (float)tex->GetWidth();
			texHeight = (float)tex->GetHeight();
		}

		float cornerWidth = mCornerSize.Width;
		float cornerHeight = mCornerSize.Height;

		float widthPerc = 1.0f;
		if (mSize.Width < mCornerSize.Width*2.0f)
		{
			widthPerc = mSize.Width/(mCornerSize.Width*2.0f);
		}
		cornerWidth *= widthPerc;

		float heightPerc = 1.0f;
		if (mSize.Height < mCornerSize.Height*2.0f)
		{
			heightPerc = mSize.Height/(mCornerSize.Height*2.0f);
		}
		cornerHeight *= heightPerc;

		float corW = cornerWidth/texWidth;
		float corH = cornerHeight/texHeight;

		float u0 = mUV0[0];
		float u1 = mUV0[0] + corW;
		float u2 = mUV1[0] - corW;
		float u3 = mUV1[0];
		float v0 = mUV0[1];
		float v1 = mUV0[1] + corH;
		float v2 = mUV2[1] - corH;
		float v3 = mUV2[1];

		Float2 uv[16];
		if (!mPackEle.Rolated)
		{
			uv[0] = Float2(u0, v0);
			uv[1] = Float2(u1, v0);
			uv[2] = Float2(u2, v0);
			uv[3] = Float2(u3, v0);
			uv[4] = Float2(u0, v1);
			uv[5] = Float2(u1, v1);
			uv[6] = Float2(u2, v1);
			uv[7] = Float2(u3, v1);
			uv[8] = Float2(u0, v2);
			uv[9] = Float2(u1, v2);
			uv[10] = Float2(u2, v2);
			uv[11] = Float2(u3, v2);
			uv[12] = Float2(u0, v3);
			uv[13] = Float2(u1, v3);
			uv[14] = Float2(u2, v3);
			uv[15] = Float2(u3, v3);
		}
		else
		{
			uv[0] = Float2(u0, v3);
			uv[1] = Float2(u0, v2);
			uv[2] = Float2(u0, v1);
			uv[3] = Float2(u0, v0);

			uv[4] = Float2(u1, v3);
			uv[5] = Float2(u1, v2);
			uv[6] = Float2(u1, v1);
			uv[7] = Float2(u1, v0);

			uv[8] = Float2(u2, v3);
			uv[9] = Float2(u2, v2);
			uv[10] = Float2(u2, v1);
			uv[11] = Float2(u2, v0);

			uv[12] = Float2(u3, v3);
			uv[13] = Float2(u3, v2);
			uv[14] = Float2(u3, v1);
			uv[15] = Float2(u3, v0);
		}

		DBObject_V *objV = PX2_DBM.AllocVertexBuffer(16);
		SetShareDBObject_V(objV);
		DBObject_I *objI = PX2_DBM.AllocIndexBuffer(54);
		SetShareDBObject_I(objI);

		VertexBufferAccessor vba(GetVertexFormat(), objV->Buf);

		vba.Position<Float3>(objV->Offset+0) = Float3(0.0f-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+0) = uv[0];
		vba.Position<Float3>(objV->Offset+1) = Float3(cornerWidth-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+1) = uv[1];
		vba.Position<Float3>(objV->Offset+2) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+2) = uv[2];
		vba.Position<Float3>(objV->Offset+3) = Float3(mSize.Width-anchorWidth, 0.0f, 0.0f-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+3) = uv[3];
		vba.Position<Float3>(objV->Offset+4) = Float3(0.0f-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+4) = uv[4];
		vba.Position<Float3>(objV->Offset+5) = Float3(cornerWidth-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+5) = uv[5];
		vba.Position<Float3>(objV->Offset+6) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+6) = uv[6];
		vba.Position<Float3>(objV->Offset+7) = Float3(mSize.Width-anchorWidth, 0.0f, cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+7) = uv[7];
		vba.Position<Float3>(objV->Offset+8) = Float3(0.0f-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+8) = uv[8];
		vba.Position<Float3>(objV->Offset+9) = Float3(cornerWidth-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+9) = uv[9];
		vba.Position<Float3>(objV->Offset+10) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+10) = uv[10];
		vba.Position<Float3>(objV->Offset+11) = Float3(mSize.Width-anchorWidth, 0.0f, mSize.Height-cornerHeight-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+11) = uv[11];
		vba.Position<Float3>(objV->Offset+12) = Float3(0.0f-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+12) = uv[12];
		vba.Position<Float3>(objV->Offset+13) = Float3(cornerWidth-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+13) = uv[13];
		vba.Position<Float3>(objV->Offset+14) = Float3(mSize.Width-cornerWidth-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+14) = uv[14];
		vba.Position<Float3>(objV->Offset+15) = Float3(mSize.Width-anchorWidth, 0.0f, mSize.Height-anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset+15) = uv[15];	

		vba.Color<Float4>(0, objV->Offset+0) = mColor;
		vba.Color<Float4>(0, objV->Offset+1) = mColor;
		vba.Color<Float4>(0, objV->Offset+2) = mColor;
		vba.Color<Float4>(0, objV->Offset+3) = mColor;
		vba.Color<Float4>(0, objV->Offset+4) = mColor;
		vba.Color<Float4>(0, objV->Offset+5) = mColor;
		vba.Color<Float4>(0, objV->Offset+6) = mColor;
		vba.Color<Float4>(0, objV->Offset+7) = mColor;
		vba.Color<Float4>(0, objV->Offset+8) = mColor;
		vba.Color<Float4>(0, objV->Offset+9) = mColor;
		vba.Color<Float4>(0, objV->Offset+10) = mColor;
		vba.Color<Float4>(0, objV->Offset+11) = mColor;
		vba.Color<Float4>(0, objV->Offset+12) = mColor;
		vba.Color<Float4>(0, objV->Offset+13) = mColor;
		vba.Color<Float4>(0, objV->Offset+14) = mColor;
		vba.Color<Float4>(0, objV->Offset+15) = mColor;

		unsigned short *indices = (unsigned short*)objI->Buf->GetData();
		indices += objI->Offset;
		for (unsigned short j=0; j<3; j++)
		{
			for (unsigned short i=0; i<3; i++)
			{
				unsigned short v0 = (unsigned short)(objV->Offset + i + 4 * j);
				unsigned short v1 = (unsigned short)(v0 + 1);
				unsigned short v2 = (unsigned short)(v0 + 4);
				unsigned short v3 = (unsigned short)(v1 + 4);

				*indices++ = v0;
				*indices++ = v1;
				*indices++ = v2;
				*indices++ = v1;
				*indices++ = v3;
				*indices++ = v2;
			}
		}
	}
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateIndexBuffer ()
{
	unsigned short *indices = (unsigned short*)GetIndexBuffer()->GetData();
	if (PBT_NORMAL == mPicBoxType)
	{
		unsigned short v0 = 0;
		unsigned short v1 = 1;
		unsigned short v2 = 2;
		unsigned short v3 = 3;

		*indices++ = v0;
		*indices++ = v1;
		*indices++ = v2;
		*indices++ = v1;
		*indices++ = v3;
		*indices++ = v2;
	}
	else if (PBT_NINE == mPicBoxType)
	{
		for (unsigned short j=0; j<3; j++)
		{
			for (unsigned short i=0; i<3; i++)
			{
				unsigned short v0 = i + 4 * j;
				unsigned short v1 = v0 + 1;
				unsigned short v2 = v0 + 4;
				unsigned short v3 = v1 + 4;

				*indices++ = v0;
				*indices++ = v1;
				*indices++ = v2;
				*indices++ = v1;
				*indices++ = v3;
				*indices++ = v2;
			}
		}
	}

	UpdateModelSpace(GU_MODEL_BOUND_ONLY);

	if (!IsUseShareBuffers() && Renderer::IsOneBind(GetVertexBuffer()))
	{
		Renderer::UpdateAll(GetIndexBuffer());
	}
}
//----------------------------------------------------------------------------
void UIPicBox::OnPicked (int info)
{
	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildPicked(info, this);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::OnNotPicked (int pickInfo)
{
	PX2_UNUSED(pickInfo);
}
//----------------------------------------------------------------------------
void UIPicBox::ReCreateVBuffer ()
{
	VertexFormat *vFormat = UIManager::GetSingleton().GetVertexFormat();
	if (IsUseAddedMask())
		vFormat = UIManager::GetSingleton().GetVertexFormatUV3();
	SetVertexFormat(vFormat);

	int numVertex = 4;
	int numIndex = 6;

	if (PBT_NORMAL == mPicBoxType)
	{
		numVertex = 4;
		numIndex = 6;
	}
	else if (PBT_NINE == mPicBoxType)
	{
		numVertex = 16;
		numIndex = 54;
	}

	VertexBuffer *vBuffer = new0 VertexBuffer(numVertex, vFormat->GetStride(),
		mIsDynamic ? Buffer::BU_DYNAMIC : Buffer::BU_STATIC);
	IndexBuffer *iBuffer = new0 IndexBuffer(numIndex, 2);
	SetVertexBuffer(vBuffer);
	SetIndexBuffer(iBuffer);

	mIsBufferNeedUpdate = true; 
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateMtl ()
{
	if (mIsUseAddedMask)
	{
		mAddedColorFloat->SetRegister(0, mAddedTextureColor);

		Texture2D *base = DynamicCast<Texture2D>(PX2_RM.BlockLoad(mTexturePathname));
		Texture2D *added = DynamicCast<Texture2D>(PX2_RM.BlockLoad(mAddedTextureFilename));
		Texture2D *mask = DynamicCast<Texture2D>(PX2_RM.BlockLoad(mMaskTextureFilename));

		if (!mUIMtlInstUV3)
		{
			mUIMtlInstUV3 = mUIMtlUV3->CreateInstance(base, added, mAddedColorFloat, mask);
		}
		else
		{
			mUIMtlInstUV3->SetPixelTexture(0, "gDiffuseSampler", base);
			mUIMtlInstUV3->SetPixelTexture(0, "gAddedSampler", added);
			mUIMtlInstUV3->SetPixelTexture(0, "gMaskSampler", mask);
		}

		SetMaterialInstance(mUIMtlInstUV3);
	}
	else if (mIsUseDark)
	{
		if (!mDarkScaleFloat)
		{
			mDarkScaleFloat = new0 ShaderFloat(1);
		}
		mDarkScaleFloat->SetRegister(0, mDarkParam);

		Texture2DPtr base = DynamicCast<Texture2D>(PX2_RM.BlockLoad(mTexturePathname));

		if (!mUIMtlDark)
		{
			mUIMtlDark = new0 UIMaterialDark();
		}

		if (!mUIMtlInstDark)
		{
			mUIMtlInstDark = mUIMtlDark->CreateInstance(base, mDarkScaleFloat);
		}
		else
		{
			mUIMtlInstDark->SetPixelTexture(0, "gDiffuseSampler", base);
		}

		SetMaterialInstance(mUIMtlInstDark);
	}
	else
	{
		Texture2DPtr base = DynamicCast<Texture2D>(PX2_RM.BlockLoad(mTexturePathname));

		if (!mUIMtlInst)
		{
			mUIMtlInst = mUIMtl->CreateInstance(base);
		}
		else
		{
			mUIMtlInst->SetPixelTexture(0, "gDiffuseSampler", base);
		}

		SetMaterialInstance(mUIMtlInst);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::OnForceBind ()
{
	if (mIsBufferNeedUpdate)
	{
		UpdateBuffers(0.0f);

		mIsBufferNeedUpdate = false;
	}

	if (mIsMtlNeedUpdate)
	{
		Texture2D *tex2D = DynamicCast<Texture2D>(PX2_RM.BlockLoad(mTexturePathname));
		if (tex2D)
		{
			Renderer::UpdateAll(tex2D, 0);
		}

		if (!mUIMtlInst)
		{
			mUIMtlInst = mUIMtl->CreateInstance(tex2D);
		}
		else
		{
			mUIMtlInst->SetPixelTexture(0, "gDiffuseSampler", tex2D);
		}

		SetMaterialInstance(mUIMtlInst);

		mIsMtlNeedUpdate = false;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::UIAfterPicked (int info)
{
	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildUIAfterPicked(info, this);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// UIPicBox
//----------------------------------------------------------------------------
void UIPicBox::RegistProperties ()
{
	TriMesh::RegistProperties();

	AddPropertyClass("UIPicBox");

	std::vector<std::string> picBoxTypes;
	picBoxTypes.push_back("PBT_NORMAL");
	picBoxTypes.push_back("PBT_NINE");
	AddPropertyEnum("PicBoxType", (int)GetPicBoxType(), picBoxTypes);

	AddProperty("IsDynamic", PT_BOOL, IsDynamic());
	AddProperty("AnchorPoint", PT_FLOAT2, GetAnchorPoint());
	AddProperty("Size", PT_SIZE, GetSize());
	AddProperty("UVScale", PT_FLOAT2, GetUVScale());

	std::vector<std::string> texModes;
	texModes.push_back("TM_TEX");
	texModes.push_back("TM_TEXPACK_ELE");
	AddPropertyEnum("TexMode", (int)GetTexMode(), texModes);

	AddProperty("Tex", PT_STRINGBUTTON, mTexturePathname);
	AddProperty("TexPack_Ele", PT_STRINGBUTTON, mElementName);

	AddProperty("IsDoubleSide", PT_BOOL, IsDoubleSide());
	AddProperty("IsUseAlphaTest", PT_BOOL, IsUseAlphaText());
	AddProperty("IsFliterPoint", PT_BOOL, IsFliterPoint());
	AddProperty("IsUVClamp", PT_BOOL, IsUseClamp());
	AddProperty("TexCornerSize", PT_SIZE, GetTexCornerSize());

	AddProperty("IsUseAddedMask", PT_BOOL, IsUseAddedMask());
	AddProperty("AddedTexture", PT_STRINGBUTTON, GetAddedTextureFilename());
	AddProperty("AddedTextureUVSpeed", PT_FLOAT2, GetAddedTextureUVSpeed());
	AddProperty("AddedTextureUVRepeat", PT_FLOAT2, GetAddedTextureUVRepeat());
	AddProperty("AddedTextureColor", PT_FLOAT3, GetAddedTextureColor());
	AddProperty("AddedTextureAlpha", PT_FLOAT, GetAddedTextureAlpha());
	AddProperty("AddedTextureAlphaSpeed", PT_FLOAT, GetAddedTextureAlphaSpeed());
	AddProperty("MaskTexture", PT_STRINGBUTTON, GetMaskTexture());
	AddProperty("MaskTextureAlpha", PT_FLOAT, GetMaskTextureAlpha());
	AddProperty("MaskTextureAlphaSpeed", PT_FLOAT, GetMaskTextureAlphaSpeed());

	AddProperty("IsUseDark", PT_BOOL, IsUserDark());
}
//----------------------------------------------------------------------------
void UIPicBox::OnPropertyChanged (const PropertyObject &obj)
{
	TriMesh::OnPropertyChanged(obj);

	if ("PicBoxType" == obj.Name)
	{
		SetPicBoxType((PicBoxType)PX2_ANY_AS(obj.Data, int));
	}
	else if ("IsDynamic" == obj.Name)
	{
		SetDynamic(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("AnchorPoint" == obj.Name)
	{
		SetAnchorPoint(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("UVScale" == obj.Name)
	{
		SetUVScale(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("IsDoubleSide" == obj.Name)
	{
		SetDoubleSide(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsUseAlphaTest" == obj.Name)
	{
		SetUseAlphaTest(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsFliterPoint" == obj.Name)
	{
		SetFliterPoint(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("IsUVClamp" == obj.Name)
	{
		SetUseClamp(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("TexCornerSize" == obj.Name)
	{
		SetTexCornerSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("TexMode" == obj.Name)
	{
		SetTexMode((TexMode)PX2_ANY_AS(obj.Data, int));
	}
	else if ("Tex" == obj.Name && mTexMode==TM_TEX)
	{
		SetTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("TexPack_Ele" == obj.Name && mTexMode==TM_TEXPACK_ELE)
	{
		SetTexture(PX2_ANY_AS(obj.Data1, std::string),
			PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("IsUseAddedMask" == obj.Name)
	{
		SetUseAddedMask(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("AddedTexture" == obj.Name)
	{
		SetAddedTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("AddedTextureUVSpeed" == obj.Name)
	{
		SetAddedTextureUVSpeed(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("AddedTextureUVRepeat" == obj.Name)
	{
		SetAddedTextureUVRepeat(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("AddedTextureColor" == obj.Name)
	{
		SetAddedTextureColor(PX2_ANY_AS(obj.Data, Float3));
	}
	else if ("AddedTextureAlpha" == obj.Name)
	{
		SetAddedTextureAlpha(PX2_ANY_AS(obj.Data, float));
	}
	else if ("AddedTextureAlphaSpeed" == obj.Name)
	{
		SetAddedTextureAlphaSpeed(PX2_ANY_AS(obj.Data, float));
	}
	else if ("MaskTexture" == obj.Name)
	{
		SetMaskTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("MaskTextureAlpha" == obj.Name)
	{
		SetMaskTextureAlpha(PX2_ANY_AS(obj.Data, float));
	}
	else if ("MaskTexture" == obj.Name)
	{
		SetMaskTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("MaskTextureAlpha" == obj.Name)
	{
		SetMaskTextureAlpha(PX2_ANY_AS(obj.Data, float));
	}
	else if ("MaskTextureAlphaSpeed" == obj.Name)
	{
		SetMaskTextureAlphaSpeed(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsUseDark" == obj.Name)
	{
		SetUseDark(PX2_ANY_AS(obj.Data, bool));
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTextureNoRecreateBuffer (const std::string &texPackName, 
	std::string eleName)
{
	ResourceManager::GetSingleton().AddTexPack(texPackName);
	mPackEle = 
		ResourceManager::GetSingleton().GetTexPackElement(texPackName, eleName);

	if (!mPackEle.IsValid())
		return;

	Object *obj = ResourceManager::GetSingleton().BlockLoad(
		mPackEle.ImagePathFull);
	Texture2D *tex = DynamicCast<Texture2D>(obj);

	if (tex)
	{
		mElementName = eleName;
		mTexturePackName = texPackName;
		mTexturePathname = tex->GetResourcePath();

		float u0 = (float)mPackEle.X/(float)mPackEle.TexWidth;
		float u1 = (float)(mPackEle.X+mPackEle.W)/(float)mPackEle.TexWidth;
		float v0 = (float)(mPackEle.TexHeight-mPackEle.Y-mPackEle.H)/(float)mPackEle.TexHeight;
		float v1 = (float)(mPackEle.TexHeight-mPackEle.Y)/(float)mPackEle.TexHeight;

		if (PBT_NORMAL == mPicBoxType)
		{
			if (!mPackEle.Rolated)
			{
				mUV0 = Float2(u0, v0);
				mUV1 = Float2(u1, v0);
				mUV2 = Float2(u0, v1);
				mUV3 = Float2(u1, v1);
			}
			else
			{
				mUV0 = Float2(u0, v1);
				mUV1 = Float2(u0, v0);
				mUV2 = Float2(u1, v1);
				mUV3 = Float2(u1, v0);
			}
		}
		else
		{
			mUV0 = Float2(u0, v0);
			mUV1 = Float2(u1, v0);
			mUV2 = Float2(u0, v1);
			mUV3 = Float2(u1, v1);
		}

		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称支持
//----------------------------------------------------------------------------
Object* UIPicBox::GetObjectByName (const std::string& name)
{
	Object* found = TriMesh::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mUIMtl, name, found);

	return 0;
}
//----------------------------------------------------------------------------
void UIPicBox::GetAllObjectsByName (const std::string& name,
	std::vector<Object*>& objects)
{
	TriMesh::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mUIMtl, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIPicBox::UIPicBox (LoadConstructor value)
	:
TriMesh(value),
mPicBoxType(PBT_MAX_TYPE),
mIsDynamic(false),
mAnchorPoint(0.5f, 0.5f),
mSize(128, 64),
mCornerSize(6, 6),
mUV0(0.0f, 0.0f),
mUV1(1.0f, 0.0f),
mUV2(0.0f, 1.0f),
mUV3(1.0f, 1.0f),
mUVScale(1.0f, 1.0f),
mColor(Float4::WHITE),
mIsBufferNeedUpdate(true),
mTexMode(TM_TEX),
mIsUseAddedMask(false),
mLastAddedAppTime(0.0f),
mAddedTextureFilename("Data/engine/liuGuang.png"),
mAddedTextureColor(Float4::WHITE),
mAddedTextureUVSpeed(Float2::ZERO),
mAddedTextureUVSRepeat(Float2::UNIT),
mAddedTextureAlphaSpeed(0.0f),
mMaskTextureFilename("Data/engine/qiu.png"),
mMaskTextureAlpha(1.0f),
mMaskTextureAlphaSpeed(0.0f),
mIsUseDark(false),
mIsMtlNeedUpdate(true)
{
	mDarkParam = Float4::WHITE;
	mAddedUV0 = Float2::ZERO;
	mAddedUV1 = Float2(1.0f, 0.0f);
	mAddedUV2 = Float2(0.0f, 1.0f);
	mAddedUV3 = Float2(1.0f, 1.0f);
}
//----------------------------------------------------------------------------
void UIPicBox::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadEnum(mPicBoxType);
	source.ReadBool(mIsDynamic);
	source.ReadAggregate(mAnchorPoint),
	source.ReadAggregate(mSize);
	source.ReadAggregate(mCornerSize);
	source.ReadAggregate(mUV0);
	source.ReadAggregate(mUV1);
	source.ReadAggregate(mUV2);
	source.ReadAggregate(mUV3);
	source.ReadAggregate(mUVScale);
	source.ReadAggregate(mColor);
	source.ReadPointer(mUIMtl);
	source.ReadPointer(mUIMtlInst);

	int readedVersion = GetReadedVersion();
	if (0 == readedVersion)
	{
		source.ReadPointer(mTexReaded);
	}
	else if (1 == readedVersion)
	{
		source.ReadString(mTexturePathname);
	} 
	else if (2 == readedVersion)
	{
		source.ReadString(mTexturePathname);
		source.ReadString(mTexturePackName);
		source.ReadString(mElementName);
	}
	else if (3 <= readedVersion)
	{
		source.ReadString(mTexturePathname);
		source.ReadString(mTexturePackName);
		source.ReadString(mElementName);
		source.ReadEnum(mTexMode);
	}

	if (readedVersion <= 2)
	{
		if (mTexturePackName.empty() && mElementName.empty())
		{
			mTexMode = TM_TEX;
		}
		else
		{
			mTexMode = TM_TEXPACK_ELE;
		}
	}

	if (4 <= readedVersion)
	{
		source.ReadPointer(mUIMtlUV3);
		source.ReadPointer(mUIMtlInstUV3);
		source.ReadPointer(mAddedColorFloat);

		source.ReadBool(mIsUseAddedMask);
		source.ReadString(mAddedTextureFilename);
		source.ReadAggregate(mAddedTextureColor);
		source.ReadAggregate(mAddedTextureUVSpeed);
		source.ReadAggregate(mAddedTextureUVSRepeat);
		source.Read(mAddedTextureAlphaSpeed);

		source.ReadString(mMaskTextureFilename);
		source.Read(mMaskTextureAlpha);
		source.Read(mMaskTextureAlphaSpeed);
	}

	if (5 <= readedVersion)
	{
		source.ReadBool(mIsUseDark);
		source.ReadPointer(mUIMtlDark);
		source.ReadPointer(mUIMtlInstDark);
	}

	if (6 <= readedVersion)
	{
		source.ReadPointer(mDarkScaleFloat);
		source.ReadAggregate(mDarkParam);
	}

	PX2_END_DEBUG_STREAM_LOAD(UIPicBox, source);
}
//----------------------------------------------------------------------------
void UIPicBox::Link (InStream& source)
{
	TriMesh::Link(source);

	source.ResolveLink(mUIMtl);
	source.ResolveLink(mUIMtlInst);

	int readedVersion = GetReadedVersion();
	if (0 == readedVersion)
	{
		source.ResolveLink(mTexReaded);
		mTexturePathname = mTexReaded->GetResourcePath();
	}

	if (4 <= readedVersion)
	{
		source.ResolveLink(mUIMtlUV3);
		source.ResolveLink(mUIMtlInstUV3);
		source.ResolveLink(mAddedColorFloat);
	}

	if (5 <= readedVersion)
	{
		source.ResolveLink(mUIMtlDark);
		source.ResolveLink(mUIMtlInstDark);
	}

	if (6 <= readedVersion)
	{
		source.ResolveLink(mDarkScaleFloat);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::PostLink ()
{
	TriMesh::PostLink();

	if (""!=mElementName && ""!=mTexturePackName)
	{
		SetTextureNoRecreateBuffer(mTexturePackName, mElementName);
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::Register (OutStream& target) const
{
	 if (TriMesh::Register(target))
	 {
		 target.Register(mUIMtl);
		 target.Register(mUIMtlInst);

		 target.Register(mUIMtlUV3);
		 target.Register(mUIMtlInstUV3);
		 target.Register(mAddedColorFloat);

		 target.Register(mUIMtlDark);
		 target.Register(mUIMtlInstDark);
		 target.Register(mDarkScaleFloat);

		 return true;
	 }

	 return false;
}
//----------------------------------------------------------------------------
void UIPicBox::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriMesh::Save(target);
	PX2_VERSION_SAVE(target);

	target.WriteEnum(mPicBoxType);
	target.WriteBool(mIsDynamic);
	target.WriteAggregate(mAnchorPoint);
	target.WriteAggregate(mSize);
	target.WriteAggregate(mCornerSize);
	target.WriteAggregate(mUV0);
	target.WriteAggregate(mUV1);
	target.WriteAggregate(mUV2);
	target.WriteAggregate(mUV3);
	target.WriteAggregate(mUVScale);
	target.WriteAggregate(mColor);
	target.WritePointer(mUIMtl);
	target.WritePointer(mUIMtlInst);
	target.WriteString(mTexturePathname);
	target.WriteString(mTexturePackName);
	target.WriteString(mElementName);
	target.WriteEnum(mTexMode);

	target.WritePointer(mUIMtlUV3);
	target.WritePointer(mUIMtlInstUV3);
	target.WritePointer(mAddedColorFloat);

	target.WriteBool(mIsUseAddedMask);
	target.WriteString(mAddedTextureFilename);
	target.WriteAggregate(mAddedTextureColor);
	target.WriteAggregate(mAddedTextureUVSpeed);
	target.WriteAggregate(mAddedTextureUVSRepeat);
	target.Write(mAddedTextureAlphaSpeed);

	target.WriteString(mMaskTextureFilename);
	target.Write(mMaskTextureAlpha);
	target.Write(mMaskTextureAlphaSpeed);

	target.WriteBool(mIsUseDark);
	target.WritePointer(mUIMtlDark);
	target.WritePointer(mUIMtlInstDark);
	target.WritePointer(mDarkScaleFloat);
	target.WriteAggregate(mDarkParam);

	PX2_END_DEBUG_STREAM_SAVE(UIPicBox, target);
}
//----------------------------------------------------------------------------
int UIPicBox::GetStreamingSize (Stream &stream) const
{
	int size = TriMesh::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += PX2_ENUMSIZE(mPicBoxType);
	size += PX2_BOOLSIZE(mIsDynamic);
	size += sizeof(mAnchorPoint),
	size += sizeof(mSize);
	size += sizeof(mCornerSize);
	size += sizeof(mUV0);
	size += sizeof(mUV1);
	size += sizeof(mUV2);
	size += sizeof(mUV3);
	size += sizeof(mUVScale);
	size += sizeof(mColor);
	size += PX2_POINTERSIZE(mUIMtl);
	size += PX2_POINTERSIZE(mUIMtlInst);

	if (Stream::ST_IN == stream.GetStreamType())
	{
		int readedVersion = GetReadedVersion();
		if (0 == readedVersion)
		{
			size += PX2_POINTERSIZE(mTexture);
		}
		else if (1 == readedVersion)
		{
			size += PX2_STRINGSIZE(mTexturePathname);
		}
		else if (2 == readedVersion)
		{
			size += PX2_STRINGSIZE(mTexturePathname);
			size += PX2_STRINGSIZE(mTexturePackName);
			size += PX2_STRINGSIZE(mElementName);
		}
		else if (3 <= readedVersion)
		{
			size += PX2_STRINGSIZE(mTexturePathname);
			size += PX2_STRINGSIZE(mTexturePackName);
			size += PX2_STRINGSIZE(mElementName);
			size += PX2_ENUMSIZE(mTexMode);
		}
	}
	else
	{
		size += PX2_STRINGSIZE(mTexturePathname);
		size += PX2_STRINGSIZE(mTexturePackName);
		size += PX2_STRINGSIZE(mElementName);
		size += PX2_ENUMSIZE(mTexMode);
	}

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();

		if (4 <= readedVersion)
		{
			size += PX2_POINTERSIZE(mUIMtlUV3);
			size += PX2_POINTERSIZE(mUIMtlInstUV3);
			size += PX2_POINTERSIZE(mAddedColorFloat);

			size += PX2_BOOLSIZE(mIsUseAddedMask);
			size += PX2_STRINGSIZE(mAddedTextureFilename);
			size += sizeof(mAddedTextureColor);
			size += sizeof(mAddedTextureUVSpeed);
			size += sizeof(mAddedTextureUVSRepeat);
			size += sizeof(mAddedTextureAlphaSpeed);

			size += PX2_STRINGSIZE(mMaskTextureFilename);
			size += sizeof(mMaskTextureAlpha);
			size += sizeof(mMaskTextureAlphaSpeed);
		}

		if (5 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsUseDark);
			size += PX2_BOOLSIZE(mUIMtlDark);
			size += PX2_BOOLSIZE(mUIMtlInstDark);
		}

		if (6 <= readedVersion)
		{
			size += PX2_POINTERSIZE(mDarkScaleFloat);
			size += sizeof(mDarkParam);
		}
	}
	else
	{
		size += PX2_POINTERSIZE(mUIMtlUV3);
		size += PX2_POINTERSIZE(mUIMtlInstUV3);
		size += PX2_POINTERSIZE(mAddedColorFloat);

		size += PX2_BOOLSIZE(mIsUseAddedMask);
		size += PX2_STRINGSIZE(mAddedTextureFilename);
		size += sizeof(mAddedTextureColor);
		size += sizeof(mAddedTextureUVSpeed);
		size += sizeof(mAddedTextureUVSRepeat);
		size += sizeof(mAddedTextureAlphaSpeed);

		size += PX2_STRINGSIZE(mMaskTextureFilename);
		size += sizeof(mMaskTextureAlpha);
		size += sizeof(mMaskTextureAlphaSpeed);

		size += PX2_BOOLSIZE(mIsUseDark);
		size += PX2_POINTERSIZE(mUIMtlDark);
		size += PX2_POINTERSIZE(mUIMtlInstDark);
		size += PX2_POINTERSIZE(mDarkScaleFloat);
		size += sizeof(mDarkParam);
	}

	return size;
}
//----------------------------------------------------------------------------
