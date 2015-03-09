-- start.lua
-- this is the place where logic start

function Start()
	local scene = PX2_PROJ:GetScene()
	local cameraActor = scene:GetUseCameraActor()
	
	local sphereActor = PX2_CREATER:CreateActor_Sphere(scene, APoint.ORIGIN)
	
	cameraActor:LookAt(sphereActor)
end

Start()