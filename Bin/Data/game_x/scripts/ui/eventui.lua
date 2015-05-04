-- eventui.lua

function OnEventGeneralStringUI(eventStr)
	if "ToBat"==eventStr then
		OnUIBat()
	end
end