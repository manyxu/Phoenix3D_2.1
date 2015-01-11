/*
*
* ÎÄ¼þÃû³Æ	£º	PX2InputEventHandler.hpp
*
*/

#ifndef PX2INPUTEVENTHANDLER_HPP
#define PX2INPUTEVENTHANDLER_HPP

#include "PX2InputEvent.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2InputRanges.hpp"

namespace PX2
{

	class InputEventHandler
	{
	public:
		InputEventHandler ();
		virtual ~InputEventHandler ();

		void SetPriority (int priority);
		int GetPriority () const;

		void SetSigned (bool sign);
		bool IsSigned () const;
		void SetSignIgnoreOtherHandlers (bool doIngore);
		bool IsSignIgnoreOtherHandlers () const;

		void AddAcceptRange (const Rectf &ar);
		bool HasAcceptRange (const Rectf &ar);
		void RemoveAcceptRange (const Rectf &ar);
		void ClearAcceptRanges ();

		void AddExceptRange (const Rectf &er);
		bool HasExceptRange (const Rectf &er);
		void RemoveExceptRange (const Rectf &er);
		void ClearExceptRanges ();

		virtual bool TouchMoved (const InputEventData &data);
		virtual bool TouchPressed (const InputEventData &data);
		virtual bool TouchReleased (const InputEventData &data);
		virtual bool TouchCancelled (const InputEventData &data);

	protected:
		bool IsValuable (const InputEventData &data);

		int mPriority;
		InputRange mInputRange;
		bool mIsSigned;
		bool mIsSignIgnoreOtherHandlers;
	};

}

#endif