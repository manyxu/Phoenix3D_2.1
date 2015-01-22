/*
*
* ÎÄ¼þÃû³Æ	£º	PX2StringHelp.cpp
*
*/

#include "PX2StringHelp.hpp"
#include "PX2Assert.hpp"
using namespace PX2;
using namespace std;

#ifdef WIN32
	#include <Windows.h>
#endif

//----------------------------------------------------------------------------
#define MPQ_TOOLS_BUFSIZE 0x500
static unsigned int	mpqBuffer[MPQ_TOOLS_BUFSIZE];
static void InitMPQBuffer()
{
	unsigned int seed   = 0x00100001;
	unsigned int index1 = 0;
	unsigned int index2 = 0;
	int i;

	for (index1 = 0; index1 < 0x100; index1++)
	{
		for(index2 = index1, i = 0; i < 5; i++, index2 += 0x100)
		{
			unsigned int temp1, temp2;
			seed  = (seed * 125 + 3) % 0x2AAAAB;
			temp1 = (seed & 0xFFFF) << 0x10;

			seed  = (seed * 125 + 3) % 0x2AAAAB;
			temp2 = (seed & 0xFFFF);

			mpqBuffer[index2] = (temp1 | temp2);
		}
	}
}
//----------------------------------------------------------------------------
bool StringHelp::Initlize()
{
	InitMPQBuffer();

	return true;
}
//----------------------------------------------------------------------------
std::string StringHelp::StandardisePath (const std::string &path)
{
	std::string strPath = path;
	
	std::replace(strPath.begin(), strPath.end(), '\\', '/');

	if (strPath[strPath.length() - 1] != '/')
		strPath += '/';

	return strPath;
}
//----------------------------------------------------------------------------
void StringHelp::SplitFilename (const std::string &fullName,
						   std::string &outPath, std::string &outBaseFileName)
{
	std::string path = fullName;

	// Replace \ with / first
	std::replace(path.begin(), path.end(), '\\', '/');
	// split based on final /

	size_t i = path.find_last_of('/');

	if (i == std::string::npos)
	{
		outPath.clear();
		outBaseFileName = fullName;
	}
	else
	{
		outPath = path.substr(0, i+1);
		outBaseFileName = path.substr(i+1, path.size()-i-1);
	}
}
//----------------------------------------------------------------------------
void StringHelp::SplitFullFilename (const std::string &fullName,
							   std::string &outPath,
							   std::string &outBaseName,
							   std::string &outExtention)
{
	std::string outName;
	SplitFilename(fullName, outPath, outName);
	SplitBaseFilename(outName, outBaseName, outExtention);
}
//----------------------------------------------------------------------------
void StringHelp::SplitBaseFilename (const std::string &baseFileName,
							   std::string &outBaseName,
							   std::string &outExtention)
{
	size_t i = baseFileName.find_last_of(".");

	if (i == std::string::npos)
	{
		outExtention.clear();
		outBaseName = baseFileName;
	}
	else
	{
		outExtention = baseFileName.substr(i+1);
		outBaseName = baseFileName.substr(0, i);
	}
}
//----------------------------------------------------------------------------
std::string StringHelp::PathToWindowStyle (const std::string &fromPath)
{
	std::string path = fromPath;
	std::replace(path.begin(), path.end(), '/', '\\');

	return path;
}
//----------------------------------------------------------------------------
const size_t MAX_CONVERT = 4096*2;
static char s_DBCSBuffer[MAX_CONVERT];
static wchar_t s_UnicodeBuffer[MAX_CONVERT];
//----------------------------------------------------------------------------
int StringHelp::UnicodeToAnsi (char *dest, int maxChar, const wchar_t *src,
						  int numSrcChar)
{
#ifdef WIN32

	int nchar;
#ifdef _DEBUG
	nchar = WideCharToMultiByte(CP_ACP, WC_SEPCHARS|WC_COMPOSITECHECK, src, 
		numSrcChar, dest, 0, NULL, NULL );
	assertion(nchar<maxChar, "");
#endif
	nchar = WideCharToMultiByte(
		CP_ACP,
		WC_SEPCHARS | WC_COMPOSITECHECK,
		src,
		numSrcChar,
		dest,
		maxChar,
		NULL,
		NULL);
	assertion (nchar>0, "");
	return nchar;
#else

	assertion(false, "Not supported on other platform.");

	return 0;

#endif
}
//----------------------------------------------------------------------------
int StringHelp::AnsiToUnicode (wchar_t *dest, int maxChar, const char *src, 
						  int numSrcChar)
{
	#ifdef WIN32

	int nchar;
#ifdef _DEBUG
	nchar = MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, src, numSrcChar, dest, 0);
	assertion(nchar<=maxChar, "");
