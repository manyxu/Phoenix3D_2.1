// PX2SelectResData.hpp

#ifndef PX2SELECTRESDATA_HPP
#define PX2SELECTRESDATA_HPP

#include "PX2EditPre.hpp"
#include "PX2Object.hpp"
#include "PX2Size.hpp"

namespace PX2
{

	class SelectResData
	{
	public:
		enum SelectResType
		{
			RT_NORMAL,
			RT_TEXPACKELEMENT,
			RT_MAX_TYPE
		};
		SelectResData(SelectResType type = RT_NORMAL);
		~SelectResData();

		SelectResType GetSelectResType() const;

		std::string ResPathname;
		PX2::ObjectPtr TheObject;
		std::string EleName; // 如果是RT_TEXPACKELE,这个成员有效

		Sizef GetTheObjectTexSize() const;

	private:
		SelectResType mSelectResType;
	};

}

#endif