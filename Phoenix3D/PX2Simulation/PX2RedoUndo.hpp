// PX2RedoUndo.hpp

#ifndef PX2REDOUNDO_HPP
#define PX2REDOUNDO_HPP

#include "PX2SimulationPre.hpp"
#include "PX2SmartPointer.hpp"
#include "PX2APoint.hpp"
#include "PX2HMatrix.hpp"
#include "PX2Object.hpp"
#include "PX2Singleton_NeedNew.hpp"

namespace PX2
{

	class PX2_SIMULATION_ITEM URDo
	{
	public:
		URDo();
		virtual ~URDo();

		virtual void OnUnDo();
		virtual void OnReDo();
	};

	typedef PX2::Pointer0<URDo> URDoPtr;

	class PX2_SIMULATION_ITEM MovableTransURDo : public URDo
	{
	public:
		MovableTransURDo();
		virtual ~MovableTransURDo();

		virtual void OnUnDo();
		virtual void OnReDo();

	protected:
		std::vector<PX2::ObjectPtr> mObjects;
		std::vector<PX2::APoint> mPositions;
		std::vector<PX2::APoint> mRotations;
		std::vector<PX2::HMatrix> mRotationMats;
		std::vector<PX2::APoint> mScales;

		std::vector<PX2::APoint> mPositionsReDo;
		std::vector<PX2::APoint> mRotationsReDo;
		std::vector<PX2::HMatrix> mRotationMatsReDo;
		std::vector<PX2::APoint> mScalesReDo;
	};

	class PX2_SIMULATION_ITEM ObjectAddDeleteURDo : public URDo
	{
	public:
		ObjectAddDeleteURDo(bool isAdd, PX2::Object *object);
		virtual ~ObjectAddDeleteURDo();

		PX2::Object *GetObject() { return mObject; }
		bool IsAdd() const { return mIsAdd; }

		virtual void OnUnDo();
		virtual void OnReDo();

	protected:
		ObjectAddDeleteURDo();

		bool mIsAdd;
		PX2::ObjectPtr mObject;
		PX2::ObjectPtr mParent;
	};

	class PX2_SIMULATION_ITEM URDoManager : public Singleton<URDoManager>
	{
	public:
		URDoManager();
		~URDoManager();

		void Clear();
		bool IsHasUnDo() const;
		bool IsHasReDo() const;

		void PushUnDo(URDo *command);

		void UnDo();
		void ReDo();

	protected:
		std::deque<URDoPtr> mUnDoCommands;
		std::deque<URDoPtr> mReDoCommands;
	};

#define PX2_URDOMAN URDoManager::GetSingleton()

}

#endif