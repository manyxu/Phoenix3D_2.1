/*
*
* 文件名称	：	PX2Movable.cpp
*
*/

#include "PX2Movable.hpp"
#include "PX2Culler.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI_V(PX2, Controlledable, Movable, 3);
PX2_IMPLEMENT_STREAM(Movable);
PX2_IMPLEMENT_ABSTRACT_FACTORY(Movable);

//----------------------------------------------------------------------------
Movable::Movable ()
    :
    WorldTransformIsCurrent(false),
    WorldBoundIsCurrent(false),
    Culling(CULL_DYNAMIC),
    mParent(0),
	mIsAlphaSelfCtrled(false),
	mAlpha(1.0f),
	mIsColorSelfCtrled(false),
	mColor(Float3::WHITE),
	mIsBrightnessSelfCtrled(false),
	mBrightness(1.0f),
	mUpdateTime(-1.0f),
	mUpdateTiming(0.0f),
	mUpdateTimingInit(-1.0f),
	mUpdatePriority(0),
	mIsDoPick(true),
	mIsPickIngoreCullingMode(false),
	mIsNotPickedParentChildrenNotPicked(false),
	mIsIngoreParent_Translate(false),
	mIsIngoreParent_Rotate(false),
	mIsIngoreParent_Scale(false),
	IsSkinCtrlSetWroldTrans(false)
{
}
//----------------------------------------------------------------------------
Movable::~Movable ()
{
	// mParent不需要被释放
}
//----------------------------------------------------------------------------
void Movable::Show (bool show)
{
	if (show)
	{
		if (CULL_ALWAYS == Culling)
		{
			Culling = CULL_DYNAMIC;
		}
	}
	else
	{
		Culling = CULL_ALWAYS;
	}
}
//----------------------------------------------------------------------------
void Movable::SetDoPick (bool doPick)
{
	mIsDoPick = doPick;
}
//----------------------------------------------------------------------------
bool Movable::IsShow () const
{
	return Culling!=CULL_ALWAYS;
}
//----------------------------------------------------------------------------
void Movable::Update (double applicationTime, bool initiator)
{
	bool doUpdateTrans = true;
	if (mUpdateTime > 0.0f)
	{
		if (-1.0f == mUpdateTimingInit)
		{
			mUpdateTimingInit = (float)applicationTime;
			mUpdateTiming = 0.0f;
		}
		else
		{
			mUpdateTiming = ((float)applicationTime-mUpdateTimingInit);
		}

		if (mUpdateTiming > mUpdateTime)
		{
			doUpdateTrans = false;
		}
	}

	if (doUpdateTrans)
	{
		UpdateWorldData(applicationTime);
		UpdateWorldBound();
		if (initiator)
		{
			PropagateBoundToRoot();
		}
	}
}
//----------------------------------------------------------------------------
void Movable::SetParentTransformIngore (bool trans, bool rotate, bool scale)
{
	mIsIngoreParent_Translate = trans;
	mIsIngoreParent_Rotate = rotate;
	mIsIngoreParent_Scale = scale;
}
//----------------------------------------------------------------------------
void Movable::GetParentTransformIngore (bool &trans, bool &rotate, bool &scale)
{
	trans = mIsIngoreParent_Translate;
	rotate = mIsIngoreParent_Rotate;
	scale = mIsIngoreParent_Scale;
}
//----------------------------------------------------------------------------
void Movable::OnAttach ()
{
}
//----------------------------------------------------------------------------
void Movable::OnDetach ()
{
}
//----------------------------------------------------------------------------
void Movable::OnPicked (int pickInfo)
{
	PX2_UNUSED(pickInfo);
}
//----------------------------------------------------------------------------
void Movable::OnNotPicked (int pickInfo)
{
	PX2_UNUSED(pickInfo);
}
//----------------------------------------------------------------------------
void Movable::UpdateWorldData (double applicationTime)
{
	// 更新控制器
	UpdateControllers(applicationTime);

	if (LocalTransform.IsRSMatrix())
	{
		const APoint &scale = LocalTransform.GetScale();
		if (scale.X()==scale.Y() && scale.Y()==scale.Z())
			LocalTransform.SetUniformScale(scale.X());
	}

	// 更新世界变换
	if (!WorldTransformIsCurrent)
	{
		if (mParent)
		{
			if (mIsIngoreParent_Translate || mIsIngoreParent_Rotate ||
				mIsIngoreParent_Scale)
			{
				Transform trans = mParent->WorldTransform;

				if (mIsIngoreParent_Translate)
				{
					trans.SetTranslate(APoint::ORIGIN);
				}
				if (mIsIngoreParent_Rotate)
				{
					trans.SetRotate(HMatrix::IDENTITY);
				}
				if (mIsIngoreParent_Scale)
				{
					trans.SetScale(APoint(1.0f, 1.0f, 1.0f));
				}
				WorldTransform = trans*LocalTransform;
			}
			else
			{
				WorldTransform = mParent->WorldTransform*LocalTransform;
			}
		}
		else
		{
			WorldTransform = LocalTransform;
		}
	}

	if (IsSkinCtrlSetWroldTrans)
	{
		if (mParent)
		{
			if (mIsIngoreParent_Translate || mIsIngoreParent_Rotate ||
				mIsIngoreParent_Scale)
			{
				Transform trans = mParent->WorldTransform;

				if (mIsIngoreParent_Translate)
				{
					trans.SetTranslate(APoint::ORIGIN);
				}
				if (mIsIngoreParent_Rotate)
				{
					trans.SetRotate(HMatrix::IDENTITY);
				}
				if (mIsIngoreParent_Scale)
				{
					trans.SetScale(APoint(1.0f, 1.0f, 1.0f));
				}
				BoundWorldTransform = trans*LocalTransform;
			}
			else
			{
				BoundWorldTransform = mParent->WorldTransform*LocalTransform;
			}
		}
		else
		{
			BoundWorldTransform = LocalTransform;
		}
	}
	else
	{
		BoundWorldTransform = WorldTransform;
	}
}
//----------------------------------------------------------------------------
void Movable::PropagateBoundToRoot ()
{
    if (mParent)
    {
        mParent->UpdateWorldBound();
        mParent->PropagateBoundToRoot();
    }
}
//----------------------------------------------------------------------------
void Movable::OnGetVisibleSet (Culler& culler, bool noCull)
{
    if (Culling == CULL_ALWAYS)
    {
        return;
    }

    if (Culling == CULL_NEVER)
    {
        noCull = true;
    }

    unsigned int savePlaneState = culler.GetPlaneState();
    if (noCull || culler.IsVisible(WorldBound))
    {
        GetVisibleSet(culler, noCull);
    }
    culler.SetPlaneState(savePlaneState);
}
//----------------------------------------------------------------------------
void Movable::SetAlpha (float alpha)
{
	mAlpha = alpha;
}
//----------------------------------------------------------------------------
void Movable::SetColor (const Float3 &color)
{
	mColor = color;
}
//----------------------------------------------------------------------------
void Movable::SetBrightness (float brightness)
{
	mBrightness = brightness;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* Movable::GetObjectByName (const std::string& name)
{
    // mParent不用查找，否则会无限循环
    return Controlledable::GetObjectByName(name);
}
//----------------------------------------------------------------------------
void Movable::GetAllObjectsByName (const std::string& name,
    std::vector<Object*>& objects)
{
    // mParent不用查找，否则会无限循环
    Controlledable::GetAllObjectsByName(name, objects);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Movable::RegistProperties ()
{
	Controlledable::RegistProperties();

	AddPropertyClass("Movable");

	PropertyObject objLocalTrans;
	objLocalTrans.Name = "LocalTransform";
	objLocalTrans.Type = Object::PT_TRANSFORM;
	objLocalTrans.Data = LocalTransform;
	objLocalTrans.Data1 = true;
	AddProperty(objLocalTrans);

	PropertyObject objWorldTrans;
	objWorldTrans.Name = "WorldTransform";
	objWorldTrans.Type = Object::PT_TRANSFORM;
	objWorldTrans.Data = WorldTransform;
	objWorldTrans.Data1 = false;
	AddProperty(objWorldTrans);
	AddProperty("WorldTransformIsCurrent", Object::PT_BOOL, Any(WorldTransformIsCurrent));

	AddProperty("WorldBoundCenter", Object::PT_APOINT3, Any(WorldBound.GetCenter()));
	AddProperty("WorldBoundRadius", Object::PT_FLOAT, Any(WorldBound.GetRadius()));
	AddProperty("WorldBoundIsCurrent", Object::PT_BOOL, Any(WorldBoundIsCurrent));

	std::vector<std::string> cullings;
	cullings.push_back("CULL_DYNAMIC");
	cullings.push_back("CULL_ALWAYS");
	cullings.push_back("CULL_NEVER");
	AddPropertyEnum("CullingMode", (int)Culling, cullings);
	AddProperty("IsShow", Object::PT_BOOL, IsShow());

	AddProperty("Alpha", Object::PT_FLOAT, Any(GetAlpha()));
	AddProperty("IsAlphaSelfCtrled", Object::PT_BOOL, Any(IsAlphaSelfCtrled()));
	AddProperty("Color", Object::PT_COLOR3FLOAT3, Any(GetColor()));
	AddProperty("IsColorSelfCtrled", Object::PT_BOOL, Any(IsColorSelfCtrled()));
	AddProperty("Brightness", Object::PT_FLOAT, GetBrightness());
	AddProperty("IsBrightnessSelfCtrled", Object::PT_BOOL, IsBrightnessSelfCtrled());

	AddProperty("UpdateTime", Object::PT_FLOAT, GetUpdateTime());
}
//----------------------------------------------------------------------------
void Movable::OnPropertyChanged (const PropertyObject &obj)
{
	Controlledable::OnPropertyChanged(obj);

	if ("LocalTransform" == obj.Name)
	{
		LocalTransform = *Any_Cast<Transform>(&obj.Data);
	}
	else if ("WorldTransform" == obj.Name)
	{
		LocalTransform = *Any_Cast<Transform>(&obj.Data);
	}
	else if ("WorldTransformIsCurrent" == obj.Name)
	{
		WorldTransformIsCurrent = *Any_Cast<bool>(&obj.Data);
	}
	else if ("WorldBoundIsCurrent" == obj.Name)
	{
		WorldBoundIsCurrent = PX2_ANY_AS(obj.Data, bool);
	}
	else if ("WorldBoundCenter" == obj.Name)
	{
		WorldBound.SetCenter(*Any_Cast<APoint>(&obj.Data));
	}
	else if ("WorldBoundRadius" == obj.Name)
	{
		WorldBound.SetRadius(*Any_Cast<float>(&obj.Data));
	}
	else if ("CullingMode" == obj.Name)
	{
		Culling = (CullingMode)(*Any_Cast<int>(&obj.Data));
	}
	else if ("IsShow" == obj.Name)
	{
		Show(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("Alpha" == obj.Name)
	{
		SetAlpha(*Any_Cast<float>(&obj.Data));
	}
	else if ("IsAlphaSelfCtrled" == obj.Name)
	{
		SetAlphaSelfCtrled(*Any_Cast<bool>(&obj.Data));
	}
	else if ("Color" == obj.Name)
	{
		SetColor(*Any_Cast<Float3>(&obj.Data));
	}
	else if ("IsColorSelfCtrled" == obj.Name)
	{
		SetColorSelfCtrled(*Any_Cast<bool>(&obj.Data));
	}
	else if ("Brightness" == obj.Name)
	{
		SetBrightness(PX2_ANY_AS(obj.Data, float));
	}
	else if ("IsBrightnessSelfCtrled" == obj.Name)
	{
		SetBrightnessSelfCtrled(PX2_ANY_AS(obj.Data, bool));
	}
	else if ("UpdateTime" == obj.Name)
	{
		SetUpdateTime(PX2_ANY_AS(obj.Data, float));
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
Movable::Movable (LoadConstructor value)
    :
    Controlledable(value),
    WorldTransformIsCurrent(false),
    WorldBoundIsCurrent(false),
    Culling(CULL_DYNAMIC),
    mParent(0),
	mIsAlphaSelfCtrled(false),
	mAlpha(1.0f),
	mIsColorSelfCtrled(false),
	mColor(Float3::WHITE),
	mIsBrightnessSelfCtrled(false),
	mBrightness(1.0f),
	mUpdateTime(-1.0f),
	mUpdateTiming(0.0f),
	mUpdateTimingInit(-1.0f),
	mUpdatePriority(0),
	mIsDoPick(true),
	mIsPickIngoreCullingMode(false),
	mIsNotPickedParentChildrenNotPicked(false),
	mIsIngoreParent_Translate(false),
	mIsIngoreParent_Rotate(false),
	mIsIngoreParent_Scale(false),
	IsSkinCtrlSetWroldTrans(false)
{
}
//----------------------------------------------------------------------------
void Movable::Load (InStream& source)
{
    PX2_BEGIN_DEBUG_STREAM_LOAD(source);

    Controlledable::Load(source);
	PX2_VERSION_LOAD(source);

    source.ReadAggregate(LocalTransform);
    source.ReadAggregate(WorldTransform);
    source.ReadBool(WorldTransformIsCurrent);
    source.ReadAggregate(WorldBound);
    source.ReadBool(WorldBoundIsCurrent);
    source.ReadEnum(Culling);
	source.Read(mAlpha);
	source.ReadAggregate(mColor);

	int readedVersion = GetReadedVersion();
	if (1 <= readedVersion)
	{
		source.Read(mUpdateTime);
	}

	// mParent不被保存，它会在Node::Link中调用Node::SetChild被设置。

	if (2 <= readedVersion)
	{
		source.ReadBool(mIsAlphaSelfCtrled);
		source.ReadBool(mIsColorSelfCtrled);
	}

	if (3 <= readedVersion)
	{
		source.ReadBool(mIsBrightnessSelfCtrled);
		source.Read(mBrightness);
	}

    PX2_END_DEBUG_STREAM_LOAD(Movable, source);
}
//----------------------------------------------------------------------------
void Movable::Link (InStream& source)
{
	// mParent不被保存，它会在Node::Link中调用Node::SetChild被设置。

    Controlledable::Link(source);
}
//----------------------------------------------------------------------------
void Movable::PostLink ()
{
    Controlledable::PostLink();
}
//----------------------------------------------------------------------------
bool Movable::Register (OutStream& target) const
{
	// mParent不需要被注册

    return Controlledable::Register(target);
}
//----------------------------------------------------------------------------
void Movable::Save (OutStream& target) const
{
    PX2_BEGIN_DEBUG_STREAM_SAVE(target);

    Controlledable::Save(target);
	PX2_VERSION_SAVE(target);

    target.WriteAggregate(LocalTransform);
    target.WriteAggregate(WorldTransform);
    target.WriteBool(WorldTransformIsCurrent);
    target.WriteAggregate(WorldBound);
    target.WriteBool(WorldBoundIsCurrent);
    target.WriteEnum(Culling);
	target.Write(mAlpha);
	target.WriteAggregate(mColor);
	target.Write(mUpdateTime);

	target.WriteBool(mIsAlphaSelfCtrled);
	target.WriteBool(mIsColorSelfCtrled);

	target.WriteBool(mIsBrightnessSelfCtrled);
	target.Write(mBrightness);

	// mParent不被保存，它会在Node::Link中调用Node::SetChild被设置。

    PX2_END_DEBUG_STREAM_SAVE(Movable, target);
}
//----------------------------------------------------------------------------
int Movable::GetStreamingSize (Stream &stream) const
{
    int size = Controlledable::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
    size += LocalTransform.GetStreamingSize();;
    size += WorldTransform.GetStreamingSize();
    size += PX2_BOOLSIZE(WorldTransformIsCurrent);
    size += WorldBound.GetStreamingSize();
    size += PX2_BOOLSIZE(WorldBoundIsCurrent);
    size += PX2_ENUMSIZE(Culling);
	size += sizeof(mAlpha);
	size += sizeof(mColor);

	if (stream.IsIn())
	{
		int readedVersion = GetReadedVersion();
		if (1 <= readedVersion)
		{
			size += sizeof(mUpdateTime);
		}
		if (2 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsAlphaSelfCtrled);
			size += PX2_BOOLSIZE(mIsColorSelfCtrled);
		}
		if (3 <= readedVersion)
		{
			size += PX2_BOOLSIZE(mIsBrightnessSelfCtrled);
			size += sizeof(mBrightness);
		}
	}
	else
	{
		size += sizeof(mUpdateTime);
		size += PX2_BOOLSIZE(mIsAlphaSelfCtrled);
		size += PX2_BOOLSIZE(mIsColorSelfCtrled);

		size += PX2_BOOLSIZE(mIsBrightnessSelfCtrled);
		size += sizeof(mBrightness);
	}

    // mParent不被持久化

    return size;
}
//----------------------------------------------------------------------------
