// PX2PlatformSDK.hpp

#ifndef PX2PLATFORMSDK_HPP
#define PX2PLATFORMSDK_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton.hpp"

namespace PX2
{

	class LoginData
	{
	public:
		LoginData();
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
		BuyData();
		~BuyData();

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

	class PlatformSDK
	{
		PX2_SINGLETION(PlatformSDK);

	public:
		void SetPlatformSDK(const std::string &thirdname);
		const std::string &GetPlatformSDK() const;
		bool IsThirdPlatform() const;

		void PlatformSDKLogin();
		void PlatformSDKLogout();

		void OnLoginSuc(int apiID, std::string loginUin, std::string sessionID, std::string nickname);
		void OnLoginCancel();
		void OnLoginFailed();
		void OnGuestOfficialSuc();

		void SynPay(const std::string &productID, const std::string &productName,
			float productPrice, float productOriginPrice, int count,
			const std::string &payDescription);
		void ASynPay(const std::string &productID, const std::string &productName,
			float productPrice, float productOriginPrice, int count,
			const std::string &payDescription);

		void OnPaySuc(const std::string &serial, bool isSyn);
		void OnPayCancel(const std::string &serial, bool isSyn);
		void OnPayFailed(const std::string &serial, bool isSyn);
		void OnPaySMSSent(const std::string &serial, bool isSyn);
		void OnPayRequestSubmitted(const std::string &serial, bool isSyn);
		void OnPayError(const std::string &serial, int error, bool isSyn);

	private:
		std::string mPlatformSDK;
	};

#define PX2_PFSDK PlatformSDK::GetSingleton()

}

#endif