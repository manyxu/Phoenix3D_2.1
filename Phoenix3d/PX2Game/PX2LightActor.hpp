/*
*
* ÎÄ¼þÃû³Æ	£º	PX2LightActor.hpp
*
*/

#ifndef PX2LIGHTACTOR_HPP
#define PX2LIGHTACTOR_HPP

#include "PX2Actor.hpp"
#include "PX2Light.hpp"
#include "PX2LightNode.hpp"

namespace PX2
{

	class LightActor : public Actor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(LightActor);

	public:
		LightActor ();
		virtual ~LightActor ();

		Light *GetLight ();

		enum LightType
		{
			LT_POINT,
			LT_SPOT,
			LT_MAX_TYPE
		};
		void SetLightType (LightType type);
		LightType GetLightType () const;

		void SetColor (const Float3 &color);
		const Float3 &GetColor () const;

		void SetRange (float range);
		float GetRange () const;

		virtual void Update (double appSeconds, double elapsedSeconds);

public_internal:
		virtual void SetScene (Scene *scene);

	protected:
		LightPtr mLight;
		LightType mLightType;
		Float3 mColor;
		float mRange;
	};

	PX2_REGISTER_STREAM(LightActor);
	typedef Pointer0<LightActor> LightActorPtr;
#include "PX2LightActor.inl"

}

#endif