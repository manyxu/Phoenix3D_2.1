/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StringTokenizer.inl
*
*/

//----------------------------------------------------------------------------
inline StringTokenizer::Iterator StringTokenizer::Begin() const
{
	return _tokens.begin();
}
//----------------------------------------------------------------------------
inline StringTokenizer::Iterator StringTokenizer::End() const
{
	return _tokens.end();
}
//----------------------------------------------------------------------------
inline std::size_t StringTokenizer::Count() const
{
	return _tokens.size();
}
//----------------------------------------------------------------------------