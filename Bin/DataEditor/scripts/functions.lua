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
	E_MainFrame:OnSetEditMode(1)
end

function e_OnTranslate()
	E_MainFrame:OnSetEditMode(2)
end

function e_OnRotate()
	E_MainFrame:OnSetEditMode(3)
end

function e_OnScale()
	E_MainFrame:OnSetEditMode(4)
end

function e_ImportSelectedRes()
end

function e_Import()
end

function e_ExportSelected()
end

function ResetPlay()
end

function Play()
end

function Stop()
end

-- Scene
function e_SceneActor_CreateRectPiece()
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

-- General
function e_CreateRectPiece()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateRectangle(node, pickPos, true, true)
		mov.LocalTransform:SetUniformScale(100.0)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateBox()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateBox(node, pickPos, true, true)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateSphere()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		local mov = PX2_CREATER:CreateSphere(node, pickPos, true, true)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIPixBox()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIPicBox(node, pickPos, "Data/engine/default.png", true)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIText()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIText(node, pickPos, true)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIFrame()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIFrame(node, pickPos, true)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIButton()
	local selectObj = PX2_SELECTION:GetFirstObject()
	local node = PX2_CREATER:ConvertToNode(selectObj)
	if nil~=node then
		local pickPos = PX2_EDIT:GetPickPos()
		PX2_CREATER:CreateUIButton(node, pickPos, true)
	else
		NirMan:MessageBox(PX2_LM:GetValue("Tip1"), PX2_LM:GetValue("Notice"))
	end
end

function e_CreateUIProgressBar()
end