// X_DEFMAN_HPP

#ifndef X_DEFMAN_HPP
#define X_DEFMAN_HPP

#include "X_Pre.hpp"
#include "X_Def.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class X_DefMan
	{
	public:
		PX2_SINGLETION(X_DefMan);

	public:
		bool LoadAll();
		bool ReloadAll();

	protected:
		bool LoadModelDef(const std::string &filename);
		bool LoadActorDef(const std::string &filename);
		bool LoadSkillDef(const std::string &filename);
		bool LoadItemDef(const std::string &filename);
		bool LoadMapDef(const std::string &filename);
		bool LoadMonsterDef(const std::string &filename);

		bool mIsAllLoaded;

	public:
		std::map<int, ActorDef> mActorDefs;
		std::map<int, SkillDef> mSkillDefs;
		std::map<int, ModelDef> mModelDefs;
		std::map<int, ItemDef> mItemModelDefs;
		std::map<int, MapDef> mMapDefs;
		std::map<int, MonsterDef> mMonsterDefs;
	};

#define X_DEFM X_DefMan::GetSingleton()

}


#endif