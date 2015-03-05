-- functions.lua

function e_OnNewProject()
	E_MainFrame:OnNewProject();
end

function e_OnOpenProject()
	E_MainFrame:OnOpenProject();
end

function e_OnSaveProject()
	E_MainFrame:OnSaveProject();
end

function e_OnSaveAsProject()
	E_MainFrame:OnSaveProjectAs();
end

function e_OnCloseProject()
	E_MainFrame:OnCloseProject();
end

function e_OnNewScene()
	E_MainFrame:OnNewScene();
end

function e_OnOpenScene()
	E_MainFrame:OnOpenScene();
end

function e_OnSaveScene()
	E_MainFrame:OnSaveScene();
end

function e_OnSaveAsScene()
	E_MainFrame:OnSaveSceneAs();
end

function e_OnCloseScene()
	E_MainFrame:OnCloseScene();
end

function e_OnExit()
end

function e_OnSetting()
	E_MainFrame:OnSetting()
end

function e_OnSelect()
	E_MainFrame:OnSetEditMode(Edit.EM_SELECT)
end

function e_OnTranslate()
	E_MainFrame:OnSetEditMode(Edit.EM_TRANSLATE)
end

function e_OnRotate()
	E_MainFrame:OnSetEditMode(Edit.EM_ROLATE)
end

function e_OnScale()
	E_MainFrame:OnSetEditMode(Edit.EM_SCALE)
end

function e_OnCopy()
end

function e_OnPaste()
end

function e_OnDelete()
	PX2_EDIT:DeleteSelection()
end

function e_ImportSelectedRes()
end

function e_Import()
end

function e_ExportSelected()
end

function e_AnimResetPlay()
	PX2_EDIT:AnimResetPlay()
end

function e_AnimPlayStop()
	PX2_EDIT:AnimPlayStop()
end

function e_AnimPlay()
	PX2_EDIT:AnimPlay()
end

function e_AnimStop()
	PX2_EDIT:AnimStop()
end

function e_AnimReset()
	PX2_EDIT:AnimReset()
end

-- edit mode
function e_SetEditMode_Scene()
	PX2_EDIT:SetEditType(Edit.ET_SCENE)
end

function e_SetEditMode_Terrain()
	PX2_EDIT:SetEditType(Edit.ET_TERRAIN)
end

function e_SetEditMode_UI()
	PX2_EDIT:SetEditType(Edit.ET_UI)
end

-- Scene
function e_SceneActor_CreateRectangle()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Rectangle(scene, pickPos)
end

function e_SceneActor_CreateBox()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Box(scene, pickPos)
end

function e_SceneActor_CreateSphere()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Sphere(scene, pickPos)
end

function e_SceneActor_CreateCharacter()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Character(scene, pickPos)
end

function e_SceneActor_CreateEffect()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Effect(scene, pickPos)
end

-- General
function e_CreateRectangle(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateRectangle(node, pickPos, true, true, isWorld)
		mov.LocalTransform:SetUniformScale(100.0)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateBox(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateBox(node, pickPos, true, true, usePickPos)
		mov.LocalTransform:SetUniformScale(100.0)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateSphere(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateSphere(node, pickPos, true, true, usePickPos)
		mov.LocalTransform:SetUniformScale(100.0)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateParticles(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateParticleEmitter(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateBillboard(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateBillboard(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateBeam(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateBeamEmitter(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateRobbion(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateRibbonEmitter(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateSoundable(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateSoundable(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIPixBox(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIPicBox(node, pickPos, "Data/engine/default.png", true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIText(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIText(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIFrame(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIFrame(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIButton(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIButton(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUICheckButton(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUICheckButton(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIEditBox(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIEditBox(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIProgressBar(usePickPos)
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIProgressBar(node, pickPos, true, usePickPos)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

-- add
function e_AddSceneActor_Actor()
	local scene = PX2_PROJ:GetScene()
	local resPath = PX2_EDIT:GetSelectedResource().ResPathname;
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:AddActor(scene, resPath, pickPos)
end

function e_AddSceneActor_Character()
	local scene = PX2_PROJ:GetScene()
	local resPath = PX2_EDIT:GetSelectedResource().ResPathname;
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:AddCharacter(scene, resPath, pickPos)
end

function e_AddSceneActor_Effect()
	local scene = PX2_PROJ:GetScene()
	local resPath = PX2_EDIT:GetSelectedResource().ResPathname;
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:AddEffectActor(scene, resPath, pickPos)
end

function e_AddSceneActor_Sound()
end

-- scene view
function e_FindInSceneTree()
	PX2_EDIT:OnFindSelectInProjTree()
end

function e_FindInResTree()
	PX2_EDIT:OnFindSelectInResTree()
end

-- project view
function e_ProjectView_Detail_General()
	NirMan:SetProjTreeLevel(0)
end

function e_ProjectView_Detail_Children()
	NirMan:SetProjTreeLevel(1)
end

function e_ProjectView_Detail_Controls()
	NirMan:SetProjTreeLevel(2)
end

function e_ProjectView_Detail_Materials()
	NirMan:SetProjTreeLevel(3)
end

function e_ProjectView_Detail_Details()
	NirMan:SetProjTreeLevel(4)
end

-- res view
function e_ResView_Refresh()
end

function e_ResView_Clear()
end

--Insp view
function e_InspView_ChangeWindow(windowType)
	E_MainFrame:InspChangeWindow(windowType)
end