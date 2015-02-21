// PX2APoint.inl

//----------------------------------------------------------------------------
inline APoint::operator const Float3& () const
{
	return *(const Float3*)mTuple;
}
//----------------------------------------------------------------------------
inline APoint::operator Float3& ()
{
	return *(Float3*)mTuple;
}
//----------------------------------------------------------------------------
inline APoint::operator const Vector3f& () const
{
	return *(const Vector3f*)mTuple;
}
//----------------------------------------------------------------------------
inline APoint::operator Vector3f& ()
{
	return *(Vector3f*)mTuple;
}
//----------------------------------------------------------------------------