/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Animation.hpp
*
*/

#ifndef PX2ANIMATION2DFRAMES_HPP
#define PX2ANIMATION2DFRAMES_HPP

#include "PX2GamePre.hpp"
#include "PX2Animation.hpp"
#include "PX2A2DF8_Mesh.hpp"

namespace PX2
{

	class Animation2DFrames8 : public Animation
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_PROPERTY;
		PX2_DECLARE_STREAM(Animation2DFrames8);

	public:
		Animation2DFrames8 ();
		virtual ~Animation2DFrames8 ();

		virtual void SetTime (float time);
		void SetInterval (float interval);
		float GetInterval () const;

		virtual void SetFilename (const std::string &texPackFilename);
		int GetNumFramesPerDir () const;
		void SetColor (const Float3 &color);

		virtual void SetPlayOnce (bool once);

		void SetWorldRunDir (const AVector &vec);
		const AVector &GetWorldRunDir () const;

		void SetAnimSize (float size);

		virtual void Stop ();
		virtual bool IsPlaying () const;
		virtual void OnPlay (Character *character);
		virtual void OnRemove (Character *character);

public_internal:
		virtual void SaveToXMLNode (XMLNode nodeParent);
		virtual void LoadFromXMLNode (XMLNode node);

		float mInterval;
		int mNumFramePerDir;
		AVector mWorldRunDir;
		A2DF8_MeshPtr mMesh;
	};

#include "PX2Animation2DFrames8.inl"
	PX2_REGISTER_STREAM(Animation2DFrames8);
	typedef Pointer0<Animation2DFrames8> Animation2DFramesPtr;

}

#endif