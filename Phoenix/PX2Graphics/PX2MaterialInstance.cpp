/*
*
* 文件名称	：	PX2MaterialInstance.cpp
*
*/

#include "PX2MaterialInstance.hpp"
#include "PX2StringHelp.hpp"
#include "PX2GraphicsRoot.hpp"
#include "PX2MaterialManager.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, MaterialInstance);
PX2_IMPLEMENT_STREAM(MaterialInstance);
PX2_IMPLEMENT_FACTORY(MaterialInstance);

//----------------------------------------------------------------------------
MaterialInstance::MaterialInstance (const Material* material,
											int techniqueIndex)
											:
mMaterial((Material*)material),  // conceptual constness
mTechniqueIndex(techniqueIndex),
mNumPasses(0),
mVertexParameters(0),
mPixelParameters(0)
{
	assertion(material != 0, "Material must be specified.\n");
	assertion(
		0 <= techniqueIndex && techniqueIndex < material->GetNumTechniques(),
		"Invalid technique index.\n");

	MaterialTechnique* technique = mMaterial->GetTechnique(mTechniqueIndex);
	mNumPasses = technique->GetNumPasses();
	mVertexParameters = new1<ShaderParametersPtr>(mNumPasses);
	mPixelParameters = new1<ShaderParametersPtr>(mNumPasses);
	int p;
	for (p = 0; p < mNumPasses; ++p)
	{
		MaterialPass* pass = technique->GetPass(p);
		mVertexParameters[p] =
			new0 ShaderParameters(pass->GetVertexShader());
		mVertexParameters[p]->SetName("VParams_" + StringHelp::IntToString(p));
		mPixelParameters[p] =
			new0 ShaderParameters(pass->GetPixelShader());
		mPixelParameters[p]->SetName("PParams_" + StringHelp::IntToString(p));
	}
}
//----------------------------------------------------------------------------
MaterialInstance::MaterialInstance(const std::string &mtlFilename, 
	const std::string &intanceName) :
	mMaterialFilename(mtlFilename),
	mInstanceTagName(intanceName),
	mNumPasses(0),
	mVertexParameters(0),
	mPixelParameters(0)
{
	_RefreshMaterial(mMaterialFilename, mInstanceTagName);
}
//----------------------------------------------------------------------------
void MaterialInstance::_RefreshMaterial(const std::string &mtlFilename,
	const std::string &tagName)
{
	mMaterial = PX2_MATERIALMAN.GetMaterial(mtlFilename.c_str());
	assertion(mMaterial != 0, "Material must be specified.\n");

	MaterialTechnique* technique = mMaterial->GetTechnique(tagName,
		mTechniqueIndex);

	int newNumPass = technique->GetNumPasses();
	ShaderParametersPtr* newVertexParameters = new1<ShaderParametersPtr>(
		newNumPass);
	ShaderParametersPtr* newPixelParameters = new1<ShaderParametersPtr>(
		newNumPass);

	for (int p = 0; p < newNumPass; ++p)
	{
		MaterialPass* pass = technique->GetPass(p);
		VertexShader *vs = pass->GetVertexShader();
		PixelShader *ps = pass->GetPixelShader();

		ShaderParameters *oldParams_V = 0;
		if (p < mNumPasses)
			oldParams_V = mVertexParameters[p];

		ShaderParameters *oldParams_P = 0;
		if (p < mNumPasses)
			oldParams_P = mPixelParameters[p];

		_RefreshMaterialParams(oldParams_V, newVertexParameters[p],
			vs);
		_RefreshMaterialParams(oldParams_P, newPixelParameters[p],
			ps);

		if (oldParams_V)
			mVertexParameters[p] = 0;

		if (oldParams_P)
			mPixelParameters[p] = 0;
	}

	delete1(mVertexParameters);
	delete1(mPixelParameters);

	mNumPasses = newNumPass;
	mVertexParameters = newVertexParameters;
	mPixelParameters = newPixelParameters;
}
//----------------------------------------------------------------------------
void MaterialInstance::_RefreshMaterialParams(ShaderParameters *oldParam,
	ShaderParametersPtr &newParam, Shader *shader)
{
	PX2_UNUSED(oldParam);

	newParam = new0 ShaderParameters(shader);

	for (int i = 0; i < shader->GetNumConstants(); i++)
	{
		const std::string &constantName = shader->GetConstantName(i);

		ShaderFloat *shaderFloat = PX2_MATERIALMAN.CreateShaderFloat(
			constantName.c_str());
		if (shaderFloat)
		{
			newParam->SetConstant(i, shaderFloat);
		}
	}
}
//----------------------------------------------------------------------------
MaterialInstance::~MaterialInstance ()
{
	delete1(mVertexParameters);
	delete1(mPixelParameters);
}
//----------------------------------------------------------------------------
const MaterialPass* MaterialInstance::GetPass (int pass) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mMaterial->GetTechnique(mTechniqueIndex)->GetPass(pass);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
ShaderParameters* MaterialInstance::GetVertexParameters (int pass) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass];
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
ShaderParameters* MaterialInstance::GetPixelParameters (int pass) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass];
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
int MaterialInstance::SetVertexConstant (int pass,
											 const std::string& name, ShaderFloat* sfloat)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->SetConstant(name, sfloat);
	}

	assertion(false, "Invalid pass index.\n");
	return -1;
}
//----------------------------------------------------------------------------
int MaterialInstance::SetPixelConstant (int pass, const std::string& name,
											ShaderFloat* sfloat)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->SetConstant(name, sfloat);
	}

	assertion(false, "Invalid pass index.\n");
	return -1;
}
//----------------------------------------------------------------------------
int MaterialInstance::SetVertexTexture (int pass, const std::string& name,
											Texture* texture)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->SetTexture(name, texture);
	}

	assertion(false, "Invalid pass index.\n");
	return -1;
}
//----------------------------------------------------------------------------
int MaterialInstance::SetPixelTexture (int pass, const std::string& name,
										   Texture* texture)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->SetTexture(name, texture);
	}

	assertion(false, "Invalid pass index.\n");
	return -1;
}
//----------------------------------------------------------------------------
void MaterialInstance::SetVertexConstant (int pass, int handle,
											  ShaderFloat* sfloat)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->SetConstant(handle, sfloat);
	}

	assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
