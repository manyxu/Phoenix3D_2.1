/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2GraphicsRoot.hpp
*
* 版本		:	1.0 (2012/04/15)
*
* 作者		：	more
*
*/

#ifndef PX2GRAPHICSROOT_HPP
#define PX2GRAPHICSROOT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Size.hpp"
#include "PX2Camera.hpp"
#include "PX2Light.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Rect.hpp"
#include "PX2VertexFormat.hpp"
#include "PX2RenderStep.hpp"

namespace PX2
{

	typedef Object *(*ObjectLoadFun) (const char *filename);

	class Renderer;
	class VisibleSet;

	class GraphicsRoot : public Singleton<GraphicsRoot>
	{
	public:
		GraphicsRoot ();
		~GraphicsRoot ();

		bool Initlize ();
		bool Terminate ();
		
		void SetInEditor (bool isInEditor);
		bool IsInEditor () const;

		void SetCamera (Camera *camera);
		PX2::Camera *GetCamera();

		// Size Rect
		void SetSize (const Sizef &size);	// screen size
		const Sizef &GetSize () const;		
		void SetRect (const Rectf &rect);	// view rect
		const Rectf &GetRect () const;
		void SetRenderViewPort (Renderer *renderer, bool adjustCamera,
			const Sizef *projSize=0, const Rectf *sceneViewPort=0);

		// Light
		void AddLight (Light *light);
		void RemoveLight (Light *light);
		void ClearAllLights ();
		int GetNumLights ();
		Light *GetLight (int index);

		// Fog
		void SetFogParam (const Float4 &param);
		const Float4 &GetFogParam () const;
		void SetFogColor (const Float4 &fogColor);
		const Float4 &GetFogColor () const;
		void SetFogColorDist (const Float4 &fogColor);
		const Float4 &GetFogColorDist () const;

		// environment
		void ComputeEnvironment (VisibleSet &vs);

		const static std::string sEmptyResPath;
		const static std::string sTerResPath;

	private:
		bool mIsInEditor;
		Rectf mRect;
		Sizef mSize;
		PX2::CameraPtr mCamera;
		std::vector<LightPtr> mAllLights; // 保存放在场景中的所有灯光
		static std::string PX2Path;
		Float4 mFogParam;
		Float4 mFogColor;
		Float4 mFogColorDist;

		// RenderStep;
	public:
		bool AddRenderStep(RenderStep *step);
		bool IsHasRenderStep(RenderStep *step) const;
		bool RemoveRenderStep(RenderStep *step);

		void ComputeVisibleSet();
		void Draw();

	protected:
		std::vector<RenderStepPtr> mRenderSteps;

		// VertexFormat
	public:
		enum VertexFormatType
		{
			VFT_PT1,
			VFT_PT2,
			VFT_MAX_TYPE
		};

		VertexFormat *GetVertexFormat(VertexFormatType type);

	protected:
		std::map<VertexFormatType, VertexFormatPtr > mCreatedVFs;

		// Load
	public:
		static void SetUserLoadFun(ObjectLoadFun userLoadFun);
		static ObjectLoadFun msUserLoadFun;
	};

#include "PX2GraphicsRoot.inl"

#define PX2_GR GraphicsRoot::GetSingleton()

}

#endif