/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2BitHacks.hpp
*
* 版本		:	1.0 (2011/01/31)
*
* 作者		：	more
*
*/

#ifndef PX2BITHACKS_HPP
#define PX2BITHACKS_HPP

#include "PX2MathematicsPre.hpp"

namespace PX2
{

	bool IsPowerOfTwo (unsigned int value);
	bool IsPowerOfTwo (int value);

	unsigned int Log2OfPowerOfTwo (unsigned int powerOfTwo);
	int Log2OfPowerOfTwo (int powerOfTwo);

	/// 快速将在区间[0,1]范围内的32bit的浮点数F，转换到在区间[0,2^P-1]的32bit的
	// 整数I。value表示F，power表示P，返回值表示I。
	inline int ScaledFloatToInt (float value, int power);

#include "PX2BitHacks.inl"

}

#endif
