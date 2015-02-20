/*
*
* 文件名称	：	PX2LODTerrainPage.cpp
*
*/

#include "PX2LODTerrainPage.hpp"
#include "PX2LODTerrainBlock.hpp"
#include "PX2LODTerrainVertex.hpp"
#include "PX2GraphicsRoot.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, TerrainPage, LODTerrainPage);
PX2_IMPLEMENT_STREAM(LODTerrainPage);
PX2_IMPLEMENT_FACTORY(LODTerrainPage);
PX2_IMPLEMENT_DEFAULT_NAMES(TerrainPage, LODTerrainPage);

//----------------------------------------------------------------------------
LODTerrainPage::LODTerrainPage(VertexFormat* vformat, int size, float* heights,
	const Float2& origin, float spacing)
	:
TerrainPage(size, heights, origin, spacing),
mTextureSpacing(1.0f),
mPixelTolerance(1.0f),
mWorldTolerance(-1.0f),// 必须被初始化为-1，后面需要使用
mNeedsTessellation(false),
mLookup(0),
mVertexs(0),
mTotalVQuantity(0),
mTotalTQuantity(0),
mTotalIQuantity(0),
mBlockQuantity(0),
mBlocks(0),
mQueue(0),
mNumQueue(0),
mFront(0),
mBack(0),
mNumUnprocessed(0),
mItemsInQueue(0)
{
	SetVertexFormat(vformat);

	// 顶点
	mTotalVQuantity = mSize*mSize; // 最多顶点数量
	mVBuffer = new0 VertexBuffer(mTotalVQuantity, mVFormat->GetStride(),
		Buffer::BU_DYNAMIC);

	// 顶点索引
	mTotalTQuantity = 2*(mSize-1)*(mSize-1);
	mTotalIQuantity = 3*mTotalTQuantity;
	mIBuffer = new0 IndexBuffer(mTotalIQuantity, sizeof(int), Buffer::BU_DYNAMIC);

	mVBA.ApplyTo(mVFormat, mVBuffer);

	int numVertices = mVBuffer->GetNumElements();
	for (int i = 0; i < numVertices; ++i)
	{
		int x = i % mSize;
		int y = i / mSize;
		mVBA.Position<Float3>(i) = Float3(GetX(x), GetY(y), GetHeight(i));
		mVBA.Normal<Float3>(i) = Float3(0.0f, 0.0f, 1.0f);
		mVBA.Color<Float3>(0, i) = Float3(0.0f, 0.0f, 0.0f);
	}
	mIBuffer->SetNumElements(0);

	UpdateModelSpace(Renderable::GU_MODEL_BOUND_ONLY);
	UpdateModelSpace(Renderable::GU_NORMALS);

	InitializeDerivedData();
}
//----------------------------------------------------------------------------
LODTerrainPage::~LODTerrainPage ()
{
	delete1(mHeights);
	delete1(mVertexs);
	delete1(mBlocks);
	delete1(mQueue);
	delete1(mLookup);
}
//----------------------------------------------------------------------------
void LODTerrainPage::InitializeDerivedData ()
{
	// do it again
	mTotalVQuantity = mSize*mSize;
	mTotalTQuantity = 2*(mSize-1)*(mSize-1);
	mTotalIQuantity = 3*mTotalTQuantity;
	mVBA.ApplyTo(mVFormat, mVBuffer);

	mLookup = new1<int>(mTotalVQuantity);

	// 初始化顶点信息数组
	mVertexs = new1<LODTerrainVertex>(mTotalVQuantity);
	memset(mVertexs, 0, mTotalVQuantity*sizeof(LODTerrainVertex));

	// 分配block的quadtree
	mBlockQuantity = mSize*(mSize-2)/3;
	mBlocks = new1<LODTerrainBlock>(mBlockQuantity);

	// 初始化quadtree
	int stride = (mSize-1)/2;
	mBlocks[0].Initialize(this, mBlocks, 0, 0, 0, stride, true);
	mBlocks[0].UpdateBoundingBox(this, mBlocks, 0, stride);

	// 根据最顶层block“坐标轴向包围”合计算地形页包围盒
	APoint center = 0.5f*(mBlocks[0].GetMax() + mBlocks[0].GetMin());
	AVector diag = 0.5f*(mBlocks[0].GetMax() - mBlocks[0].GetMin());
	mModelBound.SetCenter(center);
	mModelBound.SetRadius(diag.Length());

	// 分配queue
	mNumQueue = (unsigned short)(mBlockQuantity - mBlockQuantity/4);
	mQueue = new1<unsigned short>((int)mNumQueue);

	// 根quadtree被初始化激活
	mQueue[0] = 0;
	mFront = 0;
	mBack = 1;
	mItemsInQueue = 1;

	mNeedsTessellation = true;
}
//----------------------------------------------------------------------------
void LODTerrainPage::SetPixelTolerance (float tolerance)
{
	const Rectf &rect = GraphicsRoot::GetSingleton().GetViewRect();
	const Camera *cam = GraphicsRoot::GetSingleton().GetCamera();

	float rMax = cam->GetRMax();
	float dMin = cam->GetDMin();

	mPixelTolerance = tolerance;
	mWorldTolerance = 2.0f*rMax*mPixelTolerance/(dMin*rect.Width());
	mWorldTolerance *= mWorldTolerance;
}
//----------------------------------------------------------------------------
bool LODTerrainPage::IntersectFrustum (const Camera *camera)
{
	mBlocks[0].TestIntersectFrustum(this, camera);
	bool intersect = mBlocks[0].IsVisible();
	return intersect;
}
//----------------------------------------------------------------------------
void LODTerrainPage::AddToQueue (unsigned short blockIndex)
{
	mQueue[mBack] = blockIndex;
	if (++mBack == mNumQueue)
	{
		mBack = 0;
	}
	mItemsInQueue++;
}
//----------------------------------------------------------------------------
unsigned short LODTerrainPage::RemoveFromQueue ()
{
	unsigned short block = mQueue[mFront];
	if (++mFront == mNumQueue)
	{
		mFront = 0;
	}
	mItemsInQueue--;
	return block;
}
//----------------------------------------------------------------------------
unsigned short LODTerrainPage::ReadFromQueue (unsigned short index)
{
	index = index + mFront;
	if (index < mNumQueue)
	{
		return mQueue[index];
	}
	else
	{
		return mQueue[index - mNumQueue];
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::EnableBlocks ()
{
	for (int i=0; i<mBlockQuantity; i++)
	{
		mBlocks[i].Enable(this);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::ResetBlocks ()
{
	unsigned short queue, block;
	if (mFront < mBack)
	{
		mNumUnprocessed = mBack - mFront;
		for (queue = mFront; queue < mBack; queue++)
		{
			block = mQueue[queue];
			if (mBlocks[block].IsBitsSet())
			{
				mBlocks[block].Disable(this);
				mBlocks[block].ClearBits();
			}
		}
	}
	else
	{
		mNumUnprocessed = mNumQueue - mFront + mBack;
		for (queue = mFront; queue < mNumQueue; queue++)
		{
			block = mQueue[queue];
			if (mBlocks[block].IsBitsSet())
			{
				mBlocks[block].Disable(this);
				mBlocks[block].ClearBits();
			}
		}
		for (queue = 0; queue < mBack; queue++)
		{
			block = mQueue[queue];
			if (mBlocks[block].IsBitsSet())
			{
				mBlocks[block].Disable(this);
				mBlocks[block].ClearBits();
			}
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::SimplifyBlocks (const Camera* camera,
									  const APoint &modelEye, 
									  const AVector& modelDir,
									  bool closeAssumption)
{
	while (mNumUnprocessed > 0)
	{
		// 从队首读取需要处理的block
		unsigned short blockIndex = RemoveFromQueue();
		LODTerrainBlock* block = &mBlocks[blockIndex];

		if (!block->IsProcessed())
		{
			mNumUnprocessed--;

			unsigned short childIndex;
			LODTerrainBlock *child;
			Vector2f location;
			int i;
			
			// --- 被父亲替代检测 ---

			if (block->IsFirstChild(blockIndex))
			{
				// 检测block和他的兄弟block需要被父block替代
				if (block->IsSibling(blockIndex, ReadFromQueue(2)))
				{
					child = block;
					if (closeAssumption)
					{
						for (i = 0; i < 4; i++, child++)
						{
							location.X() = child->GetX()*mSpacing +	mOrigin[0];
							location.Y() = child->GetY()*mSpacing +	mOrigin[1];
							child->ComputeInterval(modelDir, modelEye,
								mWorldTolerance,location,mSpacing);
							if (child->GetDeltaMax() > child->GetDeltaL())
							{
								break;
							}
						}
					}
					else // distant assumption
					{
						for (i = 0; i < 4; i++, child++)
						{
							child->ComputeInterval(modelEye,mWorldTolerance);
							if (child->GetDeltaMax() > child->GetDeltaL())
							{
								break;
							}
						}
					}

					if (i == 4) // 所有的孩子都不需要细分，则被父亲替代
					{
						// 移除所有子block，（第一个子block已经被移除）
						for (i = 0; i < 3; i++)
						{
							childIndex = RemoveFromQueue();
							if (!mBlocks[childIndex].IsProcessed())
							{
								mNumUnprocessed--;
							}
							mBlocks[childIndex].ClearBits();
						}

						// 将父block加入
						unsigned short parentIndex =
							(unsigned short)block->GetParentIndex(blockIndex);
						AddToQueue(parentIndex);
						assert(!mBlocks[parentIndex].IsProcessed());
						mNumUnprocessed++;

						continue; // continue!
					}
				}
			} // end if (block->IsFirstChild(blockIndex))

			// --- 细分检测 ---

			if (!block->IsVisibilityTested())
			{
				block->TestIntersectFrustum(this,camera);
			}

			// block是内部的block
			if (block->GetStride() > 1)
			{
				// 只有当在截头体范围内可见，才细分地形块
				if (block->IsVisible())
				{
					childIndex = (unsigned short)block->GetChildIndex(
						blockIndex,1);
					child = &mBlocks[childIndex];
					if (closeAssumption) 
					{
						for (i = 0; i < 4; i++, child++)
						{
							location.X() = child->GetX()*mSpacing + mOrigin[0];
							location.Y() = child->GetY()*mSpacing +	mOrigin[1];
							child->ComputeInterval(modelDir, modelEye,
								mWorldTolerance, location, mSpacing);
							if (child->GetDeltaMax() > child->GetDeltaL())
							{
								break;
							}
						}
					}
					else // distant assumption
					{
						for (i = 0; i < 4; i++, child++)
						{
							child->ComputeInterval(modelEye, mWorldTolerance);
							if (child->GetDeltaMax() > child->GetDeltaL())
							{
								break;
							}
						}
					}

					// 只要有一个孩子需要细分，就将4个孩子加入处理队列
					if (i < 4)
					{
						// 将孩子加入处理队列（父亲已经被移除）
						for (i = 0; i < 4; i++, childIndex++)
						{
							// 加入孩子block
							AddToQueue(childIndex);
							assertion(!mBlocks[childIndex].IsProcessed(), 
								"child shoule not already be processed.");
							mNumUnprocessed++;
						}

						continue; // continue!

					} // end if (block->IsVisible())
				}
			} // end if (block->GetStride() > 1)

			// --- 既不塌陷也不细分 ---

			block->SetProcessed(true);

		} // end if (!block->IsProcessed())

		AddToQueue(blockIndex);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::SimplifyVertices (const APoint& modelEye,
										const AVector& modelDir, bool closeAssumption)
{
	unsigned int queue, block;

	if (mFront < mBack)
	{
		for (queue = mFront; queue < mBack; queue++)
		{
			block = mQueue[queue];
			if (mBlocks[block].IsVisible())
			{
				mBlocks[block].SimplifyVertices(this,modelEye,
					modelDir,mWorldTolerance,closeAssumption);
			}
		}
	}
	else
	{
		for (queue = mFront; queue < mNumQueue; queue++)
		{
			block = mQueue[queue];
			if (mBlocks[block].IsVisible())
			{
				mBlocks[block].SimplifyVertices(this,modelEye,
					modelDir,mWorldTolerance,closeAssumption);
			}
		}
		for (queue = 0; queue < mBack; queue++)
		{
			block = mQueue[queue];
			if (mBlocks[block].IsVisible())
			{
				mBlocks[block].SimplifyVertices(this,modelEye,
					modelDir,mWorldTolerance,closeAssumption);
			}
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::Simplify (const APoint &modelEye, const AVector &modelDir,
								bool closeAssumption)
{
	const Camera *camera = GraphicsRoot::GetSingleton().GetCamera();

	if (mWorldTolerance == -1.0f)
	{
		SetPixelTolerance(mPixelTolerance);
	}

	SimplifyBlocks(camera, modelEye, modelDir, closeAssumption);
	SimplifyVertices(modelEye, modelDir, closeAssumption);

	mNeedsTessellation = true;
}
//----------------------------------------------------------------------------
void LODTerrainPage::Render (LODTerrainBlock &block)
{
	int origin = block.GetX() + mSize*block.GetY();
	int stride = block.GetStride();
	int twoStride = 2*stride;
	int twoStrideTimesSize = twoStride*mSize;
	int index[5] =
	{
		origin,
		origin + twoStride,
		origin + stride*(mSize + 1),
		origin + twoStrideTimesSize,
		origin + twoStrideTimesSize + twoStride
	};

	if (block.IsEven())
	{ // 偶数
		RenderTriangle(index[0], index[3], index[1]);
		RenderTriangle(index[4], index[1], index[3]);
	}
	else
	{
		RenderTriangle(index[1], index[0], index[4]);
		RenderTriangle(index[3], index[4], index[0]);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::RenderTriangle (int t, int l, int r)
{
	// 确定三角形是内部的还是叶子上的
	bool interior;
	if (r > t)
	{
		if (l > t)
		{
			interior = (r - t > 1);
		}
		else
		{
			interior = (t - l > 1);
		}
	}
	else
	{
		if (l > t)
		{
			interior = (l - t > 1);
		}
		else
		{
			interior = (t - r > 1);
		}
	}

	if (interior)
	{
		// 三角形属于内部block可以被细分，M是边<L,R>的中点。
		int m = ((l + r) >> 1);
		if (mVertexs[m].IsEnabled())
		{
			RenderTriangle(m, t, l);
			RenderTriangle(m, r, t);
			return;
		}
	}

	//// 将顶点数据打包
	//int vertexNumElements = mVBuffer->GetNumElements();
	//int x, y, unit;
	//Float2 tCoord;
	//if (mLookup[t] == -1)
	//{
	//	x = t % mSize;
	//	y = t / mSize;

	//	mVBA.Position<Float3>(vertexNumElements) =
	//		Float3(GetX(x), GetY(y), GetHeight(t));

	//	tCoord = Float2(GetTextureCoordinate(x), GetTextureCoordinate(y));
	//	for (unit=0; unit<VertexFormat::AM_MAX_TCOORD_UNITS; unit++)
	//	{
	//		if (mVBA.HasTCoord(unit))
	//		{
	//			mVBA.TCoord<Float2>(unit, vertexNumElements) = tCoord;
	//		}
	//	}
	//	mLookup[t] = vertexNumElements++;
	//	mVBuffer->SetNumElements(vertexNumElements);
	//}

	//if (mLookup[r] == -1)
	//{
	//	x = r % mSize;
	//	y = r / mSize;

	//	mVBA.Position<Float3>(vertexNumElements) =
	//		Float3(GetX(x), GetY(y), GetHeight(r));

	//	tCoord = Float2(GetTextureCoordinate(x), GetTextureCoordinate(y));
	//	for (unit=0; unit<VertexFormat::AM_MAX_TCOORD_UNITS; unit++)
	//	{
	//		if (mVBA.HasTCoord(unit))
	//		{
	//			mVBA.TCoord<Float2>(unit, vertexNumElements) = tCoord;
	//		}
	//	}
	//	mLookup[r] = vertexNumElements++;
	//	mVBuffer->SetNumElements(vertexNumElements);
	//}

	//if (mLookup[l] == -1)
	//{
	//	x = l % mSize;
	//	y = l / mSize;

	//	mVBA.Position<Float3>(vertexNumElements) =
	//		Float3(GetX(x), GetY(y), GetHeight(l));

	//	tCoord = Float2(GetTextureCoordinate(x), GetTextureCoordinate(y));
	//	for (unit=0; unit<VertexFormat::AM_MAX_TCOORD_UNITS; unit++)
	//	{
	//		if (mVBA.HasTCoord(unit))
	//		{
	//			mVBA.TCoord<Float2>(unit, vertexNumElements) = tCoord;
	//		}
	//	}
	//	mLookup[l] = vertexNumElements++;
	//	mVBuffer->SetNumElements(vertexNumElements);
	//}

	//assertion(vertexNumElements<mTotalVQuantity,
	//	"vertexNumElements must be less than mTotalVQuantity.");


	// 设置顶点索引
	int indexNumElements = mIBuffer->GetNumElements();

	int *indices = (int*)mIBuffer->GetData();
	//indices[indexNumElements++] = mLookup[t];
	//indices[indexNumElements++] = mLookup[r];
	//indices[indexNumElements++] = mLookup[l];
	indices[indexNumElements++] = t;
	indices[indexNumElements++] = r;
	indices[indexNumElements++] = l;
	mIBuffer->SetNumElements(indexNumElements);

	assertion(indexNumElements<mTotalIQuantity,
		"indexNumElements should be less than mTotalIQuantity");
}
//----------------------------------------------------------------------------
void LODTerrainPage::RenderBlocks ()
{
	// 重置缓冲区
	memset(mLookup,0xFF,mSize*mSize*sizeof(int));
	mIBuffer->SetNumElements(0);

	unsigned short queue;
	if (mFront < mBack)
	{
		for (queue=mFront; queue<mBack; queue++)
		{
			LODTerrainBlock &block = mBlocks[mQueue[queue]];
			if (block.IsVisible())
			{
				Render(block);
			}
		}
	}
	else
	{
		for (queue=mFront; queue<mNumQueue; queue++)
		{
			LODTerrainBlock& block = mBlocks[mQueue[queue]];
			if (block.IsVisible())
			{
				Render(block);
			}
		}
		for (queue=0; queue<mBack; queue++)
		{
			LODTerrainBlock& block = mBlocks[mQueue[queue]];
			if (block.IsVisible())
			{
				Render(block);
			}
		}
	}

	Renderer::UpdateAll(mIBuffer);
}
//----------------------------------------------------------------------------
void LODTerrainPage::GetVisibleSet (Culler &culler, bool noCull)
{
	if (mNeedsTessellation)
	{
		mNeedsTessellation = false;
		RenderBlocks();
	}

	if (mIBuffer->GetNumElements() > 0)
	{
		TerrainPage::GetVisibleSet(culler, noCull);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::StitchNextCol (LODTerrainPage *nextCol)
{
	// 'this'地形页为(r,c)，'nextCol'地形页为(r,c+1)
	assertion(nextCol->mSize == mSize, "size should be the same.");

	int max = mSize - 2;
	int xThis = mSize - 1;
	int xNext = 0;

	for (int y=1; y<=max; y++)
	{
		int indexThis = xThis + mSize*y;
		int indexNext = xNext + mSize*y;
		LODTerrainVertex *vThis = &mVertexs[indexThis];
		LODTerrainVertex *vNext = &nextCol->mVertexs[indexNext];
		vNext->SetDependent(0, vThis);
		vThis->SetDependent(1, vNext);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::UnstitchNextCol (LODTerrainPage *nextCol)
{
	// 'this'地形页为(r,c)，'nextCol'地形页为(r,c+1)
	assertion(nextCol->mSize == mSize, "size should be the same.");

	int max = mSize - 2;
	int xThis = mSize - 1;
	int xNext = 0;

	for (int y=1; y<=max; y++)
	{
		int indexThis = xThis + mSize*y;
		int indexNext = xNext + mSize*y;
		LODTerrainVertex *vThis = &mVertexs[indexThis];
		LODTerrainVertex *vNext = &nextCol->mVertexs[indexNext];
		vNext->SetDependent(0, 0);
		vThis->SetDependent(1, 0);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::StitchNextRow (LODTerrainPage *nextRow)
{
	// 'this'地形页为(r,c)，'nextRow'地形页为(r+1,c)
	assertion(nextRow->mSize == mSize, "size should be the same.");

	int max = mSize - 2;
	int yThis = mSize - 1;
	int yNext = 0;

	for (int x=1; x<max; x++)
	{
		int indexThis = x + mSize*yThis;
		int indexNext = x + mSize*yNext;
		LODTerrainVertex *vThis = &mVertexs[indexThis];
		LODTerrainVertex *vNext = &nextRow->mVertexs[indexNext];
		vNext->SetDependent(1, vThis);
		vThis->SetDependent(0, vNext);
	}
}
//----------------------------------------------------------------------------
void LODTerrainPage::UnstitchNextRow (LODTerrainPage *nextRow)
{
	// 'this'地形页为(r,c)，'nextRow'地形页为(r+1,c)
	assertion(nextRow->mSize == mSize, "size should be the same.");

	int max = mSize - 2;
	int yThis = mSize - 1;
	int yNext = 0;

	for (int x=1; x<max; x++)
	{
		int indexThis = x + mSize*yThis;
		int indexNext = x + mSize*yNext;
		LODTerrainVertex *vThis = &mVertexs[indexThis];
		LODTerrainVertex *vNext = &nextRow->mVertexs[indexNext];
		vNext->SetDependent(1, 0);
		vThis->SetDependent(0, 0);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
LODTerrainPage::LODTerrainPage (LoadConstructor value)
:
TerrainPage(value),
	mTextureSpacing(1.0f),
	mPixelTolerance(1.0f),
	mWorldTolerance(-1.0f),// 必须被初始化为-1，后面需要使用
	mNeedsTessellation(false),
	mLookup(0),
	mVertexs(0),
	mTotalVQuantity(0),
	mTotalTQuantity(0),
	mTotalIQuantity(0),
	mBlockQuantity(0),
	mBlocks(0),
	mQueue(0),
	mNumQueue(0),
	mFront(0),
	mBack(0),
	mNumUnprocessed(0),
	mItemsInQueue(0)
{
}
//----------------------------------------------------------------------------
void LODTerrainPage::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	TerrainPage::Load(source);
	PX2_VERSION_LOAD(source);

	source.Read(mTextureSpacing);
	source.Read(mPixelTolerance);

	PX2_END_DEBUG_STREAM_LOAD(LODTerrainPage, source);
}
//----------------------------------------------------------------------------
void LODTerrainPage::Link (InStream& source)
{
	TerrainPage::Link(source);
}
//----------------------------------------------------------------------------
void LODTerrainPage::PostLink ()
{
	TerrainPage::PostLink();

	InitializeDerivedData();
}
//----------------------------------------------------------------------------
bool LODTerrainPage::Register (OutStream& target) const
{
	return TerrainPage::Register(target);
}
//----------------------------------------------------------------------------
void LODTerrainPage::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	TerrainPage::Save(target);
	PX2_VERSION_SAVE(target);

	target.Write(mTextureSpacing);
	target.Write(mPixelTolerance);

	PX2_END_DEBUG_STREAM_SAVE(LODTerrainPage, target);
}
//----------------------------------------------------------------------------
int LODTerrainPage::GetStreamingSize (Stream &stream) const
{
	int size = TerrainPage::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	size += sizeof(mTextureSpacing);
	size += sizeof(mPixelTolerance);
	return size;
}
//----------------------------------------------------------------------------