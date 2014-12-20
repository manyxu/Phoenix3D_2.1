/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Mtls.hpp
*
* 版本		:	1.0 (2011/05/22)
*
* 作者		：	more
*
*/

#ifndef PX2MTLS_HPP
#define PX2MTLS_HPP

#include "PX2MaxToPX2PluginPre.hpp"

class Mtl;

class Mtls
{
public:
	Mtls ();

	bool Add (Mtl *mtl);
	void SetQuantity (int quantity);
	int GetQuantity () const;
	int GetIndex (Mtl *mtl) const;
	Mtl *GetMtl (int mtlIndex) const;

private:
	std::vector<Mtl*> mMaterial;
};

#endif