/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Visitor.hpp
*
*/

#ifndef PX2VISITOR_HPP
#define PX2VISITOR_HPP

#include "PX2CorePre.hpp"

namespace PX2
{

	class Object;
	class Any;

	class Vistor
	{
	public:
		Vistor ();
		virtual ~Vistor ();

		virtual void Visit (Object *obj, const int info);
		virtual void Visit (Object *obj, const std::string &info);
		virtual void Visit (Object *obj, const Any &info);
	};

#define  PX2_VISITOR \
public: \
	void AddVistor (Vistor *vistor) \
	{ \
		for (int i=0; i<(int)mVistors.size(); i++) \
		{ \
			if (vistor == mVistors[i]) \
				return; \
		} \
		mVistors.push_back(vistor); \
	} \
	\
protected: \
	std::vector<Vistor *> mVistors;
}

#endif