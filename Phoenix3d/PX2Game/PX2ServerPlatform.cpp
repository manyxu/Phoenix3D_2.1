/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ServerPlatform.cpp
*
*/

#include "PX2ServerPlatform.hpp"
#include "PX2ServerPlatformEventType.hpp"
#include "PX2EventWorld.hpp"
#include "PX2JNI.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
// LoginData
//----------------------------------------------------------------------------
LoginData::LoginData ()
	:
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
// BuyData
//----------------------------------------------------------------------------
BuyData::BuyData ()
	:
Result(BR_MAXTYPE),
IsSyn(true),
Error(0)
{
}
//----------------------------------------------------------------------------
BuyData::~BuyData ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// ServerPlatform
//----------------------------------------------------------------------------
ServerPlatform::ServerPlatform ()
{
}
//----------------------------------------------------------------------------
ServerPlatform::~ServerPlatform()
{
}
//----------------------------------------------------------------------------
void ServerPlatform::SetThirdPlatform (const std::string &thirdname)
{
	mThirdPlatformName = thirdname;
}
//----------------------------------------------------------------------------
const std::string &ServerPlatform::GetThirdPlatform () const
{
	return mThirdPlatformName;
}
//----------------------------------------------------------------------------
bool ServerPlatform::IsThirdPlatform () const
{
	return !mThirdPlatformName.empty();
}
//----------------------------------------------------------------------------
void ServerPlatform::ThirdPlatformLogin ()
{
#ifdef __ANDROID__
	ThirdPlatformLoginJNI();
#endif
}
//----------------------------------------------------------------------------
void ServerPlatform::ThirdPlatformLogout ()
{
#ifdef __ANDROID__
	ThirdPlatformLogoutJNI();
#endif
}
//----------------------------------------------------------------------------
void ServerPlatform::OnLoginSuc (int apiID, std::string loginUin, std::string sessionID, 
	std::string nickname)
{
	LoginData data;
	data.APIID = apiID;
	data.Result = LoginData::LR_SUC;
	data.LoginUin = loginUin;
	data.SessionID = sessionID;
	data.Nickname = nickname;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnLoginCancel ()
{
	LoginData data;
	data.Result = LoginData::LR_CANCEL;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnLoginFailed ()
{
	LoginData data;
	data.Result = LoginData::LR_FAILED;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnGuestOfficialSuc ()
{
	LoginData data;
	data.Result = LoginData::LR_GUESTOFFICIAL;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Login);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::SynPay (
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
void ServerPlatform::ASynPay (
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
void ServerPlatform::OnPaySuc (const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPaySuc Serial:%s IsSyn:%d", serial.c_str(), isSyn?1:0);

	BuyData data;
	data.Result = BuyData::BR_SUC;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnPayCancel (const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPayCancel Serial:%s IsSyn:%d", serial.c_str(), isSyn?1:0);

	BuyData data;
	data.Result = BuyData::BR_CANCEL;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnPayFailed (const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPayFailed Serial:%s IsSyn:%d", serial.c_str(), isSyn?1:0);

	BuyData data;
	data.Result = BuyData::BR_FAILED;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnPaySMSSent (const std::string &serial, bool isSyn)
{
	PX2_LOG_INFO("OnPaySMSSent Serial:%s IsSyn:%d", serial.c_str(), isSyn?1:0);

	BuyData data;
	data.Result = BuyData::BR_SMSSENT;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnPayRequestSubmitted (const std::string &serial,
	bool isSyn)
{
	PX2_LOG_INFO("OnPayRequestSubmitted Serial:%s IsSyn:%d", serial.c_str(), isSyn?1:0);

	BuyData data;
	data.Result = BuyData::BR_REQUESTSUBMITTED;
	data.Serial = serial;
	data.IsSyn = isSyn;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------
void ServerPlatform::OnPayError (const std::string &serial, int error,
	bool isSyn)
{
	PX2_LOG_INFO("OnPayError Serial:%s Error:%d IsSyn:%d", serial.c_str(), error, isSyn?1:0);

	BuyData data;
	data.Result = BuyData::BR_ERROR;
	data.Serial = serial;
	data.Error = error;
	data.IsSyn = isSyn;

	Event *ent = ServerPlatformSpace::CreateEventX(ServerPlatformSpace::Buy);
	ent->SetData(data);
	PX2_EW.BroadcastingLocalEvent(ent);
}
//----------------------------------------------------------------------------