
#ifndef __WAVREADER_H__
#define __WAVREADER_H__

#include "PX2SmartPointer.hpp"
#include <vector>

namespace PX2
{
	class WavReader
	{
	public:
		WavReader();
		~WavReader();

		bool LoadFromFile(const char *path);
		bool LoadFromBuffer(const void *buffer, int buflen);
		short *GetSamples()
		{
			return &mSamples[0];
		}
		int GetSampleCount()
		{
			return int(mSamples.size());
		}
		int GetChannels()
		{
			return mChannels;
		}
		int GetHerz()
		{
			return mHerz;
		}

	private:
		bool ReadWave(const char *path);

	private:
		int mHerz;
		int mChannels;
		int mSampleBits;
		std::vector<short>mSamples;
	};

	typedef Pointer0<WavReader> WavReaderPtr;
}

#endif