/*
*
* ÎÄ¼þÃû³Æ	£º	PX2PropertyPage.hpp
*
*/

#ifndef PX2PROPERTYPAGE_HPP
#define PX2PROPERTYPAGE_HPP

#include "PX2EditorPre.hpp"
#include "PX2EditProperty.hpp"

namespace PX2Editor
{

	class PropertyGrid;

	class PropertyPage
	{
	public:
		PropertyPage (PropertyGrid *parent, std::string name = "");
		~PropertyPage ();

		PropertyGrid *GetGrid () { return mParent; }

		std::string GetName () { return mName; }

		void Clear ();
		Property *AddProperty (const std::string &name, const std::string &tag,
			Property::PropertyType type, void *data, bool enable=true, 
			const std::vector<std::string> *enums=0);
		Property *GetProperty (const std::string &name);
		bool HasProperty (wxPGProperty *prop);
		void RemoveProperty (const std::string &name);

		void OnPropertyGridChange (wxPropertyGridEvent &event);
		void OnPropertyGridChanging (wxPropertyGridEvent &event);
		void OnPropertyGridSelect (wxPropertyGridEvent &event);

	protected:
		std::string mName;

public_internal:
		void AddProperty (Property *prop);
		
		PropertyGrid *mParent;
		std::vector<PropertyPtr> mProperties;
		wxPropertyGridPage *mPage;
	};

	typedef PX2::Pointer0<PropertyPage> PropertyPagePtr;

}

#endif