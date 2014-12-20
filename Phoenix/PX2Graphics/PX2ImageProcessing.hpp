/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2ImageProcessing.hpp
*
* 版本		:	1.0 (2011/03/19)
*
* 作者		：	more
*
*/

#ifndef PX2IMAGEPROCESSING_HPP
#define PX2IMAGEPROCESSING_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Camera.hpp"
#include "PX2PVWMatrixConstant.hpp"
#include "PX2Renderer.hpp"
#include "PX2RenderTarget.hpp"
#include "PX2TriMesh.hpp"

namespace PX2
{

	class ImageProcessing
	{
	public:
		ImageProcessing (int numCols, int numRows, int numTargets);
		virtual ~ImageProcessing ();

		// 成员访问
		inline int GetNumCols () const;
		inline int GetNumRows () const;
		inline int GetNumTargets () const;
		inline float GetColSpacing () const;
		inline float GetRowSpacing () const;
		inline Camera* GetCamera () const;
		inline TriMesh* GetRectangle () const;
		inline RenderTarget* GetTarget (int i) const;

		// The lexicographical mapping into linear memory.
		inline int Index (int col, int row) const;

		// Allow the caller to create an material that shares the vertex shader
		// managed by this class.
		void CreateMaterial (PixelShader* pshader, Material*& material,
			MaterialInstance*& instance);

		// These function calls bound the drawing of the processed image to the
		// backbuffer.
		void PreDraw ();
		void PostDraw ();

		// Support for the standard image processing pipeline.
		inline Texture2D* GetMainTexture () const;
		inline MaterialInstance* GetMainMaterialInstance () const;
		void Initialize (Renderer* renderer, bool openglHack = false);
		void ExecuteStep (Renderer* renderer, bool draw);

	protected:
		void CreateVertexShader ();

		int mNumCols, mNumRows, mNumColsM1, mNumRowsM1;
		int mNumTargets;
		float mColSpacing, mRowSpacing;
		CameraPtr mCamera;
		TriMeshPtr mRectangle;
		VertexShaderPtr mVertexShader;
		PVWMatrixConstantPtr mPVWMatrixConstant;
		RenderTargetPtr* mTargets;

		// Support for the standard image processing pipeline.
		Texture2DPtr mMainTexture;
		MaterialPtr mMainMaterial;
		MaterialInstancePtr mMainMaterialInstance;
		MaterialPtr mBoundaryMaterial;
		MaterialInstancePtr mBoundaryMaterialInstance;
		MaterialPtr mDrawMaterial;
		MaterialInstancePtr mDrawMaterialInstance;
		MaterialPtr mDrawInput;
		MaterialInstancePtr mDrawInputInstance;

		static int msDx9VRegisters[1];
		static int msOglVRegisters[1];
		static int* msVRegisters[Shader::MAX_PROFILES];
		static std::string msVPrograms[Shader::MAX_PROFILES];
	};

#include "PX2ImageProcessing.inl"

}

#endif