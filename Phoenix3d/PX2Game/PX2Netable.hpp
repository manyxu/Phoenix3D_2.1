/*
*
* 文件名称	：	PX2Netable.hpp
*
*/

#ifndef PX2NETABLE_HPP
#define PX2NETABLE_HPP

#include "PX2GamePre.hpp"
#include "PX2Controlledable.hpp"
#include "PX2EventHandler.hpp"

namespace PX2
{
	class Netable;

	/**
	* 该类为Netable的辅助类，作为Netable的成员。用来支持派生对象的消息功能。通
	* 常不要是使用该类。
	*
	* DoEnter，DoExecute，DoLeave内部调用Netable的相应函数。
	* 该类不负责Netable内存的管理。
	*/
	class NetableEventHandler : public EventHandler
	{
	public:
		NetableEventHandler (Netable *netable);
		virtual ~NetableEventHandler ();

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	protected:
		NetableEventHandler ();

		Netable *mNetable;
	};
	
	typedef Pointer0<NetableEventHandler> NetableEventHandlerPtr;

	/**
	* 派生于此类的对象，具备消息的功能。
	*/
	class Netable : public Controlledable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(Netable);

	public:
		Netable ();
		virtual ~Netable ();

		EventHandler *GetEventHandler ();

		void ComeInToEventWorld ();
		void GoOutFromEventWorld ();
		bool IsInEventWorld ();

		// event
		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

	protected:
		NetableEventHandlerPtr mNetableEventHandler;
	};

	PX2_REGISTER_STREAM(Netable);
	typedef Pointer0<Netable> NetablePtr;
#include "PX2Netable.inl"

}

#endif