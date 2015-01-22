/*
*
* ÎÄ¼þÃû³Æ	£º	PX2FogColorConstant.hpp
*
*/

#ifndef PX2FOGCOLORCONSTANT_HPP
#define PX2FOGCOLORCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Float4.hpp"

namespace PX2
{

	class FogColorConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(FogColorConstant);

	public:
		FogColorConstant ();
		virtual ~FogColorConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);
	};

	PX2_REGISTER_STREAM(FogColorConstant);
	typedef Pointer0<FogColorConstant> FogColorConstantPtr;

}

#endif
