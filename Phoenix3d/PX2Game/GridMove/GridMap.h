
#ifndef __GRIDMAP_H__
#define __GRIDMAP_H__

#include "PX2GamePre.hpp"
#include "HeapNode.h"
#include "BitArray.h"
#include "Point2D.h"


namespace GridMove
{
	const float FIXPOINT_SCALE = 100.0f;
	class CLogicMap;

	//寻路结果
	class CNaviPath
	{
		friend class CLogicMap;

		struct stPathPoint
		{
			int x; //虚拟屏幕上的像素坐标
			int y;
			int len; //从这个节点到下个点的距离
		};
		std::vector<stPathPoint>m_Points;
		CLogicMap *m_pMap;
		unsigned int m_GridUpdateAccum;

	public:
		CNaviPath() : m_pMap(NULL){}
		void Reset(CLogicMap *pmap);
		void Revert();
		void AddPathPoint( int x, int y );
		int  FindNextVisiblePoint( int i );
		Point2D GetPathPoint( int i )
		{ 
			assert( i < (int)m_Points.size() );
			return Point2D(m_Points[i].x, m_Points[i].y); 
		}
		Point2D GetPathGoal()
		{
			assert( (int)m_Points.size() > 1 );
			stPathPoint &pt = m_Points[ m_Points.size()-1 ];
			return Point2D( pt.x, pt.y );
		}
		int GetPathSegLen(int i)
		{
			assert(i<int(m_Points.size())-1);
			return m_Points[i].len;
		}
		int  GetNumPoint(){ return int(m_Points.size()); }
		void LooseGoal( int radius ); //改变path, 让path的goal在和原来目标距离radius的地方
		void SmoothPath();
		void ComputePathSegLen();
		void LimitPathPoint( int number )
		{
			assert( number >= 2 );
			if( number >= int(m_Points.size()) ) return;

			m_Points.resize( number );
		}

		Point2D MoveOnPath(int &curpt, int &offset, int movelen); //返回当前坐标点
		bool IsPointOnPath( const Point2D &pt );
		int  GetPathLength();
		Point2D GetPathPosition(int curpt, int offset);
		bool IsPathOK(int curpt, int offset);

		static bool IsPointInSegment( int x, int y, int x1, int y1, int x2, int y2 );
	};

	class CLogicMap
	{
		friend class CNaviPath;
	public:
		enum MaskBits
		{
			maskDynamic			=   0x7f,   // 角色的阻挡，设置+1， 离开-1
			maskStatic			=   0x80,   // 地图本身阻挡
			maskStop            =   0xff,   //  
		};
		enum MaskPathResults
		{
			maskPathArrive      =   0,  //已經達到
			maskPathFound       =   1,  //找到可以到達的路徑
			maskPathNear        =   2,  //靠近目標
			maskPathFail        =   3,  //尋徑失敗
			maskPathError       =   -1, //錯誤
		};
		enum MaskStepResults
		{
			maskStepArrive      =   0,  //到達
			maskStepOnTheWay    =   1,   //在途中
			maskStepObstruct    =   2,   //被阻隔
			maskStepOutstretch  =   3,   //超出範圍
		};

	public:
		CLogicMap();
		~CLogicMap();

		void CreateGraph(int lenghA, int lenghB, int cellsA, int cellsB, unsigned char *pmskbits=NULL);

		bool FindNaviPath( CNaviPath &path, const Point2D &start, const Point2D &end );

		/**
		* 从开始点移动到结束点，只到碰到阻挡
		* \param start 开始点，以像素为单位
		* \param delta 移动矢量，以像素为单位
		* \return 移动的结束点
		*/
		Point2D DoMotion( const Point2D &start, const Point2D &delta );

		/**
		* 测试是否能够直线从start移动到end
		*/
		bool LineOfSightTest( const Point2D &start, const Point2D &end, int mask=maskStop );
		bool LineOfSightTest1( const Point2D &start, const Point2D &end, int mask=maskStop );
		bool LineOfSightTest2( const Point2D &start, const Point2D &end, int mask=maskStop );

		/**
		* 根据输入的点，在附近找出能走的点，从此点往周围扩散着找
		* \return 是否能够找到
		*/
		bool FindPointWalkable( Point2D &point, int range=50, int mask=maskStatic );
		bool CanWalkPixelCoord( int x, int y, int mask=maskStop );
		bool IsInSameGrid(const Point2D &p1, const Point2D &p2);
		void UpdateMask(int x1, int y1, int x2, int y2, bool b);
		unsigned int GetGridUpdateTime(int x, int y);

		bool CanWalkGridCoord( int x, int y, int mask=maskStop )
		{
			return CanWalk( x, y, mask );
		}

		bool IsPointInMap( const Point2D &point )
		{
			return point.x>=0 && point.x<m_lPlaneWidth && point.y>=0 && point.y<m_lPlaneHeight;
		}

		//在半径为radius的圆圈上找一个方向，使得面对mask(比如水层)
		bool FindDirFaceMask( Point2D &point, const Point2D &center, int radius, int mask );

	public:
		int   m_lWidthMasks;
		int   m_lHeightMasks;
		int   m_lMaskPixelWidth;
		int   m_lMaskPixelHeight;
		int   m_lPlaneWidth;
		int   m_lPlaneHeight;
		unsigned char *m_pMaskData;
		unsigned int *m_GridUpdateTime;
		unsigned int m_GridUpdateAccum;

		CPathHeap m_PathHeap;
		BitArray2D *m_pVisitMap;
		std::vector<stPathHeapNode>m_ClosedNodes;

		void TryGotoNeighbour( stPathHeapNode &node, int dx, int dy );

		unsigned char GetGridAttrib( int x, int y )
		{ 
			return m_pMaskData[y*m_lWidthMasks+x]; 
		}

		bool CanWalk( int x, int y, int mask=maskStop )
		{ 
			return (m_pMaskData[y*m_lWidthMasks+x]&mask)==0;
		}

		void CoordPixel2Grid( int &x, int &y )
		{ 
			x/=m_lMaskPixelWidth, y/=m_lMaskPixelHeight; 
		}

		void CoordGrid2Pixel( int &x, int &y )
		{ 
			x = x*m_lMaskPixelWidth+m_lMaskPixelWidth/2;
			y = y*m_lMaskPixelHeight+m_lMaskPixelHeight/2;
		}

		/**
		* 从开始点到结束点之间找出一条路经
		* \param path 用于存储返回的路径
		* \param start 开始点，以像素为单位
		* \param end 结束点，以像素为单位
		* \return 0: 成功， 
		*         1：程序逻辑错误（比如上次走到阻挡格里面去了）
		*         2：寻路节点过多，停止寻路，
		*         3: 起始点和目标点是同一个点
		*/
		int FindNaviPath_Internal( CNaviPath &path, const Point2D &start, const Point2D &end );

		//在目标点周围找目标点
		bool FindSimplePath_Internal( CNaviPath &path, const Point2D &start, const Point2D &end , int range);
	};
}

#endif