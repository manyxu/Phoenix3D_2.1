// PX2MaterialInstance.cpp

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
mIsShareMtl(false),
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
	const std::string &tagName, bool shareMtl) :
	mIsShareMtl(shareMtl),
	mTechniqueIndex(0),
	mMaterialFilename(mtlFilename),
	mInstanceTagName(tagName),
	mNumPasses(0),
	mVertexParameters(0),
	mPixelParameters(0)
{
	_RefreshMaterial(mMaterialFilename, mInstanceTagName,
		mVertexParameters, mPixelParameters, mIsShareMtl);
}
//----------------------------------------------------------------------------
void MaterialInstance::_RefreshMaterial(const std::string &mtlFilename,
	const std::string &tagName, ShaderParametersPtr* &vp,
	ShaderParametersPtr* &pp, bool shareMtl)
{
	// we reload the mtl
	mMaterial = PX2_MATERIALMAN.GetMaterial(mtlFilename.c_str(), shareMtl);
	assertion(mMaterial != 0, "Material must be specified.\n");

	MaterialTechnique* technique = mMaterial->GetTechnique(tagName,
		mTechniqueIndex);

	int newNumPass = technique->GetNumPasses();
	if (0 == vp)
		vp = new1<ShaderParametersPtr>(newNumPass);
	if (0 == pp)
		pp = new1<ShaderParametersPtr>(newNumPass);

	for (int p = 0; p < newNumPass; ++p)
	{
		MaterialPass* pass = technique->GetPass(p);
		VertexShader *vs = pass->GetVertexShader();
		PixelShader *ps = pass->GetPixelShader();

		_RefreshMaterialParams(vp[p], vs);
		_RefreshMaterialParams(pp[p], ps);
	}

	mNumPasses = newNumPass;
}
//----------------------------------------------------------------------------
void MaterialInstance::_RefreshMaterialParams(ShaderParametersPtr &newParam, 
	Shader *shader)
{
	if (0 == newParam)
		newParam = new0 ShaderParameters(shader);

	for (int i = 0; i < shader->GetNumConstants(); i++)
	{
		const std::string &constantName = shader->GetConstantName(i);
		int numRegister = shader->GetNumRegistersUsed(i);

		if (!newParam->GetConstant(constantName))
		{
			ShaderFloat *shaderFloat = PX2_MATERIALMAN.CreateShaderFloat(
				constantName.c_str(), numRegister);
			if (shaderFloat)
			{
				newParam->SetConstant(constantName, shaderFloat);
			}
		}
	}

	//std::vector<std::string, Texture1DPtr>

	//for (int i = 0; i < shader->GetNumSamplers(); i++)
	//{
	//	const std::string &sampleName = shader->GetSamplerName(i);
	//	
	//	// 旧的已经存在
	//	Texture *texture = newParam->GetTexture(sampleName);
	//	if (texture)
	//	{
	//		newParam->SetTexture(i, texture);
	//	}
	//}
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
int MaterialInstance::SetVertexConstant (int pass, const std::string& name, 
	ShaderFloat* sfloat)
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
mIsShareMtl(false),
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

	source.ReadBool(mIsShareMtl);

	source.ReadString(mMaterialFilename);
	source.ReadString(mInstanceTagName);

	if (mMaterialFilename.empty() && mInstanceTagName.empty())
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
		_RefreshMaterial(mMaterialFilename, mInstanceTagName,
			mVertexParameters, mPixelParameters, mIsShareMtl);
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

	target.WriteBool(mIsShareMtl);

	target.WriteString(mMaterialFilename);
	target.WriteString(mInstanceTagName);

	if (mMaterialFilename.empty() && mInstanceTagName.empty())
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

	size += PX2_BOOLSIZE(mIsShareMtl);

	size += PX2_STRINGSIZE(mMaterialFilename);
	size += PX2_STRINGSIZE(mInstanceTagName);

	if (mMaterialFilename.empty() && mInstanceTagName.empty())
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
