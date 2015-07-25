// X_UIMan.hpp

#ifndef X_MAN_HPP
#define X_MAN_HPP

#include "PX2Singleton.hpp"
#include "PX2EventHandler.hpp"
#include "PX2ServerInfo.hpp"

namespace PX2
{

	class X_User;
	class X_UserActor;
	class LoginData_Actor;

	class X_Man : public EventHandler
	{
		PX2_SINGLETION(X_Man);

		// Init Term
	public:
		bool Init();
		bool Init_Start();
		bool Init_Updated();
		bool Term();
		void Update(float appSeconds, float elapsedSeconds);

		// Event
	public:
		virtual void DoExecute(Event *event);

		// GameData
	public:
		bool SaveGameData();
		bool LoadGameData();
		bool IsGameDataValied() const;

		bool IsGameData_HasAccounts() const;

	protected:
		int mCurGameDataVersion;
		bool mIsHasAccounts;

		// 网络状态
	public:
		bool IsUseNet() const;
		bool NetStating() const;

		// 账号服务器
	public:
		void ConnectToAccountServer();
		void FastRegist();
		void Regist(const std::string &userName, const std::string &password);
		void Login(const std::string &userName, const std::string &normalPassward);
		void LoginMD5(const std::string &uin, const std::string &userName, const std::string &md5password);
		void LoginTP(int apiID, const std::string &sessionID, const std::string &uin, const std::string &userName);

		uint32_t GetLoginedUin() const;
		const std::string &GetLoginedSessionID() const;

		void SendGetGameServerList();

	public_internal:
		void OnConnectToAccountServer();
		void OnGetGameServerList(const std::vector<ServerInfo> &serverInfos);
		void OnFastRegist(int result, const std::string &uni, const std::string &md5password);
		void OnRegist(int result);
		void OnLogined(int result, int getted_uIn, const std::string &getted_SessionID);

	protected:
		std::vector<ServerInfo> mServerInfos;

		// 游戏服务器
	public:
		void ConnectToGameServer(int serverID);
		void SendGameServerLogin(int uIn, const std::string &sessionID);

		void SendCreateNewRole(const std::string &nickName, int headID);

	public_internal:
		void OnConnectedToGameServer();
		void OnLoginToGameServer(int result);
		void OnNewRole(int result);

	protected:
		void _CreateNoNetLoginUserActors();
		void _LoginUpdateUserActors(X_User *user,
			const std::vector<LoginData_Actor *> &loginData_Actors);
		void ReadAccounts();
		void WriteAccouts();

		std::string mRegistUserName;
		std::string mRegistPasswordMD5;
		std::string mTryLoginUin;
		std::string mTryLoginUserName;
		std::string mTryLoginPasswordMD5;
		std::string mUin; // 在服务器表示用户(服务器不使用用户名索引用户)
		std::string mUserName;
		std::string mPasswordMD5;
		std::string mLoginedSessionID;

		// 游戏服务器Play
	public:
		void SendEnterMap(int mapID, int actorIndexToPlay);

		int GetIndexActorTryToPlay() const;
		int GetIndexActorPlay() const;
		X_UserActor *GetUserActorPlay();

		int GetMapIDTryToEnter() const;
		int GetMapIDEntered() const;

	public_internal:
		void OnEnterMap(int result);

	protected:
		int mMapIDTryToEnter;
		int mMapIDEntered;
		int mIndexActorTryToPlay;
		int mIndexActorPlay;
	};

#define X_MAN X_Man::GetSingleton()

}

#endif