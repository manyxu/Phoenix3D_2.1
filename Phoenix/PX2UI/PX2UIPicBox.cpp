// PX2UIPicBox.cpp

#include "PX2UIPicBox.hpp"
#include "PX2Renderer.hpp"
#include "PX2UIManager.hpp"
#include "PX2UIFrame.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2DynamicBufferManager.hpp"
#include "PX2Material.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, TriMesh, UIPicBox, 6);
PX2_IMPLEMENT_STREAM(UIPicBox);
PX2_IMPLEMENT_FACTORY(UIPicBox);

//----------------------------------------------------------------------------
UIPicBox::UIPicBox(const std::string &filename)
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
UIPicBox::UIPicBox(const std::string &packName, const std::string &eleName)
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
mIsMtlNeedUpdate(true)
{
	_Init();

	SetTexMode(TM_TEXPACK_ELE);
	SetTexture(packName, eleName);
	SetSize((float)mPackEle.W, (float)mPackEle.H);
}
//----------------------------------------------------------------------------
UIPicBox::~UIPicBox()
{
}
//----------------------------------------------------------------------------
void UIPicBox::SetPicBoxType(PicBoxType type)
{
	mPicBoxType = type;

	ReCreateVBuffer();

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetDynamic(bool dyn)
{
	mIsDynamic = dyn;
	SetPicBoxType(mPicBoxType);
}
//----------------------------------------------------------------------------
void UIPicBox::SetAnchorPoint(float anchX, float anchZ)
{
	SetAnchorPoint(Float2(anchX, anchZ));
}
//----------------------------------------------------------------------------
void UIPicBox::SetAnchorPoint(Float2 anchor)
{
	mAnchorPoint = anchor;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetSize(float width, float height)
{
	mSize.Width = width;
	mSize.Height = height;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetSize(const Sizef &size)
{
	mSize = size;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetWidth(float width)
{
	mSize.Width = width;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetHeight(float height)
{
	mSize.Height = height;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::MakeSizeWithTex()
{
	if (!mTexturePackName.empty() && !mElementName.empty())
	{
		mSize.Width = (float)mPackEle.W;
		mSize.Height = (float)mPackEle.H;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetColor(const Float3 &color)
{
	TriMesh::SetColor(color);

	mColor[0] = color[0];
	mColor[1] = color[1];
	mColor[2] = color[2];

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetAlpha(float alpha)
{
	TriMesh::SetAlpha(alpha);

	mColor[3] = alpha;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVScaleX(float xScale)
{
	mUVScale[0] = xScale;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVScaleY(float yScale)
{
	mUVScale[1] = yScale;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVScale(Float2 uvScale)
{
	mUVScale = uvScale;

	mIsBufferNeedUpdate = true;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexMode(TexMode mode)
{
	mTexMode = mode;
}
//----------------------------------------------------------------------------
UIPicBox::TexMode UIPicBox::GetTexMode() const
{
	return mTexMode;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexture(Texture2D *tex)
{
	mTexturePackName = "";
	mElementName = "";

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
//----------------------------------------------------------------------------
void UIPicBox::SetTexture(const std::string &filename)
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
void UIPicBox::SetTexture(const std::string &texPackName,
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

		float u0 = (float)mPackEle.X / (float)mPackEle.TexWidth;
		float u1 = (float)(mPackEle.X + mPackEle.W) / (float)mPackEle.TexWidth;
		float v0 = (float)(mPackEle.TexHeight - mPackEle.Y - mPackEle.H) / (float)mPackEle.TexHeight;
		float v1 = (float)(mPackEle.TexHeight - mPackEle.Y) / (float)mPackEle.TexHeight;

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
Texture2D *UIPicBox::GetTexture()
{
	return DynamicCast<Texture2D>(ResourceManager::GetSingleton().BlockLoad(
		mTexturePathname));
}
//----------------------------------------------------------------------------
void UIPicBox::SetDoubleSide(bool d)
{
	if (mUIMtl)
	{
		mUIMtl->GetCullProperty(0, 0)->Enabled = !d;
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::IsDoubleSide() const
{
	if (mUIMtl)
	{
		return (!mUIMtl->GetCullProperty(0, 0)->Enabled);
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUseAlphaTest(bool use)
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
//----------------------------------------------------------------------------
bool UIPicBox::IsUseAlphaText() const
{
	if (mUIMtl)
	{
		return (!mUIMtl->GetAlphaProperty(0, 0)->BlendEnabled);
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetFliterPoint(bool point)
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
bool UIPicBox::IsFliterPoint() const
{
	if (mUIMtl)
	{
		return (Shader::SF_NEAREST == mUIMtl->GetPixelShader()->GetFilter(0));
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetUseClamp(bool clamp)
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
bool UIPicBox::IsUseClamp() const
{
	if (mUIMtl)
	{
		return (Shader::SC_CLAMP == mUIMtl->GetPixelShader()->GetCoordinate(0, 0));
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerSize(float width, float height)
{
	mCornerSize.Width = width;
	mCornerSize.Height = height;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerSize(const Sizef &size)
{
	mCornerSize = size;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerWidth(float width)
{
	mCornerSize.Width = width;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexCornerHeight(float height)
{
	mCornerSize.Height = height;

	if (mPicBoxType == PBT_NINE)
	{
		mIsBufferNeedUpdate = true;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateBuffers(float elapsedTime)
{
	UpdateVertexBuffer(elapsedTime);
	UpdateIndexBuffer();
}
//----------------------------------------------------------------------------
void UIPicBox::_Init()
{
	SetName("UIPicBox");
	SetRenderLayer(Renderable::RL_UI);

	SetPicBoxType(PBT_NORMAL);

	mUIMtl = new0 UIMaterial();
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateWorldData(double applicationTime)
{
	TriMesh::UpdateWorldData(applicationTime);

	if (mIsBufferNeedUpdate)
	{
		UpdateBuffers(0.0f);

		mIsBufferNeedUpdate = false;
	}

	if (mIsMtlNeedUpdate)
	{
		UpdateMtl();

		mIsMtlNeedUpdate = false;
	}
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateVertexBuffer(float elapsedTime)
{
	float anchorWidth = mAnchorPoint[0] * mSize.Width;
	float anchorHeight = mAnchorPoint[1] * mSize.Height;

	if (PBT_NORMAL == mPicBoxType)
	{
		VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

		vba.Position<Float3>(0) = Float3(0.0f - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.Position<Float3>(1) = Float3(mSize.Width - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.Position<Float3>(2) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.Position<Float3>(3) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - anchorHeight);

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
			widthPerc = mSize.Width / (mCornerSize.Width*2.0f);
		}
		cornerWidth *= widthPerc;

		float heightPerc = 1.0f;
		if (mSize.Height < mCornerSize.Height*2.0f)
		{
			heightPerc = mSize.Height / (mCornerSize.Height*2.0f);
		}
		cornerHeight *= heightPerc;

		float corW = cornerWidth / texWidth;
		float corH = cornerHeight / texHeight;

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

		vba.Position<Float3>(0) = Float3(0.0f - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, 0) = uv[0];
		vba.Position<Float3>(1) = Float3(cornerWidth - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, 1) = uv[1];
		vba.Position<Float3>(2) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, 2) = uv[2];
		vba.Position<Float3>(3) = Float3(mSize.Width - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, 3) = uv[3];
		vba.Position<Float3>(4) = Float3(0.0f - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 4) = uv[4];
		vba.Position<Float3>(5) = Float3(cornerWidth - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 5) = uv[5];
		vba.Position<Float3>(6) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 6) = uv[6];
		vba.Position<Float3>(7) = Float3(mSize.Width - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 7) = uv[7];
		vba.Position<Float3>(8) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 8) = uv[8];
		vba.Position<Float3>(9) = Float3(cornerWidth - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 9) = uv[9];
		vba.Position<Float3>(10) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 10) = uv[10];
		vba.Position<Float3>(11) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, 11) = uv[11];
		vba.Position<Float3>(12) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, 12) = uv[12];
		vba.Position<Float3>(13) = Float3(cornerWidth - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, 13) = uv[13];
		vba.Position<Float3>(14) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, 14) = uv[14];
		vba.Position<Float3>(15) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, 15) = uv[15];

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
void UIPicBox::UpdateDynBuffers(float elapsedTime)
{
	PX2_UNUSED(elapsedTime);

	float anchorWidth = mAnchorPoint[0] * mSize.Width;
	float anchorHeight = mAnchorPoint[1] * mSize.Height;

	if (PBT_NORMAL == mPicBoxType)
	{
		DBObject_V *objV = PX2_DBM.AllocVertexBuffer(4);
		SetShareDBObject_V(objV);
		DBObject_I *objI = PX2_DBM.AllocIndexBuffer(6);
		SetShareDBObject_I(objI);

		VertexBufferAccessor vba(GetVertexFormat(), objV->Buf);

		vba.Position<Float3>(objV->Offset + 0) = Float3(0.0f - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.Position<Float3>(objV->Offset + 1) = Float3(mSize.Width - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.Position<Float3>(objV->Offset + 2) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.Position<Float3>(objV->Offset + 3) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - anchorHeight);

		vba.Color<Float4>(0, objV->Offset + 0) = mColor;
		vba.Color<Float4>(0, objV->Offset + 1) = mColor;
		vba.Color<Float4>(0, objV->Offset + 2) = mColor;
		vba.Color<Float4>(0, objV->Offset + 3) = mColor;
		vba.TCoord<Float2>(0, objV->Offset + 0)[0] = mUV0[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset + 0)[1] = mUV0[1] * mUVScale[1];
		vba.TCoord<Float2>(0, objV->Offset + 1)[0] = mUV1[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset + 1)[1] = mUV1[1] * mUVScale[1];
		vba.TCoord<Float2>(0, objV->Offset + 2)[0] = mUV2[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset + 2)[1] = mUV2[1] * mUVScale[1];
		vba.TCoord<Float2>(0, objV->Offset + 3)[0] = mUV3[0] * mUVScale[0];
		vba.TCoord<Float2>(0, objV->Offset + 3)[1] = mUV3[1] * mUVScale[1];

		unsigned short *indices = (unsigned short*)objI->Buf->GetData();
		indices += objI->Offset;

		unsigned short v0 = (unsigned short)(objV->Offset + 0);
		unsigned short v1 = (unsigned short)(objV->Offset + 1);
		unsigned short v2 = (unsigned short)(objV->Offset + 2);
		unsigned short v3 = (unsigned short)(objV->Offset + 3);

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
			widthPerc = mSize.Width / (mCornerSize.Width*2.0f);
		}
		cornerWidth *= widthPerc;

		float heightPerc = 1.0f;
		if (mSize.Height < mCornerSize.Height*2.0f)
		{
			heightPerc = mSize.Height / (mCornerSize.Height*2.0f);
		}
		cornerHeight *= heightPerc;

		float corW = cornerWidth / texWidth;
		float corH = cornerHeight / texHeight;

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

		vba.Position<Float3>(objV->Offset + 0) = Float3(0.0f - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 0) = uv[0];
		vba.Position<Float3>(objV->Offset + 1) = Float3(cornerWidth - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 1) = uv[1];
		vba.Position<Float3>(objV->Offset + 2) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 2) = uv[2];
		vba.Position<Float3>(objV->Offset + 3) = Float3(mSize.Width - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 3) = uv[3];
		vba.Position<Float3>(objV->Offset + 4) = Float3(0.0f - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 4) = uv[4];
		vba.Position<Float3>(objV->Offset + 5) = Float3(cornerWidth - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 5) = uv[5];
		vba.Position<Float3>(objV->Offset + 6) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 6) = uv[6];
		vba.Position<Float3>(objV->Offset + 7) = Float3(mSize.Width - anchorWidth, 0.0f, cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 7) = uv[7];
		vba.Position<Float3>(objV->Offset + 8) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 8) = uv[8];
		vba.Position<Float3>(objV->Offset + 9) = Float3(cornerWidth - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 9) = uv[9];
		vba.Position<Float3>(objV->Offset + 10) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 10) = uv[10];
		vba.Position<Float3>(objV->Offset + 11) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - cornerHeight - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 11) = uv[11];
		vba.Position<Float3>(objV->Offset + 12) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 12) = uv[12];
		vba.Position<Float3>(objV->Offset + 13) = Float3(cornerWidth - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 13) = uv[13];
		vba.Position<Float3>(objV->Offset + 14) = Float3(mSize.Width - cornerWidth - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 14) = uv[14];
		vba.Position<Float3>(objV->Offset + 15) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.TCoord<Float2>(0, objV->Offset + 15) = uv[15];

		vba.Color<Float4>(0, objV->Offset + 0) = mColor;
		vba.Color<Float4>(0, objV->Offset + 1) = mColor;
		vba.Color<Float4>(0, objV->Offset + 2) = mColor;
		vba.Color<Float4>(0, objV->Offset + 3) = mColor;
		vba.Color<Float4>(0, objV->Offset + 4) = mColor;
		vba.Color<Float4>(0, objV->Offset + 5) = mColor;
		vba.Color<Float4>(0, objV->Offset + 6) = mColor;
		vba.Color<Float4>(0, objV->Offset + 7) = mColor;
		vba.Color<Float4>(0, objV->Offset + 8) = mColor;
		vba.Color<Float4>(0, objV->Offset + 9) = mColor;
		vba.Color<Float4>(0, objV->Offset + 10) = mColor;
		vba.Color<Float4>(0, objV->Offset + 11) = mColor;
		vba.Color<Float4>(0, objV->Offset + 12) = mColor;
		vba.Color<Float4>(0, objV->Offset + 13) = mColor;
		vba.Color<Float4>(0, objV->Offset + 14) = mColor;
		vba.Color<Float4>(0, objV->Offset + 15) = mColor;

		unsigned short *indices = (unsigned short*)objI->Buf->GetData();
		indices += objI->Offset;
		for (unsigned short j = 0; j < 3; j++)
		{
			for (unsigned short i = 0; i < 3; i++)
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
void UIPicBox::UpdateIndexBuffer()
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
		for (unsigned short j = 0; j < 3; j++)
		{
			for (unsigned short i = 0; i < 3; i++)
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
void UIPicBox::OnPicked(int info)
{
	UIFrame *frame = DynamicCast<UIFrame>(GetParent());
	if (frame)
	{
		frame->OnChildPicked(info, this);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::OnNotPicked(int pickInfo)
{
	PX2_UNUSED(pickInfo);
}
//----------------------------------------------------------------------------
void UIPicBox::ReCreateVBuffer()
{
	VertexFormat *vFormat = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PCT1);
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
void UIPicBox::UpdateMtl()
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
//----------------------------------------------------------------------------
void UIPicBox::OnForceBind()
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
void UIPicBox::UIAfterPicked(int info)
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
void UIPicBox::RegistProperties()
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
}
//----------------------------------------------------------------------------
void UIPicBox::OnPropertyChanged(const PropertyObject &obj)
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
	else if ("Tex" == obj.Name && mTexMode == TM_TEX)
	{
		SetTexture(PX2_ANY_AS(obj.Data, std::string));
	}
	else if ("TexPack_Ele" == obj.Name && mTexMode == TM_TEXPACK_ELE)
	{
		SetTexture(PX2_ANY_AS(obj.Data1, std::string),
			PX2_ANY_AS(obj.Data, std::string));
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTextureNoRecreateBuffer(const std::string &texPackName,
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

		float u0 = (float)mPackEle.X / (float)mPackEle.TexWidth;
		float u1 = (float)(mPackEle.X + mPackEle.W) / (float)mPackEle.TexWidth;
		float v0 = (float)(mPackEle.TexHeight - mPackEle.Y - mPackEle.H) / (float)mPackEle.TexHeight;
		float v1 = (float)(mPackEle.TexHeight - mPackEle.Y) / (float)mPackEle.TexHeight;

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
Object* UIPicBox::GetObjectByName(const std::string& name)
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
void UIPicBox::GetAllObjectsByName(const std::string& name,
	std::vector<Object*>& objects)
{
	TriMesh::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mUIMtl, name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIPicBox::UIPicBox(LoadConstructor value)
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
mIsMtlNeedUpdate(true)
{
}
//----------------------------------------------------------------------------
void UIPicBox::Load(InStream& source)
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

	source.ReadString(mTexturePathname);
	source.ReadString(mTexturePackName);
	source.ReadString(mElementName);
	source.ReadEnum(mTexMode);

	if (mTexturePackName.empty() && mElementName.empty())
	{
		mTexMode = TM_TEX;
	}
	else
	{
		mTexMode = TM_TEXPACK_ELE;
	}

	PX2_END_DEBUG_STREAM_LOAD(UIPicBox, source);
}
//----------------------------------------------------------------------------
void UIPicBox::Link(InStream& source)
{
	TriMesh::Link(source);

	source.ResolveLink(mUIMtl);
	source.ResolveLink(mUIMtlInst);
}
//----------------------------------------------------------------------------
void UIPicBox::PostLink()
{
	TriMesh::PostLink();

	if ("" != mElementName && "" != mTexturePackName)
	{
		SetTextureNoRecreateBuffer(mTexturePackName, mElementName);
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::Register(OutStream& target) const
{
	if (TriMesh::Register(target))
	{
		target.Register(mUIMtl);
		target.Register(mUIMtlInst);

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void UIPicBox::Save(OutStream& target) const
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

	PX2_END_DEBUG_STREAM_SAVE(UIPicBox, target);
}
//----------------------------------------------------------------------------
int UIPicBox::GetStreamingSize(Stream &stream) const
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

	size += PX2_STRINGSIZE(mTexturePathname);
	size += PX2_STRINGSIZE(mTexturePackName);
	size += PX2_STRINGSIZE(mElementName);
	size += PX2_ENUMSIZE(mTexMode);

	return size;
}
//----------------------------------------------------------------------------
