/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2CameraNode.hpp
*
* 版本		:	1.0 (2011/04/07)
*
* 作者		：	more
*
*/

#ifndef PX2CAMERANODE_HPP
#define PX2CAMERANODE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Camera.hpp"
#include "PX2Node.hpp"

namespace PX2
{

	/// 像机节点类
	/**
	* Node的世界变换被用作Camera的空间方位。Node的世界旋转矩阵被用作Camera的坐
	* 标轴方向。世界变换的第0列是像机的方向（direction）向量，第1列是像机的上
	* （up）向量，第2列是像机的右（right）向量。
	*/
	class CameraNode : public Node
	{
	public:
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(CameraNode);

	public:
		/// 构造函数
		/**
		* 在构造函数中，像机的当前坐标系统被作为Node的本地变换。
		* local translation		  = camera location
		* local rotation column 0 = camera direction
		* local rotation column 1 = camera up
		* local rotation column 2 = camera right
		*/
		CameraNode (Camera* camera = 0);
		virtual ~CameraNode ();

		/// 设置像机
		/**
		* 像机的当前坐标系统被设置为Node的本地变换。Node世界变换被
		* UpdateWorldData更新计算，像机的坐标系统被设置为Node世界变换。
		*/
		void SetCamera (Camera* camera);

		Camera* GetCamera ();
		const Camera* GetCamera () const;

		void EnableUpdate (bool enable);
		bool IsEnableUpdate ();

	protected:
		virtual void UpdateWorldData (double applicationTime);

		CameraPtr mCamera;
		bool mEnableUpdate;
	};

	PX2_REGISTER_STREAM(CameraNode);
	typedef Pointer0<CameraNode> CameraNodePtr;
#include "PX2CameraNode.inl"


}

#endif
