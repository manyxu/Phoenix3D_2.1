// PX2UIManager.hpp

#ifndef PX2UIMANAGER_HPP
#define PX2UIMANAGER_HPP

#include "PX2Object.hpp"
#include "PX2Singleton_NeedNew.hpp"
#include "PX2UIView.hpp"

namespace PX2
{

	class UIManager : public Object, public Singleton<UIManager>
	{
	public:
		UIManager();
		virtual ~UIManager();

		void Clear();
		void Update(double appSeconds, double elapsedSeconds);

		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;

	protected:
		Sizef mSize;

		// UIView
	public:
		UIView *GetDefaultUIView();

		bool IsHasUIView(const std::string &name) const;
		bool AddUIView(const std::string &name, UIView *view);
		bool RemoveUIView(const std::string &name);

	protected:
		UIViewPtr mDefaultUIView;
		std::map<std::string, UIViewPtr> mUIViews;
	};

#include "PX2UIManager.inl"
#define PX2_UIM UIManager::GetSingleton()

}

#endif