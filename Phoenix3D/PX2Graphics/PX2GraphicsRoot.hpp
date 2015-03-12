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
#include "PX2FString.hpp"
#include "PX2Projector.hpp"

namespace PX2
{

	typedef Object *(*ObjectLoadFun) (const char *filename);
	typedef bool (*BufferLoadFun)(const char *filename, int &bufferSize,
		char* &buffer);

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

		// Size Rect
		void SetScreenSize (const Sizef &size);	// screen size
		const Sizef &GetScreenSize () const;		
		void SetViewRect (const Rectf &rect);	// view rect
		const Rectf &GetViewRect () const;

		void SetProjectSize(const Sizef &size);
		const Sizef &GetProjectSize() const;

		// DirLight
		Light *GetLight_Dir();
		Projector *GetLight_Dir_Projector();
		void SetLight_Dir_DepthTexture(Texture *tex);
		Texture *GetLight_Dir_DepthTexture();

		// PointLight
		void AddLight (Light *light);
		void RemoveLight (Light *light);
		void ClearAllLights ();
		int GetNumLights ();
		Light *GetLight (int index);

		// environment
		void ComputeEnvironment (VisibleSet &vs);

		const static std::string sEmptyResPath;
		const static std::string sTerResPath;

	private:
		bool mIsInEditor;
		Rectf mViewRect;
		Sizef mScreenSize;
		Sizef mProjectSize;
		PX2::CameraPtr mCamera;
		std::vector<LightPtr> mAllLights; // 保存放在场景中的所有灯光
		LightPtr mLight_Dir;
		ProjectorPtr mLight_Dir_Projector;
		TexturePtr mLight_Dir_DepthTexture;

		// Fog
	public:
		void SetFogParam(const Float4 &param);
		const Float4 &GetFogParam() const;
		void SetFogColorHeight(const Float4 &fogColor);
		const Float4 &GetFogColorHeight() const;
		void SetFogColorDist(const Float4 &fogColor);
		const Float4 &GetFogColorDist() const;

	protected:
		Float4 mFogParam;
		Float4 mFogColorDist;
		Float4 mFogColorHeight;

		// RenderStep;
	public:
		bool AddRenderStep(const char *name, RenderStep *step);
		bool IsHasRenderStep(const char *name) const;
		bool RemoveRenderStep(const char *name);
		void RemoveRenderSteps(RenderStep *step);
		RenderStep *GetRenderStep(const char *name);
		RenderStep *GetRenderStepScene();
		RenderStep *GetRenderStepUI();

		void Update(double appSeconds, double elapsedSeconds);
		void ComputeVisibleSet();
		void Draw();

	protected:
		RenderStepPtr mRenderStepScene;
		RenderStepPtr mRenderStepUI;
		std::map<FString, RenderStepPtr> mRenderStepMap;
		std::vector<RenderStep *> mRenderStepVec;

		// VertexFormat
	public:
		enum VertexFormatType
		{
			VFT_PT1,
			VFT_PT2,
			VFT_PC,
			VFT_PCT1,
			VFT_PCT2,
			VFT_PNT1,
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

		static void SetBufferLoadFun(BufferLoadFun bufferLoadFun);
		static BufferLoadFun msBufferLoadFun;

	public:
		const std::string *GetShaderStr(const char *filename);
	
	protected:
		std::map<FString, std::string> mShadersMap;
	};

#include "PX2GraphicsRoot.inl"

#define PX2_GR GraphicsRoot::GetSingleton()

}

#endif