
#ifndef __HEAPNODE_H__
#define __HEAPNODE_H__

#include "PX2GamePre.hpp"

namespace GridMove
{
	inline unsigned int MAKEINDEX( int x, int y )
	{
		return (y<<16) | (x);
	}

	inline int INDEX_TO_X( unsigned int index )
	{
		return index&0xffff;
	}

	inline int INDEX_TO_Y( unsigned int index )
	{
		return index>>16;
	}

	struct stPathHeapNode
	{
		unsigned int from;
		unsigned int index;
		int hval;  //heuristics_cost
		int aval; //从开始点到达当前点的实际cost
	};

	inline bool operator <( const stPathHeapNode &node1, const stPathHeapNode &node2 )
	{ 
		return (node1.hval+node1.aval < node2.hval+node2.aval);
	}
	inline bool operator >( const stPathHeapNode &node1, const stPathHeapNode &node2 )
	{ 
		return (node1.hval+node1.aval > node2.hval+node2.aval); 
	}
	inline bool operator ==( const stPathHeapNode &node1, const stPathHeapNode &node2 )
	{ 
		return (node1.hval+node1.aval == node2.hval+node2.aval);
	}

	class CPathHeap
	{
	public:
		void Init()
		{
			m_AllNodes.resize(0);
		}
		void PushNode( const stPathHeapNode &node )
		{
			m_AllNodes.push_back( node );
			std::push_heap( m_AllNodes.begin(), m_AllNodes.end(), mComp );
		}
		void PopNode( stPathHeapNode &node )
		{
			node = m_AllNodes.front();
			std::pop_heap( m_AllNodes.begin(), m_AllNodes.end(), mComp );
			m_AllNodes.pop_back();
		}
		bool HasNode()
		{
			return m_AllNodes.size()>0;
		}
		void AdjustNode( std::vector<stPathHeapNode>::iterator iter )
		{
			std::push_heap( m_AllNodes.begin(), iter+1, mComp );
		}

	public:
		std::vector<stPathHeapNode> m_AllNodes;
		std::greater<stPathHeapNode> mComp;
	};
}

#endif