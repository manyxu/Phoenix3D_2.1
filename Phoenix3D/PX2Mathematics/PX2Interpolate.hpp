// PX2Interpolate.hpp

#ifndef PX2INTERPOLATE_HPP
#define PX2INTERPOLATE_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Float4.hpp"

namespace PX2
{

	class PX2_MATHEMATICS_ITEM Interpolate
	{
	public:
		Interpolate ();
		~Interpolate ();

		static float LinearFloat (float &v0, float &v1, float t);
		static Float4 LinearFloat4 (Float4 &v0, Float4 &v1, float t);

	};
}

#endif