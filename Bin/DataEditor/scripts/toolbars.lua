-- toolbars.lua

-- menu tool bar
function e_CreateToolBarMenu()
	NirMan:AddMenuTool(" "..(PX2_LM:GetValue("File")).." ", "e_CreateToolMenuFile()");
	NirMan:AddMenuTool(" "..(PX2_LM:GetValue("Edit")).." ", "e_CreateToolMenuEdit()");
	NirMan:AddMenuTool(" "..(PX2_LM:GetValue("View")).." ", "e_CreateToolMenuView()");
	NirMan:AddMenuTool(" "..(PX2_LM:GetValue("Debug")).." ", "e_CreateToolMenuDebug()");
	NirMan:AddMenuTool(" "..(PX2_LM:GetValue("Tool")).." ", "e_CreateToolMenuTool()");
	NirMan:AddMenuTool(" "..(PX2_LM:GetValue("Help")), "e_CreateToolMenuHelp()");
end

-- file tool bar
function e_CreateToolBarMain()
	NirMan:AddTool("DataEditor/icons/file/proj_new.png", "e_OnNewProject()")
	NirMan:AddTool("DataEditor/icons/file/proj_open.png", "e_OnOpenProject()")
	NirMan:AddTool("DataEditor/icons/file/proj_save.png", "e_OnSaveProject()")
	NirMan:AddTool("DataEditor/icons/file/proj_saveas.png", "e_OnSaveAsProject()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/file/scene_new.png", "e_OnNewScene()")
	NirMan:AddTool("DataEditor/icons/file/scene_open.png", "e_OnOpenScene()")
	NirMan:AddTool("DataEditor/icons/file/scene_save.png", "e_OnSaveScene()")
	NirMan:AddTool("DataEditor/icons/file/scene_saveas.png", "e_OnSaveAsScene()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/edittype/playinwindow.png", "e_OnPlay()")
end

-- scene view toolbar
function e_CreateToolBarSceneUI()
	NirMan:AddTool("DataEditor/icons/edittype/sceneedit.png", "e_SetEditMode_Scene()", PX2_LM:GetValue("SceneEdit"), 2)
	NirMan:AddTool("DataEditor/icons/edittype/terrainedit.png", "e_SetEditMode_Terrain()", PX2_LM:GetValue("TerrainEdit"), 2)
	NirMan:AddTool("DataEditor/icons/edittype/uiedit.png", "e_SetEditMode_UI()", PX2_LM:GetValue("UIEdit"), 2)
	NirMan:AddToolSeparater()
	NirMan:AddToolChoose(PX2_LM:GetValue("World"), PX2_LM:GetValue("Local"), "", "", "")
	NirMan:AddTool("DataEditor/icons/editmode/select.png", "e_OnSelect()", PX2_LM:GetValue("Select"), 2)
	NirMan:AddTool("DataEditor/icons/editmode/translate.png", "e_OnTranslate()", PX2_LM:GetValue("Translate"), 2)
	NirMan:AddTool("DataEditor/icons/editmode/rotate.png", "e_OnRotate()", PX2_LM:GetValue("Rotate"), 2)
	NirMan:AddTool("DataEditor/icons/editmode/scale.png", "e_OnScale()", PX2_LM:GetValue("Scale"), 2)
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/edittype/simulate.png", "e_SetEditMode_UI()", PX2_LM:GetValue("Simulate"), 1)
	NirMan:AddTool("DataEditor/icons/edittype/play.png", "e_SetEditMode_UI()", PX2_LM:GetValue("Play"), 1)
end

-- project view toolbar
function e_CreateTooBarProject()
	NirMan:AddTool("DataEditor/icons/projview/general.png", "e_ProjectView_Detail_General()")
	NirMan:AddTool("DataEditor/icons/projview/children.png", "e_ProjectView_Detail_Children()")
	NirMan:AddTool("DataEditor/icons/projview/ctrl.png", "e_ProjectView_Detail_Controls()")
	NirMan:AddTool("DataEditor/icons/projview/mtl.png", "e_ProjectView_Detail_Materials()")
	NirMan:AddTool("DataEditor/icons/projview/detail.png", "e_ProjectView_Detail_Details()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/projview/detail.png", "e_ProjectView_ShowHelpNode()")
end

-- res view toolbar
function e_CreateToolBarRes()
	NirMan:AddTool("DataEditor/icons/resview/res_refresh.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/resview/res_clear.png", "e_ResView_Clear()")
	NirMan:AddToolSeparater()
end

-- pre view toolbar
function e_CreateToolBarPreView ()
	NirMan:AddTool("DataEditor/icons/resview/res_refresh.png", "e_ResView_Refresh()")
end

-- timeline toolbar
function e_CreateToolBarTimeLine()
	NirMan:AddTool("DataEditor/icons/timeline/fit_horz.png", "e_TimeLine_FitHor()", PX2_LM:GetValue("FitHor"), 0)
	NirMan:AddTool("DataEditor/icons/timeline/fit_vert.png", "e_TimeLine_FitVer()", PX2_LM:GetValue("FitVer"), 0)
	NirMan:AddTool("DataEditor/icons/timeline/fit_all.png", "e_TimeLine_FitAll()", PX2_LM:GetValue("FitAll"), 0)
	NirMan:AddTool("DataEditor/icons/timeline/fit_select.png", "e_TimeLine_FitSelected()", PX2_LM:GetValue("FitSelected"), 0)
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/timeline/pan.png", "e_TimeLine_Pan()", PX2_LM:GetValue("Pan"), 2)
	NirMan:AddTool("DataEditor/icons/timeline/zoom.png", "e_TimeLine_Zoom()", PX2_LM:GetValue("Zoom"), 2)
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/timeline/curve_auto.png", "e_TimeLine_Auto()", PX2_LM:GetValue("Curve_Auto"), 2)
	NirMan:AddTool("DataEditor/icons/timeline/curve_clamped.png", "e_TimeLine_Clamped()", PX2_LM:GetValue("Curve_Clamped"), 2)
	NirMan:AddTool("DataEditor/icons/timeline/curve_user.png", "e_TimeLine_User()", PX2_LM:GetValue("Curve_User"), 2)
	NirMan:AddTool("DataEditor/icons/timeline/curve_break.png", "e_TimeLine_Break()", PX2_LM:GetValue("Curve_Break"), 2)
	NirMan:AddTool("DataEditor/icons/timeline/curve_linear.png", "e_TimeLine_Linear()", PX2_LM:GetValue("Curve_Linear"), 2)
	NirMan:AddTool("DataEditor/icons/timeline/curve_constant.png", "e_TimeLine_Constant()", PX2_LM:GetValue("Curve_Constant"), 2)
	--NirMan:AddToolSeparater()
	--NirMan:AddTool("DataEditor/icons/timeline/curve_flattentangentstoaxis.png", "e_ResView_Refresh()", PX2_LM:GetValue("Curve_Constant"))
	--NirMan:AddTool("DataEditor/icons/timeline/curve_straightentangents.png", "e_ResView_Refresh()", PX2_LM:GetValue("Curve_Constant"))
	--NirMan:AddTool("DataEditor/icons/timeline/curve_showallctrls.png", "e_ResView_Refresh()", PX2_LM:GetValue("Curve_Constant"))
end

--insp view toolbar
function e_createTooBarInsp()
	NirMan:AddTool("DataEditor/icons/insp/grid.png", "e_InspView_ChangeWindow(1)")
	NirMan:AddTool("DataEditor/icons/insp/panes.png", "e_InspView_ChangeWindow(2)")
end