// PX2Edit.hpp

#ifndef PX2EDIT_HPP
#define PX2EDIT_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2EditMap.hpp"
#include "PX2EditDefine.hpp"
#include "PX2GeoObjFactory.hpp"
#include "PX2EditParams.hpp"
#include "PX2SelectResData.hpp"
#include "PX2EditTimeLineEdit.hpp"
#include "PX2TerrainEdit.hpp"

namespace PX2
{

	class EditMap;
	class EditParams;

	class Edit : public Singleton<Edit>
	{
	public:
		Edit();
		~Edit();

		bool Initlize();
		bool Ternamate();
		void Reset();

		Node *GetHelpNode() { return mHelpNode; }

	protected:
		PX2::NodePtr mHelpNode;

	public:
		enum EditType
		{
			ET_SCENE,
			ET_TERRAIN,
			ET_UI,
			ET_SIMULATE,
			ET_PLAY,
			ET_MAXTYPE
		};
		void SetEditType(EditType type);
		EditType GetEditType() const;
		bool CanDoEdit() const;

		enum EditAxisMode
		{
			EAM_WORLD,
			EAM_LOCAL,
			EAM_PARENT,
			EMA_MAX_MODE
		};
		void SetEditAxisMode(EditAxisMode mode);
		EditAxisMode GetEdtiAxisMode() const;

		enum EditMode
		{
			EM_NONE,
			EM_SELECT,
			EM_TRANSLATE,
			EM_ROLATE,
			EM_SCALE,
			EM_MAX_MODE
		};
		void SetEditMode(EditMode mode);
		EditMode GetEditMode() const;

		EditMap *GetEditMap();

	protected:
		EditType mEditType;
		EditAxisMode mEditAxisMode;
		EditMode mEditMode;
		EditMap *mEditMap;

	public:
		GeoObjFactory *GetGOF();

		static int GetEditID();

	protected:
		GeoObjFactory *mGeoObjFactory;

		static int msEditorID;

	public:
		EditParams *GetEditParams();

	protected:
		EditParamsPtr mEditParams;

		// key
	public:
		bool IsAltDown;
		bool IsCtrlDown;
		bool IsShiftDown;
		bool IsKeyDown_W;
		bool IsKeyDown_S;
		bool IsKeyDown_A;
		bool IsKeyDown_D;
		bool IsLeftMouseDown;
		bool IsRightMouseDown;
		bool IsMidMouseDown;

	public:
		void SetCameraMoveLevel(int level);
		int GetCameraMoveLevel() const;
		float GetCameraMoveSpeedBase() const;
		float GetCameraMoveSpeed() const;

	protected:
		int mCameraMoveLevel;
		float mCameraMoveSpeedBase;

		// Pick
	public:
		void SetPickPos(const APoint &pos);
		const APoint &GetPickPos() const;

	protected:
		APoint mPickPos;

		// Select
	public:
		bool DeleteSelection();

		// select res
	public:
		void SetSelectPath_ChildFilenames(const std::vector<std::string> &filenamess);
		void SetSelectPath_ChildPaths(const std::vector<std::string> &paths);
		const std::vector<std::string> &GetSelectPath_ChildFilenames() const;
		const std::vector<std::string> &GetSelectPath_ChildPaths() const;

		void SetSelectedResource(const SelectResData &data);
		const SelectResData &GetSelectedResource() const;

	protected:
		std::vector<std::string> mSelectPath_ChildFilenames;
		std::vector<std::string> mSelectPath_ChildPaths;

		SelectResData mSelectResData;

		// select res find
	public:
		void OnFindSelectInProjTree();
		void OnFindSelectInResTree();

		// PreView Object
	public:
		void SetPreViewObject(Object *obj);
		PX2::Object *GetPreViewObject();

	protected:
		PX2::ObjectPtr mPreObject;

		// Copy
	public:
		void SetCopyObject(Object *obj);
		Object *GetCopyObject();
		void PasteCopyedObject();

	protected:
		PX2::ObjectPtr mCopyObject;

		// export
	public:
		bool Import(const char *pathname);
		bool Export(PX2::Object *obj, const char *pathname);

		// anim
	public:
		void AnimResetPlay();
		void AnimPlay();
		void AnimStop();
		void AnimReset();
		
		bool IsAnimPlaying();
		void AnimPlayStop();

		// TimeLine
	public:
		TimeLineEdit *GetTimeLineEdit();

		void MakeSelectTimeLineEdit();

	protected:
		TimeLineEdit *mTimeLineEidt;

		// Terrain
	public:
		TerrainEdit *GetTerrainEdit();

	protected:
		TerrainEdit *mTerrainEdit;
	};

#include "PX2Edit.inl"

#define PX2_EDIT Edit::GetSingleton()
#define PX2_EDIT_GETID Edit::GetEditID()

}

#endif