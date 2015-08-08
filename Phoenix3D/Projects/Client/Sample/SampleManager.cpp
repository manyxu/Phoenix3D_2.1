// SampleManager.cpp

#include "SampleManager.hpp"
#include "SamplePre.hpp"
#include "SampleCharacter.hpp"
#include "PX2EventWorld.hpp"
#include "PX2StringHelp.hpp"
#include "PX2Project.hpp"
#include "PX2ResourceManager.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
SampleManager::SampleManager()
{
}
//----------------------------------------------------------------------------
SampleManager::~SampleManager()
{
}
//----------------------------------------------------------------------------
void SampleManager::Initlize()
{
	PX2_EW.ComeIn(this);

	OnEnterMap(1);
}
//----------------------------------------------------------------------------
void SampleManager::Ternamate()
{
	PX2_EW.GoOut(this);

	PX2_PROJ.SetScene(0);
}
//----------------------------------------------------------------------------
void SampleManager::DoExecute(Event *event)
{
	PX2_UNUSED(event);
}
//----------------------------------------------------------------------------
void SampleManager::OnEnterMap(int id)
{
	std::string sceneName = PDP + "scenes/scene" + 
		StringHelp::IntToString(id) + ".px2obj";

	if (PX2_PROJ.LoadScene(sceneName))
	{
		Scene *scene = PX2_PROJ.GetScene();
		scene->GetDefaultAmbientRegionActor()->SetFogParamDistance(Float2(1000.0f, 2000.0f));
		scene->GetDefaultAmbientRegionActor()->SetFogParamHeight(Float2(-500.0f, -100.0f));

		// playground
		ActorPtr pgActor = new0 Actor();
		Node *pgNode = pgActor;
		scene->AttachChild(pgActor);
		pgActor->SetName("PG");

		Texture2D *tex = DynamicCast<Texture2D>(PX2_RM.BlockLoad(
			"Data/Sample/images/background.png"));

		VertexFormat *vf = PX2_GR.GetVertexFormat(GraphicsRoot::VFT_PNT1);

		StandardMesh stdMesh(vf);
		TriMesh *mesh = stdMesh.Rectangle(2, 2, 916.0f/2.0f, 546.0f/2.0f, Float2(0.5f, 0.5f));
		mesh->SetName("NoName");

		MaterialInstance *mi = new0 MaterialInstance(
			"Data/engine_mtls/std/std.px2obj", "std_light", false);
		mesh->SetMaterialInstance(mi);

		mi->SetPixelTexture(0, "SampleBase", tex);

		pgActor->SetMovable(mesh);
		pgActor->LocalTransform.SetTranslate(916.0f / 2.0f, 546.0f / 2.0f, -10.0f);

		// camera
		CameraActor *cameraActor = scene->GetUseCameraActor();
		cameraActor->LocalTransform.SetTranslate(916.0f / 2.0f, 546.0f / 2.0f, 200.0f);
		cameraActor->LocalTransform.SetRotate(-90.0f*Mathf::DEG_TO_RAD, 0.0f, 0.0f);
		cameraActor->GetCamera()->SetPerspective(false);
		cameraActor->GetCamera()->SetFrustum(0.0f, 1000.0f, 
			-546.0f / 2.0f, 546.0f / 2.0f, -916.0f / 2.0f, 916.0f / 2.0f);

		// soccerchara
		SampleCharaPtr chara = new SampleChara();
		scene->AttachChild(chara);
		chara->LocalTransform.SetTranslateXY(916.0f / 2.0f, 546.0f / 2.0f);
		chara->LocalTransform.SetUniformScale(1.0f);
		chara->GetNodeHelp()->LocalTransform.SetUniformScale(10.0f);
	}
}
//----------------------------------------------------------------------------