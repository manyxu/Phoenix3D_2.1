// X_UIMan.hpp

#ifndef X_UIMAN_HPP
#define X_UIMAN_HPP

#include "PX2Singleton.hpp"
#include "PX2UIFrame.hpp"
#include "PX2UIEditBox.hpp"
#include "PX2UIButton.hpp"

namespace PX2
{

	class PageNode
	{
	public:
		PageNode(const std::string &name = "", PageNode *parent = 0);
		~PageNode();

		std::string Name;
		PageNode *Parent;
		std::list<Pointer0<PageNode> > Nexts;

		PageNode *GetPageNode(const std::string &name);
	};
	typedef Pointer0<PageNode> PageNodePtr;

	class X_UIMan : public Singleton<X_UIMan>, public EventHandler, public Visitor
	{
	public:
		X_UIMan();
		~X_UIMan();

		bool Init();
		bool Init_Updated();
		bool Term();
		void Update(float appSeconds, float elapsedSeconds);

	public:
		virtual void DoExecute(Event *event);
		virtual void Visit(Object *obj, const int info);

		// Start
	public:
		bool Create_CompanyFrame();
		void Destory_CompanyFrame();

		bool Create_StartupFrame();
		void Destory_StartupFrame();

	protected:
		UIFramePtr mDebugFrame;
		UIEditBoxPtr mDebugEdit;
		UITextPtr mDebugText;
		UIFramePtr mInfoFrame;
		UIFramePtr mGameFrame;
		UIFramePtr mGameInfoFrame;
		UIFramePtr mGameXinShouFrame;
		UIFramePtr mABFrame;
		UIFramePtr mAFrame;
		UIFramePtr mBFrame;

		// SelectActor
	public:
		bool Create_SelectActorFrame();
		void Destory_SelectActorFrame();
		int GetSelectActorIndex();

	protected:
		void Visit_SelectActorFrame(Object *obj, const int info);
		void On_SelectActorFrameBut(UIButton *but);
		void On_ActorLeftTurnBut(float turnTime);
		void On_ActorRightTurnBut(float turnTime);
		void Update_ActorTurn(float appSeconds, float elapsedSeconds);

		UIFramePtr mSelectActorFrame;
		int mSelectActorIndex;
		int mActorTurnType;			//0不转 1左转 2右转

		// Load Map
	public:
		bool Create_LoadMapFrame();
		void Destroy_LoadMapFrame();
		bool LoadMap(int mapID);

	protected:
		void Update_LoadMap(float appSeconds, float elapsedSeconds);
		void Visit_LoadMapFrame(Object *obj, const int info);

		UIFramePtr mLoadMapFrame;
		ResHandle mMapResHandle;

		// Main
	public:
		bool Create_MainFrame();
		void Destory_MainFrame();
		void MapLoadedInit();
		void CreateMainChara();
		void CreateMonster(int monsterID, const APoint &pos);

	protected:
		void Visit_GamePadFrame(Object *obj, const int info);
		void Update_StateForGamePad(float appSeconds, float elapsedSeconds);

		bool mIsGamePadLeftButPressed;
		bool mIsGamePadRightButPressed;

		// Bat
	public:
		bool Create_BatFrame();
		void Destory_BatFrame();

	protected:
		void ProcessUISkillFrame(UIFrame *skillFrame);
		void Visit_SkillFrame(Object *obj, const int info);
		void CollectADefSkillStep();
		void Update_Bat(float appSeconds, float elapsedSeconds);

		bool mIsBatBut0Pressed;
		float mBatBut0CollecttingTime;

	protected:
		std::map<std::string, UIFramePtr> mPages;
		UIFramePtr mCurPage;
		PageNodePtr mRootPageNode;
	};

#define X_UIMAN X_UIMan::GetSingleton()

}

#endif