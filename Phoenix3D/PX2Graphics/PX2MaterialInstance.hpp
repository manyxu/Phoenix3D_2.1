/*
* Phoenix 3D 游戏引擎 Version 2.0
*
* Copyright (C) 2009-2011 http://www.Phoenix3d.org/
*
* 文件名称	：	PX2MaterialInstance.hpp
*
* 版本		:	1.0 (2011/02/01)
*
* 作者		：	more
*
*/

#ifndef PX2MATERIALINSTANCE_HPP
#define PX2MATERIALINSTANCE_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2ShaderParameters.hpp"
#include "PX2Material.hpp"

namespace PX2
{

	class MaterialInstance : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(MaterialInstance);

	public:
		MaterialInstance(const Material* material, int techniqueIndex);
		MaterialInstance(const std::string &mtlFilename, 
			const std::string &tagName);
		virtual ~MaterialInstance ();

		// 成员访问
		/*
		* 这些主要被Renderer渲染几何图形时调用。
		*/
		inline Material* GetMaterial () const;
		inline int GetTechniqueIndex () const;
		inline int GetNumPasses () const;
		const MaterialPass* GetPass (int pass) const;
		ShaderParameters* GetVertexParameters (int pass) const;
		ShaderParameters* GetPixelParameters (int pass) const;

		// 这些函数用来设置着色器常量和纹理。如果函数成功，返回常量或者纹理在相
		// 应数组中的索引。这个返回值用作下面Set*函数中的'handle'参数，可以避免
		// 文件名的比较。
		int SetVertexConstant (int pass, const std::string& name,
			ShaderFloat* sfloat);

		int SetPixelConstant (int pass, const std::string& name,
			ShaderFloat* sfloat);

		int SetVertexTexture (int pass, const std::string& name,
			Texture* texture);

		int SetPixelTexture (int pass, const std::string& name,
			Texture* texture);

		// 'handle'由上面的Set*函数返回。
		void SetVertexConstant (int pass, int handle, ShaderFloat* sfloat);
		void SetPixelConstant (int pass, int handle, ShaderFloat* sfloat);
		void SetVertexTexture (int pass, int handle, Texture* texture);
		void SetPixelTexture (int pass, int handle, Texture* texture);

		// 获得着色器常量和纹理
		ShaderFloat* GetVertexConstant (int pass, const std::string& name) const;
		ShaderFloat* GetPixelConstant (int pass, const std::string& name) const;
		Texture* GetVertexTexture (int pass, const std::string& name) const;
		Texture* GetPixelTexture (int pass, const std::string& name) const;

		// 'handle'由上面的Set*函数返回。
		ShaderFloat* GetVertexConstant (int pass, int handle) const;
		ShaderFloat* GetPixelConstant (int pass, int handle) const;
		Texture* GetVertexTexture (int pass, int handle) const;
		Texture* GetPixelTexture (int pass, int handle) const;

	protected:
		void _RefreshMaterial(const std::string &mtlFilename,
			const std::string &intanceName);
		void _RefreshMaterialParams(ShaderParametersPtr &newParam, Shader *shader);

		MaterialPtr mMaterial;
		int mTechniqueIndex;

		std::string mMaterialFilename;
		std::string mInstanceTagName;
		
		int mNumPasses;
		ShaderParametersPtr* mVertexParameters;
		ShaderParametersPtr* mPixelParameters;
	};

	PX2_REGISTER_STREAM(MaterialInstance);
	typedef Pointer0<MaterialInstance> MaterialInstancePtr;
#include "PX2MaterialInstance.inl"

}

#endif
