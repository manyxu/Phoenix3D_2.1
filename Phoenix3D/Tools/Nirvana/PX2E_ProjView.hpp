// PX2E_ProjView.hpp

#ifndef PX2E_PROJVIEW_HPP
#define PX2E_PROJVIEW_HPP

#include "PX2EditorPre.hpp"
#include "PX2E_ProjTree.hpp"
#include "PX2EditParams.hpp"
using namespace PX2;

namespace PX2Editor
{

	class ProjView : public wxWindow
	{
		DECLARE_DYNAMIC_CLASS(ProjView)

	public:
		ProjView(wxWindow *parent);
		virtual ~ProjView();

		ProjTree *GetProjTree();
		void SetColorForTheme(EditParams::Theme theme);

	protected:
		DECLARE_EVENT_TABLE()

		ProjView();

		wxToolBar *mProjTreeBar;
		ProjTree *mProjTree;
	};

}

#endif