/*
*
* 文件名称	：	PX2ServerPlatform.hpp
*
*/

#ifndef PX2SERVERPLATFORM_HPP
#define PX2SERVERPLATFORM_HPP

#include "PX2GamePre.hpp"
#include "PX2Singleton1.hpp"

namespace PX2
{

	class LoginData
	{
	public:
		LoginData ();
		~LoginData();

		enum LoginResult
		{
			LR_SUC,
			LR_CANCEL,
			LR_FAILED,
			LR_GUESTOFFICIAL,
			LR_MAXTYPE
		};

		LoginResult Result;

		int APIID;
		std::string LoginUin;
		std::string SessionID;
		std::string Nickname;
	};

	class BuyData
	{
	public:
		BuyData ();
		~BuyData ();

		enum BuyResult
		{
			BR_SUC,
			BR_CANCEL,
			BR_FAILED,
			BR_SMSSENT,
			BR_REQUESTSUBMITTED,
			BR_ERROR,
			BR_MAXTYPE
		};

		BuyResult Result;
		std::string Serial;
		bool IsSyn;
		int Error;
	};

	// 广播消息做登录相应
	class ServerPlatform 
	{
	public:
		PX2_SINGLETION(ServerPlatform);

	public:
		void SetThirdPlatform (const std::string &thirdname); // 如果名字不为空，表示是游戏接第三方平台
		const std::string &GetThirdPlatform () const;
		bool IsThirdPlatform () const;

		void ThirdPlatformLogin ();
		void ThirdPlatformLogout ();

		void OnLoginSuc (int apiID, std::string loginUin, std::string sessionID, 
			std::string nickname);	
		void OnLoginCancel ();	
		void OnLoginFailed ();
		void OnGuestOfficialSuc ();

		void SynPay (const std::string &productID, const std::string &productName,
			float productPrice, float productOriginPrice, int count,
			const std::string &payDescription);
		void ASynPay (const std::string &productID, const std::string &productName,
			float productPrice, float productOriginPrice, int count,
			const std::string &payDescription);

		void OnPaySuc (const std::string &serial, bool isSyn);
		void OnPayCancel (const std::string &serial, bool isSyn);
		void OnPayFailed (const std::string &serial, bool isSyn);
		void OnPaySMSSent (const std::string &serial, bool isSyn);
		void OnPayRequestSubmitted (const std::string &serial, bool isSyn);
		void OnPayError (const std::string &serial, int error, bool isSyn);

	protected:
		std::string mThirdPlatformName;
	};

}

#endif