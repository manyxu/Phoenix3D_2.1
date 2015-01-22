// PX2Componable.hpp

#ifndef PX2COMPONABLE_HPP
#define PX2COMPONABLE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Object.hpp"
#include "PX2Component.hpp"

namespace PX2
{

	class Componable : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_IDS;
		PX2_DECLARE_STREAM(Componable);

	public:
		Componable();
		virtual ~Componable();

		// Component
	public:
		int GetNumComponents() const;
		Component *GetComponent(int i) const;
		Component *GetComponentByName(const std::string &name) const;
		bool IsHasComponent(Component* component);
		void AttachComponent(Component* component);
		void DetachComponent(Component* component);
		void DetachAllComponents();
		void SortComponents(); // 按照优先级从大到小排序

	protected:
		bool UpdateComponents(double applicationTime);

		std::vector<ComponentPtr> mComponents;
	};

#include "PX2Componable.inl"
	PX2_REGISTER_STREAM(Componable);
	typedef Pointer0<Componable> ComponablePtr;

}

#endif