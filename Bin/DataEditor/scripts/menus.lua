-- menus.lua

-- tag 1 renderview
-- tag 2 projview
function e_CreateEditMenu(tag)

	local selObj = PX2_SELECTION:GetFirstObject()

	local editMenu = NirMan:GetCurMenu()
	
	local createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
	
	if 1==tag then
		local createSceneMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("SceneActor")))
		local createSceneGeometryMenu = NirMan:AddSubMenu(createSceneMenu, (PX2_LM:GetValue("Geometry")))
	
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_SceneActor_CreateRectPiece")
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Box"), "e_SceneActor_CreateBox")
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Sphere"), "e_SceneActor_CreateSphere")
		
		local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPixBox")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "e_CreateUIText")
		NirMan:AddSeparater(createUIMenu)
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "e_CreateUIFrame")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "e_CreateUIButton")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar")
	elseif 2==tag then
		local createGeometryMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Geometry")))
		NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_CreateRectPiece")
		NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Box"), "e_CreateBox")
		NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Sphere"), "e_CreateSphere")
		
		local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPixBox")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "e_CreateUIText")
		NirMan:AddSeparater(createUIMenu)
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "e_CreateUIFrame")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "e_CreateUIButton")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar")
	end

	if 1==tag then
		local addMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Add")))
		local addSceneMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("SceneActor")))
	end
	
	if nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Copy"), "e_OnCopy")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Paste"), "e_OnPaste")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete"), "e_OnDelete")
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ResetPlay"), "e_ResetPlay")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Play"), "e_Play")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Stop"), "e_Stop")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Reset"), "e_Reset")
	end
	
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ImportSelectedRes"), "e_ImportSelectedRes")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Import"), "e_Import")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ExportSelected"), "e_ExportSelected")
	
	if 1==tag and nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInSceneTree"), "e_FindInSceneTree")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInResTree"), "e_FindInResTree")
	end
end

function e_CreateResMenu()
end