-- stageview.lua

function CreateStageEditMenu()
	local selObj = PX2_SELECTION:GetFirstObject()

	local editMenu = NirMan:GetCurMenu()
	
	local createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
	
	local createSceneMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Scene")))
	local createSceneGeometryMenu = NirMan:AddSubMenu(createSceneMenu, (PX2_LM:GetValue("Geometry")))
	NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("RectPiece"), "CreateRectPiece")
	NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Box"), "CreateBox")
	NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Sphere"), "CreateSphere")
	
	local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
	
	local addMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Add")))
	local addSceneMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("Scene")))
	local addUIMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("UI")))
	
	if nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ResetPlay"), "ResetPlay")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Play"), "Play")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Stop"), "Stop")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Reset"), "Reset")
	end
	
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ImportSelectedRes"), "ImportSelectedRes")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Import"), "Import")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ExportSelected"), "ExportSelected")
	
	if nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInSceneTree"), "FindInSceneTree")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInResTree"), "FindInResTree")
	end
end