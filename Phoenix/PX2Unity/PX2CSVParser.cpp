/*
*
* 文件名称	：	PX2CSVParser.cpp
*
*/

#include "PX2CSVParser.hpp"
using namespace PX2;

CSVParser::CSVParser (std::string sep)
	:
mFieldSep(sep),
mColsNum(0)
{
}
//----------------------------------------------------------------------------
CSVParser::~CSVParser()
{
}
//----------------------------------------------------------------------------
void CSVParser::Split (std::vector<std::string> &fields, std::string line)
{
	std::string fld;
	int i = 0;
	int j = 0;

	if (line.length() == 0)
		return;

	do 
	{
		if (i < (int)line.length() && line[i] == '"')
		{
			j = AdvQuoted(line, fld, ++i);    // skip quote
		}
		else
		{
			j = AdvPlain(line, fld, i);
		}

		fields.push_back(fld);

		i = j + 1;

	} while (j < (int)line.length());
}
//----------------------------------------------------------------------------
int CSVParser::AdvQuoted (const std::string &line, std::string &fld, int i)
{
	int j;

	fld = "";
	for (j = i; j < (int)line.length(); j++)
	{
		if (line[j] == '"' && line[++j] != '"')
		{
			int k = (int)line.find_first_of(mFieldSep, j);
			if (k>(int)line.length() || k==(int)std::string::npos)    // no separator found
			{
				k = (int)line.length();
			}

			for (k -= j; k-- > 0; )
			{
				fld += line[j++];
			}

			break;
		}
		fld += line[j];
	}

	return j;
}
//----------------------------------------------------------------------------
int CSVParser::AdvPlain (const std::string &line, std::string &fld, int i)
{
	int j;

	j = (int)line.find_first_of(mFieldSep, i); 

	if (j > (int)line.length() || j==(int)std::string::npos)
		j = (int)line.length();

	fld = std::string(line, i, j-i);

	return j;
}
//----------------------------------------------------------------------------
const char *CSVParser::GetData (int rows, int cols)
{
	if (rows<0 || rows>=(int)mData.size() || cols<0 
		|| cols>=(int)mData[rows].size())
	{
		return "";
	}

	return mData[rows][cols].c_str();
}
//----------------------------------------------------------------------------
// 用于兼容windows下的换行符\r\n
// 原因是在windows下换行符为\r\n，而在unix下则为\n
// 将window的\r去掉
bool GetLine (std::ifstream &is, std::string &str)
{
	std::getline(is, str);

	std::string::size_type p = str.find_last_of('\r');

	if(p != std::string::npos)
		str.erase(p);

	return str != "";
}
//----------------------------------------------------------------------------
bool CSVParser::Open (const char *filename)
{
	std::ifstream fin(filename);  

	if (!fin.is_open())
		return false;

	std::string str;  

	while (GetLine(fin, str))
	{   
		std::vector<std::string> fields;
		Split(fields, str);

		mData.push_back(fields);

		if ((int)fields.size() > mColsNum)
			mColsNum = (int)fields.size();
	}

	return true;
}
//----------------------------------------------------------------------------