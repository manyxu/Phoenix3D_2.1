/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UserConstant.hpp
*
*/

#ifndef PX2USERCONSTANCE_HPP
#define PX2USERCONSTANCE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Float4.hpp"

namespace PX2
{

	class UserConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(UserConstant);

	public:
		UserConstant ();
		virtual ~UserConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);
	};

	PX2_REGISTER_STREAM(UserConstant);
	typedef Pointer0<UserConstant> UserConstantPtr;

}

#endif
