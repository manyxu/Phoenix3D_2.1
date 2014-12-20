/*
*
* 文件名称	：	PX2Material.cpp
*
*/

#include "PX2Material.hpp"
#include "PX2Renderable.hpp"
using namespace PX2;

PX2_IMPLEMENT_RTTI(PX2, Object, Material);
PX2_IMPLEMENT_STREAM(Material);
PX2_IMPLEMENT_FACTORY(Material);

//----------------------------------------------------------------------------
Material::Material ()
{
	SetName("Mtl");
}
//----------------------------------------------------------------------------
Material::~Material ()
{
}
//----------------------------------------------------------------------------
void Material::InsertTechnique (MaterialTechnique* technique)
{
	if (technique)
	{
		mTechniques.push_back(technique);
	}
	else
	{
		assertion(false, "Input to InsertTechnique must be nonnull.\n");
	}
}
//----------------------------------------------------------------------------
MaterialTechnique* Material::GetTechnique (int techniqueIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex];
	}

	assertion(false, "Invalid index in GetTechnique.\n");
	return 0;
}
//----------------------------------------------------------------------------
int Material::GetNumPasses (int techniqueIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetNumPasses();
	}

	assertion(false, "Invalid index in GetNumPasses.\n");
	return 0;
}
//----------------------------------------------------------------------------
MaterialPass* Material::GetPass (int techniqueIndex, int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetPass(passIndex);
	}

	assertion(false, "Invalid index in GetPass.\n");
	return 0;
}
//----------------------------------------------------------------------------
VertexShader* Material::GetVertexShader (int techniqueIndex,
											 int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetVertexShader(passIndex);
	}

	assertion(false, "Invalid index in GetVertexShader.\n");
	return 0;
}
//----------------------------------------------------------------------------
PixelShader* Material::GetPixelShader (int techniqueIndex,
										   int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetPixelShader(passIndex);
	}

	assertion(false, "Invalid index in GetPixelShader.\n");
	return 0;
}
//----------------------------------------------------------------------------
AlphaProperty* Material::GetAlphaProperty (int techniqueIndex,
										 int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetAlphaProperty(passIndex);
	}

	assertion(false, "Invalid index in GetAlphaProperty.\n");
	return 0;
}
//----------------------------------------------------------------------------
CullProperty* Material::GetCullProperty (int techniqueIndex,
									   int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetCullProperty(passIndex);
	}

	assertion(false, "Invalid index in GetCullProperty.\n");
	return 0;
}
//----------------------------------------------------------------------------
DepthProperty* Material::GetDepthProperty (int techniqueIndex,
										 int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetDepthProperty(passIndex);
	}

	assertion(false, "Invalid index in GetDepthProperty.\n");
	return 0;
}
//----------------------------------------------------------------------------
OffsetProperty* Material::GetOffsetProperty (int techniqueIndex,
										   int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetOffsetProperty(passIndex);
	}

	assertion(false, "Invalid index in GetOffsetProperty.\n");
	return 0;
}
//----------------------------------------------------------------------------
StencilProperty* Material::GetStencilProperty (int techniqueIndex,
											 int passIndex) const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetStencilProperty(passIndex);
	}

	assertion(false, "Invalid index in GetStencilProperty.\n");
	return 0;
}
//----------------------------------------------------------------------------
WireProperty* Material::GetWireProperty (int techniqueIndex, int passIndex)
const
{
	if (0 <= techniqueIndex && techniqueIndex < (int)mTechniques.size())
	{
		return mTechniques[techniqueIndex]->GetWireProperty(passIndex);
	}

	assertion(false, "Invalid index in GetWireProperty.\n");
	return 0;
}
//----------------------------------------------------------------------------
void Material::_CalShaderKey ()
{
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Property
//----------------------------------------------------------------------------
void Material::RegistProperties ()
{
	Object::RegistProperties();

	AddPropertyClass("Material");

	int numTech = GetNumTechniques();
	AddProperty("NumTechniques", Object::PT_INT, numTech, false);
}
//----------------------------------------------------------------------------
void Material::OnPropertyChanged (const PropertyObject &obj)
{
	Object::OnPropertyChanged(obj);
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Begin load/save
//----------------------------------------------------------------------------
Material* Material::LoadPX2fx (const std::string& name, int mode)
{
	return new0 Material(name, mode);
}
//----------------------------------------------------------------------------
void Material::SavePX2fx (const std::string& name, int mode)
{
	FileIO outFile(name, mode);
	if (!outFile)
	{
		assertion(false, "Failed to open file %s\n", name.c_str());
		return;
	}

	int numTechniques = (int)mTechniques.size();
	outFile.Write(sizeof(int), &numTechniques);
	for (int i = 0; i < numTechniques; ++i)
	{
		SaveMaterialTechnique(outFile, mTechniques[i]);
	}

	outFile.Close();
}
//----------------------------------------------------------------------------
Material::Material (const std::string& name, int mode)
{
	FileIO inFile(name, mode);
	if (!inFile)
	{
		assertion(false, "Failed to open file %s\n", name.c_str());
		return;
	}

	int numTechniques;
	inFile.Read(sizeof(int), &numTechniques);
	for (int i = 0; i < numTechniques; ++i)
	{
		InsertTechnique(LoadMaterialTechnique(inFile));
	}

	inFile.Close();
}
//----------------------------------------------------------------------------
MaterialTechnique* Material::LoadMaterialTechnique (FileIO& inFile)
{
	MaterialTechnique* technique = new0 MaterialTechnique();

	int numPasses;
	inFile.Read(sizeof(int), &numPasses);
	for (int i = 0; i < numPasses; ++i)
	{
		technique->InsertPass(LoadMaterialPass(inFile));
	}
	return technique;
}
//----------------------------------------------------------------------------
MaterialPass* Material::LoadMaterialPass (FileIO& inFile)
{
	MaterialPass* pass = new0 MaterialPass();

	pass->SetVertexShader((VertexShader*)LoadShader(inFile, true));
	pass->SetPixelShader((PixelShader*)LoadShader(inFile, false));
	pass->SetAlphaProperty(LoadAlphaProperty(inFile));
	pass->SetCullProperty(LoadCullProperty(inFile));
	pass->SetDepthProperty(LoadDepthProperty(inFile));
	pass->SetOffsetProperty(LoadOffsetProperty(inFile));
	pass->SetStencilProperty(LoadStencilProperty(inFile));
	pass->SetWireProperty(LoadWireProperty(inFile));

	return pass;
}
//----------------------------------------------------------------------------
Shader* Material::LoadShader (FileIO& inFile, bool isVertexShader)
{
	std::string programName = LoadString(inFile);

	int numInputs, numOutputs, numConstants, numSamplers, numProfiles;
	inFile.Read(sizeof(int), &numInputs);
	inFile.Read(sizeof(int), &numOutputs);
	inFile.Read(sizeof(int), &numConstants);
	inFile.Read(sizeof(int), &numSamplers);
	inFile.Read(sizeof(int), &numProfiles);

	Shader* shader;
	if (isVertexShader)
	{
		shader = new0 VertexShader(programName, numInputs, numOutputs,
			numConstants, numSamplers, true);
	}
	else
	{
		shader = new0 PixelShader(programName, numInputs, numOutputs,
			numConstants, numSamplers, true);
	}

	std::string name;
	int i, type, semantic, numRegistersUsed, filter, coord[3];
	float lodBias, anisotropy;
	Float4 borderColor;

	for (i = 0; i < numInputs; ++i)
	{
		name = LoadString(inFile);
		inFile.Read(sizeof(int), &type);
		inFile.Read(sizeof(int), &semantic);
		shader->SetInput(i, name, (Shader::VariableType)type,
			(Shader::VariableSemantic)semantic);
	}

	for (i = 0; i < numOutputs; ++i)
	{
		name = LoadString(inFile);
		inFile.Read(sizeof(int), &type);
		inFile.Read(sizeof(int), &semantic);
		shader->SetOutput(i, name, (Shader::VariableType)type,
			(Shader::VariableSemantic)semantic);
	}

	for (i = 0; i < numConstants; ++i)
	{
		name = LoadString(inFile);
		inFile.Read(sizeof(int), &numRegistersUsed);
		shader->SetConstant(i, name, numRegistersUsed);
	}

	for (i = 0; i < numSamplers; ++i)
	{
		name = LoadString(inFile);
		inFile.Read(sizeof(int), &type);
		inFile.Read(sizeof(int), &filter);
		inFile.Read(sizeof(int), 3, coord);
		inFile.Read(sizeof(float), &lodBias);
		inFile.Read(sizeof(float), &anisotropy);
		inFile.Read(sizeof(float), 4, &borderColor[0]);
		shader->SetSampler(i, name, (Shader::SamplerType)type);
		shader->SetFilter(i, (Shader::SamplerFilter)filter);
		shader->SetCoordinate(i, 0, (Shader::SamplerCoordinate)coord[0]);
		shader->SetCoordinate(i, 1, (Shader::SamplerCoordinate)coord[1]);
		shader->SetCoordinate(i, 2, (Shader::SamplerCoordinate)coord[2]);
		shader->SetLodBias(i, lodBias);
		shader->SetAnisotropy(i, anisotropy);
		shader->SetBorderColor(i, borderColor);
	}

	for (i = 0; i < numProfiles; ++i)
	{
		inFile.Read(sizeof(int), &type);
		if (0 <= type && type < Shader::MAX_PROFILES)
		{
			std::string programName = LoadString(inFile);
			shader->SetProgram(i, programName);

			if (programName != "")
			{
				int j;
				for (j = 0; j < numConstants; ++j)
				{
					int baseRegister;
					inFile.Read(sizeof(int), &baseRegister);
					shader->SetBaseRegister(i, j, baseRegister);
				}

				for (j = 0; j < numSamplers; ++j)
				{
					int textureUnit;
					inFile.Read(sizeof(int), &textureUnit);
					shader->SetTextureUnit(i, j, textureUnit);
				}
			}
		}
		else
		{
			assertion(false, "Invalid profile.\n");
		}
	}

	return shader;
}
//----------------------------------------------------------------------------
AlphaProperty* Material::LoadAlphaProperty (FileIO& inFile)
{
	int blendEnabled, srcBlend, dstBlend, compareEnabled, compare;
	float reference;
	Float4 constantColor;
	inFile.Read(sizeof(int), &blendEnabled);
	inFile.Read(sizeof(int), &srcBlend);
	inFile.Read(sizeof(int), &dstBlend);
	inFile.Read(sizeof(int), &compareEnabled);
	inFile.Read(sizeof(int), &compare);
	inFile.Read(sizeof(float), &reference);
	inFile.Read(sizeof(float), 4, &constantColor[0]);

	AlphaProperty* aproperty = new0 AlphaProperty();
	aproperty->BlendEnabled = (blendEnabled != 0);
	aproperty->SrcBlend = (AlphaProperty::SrcBlendMode)srcBlend;
	aproperty->DstBlend = (AlphaProperty::DstBlendMode)dstBlend;
	aproperty->CompareEnabled = (compareEnabled != 0);
	aproperty->Compare = (AlphaProperty::CompareMode)compare;
	aproperty->Reference = reference;
	aproperty->ConstantColor = constantColor;

	return aproperty;
}
//----------------------------------------------------------------------------
CullProperty* Material::LoadCullProperty (FileIO& inFile)
{
	int enabled, ccwOrder;
	inFile.Read(sizeof(int), &enabled);
	inFile.Read(sizeof(int), &ccwOrder);

	CullProperty* cproperty = new0 CullProperty();
	cproperty->Enabled = (enabled != 0);
	cproperty->CCWOrder = (ccwOrder != 0);

	return cproperty;
}
//----------------------------------------------------------------------------
DepthProperty* Material::LoadDepthProperty (FileIO& inFile)
{
	int enabled, writable, compare;
	inFile.Read(sizeof(int), &enabled);
	inFile.Read(sizeof(int), &writable);
	inFile.Read(sizeof(int), &compare);

	DepthProperty* dproperty = new0 DepthProperty();
	dproperty->Enabled = (enabled != 0);
	dproperty->Writable = (writable != 0);
	dproperty->Compare = (DepthProperty::CompareMode)compare;

	return dproperty;
}
//----------------------------------------------------------------------------
OffsetProperty* Material::LoadOffsetProperty (FileIO& inFile)
{
	int fillEnabled, lineEnabled, pointEnabled;
	float scale, bias;
	inFile.Read(sizeof(int), &fillEnabled);
	inFile.Read(sizeof(int), &lineEnabled);
	inFile.Read(sizeof(int), &pointEnabled);
	inFile.Read(sizeof(float), &scale);
	inFile.Read(sizeof(float), &bias);

	OffsetProperty* oproperty = new0 OffsetProperty();
	oproperty->FillEnabled = (fillEnabled != 0);
	oproperty->LineEnabled = (lineEnabled != 0);
	oproperty->PointEnabled = (pointEnabled != 0);
	oproperty->Scale = scale;
	oproperty->Bias = bias;

	return oproperty;
}
//----------------------------------------------------------------------------
StencilProperty* Material::LoadStencilProperty (FileIO& inFile)
{
	int enabled, compare, onFail, onZFail, onZPass;
	unsigned int reference, mask, writeMask;
	inFile.Read(sizeof(int), &enabled);
	inFile.Read(sizeof(int), &compare);
	inFile.Read(sizeof(unsigned int), &reference);
	inFile.Read(sizeof(unsigned int), &mask);
	inFile.Read(sizeof(unsigned int), &writeMask);
	inFile.Read(sizeof(int), &onFail);
	inFile.Read(sizeof(int), &onZFail);
	inFile.Read(sizeof(int), &onZPass);

	StencilProperty* sproperty = new0 StencilProperty();
	sproperty->Enabled = (enabled != 0);
	sproperty->Compare = (StencilProperty::CompareMode)compare;
	sproperty->Reference = reference;
	sproperty->Mask = mask;
	sproperty->WriteMask = writeMask;
	sproperty->OnFail = (StencilProperty::OperationType)onFail;
	sproperty->OnZFail = (StencilProperty::OperationType)onZFail;
	sproperty->OnZFail = (StencilProperty::OperationType)onZPass;

	return sproperty;
}
//----------------------------------------------------------------------------
WireProperty* Material::LoadWireProperty (FileIO& inFile)
{
	int enabled;
	inFile.Read(sizeof(int), &enabled);

	WireProperty* wproperty = new0 WireProperty();
	wproperty->Enabled = (enabled != 0);

	return wproperty;
}
//----------------------------------------------------------------------------
std::string Material::LoadString (FileIO& inFile)
{
	int length;
	inFile.Read(sizeof(int), &length);
	if (length <= 0)
	{
		return std::string("");
	}

	// 字符串被按照4字节倍数写入
	int padding = (length % 4);
	if (padding > 0)
	{
		padding = 4 - padding;
	}

	int numBytes = length + padding;
	char* text = new1<char>(numBytes);
	inFile.Read(sizeof(char), numBytes, text);

	std::string name;
	name.assign(text, length);
	delete1(text);

	return name;
}
//----------------------------------------------------------------------------
void Material::SaveMaterialTechnique (FileIO& outFile,
										MaterialTechnique* technique)
{
	int numPasses = technique->GetNumPasses();
	outFile.Write(sizeof(int), &numPasses);
	for (int i = 0; i < numPasses; ++i)
	{
		SaveMaterialPass(outFile, technique->GetPass(i));
	}
}
//----------------------------------------------------------------------------
void Material::SaveMaterialPass (FileIO& outFile, MaterialPass* pass)
{
	SaveShader(outFile, pass->GetVertexShader());
	SaveShader(outFile, pass->GetPixelShader());
	SaveAlphaProperty(outFile, pass->GetAlphaProperty());
	SaveCullProperty(outFile, pass->GetCullProperty());
	SaveDepthProperty(outFile, pass->GetDepthProperty());
	SaveOffsetProperty(outFile, pass->GetOffsetProperty());
	SaveStencilProperty(outFile, pass->GetStencilProperty());
	SaveWireProperty(outFile, pass->GetWireProperty());
}
//----------------------------------------------------------------------------
void Material::SaveShader (FileIO& outFile, Shader* shader)
{
	std::string programName = shader->GetName();
	SaveString(outFile, programName);

	int numInputs = shader->GetNumInputs();
	int numOutputs = shader->GetNumOutputs();
	int numConstants = shader->GetNumConstants();
	int numSamplers = shader->GetNumSamplers();
	int numProfiles = Shader::MAX_PROFILES;
	outFile.Write(sizeof(int), &numInputs);
	outFile.Write(sizeof(int), &numOutputs);
	outFile.Write(sizeof(int), &numConstants);
	outFile.Write(sizeof(int), &numSamplers);
	outFile.Write(sizeof(int), &numProfiles);

	std::string name;
	int i, type, semantic, numRegistersUsed, filter, coord[3];
	float lodBias, anisotropy;
	Float4 borderColor;

	for (i = 0; i < numInputs; ++i)
	{
		name = shader->GetInputName(i);
		type = (int)shader->GetInputType(i);
		semantic = (int)shader->GetInputSemantic(i);
		SaveString(outFile, name);
		outFile.Write(sizeof(int), &type);
		outFile.Write(sizeof(int), &semantic);
	}

	for (i = 0; i < numOutputs; ++i)
	{
		name = shader->GetOutputName(i);
		type = (int)shader->GetOutputType(i);
		semantic = (int)shader->GetOutputSemantic(i);
		SaveString(outFile, name);
		outFile.Write(sizeof(int), &type);
		outFile.Write(sizeof(int), &semantic);
	}

	for (i = 0; i < numConstants; ++i)
	{
		name = shader->GetConstantName(i);
		numRegistersUsed = shader->GetNumRegistersUsed(i);
		SaveString(outFile, name);
		outFile.Write(sizeof(int), &numRegistersUsed);
	}

	for (i = 0; i < numSamplers; ++i)
	{
		name = shader->GetSamplerName(i);
		type = shader->GetSamplerType(i);
		filter = shader->GetFilter(i);
		coord[0] = shader->GetCoordinate(i, 0);
		coord[1] = shader->GetCoordinate(i, 1);
		coord[2] = shader->GetCoordinate(i, 2);
		lodBias = shader->GetLodBias(i);
		anisotropy = shader->GetAnisotropy(i);
		borderColor = shader->GetBorderColor(i);

		SaveString(outFile, name);
		outFile.Write(sizeof(int), &type);
		outFile.Write(sizeof(int), &filter);
		outFile.Write(sizeof(int), 3, coord);
		outFile.Write(sizeof(float), &lodBias);
		outFile.Write(sizeof(float), &anisotropy);
		outFile.Write(sizeof(float), 4, &borderColor[0]);
	}

	for (i = 0; i < numProfiles; ++i)
	{
		outFile.Write(sizeof(int), &i);
		std::string programString = *shader->GetProgram(i);
		SaveString(outFile, programString);

		if (programString != "")
		{
			int j;
			for (j = 0; j < numConstants; ++j)
			{
				// TEST program for not "" before "get"
				int baseRegister = shader->GetBaseRegister(i, j);
				outFile.Write(sizeof(int), &baseRegister);
			}
			for (j = 0; j < numSamplers; ++j)
			{
				int textureUnit = shader->GetTextureUnit(i, j);
				outFile.Write(sizeof(int), &textureUnit);
			}
		}
	}
}
//----------------------------------------------------------------------------
void Material::SaveAlphaProperty (FileIO& outFile, AlphaProperty* aproperty)
{
	int blendEnabled = (aproperty->BlendEnabled ? 1 : 0);
	int srcBlend = (int)aproperty->SrcBlend;
	int dstBlend = (int)aproperty->DstBlend;
	int compareEnabled = (aproperty->CompareEnabled ? 1 : 0);
	int compare = (int)aproperty->Compare;
	float reference = aproperty->Reference;
	Float4 constantColor = aproperty->ConstantColor;

	outFile.Write(sizeof(int), &blendEnabled);
	outFile.Write(sizeof(int), &srcBlend);
	outFile.Write(sizeof(int), &dstBlend);
	outFile.Write(sizeof(int), &compareEnabled);
	outFile.Write(sizeof(int), &compare);
	outFile.Write(sizeof(float), &reference);
	outFile.Write(sizeof(float), 4, &constantColor[0]);
}
//----------------------------------------------------------------------------
void Material::SaveCullProperty (FileIO& outFile, CullProperty* cproperty)
{
	int enabled = (cproperty->Enabled ? 1 : 0);
	int ccwOrder = (cproperty->CCWOrder ? 1 : 0);

	outFile.Write(sizeof(int), &enabled);
	outFile.Write(sizeof(int), &ccwOrder);
}
//----------------------------------------------------------------------------
void Material::SaveDepthProperty (FileIO& outFile, DepthProperty* dproperty)
{
	int enabled = (dproperty->Enabled ? 1 : 0);
	int writable = (dproperty->Writable ? 1 : 0);
	int compare = (int)dproperty->Compare;

	outFile.Write(sizeof(int), &enabled);
	outFile.Write(sizeof(int), &writable);
	outFile.Write(sizeof(int), &compare);
}
//----------------------------------------------------------------------------
void Material::SaveOffsetProperty (FileIO& outFile, OffsetProperty* oproperty)
{
	int fillEnabled = (oproperty->FillEnabled ? 1 : 0);
	int lineEnabled = (oproperty->LineEnabled ? 1 : 0);
	int pointEnabled = (oproperty->PointEnabled ? 1 : 0);
	float scale = oproperty->Scale;
	float bias = oproperty->Bias;

	outFile.Write(sizeof(int), &fillEnabled);
	outFile.Write(sizeof(int), &lineEnabled);
	outFile.Write(sizeof(int), &pointEnabled);
	outFile.Write(sizeof(float), &scale);
	outFile.Write(sizeof(float), &bias);
}
//----------------------------------------------------------------------------
void Material::SaveStencilProperty (FileIO& outFile, StencilProperty* sproperty)
{
	int enabled = (sproperty->Enabled ? 1 : 0);
	int compare = (int)sproperty->Compare;
	unsigned int reference = sproperty->Reference;
	unsigned int mask = sproperty->Mask;
	unsigned int writeMask = sproperty->WriteMask;
	int onFail = (int)sproperty->OnFail;
	int onZFail = (int)sproperty->OnZFail;
	int onZPass = (int)sproperty->OnZPass;

	outFile.Write(sizeof(int), &enabled);
	outFile.Write(sizeof(int), &compare);
	outFile.Write(sizeof(unsigned int), &reference);
	outFile.Write(sizeof(unsigned int), &mask);
	outFile.Write(sizeof(unsigned int), &writeMask);
	outFile.Write(sizeof(int), &onFail);
	outFile.Write(sizeof(int), &onZFail);
	outFile.Write(sizeof(int), &onZPass);
}
//----------------------------------------------------------------------------
void Material::SaveWireProperty (FileIO& outFile, WireProperty* wproperty)
{
	int enabled = (wproperty->Enabled ? 1 : 0);

	outFile.Write(sizeof(int), &enabled);
}
//----------------------------------------------------------------------------
void Material::SaveString (FileIO& outFile, std::string& name)
{
	int length = (int)name.length();
	outFile.Write(sizeof(int), &length);
	if (length > 0)
	{
		outFile.Write(sizeof(char), length, name.c_str());

		// 字符串被按照4bytes倍数被写入
		char zero[4] = { 0, 0, 0, 0 };
		int padding = (length % 4);
		if (padding > 0)
		{
			padding = 4 - padding;
			outFile.Write(sizeof(char), padding, zero);
		}
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 名称
//----------------------------------------------------------------------------
Object* Material::GetObjectByName (const std::string& name)
{
	Object* found = Object::GetObjectByName(name);
	if (found)
	{
		return found;
	}

	std::vector<MaterialTechniquePtr>::iterator iter = mTechniques.begin();
	std::vector<MaterialTechniquePtr>::iterator end = mTechniques.end();
	for (/**/; iter != end; ++iter)
	{
		PX2_GET_OBJECT_BY_NAME((*iter), name, found);
	}

	return 0;
}
//----------------------------------------------------------------------------
void Material::GetAllObjectsByName (const std::string& name,
										std::vector<Object*>& objects)
{
	Object::GetAllObjectsByName(name, objects);

	std::vector<MaterialTechniquePtr>::iterator iter = mTechniques.begin();
	std::vector<MaterialTechniquePtr>::iterator end = mTechniques.end();
	for (/**/; iter != end; ++iter)
	{
		PX2_GET_ALL_OBJECTS_BY_NAME((*iter), name, objects);
	}
}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// 持久化
//----------------------------------------------------------------------------
Material::Material (LoadConstructor value)
:
Object(value)
{
}
//----------------------------------------------------------------------------
void Material::Load (InStream& source)
{
	PX2_BEGIN_DEBUG_STREAM_LOAD(source);

	Object::Load(source);
	PX2_VERSION_LOAD(source);

	int numTechniques;
	source.Read(numTechniques);
	mTechniques.resize(numTechniques);
	source.ReadPointerVV(numTechniques, &mTechniques[0]);

	PX2_END_DEBUG_STREAM_LOAD(Material, source);
}
//----------------------------------------------------------------------------
void Material::Link (InStream& source)
{
	Object::Link(source);

	std::vector<MaterialTechniquePtr>::iterator iter = mTechniques.begin();
	std::vector<MaterialTechniquePtr>::iterator end = mTechniques.end();
	for (/**/; iter != end; ++iter)
	{
		source.ResolveLink(*iter);
	}
}
//----------------------------------------------------------------------------
void Material::PostLink ()
{
	Object::PostLink();
}
//----------------------------------------------------------------------------
bool Material::Register (OutStream& target) const
{
	if (Object::Register(target))
	{
		std::vector<MaterialTechniquePtr>::const_iterator iter =
			mTechniques.begin();
		std::vector<MaterialTechniquePtr>::const_iterator end = mTechniques.end();
		for (/**/; iter != end; ++iter)
		{
			target.Register(*iter);
		}
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------
void Material::Save (OutStream& target) const
{
	PX2_BEGIN_DEBUG_STREAM_SAVE(target);

	Object::Save(target);
	PX2_VERSION_SAVE(target);

	target.WritePointerW((int)mTechniques.size(), &mTechniques[0]);

	PX2_END_DEBUG_STREAM_SAVE(Material, target);
}
//----------------------------------------------------------------------------
int Material::GetStreamingSize (Stream &stream) const
{
	int size = Object::GetStreamingSize(stream);
	size += PX2_VERSION_SIZE(mVersion);
	int numTechniques = (int)mTechniques.size();
	size += sizeof(numTechniques);
	size += numTechniques*PX2_POINTERSIZE(mTechniques[0]);
	return size;
}
//----------------------------------------------------------------------------