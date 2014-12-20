/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Float4.hpp
*
* 版本		:	1.0 (2011/01/30)
*
* 作者		：	more
*
*/

#ifndef PX2FLOAT4_HPP
#define PX2FLOAT4_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Tuple.hpp"

namespace PX2
{

	class Float4 : public Tuple<4,float>
	{
	public:
		Float4 ();   //< 未初始化
		~Float4 ();  // hides ~Tuple<4,float>
		Float4 (float f0, float f1, float f2, float f3);
		Float4 (const Float4& tuple);

		// 赋值
		Float4& operator= (const Float4& tuple);

		static Float4 MakeColor (unsigned int r, unsigned int g, 
			unsigned int b, unsigned int a);

		static const Float4 ZERO;   //< (0,0,0,0)
		static const Float4 UNIT;	//< (1,1,1,1)
		static const Float4 BLACK;	//< (0,0,0,1)
		static const Float4 WHITE;	//< (1,1,1,1)
		static const Float4 RED;	//< (1,0,0,1)
		static const Float4 GREEN;  //< (0,1,0,1)
		static const Float4 BLUE;	//< (0,0,1,1)
		static const Float4 YELLOW; //< (1,1,0,1)
	};

}

#endif
