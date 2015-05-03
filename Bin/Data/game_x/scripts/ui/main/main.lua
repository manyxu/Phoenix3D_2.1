-- main.lua

function onBut_Enter()
	local name = this:GetName()
	if arg0 == UICT_PRESSED then
		playSmallCtrl(this)
	elseif arg0 == UICT_RELEASED then
		playBigCtlr(this)
		
		--onUIBat()
		
		PX2_ENGINELOOP:FireEventGeneralString("ToBat")
	elseif arg0 == UICT_RELEASED_NOTVALIED then
		playBigCtlr(this)
	end
end

function onUIBat()
	PX2_PROJ:GetUIFrame():DetachAllChildren()
end