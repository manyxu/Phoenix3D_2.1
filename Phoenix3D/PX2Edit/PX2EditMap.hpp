// PX2EditMap.hpp

#ifndef PX2EDITMAP_HPP
#define PX2EDITMAP_HPP

#include "PX2EditPre.hpp"

namespace PX2
{

	class EditMap
	{
	public:
		EditMap();
		~EditMap();

		// project scene
	public:
		void NewProject(const std::string &pathname, 
			const std::string &projName, int width, int height);
		bool LoadProject(const char *pathname);
		bool SaveProject();
		bool SaveProjectAs(const char *pathname);
		void CloseProject();
		std::string GetProjectFilePath() { return mProjectFilePath; }

		void NewScene();
		bool LoadScene(const std::string &pathname);
		bool SaveScene(const std::string &pathname);
		bool SaveSceneAs(const std::string &pathname);
		void CloseScene();

		bool LoadUI(const std::string &pathname);
		void CloseUI();

	protected:
		std::string _CalSavePath(const std::string &pathname);
		bool _SaveSceneInternal(const std::string &pathname);

		std::string mProjectFilePath;
	};

}


#endif