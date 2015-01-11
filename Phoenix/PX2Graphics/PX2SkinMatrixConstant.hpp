/*
*
* ÎÄ¼þÃû³Æ	£º	PX2SkinMatrixConstant.hpp
*
*/

#ifndef PX2SKINMATRIXCONSTANT_HPP
#define PX2SKINMATRIXCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"

namespace PX2
{

	class SkinController;

	class SkinMatrixConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkinMatrixConstant);

	public:
		SkinMatrixConstant (int numMatrix=37);
		virtual ~SkinMatrixConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);

	private:		
		SkinController *mSkinContrl;
	};

	PX2_REGISTER_STREAM(SkinMatrixConstant);
	typedef Pointer0<SkinMatrixConstant> SkinMatrixConstantPtr;

}

#endif