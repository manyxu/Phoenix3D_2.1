// PX2Improter.hpp

#ifndef PX2IMPORTER_HPP
#define PX2IMPORTER_HPP

#include "PX2Movable.hpp"
#include "PX2UnityPre.hpp"

namespace PX2
{

	class PX2_UNITY_ITEM Importer
	{
	public:
		Importer();
		virtual ~Importer();

		Movable *GetFrom(const std::string &filename);
	};

}

#endif