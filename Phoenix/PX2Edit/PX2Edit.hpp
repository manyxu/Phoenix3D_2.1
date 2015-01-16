// PX2Edit.hpp

#ifndef PX2EDIT_HPP
#define PX2EDIT_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2EditUIMan.hpp"

namespace PX2
{

	class Edit : public Singleton<Edit>
	{
	public:
		Edit();
		~Edit();

		bool Initlize();
		bool Ternamate();

	protected:
		EditUIMan *mEditUIMain;
	};

#define PX2EDIT Edit::GetSingleton()

}

#endif