
#include "GridMap.h"

using namespace GridMove;

const int MAX_NAVIGRID = 5000;

bool  IsPointInCircle( int x, int y, int ox, int oy, int radius )
{
	int r2 = (x-ox)*(x-ox) + (y-oy)*(y-oy);
	return r2<radius*radius ? 1 : 0;
}

#define MY_PI 3.1415926f
inline float mycos( float angle )
{
	return cos(angle*MY_PI/180.0f);
}
inline float mysin( float angle )
{
	return sin(angle*MY_PI/180.0f);
}

int FaceAngleBetween( int from_x, int from_y, int to_x, int to_y )
{
	int dx = to_x - from_x;
	int dy = to_y - from_y;

	double length = sqrt(double(dx*dx + dy*dy));
	if( length < 0.5 ) return 0;

	double tmp = dx / length;
	double angle = acos(tmp) * 180 / MY_PI;
	if( dy < 0 ) angle = (360 - angle);

	return int(angle);
}

bool  IsPointInFan( int x, int y, int ox, int oy, int radius, int face_angle, int angle_range )
{
	float EPSILON = 5.0f;
	if( !IsPointInCircle(x, y, ox, oy, radius) ) return 0;

	float r = sqrt(float((x-ox)*(x-ox) + (y-oy)*(y-oy)));
	if( r < EPSILON ) return 1;

	float fangle = float(face_angle);
	float mydot = ((x-ox)/r)*mycos(fangle) + ((y-oy)/r)*mysin(fangle);
	return mydot>mycos(float(angle_range)*0.5f) ? 1 : 0;
}

bool  IsPointInRectangle( int x, int y, int ox, int oy, int xlen, int ylen, int face_angle )
{
	int x1 = (int)( (x-ox)*mycos((float)face_angle) + (y-oy)*mysin((float)face_angle) );
	int y1 = (int)( -(x-ox)*mysin((float)face_angle) + (y-oy)*mycos((float)face_angle) );

	if( x1>0 && x1<xlen && y1>-ylen/2 && y1<ylen/2 ) return 1;
	else return 0;
}

bool CNaviPath::IsPointInSegment( int x, int y, int x1, int y1, int x2, int y2 )
{
	if( x1 <= x2 )
	{
		if( x<x1 || x>x2 ) return false;
	}
	else if( x<x2 || x>x1 ) return false;

	if( y1 <= y2 )
	{
		if( y<y1 || y>y2 ) return false;
	}
	else if( y<y2 || y>y1 ) return false;

	int r = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
	if( r == 0 ) return true;
	int dist = (x-x1)*(y2-y1) - (y-y1)*(x2-x1);
	dist = dist*dist / r;

	return dist<=2;
}

bool CNaviPath::IsPointOnPath( const Point2D &pt )
{
	for( int i=0; i<int(m_Points.size())-1; i++ )
	{
		if( IsPointInSegment(pt.x, pt.y, m_Points[i].x, m_Points[i].y, m_Points[i+1].x, m_Points[i+1].y) ) return true;
	}
	return false;
}

int  CNaviPath::GetPathLength()
{
	int len = 0;
	for( int i=0; i<int(m_Points.size())-1; i++ )
	{
		stPathPoint &p1 = m_Points[i];
		stPathPoint &p2 = m_Points[i+1];

		len += (int)sqrt( float((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y) ));
	}

	return len;
}

Point2D CNaviPath::GetPathPosition(int curpt, int offset)
{
	if(curpt >= GetNumPoint()-1) return GetPathPoint(curpt);
	else
	{
		Point2D p1 = GetPathPoint(curpt);
		Point2D p2 = GetPathPoint(curpt+1);

		int seglen = GetPathSegLen(curpt);
		return Point2D(p1.x+(p2.x-p1.x)*offset/seglen, p1.y+(p2.y-p1.y)*offset/seglen);
	}
}

Point2D CNaviPath::MoveOnPath(int &curpt, int &offset, int movelen)
{
	offset += movelen;
	while(offset >= m_Points[curpt].len)
	{
		offset -= m_Points[curpt].len;
		curpt++;
		if(curpt == int(m_Points.size())-1)
		{
			offset = 0;
			return Point2D(m_Points[curpt].x, m_Points[curpt].y);
		}
	}

	return GetPathPosition(curpt, offset);
}

