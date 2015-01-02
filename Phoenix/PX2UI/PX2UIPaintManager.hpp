// PX2UIPaintManager.hpp

#ifndef PX2UIPAINTMANAGER_HPP
#define PX2UIPAINTMANAGER_HPP

#include "PX2Singleton.hpp"
#include "PX2Size.hpp"
#include "PX2APoint.hpp"
#include "PX2Float2.hpp"
#include "PX2UIDefinePre.hpp"

namespace PX2
{

	class UIPaintManager : public Singleton<UIPaintManager>
	{
	public:
		UIPaintManager();
		virtual ~UIPaintManager();

		void Init();

		const Float2 &GetMousePos() const;
		void SetMinMaxInfo (int cx, int cy);

	protected:
		Sizef mMinSize;
		Float2 mLastMousePos;

		SystemMetricsUI mSystemMetrics;
		SystemSettingsUI mSystemConfig;

		bool mIsResizeNeeded;
	};

}

#endif