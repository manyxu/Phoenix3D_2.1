-- mainframe.lua

function e_CreateMainMenu()
	-- file
	local itemFile = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("File")))
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("NewProject").."\tCtrl-N", "e_OnNewProject()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Open").."\tCtrl-O", "e_OnOpenProject()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Save").."\tCtrl-S", "e_OnSaveProject()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Close"), "e_OnCloseProject()")
	E_MainFrame:AddSeparater(itemFile)
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("NewScene"), "e_OnNewScene()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Open"), "e_OnOpenScene()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Save"), "e_OnSaveScene()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("SaveAs"), "e_OnSaveAsScene()")
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Close"), "e_OnCloseScene()")
	E_MainFrame:AddSeparater(itemFile)
	E_MainFrame:AddMenuItem(itemFile, PX2_LM:GetValue("Exit"), "e_OnExit()")
	--edit
	local itemEdit = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Edit")))
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("OnDo").."\tCtrl-Z", "e_OnUnDo()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("ReDo").."\tCtrl-Y", "e_OnReDo()")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Copy").."\tCtrl-C", "e_OnCopy()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Paste").."\tCtrl-V", "e_OnPaste()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Delete").."\tDelete", "e_OnDelete()")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Import").."\tCtrl-I", "e_OnImport()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Export").."\tCtrl-E", "e_OnExport()")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Select"), "e_OnSelect()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Translate"), "e_OnTranslate()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Rotate"), "e_OnRotate()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("Scale"), "e_OnScale()")
	E_MainFrame:AddSeparater(itemEdit)
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("PlayAndStop").."\tAlt-Space", "e_AnimPlayStop()")
	E_MainFrame:AddMenuItem(itemEdit, PX2_LM:GetValue("ResetPlay").."\tSpace", "e_AnimResetPlay()")
	--itemview
	local itemView = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("View")))
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("Window"), "e_OnWindow()")
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("StageCenter").."\tCtrl-Enter", "e_OnStageCenter()")
	E_MainFrame:AddSeparater(itemView)
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("PerspectiveCamera").."\tF5", "e_OnPerspectiveCamera()")
	E_MainFrame:AddMenuItem(itemView, PX2_LM:GetValue("TopViewCamera").."\tF6", "e_OnTopViewCamera()")
	--debug
	local itemDebug = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Debug")))
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("EditorSimulate"), "e_OnEditorSimulate()")
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("EditorPlay"), "e_OnEditorPlay()")
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("EditorStop"), "e_OnEditorStop()")
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("WindowPlay").."\tCtrl-G", "e_OnPlay()")
	E_MainFrame:AddSeparater(itemDebug)
	E_MainFrame:AddMenuItem(itemDebug, PX2_LM:GetValue("PlayConfig"), "e_OnPlayConfig()")
	--tool
	local itemTool = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Tool")))
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("VersionWindows"), "e_OnVersionWindows()")
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("VersionAndroid"), "e_OnVersionAndroid()")
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("VersionIOS"), "e_OnVersionIOS()")
	E_MainFrame:AddMenuItem(itemTool, PX2_LM:GetValue("Setting"), "e_OnSetting()")
	--help
	local itemHelp = E_MainFrame:AddMainMenuItem((PX2_LM:GetValue("Help")))
end

function e_ResView_CopyResPath()
	
end