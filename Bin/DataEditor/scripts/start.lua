-- onstart.lua

PX2_SM:CallFile("DataEditor/scripts/language.lua")

AddLanguages()

function CreateMainMenu()
	-- file
	local itemFile = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("File")))
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("NewProject").."\tCtrl-N", "OnNewProject")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Open").."\tCtrl-O", "OnOpenProject")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Save").."\tCtrl-S", "OnSaveProject")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("SaveAs"), "OnSaveAsProject")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Close"), "OnCloseProject")
	E_MainFrame:AddSeparater(itemFile)
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("NewScene"), "OnNewScene")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Open"), "OnOpenScene")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Save"), "OnSaveScene")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("SaveAs"), "OnSaveAsScene")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Close"), "OnCloseScene")
	E_MainFrame:AddSeparater(itemFile)
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Exit"), "OnExit")
	--edit
	local itemEdit = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Edit")))
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Repeal").."\tCtrl-Z", "OnRepeal")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Repeat").."\tCtrl-Y", "OnRepeat")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Copy").."\tCtrl-C", "OnCopy")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Paste").."\tCtrl-V", "OnPaste")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Delete").."\tDelete", "OnDelete")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Select").."\tF1", "OnSelect")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Move").."\tF2", "OnMove")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Rotate").."\tF3", "OnRotate")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Scale").."\tF4", "OnScale")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("PlayAndStop").."\tAlt-Space", "OnPlayAndStop")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("ResetPlay").."\tShift-Space", "OnResetPlay")
	--itemview
	local itemView = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("View")))
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("Window"), "OnWindow")
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("StageCenter").."\tCtrl-Enter", "OnStageCenter")
	E_MainFrame:AddSeparater(itemView)
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("PerspectiveCamera").."\tF5", "OnPerspectiveCamera")
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("TopViewCamera").."\tF6", "OnTopViewCamera")
	--debug
	local itemDebug = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Debug")))
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("EditorSimulate"), "OnEditorSimulate")
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("EditorPlay"), "OnEditorPlay")
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("Operation").."\tCtrl-G", "OnOperation")
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("PlayConfig"), "OnPlayConfig")
	--tool
	local itemTool = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Tool")))
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("VersionWindows"), "OnVersionWindows")
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("VersionAndroid"), "OnVersionAndroid")
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("VersionIOS"), "OnVersionIOS")
	--help
	local itemHelp = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Help")))
end

function OnNewProject()
end

function OnOpenProject()
end

function OnSaveProject()
end

function OnSaveAsProject()
end

function OnCloseProject()
end

function OnNewScene()
end

function OnOpenScene()
end

function OnSaveScene()
end

function OnSaveAsScene()
end

function OnCloseScene()
end

function OnExit()
end

CreateMainMenu()
