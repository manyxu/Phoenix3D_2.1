-- start.lua

PX2_SM:CallFile("Data/game_x/scripts/generalfunctions.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/eventui.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/main/main.lua")

function onEventGeneralString(eventStr)
	onEventGeneralStringUI(eventStr)
end