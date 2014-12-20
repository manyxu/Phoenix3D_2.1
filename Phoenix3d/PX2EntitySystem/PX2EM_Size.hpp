/*
*
* ÎÄ¼þÃû³Æ	£º	PX2EM_Size.hpp
*
*/

#ifndef PX2EM_SIZE_HPP
#define PX2EM_SIZE_HPP

#include "PX2EntityModule.hpp"

namespace PX2
{

	class EN_Size : public EntityModule
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(EN_Size);

	public:
		EN_Size ();
		virtual ~EN_Size();

		enum Type
		{
			T_LENGTH,
			T_WIDTH,
			T_HEIGHT,
			T_RADIUS,
			T_MAX_TYPE
		};

		void SetLength (float val);
		void SetWidth (float val);
		void SetHeight (float val);
		void SetRadius (float radius);
		float GetLength () const;
		float GetWidth () const;
		float GetHeight () const;
		float GetRadius () const;

	protected:
		float mLength;
		float mWidth;
		float mHeight;
		float mRadius;
	};

	PX2_REGISTER_STREAM(EN_Size);
	typedef Pointer0<EN_Size> EN_SizePtr;
#include "PX2EM_Size.inl"

}

#endif