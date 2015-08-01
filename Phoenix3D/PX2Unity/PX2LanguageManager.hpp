// PX2LanguageManager.hpp

#ifndef PX2LANGUAGEMANAGER_HPP
#define PX2LANGUAGEMANAGER_HPP

#include "PX2UnityPre.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class PX2_UNITY_ITEM LanguageManager : public Singleton<LanguageManager>
	{
	public:
		LanguageManager ();
		virtual ~LanguageManager ();

		bool Load (const std::string &filename);
		bool Add (const std::string &filename);
		void AddItem(const std::string &key, const std::string &langauge0, 
			const std::string &langauge1);
		void AddItem1(const std::string &key, const std::string &langauge0);

		void SetLanguage (int index);
		bool HasValue (const std::string &key) const;
		const std::string &GetValue (const std::string &key);
		const std::string &GetValue (const std::string &key, int index);
		void Clear ();

	protected:
		int mLanguageIndex;
		typedef HashTable<FString, std::vector<std::string>, FixedStringHashCoder> LanguageTable;
		typedef LanguageTable::Element * LanguageTableIterator;

		LanguageTable mLanguages;

		std::string mEmptyStr;
	};

#define PX2_LM LanguageManager::GetSingleton()
#define PX2_LMVAL LanguageManager::GetSingleton().GetValue

}

#endif