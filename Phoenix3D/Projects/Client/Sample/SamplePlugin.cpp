// SamplePlugin.cpp

#include "SamplePlugin.hpp"
#include "SampleManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
SamplePlugin::SamplePlugin()
{
}
//----------------------------------------------------------------------------
SamplePlugin::~SamplePlugin()
{
}
//----------------------------------------------------------------------------
std::string SamplePlugin::GetName()
{
	return "Sample";
}
//----------------------------------------------------------------------------
void SamplePlugin::OnInstall()
{
	SampleManager::GetSingleton().Initlize();
}
//----------------------------------------------------------------------------
void SamplePlugin::OnTernamate()
{
	SampleManager::GetSingleton().Ternamate();
}
//----------------------------------------------------------------------------
void SamplePlugin::OnUnstall()
{
}
//----------------------------------------------------------------------------