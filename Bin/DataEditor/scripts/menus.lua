-- menus.lua

-- tag 1 renderview
-- tag 2 projview
function CreateEditMenu(tag)

	local selObj = PX2_SELECTION:GetFirstObject()

	local editMenu = NirMan:GetCurMenu()
	
	local createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
	
	if 1==tag then
		local createSceneMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("SceneActor")))
		local createSceneGeometryMenu = NirMan:AddSubMenu(createSceneMenu, (PX2_LM:GetValue("Geometry")))
	
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("RectPiece"), "SceneActor_CreateRectPiece")
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Box"), "SceneActor_CreateBox")
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Sphere"), "SceneActor_CreateSphere")
	elseif 2==tag then
		local createGeometryMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Geometry")))
		NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("RectPiece"), "CreateRectPiece")
		NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Box"), "CreateBox")
		NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Sphere"), "CreateSphere")
		
		local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "CreateUIPixBox")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "CreateUIText")
		NirMan:AddSeparater(createUIMenu)
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "CreateUIFrame")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "CreateUIButton")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "CreateUIProgressBar")
	end

	if 1==tag then
		local addMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Add")))
		local addSceneMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("SceneActor")))
	end
	
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
	
	if 1==tag and nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInSceneTree"), "FindInSceneTree")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInResTree"), "FindInResTree")
	end
end

function CreateResMenu()
end