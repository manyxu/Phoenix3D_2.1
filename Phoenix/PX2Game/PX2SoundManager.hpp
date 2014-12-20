/*
*
* ÎÄ¼þÃû³Æ	£º	PX2GameSoundManager.hpp
*
*/

#ifndef PX2GAMESOUNDMANAGER_HPP
#define PX2GAMESOUNDMANAGER_HPP

#include "PX2GamePre.hpp"
#include "PX2Singleton.hpp"
#include "PX2Sound.hpp"

namespace PX2
{

	class SoundManager : public Singleton<SoundManager>
	{
	public:
		SoundManager ();
		~SoundManager();

		void ClearPreLoadSoundFiles ();
		void AddPreLoadSound (const std::string &filename);
		void PreLoad ();

		void Clear ();
		void Update (double appSeconds, double elapsedSeconds);

		void PlaySound (const std::string &name,
			const std::string &filename, float volume, bool isLoop=false);
		void StopSound (const std::string &name, float disTime=0.0f);
		void PlayASound (const std::string &filename, float volume, float deleteTime=5.0f);

	protected:
		class SoundCtrlObj
		{
		public:
			SoundCtrlObj ();
			~SoundCtrlObj ();

			std::string SoundName;
			std::string SoundFilename;
			float InitVolume;
			float CurVolume;
			SoundPtr TheSound;

			bool IsDoingStop;
			float StopDelayTime;
			float DisTime;
			float DisSpeed;

			float DeleteTime;
		};
		typedef Pointer0<SoundCtrlObj> SoundCtrlObjPtr;

		std::map<std::string, SoundCtrlObjPtr> mSoundMap;
		std::vector<SoundCtrlObjPtr> mASoundArray;

		std::vector<std::string> mPreLoadSoundFiles;
	};

#define PX2_SOUNDM SoundManager::GetSingleton()

}

#endif