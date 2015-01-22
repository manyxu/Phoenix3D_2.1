/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2ContSphere3.hpp
*
* 版本		:	1.0 (2011/01/30)
*
* 作者		：	more
*
*/

#ifndef PX2CONTSPHERE3_HPP
#define PX2CONTSPHERE3_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Sphere3.hpp"

namespace PX2
{

	// 首先计算点的轴向AABB包围盒，然后计算AABB的球形包围盒
	template <typename Real> 
		Sphere3<Real> ContSphereOfAABB (int numPoints, const Vector3<Real>* points);

	// 计算输入点最小包围盒
	template <typename Real> 
		Sphere3<Real> ContSphereAverage (int numPoints, const Vector3<Real>* points);

	// 检测点是否在球内
	template <typename Real> 
		bool InSphere (const Vector3<Real>& point, const Sphere3<Real>& sphere);

	// 两球体融合
	template <typename Real> 
		Sphere3<Real> MergeSpheres (const Sphere3<Real>& sphere0,
		const Sphere3<Real>& sphere1);

}

#endif
