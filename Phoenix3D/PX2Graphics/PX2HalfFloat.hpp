/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2HalfFloat.hpp
*
* 版本		:	1.0 (2011/01/31)
*
* 作者		：	more
*
*/

#ifndef PX2HALFFLOAT_HPP
#define PX2HALFFLOAT_HPP

#include "PX2GraphicsPre.hpp"

namespace PX2
{

	//----------------------------------------------------------------------------
	// A 16-bit floating-point number has a 1-bit sign (S), a 5-bit
	// exponent (E), and a 10-bit mantissa (M).  The value of a 16-bit
	// floating-point number is determined by the following:
	//    (-1)^S * 0.0,                        if E == 0 and M == 0,
	//    (-1)^S * 2^-14 * (M / 2^10),         if E == 0 and M != 0,
	//    (-1)^S * 2^(E-15) * (1 + M/2^10),    if 0 < E < 31,
	//    (-1)^S * INF,                        if E == 31 and M == 0, or
	//    NaN,                                 if E == 31 and M != 0,
	// where
	//    S = floor((N mod 65536) / 32768),
	//    E = floor((N mod 32768) / 1024), and
	//    M = N mod 1024.
	// Implementations are also allowed to use any of the following
	// alternative encodings:
	//    (-1)^S * 0.0,                        if E == 0 and M != 0,
	//    (-1)^S * 2^(E-15) * (1 + M/2^10),    if E == 31 and M == 0, or
	//    (-1)^S * 2^(E-15) * (1 + M/2^10),    if E == 31 and M != 0,
	//
	// This table explains the conversions in ToHalf and ToFloat.
	// ---------------------------
	// bias16  exp32  bias32
	// ---------------------------
	//     0    -127      0 (0x00)
	//     :       :      :
	//     0     -15    112 (0x70)
	// ---------------------------
	//     1     -14    113 (0x71)
	//     :       :      :
	//    15       0    127 (0x7F)
	//     :       :      :
	//    30      15    142 (0x8E)
	// ---------------------------
	//    31      16    143 (0x8F)
	//     :       :      :
	//    31     128    255 (0xFF)
	// ---------------------------
	//----------------------------------------------------------------------------

	typedef unsigned short HalfFloat;

	HalfFloat ToHalf (float value);
	float ToFloat (HalfFloat value);

}

#endif