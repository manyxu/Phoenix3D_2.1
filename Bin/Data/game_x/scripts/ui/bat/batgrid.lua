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

function BGO.New(o)
	o = o or {} -- create object if user does not provide one
	setmetatable(o, self)
	self.__index = self
	return o
end

BatGrid = {}

function BatGrid.Rew()

end

function BatGrid.Reset()

end