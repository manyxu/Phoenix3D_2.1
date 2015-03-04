// PX2EditTimeLineEdit.hpp

#ifndef PX2EDITCURVEEDIT_HPP
#define PX2EDITCURVEEDIT_HPP

#include "PX2EditPre.hpp"
#include "PX2Float2.hpp"
#include "PX2Polysegment.hpp"
#include "PX2Curve.hpp"
#include "PX2CurveGroup.hpp"
#include "PX2UICurveGroup.hpp"

namespace PX2
{

	class TimeLineEdit
	{
	public:
		TimeLineEdit();
		~TimeLineEdit();

		void SetCtrlsScale(const Float2 &scale);
		const Float2 &GetCtrlsScale() const;

		void GetInRange(float &inMin, float &inMax);
		void GetOutRange(float &outMin, float &outMax);

	protected:
		Float2 mCtrlsScale;

	public:
		void CreateAddCurveGroup(PX2::Object *obj);
		void ReCreateAddCurveGroup(PX2::Object *obj);
		bool HasCurveGroup(PX2::Object *obj);
		void RemoveGroup(PX2::Object *obj);
		void ClearGroup(PX2::UICurveGroup *uiGroup);
		void ClearAllGroups();
		CurveGroup *GetCurveGroup(PX2::Object *obj);
		CurveGroup *GetCurveGroup(Curve *curve);
		void UpdateCurve(PX2::Object *obj, bool addRemovePoint = false);

		bool HasCurve(Curve *curve);
		void AddCurve(Curve *curve);
		void RemoveCurve(Curve *curve);
		int GetNumCurves() const;
		Curve *GetCurve(int i);

		void SetActiveCurve(Curve *curve);
		Curve *GetActiveCurve() { return mActiveCurve; }

		CurveCtrl *TrySelectCurve(PX2::Movable *mov);
		void SetSelectedCurveCtrl(CurveCtrl *ctrl);
		CurveCtrl *GetSelectedCurveCtrl() { return mSelectedCurveCtrl; }

		void SetSelectedUICurveGroup(PX2::UICurveGroup *group);
		PX2::UICurveGroup *GetSelectedUICurveGroup() { return mSelectedCruveGroup; }

	public_internal:
		PX2::Polysegment *CreatePoly(PX2::InterpCurveFloat *curve, PX2::Float3 color);
		void UpdatePoly(PX2::InterpCurveFloat *curve, PX2::Polysegment *p, PX2::Float3 color);
		PX2::Polysegment *CreatePoly(PX2::InterpCurveFloat3 *curve, int axis, PX2::Float3 color);
		void UpdatePoly(PX2::InterpCurveFloat3 *curve, PX2::Polysegment *p, int axis, PX2::Float3 color);

	protected:
		void _CreateAddCurveGroup(PX2::EffectModule *module);
		void _CreateAddCurveGroup(PX2::Controller *ctrl);
		void _AddGroup(CurveGroup *group);
		int _GetNumGroups() const;
		void _RemoveGroup(CurveGroup *group);

		PX2::UICurveGroup *_GetUICurveGroupFormUIView(PX2::Node *frame, CurveGroup *group);

		int mNumSamples;
		float mMaxRange;
		PX2::VertexFormatPtr mVFormat;

		std::vector<CurveGroupPtr> mCurveGroups;
		std::vector<CurvePtr> mCurves;

		CurvePtr mActiveCurve;

		PX2::UICurveGroupPtr mSelectedCruveGroup;
		CurveCtrlPtr mSelectedCurveCtrl;

		PX2::NodePtr mCurveEditScene;
	};

}

#endif