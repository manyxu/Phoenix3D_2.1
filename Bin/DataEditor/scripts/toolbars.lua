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
	NirMan:AddTool("DataEditor/icons/edittype/sceneedit.png", "e_SetEditMode_Scene()")
	NirMan:AddTool("DataEditor/icons/edittype/terrainedit.png", "e_SetEditMode_Terrain()")
	NirMan:AddTool("DataEditor/icons/edittype/uiedit.png", "e_SetEditMode_UI()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/editmode/translate.png", "e_OnTranslate()")
	NirMan:AddTool("DataEditor/icons/editmode/rotate.png", "e_OnRotate()")
	NirMan:AddTool("DataEditor/icons/editmode/scale.png", "e_OnScale()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/edittype/simulate.png", "e_SetEditMode_UI()")
	NirMan:AddTool("DataEditor/icons/edittype/play.png", "e_SetEditMode_UI()")
end

-- project view toolbar
function e_CreateTooBarProject()
	NirMan:AddTool("DataEditor/icons/projview/general.png", "e_ProjectView_Detail_General()")
	NirMan:AddTool("DataEditor/icons/projview/children.png", "e_ProjectView_Detail_Children()")
	NirMan:AddTool("DataEditor/icons/projview/ctrl.png", "e_ProjectView_Detail_Controls()")
	NirMan:AddTool("DataEditor/icons/projview/mtl.png", "e_ProjectView_Detail_Materials()")
	NirMan:AddTool("DataEditor/icons/projview/detail.png", "e_ProjectView_Detail_Details()")
end

-- res view toolbar
function e_CreateTooBarRes()
	NirMan:AddTool("DataEditor/icons/resview/res_refresh.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/resview/res_clear.png", "e_ResView_Clear()")
	NirMan:AddToolSeparater()
end

-- timeline toolbar
function e_CreateToolBarTimeLine()
	NirMan:AddTool("DataEditor/icons/timeline/fit_horz.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/fit_vert.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/fit_all.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/fit_select.png", "e_ResView_Refresh()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/timeline/pan.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/zoom.png", "e_ResView_Refresh()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/timeline/curve_auto.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_clamped.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_user.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_break.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_linear.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_constant.png", "e_ResView_Refresh()")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/timeline/curve_flattentangentstoaxis.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_straightentangents.png", "e_ResView_Refresh()")
	NirMan:AddTool("DataEditor/icons/timeline/curve_showallctrls.png", "e_ResView_Refresh()")
end

--insp view toolbar
function e_createTooBarInsp()
	NirMan:AddTool("DataEditor/icons/resview/res_refresh.png", "e_InspView_ChangeWindow(1)")
	NirMan:AddTool("DataEditor/icons/resview/res_clear.png", "e_InspView_ChangeWindow(2)")
end