bool CNaviPath::IsPathOK(int curpt, int offset)
{
	assert(curpt < int(m_Points.size())-1);
	for(int i=0; i<3; i++)
	{
		while(offset >= m_Points[curpt].len)
		{
			offset -= m_Points[curpt].len;
			curpt++;
			if(m_pMap->GetGridUpdateTime(m_Points[curpt].x, m_Points[curpt].y) > m_GridUpdateAccum) return false;
			if(curpt == int(m_Points.size())-1) return true;
		}

		Point2D pos = GetPathPosition(curpt, offset);
		if(m_pMap->GetGridUpdateTime(pos.x, pos.y) > m_GridUpdateAccum) return false;

		offset += m_pMap->m_lMaskPixelWidth;
	}

	return true;
}

void CNaviPath::AddPathPoint( int x, int y )
{
	if( m_Points.size() > 0 )
	{
		stPathPoint &tmp = m_Points[m_Points.size()-1];
		if( x==tmp.x && y==tmp.y ) return;
	}
	stPathPoint pt;
	pt.x = x;
	pt.y = y;

	m_Points.push_back(pt);
}

void CNaviPath::Reset( CLogicMap *pmap )
{
	m_Points.resize(0);
	m_pMap = pmap; 
	m_GridUpdateAccum = pmap->m_GridUpdateAccum;
}

void CNaviPath::Revert()
{
	stPathPoint tmp;
	size_t num = m_Points.size();
	for(size_t i=0; i<num/2; i++)
	{
		tmp = m_Points[i];
		m_Points[i] = m_Points[num-1-i];
		m_Points[num-1-i] = tmp;
	}
}

int  CNaviPath::FindNextVisiblePoint( int i )
{
	assert( m_Points.size()>1 && i<int(m_Points.size()) );
	Point2D begin(m_Points[i].x, m_Points[i].y);

	int next = i+1;
	while( next < int(m_Points.size()) )
	{
		bool b = m_pMap->LineOfSightTest( begin, Point2D(m_Points[next].x, m_Points[next].y) );
		assert( b == m_pMap->LineOfSightTest1(begin, Point2D(m_Points[next].x, m_Points[next].y)) );
		if( !b ) break;
		next++;
	}
	return next-1;
}

void CNaviPath::LooseGoal( int radius ) //改变path, 让path的goal在和原来目标距离radius的地方
{
	if( radius <= 0 ) return;

	Point2D goal = GetPathGoal();
	int i;
	for( i=0; i<int(m_Points.size()); i++ )
	{
		int dx = m_Points[i].x - goal.x;
		int dy = m_Points[i].y - goal.y;
		if( dx*dx+dy*dy <= radius*radius ) break;
	}

	m_Points.resize(i+1);
}

void CNaviPath::SmoothPath()
{
	int begin = 0;
	while(1)
	{
		int end = FindNextVisiblePoint(begin);
		if( end == begin ) break; //到终点了
		if( end > begin+1 ) //之间有多余的路径点
		{
			m_Points.erase( m_Points.begin()+begin+1, m_Points.begin()+end );
		}
		begin++;
	}
}

void CNaviPath::ComputePathSegLen()
{
	for(size_t i=0; i<m_Points.size()-1; i++)
	{
		Point2D p1 = GetPathPoint((int)i);
		Point2D p2 = GetPathPoint((int)i+1);
		m_Points[i].len = (p2-p1).Length();
	}
	m_Points.back().len = 0;
}

CLogicMap::CLogicMap() : m_pMaskData(NULL), m_pVisitMap(NULL), m_GridUpdateTime(NULL)
{
	m_ClosedNodes.reserve( MAX_NAVIGRID );
}

CLogicMap::~CLogicMap()
{
	if(m_pMaskData) delete[] m_pMaskData;
	delete m_pVisitMap;
	if(m_GridUpdateTime) delete[] m_GridUpdateTime;
}

