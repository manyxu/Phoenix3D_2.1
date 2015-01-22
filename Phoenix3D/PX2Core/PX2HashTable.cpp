/*
*
* ÎÄ¼þÃû³Æ	£º	PX2HashTable.cpp
*
*/

#include "PX2HashTable.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// UIntHashCoder
//----------------------------------------------------------------------------
unsigned int UIntHashCoder::operator () (unsigned int i) const
{
	return i; 
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// FixedStringHashCoder
//----------------------------------------------------------------------------
unsigned int FixedStringHashCoder::operator () (const FString &str) const
{
	return (unsigned int)(str.GetHandle());
}
//----------------------------------------------------------------------------