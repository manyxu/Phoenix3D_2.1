/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2PickRecord.hpp
*
* 版本		:	1.0 (2011/06/05)
*
* 作者		：	more
*
*/

#ifndef PX2PICKRECORD_HPP
#define PX2PICKRECORD_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Movable.hpp"

namespace PX2
{

	/// 裁剪物体纪录类
	class PickRecord
	{
	public:
		PickRecord ();
		~PickRecord ();

		// 用来选择支持
		inline bool operator== (const PickRecord& record) const;
		inline bool operator!= (const PickRecord& record) const;
		inline bool operator<  (const PickRecord& record) const;
		inline bool operator<= (const PickRecord& record) const;
		inline bool operator>  (const PickRecord& record) const;
		inline bool operator>= (const PickRecord& record) const;

		// 相交的物体
		MovablePtr Intersected;

		// 射线P + t*D中的线性元素量。T是其中t的表示。
		float T;

		// 被射线相交的三角形
		int Triangle;

		// 质心坐标系点选择。所有坐标都在区间[0,1]内，
		// 并且Bary[0] + Bary[1] + Bary[2] = 1。
		float Bary[3];
	};

#include "PX2PickRecord.inl"

}

#endif
