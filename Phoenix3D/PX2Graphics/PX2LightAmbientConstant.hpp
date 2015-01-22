/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2LightAmbientConstant.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

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
