/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2ScreenTarget.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2SCREENTARGET_HPP
#define PX2SCREENTARGET_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Camera.hpp"
#include "PX2TriMesh.hpp"

namespace PX2
{

	class ScreenTarget
	{
	public:
		// 屏幕空间的相机
		static Camera* CreateCamera ();

		// 创建reder target的屏幕网格。顶点格式必须有3-tuple positions和2-tuple
		// texture coordinates in unit 0。其他属性[xmin,xmax]x[ymin,ymax]所代表
		// 的区间必须在范围[0,1]x[0,1]内。
		static TriMesh *CreateRectangle (VertexFormat* vformat, int rtWidth,
			int rtHeight, float xmin, float xmax, float ymin, float ymax,
			float zValue);

		static TriMesh *CreateRectangle (VertexFormat* vformat, float xMin,
			float xMax, float yMin, float yMax, float zValue);

		/// 拷贝屏幕矩形的空间位置到输入的数组里
		static bool CreatePositions (int rtWidth, int rtHeight, float xmin,
			float xmax, float ymin, float ymax, float zValue, Float3* positions);

		/// 拷贝屏幕矩形的纹理坐标到输入的数组里
		static void CreateTCoords (Float2* tcoords);

	private:
		static bool ValidSizes (int rtWidth, int rtHeight);
		static bool ValidFormat (VertexFormat* vformat);
	};

}

#endif