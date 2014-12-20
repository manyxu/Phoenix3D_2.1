/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AIGraphEdge.hpp
*
*/

#ifndef PX2AIGRAPHEDGE_HPP
#define PX2AIGRAPHEDGE_HPP

#include "PX2AIGraphDefine.hpp"

namespace PX2
{

	class GraphEdge
	{
	public:
		GraphEdge ();
		GraphEdge (int from, int to, double cost);
		GraphEdge (int from, int to);
		virtual ~GraphEdge ();

		void SetFrom (int index);
		int GetFrom () const;

		void SetTo (int index);
		int GetTo () const;

		bool operator == (const GraphEdge &edge);
		bool operator != (const GraphEdge &edge);

	protected:
		int mFrom;
		int mTo;
		double mCost;
	};

#include "PX2AIGraphEdge.inl"

}

#endif