-- eventui.lua

function onEventGeneralStringUI(eventStr)
	if "ToBat"==eventStr then
		onUIBat()
	end
end