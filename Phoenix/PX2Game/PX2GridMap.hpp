
#ifndef _PX2GRIDMAP_HPP_
#define _PX2GRIDMAP_HPP_

#include "PX2Heapnode.hpp"
#include <assert.h>

namespace PX2
{
	const float FIXPOINT_SCALE = 100.0f;

	class BitArray1D
	{
	public:
		BitArray1D( int len ) : m_NumBits(len)
		{
			m_BufLen = (m_NumBits+31)/32;
			m_pData = new unsigned int[m_BufLen];
		}
		~BitArray1D()
		{
			delete[] m_pData;
		}
		void Clear()
		{
			memset( m_pData, 0, m_BufLen*4 );
		}
		int GetBit( int i )
		{
			return (m_pData[i>>5] >> (i&31)) & 1;
		}
		void SetBit( int i, int bit )
		{
			unsigned int &data = m_pData[i>>5];
			int ibit = i&31;
			data = (data & ~(1<<ibit)) | (bit<<ibit);
		}

	private:
		unsigned int *m_pData;
		int m_NumBits;
		int m_BufLen;
	};
	class BitArray2D
	{
	public:
		BitArray2D( int nbitx, int nbity ) : m_nBitX(nbitx), m_nBitY(nbity), m_BitArray(nbitx*nbity)
		{
		}
		~BitArray2D()
		{
		}
		void Clear()
		{
			m_BitArray.Clear();
		}
		int GetBit( int x, int y )
		{
			return m_BitArray.GetBit( y*m_nBitX+x );
		}
		void SetBit( int x, int y, int bit )
		{
			m_BitArray.SetBit( y*m_nBitX+x, bit );
		}

		int GetWidth(){ return m_nBitX; }
		int GetHeight(){ return m_nBitY; }

	private:
		BitArray1D m_BitArray;
		int m_nBitX, m_nBitY;
	};
	class Point2D
	{

	public:

		Point2D(){x=0;y=0;}
		Point2D( int x1, int y1 ) : x(x1), y(y1){}
		Point2D( const Point2D &rhs ) : x(rhs.x), y(rhs.y){}
		Point2D &operator =( const Point2D &rhs ){ x=rhs.x, y=rhs.y; return *this; }
		Point2D operator +( const Point2D &rhs ) const
		{
			return Point2D(x+rhs.x, y+rhs.y);
		}
		Point2D operator -( const Point2D &rhs ) const
		{
			return Point2D(x-rhs.x, y-rhs.y);
		}
		Point2D operator *( const Point2D &rhs ) const
		{
			return Point2D(x*rhs.x, y*rhs.y);
		}
		Point2D operator /( const Point2D &rhs ) const
		{
			return Point2D(x/rhs.x, y/rhs.y);
		}

		Point2D operator *( int scale ) const
		{
			return Point2D(x*scale, y*scale);
		}

		Point2D operator /( int scale ) const
		{
			return Point2D(x/scale, y/scale);
		}

		bool operator==( const Point2D &rhs ) const
		{
			return x==rhs.x && y==rhs.y;
		}

		bool operator!=( const Point2D &rhs ) const
		{
			return x!=rhs.x || y!=rhs.y;
		}

		Point2D &operator +=( const Point2D &rhs )
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		Point2D &operator -=( const Point2D &rhs )
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		Point2D &operator *=( float scale )
		{
			x = int(x*scale);
			y = int(y*scale);
			return *this;
		}

		Point2D &operator /=( float scale )
		{
			x = int(x/scale);
			y = int(y/scale);
			return *this;
		}

		int LengthSq(){ return x*x+y*y; }
		int Length(){ return (int)sqrt(double(x*x+y*y)); }

	public:

		int x;
		int y;

	};

	class CLogicMap;

	//寻路结果
	class CNaviPath
	{
		friend class CLogicMap;

		struct stPathPoint
		{
			int x; //虚拟屏幕上的像素坐标
			int y;
		};
		std::vector<stPathPoint>m_Points;
		CLogicMap *m_pMap;

	public:
		CNaviPath() : m_pMap(NULL){}
		void Reset( CLogicMap *pmap ){ m_Points.resize(0); m_pMap = pmap; }
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
		int  GetNumPoint(){ return (int)m_Points.size(); }
		void LooseGoal( int radius ); //改变path, 让path的goal在和原来目标距离radius的地方
		void SmoothPath();
		void LimitPathPoint( int number )
		{
			assert( number >= 2 );
			if( number >= int(m_Points.size()) ) return;

			m_Points.resize( number );
		}

		bool IsPointOnPath( const Point2D &pt );
		int  GetPathLength();

		static bool IsPointInSegment( int x, int y, int x1, int y1, int x2, int y2 );
	};

	class CLogicMap
	{
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

		void CreateGraph(float lenghA, float lenghB, int cellsA, int cellsB);

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
		bool FindPointWalkable( Point2D &point, int range=50 );
		bool CanWalkPixelCoord( int x, int y, int mask=maskStop );
		bool IsInSameGrid(const Point2D &p1, const Point2D &p2);
		bool UpdateMask(int x, int y, bool b);

		bool CanWalkGridCoord( int x, int y, int mask=maskStop )
		{
			return CanWalk( x, y, mask );
		}

		bool IsPointInMap( Point2D &point )
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

		//找出从start往end走，最远的直线路径
		bool FindSimplePath_Internal( CNaviPath &path, const Point2D &start, const Point2D &end );
	};
}

#endif