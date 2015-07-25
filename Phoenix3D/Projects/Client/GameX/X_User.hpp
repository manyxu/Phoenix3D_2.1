// X_User.hpp

#ifndef X_USER_HPP
#define X_USER_HPP

#include "PX2User.hpp"
#include "PX2Singleton1.hpp"
#include "X_UserActor.hpp"

namespace PX2
{

	class X_UserActor;

	class X_User : public User
	{
	public:
		X_User();
		virtual ~X_User();

		virtual void Update(float appTime, float elapsedTime);

		void SetPlayUserActor(int index);
		X_UserActor *GetPlayUserActor();

	protected:
		X_UserActorPtr mPlayUserActor;
	};

#include "X_User.inl"
	typedef Pointer0<X_User> X_UserPtr;

}

#endif