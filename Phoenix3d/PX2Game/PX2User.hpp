/*
*
* ÎÄ¼þÃû³Æ	£º	PX2User.hpp
*
*/

#ifndef PX2USER_HPP
#define PX2USER_HPP

#include "PX2GamePre.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2UserActor.hpp"
#include "PX2Singleton1.hpp"

namespace PX2
{

	class User
	{
	public:
		User ();
		virtual ~User ();

		virtual void Update (float appTime, float elapsedTime);

		void SetName (const std::string name);
		const std::string &GetName () const;

		void SetUserName (const std::string &useName);
		const std::string &GetUserName () const;

		void AddUserActor (UserActor *userActor);
		void DeleteUserActor (UserActor *userActor);
		UserActor *GetUserActor (int index) const;
		UserActor *GetUserActorByName (const std::string &useName) const;
		int GetNumUserActors () const;

	protected:
		std::string mName;
		std::string mUserName;
		std::vector<UserActorPtr> mUserActors;
	};

#include "PX2User.inl"
	typedef Pointer0<User> UserPtr;

}

#endif