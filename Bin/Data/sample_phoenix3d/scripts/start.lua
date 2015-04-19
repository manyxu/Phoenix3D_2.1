--

actorBox = nil;

function onCreateActor()
	local scene = PX2_PROJ:GetScene()
	
	local actorBox = PX2_CREATER:CreateActor_Box(scene, APoint.ORIGIN)
	actorBox.LocalTransform:SetTranslate(APoint(56.0, 43.0, 0.0))
	actorBox:SetName("MyActorBox")
end
onCreateActor()

function onCreateUI()
	local uiFrame = PX2_PROJ:GetUIFrame()
	
	local uiButton = PX2_CREATER:CreateUIButton(uiFrame, APoint(100.0, 0.0, 200.0), false, false)
	uiButton.LocalTransform:SetTranslate(APoint(200.0, 0.0, 200.0))
	uiButton:SetSize(200.0, 50.0)
	uiButton:SetScriptHandler("onButton(arg1)")
end
onCreateUI()

function onButton()
	if UICT_RELEASED==arg1 then
		local scene = PX2_PROJ:GetScene()
		local actorBox = scene:GetObjectByName("MyActorBox")
		actorBox:Show(not actorBox:IsShow())
	end
end