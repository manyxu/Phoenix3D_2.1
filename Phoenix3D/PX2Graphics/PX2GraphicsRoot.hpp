// PX2GraphicsRoot.hpp

#ifndef PX2GRAPHICSROOT_HPP
#define PX2GRAPHICSROOT_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Size.hpp"
#include "PX2Camera.hpp"
#include "PX2Light.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Rect.hpp"
#include "PX2EnvirParam.hpp"
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

		const static std::string sEmptyResPath;
		const static std::string sTerResPath;

	private:
		bool mIsInEditor;
		Rectf mViewRect;
		Sizef mScreenSize;
		Sizef mProjectSize;

		// Environment
	public:
		// 环境参数是用来保存当前要渲染的3D物件，所收到的光照，雾的信息。
		// 每一个Scene中都会与一个环境参数，在加载Scene的时候设置该Scene的环境
		// 参数到当前。
		// 有一种情况你需要同时渲染两个场景，比如在编辑器中，的主场景和，
		// PreView场景，你想需要他们有不同环境感觉，需要在加载和渲染该物体的之
		// 前设置一下当前环境参数。在渲染完成之后，再置回原来的参数。
		void SetCurEnvirParam(EnvirParam *param);
		EnvirParam *GetCurEnvirParam();

	protected:
		EnvirParamPtr mCurEnvirParam;

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
		void ComputeVisibleSetAndEnv();
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