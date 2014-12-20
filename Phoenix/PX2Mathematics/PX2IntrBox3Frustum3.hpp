/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2IntrBox3Frustum3.hpp
*
* 版本		:	1.0 (2011/04/09)
*
* 作者		：	more
*
*/

#ifndef PX2INTRBOX3FRUSTUM3_HPP
#define PX2INTRBOX3FRUSTUM3_HPP

#include "PX2MathematicsPre.hpp"
#include "PX2Intersector.hpp"
#include "PX2Box3.hpp"
#include "PX2Frustum3.hpp"

namespace PX2
{

	/// Box3，Frustum3相交模板类
	template <typename Real>
	class IntrBox3Frustum3
		: public Intersector<Real,Vector3<Real> >
	{
	public:
		IntrBox3Frustum3 (const Box3<Real>& box, const Frustum3<Real>& frustum);

		// 对象访问
		const Box3<Real>& GetBox () const;
		const Frustum3<Real>& GetFrustum () const;

		// 相交检测
		virtual bool Test ();

	private:
		const Box3<Real>* mBox;
		const Frustum3<Real>* mFrustum;
	};

	typedef IntrBox3Frustum3<float> IntrBox3Frustum3f;
	typedef IntrBox3Frustum3<double> IntrBox3Frustum3d;

}

#endif