void CLogicMap::CreateGraph(int lenghA, int lenghB, int cellsA, int cellsB, unsigned char *pmskbits)
{
	m_lWidthMasks = cellsA;
	m_lHeightMasks = cellsB;

	m_lMaskPixelWidth = lenghA/m_lWidthMasks;
	m_lMaskPixelHeight = lenghB/m_lHeightMasks;

	m_lPlaneWidth = m_lWidthMasks*m_lMaskPixelWidth;
	m_lPlaneHeight = m_lHeightMasks*m_lMaskPixelHeight;

	m_pVisitMap = new BitArray2D(m_lWidthMasks, m_lHeightMasks);
	if(pmskbits)
	{
		m_pMaskData = new unsigned char[m_lWidthMasks*m_lHeightMasks];
		memcpy(m_pMaskData, pmskbits, m_lWidthMasks*m_lHeightMasks);
	}
	else memset(m_pMaskData, 0, m_lWidthMasks*m_lHeightMasks);

	m_GridUpdateTime = new unsigned int[m_lWidthMasks*m_lHeightMasks];
	memset(m_GridUpdateTime, 0, m_lWidthMasks*m_lHeightMasks*sizeof(int));
}

static Point2D s_EndGrid;
inline int ComputeHeuticsCost( int x, int y )
{
	return (abs(x-s_EndGrid.x) + abs(y-s_EndGrid.y))*2/3;
}
static std::vector<stPathHeapNode>::iterator FindHeapNodeInArray( std::vector<stPathHeapNode> &array, unsigned int index )
{
	std::vector<stPathHeapNode>::iterator iter = array.begin();
	for( ; iter!=array.end(); iter++ )
	{
		if( iter->index == index ) return iter;
	}
	return array.end();
}
void CLogicMap::TryGotoNeighbour( stPathHeapNode &from, int dx, int dy )
{
	int x1 = INDEX_TO_X(from.index) + dx;
	int y1 = INDEX_TO_Y(from.index) + dy;
	if( x1<0 || x1>=m_lWidthMasks || y1<0 || y1>=m_lHeightMasks ) return; //超出地图外

	unsigned char frombits = GetGridAttrib(INDEX_TO_X(from.index), INDEX_TO_Y(from.index));
	unsigned char tobits = GetGridAttrib(x1, y1);

	if( tobits & maskStatic )
	{
		return; //静态阻挡，不能通过
	}

	int addaval = int(tobits&maskDynamic) - int(frombits&maskDynamic);
	if(addaval < 0) addaval = 0;
	else addaval *= 5; //从低阻挡到高阻挡相当于绕5格
	
	unsigned int curindex = MAKEINDEX( x1, y1 );
	int aval = from.aval + addaval;
	if( m_pVisitMap->GetBit(x1,y1) )//已经访问过了
	{
		std::vector<stPathHeapNode>::iterator iter = FindHeapNodeInArray( m_PathHeap.m_AllNodes, curindex );
		if( iter != m_PathHeap.m_AllNodes.end() )
		{
			if( aval < iter->aval )
			{
				iter->aval = aval;
				iter->from = from.index;
				m_PathHeap.AdjustNode( iter );
			}
		}
		return;
	}

	stPathHeapNode tmpnode;
	tmpnode.from = from.index;
	tmpnode.index = curindex;
	tmpnode.aval = aval;
	tmpnode.hval = ComputeHeuticsCost(x1, y1);
	m_PathHeap.PushNode( tmpnode );

	m_pVisitMap->SetBit( x1, y1, 1 );
}

