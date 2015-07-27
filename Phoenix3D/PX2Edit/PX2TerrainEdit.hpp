// PX2TerrainEdit.hpp

#ifndef PX2TERRAINEDIT_HPP
#define PX2TERRAINEDIT_HPP

#include "PX2EditPre.hpp"
#include "PX2TerrainBrush.hpp"
#include "PX2TerrainProcess.hpp"
#include "PX2LODTerrain.hpp"
#include "PX2TerrainActor.hpp"

namespace PX2
{

	class PX2_EDIT_ITEM TerrainEdit
	{
	public:
		TerrainEdit();
		~TerrainEdit();

		void EnableEdit();
		void DisableEdit();
		void ShowPageLine(bool show);
		bool IsPageLineShow();

		void UseLodTerrain(bool use);
		bool IsUseLodTerrain();

		void SetEditType(TerrainProcess::TerProType type);
		TerrainProcess::TerProType GetEditType();

		TerrainBrush *GetBrush() { return mBrush; }

		TerrainHeightProcess *GetHeightProcess() { return mHeightProcess; }
		TerrainTextureProcess *GetTextureProcess() { return mTextureProcess; }
		TerrainJunglerProcess *GetJunglerProcess() { return mJunglerProcess; }

		PX2::Renderable *GetTerrainHelpGrid() { return mTerrainHelpGrid; }

		// Do
		void Apply(bool calAverage);

	public_internal:
		void SetTerrain(PX2::RawTerrain *terrain);

	protected:
		PX2::LODTerrain *CreateLODTerrain(PX2::RawTerrain *rawTerrain);
		void CreateTerrainHelpGrid();
		void DestoryTerrainHelpGrid();

		bool mIsUsingLodTerrain;
		PX2::RawTerrainPtr mTerrain;
		TerrainBrush *mBrush;
		TerrainProcess *mActiveProcess;
		TerrainHeightProcess *mHeightProcess;
		TerrainTextureProcess *mTextureProcess;
		TerrainJunglerProcess *mJunglerProcess;
		PX2::RenderablePtr mTerrainHelpGrid;
	};

}

#endif