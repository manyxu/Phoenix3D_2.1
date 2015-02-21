// PX2RenderTarget.hpp

#ifndef PX2RENDERTARGET_HPP
#define PX2RENDERTARGET_HPP

#include "PX2GraphicsPre.hpp"
#include "PX2Texture2D.hpp"

namespace PX2
{

	/// 渲染到纹理对象类
	class RenderTarget : public Object
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(RenderTarget);

	public:
		/// 构造函数
		/**
		* 支持的render target依赖于硬件。numTargets至少为1。
		*/
		RenderTarget (int numTargets, Texture::Format tformat, int width,
			int height, bool hasMipmaps, bool hasDepthStencil);

		virtual ~RenderTarget ();

		// 成员访问
		inline int GetNumTargets () const;
		inline Texture::Format GetFormat () const;
		inline int GetWidth () const;
		inline int GetHeight () const;
		inline Texture2D* GetColorTexture (int i) const;
		inline Texture2D* GetDepthStencilTexture () const;
		inline bool HasMipmaps () const;
		inline bool HasDepthStencil () const;

		void *PdrPointer;

	protected:
		int mNumTargets;
		Texture2DPtr* mColorTextures;
		Texture2DPtr mDepthStencilTexture;
		bool mHasMipmaps;
	};

	PX2_REGISTER_STREAM(RenderTarget);
	typedef Pointer0<RenderTarget> RenderTargetPtr;
#include "PX2RenderTarget.inl"

}

#endif
