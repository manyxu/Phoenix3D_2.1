
#include "PX2WavReader.hpp"

using namespace PX2;

class MemoryFile
{
public:
	MemoryFile(const void *data, size_t len) : mBuffer((const char *)data), mBufLen(len), mCurPos(0)
	{
	}
	~MemoryFile()
	{
	}

	size_t Read(void *dstbuf, size_t len)
	{
		if(len > mBufLen-mCurPos) len = mBufLen-mCurPos;

		if(len > 0)
		{
			memcpy(dstbuf, &mBuffer[mCurPos], len);
			mCurPos += len;
		}

		return len;
	}

	size_t Tell()
	{
		return mCurPos;
	}

	void Seek(size_t pos)
	{
		mCurPos = pos;
	}

	size_t GetSize()
	{
		return mBufLen;
	}

private:
	const char *mBuffer;
	size_t mBufLen;
	size_t mCurPos;
};

// Format tags
#define WAVE_FORMAT_UNKNOWN 0x0000
#define WAVE_FORMAT_PCM     0x0001
#define WAVE_FORMAT_ADPCM   0x0002

typedef unsigned int uint32;
typedef unsigned short uint16;

// Data structures
typedef struct IwRIFFHeader
{
	char    typeID[4];          //!< ID string - Expect "RIFF"
	uint32  length;             //!< Length of data after this field (i.e. including rest of this struct)
	char    subTypeID[4];       //!< Sub-type ID string - Expect "WAVE"
} IwRIFFHeader;

typedef struct IwRIFFChunkHeader
{
	char    typeID[4];          //!< ID string - Either "fmt " or "data"
	uint32  length;             //!< Length of data after this field
} IwRIFFChunkHeader;

typedef struct IwWAVEFormatChunk
{
	uint16  formatTag;          //!< Format category
	uint16  channels;           //!< Number of channels
	uint32  samplesPerSec;      //!< Sampling rate
	uint32  avgBytesPerSec;     //!< For buffer estimation
	uint16  blockAlign;         //!< Data block size
	uint16  bitsPerSample;      //!< Bits per sample - Should be 8 or 16
} IwWAVEFormatChunk;


typedef struct IwWAVEFormatChunkADPCM
{
	uint16  formatTag;          //!< Format category
	uint16  channels;           //!< Number of channels
	uint32  samplesPerSec;      //!< Sampling rate
	uint32  avgBytesPerSec;     //!< For buffer estimation
	uint16  blockAlign;         //!< Data block size
	uint16  bitsPerSample;      //!< Bits per sample - Should be 8 or 16
	uint16  cbSize;             //!< The size in bytes of the extra information in the extended WAVE 'fmt' header. This should be 2 for adpcm.
	uint16  samplesPerBlock;    //!< The number of samples in each adpcm block
} IwWAVEFormatChunkADPCM;

bool ReadChunkFormat(const IwRIFFChunkHeader& header, MemoryFile &memfp, int &herz, int &samplebits, int &channels)
{
	IwWAVEFormatChunkADPCM format;

	// Read data from file
	if ((header.length < sizeof(IwWAVEFormatChunk))	|| (memfp.Read(&format, sizeof(IwWAVEFormatChunkADPCM)) != sizeof(IwWAVEFormatChunkADPCM)))
	{
		assert(0);
		return false;
	}

	assert(format.channels==1 && format.bitsPerSample==16 && format.samplesPerSec==22050);
	if((format.channels!=1&&format.channels!=2) || format.formatTag!=WAVE_FORMAT_PCM)
	{
		return false;
	}

	if(format.bitsPerSample != 16 && format.bitsPerSample!=8)
	{
		return false;
	}

	samplebits = format.bitsPerSample;
	herz = format.samplesPerSec;
	channels = format.channels;
	return true;
}
//-------------------------------------------------------------------------
bool ReadChunkData(const IwRIFFChunkHeader& header, MemoryFile &memfp, std::vector<short>&data, int samplebits)
{
	size_t len = data.size();

	if(samplebits == 16)
	{
		data.resize(len+header.length/2);
		if(memfp.Read(&data[len], header.length) != header.length)
		{
			return false;
		}
	}
	else
	{
		std::vector<char>bit8data(header.length);
		if(memfp.Read(&bit8data[0], header.length) != header.length)
		{
			return false;
		}

		data.resize(len+header.length);
		for(int i=0; i<header.length; i++)
		{
			data[len+i] = bit8data[i]*256;
		}
	}
	return true;
}
//-------------------------------------------------------------------------
bool ReadChunkFact(const IwRIFFChunkHeader& header, MemoryFile &memfp, int &sampleCount)
{
	if (memfp.Read(&sampleCount, sizeof(int)) != sizeof(int))
	{
		return false;
	}

	return true;
}

WavReader::WavReader(): mHerz(0), mChannels(0), mSampleBits(0)
{
}

WavReader::~WavReader()
{
}

bool WavReader::LoadFromFile(const char *path)
{
	FILE *fp = fopen(path, "rb");
	if(fp == NULL) return false;

	fseek(fp, 0, SEEK_END);
	int len = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	void *buffer = malloc(len);
	fread(buffer, len, 1, fp);
	fclose(fp);

	bool b = LoadFromBuffer(buffer, len);
	free(buffer);
	return b;
}

bool WavReader::LoadFromBuffer(const void *buffer, int buflen)
{
	MemoryFile memfp(buffer, buflen);
	IwRIFFHeader riffHeader;
	if(memfp.Read(&riffHeader, sizeof(riffHeader))!=sizeof(riffHeader) || (strncmp(riffHeader.typeID, "RIFF", 4) != 0) ||
		(strncmp(riffHeader.subTypeID, "WAVE", 4) != 0))
	{
		return false;
	}

	IwRIFFChunkHeader chunkHeader;
	while (memfp.Read(&chunkHeader, sizeof(chunkHeader)) == sizeof(chunkHeader))
	{
		size_t chunkStartPos = memfp.Tell();

		// Next action depends on chunk type. The order of this is important and we may fail
		// if an unexpected chunk type is found
		if (!strncmp(chunkHeader.typeID, "fmt ", 4))
		{
			// Read WAVE info chunk
			if (!ReadChunkFormat(chunkHeader, memfp, mHerz, mSampleBits, mChannels))
			{
				return false;
			}
		}
		else if (!strncmp(chunkHeader.typeID, "data", 4))
		{
			if (!ReadChunkData(chunkHeader, memfp, mSamples, mSampleBits))
			{
				return false;
			}
		}
		else if (!strncmp(chunkHeader.typeID, "fact", 4))
		{
			int samplecount;
			if (!ReadChunkFact(chunkHeader, memfp, samplecount))
			{
				return false;
			}
		}
		else
		{
			// Unknown chunk type
			// Make a proper string from the chunk type info
			char typeID[5];
			strncpy(typeID, chunkHeader.typeID, 4);
			typeID[4] = 0;  // Terminate

			const char* g_IgnoreTypes = "LIST" //LIST is just copyright info etc.
				"DISP";  //DISP seems to be info about what package exported it

			//IwAssertMsg(SOUND, strstr(g_IgnoreTypes, typeID), ("Unhandled chunk type '%s' in %s. Ignoring this data.", typeID, m_Pathname.c_str()));
		}

		// Exit if at end of file
		if (chunkStartPos + chunkHeader.length >= memfp.GetSize())
			break;

		// Move to next chunk
		memfp.Seek(chunkStartPos + chunkHeader.length);
	}
	
	return true;
}
