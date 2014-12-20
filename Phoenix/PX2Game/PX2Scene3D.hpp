/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Scene3D.hpp
*/

#ifndef PX2SCENE3D_HPP
#define PX2SCENE3D_HPP

#include "PX2Scene.hpp"
#include "PX2TerrainActor.hpp"
#include "PX2CameraActor.hpp"
#include "PX2AmbientRegionActor.hpp"

namespace PX2
{

	class Scene3D : public Scene
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Scene3D);

	public:
		Scene3D ();
		virtual ~Scene3D ();

		virtual void Update (double appSeconds, double elapsedSeconds);

		void OnAddedActor (Actor *actor);

		void ShowHelpMovables (bool show);

		TerrainActor *GetTerrainActor ();
		AmbientRegionActor *GetDefaultARActor ();

		// SceneBake
		enum BakeSizeType
		{
			BST_NORMAL,
			BST_NORMALOVER2,
			BST_NORMALOVER4,
			BST_MAX_TYPE
		};
		void SetBakeSizeType (BakeSizeType type);
		BakeSizeType GetBakeSizeType () const;

		void SetUseLightTexture (bool use);
		bool IsUseLightTexture () const;

	protected:
		TerrainActorPtr mTerrainActor;
		PX2::AmbientRigionActorPtr mDefaultARActor;
		BakeSizeType mBakeSizeType;
		bool mIsUseLightTexture;
	};

	PX2_REGISTER_STREAM(Scene3D);
	typedef Pointer0<Scene3D> Scene3DPtr;

#include "PX2Scene3D.inl"

}

#endif