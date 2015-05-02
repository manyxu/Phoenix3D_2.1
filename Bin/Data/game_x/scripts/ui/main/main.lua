-- main.lua

function onBut_Enter()
	local name = this:GetName()
	if arg0 == UICT_PRESSED then
		playSmallCtrl(this)
	elseif arg0 == UICT_RELEASED then
		playBigCtlr(this)
	elseif arg0 == UICT_RELEASED_NOTVALIED then
		playBigCtlr(this)
	end
end