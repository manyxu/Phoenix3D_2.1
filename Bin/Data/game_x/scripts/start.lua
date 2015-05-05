-- start.lua


-- calls
PX2_SM:CallFile("Data/game_x/scripts/generalfunctions.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/eventui.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/main/main.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/bat/bat.lua")
PX2_SM:CallFile("Data/game_x/scripts/ui/bat/batgrid.lua")


-- EventGeneralString
function OnEventGeneralString(eventStr)
	OnEventGeneralStringUI(eventStr)
end


-- TheGame
GameX = {}
GameX.IsInBat = false
GameX.BatGrid = nil

function GameX:New(o)
	o = o or {}
	setmetatable(o, self)
	self.__index = self
	return o
end

function GameX:CreateMainUI()
	local ui = PX2_RM:BlockLoad("Data/game_x/objects/ui/main/mainframe.px2obj")
	PX2_PROJ:GetUIFrame():AttachChild(ui)
end

function GameX:CreateBat()
end

gTheGame = GameX:New()

gTheGame:CreateMainUI()