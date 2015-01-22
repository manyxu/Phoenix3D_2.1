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
	
	local itemEdit = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Edit")))
	
	local itemView = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("View")))
	
	local itemDebug = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Debug")))
	
	local itemTool = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Tool")))
	
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
