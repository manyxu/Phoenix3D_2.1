// PX2AVector.inl

//----------------------------------------------------------------------------
inline AVector::operator const Float3& () const
{
    return *(const Float3*)mTuple;
}
//----------------------------------------------------------------------------
inline AVector::operator Float3& ()
{
    return *(Float3*)mTuple;
}
//----------------------------------------------------------------------------
inline AVector::operator const Vector3f& () const
{
    return *(const Vector3f*)mTuple;
}
//----------------------------------------------------------------------------
inline AVector::operator Vector3f& ()
{
    return *(Vector3f*)mTuple;
}
//----------------------------------------------------------------------------