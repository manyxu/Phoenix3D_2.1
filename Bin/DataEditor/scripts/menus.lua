-- menus.lua

function e_CreateEditMenu(tag)

	local selObj = PX2_SELECTION:GetFirstObject()

	local editMenu = NirMan:GetCurMenu()
	
	if PVT_PROJECT==tag or RVT_SCENEUI==tag then
		local createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
		
		if PVT_PROJECT==tag then
			local createGeometryMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Geometry")))
			NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_CreateRectangle(false)")
			NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Box"), "e_CreateBox(false)")
			NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Sphere"), "e_CreateSphere(false)")
			
			local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPixBox(false)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "e_CreateUIText(false)")
			NirMan:AddSeparater(createUIMenu)
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "e_CreateUIFrame(false)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "e_CreateUIButton(false)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UICheckButton"), "e_CreateUICheckButton(false)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIEditBox"), "e_CreateUIEditBox(true)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar(false)")
			
			local createEffect = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Effect")))
			NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Particles"), "e_CreateParticles(false)")
			NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Billboard"), "e_CreateBillboard(false)")
			NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Beam"), "e_CreateBeam(false)")
			NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Robbion"), "e_CreateRobbion(false)")
			NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Soundable"), "e_CreateSoundable(false)")
		elseif RVT_SCENEUI==tag then
			local createSceneMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("SceneActor")))
			
			local createSceneGeometryMenu = NirMan:AddSubMenu(createSceneMenu, (PX2_LM:GetValue("Geometry")))
			NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_SceneActor_CreateRectangle()")
			NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Box"), "e_SceneActor_CreateBox()")
			NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Sphere"), "e_SceneActor_CreateSphere()")
			
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Character"), "e_SceneActor_CreateCharacter()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Light"), "e_SceneActor_CreateLight()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Effect"), "e_SceneActor_CreateEffect()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Trigger"), "e_SceneActor_CreateTrigger()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Terrain"), "e_SceneActor_CreateTerrain()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Sky"), "e_SceneActor_CreateSky()")
			
			local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPixBox(true)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "e_CreateUIText(true)")
			NirMan:AddSeparater(createUIMenu)
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "e_CreateUIFrame(true)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "e_CreateUIButton(true)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UICheckButton"), "e_CreateUICheckButton(true)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIEditBox"), "e_CreateUIEditBox(true)")
			NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar(true)")
		end

		if RVT_SCENEUI==tag then
			local addMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Add")))
			local addSceneMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("SceneActor")))
			NirMan:AddMenuItem(addSceneMenu, PX2_LM:GetValue("Object"), "e_AddSceneActor_Actor()")
			NirMan:AddMenuItem(addSceneMenu, PX2_LM:GetValue("Character"), "e_AddSceneActor_Character()")
			NirMan:AddMenuItem(addSceneMenu, PX2_LM:GetValue("Effect"), "e_AddSceneActor_Effect()")
		end
		
		if nil~=selObj then
			NirMan:AddSeparater(editMenu)
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Copy"), "e_OnCopy()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Paste"), "e_OnPaste()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete"), "e_OnDelete()")
			NirMan:AddSeparater(editMenu)
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ResetPlay"), "e_AnimResetPlay()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Play"), "e_AnimPlay()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Stop"), "e_AnimStop()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Reset"), "e_AnimReset()")
		end
		
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ImportSelectedRes"), "e_OnImportSelectedRes()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Import"), "e_OnImport()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Export"), "e_OnExport()")
		
		if RVT_SCENEUI==tag and nil~=selObj then
			NirMan:AddSeparater(editMenu)
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInSceneTree"), "e_FindInSceneTree()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInResTree"), "e_FindInResTree()")
		end
	end
end

function e_CreateResMenu()
	local editMenu = NirMan:GetCurMenu()
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Open"), "e_ResView_Open()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("CopyResPath"), "e_ResView_CopyResPath()")
end