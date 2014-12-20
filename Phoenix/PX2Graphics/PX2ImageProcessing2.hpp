/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2ImageProcessing2.hpp
*
* 版本		:	1.0 (2011/03/19)
*
* 作者		：	more
*
*/

#ifndef PX2IMAGEPROCESSING2_HPP
#define PX2IMAGEPROCESSING2_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ImageProcessing.hpp"

namespace PX2
{

	/**
	* 这个类的对象只有在着色器版本确定之后才能被创建，所以不能在应用程序的构造
	* 函数里创建该对象，将其放到例似OnInitialize或者之后的函数里。
	*/
	class ImageProcessing2 : public ImageProcessing
	{
	public:
		// Use this constructor for the standard image processing pipeline.
		ImageProcessing2 (int bound0, int bound1, Float4* imageData,
			PixelShader* mainPShader, bool useDirichlet);

		// Use this constructor when you want to set up your own pipeline for
		// processing the image.
		ImageProcessing2 (int bound0, int bound1, int numTargets);

		virtual ~ImageProcessing2 ();

		// 成员访问
		inline int GetBound0 () const;
		inline int GetBound1 () const;
		inline float GetDx () const;
		inline float GetDy () const;

		// Create a texture corresponding to the 2D image data.
		Texture2D* CreateImage (Float4* imageData);

		// Set boundary pixels to (0,0,0,0).
		void CreateBoundaryDirichletMaterial (Material*& material,
			MaterialInstance*& instance);

		// Set boundary pixels so that boundary derivatives are zero.
		void CreateBoundaryNeumannMaterial (Material*& material,
			MaterialInstance*& instance);

		// Draw the image.
		void CreateDrawMaterial (Material*& material,
			MaterialInstance*& instance);

	private:
		void CreateVertexShader ();

		int mBound0, mBound1, mBound0M1, mBound1M1;
		float mDx, mDy;

		// Profile information for BoundaryDirichlet.fx.
		static int msAllDirichletPTextureUnits[2];
		static int* msDirichletPTextureUnits[Shader::MAX_PROFILES];
		static std::string msDirichletPPrograms[Shader::MAX_PROFILES];

		// Profile information for BoundaryNeumann.fx.
		static int msAllNeumannPTextureUnits[2];
		static int* msNeumannPTextureUnits[Shader::MAX_PROFILES];
		static std::string msNeumannPPrograms[Shader::MAX_PROFILES];

		// Profile information for ScreenShader.fx, function v_ScreenShader and
		// p_ScreenShader2.
		static int msAllDrawPTextureUnits[2];
		static int* msDrawPTextureUnits[Shader::MAX_PROFILES];
		static std::string msDrawPPrograms[Shader::MAX_PROFILES];
	};

#include "PX2ImageProcessing2.inl"

}

#endif