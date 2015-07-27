// PX2TerrainProcess.hpp

#ifndef PX2TERRAINPROCESS_HPP
#define PX2TERRAINPROCESS_HPP

#include "PX2EditPre.hpp"
#include "PX2TerrainBrush.hpp"

namespace PX2
{

	class PX2_EDIT_ITEM TerrainProcess
	{
	public:
		~TerrainProcess();

		enum TerProType
		{
			TPT_HEIGHT,
			TPT_TEXTURE,
			TPT_JUNGLER,
			TPT_MAX_TYPE
		};

		TerProType GetTerProType();

		virtual void SetBrush(TerrainBrush *brush) { mBrush = brush; }
		TerrainBrush *GetBrush() { return mBrush; }

		void SetTerrain(PX2::RawTerrain *terrain) { mTerrain = terrain; }

		virtual void Apply(bool calAverage);

	protected:
		TerrainProcess();
		TerrainProcess(TerProType type);

		TerrainBrush *mBrush;
		TerProType mTerProType;
		PX2::RawTerrainPtr mTerrain;
	};

	class TerrainHeightProcess : public TerrainProcess
	{
	public:
		TerrainHeightProcess();
		virtual ~TerrainHeightProcess();

		enum HeightMode
		{
			HM_RAISE,
			HM_LOWER,
			HM_FLATTEN,
			HM_SMOOTH,
			HM_FIXH,
			MH_HOLE,
			MH_NOHOLE,
			HM_MAX_MODE
		};

		void SetHeightMode(HeightMode mode) { mHeightMode = mode; }
		HeightMode GetHeightMode() { return mHeightMode; }
		void SetFixHVal(float val) { mFixHVal = val; }
		float GetFixHVal() const { return mFixHVal; };

		virtual void Apply(bool calAverage);

	protected:
		HeightMode mHeightMode;
		float mFixHVal;
	};

	class TerrainTextureProcess : public TerrainProcess
	{
	public:
		TerrainTextureProcess();
		virtual ~TerrainTextureProcess();

		enum TextureMode
		{
			TM_INCREASE,
			TM_DECREASE,
			TM_APPLY,
			TM_SMOOTH,
			TM_NOISE,
			TM_MAX_MODE
		};

		void SetTextureMode(TextureMode textureMode) { mTextureMode = textureMode; }
		TextureMode GetTextureMode() { return mTextureMode; }

		void SetSelectedLayer(int index) { mSelectedLayerIndex = index; }
		int GetSelectedLayer() { return mSelectedLayerIndex; }

		void SetLayerUsingTexture(int layerIndex, PX2::Texture2D *texture);
		PX2::Texture2D *GetLayerUsingTexture(int layerIndex);
		void SetSelectedLayerUsingTexture(PX2::Texture2D *texture);
		PX2::Texture2D *GetSelectedLayerUsingTexture();

		virtual void Apply(bool calAverage);

	protected:
		TextureMode mTextureMode;
		int mSelectedLayerIndex;
		std::map<int, PX2::Texture2DPtr> mLayerTextures;
	};

	class TerrainJunglerProcess : public TerrainProcess
	{
	public:
		TerrainJunglerProcess();
		virtual ~TerrainJunglerProcess();

		enum JunglerMode
		{
			JM_ADD,
			JM_REDUCE,
			JM_MAX_MODE
		};
		void SetJunglerMode(JunglerMode mode) { mMode = mode; }
		JunglerMode GetJunglerMode() { return mMode; }

		void SetUsingTexture(PX2::Texture2D *texture)
		{
			if (texture && !texture->HasMipmaps())
			{
				texture->GenerateMipmaps();
			}

			mUsingTexture = texture;
		}
		PX2::Texture2D *GetUsingTexture() { return mUsingTexture; }

		void SetWidth(float width);
		float GetWidth() { return mWidth; }
		void SetHeight(float height);
		float GetHeight() { return mHeight; }
		void SetLower(float lower);
		float GetLower() { return mLower; }

		virtual void Apply();

	protected:
		JunglerMode mMode;
		PX2::Texture2DPtr mUsingTexture;
		float mWidth;
		float mHeight;
		float mLower;
	};

}


#endif