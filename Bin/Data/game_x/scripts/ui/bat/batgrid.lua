-- batgrid.lua

-- bat grid object
BGO = {}
BGO.Type = 0
BGO.IsDowning = false
BGO.DowningSpeed = 0.0
BGO.IndexX = 0
BGO.IndexZ = 0
BGO.OriginPos = APoint.ORIGIN
BGO.CurPos = APoint.ORIGIN
BGO.Alpha = 0.0
BGO.Lightness = 1.0
BGO.IsSplittedVisited = false

function BGO:New(o)
	o = o or {}
	setmetatable(o, self)
	self.__index = self
	return o
end

gNumGridRow = 5
gNumGridCol = 6

BatGrid = {}
BatGrid.GridFrame = nil
BatGrid.BGOS = {}

function BatGrid:New()
	o = o or {}
	setmetatable(o, self)
	self.__index = self
	return o
end

function BatGrid:Reset()
	for i=0, gNumGridRow-1 do
		for j=0, gNumGridCol-1 do
			local bgo = BGO:New()
			bgo.OriginPos = APoint(i*100.0, 0.0, j*100.0)
			table.insert(BatGrid.BGOS, 1, bgo)
			
			local picBox = UIPicBox:New()	
			picBox.LocalTransform:SetTranslate(bgo.OriginPos)
			self.GridFrame:AttachChild(picBox)
		end
	end
end