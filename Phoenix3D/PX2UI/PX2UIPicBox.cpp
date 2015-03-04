// PX2UIPicBox.cpp

#include "PX2UIPicBox.hpp"
#include "PX2Renderer.hpp"
#include "PX2UIFrame.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2DynamicBufferManager.hpp"
#include "PX2Material.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, TriMesh, UIPicBox, 6);
PX2_IMPLEMENT_STREAM(UIPicBox);
PX2_IMPLEMENT_FACTORY(UIPicBox);
PX2_IMPLEMENT_DEFAULT_NAMES(TriMesh, UIPicBox);

//----------------------------------------------------------------------------
UIPicBox::UIPicBox(const std::string &filename, int isDynamicBuffer) :
mIsDynamic(isDynamicBuffer>0),
mPicBoxType(PBT_NORMAL),
mAnchorPoint(0.5f, 0.5f),
mSize(128.0f, 64.0f),
mCornerSize(10.0f, 10.0f),
mIsBufferNeedUpdate(true),
mTexMode(TM_TEX),
mTexturePathname(filename)
{
	_Init();

	MaterialInstance *mi = new0 MaterialInstance("Data/mtls/ui/ui.px2obj",
		"default", false);
	SetMaterialInstance(mi);

	SetTexture(mTexturePathname);
	Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(
		mTexturePathname));
	if (tex) SetSize((float)tex->GetWidth(), (float)tex->GetHeight());

	SetUVRepeat(Float2::UNIT);
}
//----------------------------------------------------------------------------
UIPicBox::UIPicBox(const std::string &packName, const std::string &eleName,
	int isDynamicBuffer) :
