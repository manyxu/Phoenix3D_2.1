// PX2Edit.hpp

#ifndef PX2EDIT_HPP
#define PX2EDIT_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2EditMap.hpp"

namespace PX2
{

	class EditMap;

	class Edit : public Singleton<Edit>
	{
	public:
		Edit();
		~Edit();

		bool Initlize();
		bool Ternamate();

		EditMap *GetEditMap();

		static void SetEditForm(int from);
		static int GetEditID();

	protected:
		EditMap *mEditMap;

		static int msEditorID;
	};

#include "PX2Edit.inl"

#define PX2_EDIT Edit::GetSingleton()
#define PX2_EDIT_GETID Edit::GetEditID()

}

#endif