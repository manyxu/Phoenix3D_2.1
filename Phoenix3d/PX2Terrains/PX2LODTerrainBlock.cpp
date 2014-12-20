/*
*
* 文件名称	：	PX2LodTerrainBlock.cpp
*
*/

#include "PX2Camera.hpp"
#include "PX2IntrBox3Frustum3.hpp"
#include "PX2LODTerrainBlock.hpp"
#include "PX2LODTerrainPage.hpp"
#include "PX2LODTerrainVertex.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
void LODTerrainBlock::GetVertex9 (unsigned short size,
								   LODTerrainVertex* origin, LODTerrainVertex* vertex[9])
{
	unsigned short aorigin = mX+size*mY;
	unsigned short twoStride = 2*mStride;
	unsigned short sizePlus1 = size+1;
	unsigned short sizePlus2 = size+2;
	unsigned short twoSizePlus1 = 2*size+1;
	unsigned short sizeTimesStride = size*mStride;
	unsigned short sizePlus1TimesStride = sizePlus1*mStride;
	unsigned short sizePlus2TimesStride = sizePlus2*mStride;
	unsigned short sizeTimesTwoStride = size*twoStride;
	unsigned short twoSizePlus1TimesStride = twoSizePlus1*mStride;
	unsigned short sizePlus1TimesTwoStride = sizePlus1*twoStride;

	origin += aorigin;
	vertex[0] = &origin[0];
	vertex[1] = &origin[mStride];
	vertex[2] = &origin[twoStride];
	vertex[3] = &origin[sizeTimesStride];
	vertex[4] = &origin[sizePlus1TimesStride];
	vertex[5] = &origin[sizePlus2TimesStride];
	vertex[6] = &origin[sizeTimesTwoStride];
	vertex[7] = &origin[twoSizePlus1TimesStride];
	vertex[8] = &origin[sizePlus1TimesTwoStride];
}
//----------------------------------------------------------------------------
void LODTerrainBlock::Initialize (LODTerrainPage *page,	
								  LODTerrainBlock *blocks, int blockIndex,
								  int x, int y, int stride, bool even)
{
	mX = (unsigned char)x;
	mY = (unsigned char)y;
	mStride = (unsigned char)stride;
	mFlags = (unsigned char)0;
	mDeltaL = 0.0f;
	mDeltaH = Mathf::MAX_REAL;
	SetEven(even);

	LODTerrainVertex* vertex[9];
	GetVertex9((unsigned short)page->mSize, page->mVertexs, vertex);

	// 设置顶点相关性
	vertex[1]->SetDependent(0, vertex[4]);
	vertex[3]->SetDependent(1, vertex[4]);
	vertex[5]->SetDependent(0, vertex[4]);
	vertex[7]->SetDependent(1, vertex[4]);
	if (even)
	{
		vertex[4]->SetDependent(0, vertex[6]);
		vertex[4]->SetDependent(1, vertex[2]);
	}
	else
	{
		vertex[4]->SetDependent(0, vertex[0]);
		vertex[4]->SetDependent(1, vertex[8]);
	}

	// 如果有孩子，递归处理孩子
	if (stride > 1)
	{
		// 孩子的stride是父亲的一半(stride的大小为block的一半)
		int childStride = (stride >> 1);

		// child 00
		int childIndex = GetChildIndex(blockIndex,1);
		LODTerrainBlock* child = &blocks[childIndex];
		child->Initialize(page,blocks,childIndex,x,y,childStride,true);

		// child 01
		childIndex++;
		child++;
		child->Initialize(page,blocks,childIndex,x+stride,y,childStride,false);

		// child 10
		childIndex++;
		child++;
		child->Initialize(page,blocks,childIndex,x,y+stride,childStride,false);

		// child 11
		childIndex++;
		child++;
		child->Initialize(page,blocks,childIndex,x+stride,y+stride,childStride,
			true);
	}
}
//----------------------------------------------------------------------------
void LODTerrainBlock::UpdateBoundingBox (LODTerrainPage *page,
										 LODTerrainBlock *blocks, 
										 int blockIndex, int stride)
{
	APoint point[9];
	point[0].X() = page->GetX((int)mX);
	point[0].Y() = page->GetY((int)mY);
	point[1].X() = page->GetX((int)mX + (int)mStride);
	point[1].Y() = point[0].Y();
	point[2].X() = page->GetX((int)mX + 2*(int)mStride);
	point[2].Y() = point[0].Y();
	point[3].X() = point[0].X();
	point[3].Y() = page->GetY((int)mY + (int)mStride);
	point[4].X() = point[1].X();
	point[4].Y() = point[3].Y();
	point[5].X() = point[2].X();
	point[5].Y() = point[3].Y();
	point[6].X() = point[0].X();
	point[6].Y() = page->GetY((int)mY + 2*(int)mStride);
	point[7].X() = point[1].X();
	point[7].Y() = point[6].Y();
	point[8].X() = point[2].X();
	point[8].Y() = point[6].Y();

	int origin = (int)mX + page->mSize*(int)mY;
	point[0].Z() = page->GetHeight(origin);
	point[1].Z() = page->GetHeight(origin+stride);
	point[2].Z() = page->GetHeight(origin+2*stride);
	origin += page->mSize*stride;
	point[3].Z() = page->GetHeight(origin);
	point[4].Z() = page->GetHeight(origin+stride);
	point[5].Z() = page->GetHeight(origin+2*stride);
	origin += page->mSize*stride;
	point[6].Z() = page->GetHeight(origin);
	point[7].Z() = page->GetHeight(origin+stride);
	point[8].Z() = page->GetHeight(origin+2*stride);

	// 设置包围盒
	mMin.X() = point[0].X();
	mMin.Y() = point[0].Y();
	mMax.X() = point[8].X();
	mMax.Y() = point[8].Y();

	// 计算最大delta
	float c0 = point[0].Z();
	float md = point[1].Z();
	float c1 = point[2].Z();
	mHeightDelta[0] = 0.5f*(c0+c1)-md;
	mHeightDelta[0] *= mHeightDelta[0];

	c0 = point[8].Z();
	md = point[5].Z();
	mHeightDelta[1] = 0.5f*(c0+c1)-md;
	mHeightDelta[1] *= mHeightDelta[1];

	md = point[7].Z();
	c1 = point[6].Z();
	mHeightDelta[2] = 0.5f*(c0+c1)-md;
	mHeightDelta[2] *= mHeightDelta[2];

	c0 = point[0].Z();
	md = point[3].Z();
	mHeightDelta[3] = 0.5f*(c0+c1)-md;
	mHeightDelta[3] *= mHeightDelta[3];

	md = point[4].Z();
	if (IsEven())
	{
		c0 = point[2].Z();
		c1 = point[6].Z();
	}
	else
	{
		c0 = point[0].Z();
		c1 = point[8].Z();
	}
	mHeightDelta[4] = 0.5f*(c0+c1)-md;
	mHeightDelta[4] *= mHeightDelta[4];

	mHeightDeltaMax = mHeightDelta[0];
	for (int i = 1; i < 5; i++)
	{
		if (mHeightDelta[i] > mHeightDeltaMax)
		{
			mHeightDeltaMax = mHeightDelta[i];
		}
	}

	// 如果有孩子递归处理孩子
	if (stride > 1)
	{
		// 孩子的跨度是父亲的一半
		int childStride = (stride >> 1);

		// 处理 孩子00
		int childIndex = GetChildIndex(blockIndex,1);
		LODTerrainBlock* child = &blocks[childIndex];
		child->UpdateBoundingBox(page,blocks,childIndex,childStride);
		if (child->mHeightDeltaMax > mHeightDeltaMax)
		{
			mHeightDeltaMax = child->mHeightDeltaMax;
		}
		mMin.Z() = child->mMin.Z();
		mMax.Z() = child->mMax.Z();

		// 处理 孩子01
		childIndex++;
		child++;
		child->UpdateBoundingBox(page,blocks,childIndex,childStride);
		if (child->mHeightDeltaMax > mHeightDeltaMax)
		{
			mHeightDeltaMax = child->mHeightDeltaMax;
		}
		if (child->mMin.Z() < mMin.Z())
		{
			mMin.Z() = child->mMin.Z();
		}
		if (child->mMax.Z() > mMax.Z())
		{
			mMax.Z() = child->mMax.Z();
		}

		// 处理 孩子10
		childIndex++;
		child++;
		child->UpdateBoundingBox(page,blocks,childIndex,childStride);
		if (child->mHeightDeltaMax > mHeightDeltaMax)
		{
			mHeightDeltaMax = child->mHeightDeltaMax;
		}
		if (child->mMin.Z() < mMin.Z())
		{
			mMin.Z() = child->mMin.Z();
		}
		if (child->mMax.Z() > mMax.Z())
		{
			mMax.Z() = child->mMax.Z();
		}

		// 处理 孩子11
		childIndex++;
		child++;
		child->UpdateBoundingBox(page,blocks,childIndex,childStride);
		if (child->mHeightDeltaMax > mHeightDeltaMax)
		{
			mHeightDeltaMax = child->mHeightDeltaMax;
		}
		if (child->mMin.Z() < mMin.Z())
		{
			mMin.Z() = child->mMin.Z();
		}
		if (child->mMax.Z() > mMax.Z())
		{
			mMax.Z() = child->mMax.Z();
		}
	}
	else // 没有孩子
	{
		// 计算quadtree的叶子节点的z值
		mMin.Z() = point[0].Z();
		mMax.Z() = mMin.Z();
		for (int iIndex = 1; iIndex < 9; iIndex++)
		{
			float fZ = point[iIndex].Z();
			if (fZ < mMin.Z())
			{
				mMin.Z() = fZ;
			}
			if (fZ > mMax.Z())
			{
				mMax.Z() = fZ;
			}
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrainBlock::ComputeInterval (const APoint& modelEye, float tolerance)
{
	// distant terrain assumption

	if (tolerance > 0.0f)
	{
		// 视点到block的z的两侧的最小距离（平方）
		// hmin = |eye.Z() - clamp(bmin.Z(),eye.Z(),bmax.Z())|
		float hMin;
		if (modelEye.Z() < mMin.Z())
		{
			hMin = modelEye.Z() - mMin.Z();
			hMin *= hMin;
		}
		else if (modelEye.Z() > mMax.Z())
		{
			hMin = modelEye.Z() - mMax.Z();
			hMin *= hMin;
		}
		else
		{
			hMin = 0.0f;
		}

		// 视点到block的z的两侧的最大距离（平方）
		// hmax = max{|eye.Z() - bmin.Z()|,|eye.Z() - bmax.Z()|}
		float hMax = modelEye.Z() - mMin.Z();
		hMax *= hMax;
		float fTmp = modelEye.Z() - mMax.Z();
		fTmp *= fTmp;
		if ( fTmp > hMax )
			hMax = fTmp;

		// 视点到block的xy的两侧的最大和最小距离（平方）
		float dxMin = modelEye.X() - mMin.X();
		float dxMax = modelEye.X() - mMax.X();
		float dyMin = modelEye.Y() - mMin.Y();
		float dyMax = modelEye.Y() - mMax.Y();
		dxMin *= dxMin;
		dxMax *= dxMax;
		dyMin *= dyMin;
		dyMax *= dyMax;
		float rMin = 0.0f, rMax = 0.0f;

		if (modelEye.X() < mMin.X())
		{
			rMin += dxMin;
			rMax += dxMax;
		}
		else if (modelEye.X() <= mMax.X())
		{
			rMax += (dxMax >= dxMin ? dxMax : dxMin);
		}
		else
		{
			rMin += dxMax;
			rMax += dxMin;
		}

		if (modelEye.Y() < mMin.Y())
		{
			rMin += dyMin;
			rMax += dyMax;
		}
		else if (modelEye.Y() <= mMax.Y())
		{
			rMax += (dyMax >= dyMin ? dyMax : dyMin);
		}
		else
		{
			rMin += dyMax;
			rMax += dyMin;
		}

		// compute fmin
		float denom = rMin + hMax;
		float fFMin = (denom > 0.0f ? rMin/(denom*denom) : Mathf::MAX_REAL);
		denom = rMax + hMax;
		fTmp = (denom > 0.0f ? rMax/(denom*denom) : Mathf::MAX_REAL);
		if (fTmp < fFMin)
		{
			fFMin = fTmp;
		}

		// compute fmax
		float fFMax;
		if (rMin >= hMin)
		{
			denom = rMin + hMin;
			fFMax = (denom > 0.0f ? rMin/(denom*denom) : Mathf::MAX_REAL);
		}
		else if (rMax <= hMin)
		{
			denom = rMax + hMin;
			fFMax = (denom > 0.0f ? rMax/(denom*denom) : Mathf::MAX_REAL);
		}
		else
		{
			fFMax = (hMin > 0.0f ? 0.25f/hMin : Mathf::MAX_REAL);
		}

		mDeltaL = tolerance/fFMax;
		mDeltaH = (fFMin > 0.0f ? tolerance/fFMin : Mathf::MAX_REAL);
	}
	else  // tolerance == 0
	{
		mDeltaL = 0.0f;
		mDeltaH = Mathf::MAX_REAL;
	}
}
//----------------------------------------------------------------------------
void LODTerrainBlock::ComputeInterval (const AVector& modelDir,
									   const APoint& modelEye, float tolerance,
									   Vector2f& rkLoc, float fSpacing)
{
	// close terrain assumption

	if (tolerance > 0.0f)
	{
		// compute fmin and fmax

		// temporary quantities
		float fLmEx = rkLoc.X() - modelEye.X();
		float fLmEy = rkLoc.Y() - modelEye.Y();
		float fTmp = fSpacing*float(mStride);
		float fXSum = fLmEx + fTmp;
		float fYSum = fLmEy + fTmp;
		float fXDif = fLmEx - fTmp;
		float fYDif = fLmEy - fTmp;

		// find corners of block closest to and farthest from eye
		float fFMin = Mathf::FAbs(modelDir.X()*fXDif +
			modelDir.Y()*fYDif);
		float fFMax = fFMin;

		fTmp = Mathf::FAbs(modelDir.X()*fXSum + modelDir.Y()*fYDif);
		if (fTmp >= fFMin)
		{
			fFMin = fTmp;
		}
		else 
		{
			fFMax = fTmp;
		}

		fTmp = Mathf::FAbs(modelDir.X()*fXSum + modelDir.Y()*fYSum);
		if (fTmp >= fFMin)
		{
			fFMin = fTmp;
		}
		else 
		{
			fFMax = fTmp;
		}

		fTmp = Mathf::FAbs(modelDir.X()*fXDif + modelDir.Y()*fYSum);
		if (fTmp >= fFMin)
		{
			fFMin = fTmp;
		}
		else
		{
			fFMax = fTmp;
		}

		mDeltaL = tolerance*fFMax;
		mDeltaH = tolerance*fFMin;
	}
	else  // tolerance == 0
	{
		mDeltaL = 0.0f;
		mDeltaH = Mathf::MAX_REAL;
	}
}
//----------------------------------------------------------------------------
void LODTerrainBlock::TestIntersectFrustum (const LODTerrainPage* page,
											 const Camera* camera)
{
	SetVisibilityTested(true);

	// 地形页模型坐标系下的坐标轴向包围盒
	APoint center = 0.5f*(mMin + mMax);
	AVector extent = 0.5f*(mMax - mMin);

	// 整个地形坐标系下
	Box3f box;
	APoint cen = page->LocalTransform.GetMatrix() * center;
	box.Center = Vector3f(cen.X(), cen.Y(), cen.Z());
	int i;
	for (i = 0; i < 3; i++)
	{
		HPoint axis;
		page->LocalTransform.GetRotate().GetColumn(i, axis);
		box.Axis[i] = Vector3f(axis.X(), axis.Y(), axis.Z());
		box.Extent[i] = page->LocalTransform.GetUniformScale()*extent[i];
	}

	// 用相机匹配相机截头体
	APoint camPos = camera->GetPosition();
	AVector camD = camera->GetDVector();
	AVector camU = camera->GetUVector();
	AVector camR = camera->GetRVector();
	Frustum3f frustum;
	frustum.Origin = Vector3f(camPos.X(), camPos.Y(), camPos.Z());
	frustum.DVector = Vector3f(camD.X(), camD.Y(), camD.Z());
	frustum.UVector = Vector3f(camU.X(), camU.Y(), camU.Z());
	frustum.RVector = Vector3f(camR.X(), camR.Y(), camR.Z());
	frustum.RBound = camera->GetRMax();
	frustum.UBound = camera->GetUMax();
	frustum.DMin = camera->GetDMin();
	frustum.DMax = camera->GetDMax();
	frustum.Update();

	SetVisible(IntrBox3Frustum3f(box,frustum).Test());
}
//----------------------------------------------------------------------------
void LODTerrainBlock::SimplifyVertices (LODTerrainPage *page,
										const APoint &modelEye,
										const AVector &modelDir,
										float tolerance, bool closeAssumption)
{
	int size = page->mSize;
	int origin = (int)mX + size*(int)mY;
	LODTerrainVertex* vertexOrigin = page->mVertexs + origin;
	LODTerrainVertex* vertex;
	int offset;
	AVector diff;
	float rSqr, lenSqr, distDir;

	// 位置(stride,0)简化
	if (mDeltaL <= mHeightDelta[0])
	{
		vertex = vertexOrigin + mStride;
		if (mHeightDelta[0] <= mDeltaH)
		{
			// test vertex delta against tolerance
			if (!vertex->IsEnabled())
			{
				diff.X() = modelEye.X() - page->GetX((int)mX+(int)mStride);
				diff.Y() = modelEye.Y() - page->GetY((int)mY);
				if (closeAssumption) 
				{
					distDir = modelDir.X()*diff.X() + modelDir.Y()*diff.Y();
					if (mHeightDelta[0] > tolerance*distDir*distDir)
					{
						vertex->Enable();
					}
				}
				else // distant assumption
				{
					diff.Z() = modelEye.Z() - page->GetHeight(origin+(int)mStride);
					rSqr = diff.X()*diff.X() + diff.Y()*diff.Y();
					lenSqr = rSqr + diff.Z()*diff.Z();
					if (mHeightDelta[0]*rSqr > tolerance*lenSqr*lenSqr)
					{
						vertex->Enable();
					}
				}
			}
		}
		else
		{
			if (!vertex->IsEnabled())
			{
				vertex->Enable();
			}
		}
	}

	// 位置(2*stride,stride)简化
	if (mDeltaL <= mHeightDelta[1])
	{
		offset = (size+2)*(int)mStride;
		vertex = vertexOrigin + offset;
		if (mHeightDelta[1] <= mDeltaH)
		{
			if (!vertex->IsEnabled())
			{
				diff.X() = modelEye.X() -
					page->GetX((int)mX+2*(int)mStride);
				diff.Y() = modelEye.Y() -
					page->GetY((int)mY+(int)mStride);
				if (closeAssumption) 
				{
					distDir = modelDir.X()*diff.X() +
						modelDir.Y()*diff.Y();
					if (mHeightDelta[1] > tolerance*distDir*distDir)
					{
						vertex->Enable();
					}
				}
				else // distant assumption
				{
					diff.Z() = modelEye.Z() -
						page->GetHeight(origin+offset);
					rSqr = diff.X()*diff.X() + diff.Y()*diff.Y();
					lenSqr = rSqr + diff.Z()*diff.Z();
					if (mHeightDelta[1]*rSqr > tolerance*lenSqr*lenSqr)
					{
						vertex->Enable();
					}
				}
			}
		}
		else
		{
			if (!vertex->IsEnabled())
			{
				vertex->Enable();
			}
		}
	}

	// 位置(stride,2*stride)简化
	if (mDeltaL <= mHeightDelta[2])
	{
		offset = (2*size+1)*(int)mStride;
		vertex = vertexOrigin + offset;
		if (mHeightDelta[2] <= mDeltaH)
		{
			// test vertex delta against tolerance
			if (!vertex->IsEnabled())
			{
				diff.X() = modelEye.X() -
					page->GetX((int)mX+(int)mStride);
				diff.Y() = modelEye.Y() -
					page->GetY((int)mY+2*(int)mStride);
				if (closeAssumption) 
				{
					distDir = modelDir.X()*diff.X() +
						modelDir.Y()*diff.Y();
					if (mHeightDelta[2] > tolerance*distDir*distDir)
					{
						vertex->Enable();
					}
				}
				else // distant assumption
				{
					diff.Z() = modelEye.Z() -
						page->GetHeight(origin+offset);
					rSqr = diff.X()*diff.X() + diff.Y()*diff.Y();
					lenSqr = rSqr + diff.Z()*diff.Z();
					if (mHeightDelta[2]*rSqr > tolerance*lenSqr*lenSqr)
					{
						vertex->Enable();
					}
				}
			}
		}
		else
		{
			if (!vertex->IsEnabled())
			{
				vertex->Enable();
			}
		}
	}

	// 位置(0,stride)简化
	if (mDeltaL <= mHeightDelta[3])
	{
		offset = size*(int)mStride;
		vertex = vertexOrigin + offset;
		if (mHeightDelta[3] <= mDeltaH)
		{
			if (!vertex->IsEnabled())
			{
				diff.X() = modelEye.X() - page->GetX((int)mX);
				diff.Y() = modelEye.Y() -
					page->GetY((int)mY+(int)mStride);
				if (closeAssumption) 
				{
					distDir = modelDir.X()*diff.X() +
						modelDir.Y()*diff.Y();
					if (mHeightDelta[3] > tolerance*distDir*distDir)
					{
						vertex->Enable();
					}
				}
				else // distant terrain assumption
				{
					diff.Z() = modelEye.Z() -
						page->GetHeight(origin+offset);
					rSqr = diff.X()*diff.X() + diff.Y()*diff.Y();
					lenSqr = rSqr + diff.Z()*diff.Z();
					if (mHeightDelta[3]*rSqr > tolerance*lenSqr*lenSqr)
					{
						vertex->Enable();
					}
				}
			}
		}
		else
		{
			if (!vertex->IsEnabled())
			{
				vertex->Enable();
			}
		}
	}

	// 位置(stride,stride)简化
	if (mDeltaL <= mHeightDelta[4])
	{
		offset = (size+1)*(int)mStride;
		vertex = vertexOrigin + offset;
		if (mHeightDelta[4] <= mDeltaH)
		{
			// test vertex delta against tolerance
			if (!vertex->IsEnabled())
			{
				diff.X() = modelEye.X() -
					page->GetX((int)mX+(int)mStride);
				diff.Y() = modelEye.Y() -
					page->GetY((int)mY+(int)mStride);
				if (closeAssumption) 
				{
					distDir = modelDir.X()*diff.X() +
						modelDir.Y()*diff.Y();
					if (mHeightDelta[4] > tolerance*distDir*distDir)
					{
						vertex->Enable();
					}
				}
				else // distant terrain assumption
				{
					diff.Z() = modelEye.Z() -
						page->GetHeight(origin+offset);
					rSqr = diff.X()*diff.X() + diff.Y()*diff.Y();
					lenSqr = rSqr + diff.Z()*diff.Z();
					if (mHeightDelta[4]*rSqr > tolerance*lenSqr*lenSqr)
					{
						vertex->Enable();
					}
				}
			}
		}
		else
		{
			if (!vertex->IsEnabled())
			{
				vertex->Enable();
			}
		}
	}

	// 激活角上的顶点
	if (IsEven())
	{
		vertex = vertexOrigin + 2*(int)mStride;
		if (!vertex->IsEnabled())
		{
			vertex->Enable();
		}

		vertex = vertexOrigin + 2*size*(int)mStride;
		if (!vertex->IsEnabled())
		{
			vertex->Enable();
		}
	}
	else
	{
		vertex = vertexOrigin;
		if (!vertex->IsEnabled())
		{
			vertex->Enable();
		}

		vertex = vertexOrigin + 2*(size+1)*(int)mStride;
		if (!vertex->IsEnabled())
		{
			vertex->Enable();
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrainBlock::Enable (LODTerrainPage* page)
{
	LODTerrainVertex *vertex[9];
	GetVertex9((unsigned short)page->mSize, page->mVertexs, vertex);
	for (int i = 0; i < 9; i++)
	{
		if (!vertex[i]->IsEnabled())
		{
			vertex[i]->Enable();
		}
	}
}
//----------------------------------------------------------------------------
void LODTerrainBlock::Disable (LODTerrainPage *page)
{
	LODTerrainVertex *vertex[9];
	GetVertex9((unsigned short)page->mSize, page->mVertexs, vertex);
	for (int i = 0; i < 9; i++)
	{
		if (vertex[i]->IsEnabled())
		{
			vertex[i]->Disable();
		}
	}
}
//----------------------------------------------------------------------------