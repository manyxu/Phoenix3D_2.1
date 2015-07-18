// PX2PWindow.hpp

#ifndef PX2PWINDOW_HPP
#define PX2PWINDOW_HPP

#include "PX2PlatformUIPre.hpp"
#include "PX2Vector2.hpp"
#include "PX2Size.hpp"
#include "PX2PWinImpl.hpp"

namespace PX2
{

	class PWindow
	{
	public:
		PWindow();
		virtual ~PWindow();

		void Create(PWindow *parent, const std::string &tilte, 
			const Vector2f &pos, const Sizef &size);

		void Show(bool show = true, bool takeFocus = true);
		void ShowModal();

	protected:
		PWinImplPtr mImpl;
	};

	typedef Pointer0<PWindow> PWindowPtr;

}

#endif