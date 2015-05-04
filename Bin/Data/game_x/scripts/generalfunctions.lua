-- functions.lua

function PlaySmallCtrl(uiObj)
	local bigCtrl = uiObj:GetControllerByName("BigCtrl");
	if nil~=bigCtrl then
		uiObj:DetachController(bigCtrl)
	end	
	
	local smallCtrl = uiObj:GetControllerByName("SmallCtrl")
	if nil==smallCtrl then
		smallCtrl = InterpCurveUniformScaleController:New("SmallCtrl")
		smallCtrl:Clear()
		smallCtrl:AddPoint(0.0, 1.0, ICM_CURVE_AUTO)
		smallCtrl:AddPoint(0.06, 0.95, ICM_CURVE_AUTO)
		uiObj:AttachController(smallCtrl)
	end
	
	smallCtrl:ResetPlay()
end

function PlayBigCtrl(uiObj)
	local smallCtrl = uiObj:GetControllerByName("SmallCtrl");
	if nil~=smallCtrl then
		uiObj:DetachController(smallCtrl)
	end	
	
	local bigCtrl = uiObj:GetControllerByName("BigCtrl")
	if nil==bigCtrl then
		bigCtrl = InterpCurveUniformScaleController:New("BigCtrl")
		bigCtrl:Clear()
		bigCtrl:AddPoint(0.0, 0.95, ICM_CURVE_AUTO)
		bigCtrl:AddPoint(0.06, 1.0, ICM_CURVE_AUTO)
		uiObj:AttachController(bigCtrl)
	end
	
	bigCtrl:ResetPlay()
end