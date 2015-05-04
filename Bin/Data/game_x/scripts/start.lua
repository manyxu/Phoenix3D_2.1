-- start.lua

PX2_SM:CallFile("Data/game_x/scripts/generalfunctions.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/eventui.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/main/main.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/bat/bat.lua")

function CreateMainUI()
	local ui = PX2_RM:BlockLoad("Data/game_x/objects/ui/main/mainframe.px2obj")
	PX2_PROJ:GetUIFrame():AttachChild(ui)
end
CreateMainUI()

function OnEventGeneralString(eventStr)
	OnEventGeneralStringUI(eventStr)
end