/*
*
* 文件名称	：	PX2ExportSettings.cpp
*
*/

#include "PX2ExportSettings.hpp"

//----------------------------------------------------------------------------
ExportSettings::ExportSettings ()
{
	// object 设置
	IncludeObjects = true;
	IncludeLights = true;
	IncludeMeshes = true;

	// mesh 设置
	IncludeVertexColors = false;
	IncludeNormals = true;
	IncludeTargentBiNormal = false;
	IncludeTexCoords = true;
	NumTexCoords = 1;

	IsUseSingleTex = false;

	// modifier 设置    
	IncludeModifiers = true;
	IncludeSkins = true;

	// animation 设置
	IncludeCurrentFrame = true;
	IncludeKeyFrames = false;
	IncludeAllFrames = false;
	UseLocalTime = true;
	StartFrame = 0;
	EndFrame = 0;

	memset(SrcRootDir, 0, 256);
	memset(DstRootDir, 0, 256);
}
//----------------------------------------------------------------------------