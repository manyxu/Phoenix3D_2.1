/*
*
* ÎÄ¼þÃû³Æ	£º	PX2UIPicBox.hpp
*
*/

#ifndef PX2UIPICBOX_HPP
#define PX2UIPICBOX_HPP

#include "PX2UIPre.hpp"
#include "PX2Float2.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"
#include "PX2Texture2D.hpp"
#include "PX2Material.hpp"
#include "PX2MaterialInstance.hpp"
#include "PX2TriMesh.hpp"
#include "PX2Camera.hpp"
#include "PX2TexPackData.hpp"

namespace PX2
{

	class UIPicBox : public TriMesh
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIPicBox);

	public:
		UIPicBox(const std::string &filename = "Data/engine/default.png",
			bool isDynamicBuffer=false);
		UIPicBox(const std::string &packName, const std::string &eleName,
			bool isDynamicBuffer=false);
		virtual ~UIPicBox();

		enum PicBoxType
		{
			PBT_NORMAL,
			PBT_NINE,
			PBT_MAX_TYPE
		};
		void SetPicBoxType(PicBoxType type);
		PicBoxType GetPicBoxType();

		// anchor
		void SetAnchorPoint(float anchX, float anchZ);
		void SetAnchorPoint(Float2 anchor);
		const Float2 &GetAnchorPoint() const;
		Float2 &GetAnchorPoint();

		// size
		void SetSize(float width, float height);
		void SetSize(const Sizef &size);
		const Sizef &GetSize() const;
		void SetWidth(float width);
		float GetWidth() const;
		void SetHeight(float height);
		float GetHeight() const;
		void MakeSizeWithTex();

		// cornorsize
		void SetTexCornerSize(float width, float height);
		void SetTexCornerSize(const Sizef &size);
		const Sizef &GetTexCornerSize() const;
		Sizef &GetTexCornerSize();
		void SetTexCornerWidth(float width);
		float GetTexCornerWidth() const;
		void SetTexCornerHeight(float height);
		float GetTexCornerHeight() const;

		// alpha color
		virtual void SetAlpha(float alpha); //< 0-1
		virtual void SetColor(const Float3 &color);

		enum TexMode
		{
			TM_TEX,
			TM_TEXPACK_ELE,
			TM_MAX_MODE
		};
		TexMode GetTexMode() const;

		// base texture
		void SetTexture(const std::string &filename);
		void SetTexture(const std::string &texPackName, const std::string &eleName);
		const std::string &GetTextureFilename() const;
		void SetUVRepeat(const Float2 &uvRepeat);

		virtual void OnForceBind();

	public_internal:
		void UIAfterPicked(int info);

	protected:
		void _Init();
		virtual void UpdateWorldData(double applicationTime);

		void UpdateBuffers(float elapsedTime);
		void UpdateVertexBuffer(float elapsedTime, const std::vector<Float2> &uvs);
		void UpdateIndexBuffer();
		void ReCreateVBuffer();

		virtual void OnPicked(int info);
		virtual void OnNotPicked(int pickInfo);

		bool mIsDynamic;

		PicBoxType mPicBoxType;
		Float2 mAnchorPoint;
		Sizef mSize;
		Sizef mCornerSize;

		TexPackElement mPackEle;
		bool mIsBufferNeedUpdate;

		TexMode mTexMode;
		std::string mTexturePathname;
		std::string mTexturePackName;
		std::string mElementName;
	};

	PX2_REGISTER_STREAM(UIPicBox);
	typedef Pointer0<UIPicBox> UIPicBoxPtr;
#include "PX2UIPicBox.inl"

}

#endif