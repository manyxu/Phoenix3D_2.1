// PX2PlatformSDK.cpp

#include "PX2PlatformSDK.hpp"
#include "PX2PlatformSDKEventType.hpp"
#include "PX2Log.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
LoginData::LoginData() :
Result(LR_MAXTYPE),
APIID(-1)
{
}
//----------------------------------------------------------------------------
LoginData::~LoginData()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
BuyData::BuyData() :
Result(BR_MAXTYPE),
IsSyn(true),
Error(0)
{
}
//----------------------------------------------------------------------------
BuyData::~BuyData()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
PlatformSDK::PlatformSDK()
{
}
//----------------------------------------------------------------------------
PlatformSDK::~PlatformSDK()
{
}
//----------------------------------------------------------------------------
void PlatformSDK::SetPlatformSDK(const std::string &thirdname)
{
	mPlatformSDK = thirdname;
}
//----------------------------------------------------------------------------
const std::string &PlatformSDK::GetPlatformSDK() const
{
	return mPlatformSDK;
}
//----------------------------------------------------------------------------
bool PlatformSDK::IsThirdPlatform() const
{
	return !mPlatformSDK.empty();
}
//----------------------------------------------------------------------------
void PlatformSDK::ThirdPlatformLogin()
{
#ifdef __ANDROID__
	ThirdPlatformLoginJNI();
#endif
}
//----------------------------------------------------------------------------
void PlatformSDK::ThirdPlatformLogout()
{
#ifdef __ANDROID__
	ThirdPlatformLogoutJNI();
#endif
}
//----------------------------------------------------------------------------
void PlatformSDK::OnLoginSuc(int apiID, std::string loginUin, std::string sessionID,
	std::string nickname)
{
	LoginData data;
	data.APIID = apiID;
	data.Result = LoginData::LR_SUC;
	data.LoginUin = loginUin;
	data.SessionID = sessionID;
	data.Nickname = nickname;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnLoginCancel()
{
	LoginData data;
	data.Result = LoginData::LR_CANCEL;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnLoginFailed()
{
	LoginData data;
	data.Result = LoginData::LR_FAILED;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnGuestOfficialSuc()
{
	LoginData data;
	data.Result = LoginData::LR_GUESTOFFICIAL;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::SynPay(
	const std::string &productID, const std::string &productName,
	float productPrice, float productOriginPrice, int count,
	const std::string &payDescription)
{
	PX2_LOG_INFO("SynPay ProductID:%s ProductName:%s ProductPrice:%.2f ProductOriginPrice:%.2f Count:%d PayDesc:%s",
		productID.c_str(), productName.c_str(), productPrice, productOriginPrice, count, payDescription.c_str());

#ifdef __ANDROID__
	ThirdPlatformSynPayJNI(
		productID.c_str(), productName.c_str(),
		productPrice, productOriginPrice, count, payDescription.c_str());
#endif
}
//----------------------------------------------------------------------------
void PlatformSDK::ASynPay(
	const std::string &productID, const std::string &productName,
	float productPrice, float productOriginPrice, int count,
	const std::string &payDescription)
{
	PX2_LOG_INFO("SynPay ProductID:%s ProductName:%s ProductPrice:%.2f ProductOriginPrice:%.2f Count:%d PayDesc:%s",
		productID.c_str(), productName.c_str(), productPrice, productOriginPrice, count, payDescription.c_str());

#ifdef __ANDROID__
	ThirdPlatformASynPayJNI(
		productID.c_str(), productName.c_str(),
		productPrice, productOriginPrice, count, payDescription.c_str());
#endif
}
//----------------------------------------------------------------------------
void PlatformSDK::OnPaySuc(const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPaySuc Serial:%s IsSyn:%d", serial.c_str(), isSyn ? 1 : 0);

	BuyData data;
	data.Result = BuyData::BR_SUC;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnPayCancel(const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPayCancel Serial:%s IsSyn:%d", serial.c_str(), isSyn ? 1 : 0);

	BuyData data;
	data.Result = BuyData::BR_CANCEL;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnPayFailed(const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPayFailed Serial:%s IsSyn:%d", serial.c_str(), isSyn ? 1 : 0);

	BuyData data;
	data.Result = BuyData::BR_FAILED;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnPaySMSSent(const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPaySMSSent Serial:%s IsSyn:%d", serial.c_str(), isSyn ? 1 : 0);

	BuyData data;
	data.Result = BuyData::BR_SMSSENT;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnPayRequestSubmitted(const std::string &serial,
	bool isSyn)
{
	PX2_LOG_INFO("OnPayRequestSubmitted Serial:%s IsSyn:%d", serial.c_str(), isSyn ? 1 : 0);

	BuyData data;
	data.Result = BuyData::BR_REQUESTSUBMITTED;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void PlatformSDK::OnPayError(const std::string &serial, int error,
	bool isSyn)
{
	PX2_LOG_INFO("OnPayError Serial:%s Error:%d IsSyn:%d", serial.c_str(), error, isSyn ? 1 : 0);

	BuyData data;
	data.Result = BuyData::BR_ERROR;
	data.Serial = serial;
	data.Error = error;
	data.IsSyn = isSyn;

	Event *ent = PlatformSDKSpace::CreateEventX(PlatformSDKSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------