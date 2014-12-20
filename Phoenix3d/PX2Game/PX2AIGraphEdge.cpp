/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AIGraphEdge.cpp
*
*/

#include "PX2AIGraphEdge.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
GraphEdge::GraphEdge ()
	:
mCost(1.0),
mFrom(AIGraphIvalidNodeIndex),
mTo(AIGraphIvalidNodeIndex)
{
}
//----------------------------------------------------------------------------
GraphEdge::GraphEdge (int from, int to, double cost)
	:
mFrom(from),
mTo(to),
mCost(cost)
{
}
//----------------------------------------------------------------------------
GraphEdge::GraphEdge (int from, int to)
	:
mFrom(from),
mTo(to),
mCost(1.0)
{
}
//----------------------------------------------------------------------------
GraphEdge::~GraphEdge ()
{
}
//----------------------------------------------------------------------------
bool GraphEdge::operator == (const GraphEdge &edge)
{
	return edge.mFrom == this->mFrom && edge.mTo   == this->mTo &&
		edge.mCost == this->mCost;
}
//----------------------------------------------------------------------------
bool GraphEdge::operator != (const GraphEdge &edge)
{
	return !(*this == edge);
}
//----------------------------------------------------------------------------