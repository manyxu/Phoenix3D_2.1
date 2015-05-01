// X_UserActor.hpp

#ifndef X_USERACTOR_HPP
#define X_USERACTOR_HPP

#include "PX2UserActor.hpp"
#include "PX2EventHandler.hpp"
#include "X_Chara.hpp"

namespace PX2
{

	class X_UserActor : public UserActor, public EventHandler
	{
	public:
		X_UserActor();
		virtual ~X_UserActor();

		virtual void Update(float appTime, float elapsedTime);
		virtual void DoExecute(Event *event);

		// 等级 经验
	public:
		virtual void SetLevel(int level);
		virtual void SetCurLevelExp(int exp);

		// 资源
	public:
		virtual void SetGold(int gold);

	public:
		void SetTypeID(int typeID);
		int GetTypeID() const;

		X_Chara *CreateChara();

		void SetMainChara(X_Chara *chara);
		X_Chara *GetMainChara() const;

	protected:
		int mTypeID;
		X_CharaPtr mMainChara;
	};

	typedef Pointer0<X_UserActor> X_UserActorPtr;
#include "X_UserActor.inl"

}

#endif