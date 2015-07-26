// PX2Float3.hpp

#ifndef PX2FLOAT3_HPP
#define PX2FLOAT3_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Tuple.hpp"

namespace PX2
{

	class PX2_MATHEMATICS_ITEM Float3 : public Tuple<3, float>
	{
	public:
		Float3 ();   //< Î´³õÊ¼»¯
		~Float3 ();  // hides ~Tuple<3,float>
		Float3 (float f0, float f1, float f2);
		Float3 (const Float3& tuple);

		// ¸³Öµ
		Float3& operator= (const Float3& tuple);

		Float3 operator+ (const Float3& tuple) const;
		Float3 operator- (const Float3& tuple) const;
		Float3 operator* (float scalar) const;
		Float3 operator/ (float scalar) const;
		Float3& operator+= (const Float3& tuple);
		Float3& operator-= (const Float3& tuple);
		Float3& operator*= (float scalar);
		Float3& operator/= (float scalar);
		Float3& operator- ();

		static Float3 MakeColor (unsigned int r, unsigned int g, 
			unsigned int b);

		static const Float3 ZERO;   //< (0,0,0)
		static const Float3 UNIT;	//< (1,1,1)
		static const Float3 UNIT_X;	//< (1,0,0)
		static const Float3 UNIT_Y;	//< (0,1,0)
		static const Float3 UNIT_Z;	//< (0,0,1)
		static const Float3 BLACK;	//< (0,0,0)
		static const Float3 WHITE;	//< (1,1,1)
		static const Float3 RED;	//< (1,0,0)
		static const Float3 GREEN;  //< (0,1,0)
		static const Float3 BLUE;	//< (0,0,1)
		static const Float3 YELLOW; //< (1,1,0)
	};

}

#endif