int CLogicMap::FindNaviPath_Internal( CNaviPath &path, const Point2D &start, const Point2D &input_end )
{
	Point2D scale(m_lMaskPixelWidth, m_lMaskPixelHeight);
	Point2D end = input_end;
	Point2D startgrid = start / scale;
	s_EndGrid = end / scale;

	if(!CanWalk(s_EndGrid.x, s_EndGrid.y, maskStatic))
	{
		if(!FindPointWalkable(end, 2, maskStatic)) return 1;
		s_EndGrid = end / scale;
	}

	m_pVisitMap->Clear();
	m_PathHeap.Init();
	m_ClosedNodes.resize(0);

	stPathHeapNode node;
	node.from = node.index = MAKEINDEX(startgrid.x, startgrid.y);
	node.hval = node.aval = 0;
	m_PathHeap.PushNode( node );
	m_pVisitMap->SetBit( startgrid.x, startgrid.y, 1 );

	bool bfind = false;
	unsigned int endindex = MAKEINDEX( s_EndGrid.x, s_EndGrid.y );
	while( m_PathHeap.HasNode() )
	{
		m_PathHeap.PopNode( node );
		m_ClosedNodes.push_back( node );
		if( m_ClosedNodes.size() >= size_t(MAX_NAVIGRID) ) break;

		if( node.index == endindex )
		{
			bfind = true;
			break;
		}
		else
		{
			TryGotoNeighbour( node, -1, 0 );
			TryGotoNeighbour( node, +1, 0 );
			TryGotoNeighbour( node, 0, -1 );
			TryGotoNeighbour( node, 0, +1 );
		}
	}

	if( bfind )
	{
		path.Reset(this);
		path.AddPathPoint( end.x, end.y );

		while( node.from != node.index )
		{
			int x = INDEX_TO_X(node.index)*m_lMaskPixelWidth + m_lMaskPixelWidth/2;
			int y = INDEX_TO_Y(node.index)*m_lMaskPixelHeight + m_lMaskPixelHeight/2;
			path.AddPathPoint( x, y );
			//assert( CanWalkPixelCoord(x, y ) );

			std::vector<stPathHeapNode>::iterator iter = FindHeapNodeInArray(m_ClosedNodes, node.from);
			assert( iter != m_ClosedNodes.end() );
			node = *iter;
		}

		path.AddPathPoint( start.x, start.y );
		path.Revert();
		//assert( CanWalkPixelCoord(pathend.x, pathend.y) );

		assert( path.m_Points.size() > 1 );
		return 0;
	}
	return 2;
}

bool CLogicMap::FindNaviPath( CNaviPath &path, const Point2D &start, const Point2D &end )
{
	int naviret = FindNaviPath_Internal( path, start, end );
	if( naviret == 0 ) return true;
	return false;

	/*
	for(int range=2; range<5; range+=2)
	{
		if(FindSimplePath_Internal( path, start, end, range )) return true;
	}*/

	/*
	Point2D tmpend(end);
	if(!FindPointWalkable(tmpend)) return false;
	if(0 == FindNaviPath_Internal(path, start, end)) return true;
	return false;
	*/
}

Point2D CLogicMap::DoMotion( const Point2D &start, const Point2D &delta )
{
	return start+delta;
}

//返回到下一个格子
static Point2D LineIntersectGrid( const Point2D &pt1, const Point2D &pt2, const Point2D &start, const Point2D &dp )
{
	/*
	int y = -1;
	if( dp.x > 0 ) y = dp.y*(pt2.x-start.x)/dp.x + start.y;
	else if( dp.x < 0 ) y = dp.y*(pt1.x-start.x)/dp.x + start.y;
	if( y>=pt1.y && y<=pt2.y )  //从边 x=sx或者x=ex出去这个格子
	{
	if( dp.x > 0 ) return Point2D(1, 0);
	else return Point2D(-1, 0);
	}
	else //从边 y=sy或者y=ey出去
	{
	if( dp.y > 0 ) return Point2D(0, 1);
	else return Point2D(0, -1);
	}
	*/

	int y1 = pt1.y*dp.x;
	int y2 = pt2.y*dp.x;
	if( dp.x > 0 )
	{
		int y = dp.y*(pt2.x-start.x) + start.y*dp.x;
		if( y == y2 ) return Point2D(1, 1);
		else if( y>=y1 && y<y2 ) return Point2D(1, 0);
	}
	else if( dp.x < 0 )
	{
		int y = dp.y*(pt1.x-start.x) + start.y*dp.x;

		if( y == y2 ) return Point2D(0, 1);
		else if( y>y2 && y<=y1 ) return Point2D(-1, 0);
	}

	if( dp.y > 0 ) return Point2D(0, 1);
	else return Point2D(0, -1);
}

