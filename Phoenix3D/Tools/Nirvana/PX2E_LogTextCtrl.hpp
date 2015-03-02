// PX2E_LogTextCtrl.hpp

#ifndef PX2E_LOGTEXTCTRL_HPP
#define PX2E_LOGTEXTCTRL_HPP

#include "PX2EditorPre.hpp"
#include "PX2EventHandler.hpp"
#include "PX2Log.hpp"

namespace PX2Editor
{

	class LogTextCtrl : public wxTextCtrl, public PX2::LogHandler
	{
	public:
		LogTextCtrl(wxWindow *parent);
		virtual ~LogTextCtrl();

		virtual void Handle(const PX2::LogBuffer *logBuffer,
			const char *timeStamp);

	protected:
		DECLARE_EVENT_TABLE()
	};

}

#endif