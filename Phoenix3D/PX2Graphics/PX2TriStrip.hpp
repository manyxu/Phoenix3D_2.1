/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2TriStrip.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2TRISTRIP_HPP
#define PX2TRISTRIP_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Triangles.hpp"

namespace PX2
{
	
	/// 三角形条带类
	class TriStrip : public Triangles
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(TriStrip);

	protected:
		TriStrip ();

	public:
		/**
		* indexSize是顶点索引，一个元素的字节数。
		*/
		TriStrip (VertexFormat* vformat, VertexBuffer* vbuffer, int indexSize);
		TriStrip (VertexFormat* vformat, VertexBuffer* vbuffer,
			IndexBuffer* ibuffer);

		virtual ~TriStrip ();

		void CalIndexs (int indexSize=2);

		virtual int GetNumTriangles () const;
		virtual bool GetTriangle (int i, int& v0, int& v1, int& v2) const;
	};

	PX2_REGISTER_STREAM(TriStrip);
	typedef Pointer0<TriStrip> TriStripPtr;

}

#endif
