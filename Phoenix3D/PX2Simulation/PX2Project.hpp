// PX2Project.hpp

#ifndef PX2PROJECT_HPP
#define PX2PROJECT_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2Node.hpp"
#include "PX2Scene.hpp"
#include "PX2Size.hpp"
#include "PX2Float4.hpp"
#include "PX2RenderStep.hpp"

namespace PX2
{

	class Project : public Node, public Singleton<Project>
	{
	public:
		Project ();
		~Project ();

		// 使用该接口删除Project
		static void Destory();

	private:
		static Pointer0<Project> msProject;

		// Load Save
	public:
		bool Save(const std::string &filename); //< only used in editor
		bool SaveConfig(const std::string &filename); //< only used in editor	
		bool Load(const std::string &filename);

		// Config
	public:
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef & GetSize() const;
		float GetWidth() const;
		float GetHeight() const;

		void SetBackgroundColor(const Float4 &color);
		const Float4 &GetBackgroundColor() const;

	protected:
		Sizef mSize;
		Float4 mBackgroundColor;

		// Scene
	public:
		void SetScene(Scene *scene);
		Scene *GetScene();
		const std::string &GetSceneFilename() const;
		RenderStep *GetSceneRenderStep();

	public_internal:
		void SetSceneFilename(const std::string &scenefilename);

	protected:
		std::string mSceneFilename;
		ScenePtr mScene;
		RenderStepPtr mSceneRenderStep;

		// UI
	public:
		void SetUIFramename(const std::string &filename);
		const std::string &GetUIFilename () const;

	protected:
		std::string mUIFilename;
	};

#define PX2_PROJ Project::GetSingleton()
#include "PX2Project.inl"

}

#endif