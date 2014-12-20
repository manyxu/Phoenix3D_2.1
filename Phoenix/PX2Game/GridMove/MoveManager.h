
#ifndef __MOVEMANAGER_H__
#define __MOVEMANAGER_H__

#include "PX2GamePre.hpp"
#include "PX2Singleton.hpp"
#include "GridMovePre.h"
#include <vector>
#include <string>

#ifdef USE_RVO
namespace RVO
{
	class RVOSimulator;
}
#endif

namespace GridMove
{
	class MoveUnit;
	class CLogicMap;

	class MoveManager : public PX2::Singleton<MoveManager>
	{
	public:
		MoveManager();
		~MoveManager();
		
		void Clear ();
		void Reset(float xlen, float ylen, int xcells, int ycells);
		void Reset(float xlen, float ylen, const std::string &mskpath);

		MoveUnit *NewUnit();
		void FreeUnit(MoveUnit *unit);

		std::size_t GetNumUnit();
		MoveUnit *GetIthUnit(std::size_t i);

		void Update(float dtime);

		bool CanWalk(float x, float y);
		float GetGridSizeX();
		float GetGridSizeY();
		float GetGridNumX();
		float GetGridNumY();
		void LimitPointInRange(float &x, float &y);
		CLogicMap *GetMap()
		{
			return mMap;
		}

	private:
		std::vector<MoveUnit *>mUsedUnits;
		std::vector<MoveUnit *>mFreeUnits;

#ifdef USE_RVO
		RVO::RVOSimulator *mSimulator;
#endif

		float mFrameTime;
		float mAccumTime;

		CLogicMap *mMap;
	};

}

#endif