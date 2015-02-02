-- pre.lua

--main tool bar
function e_CreateToolBarMain()
	NirMan:AddTool("DataEditor/icons/file/proj_new.png", "e_SetEditMode_Scene")
	NirMan:AddTool("DataEditor/icons/file/proj_open.png", "e_SetEditMode_Terrain")
	NirMan:AddTool("DataEditor/icons/file/proj_save.png", "e_SetEditMode_UI")
	NirMan:AddTool("DataEditor/icons/file/proj_saveas.png", "e_SetEditMode_UI")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/file/scene_new.png", "e_SetEditMode_Scene")
	NirMan:AddTool("DataEditor/icons/file/scene_open.png", "e_SetEditMode_Terrain")
	NirMan:AddTool("DataEditor/icons/file/scene_save.png", "e_SetEditMode_UI")
	NirMan:AddTool("DataEditor/icons/file/scene_saveas.png", "e_SetEditMode_UI")
end

-- scene view toolbar
function e_CreateToolBarSceneUI()
	NirMan:AddTool("DataEditor/icons/edittype/sceneedit.png", "e_SetEditMode_Scene")
	NirMan:AddTool("DataEditor/icons/edittype/terrainedit.png", "e_SetEditMode_Terrain")
	NirMan:AddTool("DataEditor/icons/edittype/uiedit.png", "e_SetEditMode_UI")
	NirMan:AddToolSeparater()
	NirMan:AddTool("DataEditor/icons/edittype/simulate.png", "e_SetEditMode_UI")
	NirMan:AddTool("DataEditor/icons/edittype/play.png", "e_SetEditMode_UI")
end

function e_SetEditMode_Scene()
end

function e_SetEditMode_Terrain()
end

function e_SetEditMode_UI()
end