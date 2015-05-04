-- main.lua

function OnBut_Enter()
	local name = this:GetName()
	if arg0 == UICT_PRESSED then
		PlaySmallCtrl(this)
	elseif arg0 == UICT_RELEASED then
		PlayBigCtrl(this)
		PX2_ENGINELOOP:FireEventGeneralString("ToBat")
	elseif arg0 == UICT_RELEASED_NOTVALIED then
		PlayBigCtrl(this)
	end
end