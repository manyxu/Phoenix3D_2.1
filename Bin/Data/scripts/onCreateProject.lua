-- onCreateProject.lua
-- called after project res was created.

-- 发布		-------------------------------------------------------------
PX2_PROJ:SetPublish(false)

-- 初始化   -------------------------------------------------------------
PX2_RM:SetUseGarbageCollect(true)
gSM = ScriptManager:GetSingleton()

-- 声音 	-------------------------------------------------------------
PX2_SS:SetMaxNumPlaySameTime(4)
PX2_SS:SetPlaySameTimeRange(0.2)

-- 调试0	-------------------------------------------------------------
PX2_PROJ:SetShowProjectInfo(true)

-- 游戏		-------------------------------------------------------------