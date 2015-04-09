// PX2ObjectPropertyGrid.hpp

#ifndef PX2OBJECTPROPERTYGRID_HPP
#define PX2OBJECTPROPERTYGRID_HPP

#include "PX2PropertyGrid.hpp"
#include "PX2Object.hpp"

namespace PX2Editor
{

	class ObjectPropertyGrid : public PropertyGrid
	{
	public:
		ObjectPropertyGrid(wxWindow *parent);
		virtual ~ObjectPropertyGrid();

		DECLARE_DYNAMIC_CLASS(ObjectPropertyGrid)

		void SetObject(PX2::Object *actor);
		virtual void OnSetObject(PX2::Object *actor);
		PX2::Object *GetObject();

		virtual void OnPropertyGridChange(wxPropertyGridEvent &event);
		virtual void OnPropertyGridChanging(wxPropertyGridEvent &event);
		virtual void OnPropertyGridCollapsed(wxPropertyGridEvent &event);
		virtual void OnPropertyGridExpanded(wxPropertyGridEvent &event);

		void OnSize(wxSizeEvent &e);

	protected:
		ObjectPropertyGrid();

		DECLARE_EVENT_TABLE()

		PX2::ObjectPtr mObject;

		std::map<std::string, wxPGProperty *> mClassProperies;
		std::vector<std::string> mCollpasedClassNames;
	};

}

#endif