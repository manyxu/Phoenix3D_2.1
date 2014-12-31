// PX2Project.hpp

#ifndef PX2PROJECT_HPP
#define PX2PROJECT_HPP

#include "PX2SimulationPre.hpp"
#include "PX2Node.hpp"
#include "PX2Scene.hpp"
#include "PX2Size.hpp"

namespace PX2
{

	class Project : public Node
	{
	public:
		Project ();
		~Project ();

		// Config
	public:
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef & GetSize() const;
		float GetWidth() const;
		float GetHeight() const;

	protected:
		Sizef mSize;

		// Scene
	public:
		void SetSceneFilename(const std::string &scenefilename);
		const std::string &GetSceneFilename () const;
		Scene *GetScene();

	protected:
		std::string mSceneFilename;
		ScenePtr mScene;

		// UI
	public:
		void SetUIFramename(const std::string &filename);
		const std::string &GetUIFilename () const;

	protected:
		std::string mUIFilename;

		// Language
	public:
		void SetLanguage0(const std::string &filename);
		const std::string &GetLanguage0 () const;
		void SetLanguage1(const std::string &filename);
		const std::string &GetLanguage1() const;
		
	protected:
		std::string mLanguagePath0;
		std::string mLanguagePath1;
	};

#include "PX2Project.inl"

}

#endif