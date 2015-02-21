// PX2Float1.hpp

#ifndef PX2FLOAT1_HPP
#define PX2FLOAT1_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Tuple.hpp"

namespace PX2
{

	class Float1 : public Tuple<1,float>
	{
	public:
		Float1 ();   //< Î´³õÊ¼»¯
		~Float1 ();  // hides ~Tuple<1,float>
		Float1 (float f0);
		Float1 (const Float1& tuple);

		// ¸³Öµ
		Float1& operator= (const Float1& tuple);
	};

}

#endif
