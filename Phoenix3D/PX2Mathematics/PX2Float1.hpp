/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Float1.hpp
*
* 版本		:	1.0 (2011/01/30)
*
* 作者		：	more
*
*/

#ifndef PX2FLOAT1_HPP
#define PX2FLOAT1_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Tuple.hpp"

namespace PX2
{

	class Float1 : public Tuple<1,float>
	{
	public:
		Float1 ();   //< 未初始化
		~Float1 ();  // hides ~Tuple<1,float>
		Float1 (float f0);
		Float1 (const Float1& tuple);

		// 赋值
		Float1& operator= (const Float1& tuple);
	};

}

#endif
