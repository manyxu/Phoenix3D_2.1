/*
*
* ÎÄ¼þÃû³Æ	£º	PX2MultiTouch.hpp
*
*/

#ifndef PX2MULTITOUCH_HPP
#define PX2MULTITOUCH_HPP

#include "PX2InputObject.hpp"
#include "PX2InputDataTypes.hpp"

namespace PX2
{

	enum MultiTouchEventType
	{
		MTET_NONE = 0,
		MTET_PRESSED,
		MTET_MOVED,
		MTET_RELEASED,
		MTET_CANCELLED,
		MTET_MAX_TYPE
	};

	class MultiTouchState
	{
	public:
		MultiTouchState ();

		bool HasTouchType (MultiTouchEventType touch) const;
		void Clear ();

		int ID;
		Axis X;
		Axis Y;
		Axis Z;
		int TouchTypes;
	};

	class MultiTouchEvent : public EventArg
	{
	public:
		MultiTouchEvent (InputObject *obj, const MultiTouchState &mts);
		virtual ~MultiTouchEvent ();

		const MultiTouchState &State;
	};

	class MultiTouchListener
	{
	public:
		virtual ~MultiTouchListener ();
		virtual bool TouchMoved (const MultiTouchEvent &arg) = 0;
		virtual bool TouchPressed (const MultiTouchEvent &arg) = 0;
		virtual bool TouchReleased (const MultiTouchEvent &arg) = 0;
		virtual bool TouchCancelled (const MultiTouchEvent &arg) = 0;
	};

	class MultiTouch : public InputObject
	{
	public:
		virtual ~MultiTouch ();

		virtual void SetEventCallback (MultiTouchListener *touchListener);
		MultiTouchListener *GetEventCallback ();

		void ClearStates ();
		std::vector<MultiTouchState> GetMultiTouchStates () const;
		const std::vector<MultiTouchState> GetFirstNumTouchStates (int num);
		const std::vector<MultiTouchState> GetMultiTouchStatesOfType (
			MultiTouchEventType type);

	protected:
		MultiTouch (const std::string &vendor, bool buffered, int devID,
			InputManager *creator);

		std::vector<MultiTouchState> mStates;
		MultiTouchListener *mListener;
	};

#include "PX2MultiTouch.inl"

}

#endif