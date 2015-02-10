// TdOpenGLES2RendererPre.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2RENDERERPRE_HPP
#define PX2OPENGLES2RENDERERPRE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Assert.hpp"

#if defined(_WIN32) || defined(WIN32)

#include <GLES2/gl2.h>
#include <EGL/egl.h>

#elif defined (__ANDROID__)

#include <GLES2/gl2.h>
#include <EGL/egl.h>

#elif defined (__IOS__)

#include <OpenGLES/ES2/gl.h>
#include <OpenGLES/ES2/glext.h>

#elif defined(__MARMALADE__)

#include <GLES2/gl2.h>
#include <EGL/egl.h>
#include <s3e.h>

#endif

enum AttribLocationPos
{
	ALP_POSITION = 0,
	ALP_NORMAL,
	ALP_COLOR0,
	ALP_TEXCOORD0,
	ALP_TEXCOORD1,
	ALP_TEXCOORD2,
	ALP_TEXCOORD3,
	ALP_TEXCOORD4
};

#if defined(_DEBUG)

#define PX2_GL_CHECK(x) \
	x; \
		{ \
		GLenum glError = glGetError(); \
		if(glError != GL_NO_ERROR) { \
		assertion(false, "glGetError() = %i (0x%.8x) at line %i\n", glError, glError, __LINE__); \
		} \
		}

#define PX2_EGL_CHECK(x) \
	x; \
	{ \
	EGLint eglError = eglGetError(); \
	if(eglError != EGL_SUCCESS) { \
	assertion(false, "eglGetError() = %i (0x%.8x) at line %i\n", eglError, eglError, __LINE__); \
	} \
	}

#else

#define PX2_GL_CHECK(x) x;

#define PX2_EGL_CHECK(x) x;

#endif

#endif

#endif