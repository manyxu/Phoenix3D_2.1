-- menus.lua

function e_CreateEditMenu(tag)

	local selObj = PX2_SELECTION:GetFirstObject()
	local selControlledable = PX2_CREATER:ConvertToControlledable(selObj)
	local selMovable = PX2_CREATER:ConvertToMovable(selObj)
	local selNode = PX2_CREATER:ConvertToNode(selObj)
	local selEftCtrl = PX2_CREATER:ConvertToEffectableController(selObj)
	local selEftModule = PX2_CREATER:ConvertToEffectModule(selObj)
	local selIterpCurveCtrl = PX2_CREATER:ConvertToInterpCurveController(selObj)

	local editMenu = NirMan:GetCurMenu()
	
	local isAddedSomthing = false
	local isCreateMenuAddSomthing = false
	
	if PVT_PROJECT==tag or RVT_SCENEUI==tag then		
		if PVT_PROJECT==tag then
			local createMenu = nil
		
			if nil ~= selNode then
				createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
				isAddedSomthing = true
				isCreateMenuAddSomthing = true
			
				local createGeometryMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Geometry")))
				NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_CreateRectangle(false)")
				NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Box"), "e_CreateBox(false)")
				NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Sphere"), "e_CreateSphere(false)")
				
				local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPicBox(false)")
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
				
				NirMan:AddSeparater(createMenu)
				NirMan:AddMenuItem(createMenu, PX2_LM:GetValue("Node"), "e_CreateNode()")
				
			elseif nil~=selEftCtrl then
				local addEffectModuleMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("AddEffectModule")))
				isAddedSomthing = true
				NirMan:RefreshEffectableControllerModules(addEffectModuleMenu, selEftCtrl)
			end
			
			if nil ~= selMovable then
				
				if nil==createMenu then
					createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
					isAddedSomthing = true
				end
				
				if isCreateMenuAddSomthing then
					NirMan:AddSeparater(createMenu)
				end
				
				local createCtrlMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Control")))
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("ColorController"), "e_CreateColorController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("AlphaController"), "e_CreateAlphaController()")
				NirMan:AddSeparater(createCtrlMenu)
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("UniformScaleController"), "e_CreateUniformScaleController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("ScaleController"), "e_CreateScaleController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("RotateController"), "e_CreateRotateController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("TranslateController"), "e_CreateTranslateController()")					
			end
			
		elseif RVT_SCENEUI==tag then
			
			createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
			isAddedSomthing = true
			isCreateMenuAddSomthing = true
			
			local createSceneMenu = nil
			if nil==selNode then
				createSceneMenu = createMenu
			else
				createSceneMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("SceneActor")))
			end
				
			local createSceneGeometryActorMenu = NirMan:AddSubMenu(createSceneMenu, (PX2_LM:GetValue("Geometry")))
			NirMan:AddMenuItem(createSceneGeometryActorMenu, PX2_LM:GetValue("RectPiece"), "e_SceneActor_CreateRectangle()")
			NirMan:AddMenuItem(createSceneGeometryActorMenu, PX2_LM:GetValue("Box"), "e_SceneActor_CreateBox()")
			NirMan:AddMenuItem(createSceneGeometryActorMenu, PX2_LM:GetValue("Sphere"), "e_SceneActor_CreateSphere()")
			
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Actor"), "e_SceneActor_CreateActor()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Character"), "e_SceneActor_CreateCharacter()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Light"), "e_SceneActor_CreateLight()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Effect"), "e_SceneActor_CreateEffect()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Trigger"), "e_SceneActor_CreateTrigger()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Terrain"), "e_SceneActor_CreateTerrain()")
			NirMan:AddMenuItem(createSceneMenu, PX2_LM:GetValue("Sky"), "e_SceneActor_CreateSky()")
			
			if nil~=selNode then
				local createGeometryMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Geometry")))
				NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_CreateRectangle(false)")
				NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Box"), "e_CreateBox(false)")
				NirMan:AddMenuItem(createGeometryMenu, PX2_LM:GetValue("Sphere"), "e_CreateSphere(false)")
			
				local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPicBox(true)")
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "e_CreateUIText(true)")
				NirMan:AddSeparater(createUIMenu)
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "e_CreateUIFrame(true)")
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "e_CreateUIButton(true)")
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UICheckButton"), "e_CreateUICheckButton(true)")
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIEditBox"), "e_CreateUIEditBox(true)")
				NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar(true)")
					
				local createEffect = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Effect")))
				NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Particles"), "e_CreateParticles(false)")
				NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Billboard"), "e_CreateBillboard(false)")
				NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Beam"), "e_CreateBeam(false)")
				NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Robbion"), "e_CreateRobbion(false)")
				NirMan:AddMenuItem(createEffect, PX2_LM:GetValue("Soundable"), "e_CreateSoundable(false)")
					
				NirMan:AddSeparater(createMenu)
				NirMan:AddMenuItem(createMenu, PX2_LM:GetValue("Node"), "e_CreateNode()")
			end
				
			if nil ~= selMovable then
				
				if nil==createMenu then
					createMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Create")))
					isAddedSomthing = true
				end
				
				if isCreateMenuAddSomthing then
					NirMan:AddSeparater(createMenu)
				end
				
				local createCtrlMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("Control")))
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("ColorController"), "e_CreateColorController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("AlphaController"), "e_CreateAlphaController()")
				NirMan:AddSeparater(createCtrlMenu)
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("UniformScaleController"), "e_CreateUniformScaleController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("ScaleController"), "e_CreateScaleController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("RotateController"), "e_CreateRotateController()")
				NirMan:AddMenuItem(createCtrlMenu, PX2_LM:GetValue("TranslateController"), "e_CreateTranslateController()")				
			end
		end

		if RVT_SCENEUI==tag then
			local addMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Add")))
			isAddedSomthing = true
			
			local addSceneMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("SceneActor")))
			NirMan:AddMenuItem(addSceneMenu, PX2_LM:GetValue("Object"), "e_AddSceneActor_Actor()")
			NirMan:AddMenuItem(addSceneMenu, PX2_LM:GetValue("Character"), "e_AddSceneActor_Character()")
			NirMan:AddMenuItem(addSceneMenu, PX2_LM:GetValue("Effect"), "e_AddSceneActor_Effect()")
		end
		
		if nil~=selEftModule or nil~=selIterpCurveCtrl then
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("MakeTimeLine"), "e_OnMakeTimeLine()")
			isAddedSomthing = true
		end
		
		if nil~=selObj then
			if isAddedSomthing then
				NirMan:AddSeparater(editMenu)
			end
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Copy"), "e_OnCopy()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Paste"), "e_OnPaste()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete"), "e_OnDelete()")
			isAddedSomthing = true
		end
		
		if nil~=selControlledable then
			if isAddedSomthing then
				NirMan:AddSeparater(editMenu)
			end
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ResetPlay"), "e_AnimResetPlay()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Play"), "e_AnimPlay()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Stop"), "e_AnimStop()")
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Reset"), "e_AnimReset()")
			isAddedSomthing = true
		end
		
		if isAddedSomthing then
			NirMan:AddSeparater(editMenu)
		end
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ImportSelectedRes"), "e_OnImportSelectedRes()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Import"), "e_OnImport()")
		if nil~=selObj then
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Export"), "e_OnExport()")
		end
		isAddedSomthing = true
		
		if PVT_PROJECT==tag then
			NirMan:AddSeparater(editMenu)
			local showLevelMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("ShowLevel")))
			NirMan:AddMenuItem(showLevelMenu, PX2_LM:GetValue("ShowGeneral"), "e_ProjectView_ShowLevel(0)")
			NirMan:AddMenuItem(showLevelMenu, PX2_LM:GetValue("ShowChildren"), "e_ProjectView_ShowLevel(1)")
			NirMan:AddMenuItem(showLevelMenu, PX2_LM:GetValue("ShowControl"), "e_ProjectView_ShowLevel(2)")
			NirMan:AddMenuItem(showLevelMenu, PX2_LM:GetValue("ShowMaterial"), "e_ProjectView_ShowLevel(3)")
			NirMan:AddMenuItem(showLevelMenu, PX2_LM:GetValue("ShowDetail"), "e_ProjectView_ShowLevel(4)")
		end
		
		if nil~=selObj then
			NirMan:AddSeparater(editMenu)
			if RVT_SCENEUI==tag then
				NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInSceneTree"), "e_FindInSceneTree()")
			end	
			NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInResTree"), "e_FindInResTree()")
		end
	end
end

function e_CreateResMenu()
	local editMenu = NirMan:GetCurMenu()
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Open"), "e_ResView_Open()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("CopyResPath"), "e_ResView_CopyResPath()")
end

function e_CreateTimeLineMenu_Left()
	local editMenu = NirMan:GetCurMenu()
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete"), "e_DeleteCurveGroup()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("DeleteAll"), "e_DeleteAllCurveGroup()")
end

function e_CreateTimeLineMenu_Right()
	local editMenu = NirMan:GetCurMenu()
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("SetInValue"), "e_SetInValue()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("SetOutValue"), "e_SetOutValue()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete"), "e_DeleteCurveKeyPoint()")
end