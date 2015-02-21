// PX2LightAmbientConstant.hpp

#ifndef PX2LIGHTAMBIENTCONSTANT_HPP
#define PX2LIGHTAMBIENTCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"
#include "PX2Light.hpp"

namespace PX2
{

class LightAmbientConstant : public ShaderFloat
{
    PX2_DECLARE_RTTI;
    PX2_DECLARE_NAMES;
    PX2_DECLARE_STREAM(LightAmbientConstant);

public:
    LightAmbientConstant (Light* light);
    virtual ~LightAmbientConstant ();

	void SetLight (Light *light);
    Light* GetLight ();

    virtual void Update (const Renderable* renderable, const Camera* camera);

protected:
    LightPtr mLight;
};

PX2_REGISTER_STREAM(LightAmbientConstant);
typedef Pointer0<LightAmbientConstant> LightAmbientConstantPtr;

}

#endif
