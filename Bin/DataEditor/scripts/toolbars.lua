-- toolbars.lua

--main tool bar
function e_CreateToolBarMain()
	NirMan:AddTool("DataEditor/icons/file/proj_new.png", "e_OnNewProject")
	NirMan:AddTool("DataEditor/icons/file/proj_open.png", "e_OnOpenProject")
	NirMan:AddTool("DataEditor/icons/file/proj_save.png", "e_OnSaveProject")
	NirMan:AddTool("DataEditor/icons/file/proj_saveas.png", "e_OnSaveAsProject")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/file/scene_new.png", "e_OnNewScene")
	NirMan:AddTool("DataEditor/icons/file/scene_open.png", "e_OnOpenScene")
	NirMan:AddTool("DataEditor/icons/file/scene_save.png", "e_OnSaveScene")
	NirMan:AddTool("DataEditor/icons/file/scene_saveas.png", "e_OnSaveAsScene")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/edittype/playinwindow.png", "e_SetEditMode_UI")
end

-- scene view toolbar
function e_CreateToolBarSceneUI()
	NirMan:AddTool("DataEditor/icons/edittype/sceneedit.png", "e_SetEditMode_Scene")
	NirMan:AddTool("DataEditor/icons/edittype/terrainedit.png", "e_SetEditMode_Terrain")
	NirMan:AddTool("DataEditor/icons/edittype/uiedit.png", "e_SetEditMode_UI")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/editmode/translate.png", "e_SetEditMode_UI")
	NirMan:AddTool("DataEditor/icons/editmode/rotate.png", "e_SetEditMode_UI")
	NirMan:AddTool("DataEditor/icons/editmode/scale.png", "e_SetEditMode_UI")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/edittype/simulate.png", "e_SetEditMode_UI")
	NirMan:AddTool("DataEditor/icons/edittype/play.png", "e_SetEditMode_UI")
end