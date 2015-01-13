/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Float3.hpp
*
* 版本		:	1.0 (2011/01/30)
*
* 作者		：	more
*
*/

#ifndef PX2FLOAT3_HPP
#define PX2FLOAT3_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Tuple.hpp"

namespace PX2
{

	class Float3 : public Tuple<3,float>
	{
	public:
		Float3 ();   //< 未初始化
		~Float3 ();  // hides ~Tuple<3,float>
		Float3 (float f0, float f1, float f2);
		Float3 (const Float3& tuple);

		// 赋值
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
		static const Float3 BLACK;	//< (0,0,0)
		static const Float3 WHITE;	//< (1,1,1)
		static const Float3 RED;	//< (1,0,0)
		static const Float3 GREEN;  //< (0,1,0)
		static const Float3 BLUE;	//< (0,0,1)
		static const Float3 YELLOW; //< (1,1,0)
	};

}

#endif