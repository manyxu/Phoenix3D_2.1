/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2Node.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2NODE_HPP
#define PX2NODE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Movable.hpp"
#include "PX2Culler.hpp"

namespace PX2
{

	
	/// 场景节点类
	/**
	* 该类实现“父亲-孩子”机制，用来组织场景的构建。从该类可以派生不同的类如：
	* BspNode，SwitchNode等，实现不同的场景组织方式。
	*/
	class Node : public Movable
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Node);

	public:
		Node ();
		virtual ~Node ();

		virtual void Play ();
		virtual bool IsPlaying () const;
		virtual void Stop ();
		virtual void Reset ();

		/// 获得孩子数量
		int GetNumChildren () const;
		int GetNumValidChildren () const;

		/// 添加孩子节点
		/** 
		* 如果操作成功，返回孩子在孩子列表中的索引号。
		* 在有些引擎的场景图系统系统中，一个节点可以有多个父亲，这样的场景图是
		* 一个有向无环图（DGA）。在这样情况下，父亲孩子的关系不是树的关系。因此
		* ，你要为节点找个新“父亲”时，你要先解除与旧的“父子关系”，你必须先
		* DetachChild掉节点，然后另外一个“父亲”AttachChild此节点。
		*	当你在DetachChild的时候，当心孩子节点的“自析构self-destruct”。如果
		* 你不想这样的情况发生的话，把这个孩子挂到一个smart指针上。
		*	举例：
		*	Node* pkNode0 = PX2_NEW Node;
		*	Movable* pkChild0 = <...>;
		*	pkNode0->AttachChild(pkChild0);  // child at index 0
		*	Node* pkNode1 = <...>;
		*
		*	// 这里会出现一个assert，因为pkChild0已经有一个父亲节点pkNode0。
		*	pkNode1->AttachChild(pkChild0);
		*	
		*	// 为了防止“自析构self-destruct”，你必须把孩子挂到一个smart指针上。
		*	MovablePtr spkSaveChild = pkNode0->GetChild(0);
		*	pkNode0->DetachChild(spkSaveChild);
		*	pkNode1->AttachChild(spkSaveChild);
		*/
		virtual int AttachChild (Movable* child);

		void InsertChild (Movable *before, Movable *child);

		/// 从父亲节点中去除child
		/**
		* 如果'child'非空，返回child在孩子数组中的索引。否则返回-1。
		*/
		virtual int DetachChild (Movable* child);

		virtual bool DetachChildByName (const std::string &name);

		/// 从父亲节点中去除索引为i的child
		/**
		* 如果0 <= i < GetNumChildren()返回在i处孩子的指针，否则返回null。
		*/
		virtual MovablePtr DetachChildAt (int i);

		virtual void DetachAllChildren ();

		/// 设置索引为i处的孩子节点
		/**
		* 如果0 <= i < GetNumChildren()，返回之前在i处的孩子节点指针。如果i超出
		* 范围， 将孩子添加到孩子列表末尾，并返回null。
		*/
		virtual MovablePtr SetChild (int i, Movable* child);

		/// 获得索引为i处的孩子节点
		/**
		* 如果0 <= i < GetNumChildren()，返回在i处孩子的指针。如果超出范围，返
		* 回null。
		*/
		virtual MovablePtr GetChild (int i);
		virtual MovablePtr GetChildByName (const std::string &name);

		virtual void SetAlpha (float alpha);
		virtual void SetColor (const Float3 &color);
		virtual void SetBrightness (float brightness);
		
		void SetDoPickPriority (bool doPickPriority); // 一般用来为Node设置
		bool IsDoPickPriority () const;
		virtual void OnNotPicked (int pickInfo);

		void SetNeedCalUpdateChild (bool needCal);
		bool IsNeedCalUpdateChild () const;

		void SetAnchorID (int anchorID);
		int GetAnchorID () const;

	protected:
		// 几何图形更新
		virtual void UpdateWorldData (double applicationTime);
		virtual void UpdateWorldBound ();

		// 场景继承裁剪
		virtual void GetVisibleSet (Culler& culler, bool noCull);

		// 孩子列表
		std::vector<MovablePtr> mChild;

		int mAnchorID;
		
		std::vector<Movable*> mUpdateChild;
		bool mIsNeedCalUpdateChild;

		bool mIsDoPickPriority;
	};

	PX2_REGISTER_STREAM(Node);
	typedef Pointer0<Node> NodePtr;
#include "PX2Node.inl"

}

#endif
