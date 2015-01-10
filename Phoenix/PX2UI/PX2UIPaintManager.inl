// PX2UIPaintManager.inl

//----------------------------------------------------------------------------
inline void *UIPaintManager::GetPlatformData()
{
	return mPlatformData;
}
//----------------------------------------------------------------------------
inline const SystemMetricsUI &UIPaintManager::GetSystemMetrics() const
{
	return mSystemMetrics;
}
//----------------------------------------------------------------------------
inline const SystemSettingsUI &UIPaintManager::GetSystemSettings() const
{
	return mSystemSettings;
}
//----------------------------------------------------------------------------