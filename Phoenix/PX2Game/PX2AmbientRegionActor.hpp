/*
*
* 文件名称	：	PX2AmbientRegionActor.hpp
*
*/

#ifndef PX2AMBIENTACTOR_HPP
#define PX2AMBIENTACTOR_HPP

#include "PX2TriggerActor.hpp"
#include "PX2Light.hpp"

namespace PX2
{

	class AmbientRegionActor : public TriggerActor
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(AmbientRegionActor);

	public:
		AmbientRegionActor ();
		virtual ~AmbientRegionActor ();

		virtual void Update(double appSeconds, double elapsedSeconds);

		// bake
		void EnableBakeGI (bool enableGI);
		bool IsEnableBakeGI () const;

		void SetGISkyLightColor (const Float3 &color);
		const Float3 &GetGISkyLightColor () const;
		
		void SetAmbientColor_Bake (const Float3 &color);
		const Float3 &GetAmbientColor_Bake () const;
		void SetDiffColor_Bake (const Float3 &color);
		const Float3 &GetDiffColor_Bake () const;		
		void SetSpecColor_Bake (const Float3 &color);
		const Float3 &GetSpecColor_Bake () const;	

		void SetAmbientScale_Bake (float scale);
		void SetDiffuseScale_Bake (float scale);
		void SetSpecularScale_Bake (float scale);
		float GetAmbientScale_Bake () const;
		float GetDiffuseScale_Bake () const;
		float GetSpecularScale_Bake () const;

		void SetBakeShadowAngle (float shadowAnge);
		float GetBakeShadowAngle () const;

		// real time lighting
		void SetAmbientColor (const Float3 &color);
		const Float3 &GetAmbientColor () const;
		void SetLightDiffColor (const Float3 &color);
		const Float3 &GetLightDiffColor () const;		
		void SetLightSpecColor (const Float3 &color);
		const Float3 &GetLightSpecColor () const;
		void SetLightSpecPow (float pow);
		float GetLightSpecPow () const;

		void SetLightIntensity (float intensity);
		float GetLightIntensity () const;
		
		// 方向
		void SetHorAngle (float angle);
		float GetHorAngle () const;
		
		void SetVerAngle (float angle);
		float GetVerAngle () const;
		
		const Light *GetLight () const;
		Light *GetLight ();

		virtual void CalLights ();

		virtual void DoEnter ();
		virtual void DoExecute (Event *event);
		virtual void DoLeave ();

public_internal:
		virtual void SetScene (Scene *scene);

	protected:
		bool mIsEnableGI;

		Float3 mAmbientColor_Bake;
		Float3 mDiffColor_Bake;
		Float3 mSpecColor_Bake;
		float mLightIntensity;
		float mHorAngle; // (0-360)
		float mVerAngle; // (0-90)

		LightPtr mLight;

		float mBakeShadowAngle;
		Float2 mFogParam;
		Float3 mFogColor;
		Float3 mBakeSkyLightColor;

		float mAmbientScale_Bake;
		float mDiffuseScale_Bake;
		float mSpecularScale_Bake;

		Float2 mFogParam1;

		Float3 mAmbientColor;
		Float3 mDirLightDiffColor;
		Float3 mLightSpecColor;
		float mLightSpecPow;
	};

	PX2_REGISTER_STREAM(AmbientRegionActor);
	typedef Pointer0<AmbientRegionActor> AmbientRigionActorPtr;
#include "PX2AmbientRegionActor.inl"

}

#endif