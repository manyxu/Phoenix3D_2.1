// PX2OpenGLES2MaterialPass.hpp

#ifdef PX2_USE_OPENGLES2

#ifndef PX2OPENGLES2MATERIALPASS_HPP
#define PX2OPENGLES2MATERIALPASS_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2PixelShader.hpp"
#include "PX2MaterialPass.hpp"

namespace PX2
{

	class Renderer;

	class PdrMaterialPass
	{
	public:
		PdrMaterialPass (Renderer *renderer, const MaterialPass *pass);
		~PdrMaterialPass ();

		void Enable (Renderer *renderer);
		void Disable (Renderer *renderer);

		GLuint GetProgram () { return mProgramObject; }

	private:
		const MaterialPass *mPass;
		GLuint mProgramObject;

		std::map<std::string, int> mAttribLocations;
	};

}

#endif

#endif