#endif
	nchar = MultiByteToWideChar(
		CP_ACP,
		MB_PRECOMPOSED,
		src,
		numSrcChar,
		dest,
		maxChar);
	assertion (nchar>0, "");
	return nchar;

#else

	assertion(false, "Not supported on other platform.");

	return 0;

#endif
}
//----------------------------------------------------------------------------
int StringHelp::UnicodeToUTF8 (char *dest, int maxChar, const wchar_t *src, 
	int numSrcChar)
{
	unsigned char *destTemp = (unsigned char *)dest;
	const wchar_t *cur = src;
	int srcCount = numSrcChar<0 ? 2147483647 : numSrcChar;

	while (*cur && srcCount>0)
	{
		srcCount--;
		wchar_t c = *cur++;

		if( c < 0x80 )
		{
			*destTemp++ = (unsigned char)c;
		}
		else if( c < 0x800 )
		{
			*destTemp++ = (unsigned char)((c>>6) | 0xC0);
			*destTemp++ = (unsigned char)((c&0x3F) | 0x80);
		}
		else
		{
			*destTemp++ = (unsigned char)((c>>12) | 0xE0);
			*destTemp++ = (unsigned char)(((c>>6)&0x3F) | 0x80);
			*destTemp++ = (unsigned char)((c&0x3F) | 0x80);
		}
	}
	*destTemp++ = 0;

	int nunChar = int((char *)destTemp - (char *)dest - 1);

	assertion(nunChar<maxChar, "nunChar<maxChar\n");

	return nunChar;
}
//----------------------------------------------------------------------------
int StringHelp::UTF8ToUnicode (wchar_t *dest, int maxChar, const char *src, 
	int numSrcChar)
{
	wchar_t *destTemp = dest;
	const unsigned char *cur = (unsigned char *)src;
	int srcCount = numSrcChar<0 ? 2147483647 : numSrcChar;

	while( *cur && srcCount>0 )
	{
		srcCount--;
		unsigned char head = *cur++;
		unsigned char mask = 0x80;
		wchar_t  c = 0;

		int bitshift = 0;
		if( head&mask )
		{
			mask >>= 1;
			while( head&mask )
			{
				assert( *cur!=0 && srcCount>0 );
				srcCount--;

				mask >>= 1;
				c = (c<<6) | (*cur++ & 0x3F);
				bitshift += 6;
			}
		}

		c |= (head&(mask-1)) << bitshift;
		*destTemp++ = c;
	}
	*destTemp++ = 0;

	int numChar = int((char *)destTemp - (char *)dest - 1);

	assertion(numChar<maxChar, "nchar<maxChar");

	return numChar;
}
//----------------------------------------------------------------------------
const char *StringHelp::UnicodeToAnsi (const wchar_t *src, int numSrcChar)
{
	StringHelp::UnicodeToAnsi(s_DBCSBuffer, MAX_CONVERT, src, numSrcChar);
	return s_DBCSBuffer;
}
//----------------------------------------------------------------------------
wchar_t *StringHelp::AnsiToUnicode (const char *src, int numSrcChar)
{
	StringHelp::AnsiToUnicode(s_UnicodeBuffer, MAX_CONVERT, src, numSrcChar);
	return s_UnicodeBuffer;
}
//----------------------------------------------------------------------------
const size_t gStringHelpMaxConvert = 4096*2;
static char gsStringHelpDBCSBuffer[gStringHelpMaxConvert];
static wchar_t gsStringHelpUnicodeBuffer[gStringHelpMaxConvert];
//----------------------------------------------------------------------------
const char *StringHelp::UnicodeToUTF8( const wchar_t *src, int numSrcChar)
{
	UnicodeToUTF8(gsStringHelpDBCSBuffer, gStringHelpMaxConvert, src,
		numSrcChar);

	return gsStringHelpDBCSBuffer;
}
//----------------------------------------------------------------------------
const wchar_t *StringHelp::UTF8ToUnicode( const char *src, int numSrcChar)
{
	UTF8ToUnicode(gsStringHelpUnicodeBuffer, gStringHelpMaxConvert, src, 
		numSrcChar);

	return gsStringHelpUnicodeBuffer;
}
//----------------------------------------------------------------------------
std::string StringHelp::IntToString (int val)
{
	static char c[10];
	string str;
	sprintf(c, "%d", val);
	str = c;
	return str;
}
//----------------------------------------------------------------------------
int StringHelp::StringToInt (const std::string &val)
{
	return atoi(val.c_str());
}
//----------------------------------------------------------------------------
std::string StringHelp::FloatToString (float val, int numPoint)
{
	static char c[10];
	string str;
	if (1 == numPoint)
		sprintf(c, "%.1f", val);
	else if (2 == numPoint)
		sprintf(c, "%.2f", val);
	str = c;
	return str;
}
//----------------------------------------------------------------------------
std::string StringHelp::FormatStr (const std::string &str,
	const std::vector<std::string> &params)
{
	std::string resStr = str;
	std::string strFind("%s");

	int paramIndex = 0;
	bool doWhile = true;
	while (doWhile)   
	{
		std::string::size_type pos(0);     
		if ((pos=resStr.find(strFind))!=string::npos)
		{
			std::string val;
			if (paramIndex < (int)params.size())
				val = params[paramIndex];

			resStr.replace(pos, strFind.length(), val);   
		}  
		else
		{
			doWhile = false;
		}
	}     

	return resStr;
}
//----------------------------------------------------------------------------
std::string StringHelp::FormatStr (const std::string &str, int val)
{
	std::string valStr = StringHelp::IntToString(val);
	std::vector<std::string> valStrs;
	valStrs.push_back(valStr);

	return FormatStr(str, valStrs);
}
//----------------------------------------------------------------------------
unsigned int StringHelp::Hash(const std::string &str, unsigned int type)
{
	return Hash(str.c_str(), type);
}
//----------------------------------------------------------------------------
unsigned int StringHelp::Hash(const char *str, unsigned int type,
	int length)
{
	unsigned int seed1 = 0x7FED7FED;
	unsigned int seed2 = 0xEEEEEEEE;
	unsigned int ch;

	if (length < 0)
	{
		while (*str != 0) 
		{
			ch = toupper(*str++);
			seed1 = mpqBuffer[(type<<8) + ch] ^ (seed1 + seed2);
			seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;
		}
	}
	else
	{
		while(length > 0) 
		{
			ch = toupper(*str++);
			seed1 = mpqBuffer[(type<<8) + ch] ^ (seed1 + seed2);
			seed2 = ch + seed1 + seed2 + (seed2 << 5) + 3;

			length--;
		}
	}

	return seed1;
}
//----------------------------------------------------------------------------
std::string StringHelp::FormatSeconds (int seconds)
{
	int min = seconds/60;
	int sec = seconds%60;

	std::string text = "";
	if (seconds <= 60)
	{
		if (seconds < 10)
		{
			text = "0" + StringHelp::IntToString(seconds);
		}
		else
		{
			text = StringHelp::IntToString(seconds);
		}
	}
	else
	{
		if (sec < 10)
		{
			text = StringHelp::IntToString(min) + ":" + "0" + StringHelp::IntToString(sec);
		}
		else
		{
			text = StringHelp::IntToString(min) + ":" +StringHelp::IntToString(sec);
		}
	}

	return text;
}
//----------------------------------------------------------------------------