bool CLogicMap::LineOfSightTest( const Point2D &start, const Point2D &end, int mask )
{
	Point2D step( m_lMaskPixelWidth, m_lMaskPixelHeight );
	Point2D startgrid( start.x/m_lMaskPixelWidth, start.y/m_lMaskPixelHeight );
	Point2D endgrid( end.x/m_lMaskPixelWidth, end.y/m_lMaskPixelHeight );
	Point2D dp = end - start;

	Point2D curgrid = startgrid;
	if( !CanWalk(curgrid.x, curgrid.y, mask) ) return false;
	while( curgrid != endgrid )
	{
		Point2D pt1 = curgrid * step;
		curgrid += LineIntersectGrid( pt1, pt1+step, start, dp );
		if( !CanWalk(curgrid.x, curgrid.y, mask) ) return false;
	}
	return true;
}

typedef struct {
	Point2D s_StartPt;
	Point2D s_dPt;
	Point2D s_CurGrid;
} GridPoint;

static void LineIntersectGrid(const Point2D *pt1, const Point2D *pt2, GridPoint *pstGP)
{
	int dx = pstGP->s_dPt.x;
	int y1 = pt1->y * dx;
	int y2 = pt2->y * dx;
	if( dx > 0 )
	{
		int y = pstGP->s_dPt.y*(pt2->x - pstGP->s_StartPt.x) + pstGP->s_StartPt.y*dx;
		if( y == y2 )
		{
			pstGP->s_CurGrid.x++;
			pstGP->s_CurGrid.y++;
			return;
		}
		if( y>=y1 && y<y2 )
		{
			pstGP->s_CurGrid.x++;
			return;
		}
	}
	else if( dx < 0 )
	{
		int y = pstGP->s_dPt.y*(pt1->x - pstGP->s_StartPt.x) + pstGP->s_StartPt.y*dx;
		if( y == y2 )
		{
			pstGP->s_CurGrid.y++;
			return;
		}
		if( y>y2 && y<=y1 )
		{
			pstGP->s_CurGrid.x--;
			return;
		}
	}

	if( pstGP->s_dPt.y > 0 ) pstGP->s_CurGrid.y++;
	else pstGP->s_CurGrid.y--;
}

bool CMapMask_IsPixelLineThrough(CLogicMap *pmap, int lPixelX1, int lPixelY1, int lPixelX2, int lPixelY2, int mask)
{
	Point2D pt1, pt2;
	int grid_sx;
	int grid_sy;
	int grid_ex;
	int grid_ey;
	GridPoint stGP;

	stGP.s_StartPt.x = lPixelX1;
	stGP.s_StartPt.y = lPixelY1;
	stGP.s_dPt.x = lPixelX2 - lPixelX1;
	stGP.s_dPt.y = lPixelY2 - lPixelY1;

	grid_sx = lPixelX1/pmap->m_lMaskPixelWidth;
	grid_sy = lPixelY1/pmap->m_lMaskPixelHeight;
	grid_ex = lPixelX2/pmap->m_lMaskPixelWidth;
	grid_ey = lPixelY2/pmap->m_lMaskPixelHeight;

	stGP.s_CurGrid.x = grid_sx;
	stGP.s_CurGrid.y = grid_sy;
	if( !pmap->CanWalk(grid_sx, grid_sy, mask) ) return false;
	while( stGP.s_CurGrid.x!=grid_ex || stGP.s_CurGrid.y!=grid_ey )
	{
		pt1.x = stGP.s_CurGrid.x * pmap->m_lMaskPixelWidth;
		pt1.y = stGP.s_CurGrid.y * pmap->m_lMaskPixelHeight;
		pt2.x = pt1.x + pmap->m_lMaskPixelWidth;
		pt2.y = pt1.y + pmap->m_lMaskPixelHeight;

		LineIntersectGrid(&pt1, &pt2, &stGP);
		if( !pmap->CanWalk(stGP.s_CurGrid.x, stGP.s_CurGrid.y, mask) ) return false; 
	}
	return true;
}

bool CLogicMap::LineOfSightTest1( const Point2D &start, const Point2D &end, int mask )
{
	return CMapMask_IsPixelLineThrough(this, start.x, start.y, end.x, end.y, mask );
}

