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

		// Copy
	public:
		void SetCopyObject(PX2::Object *obj);
		PX2::Object *GetCopyObject();
		void PasteCopyedObject();

	protected:
		PX2::ObjectPtr mCopyObject;

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

	protected:
		TimeLineEdit *mTimeLineEidt;
	};

#include "PX2Edit.inl"

#define PX2_EDIT Edit::GetSingleton()
#define PX2_EDIT_GETID Edit::GetEditID()

}

#endif