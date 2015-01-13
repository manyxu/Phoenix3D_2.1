// PX2UIPicBox.hpp

#ifndef PX2UIPICBOX_HPP
#define PX2UIPICBOX_HPP

#include "PX2UIPre.hpp"
#include "PX2Float2.hpp"
#include "PX2Size.hpp"
#include "PX2Rect.hpp"
#include "PX2TriMesh.hpp"

namespace PX2
{

	class UIPicBox : public TriMesh
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(UIPicBox);

	public:
		UIPicBox(const std::string &filename = "Data/engine/default.png");
		UIPicBox(const std::string &packName, const std::string &eleName);
		virtual ~UIPicBox();

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

	public_internal:
		void UIAfterPicked(int info);

	protected:
		void _Init();
		virtual void UpdateWorldData(double applicationTime);

		void UpdateBuffers(float elapsedTime);
		void UpdateVertexBuffer(float elapsedTime);
		void UpdateIndexBuffer();
		void UpdateDynBuffers(float elapsedTime);
		void ReCreateVBuffer();

		void UpdateMtl();
		void SetTextureNoRecreateBuffer(const std::string &texPackName,
			std::string eleName);

		virtual void OnPicked(int info);
		virtual void OnNotPicked(int pickInfo);
	};

	PX2_REGISTER_STREAM(UIPicBox);
	typedef Pointer0<UIPicBox> UIPicBoxPtr;
#include "PX2UIPicBox.inl"

}

#endif