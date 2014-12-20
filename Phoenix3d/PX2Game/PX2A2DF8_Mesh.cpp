/*
*
* 文件名称	：	PX2A2DF8_Mesh.cpp
*
*/

#include "PX2A2DF8_Mesh.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Texture2DMaterial.hpp"
#include "PX2GameManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, TriMesh, A2DF8_Mesh);
PX2_IMPLEMENT_STREAM(A2DF8_Mesh);
PX2_IMPLEMENT_FACTORY(A2DF8_Mesh);
PX2_IMPLEMENT_DEFAULT_NAMES(TriMesh, A2DF8_Mesh);

//----------------------------------------------------------------------------
A2DF8_Mesh::A2DF8_Mesh ()
	:
mNumAllFrames(0),
mNumFramesPerDir(0),
mIsPlayOnce(true),
mPlayOnceTime(1.0f),
mInterval(0.1f),
mSize(2.0f),
mIsCaled(false),
mAnimPlayedTime(0.0f),
mLastAppTime(-1.0f),
mIsPlaying(false)
{
	mModelBound.SetCenter(APoint::ORIGIN);
	mModelBound.SetRadius(3.0f);
}
//----------------------------------------------------------------------------
A2DF8_Mesh::~A2DF8_Mesh ()
{
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::SetInterval (float interval)
{
	mInterval = interval;
	mPlayOnceTime = mNumFramesPerDir*mInterval;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::SetPlayOnce (bool once)
{
	mIsPlayOnce = once;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::SetSize (float size)
{
	mSize = size;
}
//----------------------------------------------------------------------------
int A2DF8_Mesh::SetTexPack (const std::string &texPackFilename)
{
	mTexPackFilename = texPackFilename;

	PX2_RM.AddTexPack(texPackFilename);
	const TexPack &texPack = PX2_RM.GetTexPack(texPackFilename);
	if (!texPack.IsValid())
		return 0;
	
	mNumAllFrames = (int)texPack.Elements.size();
	mNumFramesPerDir = mNumAllFrames/8;
	mPlayOnceTime = mNumFramesPerDir*mInterval;

	return mNumFramesPerDir;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Cal (const std::string &texPackFilename)
{
	const TexPack &texPack = PX2_RM.GetTexPack(texPackFilename);
	if (!texPack.IsValid())
		return;

	std::string outPath;
	std::string outBaseFilename;
	StringHelp::SplitFilename (texPackFilename, outPath, outBaseFilename);

	std::string outBaseName;
	std::string outExt;
	StringHelp::SplitBaseFilename (outBaseFilename,	outBaseName, outExt);

	VertexFormat *vf = PX2_GM.GetVertexFormatUser();
	SetVertexFormat(vf);

	mNumAllFrames = (int)texPack.Elements.size();
	mNumFramesPerDir = mNumAllFrames/8;

	UBIBObj obj = PX2_GM.GetVBID(texPackFilename);
	if (obj.IsValued)
	{
		SetVertexBuffer(obj.mVB);
		SetIndexBuffer(obj.mIB);
	}
	else
	{
		int numVertex = mNumAllFrames * 4;
		int numIndex = mNumAllFrames*6;

		int frameIndex = 0;
		VertexBuffer *vb = new0 VertexBuffer(numVertex, vf->GetStride());
		VertexBufferAccessor vba(vf, vb);
		for (int i=0; i<8; i++)
		{
			for (int j=0; j<mNumFramesPerDir; j++)
			{
				std::string eleName = outBaseName + "_" + StringHelp::IntToString(i*45) + "_" + StringHelp::IntToString(j+1);

				const TexPackElement &ele = PX2_RM.GetTexPackElement(texPackFilename, eleName);

				float xPlusPer = 0.0f;
				float widthPer = 0.0f;
				float zPlusPer = 0.0f;
				float heightPer = 0.0f;
				if (0 != ele.OW)
				{
					xPlusPer = (float)ele.OX / (float)ele.OW;
					widthPer = (float)ele.W	/(float)ele.OW;
				}
				if (0 != ele.OH)
				{
					zPlusPer = 1.0f - (float)(ele.OY+ele.H)	/ (float)ele.OH;
					heightPer = (float)ele.H /(float)ele.OH;
				}

				float width = mSize;
				float height = mSize;

				float xPos = 0.0f - width * 0.5f;
				float zPos = 0.0f - height * 0.5f;
				xPos += xPlusPer * width;
				zPos += zPlusPer * height;	

				width *= widthPer;
				height *= heightPer;

				Float3 p0 = Float3(xPos,		zPos,			0.0f);
				Float3 p1 = Float3(xPos+width,	zPos,			0.0f);
				Float3 p2 = Float3(xPos,		zPos+height,	0.0f);
				Float3 p3 = Float3(xPos+width,	zPos+height,	0.0f);

				float uBegin = (float)ele.X/(float)ele.TexWidth;
				float uEnd = (float)(ele.X+ele.W)/(float)ele.TexWidth;
				float vBegin = (float)(ele.TexHeight-ele.Y-ele.H)/(float)ele.TexHeight;
				float vEnd = (float)(ele.TexHeight-ele.Y)/(float)ele.TexHeight;

				vba.Position<Float3>(frameIndex*4+0) = p0;
				vba.Position<Float3>(frameIndex*4+1) = p1;
				vba.Position<Float3>(frameIndex*4+2) = p2;
				vba.Position<Float3>(frameIndex*4+3) = p3;

				vba.TCoord<Float2>(0, frameIndex*4+0) = Float2(uBegin, vBegin);
				vba.TCoord<Float2>(0, frameIndex*4+1) = Float2(uEnd, vBegin);
				vba.TCoord<Float2>(0, frameIndex*4+2) = Float2(uBegin, vEnd);
				vba.TCoord<Float2>(0, frameIndex*4+3) = Float2(uEnd, vEnd);

				frameIndex++;
			}
		}

		IndexBuffer *ib = new0 IndexBuffer(numIndex, 2);
		for (int i=0; i<mNumAllFrames; i++)
		{
			unsigned short *indices = (unsigned short*)ib->GetData();
			indices[i*6+0] = i*4+0;
			indices[i*6+1] = i*4+1;
			indices[i*6+2] = i*4+2;
			indices[i*6+3] = i*4+1;
			indices[i*6+4] = i*4+3;
			indices[i*6+5] = i*4+2;
		}

		SetVertexBuffer(vb);
		SetIndexBuffer(ib);

		PX2_GM.AddVBIB(texPackFilename, vb, ib);
	}

	Texture2D *tex = (Texture2D*)PX2_RM.BlockLoad(texPack.ImageFullPath);
	MaterialInstance *mi = PX2_GM.GetMaterialUser()->CreateInstance(tex);
	SetMaterialInstance(mi);

	mPlayOnceTime = mNumFramesPerDir * mInterval;

	mIsCaled = true;
}
//----------------------------------------------------------------------------
int A2DF8_Mesh::GetNumFramesPerDir () const
{
	return mNumFramesPerDir;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::SetWorldRunDir (const AVector &vec)
{
	mCurDir = vec;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Play ()
{
	mIsPlaying = true;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Stop ()
{
	mIsPlaying = false;
	mLastAppTime = -1;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Reset ()
{
	TriMesh::Reset();

	mLastAppTime = -1.0f;
	mAnimPlayedTime = 0.0f;
}
//----------------------------------------------------------------------------
bool A2DF8_Mesh::IsPlaying ()
{
	return mIsPlaying;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::UpdateWorldData (double applicationTime)
{
	TriMesh::UpdateWorldData(applicationTime);

	float elapsedTime = 0.0f;
	if (-1.0f == mLastAppTime)
	{
		mLastAppTime = applicationTime;
	}
	else
	{
		elapsedTime = (float)(applicationTime - mLastAppTime);
		mLastAppTime = applicationTime;
	}

	if (!mIsPlaying)
		return;

	mAnimPlayedTime += elapsedTime;

	if (mAnimPlayedTime > mPlayOnceTime)
	{
		if (mIsPlayOnce)
		{
			Stop();
			mAnimPlayedTime = mPlayOnceTime;
		}
		else
			mAnimPlayedTime = 0.0f;
	}

	if (!mIsCaled)
	{
		Cal(mTexPackFilename);
	}

	CalFrame();
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::CalFrame ()
{
	IndexBuffer *ib = GetIndexBuffer();
	if (!ib)
		return;

	int index = GetDirIndex(mCurDir);

	int index1 = (int)(mAnimPlayedTime/mInterval);
	if (index1 >= mNumFramesPerDir)
		index1 = mNumFramesPerDir-1;

	int frameIndex = index * mNumFramesPerDir + index1;

	SetIBOffset(6*frameIndex);
	SetIBNumElements(6);
}
//----------------------------------------------------------------------------
int A2DF8_Mesh::GetDirIndex (const AVector &dir)
{
	AVector animVec = dir;
	animVec.Normalize();

	AVector up = AVector::UNIT_Y;
	float dotVal = up.Dot(animVec);

	float rad = Mathf::ACos(dotVal);
	float degree = Mathf::RAD_TO_DEG * rad;
	bool isRight = (dir.X()>0.0f);

	if (0<=degree && degree<22.5f)
	{
		return 0;
	}
	else if (22.5f<=degree && degree<67.5f)
	{
		if (isRight)
			return 1;
		else
			return 7;
	}
	else if (67.5<=degree && degree<112.5f)
	{
		if (isRight)
			return 2;
		else
			return 6;
	}
	else if (112.5f<=degree && degree<157.5f)
	{
		if (isRight)
			return 3;
		else 
			return 5;
	}
	else if (157.5f<=degree && degree<=180.0f)
	{
		return 4;
	}

	return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化支持
//----------------------------------------------------------------------------
A2DF8_Mesh::A2DF8_Mesh (LoadConstructor value)
	:
TriMesh(value),
	mNumAllFrames(0),
	mNumFramesPerDir(0),
	mIsPlayOnce(true),
	mPlayOnceTime(1.0f),
	mInterval(0.1f),
	mSize(2.0f),
	mIsCaled(false),
	mAnimPlayedTime(0.0f),
	mLastAppTime(-1.0f),
	mIsPlaying(false)
{
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TriMesh::Load(source);
	PX2_VERSION_LOAD(source);

	PX2_END_DEBUG_STREAM_LOAD(A2DF8_Mesh, source);
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Link (InStream& source)
{
	TriMesh::Link(source);
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::PostLink ()
{
	TriMesh::PostLink();
}
//----------------------------------------------------------------------------
bool A2DF8_Mesh::Register (OutStream& target) const
{
	if (TriMesh::Register(target))
	{
		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void A2DF8_Mesh::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TriMesh::Save(target);
	PX2_VERSION_SAVE(target);

	PX2_END_DEBUG_STREAM_SAVE(A2DF8_Mesh, target);
}
//----------------------------------------------------------------------------
int A2DF8_Mesh::GetStreamingSize (Stream &stream) const
{
	int size = TriMesh::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	return size;
}
//----------------------------------------------------------------------------