mIsDynamic(isDynamicBuffer>0),
mPicBoxType(PBT_NORMAL),
mAnchorPoint(0.5f, 0.5f),
mSize(128.0f, 64.0f),
mCornerSize(10.0f, 10.0f),
mIsBufferNeedUpdate(true),
mTexMode(TM_TEXPACK_ELE)
{
	_Init();

	MaterialInstance *mi = new0 MaterialInstance("Data/mtls/ui/ui.px2obj",
		"default", false);
	SetMaterialInstance(mi);

	SetTexture(packName, eleName);
	SetSize((float)mPackEle.W, (float)mPackEle.H);

	SetUVRepeat(Float2::UNIT);
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
	SetSize(Sizef(width, height));
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
	SetSize(Sizef(width, mSize.Height));
}
//----------------------------------------------------------------------------
void UIPicBox::SetHeight(float height)
{
	SetSize(Sizef(mSize.Width, height));
}
//----------------------------------------------------------------------------
void UIPicBox::MakeSizeWithTex()
{
	if (!mTexturePackName.empty() && !mElementName.empty())
	{
		SetSize((float)mPackEle.W, (float)mPackEle.H);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetColor(const Float3 &color)
{
	TriMesh::SetColor(color);

	GetShine()->Emissive = Float4(color[0], color[1], color[2], GetAlpha());
}
//----------------------------------------------------------------------------
void UIPicBox::SetAlpha(float alpha)
{
	TriMesh::SetAlpha(alpha);

	const Float3 &color = GetColor();
	GetShine()->Emissive = Float4(color[0], color[1], color[2], alpha);
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexture(const std::string &filename)
{
	Texture *texture = DynamicCast<Texture>(PX2_RM.BlockLoad(filename));
	if (texture)
	{
		if (mTexMode != TM_TEX)
		{
			mIsBufferNeedUpdate = true;
		}

		mTexMode = TM_TEX;

		mTexturePackName = "";
		mElementName = "";
		mTexturePathname = filename;

		GetMaterialInstance()->SetPixelTexture(0, "Sample0", texture);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetTexture(const std::string &texPackName,
	const std::string &eleName)
{
	ResourceManager::GetSingleton().AddTexPack(texPackName);
	mPackEle =
		ResourceManager::GetSingleton().GetTexPackElement(texPackName, eleName);

	if (!mPackEle.IsValid())
		return;

	Object *obj = ResourceManager::GetSingleton().BlockLoad(
		mPackEle.ImagePathFull);
	Texture2D *texture = DynamicCast<Texture2D>(obj);

	if (texture)
	{
		if (mTexMode != TM_TEXPACK_ELE)
		{
			mIsBufferNeedUpdate = true;
		}

		mTexMode = TM_TEXPACK_ELE;

		mElementName = eleName;
		mTexturePackName = texPackName;

		mTexturePathname = texture->GetResourcePath();
		GetMaterialInstance()->SetPixelTexture(0, "Sample0", texture);
	}
}
//----------------------------------------------------------------------------
void UIPicBox::SetUVRepeat(const Float2 &uvRepeat)
{
	ShaderFloat *constant = GetMaterialInstance()->GetPixelConstant(0, "UVParam");
	(*constant)[0] = uvRepeat[0];
	(*constant)[1] = uvRepeat[1];
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
	std::vector<Float2> uvs;
	uvs.push_back(Float2(0.0f, 0.0f));
	uvs.push_back(Float2(1.0f, 0.0f));
	uvs.push_back(Float2(0.0f, 1.0f));
	uvs.push_back(Float2(1.0f, 1.0f));

	if (TM_TEX == mTexMode)
	{
		/*_*/
	}
	else
	{
		if (mPackEle.IsValid())
		{
			float u0 = (float)mPackEle.X / (float)mPackEle.TexWidth;
			float u1 = (float)(mPackEle.X + mPackEle.W) / (float)mPackEle.TexWidth;
			float v0 = (float)(mPackEle.TexHeight - mPackEle.Y - mPackEle.H) / (float)mPackEle.TexHeight;
			float v1 = (float)(mPackEle.TexHeight - mPackEle.Y) / (float)mPackEle.TexHeight;

			if (PBT_NORMAL == mPicBoxType)
			{
				if (!mPackEle.Rolated)
				{
					uvs[0] = Float2(u0, v0);
					uvs[1] = Float2(u1, v0);
					uvs[2] = Float2(u0, v1);
					uvs[3] = Float2(u1, v1);
				}
				else
				{
					uvs[0] = Float2(u0, v1);
					uvs[1] = Float2(u0, v0);
					uvs[2] = Float2(u1, v1);
					uvs[3] = Float2(u1, v0);
				}
			}
			else
			{
				uvs[0] = Float2(u0, v0);
				uvs[1] = Float2(u1, v0);
				uvs[2] = Float2(u0, v1);
				uvs[3] = Float2(u1, v1);
			}
		}
	}

	UpdateVertexBuffer(elapsedTime, uvs);
	
	UpdateIndexBuffer();
}
//----------------------------------------------------------------------------
void UIPicBox::_Init()
{
	SetName("UIPicBox");
	SetRenderLayer(Renderable::RL_UI);

	SetPicBoxType(PBT_NORMAL);

	GetShine()->Emissive = Float4::WHITE;
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
}
//----------------------------------------------------------------------------
void UIPicBox::UpdateVertexBuffer(float elapsedTime, 
	const std::vector<Float2> &uvs)
{
	PX2_UNUSED(elapsedTime);

	float anchorWidth = mAnchorPoint[0] * mSize.Width;
	float anchorHeight = mAnchorPoint[1] * mSize.Height;

	if (PBT_NORMAL == mPicBoxType)
	{
		VertexBufferAccessor vba(GetVertexFormat(), GetVertexBuffer());

		vba.Position<Float3>(0) = Float3(0.0f - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.Position<Float3>(1) = Float3(mSize.Width - anchorWidth, 0.0f, 0.0f - anchorHeight);
		vba.Position<Float3>(2) = Float3(0.0f - anchorWidth, 0.0f, mSize.Height - anchorHeight);
		vba.Position<Float3>(3) = Float3(mSize.Width - anchorWidth, 0.0f, mSize.Height - anchorHeight);

		vba.TCoord<Float2>(0, 0) = uvs[0];
		vba.TCoord<Float2>(0, 1) = uvs[1];
		vba.TCoord<Float2>(0, 2) = uvs[2];
		vba.TCoord<Float2>(0, 3) = uvs[3];
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

		float u0 = uvs[0][0];
		float u1 = uvs[0][0] + corW;
		float u2 = uvs[1][0] - corW;
		float u3 = uvs[1][0];

		float v0 = uvs[0][1];
		float v1 = uvs[0][1] + corH;
		float v2 = uvs[2][1] - corH;
		float v3 = uvs[2][1];

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
	}

	UpdateModelSpace(GU_MODEL_BOUND_ONLY);

	if (Renderer::IsOneBind(GetVertexBuffer()))
	{
		Renderer::UpdateAll(GetVertexBuffer());
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

	if (Renderer::IsOneBind(GetVertexBuffer()))
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
	VertexFormat *vFormat = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PT1);
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
void UIPicBox::OnForceBind()
{
	if (mIsBufferNeedUpdate)
	{
		UpdateBuffers(0.0f);

		mIsBufferNeedUpdate = false;
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

	AddProperty("AnchorPoint", PT_FLOAT2, GetAnchorPoint());
	AddProperty("Size", PT_SIZE, GetSize());;

	std::vector<std::string> texModes;
	texModes.push_back("TM_TEX");
	texModes.push_back("TM_TEXPACK_ELE");
	AddPropertyEnum("TexMode", (int)GetTexMode(), texModes);

	AddProperty("Tex", PT_STRINGBUTTON, mTexturePathname);
	AddProperty("TexPack_Ele", PT_STRINGBUTTON, mElementName);

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
	else if ("AnchorPoint" == obj.Name)
	{
		SetAnchorPoint(PX2_ANY_AS(obj.Data, Float2));
	}
	else if ("Size" == obj.Name)
	{
		SetSize(PX2_ANY_AS(obj.Data, Sizef));
	}
	else if ("TexCornerSize" == obj.Name)
	{
		SetTexCornerSize(PX2_ANY_AS(obj.Data, Sizef));
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

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
UIPicBox::UIPicBox(LoadConstructor value)
:
TriMesh(value),
mIsDynamic(false),
mPicBoxType(PBT_MAX_TYPE),
mAnchorPoint(0.5f, 0.5f),
mSize(128, 64),
mCornerSize(6, 6),
mIsBufferNeedUpdate(true),
mTexMode(TM_TEX)
{
}
//----------------------------------------------------------------------------
void UIPicBox::Load(InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	source.ReadBool(mIsDynamic);

	source.ReadEnum(mPicBoxType);
	source.ReadAggregate(mAnchorPoint),
	source.ReadAggregate(mSize);
	source.ReadAggregate(mCornerSize);

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
}
//----------------------------------------------------------------------------
void UIPicBox::PostLink()
{
	TriMesh::PostLink();

	if ("" != mElementName && "" != mTexturePackName)
	{
		SetTexture(mTexturePackName, mElementName);
	}
}
//----------------------------------------------------------------------------
bool UIPicBox::Register(OutStream& target) const
{
	if (TriMesh::Register(target))
	{
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

	target.WriteBool(mIsDynamic);

	target.WriteEnum(mPicBoxType);
	target.WriteAggregate(mAnchorPoint);
	target.WriteAggregate(mSize);
	target.WriteAggregate(mCornerSize);
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

	size += PX2_BOOLSIZE(mIsDynamic);

	size += PX2_ENUMSIZE(mPicBoxType);
	size += sizeof(mAnchorPoint),
	size += sizeof(mSize);
	size += sizeof(mCornerSize);

	size += PX2_STRINGSIZE(mTexturePathname);
	size += PX2_STRINGSIZE(mTexturePackName);
	size += PX2_STRINGSIZE(mElementName);
	size += PX2_ENUMSIZE(mTexMode);

	return size;
}
//----------------------------------------------------------------------------
