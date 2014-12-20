/*
*
* 文件名称	：	PX2UIFrame.hpp
*
*/

#ifndef PX2UIFRAME_HPP
#define PX2UIFRAME_HPP

#include "PX2UIPre.hpp"
#include "PX2Node.hpp"
#include "PX2Camera.hpp"
#include "PX2Event.hpp"
#include "PX2UICallback.hpp"

namespace PX2
{

	class UIPicBox;

	class UIFrame : public Node
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIFrame);

	public:
		UIFrame ();
		virtual ~UIFrame ();

		// 停靠
	public:
		enum LayType
		{
			LT_ZERO,
			LT_HALF,
			LT_ONE,
			LT_MAX_TYPE
		};
		void SetUseLayType (bool isUse);
		bool IsUseLayType () const;
		void SetHLayType (LayType type);
		LayType GetHLayType () const;
		void SetHLayValue (float val);
		float GetHLayValue () const;
		void SetVLayType (LayType type);
		LayType GetVLayType () const;
		void SetVLayValue (float val);
		float GetVLayValue () const;
		void AdjustLayType();

	protected:
		bool mIsUseLayType;
		LayType mHLayType;
		float mHLayValue;
		LayType mVLayType;
		float mVLayValue;
		bool mIsLayTypeChanged;

		// 操作
	public:
		virtual void Enable (bool enable); // 设置是否处理事件,一般动态设置，用来屏蔽需要屏蔽的响应
		bool IsEnable () const;

		// 层级（子节点）
	public:
		virtual int AttachChild (Movable* child);

		// 脚本
	public:
		void SetUserScriptName(const std::string &scriptName);
		const std::string &GetUserScriptName () const;
		const std::string &GetScriptName () const;
		void SetScriptHandler (const std::string &handler);
		const std::string &GetScriptHandler () const;

		bool RegistToScriptSystem ();
		bool UnRegistToScriptSystem ();
		bool IsRegistedToScriptSystem ();

		// 事件
	public:
		void SetUICallback (UICallback callback);
		UICallback GetUICallback () const;

		virtual void OnEvent (Event *event);

public_internal:
		// info为1表示Pressed，为2表示Released
		virtual void OnChildPicked (int info, Movable *child);
		virtual void OnChildUIAfterPicked(int info, Movable *child);

	protected:
		virtual void UpdateWorldData (double applicationTime);
		void CallString (const char *fun, const char *format="", ...);
		
		bool mIsEnable;
		std::string mScriptHandler;
		UICallback mUICallback;

		std::string mScriptName;
		std::string mUserScriptName;
	};

	PX2_REGISTER_STREAM(UIFrame);
	typedef Pointer0<UIFrame> UIFramePtr;
#include "PX2UIFrame.inl"

}

#endif