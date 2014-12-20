/*
*
* 文件名称	：	PX2GameObject.hpp
*
*/

#ifndef PX2GAMEOBJECT_HPP
#define PX2GAMEOBJECT_HPP

#include "PX2GamePre.hpp"
#include "PX2Netable.hpp"
#include "PX2XMLNode.hpp"
#include "PX2LogicModule.hpp"

namespace PX2
{

	class Gameable : public Netable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Gameable);

	public:
		Gameable ();
		virtual ~Gameable ();

		void Enable (bool enable);
		bool IsEnable () const;

		void SetServerID (int serverID);
		int GetServerID () const;

		virtual void Initlize ();

		// Scripts
		void SetScriptHandler_Init (const std::string &handler);
		const std::string &GetScriptHandler_Init () const;

		// 用户自己设置的名称,如果设置了
		// GetScriptName 和 GetUserScriptName是一样的
		void SetUserScriptName(const std::string &scriptName);
		const std::string &GetUserScriptName () const;
		const std::string &GetScriptName () const;

		bool RegistToScriptSystem ();
		bool UnRegistToScriptSystem ();
		bool IsRegistedToScriptSystem ();

		void CallString (const char *fun, const char *format="", ...);

	protected:
		XMLNode GetXMLNodeAtClassLayer (XMLNode node, 
			const std::string &classLayer);

		bool mIsEnable;
		int mServerID;
		std::string mScriptHandler_Init;
		std::string mScriptName;
		std::string mUserScriptName;
	};

	PX2_REGISTER_STREAM(Gameable);
	typedef Pointer0<Gameable> GameablePtr;
#include "PX2Gameable.inl"

}

#endif