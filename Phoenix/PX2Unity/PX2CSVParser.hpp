/*
*
* ÎÄ¼þÃû³Æ	£º	PX2CSVParser.hpp
*
*/

#ifndef PX2PARSER_HPP
#define PX2PARSER_HPP

#include "PX2UnityPre.hpp"

namespace PX2
{

	class CSVParser
	{
	public:
		CSVParser (std::string sep = ",");
		~CSVParser();

		bool Open (const char *filename);
		const char *GetData (int row, int col);
		int GetRowsNum ();
		int GetColsNum ();

	private:
		void Split (std::vector<std::string> &fields, std::string line);
		int AdvPlain (const std::string &line, std::string &fld, int);
		int AdvQuoted (const std::string &line, std::string &fld, int);

		std::string mFieldSep;
		int mColsNum;
		std::vector<std::vector<std::string> > mData;
	};

#include "PX2CSVParser.inl"

}

#endif
