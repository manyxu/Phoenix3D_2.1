-- start.lua
-- this is the place where logic start

function Start()
	local scene = PX2_PROJ:GetScene()
	if nil==scene then
		return
	end
	
	local cameraActor = scene:GetUseCameraActor()
	
	local sphereActor = PX2_CREATER:CreateActor_Box(scene, APoint.ORIGIN)
	sphereActor.LocalTransform:SetUniformScale(1.0);
	cameraActor:LookAt(sphereActor)
	
	local sphereActor = PX2_CREATER:CreateActor_Sphere(scene, APoint.ORIGIN)
	sphereActor.LocalTransform:SetTranslateXZ(2.0, 1.0);
	
		local sphereActor = PX2_CREATER:CreateActor_Sphere(scene, APoint.ORIGIN)
	sphereActor.LocalTransform:SetTranslate(APoint(4.0, -2.0, 2.0));
end

Start()