// PX2VBIBObj.hpp

#ifndef PX2VBIBOBJ_HPP
#define PX2VBIBOBJ_HPP

#include "PX2SimulationPre.hpp"

namespace PX2
{

	struct PX2_SIMULATION_ITEM VBIBObj
	{
		VBIBObj()
		{
			IsValued = false;
		}

		bool IsValued;
		VertexBufferPtr mVB;
		IndexBufferPtr mIB;
	};

	class PX2_SIMULATION_ITEM VBIBManager : public Singleton<VBIBManager>
	{
	public:
		VBIBManager();
		virtual ~VBIBManager();

		void Clear();
		void AddVBIB(const std::string &texPackFilename, VertexBuffer *vb, 
			IndexBuffer *ib);
		VBIBObj &GetVBID(const std::string &texPackFilename);

	protected:
		typedef HashTable<FString, VBIBObj, FixedStringHashCoder> UBIBTable;
		UBIBTable mUBIBTable;
		VBIBObj mNotValied;
	};

}

#endif