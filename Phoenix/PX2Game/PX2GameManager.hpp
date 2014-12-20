/*
*
* 文件名称	：	PX2GameManager.hpp
*
*/

#ifndef PX2GAMEMANAGER_HPP
#define PX2GAMEMANAGER_HPP

#include "PX2GamePre.hpp"
#include "PX2Singleton.hpp"
#include "PX2UIPicBox.hpp"
#include "PX2UIFrame.hpp"
#include "PX2Rect.hpp"
#include "PX2Texture2DMaterial.hpp"
#include "PX2SmartPointer.hpp"

namespace PX2
{

	struct UBIBObj
	{
		UBIBObj ()
		{
			IsValued = false;
		}

		bool IsValued;
		VertexBufferPtr mVB;
		IndexBufferPtr mIB;
	};

	class GameManager : public Singleton<GameManager>
	{
	public:
		GameManager ();
		~GameManager ();

		void LogCurMemory (const std::string &tag);
		void Update (double appSeconds, double elapsedSeconds);

		bool LoadBoost (const char *filename);
		int GetBoostWidth () const;
		int GetBoostHeight () const;
		const std::string &GetProjectPath () const;

		// 屏幕适配时设置
		enum GameViewAdjustType
		{
			GAVT_H_LEFT = 1,
			GAVT_H_CENTER = 2,
			GAVT_H_RIGHT = 4,
			GAVT_V_BUTTON = 8,
			GAVT_V_CENTER = 16,
			GAVT_V_TOP = 32
		};
		void SetGameViewAdjustType (int types);
		int GetGameViewAjustType () const;
		void SetGameViewRect (const Rectf &rect);
		const Rectf &GetGameViewRect () const;

		// Converts
		Movable *CT_Movable (Object *obj);
		Node *CT_Node (Object *obj);
		UIFrame *CT_UIFrame (Object *obj);
		UIPicBox *CT_UIPicBox (Object *obj);

		VertexFormat *GetVertexFormatUser ();
		Texture2DMaterial *GetMaterialUser ();

		void ClearVBIB ();
		void AddVBIB (const std::string &texPackFilename,
			VertexBuffer *vb, IndexBuffer *ib);
		UBIBObj GetVBID (const std::string &texPackFilename);

	private:
		int mBoostWidth;
		int mBoostHeight;
		Rectf mGameViewRect;
		std::string mProjectPath;
		int mGameViewAdjustType;

		VertexFormatPtr mVertexFormatUser;
		Texture2DMaterialPtr mMaterialUser;

		typedef HashTable<FString, UBIBObj, FixedStringHashCoder> UBIBTable;
		UBIBTable mUBIBTable;
	};

#include "PX2GameManager.inl"

#define PX2_GM GameManager::GetSingleton()

}

#endif