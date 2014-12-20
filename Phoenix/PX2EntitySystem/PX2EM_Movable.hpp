/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EM_Movable.hpp
*
*/

#ifndef PX2EM_MOVABLE_HPP
#define PX2EM_MOVABLE_HPP

#include "PX2EntityModule.hpp"
#include "PX2Node.hpp"
#include "PX2ResourceManager.hpp"

namespace PX2
{

	class EM_Movable : public EntityModule
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EM_Movable);

	public:
		EM_Movable ();
		virtual ~EM_Movable();

		virtual void Update (float appTime, float elapsedTime);

		void SetMovableFilename (const std::string &filename,
			bool block=false);
		const std::string &GetMovableFilename () const;
		bool IsSetMovableBlock () const;
		void SetMovable (Movable *movable);
		Movable *GetMovable () const;

		APoint GetAnchorPos (const std::string &name);
		Node *GetAnchor (const std::string &name);

		void SetVisible (bool visible);
		bool IsVisible () const;
		void SetTransparent (float alpha);
		float GetTransparent () const;

	protected:
		bool mIsSetMovableBlock;
		std::string mMovableFilename;
		ResHandle mMovableHandle;
		MovablePtr mMovable;
	};

	PX2_REGISTER_STREAM(EM_Movable);
	typedef Pointer0<EM_Movable> EN_MovablePtr;
#include "PX2EM_Movable.inl"

}

#endif