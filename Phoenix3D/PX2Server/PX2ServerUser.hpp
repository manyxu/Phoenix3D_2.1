// PX2ServerUser.hpp

#ifndef PX2SERVERUSER_HPP
#define PX2SERVERUSER_HPP

#include "PX2ServerPre.hpp"

namespace PX2Server
{

	enum PX2_SERVER_ITEM UserState
	{
		SUT_INIT = 0,  // 初始化，没有连接上
		SUT_NEWROLE,   // 创建角色
		SUT_IN_GAME,   // 登录成功进入游戏
		SUT_IN_LEVEL,  // 关卡中, statedata = cur_levelid
		SUT_MATCHING,  // 做对战匹配中
		SUT_PVP,       // PVP对战中
		SUT_ROB        // 掠夺模式中
	};

	class User
	{
	public:
		User();
		~User();

		void Reset();

		void SetState(UserState state);
		UserState GetState() const;

	public:
		bool IsUsed;
		unsigned int UIN;
		unsigned int ClientID;

	protected:
		UserState mState;
	};

#include "PX2ServerUser.inl"

}

#endif