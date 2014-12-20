/*
*
* ÎÄ¼þÃû³Æ	£º	PX2A2DF8_Mesh.hpp
*
*/

#ifndef PX2A2DF8_MESH_HPP
#define PX2A2DF8_MESH_HPP

#include "PX2GamePre.hpp"
#include "PX2TriMesh.hpp"
#include "PX2TexPackData.hpp"

namespace PX2
{

	class A2DF8_Mesh : public TriMesh
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(A2DF8_Mesh);

	public:
		A2DF8_Mesh ();
		~A2DF8_Mesh ();

		void SetInterval (float interval);
		void SetPlayOnce (bool once);
		void SetSize (float size);
		int SetTexPack (const std::string &texPackFilename);
		int GetNumFramesPerDir () const;

		void SetWorldRunDir (const AVector &vec);

		virtual void Play ();
		virtual void Stop ();
		virtual bool IsPlaying ();
		virtual void Reset ();

	protected:
		virtual void UpdateWorldData (double applicationTime);
		void Cal (const std::string &texPackFilename);
		int GetDirIndex (const AVector &dir);
		void CalFrame ();

		std::string mTexPackFilename;
		float mInterval;
		float mPlayOnceTime;
		bool mIsPlayOnce;
		int mNumAllFrames;
		int mNumFramesPerDir;
		float mSize;

		bool mIsPlaying;
		double mLastAppTime;
		bool mIsCaled;
		float mAnimPlayedTime;
		AVector mCurDir;
	};

	PX2_REGISTER_STREAM(A2DF8_Mesh);
	typedef Pointer0<A2DF8_Mesh> A2DF8_MeshPtr;

}

#endif