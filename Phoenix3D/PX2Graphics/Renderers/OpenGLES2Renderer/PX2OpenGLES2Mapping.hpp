/*
* Turandot 3D 游戏引擎 Version 1.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	TdOpenGLES2Mapping.hpp
*
* 版本		:	1.0 (2011/07/12)
*
* 作者		：	许多
*
*/

#ifndef PX2OPENGLMAPPING_HPP
#define PX2OPENGLMAPPING_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2AlphaProperty.hpp"
#include "PX2Buffer.hpp"
#include "PX2CullProperty.hpp"
#include "PX2DepthProperty.hpp"
#include "PX2Shader.hpp"
#include "PX2StencilProperty.hpp"
#include "PX2Texture.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2Renderable.hpp"

namespace PX2
{
	extern GLenum gOGLAlphaSrcBlend[AlphaProperty::SBM_QUANTITY];
	extern GLenum gOGLAlphaDstBlend[AlphaProperty::DBM_QUANTITY];
	extern GLenum gOGLAlphaCompare[AlphaProperty::CM_QUANTITY];
	extern GLenum gOGLDepthCompare[AlphaProperty::CM_QUANTITY];
	extern GLenum gOGLStencilCompare[StencilProperty::CM_QUANTITY];
	extern GLenum gOGLStencilOperation[StencilProperty::OT_QUANTITY];
	extern GLint  gOGLAttributeChannels[VertexFormat::AT_QUANTITY];
	extern GLuint gOGLAttributeType[VertexFormat::AT_QUANTITY];
	extern GLuint gOGLBufferLocking[Buffer::BL_QUANTITY];
	extern GLuint gOGLBufferUsage[Buffer::BU_QUANTITY];
	extern GLint  gOGLMinFilter[Shader::SF_QUANTITY];
	extern GLuint gOGLTextureFormat[Texture::TF_QUANTITY];
	extern GLuint gOGLTextureInternalFormat[Texture::TF_QUANTITY];
	extern GLuint gOGLTextureTarget[Shader::ST_QUANTITY];
	extern GLuint gOGLTextureType[Texture::TF_QUANTITY];
	extern GLint  gOGLWrapMode[Shader::SC_QUANTITY];
	extern GLenum gOGLPrimitiveType[Renderable::PT_MAX_QUANTITY];
}

#endif