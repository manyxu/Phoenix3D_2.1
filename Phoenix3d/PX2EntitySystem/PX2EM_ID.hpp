/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EM_ID.hpp
*
*/

#ifndef PX2EM_ID_HPP
#define PX2EM_ID_HPP

#include "PX2EntityModule.hpp"

namespace PX2
{

	class EN_ID : public EntityModule
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EN_ID);

	public:
		EN_ID ();
		virtual ~EN_ID();

		enum Type
		{
			T_ID,
			T_TYPEID,
			T_SERVERID,
			T_MAX_TYPE
		};

		// ids
		void SetID (int id);
		int GetID () const;
		void SetTypeID (int typeID);
		int GetTypeID () const;		
		void SetServerID (int id);
		int GetServerID () const;

	protected:
		int mID;
		int mTypeID;
		int mServerID;
	};

	PX2_REGISTER_STREAM(EN_ID);
	typedef Pointer0<EN_ID> EN_IDPtr;
#include "PX2EM_ID.inl"

}

#endif