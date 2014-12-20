/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2MtlTree.hpp
*
* 版本		:	1.0 (2011/05/22)
*
* 作者		：	more
*
*/

#ifndef PX2MTLTREE_HPP
#define PX2MTLTREE_HPP

#include "PX2Shine.hpp"
#include "PX2MaterialInstance.hpp"

class MtlTree
{
public:
	MtlTree (PX2::Shine *shine=0);

	// 材质树
	void SetMChildQuantity (int quantity);
	int GetMChildQuantity () const;
	void SetShine (PX2::Shine *shine);
	PX2::Shine *GetShine ();
	MtlTree &GetMChild (int i);

	// 贴图树
	void SetMaterialInstance (PX2::MaterialInstance *mi);
	PX2::MaterialInstance *GetMaterialInstance ();

private:
	PX2::ShinePtr mShine;
	PX2::MaterialInstancePtr mMaterialInstance;
	std::vector<MtlTree> mMChild;
};

#endif