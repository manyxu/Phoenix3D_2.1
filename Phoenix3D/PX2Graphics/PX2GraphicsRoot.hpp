// PX2GraphicsRoot.hpp

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
	class TriMesh;

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
		void SetScreenSize (const Sizef &size);	// screen size
		const Sizef &GetScreenSize () const;		
		void SetViewRect (const Rectf &rect);	// view rect
		const Rectf &GetViewRect () const;

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
		Rectf mViewRect;
		Sizef mScreenSize;
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

		void Update(double appSeconds, double elapsedSeconds);
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
			VFT_PC,
			VFT_MAX_TYPE
		};

		VertexFormat *GetVertexFormat(VertexFormatType type);

	protected:
		std::map<VertexFormatType, VertexFormatPtr > mCreatedVFs;

		// HelpMesh
	public:
		TriMesh *GetXYPlane();
		TriMesh *GetXZPlane();
		TriMesh *GetYZPlane();

	protected:
		Pointer0<TriMesh> mTriMeshXY;
		Pointer0<TriMesh> mTriMeshXZ;
		Pointer0<TriMesh> mTriMeshYZ;

		// Load
	public:
		static void SetUserLoadFun(ObjectLoadFun userLoadFun);
		static ObjectLoadFun msUserLoadFun;
	};

#include "PX2GraphicsRoot.inl"

#define PX2_GR GraphicsRoot::GetSingleton()

}

#endif