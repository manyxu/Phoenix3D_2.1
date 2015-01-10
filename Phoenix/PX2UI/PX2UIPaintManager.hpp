// PX2UIPaintManager.hpp

#ifndef PX2UIPAINTMANAGER_HPP
#define PX2UIPAINTMANAGER_HPP

#include "PX2Singleton.hpp"
#include "PX2Size.hpp"
#include "PX2APoint.hpp"
#include "PX2Float2.hpp"
#include "PX2Rect.hpp"
#include "PX2UIDefine.hpp"

namespace PX2
{

	class UIPaintManager : public Singleton<UIPaintManager>
	{
	public:
		UIPaintManager();
		virtual ~UIPaintManager();

		static UIPaintManager *Create();

		virtual void SetPlatformData(void *data);
		void *GetPlatformData();

		void Init();
		void Invalidate(const Rectf &rcItem);

		const Float2 &GetMousePos() const;
		void SetMinMaxInfo (int cx, int cy);

		const SystemMetricsUI &GetSystemMetrics() const;
		const SystemSettingsUI &GetSystemSettings() const;

		virtual void Run();

	protected:
		void *mPlatformData;

		Sizef mMinSize;
		Float2 mLastMousePos;

		SystemMetricsUI mSystemMetrics;
		SystemSettingsUI mSystemSettings;

		bool mIsResizeNeeded;
	};

#include "PX2UIPaintManager.inl"

}

#endif