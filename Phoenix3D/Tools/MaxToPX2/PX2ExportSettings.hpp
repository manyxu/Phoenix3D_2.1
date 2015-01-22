/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2ExportSettings.hpp
*
* 版本		:	1.0 (2011/05/22)
*
* 作者		：	more
*
*/

#ifndef PX2EXPORTSETTINGS_HPP
#define PX2EXPORTSETTINGS_HPP

#include "PX2MaxToPX2PluginPre.hpp"

class ExportSettings
{
public:
	ExportSettings ();

	// object 设置
	bool IncludeObjects;
	bool IncludeLights;
	bool IncludeMeshes;

	// mesh 设置
	bool IncludeVertexColors; 
	bool IncludeNormals;
	bool IncludeTargentBiNormal;
	bool IncludeTexCoords;
	int NumTexCoords;

	bool IsUseSingleTex;

	// modifier 设置
	bool IncludeModifiers;
	bool IncludeSkins;

	// animation 设置
	bool IncludeCurrentFrame;
	bool IncludeKeyFrames;
	bool IncludeAllFrames;
	bool UseLocalTime;
	int StartFrame;
	int EndFrame;

	// 目录
	char SrcRootDir[255];
	char DstRootDir[255];
};

#endif