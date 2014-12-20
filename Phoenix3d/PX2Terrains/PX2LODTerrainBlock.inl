/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LodTerrainBlock.inl
*
*/

//----------------------------------------------------------------------------
inline int LODTerrainBlock::GetX () const
{
	return (int)mX;
}
//----------------------------------------------------------------------------
inline int LODTerrainBlock::GetY () const
{
	return (int)mY;
}
//----------------------------------------------------------------------------
inline int LODTerrainBlock::GetStride () const
{
	return (int)mStride;
}
//----------------------------------------------------------------------------
inline void LODTerrainBlock::SetEven (bool set)
{
	if (set)
	{
		mFlags |= EVEN_PARITY;
	}
	else
	{
		mFlags &= ~EVEN_PARITY;
	}
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsEven () const
{
	return (mFlags & EVEN_PARITY) != 0;
}
//----------------------------------------------------------------------------
inline void LODTerrainBlock::SetProcessed (bool set)
{
	if (set)
	{
		mFlags |= PROCESSED;
	}
	else
	{
		mFlags &= ~PROCESSED;
	}
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsProcessed () const
{
	return (mFlags & PROCESSED) != 0;
}
//----------------------------------------------------------------------------
inline void LODTerrainBlock::SetVisible (bool set)
{
	if (set)
	{
		mFlags |= VISIBLE;
	}
	else
	{
		mFlags &= ~VISIBLE;
	}
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsVisible () const
{
	return (mFlags & VISIBLE) != 0;
}
//----------------------------------------------------------------------------
inline void LODTerrainBlock::SetVisibilityTested (bool set)
{
	if (set)
	{
		mFlags |= VISIBILITY_TESTED;
	}
	else
	{
		mFlags &= ~VISIBILITY_TESTED;
	}
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsVisibilityTested () const
{
	return (mFlags & VISIBILITY_TESTED) != 0;
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsBitsSet () const
{
	return (mFlags & BITS_MASK) != 0;
}
//----------------------------------------------------------------------------
inline void LODTerrainBlock::ClearBits ()
{
	mFlags &= EVEN_PARITY;
}
//----------------------------------------------------------------------------
inline float LODTerrainBlock::GetDelta (int i) const
{
	assertion(0<=i&&i<=1, "i should be in range [0,1].");
	return mHeightDelta[i];
}
//----------------------------------------------------------------------------
inline float LODTerrainBlock::GetDeltaMax () const
{
	return mHeightDeltaMax;
}
//----------------------------------------------------------------------------
inline float LODTerrainBlock::GetDeltaL () const
{
	return mDeltaL;
}
//----------------------------------------------------------------------------
inline float LODTerrainBlock::GetDeltaH () const
{
	return mDeltaH;
}
//----------------------------------------------------------------------------
inline const Vector3f& LODTerrainBlock::GetMin () const
{
	return mMin;
}
//----------------------------------------------------------------------------
inline const Vector3f& LODTerrainBlock::GetMax () const
{
	return mMax;
}
//----------------------------------------------------------------------------
inline int LODTerrainBlock::GetParentIndex (int child)
{
	// p = (c-1)/4
	return (child - 1) >> 2;
}
//----------------------------------------------------------------------------
inline int LODTerrainBlock::GetChildIndex (int parent, int index)
{
	// c = 4*p+i
	return (parent << 2) + index;
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsFirstChild (int index)
{
	return index > 0 && ((index-1) % 4) == 0;
}
//----------------------------------------------------------------------------
inline bool LODTerrainBlock::IsSibling (int index, int test)
{
	assertion(index>0 && test>0, "iIndex and iTest should be larger than 0.");
	return (index-1) >> 2 == (test-1) >> 2;
}
//----------------------------------------------------------------------------