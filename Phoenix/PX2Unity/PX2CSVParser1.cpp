/*
*
* 文件名称	：	PX2CSVParser1.cpp
*
*/

#include "PX2CSVParser1.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
CSVParser1::TableItem::TableItem(const char* szItemString)
{
	mItemString = szItemString;
}
//----------------------------------------------------------------------------	
CSVParser1::TableLine::TableLine() 
{
}
//----------------------------------------------------------------------------
CSVParser1::CSVParser1()
{
	mSeparator = ',';
	mContent = 0;
	mItems = 0;
	mLines = 0;
	mInvalidLine.SetLine(this, -1);
}
//----------------------------------------------------------------------------
CSVParser1::~CSVParser1()
{
	Clear();
}
//----------------------------------------------------------------------------
bool CSVParser1::Load(const std::string &filename)
{
	int bufSize = 0;
	char *buffer = 0;
	PX2_RM.LoadBuffer(filename, bufSize, buffer);

	if (!buffer)
		return false;

	Clear();

	mContent = new char[bufSize+1];
	memcpy(mContent, buffer, (size_t)bufSize);
	mContent[bufSize] = 0;

	if (!ParseTextTable())
	{
		Clear();
		return false;
	}

	mItems = new char*[mNumLines*mNumCols];
	memset(mItems, 0, sizeof(char*)*mNumLines*mNumCols);

	mLines = new TableLine[mNumLines];
	for (int i=0; i<mNumLines; ++i)
	{
		mLines[i].SetLine(this, i);
	}

	ParseTextTable();

	return true;
}
//----------------------------------------------------------------------------
void CSVParser1::Clear()
{
	mTitleLine = 0;
	mTitleCol = 0;
	mNumCols = 0;
	mNumLines = 0;
	if(mContent)
	{
		delete[] mContent;
		mContent = 0;
		delete[] mItems;
		mItems = 0;
		delete[] mLines;
		mLines = 0;
	}
}
//----------------------------------------------------------------------------
bool CSVParser1::ParseTextTable()
{
	assertion(0!=mContent, "mContent must not be 0.\n");

	int state = 0;
	int line = 0;
	int col = 0;

	char *pWord = mContent;
	char *pCur = mContent;
	char *pd = mContent;
	
	while (*pCur)
	{
		if (state==0)
		{
			if (*pCur=='"')
			{
				state = 1;
			}
			else if (*pCur==mSeparator)
			{
				if (mItems)
				{
					*pd = 0;
					assertion(line<mNumLines && col<mNumCols, 
						"must in right range.\n");
					mItems[line*mNumCols + col] = pWord;
				}
				col ++;
				pd = pWord = pCur + 1;
				if (mItems==0)
				{
					if (mNumCols<col) mNumCols=col;
				}
			}
			else if (*pCur==0x0A || *pCur==0x0D)
			{
				if (pCur[1]==0x0A || pCur[1]==0x0D)
				{
					pCur ++;
				}
				if (mItems)
				{
					*pd = 0;
					assertion(line<mNumLines && col<mNumCols, 
						"line and col should be in right range.\n");
					mItems[line*mNumCols + col] = pWord;
				}
				col ++;
				if (mItems==0)
				{
					if (mNumCols<col) mNumCols=col;
				}
				line ++;
				col = 0;
				pd = pWord = pCur + 1;
			}
			else
			{
				if (mItems)
				{
					if (pCur!=pd) *pd = *pCur;
					pd ++;
				}
			}
		}
		else if (state==1)
		{
			if (*pCur=='"')
			{
				if (pCur[1]=='"')
				{
					// 还是双引号
					pCur ++;
					if (mItems)
					{
						if (pCur!=pd) *pd = *pCur;
						pd ++;
					}
				}else
				{
					// 结束
					state = 0;
				}
			}
			else
			{
				if (mItems)
				{
					if (pCur!=pd) *pd = *pCur;
					pd ++;
				}
			}
		}
		pCur ++;
	}
	if (pWord!=pCur)
	{
		if (mItems)
		{
			*pd = 0;
			assertion(line<mNumLines && col<mNumCols, 
				"line must in right range.\n");
			mItems[line*mNumCols + col] = pWord;
		}
		col ++;
		if (mItems==0)
		{
			if (mNumCols<col) mNumCols=col;
		}
		line ++;
	}

	mNumLines = line;
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::FindPosByString(const char* str, int& line, int& col)
{
	char* p = 0;
	for (int i=0; i<mNumLines; i++)
	{
		for (int j=0; j<mNumCols; j++)
		{
			p = mItems[i*mNumCols+j];
			if (p)
			{
				if (strcmp(p, str)==0)
				{
					line = (int)i;
					col = (int)j;
					return true;
				}
			}
		}
	}
	return false;
}
//----------------------------------------------------------------------------
int CSVParser1::FindLineByString(const char* str)
{
	int line, col;
	if (FindPosByString(str, line, col))
	{
		return line;
	}
	return -1;
}
//----------------------------------------------------------------------------
int CSVParser1::FindColByString(const char* str)
{
	int line, col;
	if (FindPosByString(str, line, col))
	{
		return col;
	}
	return -1;
}
//----------------------------------------------------------------------------
const CSVParser1::TableLine& CSVParser1::operator[](const char* szIdx) const
{
	for (int i=0; i<mNumLines; i++)
	{
		if (strcmp(mItems[i*mNumCols+mTitleCol], szIdx)==0)
		{
			return mLines[i];
		}
	}
	return mInvalidLine;
}
//----------------------------------------------------------------------------
const char* CSVParser1::GetString(int line, const char* szColIdx) const
{
	char* pStr = 0;
	static char szNull[] = "";
	
	if (line < 0) 
		return szNull;

	for (int i=0; i<mNumCols; i++)
	{
		if (strcmp(mItems[mTitleLine*mNumCols+i], szColIdx)==0)
		{
			pStr = mItems[line*mNumCols+i];
			
			if (pStr==0)
				pStr = szNull;
			
			return pStr;
		}
	}

	assertion(false, "GetString error.\n");

	return szNull;
}
//----------------------------------------------------------------------------
const char* CSVParser1::GetString(const char* szLineIdx, const char* szColIdx)
	const
{
	return (*this)[szLineIdx][szColIdx];
}
//----------------------------------------------------------------------------
const char* CSVParser1::GetString (int line, int col) const
{
	if (line<0 || line>=mNumLines || col<0 || col>=mNumCols) return 0;
	if (mItems[line*mNumCols+col]==0) return "";
	return (const char*)mItems[line*mNumCols+col];
}
//----------------------------------------------------------------------------
bool CSVParser1::Char (size_t line, size_t col, char &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (char)atoi(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Byte (size_t line, size_t col, unsigned char &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (unsigned char)atoi(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Short(size_t line, size_t col, short &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (short)atoi(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Word (size_t line, size_t col, unsigned short&val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (unsigned short)atoi(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Int  (size_t line, size_t col, int &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (int)atoi(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::UInt (size_t line, size_t col, unsigned int &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (unsigned int)atoi(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Long (size_t line, size_t col, long &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (long)atol(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::DWord(size_t line, size_t col, unsigned long &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (unsigned long)atol(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Float (size_t line, size_t col, float &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = (float)atof(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------
bool CSVParser1::Double(size_t line, size_t col, double &val) const
{
	if (mItems[line*mNumCols+col]==0) return false;
	val = atof(mItems[line*mNumCols+col]);
	return true;
}
//----------------------------------------------------------------------------