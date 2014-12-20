/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LanguageManager.cpp
*
*/

#include "PX2LanguageManager.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2CSVParser1.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool LanguageManager::Load (const char *filename)
{
	CSVParser1 csv;
	
	if (csv.Load(filename))
	{
		mLanguages.Clear();
		
		// language start form 2
		for (int i=2; i<csv.GetNumLines(); i++)
		{
			std::string key = csv[i][0].String();

			LanguageTableIterator it = mLanguages.Insert(key.c_str());
			if (it)
			{
				it->value.clear();

				for (int j=1; j<csv.GetNumCols(); j++)
				{
					it->value.push_back(csv[i][j].String());
				}
			}
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
bool LanguageManager::Add (const char *filename)
{
	CSVParser1 csv;

	if (csv.Load(filename))
	{
		for (int i=2; i<csv.GetNumLines(); i++)
		{
			std::string key = csv[i][0].String();
			LanguageTableIterator it = mLanguages.Insert(key.c_str());
			if (it)
			{
				it->value.clear();

				for (int j=1; j<csv.GetNumCols(); j++)
				{
					it->value.push_back(csv[i][j].String());
				}
			}
		}

		return true;
	}

	return false;
}
//----------------------------------------------------------------------------
void LanguageManager::SetLanguage (int index)
{
	mLanguageIndex = index;
}
//----------------------------------------------------------------------------
bool LanguageManager::HasValue (const std::string &key) const
{
	LanguageTableIterator it = mLanguages.Find(key.c_str());
	return 0!=it;
}
//----------------------------------------------------------------------------
std::string LanguageManager::GetValue (const std::string &key)
{
	LanguageTableIterator it = mLanguages.Find(key.c_str());
	if (it)
	{
		if (mLanguageIndex < (int)it->value.size())
		{
			return it->value[mLanguageIndex];
		}
	}

	assertion(false, "language key %s does not exist.", key.c_str());
	PX2_LOG_ERROR("language key %s does not exist.", key.c_str());

	return "";
}
//----------------------------------------------------------------------------
std::string LanguageManager::GetValue (const std::string &key, int index)
{
	LanguageTableIterator it = mLanguages.Find(key.c_str());
	if (it)
	{
		if (mLanguageIndex < (int)it->value.size())
		{
			return it->value[index];
		}
	}

	assertion(false, "language key %s does not exist.", key.c_str());
	PX2_LOG_ERROR("language key %s does not exist.", key.c_str());

	return "";
}
//----------------------------------------------------------------------------
LanguageManager::LanguageManager ()
	:
mLanguageIndex(0),
mLanguages(1023)
{
}
//----------------------------------------------------------------------------
LanguageManager::~LanguageManager ()
{
	Clear();
}
//----------------------------------------------------------------------------
void LanguageManager::Clear ()
{
	mLanguages.Clear();
}
//----------------------------------------------------------------------------