bool CLogicMap::LineOfSightTest2( const Point2D &start, const Point2D &end, int mask )
{
	int   dx,dy,dm,dn,m,n,k,u,v,l,sum;

	dx = end.x - start.x, dy = end.y - start.y;
	if(dx == 0)
	{
		u = start.y, v = end.y;
		if(dy < 0) u = end.y, v = start.y;
		for (l = u; l <= v; l ++)
		{
			if( !CanWalkPixelCoord(end.x, l, mask) ) return false;
		}
		return true;
	}
	if(dy==0)
	{
		u = start.x, v = end.x;
		if(dx < 0) u = end.x,v = start.x;
		for(l = u; l <= v; l ++)
		{
			if( !CanWalkPixelCoord(l, end.y, mask) ) return false;
		}
		return true;
	}

	dm = dn = 1;
	if(dx < 0) dx = -dx, dm = -1;
	if(dy < 0) dy = -dy, dn = -1;
	m = dx, n = dy, k = 1, u = start.x, v = start.y;
	if(dx<dy) m = dy, n = dx, k = dm, dm = dn, dn = k, k = 0, u = start.y, v = start.x;
	l = 0;
	sum = m;

	if( !CanWalkPixelCoord(start.x, start.y, mask) ) return false;
	while (sum != 0)
	{
		sum--;
		l += n;
		u += dm;
		if(l >= m)
		{
			v += dn;
			l -= m;
		}
		if(k == 1)
		{
			if( !CanWalkPixelCoord(u, v, mask) ) return false;
		}
		else
		{
			if( !CanWalkPixelCoord(v, u, mask) ) return false;
		}
	}
	return true;
}

bool CLogicMap::FindPointWalkable( Point2D &point, int range, int mask )
{
	Point2D grid(point);
	CoordPixel2Grid( grid.x, grid.y );

	if( CanWalk(grid.x, grid.y, mask) ) return true;

	for( int i=1; i<=range; i++ )
	{
		int x, y;
		unsigned int flags = 0;
		int sx = grid.x - i; if( sx < 0 ) { sx = 0; flags |= 1; }
		int sy = grid.y - i; if( sy < 0 ) { sy = 0; flags |= 2; }
		int ex = grid.x + i; if( ex >= m_lWidthMasks ) { ex = m_lWidthMasks-1; flags |= 4; }
		int ey = grid.y + i; if( ey >= m_lHeightMasks ) { ey = m_lHeightMasks-1; flags |= 8; }

		if( !(flags&2) )
		{
			for( x=sx; x<=ex; x++ )
			{
				if( CanWalk(x, sy, mask) ){ point.x=x, point.y=sy; goto find_end; }
			}
		}

		if( !(flags&8) )
		{
			for( x=sx; x<=ex; x++ )
			{
				if( CanWalk(x, ey, mask) ){ point.x=x, point.y=ey; goto find_end; }
			}
		}

		if( !(flags&1) )
		{
			for( y=sy+1; y<=ey-1; y++ )
			{
				if( CanWalk(sx, y, mask) ){ point.x=sx, point.y=y; goto find_end; }
			}
		}

		if( !(flags&4) )
		{
			for( y=sy+1; y<=ey-1; y++ )
			{
				if( CanWalk(ex, y, mask) ){ point.x=ex, point.y=y; goto find_end; }
			}
		}
	}
	return false;

find_end:
	CoordGrid2Pixel( point.x, point.y );
	return true;
}

bool CLogicMap::CanWalkPixelCoord( int x, int y, int mask )
{
	if( !IsPointInMap(Point2D(x,y)) ) return false;

	int x1(x), y1(y); 
	CoordPixel2Grid(x1, y1);
	return CanWalk(x1,y1,mask);
}

bool CLogicMap::IsInSameGrid(const Point2D &p1, const Point2D &p2)
{
	if((p1.x/m_lMaskPixelWidth) == (p2.x/m_lMaskPixelWidth) && (p1.y/m_lMaskPixelHeight) == (p2.y/m_lMaskPixelHeight)) return true;
	else return false;
}