void MaterialInstance::SetPixelConstant (int pass, int handle,
											 ShaderFloat* sfloat)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->SetConstant(handle, sfloat);
	}

	assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
void MaterialInstance::SetVertexTexture (int pass, int handle,
											 Texture* texture)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->SetTexture(handle, texture);
	}

	assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
void MaterialInstance::SetPixelTexture (int pass, int handle,
											Texture* texture)
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->SetTexture(handle, texture);
	}

	assertion(false, "Invalid pass index.\n");
}
//----------------------------------------------------------------------------
ShaderFloat* MaterialInstance::GetVertexConstant (int pass,
													  const std::string& name) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->GetConstant(name);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
ShaderFloat* MaterialInstance::GetPixelConstant (int pass,
													 const std::string& name) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->GetConstant(name);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
Texture* MaterialInstance::GetVertexTexture (int pass,
												 const std::string& name) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->GetTexture(name);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
Texture* MaterialInstance::GetPixelTexture (int pass,
												const std::string& name) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->GetTexture(name);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
ShaderFloat* MaterialInstance::GetVertexConstant (int pass, int handle)
const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->GetConstant(handle);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
ShaderFloat* MaterialInstance::GetPixelConstant (int pass, int handle)
const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->GetConstant(handle);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
Texture* MaterialInstance::GetVertexTexture (int pass, int handle) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mVertexParameters[pass]->GetTexture(handle);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------
Texture* MaterialInstance::GetPixelTexture (int pass, int handle) const
{
	if (0 <= pass && pass < mNumPasses)
	{
		return mPixelParameters[pass]->GetTexture(handle);
	}

	assertion(false, "Invalid pass index.\n");
	return 0;
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* MaterialInstance::GetObjectByName (const std::string& name)
{
	Object* found = Object::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	PX2_GET_OBJECT_BY_NAME(mMaterial, name, found);
	for (int pass = 0; pass < mNumPasses; ++pass)
	{
		PX2_GET_OBJECT_BY_NAME(mVertexParameters[pass], name, found);
		PX2_GET_OBJECT_BY_NAME(mPixelParameters[pass], name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void MaterialInstance::GetAllObjectsByName (const std::string& name,
												std::vector<Object*>& objects)
{
	Object::GetAllObjectsByName(name, objects);

	PX2_GET_ALL_OBJECTS_BY_NAME(mMaterial, name, objects);
	for (int pass = 0; pass < mNumPasses; ++pass)
	{
		PX2_GET_ALL_OBJECTS_BY_NAME(mVertexParameters[pass], name, objects);
		PX2_GET_ALL_OBJECTS_BY_NAME(mPixelParameters[pass], name, objects);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void MaterialInstance::RegistProperties ()
{
	Object::RegistProperties();

	AddPropertyClass("MaterialInstance");
	AddProperty("TechniqueIndex", PT_INT, GetTechniqueIndex(), false);
	AddProperty("NumPasses", PT_INT, GetNumPasses(), false);
}
//----------------------------------------------------------------------------
void MaterialInstance::OnPropertyChanged (const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
MaterialInstance::MaterialInstance (LoadConstructor value)
:
Object(value),
mTechniqueIndex(0),
mNumPasses(0),
mVertexParameters(0),
mPixelParameters(0)
{
}
//----------------------------------------------------------------------------
void MaterialInstance::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	if (!mMaterialFilename.empty() && !mInstanceTagName.empty())
	{
		source.ReadString(mMaterialFilename);
		source.ReadString(mInstanceTagName);
	}
	else
	{
		source.ReadPointer(mMaterial);
		source.Read(mTechniqueIndex);
	}

	source.ReadPointerRR(mNumPasses, mVertexParameters);
	source.ReadPointerVR(mNumPasses, mPixelParameters);

	PX2_END_DEBUG_STREAM_LOAD(MaterialInstance, source);
}
//----------------------------------------------------------------------------
void MaterialInstance::Link (InStream& source)
{
	Object::Link(source);

	if (mMaterialFilename.empty() && mInstanceTagName.empty())
	{
		source.ResolveLink(mMaterial);
	}

	source.ResolveLink(mNumPasses, mVertexParameters);
	source.ResolveLink(mNumPasses, mPixelParameters);
}
//----------------------------------------------------------------------------
void MaterialInstance::PostLink ()
{
	Object::PostLink();

	if (!mMaterialFilename.empty() && !mInstanceTagName.empty())
	{
		_RefreshMaterial(mMaterialFilename, mInstanceTagName);
	}
}
//----------------------------------------------------------------------------
bool MaterialInstance::Register (OutStream& target) const
{
	if (Object::Register(target))
	{
		if (mMaterialFilename.empty() && mInstanceTagName.empty())
		{
			target.Register(mMaterial);
		}

		target.Register(mNumPasses, mVertexParameters);
		target.Register(mNumPasses, mPixelParameters);
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void MaterialInstance::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	if (!mMaterialFilename.empty() && !mInstanceTagName.empty())
	{
		target.WriteString(mMaterialFilename);
		target.WriteString(mInstanceTagName);
	}
	else
	{
		target.WritePointer(mMaterial);
		target.Write(mTechniqueIndex);
	}

	target.WritePointerW(mNumPasses, mVertexParameters);
	target.WritePointerN(mNumPasses, mPixelParameters);

	PX2_END_DEBUG_STREAM_SAVE(MaterialInstance, target);
}
//----------------------------------------------------------------------------
int MaterialInstance::GetStreamingSize (Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);

	if (!mMaterialFilename.empty() && !mInstanceTagName.empty())
	{
		size += PX2_STRINGSIZE(mMaterialFilename);
		size += PX2_STRINGSIZE(mInstanceTagName);
	}
	else
	{
		size += PX2_POINTERSIZE(mMaterial);
		size += sizeof(mTechniqueIndex);
	}

	size += sizeof(mNumPasses);
	size += mNumPasses*PX2_POINTERSIZE(mVertexParameters[0]);
	size += mNumPasses*PX2_POINTERSIZE(mPixelParameters[0]);

	return size;
}
//----------------------------------------------------------------------------
