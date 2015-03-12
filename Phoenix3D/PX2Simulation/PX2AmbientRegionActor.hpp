// PX2AmbientRegionActor.hpp

#ifndef PX2AMBIENTREGIONACTOR_HPP
#define PX2AMBIENTREGIONACTOR_HPP

#include "PX2TriggerActor.hpp"

namespace PX2
{

	class AmbientRegionActor : public TriggerActor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(AmbientRegionActor);

	public:
		AmbientRegionActor();
		virtual ~AmbientRegionActor();

		// Default Dir Light
	public:
		void SetHorAngle(float angle);
		float GetHorAngle() const;
		void SetVerAngle(float angle);
		float GetVerAngle() const;

		void SetAmbientColor(const Float3 &color);
		const Float3 &GetAmbientColor() const;

		void SetDiffuseColor(const Float3 &color);
		const Float3 &GetDiffuseColor() const;

		void SetSpecularColor(const Float3 &color);
		const Float3 &GetSpecularColor() const;
		void SetSpecularPow(float pow);
		float GetSpecularPow() const;

	protected:
		void _UpdateDirLight();

		float mHorAngle;
		float mVerAngle;

		Float3 mAmbientColor;
		Float3 mDiffuseColor;
		Float3 mSpecularColor;
		float mSpecularPow;

		// Bake
	public:
	protected:
	};

#include "PX2AmbientRegionActor.inl"
	PX2_REGISTER_STREAM(AmbientRegionActor);
	typedef Pointer0<AmbientRegionActor> AmbientRegionActorPtr;

}

#endif