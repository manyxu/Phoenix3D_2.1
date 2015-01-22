-- language.lua

function AddLanguages()
	--文件菜单
	PX2_LM:AddItem1("File", "文件")
	PX2_LM:AddItem1("NewProject", "新建工程")
	PX2_LM:AddItem1("NewScene", "新建场景")
	PX2_LM:AddItem1("Open", "打开")
	PX2_LM:AddItem1("Save", "保存")
	PX2_LM:AddItem1("SaveAs", "另存为")
	PX2_LM:AddItem1("Close", "关闭")
	PX2_LM:AddItem1("Exit", "退出")
	--编辑菜单
	PX2_LM:AddItem1("Edit", "编辑")
	PX2_LM:AddItem1("Repeal", "撤销")
	PX2_LM:AddItem1("Repeat", "重复")
	PX2_LM:AddItem1("Copy", "复制")
	PX2_LM:AddItem1("Paste", "粘贴")
	PX2_LM:AddItem1("Delete", "删除")
	PX2_LM:AddItem1("Select", "选择")
	PX2_LM:AddItem1("Move", "移动")
	PX2_LM:AddItem1("Rotate", "旋转")
	PX2_LM:AddItem1("Scale", "缩放")
	PX2_LM:AddItem1("PlayAndStop", "播放/停止")
	PX2_LM:AddItem1("ResetPlay", "重置播放")	
	--视图菜单
	PX2_LM:AddItem1("View", "视图")
	PX2_LM:AddItem1("Window", "窗口")
	PX2_LM:AddItem1("Stage", "舞台")
	
	PX2_LM:AddItem1("StageCenter", "舞台中心停靠")
	PX2_LM:AddItem1("PerspectiveCamera", "使用透视相机")
	PX2_LM:AddItem1("TopViewCamera", "使用顶视相机")
	--调试菜单
	PX2_LM:AddItem1("Debug", "调试")
	PX2_LM:AddItem1("EditorSimulate", "在编辑器中模拟")
	PX2_LM:AddItem1("EditorPlay", "编辑器中播放")
	PX2_LM:AddItem1("Operation", "运行")
	PX2_LM:AddItem1("PlayConfig", "播放配置")
	--工具菜单
	PX2_LM:AddItem1("Tool", "工具")
	PX2_LM:AddItem1("VersionWindows", "生成版本信息_Windows")
	PX2_LM:AddItem1("VersionAndroid", "生成版本信息_Android")
	PX2_LM:AddItem1("VersionIOS", "生成版本信息_IOS")
	
	PX2_LM:AddItem1("Help", "帮助")
end