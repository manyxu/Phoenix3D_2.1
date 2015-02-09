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
	
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("RectPiece"), "e_SceneActor_CreateRectangle()")
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Box"), "e_SceneActor_CreateBox()")
		NirMan:AddMenuItem(createSceneGeometryMenu, PX2_LM:GetValue("Sphere"), "e_SceneActor_CreateSphere()")
		
		local createUIMenu = NirMan:AddSubMenu(createMenu, (PX2_LM:GetValue("UI")))
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIPicBox"), "e_CreateUIPixBox(true)")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UITest"), "e_CreateUIText(true)")
		NirMan:AddSeparater(createUIMenu)
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIFrame"), "e_CreateUIFrame(true)")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIButton"), "e_CreateUIButton(true)")
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar(true)")
	elseif 2==tag then
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
		NirMan:AddMenuItem(createUIMenu, PX2_LM:GetValue("UIProgressBar"), "e_CreateUIProgressBar(false)")
	end

	if 1==tag then
		local addMenu = NirMan:AddSubMenu(editMenu, (PX2_LM:GetValue("Add")))
		local addSceneMenu = NirMan:AddSubMenu(addMenu, (PX2_LM:GetValue("SceneActor")))
	end
	
	if nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Copy"), "e_OnCopy()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Paste"), "e_OnPaste()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete"), "e_OnDelete()")
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ResetPlay"), "e_ResetPlay()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Play"), "e_Play()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Stop"), "e_Stop()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Reset"), "e_Reset()")
	end
	
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ImportSelectedRes"), "e_ImportSelectedRes()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Import"), "e_Import()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ExportSelected"), "e_ExportSelected()")
	
	if 1==tag and nil~=selObj then
		NirMan:AddSeparater(editMenu)
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInSceneTree"), "e_FindInSceneTree()")
		NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("FindInResTree"), "e_FindInResTree()")
	end
end

function e_CreateResMenu()
end

function e_CreateToolMenuFile()
	local editMenu = NirMan:GetCurMenu()
	
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("NewProject").."\tCtrl-N", "e_OnNewProject()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Open").."\tCtrl-O", "e_OnOpenProject()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Save").."\tCtrl-S", "e_OnSaveProject()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("SaveAs"), "e_OnSaveAsProject()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Close"), "e_OnCloseProject()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("NewScene"), "e_OnNewScene()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Open"), "e_OnOpenScene()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Save"), "e_OnSaveScene()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("SaveAs"), "e_OnSaveAsScene()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Close"), "e_OnCloseScene()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Exit"), "e_OnExit()")	
end

function e_CreateToolMenuEdit()
	local editMenu = NirMan:GetCurMenu()
	
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Repeal").."\tCtrl-Z", "e_OnRepeal()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Repeat").."\tCtrl-Y", "e_OnRepeat()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Copy").."\tCtrl-C", "e_OnCopy()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Paste").."\tCtrl-V", "e_OnPaste()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Delete").."\tDelete", "e_OnDelete()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Select").."\tQ", "e_OnSelect()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Translate").."\tW", "e_OnTranslate()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Rotate").."\tE", "e_OnRotate()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Scale").."\tR", "e_OnScale()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("PlayAndStop").."\tAlt-Space", "e_OnPlayAndStop()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("ResetPlay").."\tShift-Space", "e_OnResetPlay()")
end

function e_CreateToolMenuView()
	local editMenu = NirMan:GetCurMenu()
	
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Window"), "e_OnWindow()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("StageCenter").."\tCtrl-Enter", "e_OnStageCenter()")
	NirMan:AddSeparater(editMenu)
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("PerspectiveCamera").."\tF5", "e_OnPerspectiveCamera()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("TopViewCamera").."\tF6", "e_OnTopViewCamera()")
end

function e_CreateToolMenuDebug()
	local editMenu = NirMan:GetCurMenu()
	
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("EditorSimulate"), "e_OnEditorSimulate()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("EditorPlay"), "e_OnEditorPlay()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Operation").."\tCtrl-G", "e_OnOperation()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("PlayConfig"), "e_OnPlayConfig()")
end

function e_CreateToolMenuTool()
	local editMenu = NirMan:GetCurMenu()
	
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("VersionWindows"), "e_OnVersionWindows()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("VersionAndroid"), "e_OnVersionAndroid()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("VersionIOS"), "e_OnVersionIOS()")
	NirMan:AddMenuItem(editMenu, PX2_LM:GetValue("Setting"), "e_OnSetting()")
end

function e_CreateToolMenuHelp()
end

