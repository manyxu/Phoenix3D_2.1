/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputDataTypes.hpp
*
*/

#ifndef PX2INPUTDATATYPES_HPP
#define PX2INPUTDATATYPES_HPP

#include "PX2InputPre.hpp"

namespace PX2
{

	typedef std::multimap<std::string, std::string> ParamList;

	enum ComponentType
	{
		CT_UNKNOWN,
		CT_BUTTON,
		CT_AXIS,
		CT_SLIDER,
		CT_POV,
		CT_XYZVECTOR,
		CT_MAX_TYPE,
	};

	class Component
	{
	public:
		Component ();
		Component (ComponentType type);

		ComponentType Type;
	};

	class Button : public Component
	{
	public:
		Button ();
		Button (bool pushed);

		bool Pushed;
	};

	class Axis : public Component
	{
	public:
		Axis();

		void Clear ();

		int Absoulate;
		int Relative;
		bool IsAbsoulateOnly;
	};

	class XYZVector : public Component
	{
	public:
		XYZVector ();
		XYZVector (float x, float y, float z);

		void Clear ();

		float X;		
		float Y;
		float Z;
	};

}

#endif