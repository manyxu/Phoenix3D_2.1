// PX2Smoother.hpp

#ifndef PX2SMOOTHER_HPP
#define PX2SMOOTHER_HPP

#include "PX2CorePre.hpp"

namespace PX2
{

	template <typename T>
	class Smoother 
	{
	public:
		Smoother (int sampleSize, T zeroValue)
			:
		mHistory(sampleSize, zeroValue),
			mZeroValue(zeroValue),
			mNextUpdateSlot(0)
		{
		}
		~Smoother () {}

		T Update (const T &mostRecentValue)
		{
			mHistory[mNextUpdateSlot++] = mostRecentValue;

			if (mNextUpdateSlot == (int)mHistory.size())
				mNextUpdateSlot = 0;

			T sum = mZeroValue;

			typename std::vector<T>::iterator it = mHistory.begin();
			for (; it!=mHistory.end(); ++it)
			{
				sum += *it;
			}

			return sum/(float)mHistory.size();
		}

	protected:
		std::vector<T> mHistory;
		int mNextUpdateSlot;
		T mZeroValue;
	};

}

#endif