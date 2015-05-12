-- bat.lua

function OnUIBat()
	-- scene
	local scene = PX2_RM:BlockLoad("Data/game_x/scenes/scene.px2obj")
	PX2_PROJ:SetScene(scene)
	
	local startHeight = gBGOSize*gNumGridRow
	scene:SetViewPortProject(0.0, startHeight, gProjWidth, gProjHeight-startHeight)

	-- ui
	PX2_PROJ:GetUIFrame():DetachAllChildren()

	local ui = PX2_RM:BlockLoad("Data/game_x/objects/ui/bat/batframe.px2obj")
	PX2_PROJ:GetUIFrame():AttachChild(ui)

	gTheGame.BatGrid = BatGrid:New()
	gTheGame.BatGrid.GridFrame = ui:GetObjectByName("GridFrame")
	gTheGame.BatGrid.GridFrame:DetachAllChildren()	
	gTheGame.BatGrid:Reset()
end