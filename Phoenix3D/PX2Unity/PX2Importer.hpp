// PX2Improter.hpp

#ifndef PX2IMPORTER_HPP
#define PX2IMPORTER_HPP

#include "PX2Movable.hpp"

namespace PX2
{

	class Importer
	{
	public:
		Importer();
		virtual ~Importer();

		Movable *GetFrom(const std::string &filename);
	};

}

#endif