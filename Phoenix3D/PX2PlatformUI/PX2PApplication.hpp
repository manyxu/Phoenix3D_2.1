// PX2PApplication.hpp

#ifndef PX2PAPPLICATION_HPP
#define PX2PAPPLICATION_HPP

#include "PX2PAppImpl.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"

namespace PX2
{

	class PApplication : public Singleton<PApplication>
	{
	public:
		PApplication();
		virtual ~PApplication();

		void SetWinInstance(void *inst);
		void *GetWinInstance();

		void Run();

		void SetCaptionRect(const Rectf &rect);
		const Rectf &GetCaptionRect() const;

		void SetRoundCorner(const Rectf &rect);
		const Rectf &GetRoundCorner() const;

		PAppImpl *GetImpl();

	protected:
		Rectf mCaptionRect;
		Rectf mRoundCorner;

		PAppImplPtr mImpl;
	};

	typedef Pointer0<PApplication> PApplicationPtr;

}

#endif