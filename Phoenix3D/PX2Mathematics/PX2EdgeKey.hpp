/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2EdgeKey.hpp
*
* 版本		:	1.0 (2011/03/19)
*
* 作者		：	more
*
*/

#ifndef PX2EDGEKEY_H
#define PX2EDGEKEY_H

#include "PX2MathematicsPre.hpp"

namespace PX2
{

	class EdgeKey
	{
	public:
		EdgeKey (int v0 = -1, int v1 = -1);

		bool operator< (const EdgeKey& key) const;
		operator size_t () const;

		int V[2];
	};

#include "PX2EdgeKey.inl"

}

#endif
