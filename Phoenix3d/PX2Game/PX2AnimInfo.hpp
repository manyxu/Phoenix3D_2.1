/*
*
* ÎÄ¼þÃû³Æ	£º	PX2AnimInfo.hpp
*
*/

#ifndef PX2ANIMINFO_HPP
#define PX2ANIMINFO_HPP

#include "PX2GamePre.hpp"
#include "PX2Object.hpp"

namespace PX2
{

	class AnimInfo
	{
	public:
		AnimInfo ();
		~AnimInfo ();

		std::string AnimName;
		float AnimTime;
		int AnimRepeats;
		std::string AnimFilename;
		ObjectPtr mAnim;
	};

}

#endif