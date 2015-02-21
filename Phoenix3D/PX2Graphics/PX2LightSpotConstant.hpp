// PX2LightSpotConstant.hpp

#ifndef PX2LIGHTSPOTCONSTANT_HPP
#define PX2LIGHTSPOTCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class LightSpotConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(LightSpotConstant);

	public:
		LightSpotConstant (Light* light);
		virtual ~LightSpotConstant ();

		void SetLight (Light *light);
		Light* GetLight ();

		virtual void Update (const Renderable* renderable, const Camera* camera);

	protected:
		LightPtr mLight;
	};

	PX2_REGISTER_STREAM(LightSpotConstant);
	typedef Pointer0<LightSpotConstant> LightSpotConstantPtr;

}

#endif
