// PX2PVWMatrixConstant.hpp

#ifndef PX2PVWMATRIXCONSTANT_HPP
#define PX2PVWMATRIXCONSTANT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderFloat.hpp"

namespace PX2
{

	class PVWMatrixConstant : public ShaderFloat
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(PVWMatrixConstant);

	public:
		PVWMatrixConstant ();
		virtual ~PVWMatrixConstant ();

		virtual void Update (const Renderable* renderable, const Camera* camera);
	};

	PX2_REGISTER_STREAM(PVWMatrixConstant);
	typedef Pointer0<PVWMatrixConstant> PVWMatrixConstantPtr;

}

#endif
