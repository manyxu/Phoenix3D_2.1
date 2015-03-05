// PX2ActorInspector.cpp

#include "PX2ObjectPropertyGrid.hpp"
#include "PX2LanguageManager.hpp"
#include "PX2MovableTransProperty.hpp"
#include "PX2EditEventType.hpp"
#include "PX2InterpCurve.hpp"
#include "PX2EMFloatProperty.hpp"
#include "PX2EMFloatRangeProperty.hpp"
#include "PX2EMFloat3Property.hpp"
#include "PX2EMFloat3RangeProperty.hpp"
#include "PX2ResourceManager.hpp"
#include "PX2NirvanaEventType.hpp"
#include "PX2Edit.hpp"
using namespace PX2Editor;
using namespace PX2;

IMPLEMENT_DYNAMIC_CLASS(ObjectPropertyGrid, wxWindow)
BEGIN_EVENT_TABLE(ObjectPropertyGrid, wxWindow)
EVT_SIZE(ObjectPropertyGrid::OnSize)
EVT_MOVE(ObjectPropertyGrid::OnMove)
EVT_PG_CHANGED(wxID_ANY, ObjectPropertyGrid::OnPropertyGridChange)
END_EVENT_TABLE()
//-----------------------------------------------------------------------------
ObjectPropertyGrid::ObjectPropertyGrid()
{
}
//-----------------------------------------------------------------------------
ObjectPropertyGrid::ObjectPropertyGrid(wxWindow *parent)
:
PropertyGrid(parent)
{
}
//-----------------------------------------------------------------------------
ObjectPropertyGrid::~ObjectPropertyGrid()
{
}
//-----------------------------------------------------------------------------
void ObjectPropertyGrid::SetObject(PX2::Object *actor)
{
	mObject = actor;

	if (!mObject)
	{
		Clear();
		return;
	}

	OnSetObject(actor);
}
//-----------------------------------------------------------------------------
void StringButCallback(Property *p)
{
	const SelectResData &data = PX2_EDIT.GetSelectedResource();
	SelectResData::SelectResType selectResType = data.GetSelectResType();

	if (data.ResPathname.empty()) return;

	if (SelectResData::RT_NORMAL == selectResType)
	{
		p->SetValue(data.ResPathname);
	}
	else if (SelectResData::RT_TEXPACKELEMENT == selectResType)
	{
		const TexPack &texPack = PX2_RM.GetTexPack(data.ResPathname);

		if (texPack.IsValid())
		{
			p->SetValue(data.EleName);
		}
		else if (PX2_RM.AddTexPack(data.ResPathname))
		{
			p->SetValue(data.EleName);
		}
	}
}
//-----------------------------------------------------------------------------
void ObjectPropertyGrid::OnSetObject(PX2::Object *actor)
{
	PX2_UNUSED(actor);
	RemoveAll();
	Refresh();

	Object *obj = mObject;
	if (!obj)
		return;

	obj->RemoveAllProperties();
	obj->RegistProperties();

	const std::vector<Object::PropertyObject> &props = obj->GetProperties();

	std::vector<wxColour> textColors;
	textColors.push_back(wxColour(237, 28, 36));
	textColors.push_back(wxColour(255, 127, 39));
	textColors.push_back(wxColour(255, 242, 0));
	textColors.push_back(wxColour(34, 177, 76));
	textColors.push_back(wxColour(0, 162, 232));
	textColors.push_back(wxColour(63, 72, 204));
	textColors.push_back(wxColour(163, 73, 164));

	std::vector<wxColour> backColors;
	backColors.push_back(wxColour(237, 28, 36));
	textColors.push_back(wxColour(255, 127, 39));
	backColors.push_back(wxColour(255, 242, 0));
	backColors.push_back(wxColour(34, 177, 76));
	backColors.push_back(wxColour(0, 162, 232));
	backColors.push_back(wxColour(63, 72, 204));
	backColors.push_back(wxColour(163, 73, 164));

	PropertyPage *page = AddPropertyPage("General");

	int numClasses = 0;
	wxColour lastTextColor = textColors[0];
	wxColour lastBackColor = backColors[0];

	for (int i = 0; i < (int)props.size(); i++)
	{
		const Object::PropertyObject &propObj = props[i];
		Property *prop = 0;

		if (Object::PT_CLASS == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_CATEGORY, 0, propObj.Enable);

			int colorIndex = numClasses % 7;
			lastTextColor = textColors[colorIndex];

			mPropGrid->SetPropertyTextColour(wxString(propObj.Tag), lastTextColor, false);
		}
		else if (Object::PT_INT == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_INT,
				(void *)Any_Cast<int>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_FLOAT == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_FLOAT,
				(void *)Any_Cast<float>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_BOOL == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_BOOL,
				(void *)Any_Cast<bool>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_COLOR3FLOAT3 == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_COLOR3FLOAT3,
				(void *)Any_Cast<Float3>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_STRING == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_STRING,
				(void *)Any_Cast<std::string>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_STRINGBUTTON == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_STRINGBUTTON,
				(void *)Any_Cast<std::string>(&propObj.Data), propObj.Enable);
			prop->SetButtonDownCallback(StringButCallback);
		}
		else if (Object::PT_FLOAT2 == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_FLOAT2,
				(void *)Any_Cast<Float2>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_FLOAT3 == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_FLOAT3,
				(void *)Any_Cast<Float3>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_APOINT3 == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_APOINT3,
				(void *)Any_Cast<APoint>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_AVECTOR3 == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_AVECTOR3,
				(void *)Any_Cast<AVector>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_SIZE == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_SIZE,
				(void *)Any_Cast<Sizef>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_RECT == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_RECT,
				(void *)Any_Cast<Rectf>(&propObj.Data), propObj.Enable);
		}
		else if (Object::PT_ENUM == propObj.Type)
		{
			prop = page->AddProperty(propObj.Name, propObj.Tag, Property::PT_ENUM,
				(void*)Any_Cast<int>(&propObj.Data), propObj.Enable,
				Any_Cast<std::vector<std::string> >(&propObj.Data1));
		}
		else if (Object::PT_TRANSFORM == propObj.Type)
		{
			prop = new MovableTransProperty(page, propObj.Name, propObj.Tag,
				(Transform*)Any_Cast<Transform>(&propObj.Data), obj);
		}
		else if (Object::PT_EMFLOAT == propObj.Type)
		{
			prop = new0 EMFloatProperty(page, propObj.Name, propObj.Tag,
				(InterpCurvePointFloat*)Any_Cast<InterpCurvePointFloat>(&propObj.Data), false);
		}
		else if (Object::PT_EMFLOATRANGE == propObj.Type)
		{
			prop = new0 EMFloatRangeProperty(page, propObj.Name, propObj.Tag,
				(InterpCurvePointFloat*)Any_Cast<InterpCurvePointFloat>(&propObj.Data),
				(InterpCurvePointFloat*)Any_Cast<InterpCurvePointFloat>(&propObj.Data1), false);
		}
		else if (Object::PT_EMFLOAT3 == propObj.Type)
		{
			prop = new0 EMFloat3Property(page, propObj.Name, propObj.Tag, false,
				(InterpCurvePointFloat3*)Any_Cast<InterpCurvePointFloat3>(&propObj.Data), false);
		}
		else if (Object::PT_EMFLOAT3RANGE == propObj.Type)
		{
			prop = new0 EMFloat3RangeProperty(page, propObj.Name, propObj.Tag, false,
				(InterpCurvePointFloat3*)Any_Cast<InterpCurvePointFloat3>(&propObj.Data),
				(InterpCurvePointFloat3*)Any_Cast<InterpCurvePointFloat3>(&propObj.Data1), false);
		}
		else if (Object::PT_EMFLOAT3COLOR == propObj.Type)
		{
			prop = new0 EMFloat3Property(page, propObj.Name, propObj.Tag, true,
				(InterpCurvePointFloat3*)Any_Cast<InterpCurvePointFloat3>(&propObj.Data), false);
		}
		else if (Object::PT_EMFLOAT3COLORRANGE == propObj.Type)
		{
			prop = new0 EMFloat3RangeProperty(page, propObj.Name, propObj.Tag, true,
				(InterpCurvePointFloat3*)Any_Cast<InterpCurvePointFloat3>(&propObj.Data),
				(InterpCurvePointFloat3*)Any_Cast<InterpCurvePointFloat3>(&propObj.Data1), false);
		}

		if (prop)
		{
			if (prop->mProperty)
			{
				//prop->mProperty->SetTextColour(lastTextColor);
				//prop->mProperty->SetBackgroundColour(lastBackColor);
			}
		}

		if (Object::PT_CLASS == propObj.Type)
		{
			numClasses++;
		}
	}

	mPropGridManager->ShowHeader(true);
}
//-----------------------------------------------------------------------------
PX2::Object *ObjectPropertyGrid::GetObject()
{
	return mObject;
}
//-----------------------------------------------------------------------------
void ObjectPropertyGrid::OnPropertyGridChange(wxPropertyGridEvent &event)
{
	PropertyGrid::OnPropertyGridChange(event);

	Object *obj = mObject;
	if (!obj)
		return;

	std::string propName = event.GetPropertyName();
	std::string propLabel = event.GetProperty()->GetLabel();

	std::vector<Object::PropertyObject> &props = obj->GetProperties();

	for (int i = 0; i < (int)props.size(); i++)
	{
		Object::PropertyObject &propObj = props[i];

		if (propObj.Tag == propName)
		{
			//// tex pack
			//const SelectResData &data = EditSystem::GetSingleton().GetSelectedResource();
			//SelectResData::SelectResType selectResType = data.GetSelectResType();
			//if (SelectResData::RT_TEXPACKELEMENT == selectResType)
			//{
			//	propObj.Data1 = data.ResPathname;
			//}

			//// do change
			obj->OnPropertyChanged(propObj);

			// appended events
			if (propLabel == "Name")
			{
				Event *ent = NirvanaEventSpace::CreateEventX(NirvanaEventSpace::ObjectNameChanged);
				ent->SetData<Object*>(obj);
				EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
			}

			//EffectModule *em = DynamicCast<EffectModule>(obj);
			//if (em)
			//{
			//	if (propLabel == "IsRange")
			//	{
			//		EditSystem::GetSingleton().GetCurveEdit()->SetSelectedCurveCtrl(0);
			//		EditSystem::GetSingleton().GetCurveEdit()->SetSelectedUICurveGroup(0);
			//		EditSystem::GetSingleton().GetCurveEdit()->ReCreateAddCurveGroup(em);

			//		OnSetObject(obj);
			//	}
			//	else
			//	{
			//		size_t begin = propLabel.find_first_of("[");
			//		size_t end = propLabel.find_first_of("]");
			//		if (begin != std::string::npos && end != std::string::npos)
			//		{
			//			Event *ent = EditorEventSpace::CreateEventX(
			//				EditorEventSpace::CurveChangedByGrid);
			//			ent->SetData<Object*>(obj);
			//			EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
			//		}
			//	}
			//}

			//InterpCurveController *iCtrl = DynamicCast<InterpCurveController>(obj);
			//if (iCtrl)
			//{
			//	size_t begin = propLabel.find_first_of("[");
			//	size_t end = propLabel.find_first_of("]");
			//	if (begin != std::string::npos && end != std::string::npos)
			//	{
			//		Event *ent = EditorEventSpace::CreateEventX(
			//			EditorEventSpace::CurveChangedByGrid);
			//		ent->SetData<Object*>(obj);
			//		EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
			//	}
			//}
		}
	}
}
//-----------------------------------------------------------------------------
void ObjectPropertyGrid::OnPropertyGridChanging(wxPropertyGridEvent &event)
{
	PropertyGrid::OnPropertyGridChange(event);
}
//-----------------------------------------------------------------------------
void ObjectPropertyGrid::OnSize(wxSizeEvent &e)
{
	PropertyGrid::OnSize(e);
}
//-----------------------------------------------------------------------------