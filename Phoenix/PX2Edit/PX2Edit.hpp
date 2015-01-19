// PX2Edit.hpp

#ifndef PX2EDIT_HPP
#define PX2EDIT_HPP

#include "PX2Singleton_NeedNew.hpp"

namespace PX2
{

	class Edit : public Singleton<Edit>
	{
	public:
		Edit();
		~Edit();

		bool Initlize();
		bool Ternamate();

		static void SetEditForm(int from);
		static int GetEditID();

	protected:
		static int msEditorID;
	};

#define PX2EDIT Edit::GetSingleton()
#define PX2EDIT_GETID Edit::GetEditID()

}

#endif