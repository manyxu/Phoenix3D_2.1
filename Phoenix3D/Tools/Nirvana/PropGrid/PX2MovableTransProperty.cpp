/*
*
* ÎÄ¼þÃû³Æ	£º	PX2ActorTransProperty.cpp
*
*/

#include "PX2MovableTransProperty.hpp"
#include "PX2PropertyPage.hpp"
#include "wxPropertyExtend.hpp"
#include "PX2EditEventType.hpp"
#include "PX2LanguageManager.hpp"
using namespace PX2Editor;
using namespace PX2;

MovableTransProperty::MovableTransProperty (PropertyPage *parent, 
	const std::string &name, const std::string &tag,
	Transform *trans, Object *obj)
	:
Property(parent, name, tag, Property::PT_TRANSFORM, 0),
	mIsRSMatrix(0),
	mPropertyTranslate(0),
	mPropertyRotation(0),
	mPropertyScale(0),
	mPropertyIsUniformScale(0),
	mTrans(trans),
	mObject(obj)
{
	APoint position;
	APoint rotation;
	APoint scale(1.0f, 1.0f, 1.0f);

	bool isRSMatrix = mTrans->IsRSMatrix();
	if (isRSMatrix)
	{
		position = mTrans->GetTranslate();
		Matrix3f mat = mTrans->GetRotate();
		mat.ExtractEulerXYZ(rotation.X(), rotation.Y(), rotation.Z());
		scale = mTrans->GetScale();
		bool isUniformScale = mTrans->IsUniformScale();

		mProperty = parent->mPage->Append(new wxStringProperty(
			name, tag, wxT("<composed>")) );

		mPropertyTranslate = parent->mPage->AppendIn(mProperty, 
			new wxAPoint3Property("Translate", tag+"Translate",
			position));
		mPropertyRotation = parent->mPage->AppendIn(mProperty, 
			new wxAPoint3Property("Rotate", tag+"Rotate", rotation));
		mPropertyScale = parent->mPage->AppendIn(mProperty, 
			new wxAPoint3Property("Scale", tag+"Scale", scale));

		mPropertyIsUniformScale = parent->mPage->AppendIn(mProperty, 
			new wxBoolProperty("IsUniformScale", tag+"IsUniformScale", isUniformScale));
		mPropertyIsUniformScale->Enable(false);
	}
	else
	{
		mProperty = parent->mPage->Append(new wxStringProperty(
			name, tag, wxT("<composed>")) );

		mIsRSMatrix = parent->mPage->AppendIn(mProperty, 
			new wxBoolProperty("IsRSMatrix", tag+"IsRSMatrix", false));
		mIsRSMatrix->Enable(false);
	}
}
//-----------------------------------------------------------------------------
MovableTransProperty::~MovableTransProperty ()
{
}
//-----------------------------------------------------------------------------
void MovableTransProperty::OnChange (wxPropertyGridEvent &event)
{
	if (!mProperty)
		return;

	wxPGProperty *id = event.GetProperty();
	const wxString &name = event.GetPropertyName();
	std::string stdName = std::string(name);
	wxVariant variant = id->GetValue();

	if (0 == id)
		return;

	if (variant.IsNull())
		return;

	APoint value;

	if (mPropertyTranslate == id)
	{
		value = APointRefFromVariant(variant);
		mTrans->SetTranslate(value);
	}
	else if (mPropertyRotation == id)
	{
		value = APointRefFromVariant(variant);
		mTrans->SetRotate(Matrix3f().MakeEulerXYZ(
			value.X(), value.Y(), value.Z()));
	}
	else if (mPropertyScale == id)
	{
		value = APointRefFromVariant(variant);
		if (value.X()!=0.0f && value.Y()!=0.0f && value.Z()!=0.0f)
		{
			mTrans->SetScale(value);
		}
	}

	Event *ent = 0;
	ent = EditEventSpace::CreateEventX(EditEventSpace::ObjectTransformChanged);
	ent->SetData<Object*>(mObject);
	EventWorld::GetSingleton().BroadcastingLocalEvent(ent);
}
//-----------------------------------------------------------------------------
void MovableTransProperty::DoEnter ()
{
}
//-----------------------------------------------------------------------------
void MovableTransProperty::DoExecute (PX2::Event *event)
{
	if (EditEventSpace::IsEqual(event, EditEventSpace::ObjectTransformChanged))
	{
		//Object *obj = event->GetData<Object*>();
		//if (obj == mObject)
		//{
		//	APoint position = mTrans->GetTranslate();
		//	APoint rotation;
		//	Matrix3f mat = mTrans->GetRotate();
		//	mat.ExtractEulerXYZ(rotation.X(), rotation.Y(), rotation.Z());
		//	APoint scale = mTrans->GetScale();

		//	wxVariant variant;

		//	variant.Clear();
		//	variant << position;
		//	mPropertyTranslate->SetValue(variant);

		//	variant.Clear();
		//	variant << rotation;
		//	mPropertyRotation->SetValue(variant);

		//	variant.Clear();
		//	variant << scale;
		//	mPropertyScale->SetValue(variant);
		//}
	}
}
//-----------------------------------------------------------------------------
void MovableTransProperty::DoLeave ()
{
}
//-----------------------------------------------------------------------------