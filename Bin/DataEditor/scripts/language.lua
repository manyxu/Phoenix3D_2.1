-- language.lua

function AddLanguages()
	-- 主菜单
	PX2_LM:AddItem1("File", "文件")
	PX2_LM:AddItem1("NewProject", "新建工程")
	PX2_LM:AddItem1("NewScene", "新建场景")
	PX2_LM:AddItem1("Open", "打开")
	PX2_LM:AddItem1("OpenProject", "打开工程")
	PX2_LM:AddItem1("Save", "保存")
	PX2_LM:AddItem1("SaveAs", "另存为")
	PX2_LM:AddItem1("Close", "关闭")
	PX2_LM:AddItem1("Exit", "退出")
	--
	PX2_LM:AddItem1("Edit", "编辑")
	PX2_LM:AddItem1("Repeal", "撤销")
	PX2_LM:AddItem1("Repeat", "重复")
	PX2_LM:AddItem1("Copy", "复制")
	PX2_LM:AddItem1("Paste", "粘贴")
	PX2_LM:AddItem1("Delete", "删除")
	PX2_LM:AddItem1("ImportSelectedRes", "导入选择资源")
	PX2_LM:AddItem1("Import", "导入")
	PX2_LM:AddItem1("Export", "导出")
	PX2_LM:AddItem1("Select", "选择")
	PX2_LM:AddItem1("Translate", "位移")
	PX2_LM:AddItem1("Rotate", "旋转")
	PX2_LM:AddItem1("Scale", "缩放")
	PX2_LM:AddItem1("PlayAndStop", "播放/停止")
	PX2_LM:AddItem1("ResetPlay", "重置播放")	
	--
	PX2_LM:AddItem1("View", "视图")
	PX2_LM:AddItem1("Window", "窗口")
	PX2_LM:AddItem1("Stage", "舞台")
	
	PX2_LM:AddItem1("StageCenter", "舞台中心停靠")
	PX2_LM:AddItem1("PerspectiveCamera", "使用透视相机")
	PX2_LM:AddItem1("TopViewCamera", "使用顶视相机")
	--
	PX2_LM:AddItem1("Debug", "调试")
	PX2_LM:AddItem1("EditorSimulate", "编辑器中仿真")
	PX2_LM:AddItem1("EditorPlay", "编辑器中播放")
	PX2_LM:AddItem1("EditorStop", "停止")
	PX2_LM:AddItem1("WindowPlay", "弹出窗口播放")
	PX2_LM:AddItem1("PlayConfig", "播放配置")
	--
	PX2_LM:AddItem1("Tool", "工具")
	PX2_LM:AddItem1("VersionWindows", "生成版本信息_Windows")
	PX2_LM:AddItem1("VersionAndroid", "生成版本信息_Android")
	PX2_LM:AddItem1("VersionIOS", "生成版本信息_IOS")
	PX2_LM:AddItem1("Setting", "设置")
	
	PX2_LM:AddItem1("Help", "帮助")
	
	-- 编辑菜单
	PX2_LM:AddItem1("Create", "创建")
	PX2_LM:AddItem1("Add", "添加")
	PX2_LM:AddItem1("SceneActor", "场景角色")
	PX2_LM:AddItem1("UI", "界面")
	
	PX2_LM:AddItem1("ResetPlay", "重置播放")
	PX2_LM:AddItem1("Play", "播放")
	PX2_LM:AddItem1("Stop", "暂停")
	PX2_LM:AddItem1("Reset", "重置")
	
	PX2_LM:AddItem1("FindInSceneTree", "在工程树中查找")
	PX2_LM:AddItem1("FindInResTree", "在资源树中查找")
	
	PX2_LM:AddItem1("Node", "节点")
	PX2_LM:AddItem1("Geometry", "几何体")
	PX2_LM:AddItem1("RectPiece", "面片")
	PX2_LM:AddItem1("Box", "正方体")
	PX2_LM:AddItem1("Sphere", "球")
	PX2_LM:AddItem1("Object", "物件")
	PX2_LM:AddItem1("Character", "角色")
	PX2_LM:AddItem1("Effect", "特效")
	PX2_LM:AddItem1("Trigger", "触发器")
	PX2_LM:AddItem1("AmbientRegion", "环境")
	PX2_LM:AddItem1("Sound", "声音")
	PX2_LM:AddItem1("Particles", "粒子")
	PX2_LM:AddItem1("Billboard", "公告板")
	PX2_LM:AddItem1("Beam", "波带")
	PX2_LM:AddItem1("Robbion", "条带")
	PX2_LM:AddItem1("Soundable", "声音")
	PX2_LM:AddItem1("UIPicBox", "图片")
	PX2_LM:AddItem1("UITest", "文本")
	PX2_LM:AddItem1("UIFrame", "层")
	PX2_LM:AddItem1("UIRelativeFrame", "关联层")
	PX2_LM:AddItem1("UIButton", "按钮")
	PX2_LM:AddItem1("UICheckButton", "选择框")
	PX2_LM:AddItem1("UIEditBox", "编辑框")
	PX2_LM:AddItem1("UIProgressBar", "进度条")
	
	-- 视图
	PX2_LM:AddItem1("Project", "工程")
	PX2_LM:AddItem1("Scene", "场景")
	PX2_LM:AddItem1("TimeLine", "时间线")
	PX2_LM:AddItem1("Stage", "舞台")
	PX2_LM:AddItem1("ResView", "资源")
	PX2_LM:AddItem1("InspView", "检视")
	
	PX2_LM:AddItem1("StartView", "起始页")
	PX2_LM:AddItem1("UIView", "界面")
	PX2_LM:AddItem1("LogicView", "逻辑")
	PX2_LM:AddItem1("ConsoleView", "控制台")
	PX2_LM:AddItem1("PreView", "预览")
	
	-- ProjView
	PX2_LM:AddItem1("pv_Project", "工程(Project)")
	PX2_LM:AddItem1("pv_Scene", "场景(Scene)")
	PX2_LM:AddItem1("pv_UI", "界面(UI)")
	PX2_LM:AddItem1("pv_Logic", "逻辑(Logic)")
	PX2_LM:AddItem1("pv_Camera", "像机(Camera)")
	PX2_LM:AddItem1("pv_Sky", "天空(Sky)")
	PX2_LM:AddItem1("pv_Terrain", "地形(Terrain)")
	PX2_LM:AddItem1("pv_Character", "角色(Character)")
	PX2_LM:AddItem1("pv_Object", "物件(Object)")
	PX2_LM:AddItem1("pv_Effect", "特效(Effect)")
	PX2_LM:AddItem1("pv_Sound", "音效(Sound)")
	PX2_LM:AddItem1("pv_Trigger", "触发(Trigger)")
	PX2_LM:AddItem1("pv_AmbientRegion", "环境(Ambient)")
	
	-- ResView
	PX2_LM:AddItem1("CopyResPath", "拷贝资源路径到剪贴簿")
	
	-- 一般
	PX2_LM:AddItem1("Name", "名称")
	PX2_LM:AddItem1("Ge", "个")
	PX2_LM:AddItem1("Use", "用")
	
	-- Notice
	PX2_LM:AddItem1("Notice", "注意")
	PX2_LM:AddItem("Tip0", "必须选择父节点！", "You must select a parent node to add!")
	PX2_LM:AddItem("Tip1", "父节点必须是Node！", "Parent must be a node!")
	PX2_LM:AddItem("Tip3", "必须选择1个导出物件！", "You must select a object to export!")
	PX2_LM:AddItem("Tip4", "工程已经存在！", "Project is already exist!")
	
	--编辑器
	PX2_LM:AddItem("WelcomeToEditor", "欢迎使用Phoenix3D编辑器!", "Welcome to Phoenix3D editor!")
	PX2_LM:AddItem("CurSelObj", "当前选择对象: ", "CurrentSelect: ")
	PX2_LM:AddItem("CurSelRes", "当前选择资源: ", "CurrentSelectRes: ")
	PX2_LM:AddItem("PickingPos", "正在点选位置: ", "PickingPos: ")
	PX2_LM:AddItem("CurSelObjNull", "当前选择对象: (空)", "CurrentSelect: (null)")
	PX2_LM:AddItem("CurSelResNull", "当前选择资源: (空)", "CurrentSelectRes: (null)")
	PX2_LM:AddItem("PickingPosNull", "正在点选位置: (0,0,0)", "PickingPos: (0,0,0)")
	
	-- 编辑器TabBar
	PX2_LM:AddItem1("PinPage", "弹出页")
	PX2_LM:AddItem1("PinPages", "弹出页组")
end

AddLanguages()
