// PX2Edit.hpp

#ifndef PX2EDIT_HPP
#define PX2EDIT_HPP

#include "PX2Singleton_NeedNew.hpp"
#include "PX2EditMap.hpp"
#include "PX2EditDefine.hpp"

namespace PX2
{

	class EditMap;

	class Edit : public Singleton<Edit>
	{
	public:
		Edit();
		~Edit();

		bool Initlize();
		bool Ternamate();

	public:
		enum EditType
		{
			ET_SCENE,
			ET_TERRAIN,
			ET_UI,
			ET_MAXTYPE
		};
		void SetEditType(EditType type);
		EditType GetEditType() const;

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
		static int GetEditID();

	protected:
		static int msEditorID;

		// key
	public:
		bool IsAltDown;
		bool IsCtrlDown;
		bool IsShiftDown;
	};

#include "PX2Edit.inl"

#define PX2_EDIT Edit::GetSingleton()
#define PX2_EDIT_GETID Edit::GetEditID()

}

#endif