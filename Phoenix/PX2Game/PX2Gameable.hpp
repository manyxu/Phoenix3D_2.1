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

		void SetExtraDataInt (const std::string &name, int data);
		int GetExtraDataInt (const std::string &name) const;
		void SetExtraDataFloat (const std::string &name, float data);
		float GetExtraDataFloat (const std::string &name) const;

		// init
		void SetScriptHandler_Init (const std::string &handler);
		const std::string &GetScriptHandler_Init () const;

		virtual void Initlize ();

		// serialize
		bool SaveToXML (const std::string &filename);
		bool LoadFromXML (const std::string &filename);
		bool LoadFromXML (const std::string &filename, 
			const std::string &classLayer);

		// Scripts
		
		// 用户自己设置的名称,如果设置了
		// GetScriptName 和 GetUserScriptName是一样的
		void SetUserScriptName(const std::string &scriptName);
		const std::string &GetUserScriptName () const;
		const std::string &GetScriptName () const;

		bool RegistToScriptSystem ();
		bool UnRegistToScriptSystem ();
		bool IsRegistedToScriptSystem ();

		void CallString (const char *fun, const char *format="", ...);

	public_internal:
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);

	protected:
		XMLNode GetXMLNodeAtClassLayer (XMLNode node, 
			const std::string &classLayer);

		bool mIsEnable;

		int mServerID;
		std::map<std::string, int> mExtraDataInts;
		std::map<std::string, float> mExtraDataFloats;
		std::string mScriptHandler_Init;
		std::string mScriptName;
		std::string mUserScriptName;
	};

	PX2_REGISTER_STREAM(Gameable);
	typedef Pointer0<Gameable> GameablePtr;
#include "PX2Gameable.inl"

}

#endif