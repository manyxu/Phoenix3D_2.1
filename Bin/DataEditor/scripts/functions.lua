-- functions.lua

function OnNewProject()
	E_MainFrame:OnNewProject();
end

function OnOpenProject()
	E_MainFrame:OnOpenProject();
end

function OnSaveProject()
	E_MainFrame:OnSaveProject();
end

function OnSaveAsProject()
	E_MainFrame:OnSaveProjectAs();
end

function OnCloseProject()
	E_MainFrame:OnCloseProject();
end

function OnNewScene()
	E_MainFrame:OnNewScene();
end

function OnOpenScene()
	E_MainFrame:OnOpenScene();
end

function OnSaveScene()
	E_MainFrame:OnSaveScene();
end

function OnSaveAsScene()
	E_MainFrame:OnSaveSceneAs();
end

function OnCloseScene()
	E_MainFrame:OnCloseScene();
end

function OnExit()
end

function OnSelect()
	E_MainFrame:OnSetEditMode(1)
end

function OnTranslate()
	E_MainFrame:OnSetEditMode(2)
end

function OnRotate()
	E_MainFrame:OnSetEditMode(3)
end

function OnScale()
	E_MainFrame:OnSetEditMode(4)
end

function ImportSelectedRes()
end

function Import()
end

function ExportSelected()
end

function ResetPlay()
end

function Play()
end

function Stop()
end

function CreateRectPiece()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Rectangle(scene, pickPos)
end

function CreateBox()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Box(scene, pickPos)
end

function CreateSphere()
	local scene = PX2_PROJ:GetScene()
	local pickPos = PX2_EDIT:GetPickPos()
	PX2_CREATER:CreateActor_Sphere(scene, pickPos)
end