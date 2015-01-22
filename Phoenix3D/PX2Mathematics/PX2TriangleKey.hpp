/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2TriangleKey.hpp
*
* 版本		:	1.0 (2011/03/19)
*
* 作者		：	more
*
*/

#ifndef PX2TRIANGLEKEY_HPP
#define PX2TRIANGLEKEY_HPP

#include "PX2MathematicsPre.hpp"

namespace PX2
{

	class TriangleKey
	{
	public:
		TriangleKey (int v0 = -1, int v1 = -1, int v2 = -1);

		bool operator< (const TriangleKey& key) const;
		operator size_t () const;

		int V[3];
	};

#include "PX2TriangleKey.inl"

}

#endif