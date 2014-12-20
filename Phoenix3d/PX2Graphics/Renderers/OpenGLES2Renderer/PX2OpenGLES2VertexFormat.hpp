/*
* Turandot 3D 游戏引擎 Version 1.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	TdOpenGLES2VertexFormat.hpp
*
* 版本		:	1.0 (2011/07/12)
*
* 作者		：	许多
*
*/

#ifndef PX2OPENGLVERTEXFORMAT_HPP
#define PX2OPENGLVERTEXFORMAT_HPP

#include "PX2OpenGLES2RendererPre.hpp"
#include "PX2VertexFormat.hpp"

namespace PX2
{

	class Renderer;

	class PdrVertexFormat
	{
	public:
		PdrVertexFormat (Renderer* renderer, const VertexFormat* vformat);
		~PdrVertexFormat ();

		void Enable (Renderer* renderer);
		void Disable (Renderer* renderer);

	private:
		int mStride;

		GLuint mHasPosition;
		GLuint mPositionChannels;
		GLuint mPositionType;
		GLuint mPositionOffset;

		GLuint mHasNormal;
		GLuint mNormalChannels;
		GLuint mNormalType;
		GLuint mNormalOffset;

		GLuint mHasTangent;
		GLuint mTangentChannels;
		GLuint mTangentType;
		GLuint mTangentOffset;

		GLuint mHasBinormal;
		GLuint mBinormalChannels;
		GLuint mBinormalType;
		GLuint mBinormalOffset;

		GLuint mHasTCoord[VertexFormat::AM_MAX_TCOORD_UNITS];
		GLuint mTCoordChannels[VertexFormat::AM_MAX_TCOORD_UNITS];
		GLuint mTCoordType[VertexFormat::AM_MAX_TCOORD_UNITS];
		GLuint mTCoordOffset[VertexFormat::AM_MAX_TCOORD_UNITS];

		GLuint mHasColor[VertexFormat::AM_MAX_COLOR_UNITS];
		GLuint mColorChannels[VertexFormat::AM_MAX_COLOR_UNITS];
		GLuint mColorType[VertexFormat::AM_MAX_COLOR_UNITS];
		GLuint mColorOffset[VertexFormat::AM_MAX_COLOR_UNITS];

		GLuint mHasBlendIndices;
		GLuint mBlendIndicesChannels;
		GLuint mBlendIndicesType;
		GLuint mBlendIndicesOffset;

		GLuint mHasBlendWeight;
		GLuint mBlendWeightChannels;
		GLuint mBlendWeightType;
		GLuint mBlendWeightOffset;

		GLuint mHasFogCoord;
		GLuint mFogCoordChannels;
		GLuint mFogCoordType;
		GLuint mFogCoordOffset;

		GLuint mHasPSize;
		GLuint mPSizeChannels;
		GLuint mPSizeType;
		GLuint mPSizeOffset;
	};

}

#endif
