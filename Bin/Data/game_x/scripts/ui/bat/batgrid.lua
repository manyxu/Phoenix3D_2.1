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
BGO.GeoObj = nil

function BGO:New(o)
	o = o or {}
	setmetatable(o, self)
	self.__index = self
	return o
end

gNumGridRow = 5
gNumGridCol = 6
gBGOSize = gProjWidth/gNumGridCol
gBGOSizeHalf = gBGOSize/2.0


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
			bgo.OriginPos = APoint(gBGOSizeHalf + j*gBGOSize, 0.0, gBGOSizeHalf + i*gBGOSize)
			table.insert(BatGrid.BGOS, 1, bgo)
			
			bgo.GeoObj = PX2_CREATER:CreateSphere(nil, bgo.OriginPos, false, false, true)
			self.GridFrame:AttachChild(bgo.GeoObj)
			bgo.GeoObj.LocalTransform:SetUniformScale(50.0)
			bgo.GeoObj.LocalTransform:SetTranslate(bgo.OriginPos)
		end
	end
end