void CLogicMap::UpdateMask(int x1, int y1, int x2, int y2, bool b)
{
	m_GridUpdateAccum++;

	assert(x1<x2 && y1<y2);
	if(x1<0) x1 = 0;
	if(y1<0) y1 = 0;
	if(x2 >= m_lPlaneWidth) x2 = m_lPlaneWidth-1;
	if(y2 >= m_lPlaneHeight) y2 = m_lPlaneHeight-1;

	int gx1(x1), gx2(x2), gy1(y1), gy2(y2);
	CoordPixel2Grid(gx1, gy1);
	CoordPixel2Grid(gx2, gy2);

	for(int y=gy1; y<=gy2; y++)
	{
		for(int x=gx1; x<=gx2; x++)
		{
			unsigned char &bits = m_pMaskData[y*m_lWidthMasks+x];
			if(b)
			{
				m_GridUpdateTime[y*m_lWidthMasks+x] = m_GridUpdateAccum;
				bits++;
				//assert(bits < maskDynamic);
			}
			else
			{
				assert(bits > 0);
				bits--;
			}
		}
	}
}

unsigned int CLogicMap::GetGridUpdateTime(int x, int y)
{
	int gx(x), gy(y);
	CoordPixel2Grid(gx, gy);

	return m_GridUpdateTime[gy*m_lWidthMasks+gx];
}

class stGoalGrid
{
public:
	~stGoalGrid()
	{

	}
	stGoalGrid()
	{

	}

	bool operator < (const stGoalGrid &rhs ) const
	{
		return dirprior < rhs.dirprior;
	}

	Point2D grid;
	int dirprior; //距离越小，优先级越大
};

bool CLogicMap::FindSimplePath_Internal( CNaviPath &path, const Point2D &start, const Point2D &end, int range )
{
	stGoalGrid gridbuf[100];
	int count = 0;
	assert(range*4 <= 100);

	Point2D endgrid( end.x/m_lMaskPixelWidth, end.y/m_lMaskPixelHeight );
	for( int y=endgrid.y-range; y<=endgrid.y+range; y++ )
	{
		if( y<0 || y>=m_lHeightMasks ) continue;
		int x1 = endgrid.x-range;
		int x2 = endgrid.x+range;

		if(x1>=0 && CanWalk(x1,y)) gridbuf[count++].grid = Point2D(x1, y);
		if(x2<m_lWidthMasks && CanWalk(x2,y)) gridbuf[count++].grid = Point2D(x2, y);
	}

	for( int x=endgrid.x-range+1; x<=endgrid.x+range-1; x++ )
	{
		if( x<0 || x>=m_lWidthMasks ) continue;
		int y1 = endgrid.y-range;
		int y2 = endgrid.y+range;

		if(y1>=0 && CanWalk(x,y1)) gridbuf[count++].grid = Point2D(x, y1);
		if(y2<m_lHeightMasks && CanWalk(x,y2)) gridbuf[count++].grid = Point2D(x, y2);
	}

	if( count == 0 ) return false;
	assert( count < 100 );

	//对每个goalgrid, 计算寻路优先级
	Point2D dp = end - start;
	Point2D step( m_lMaskPixelWidth, m_lMaskPixelHeight );
	Point2D halfstep( m_lMaskPixelWidth/2, m_lMaskPixelHeight/2 );

	int i;
	for( i=0; i<count; i++ )
	{
		Point2D goalpt = gridbuf[i].grid * step + halfstep - start;
		gridbuf[i].dirprior = goalpt.x*dp.x + goalpt.y*dp.y;
	}

	std::sort( &gridbuf[0], &gridbuf[count] );

	for( i=0; i<1/*count*/; i++ )
	{
		Point2D goalpt = gridbuf[i].grid * step + halfstep;
		if(start == goalpt) continue;
		if( FindNaviPath_Internal(path, start, goalpt) == 0) return true;
	}
	return false;
}

bool CLogicMap::FindDirFaceMask( Point2D &point, const Point2D &center, int radius, int mask )
{
	const int NUM_SEG = 18; //把圆周分为多少等分
	const float TWOPI = 3.1415926f * 2;

	for( int i=0; i<NUM_SEG; i++ )
	{
		float angle = i*TWOPI/NUM_SEG;
		int x = int(center.x + radius*cos(angle));
		int y = int(center.y + radius*sin(angle));
		if( !CanWalkPixelCoord(x, y, mask) )
		{
			point.x = x;
			point.y = y;
			return true;
		}
	}
	return false;
}
