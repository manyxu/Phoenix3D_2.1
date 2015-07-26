// PX2SkyMesh.hpp

#ifndef PX2SKYMESH_HPP
#define PX2SKYMESH_HPP

#include "PX2SimulationPre.hpp"
#include "PX2TriMesh.hpp"

namespace PX2
{

	class PX2_SIMULATION_ITEM SkyMesh : public TriMesh
	{
		PX2_DECLARE_RTTI;
		PX2_DECLARE_NAMES;
		PX2_DECLARE_STREAM(SkyMesh);

	public:
		SkyMesh();
		virtual ~SkyMesh();

		float GetRadial();

		void SetDayTexture(const std::string &filename);
		const std::string &GetDayTexture() const;
		void SetSunsetTexture(const std::string &filename);
		const std::string &GetSunsetTexture();
		void SetNightTexture(const std::string &filename);
		const std::string &GetNightTexture();

		void SetSkyParam(const Float4 &skyParam);
		const Float4 &GetSkyParam() const;

		void SetSunMoonParam(const Float4 &sunMoonParam);
		const Float4 &GetSunMoonParam() const;
		void SetSunMoonColourIn(const Float4 &color);
		const Float4 &GetSunMoonColourIn() const;
		void SetSunMoonColourOut(const Float4 &color);
		const Float4 &GetSunMoonColourOut() const;

	protected:
		float mRadius;
		std::string mDayTexFilename;
		std::string mSunsetTexFilename;
		std::string mNightTexFilename;
		Float4 mSkyParam;
		Float4 mSunMoonParam;
		Float4 mSunMoonColourIn;
		Float4 mSunMoonColourOut;
	};
	
#include "PX2SkyMesh.inl"
	PX2_REGISTER_STREAM(SkyMesh);
	typedef Pointer0<SkyMesh> SkyMeshPtr;

}

#endif