// PX2ResourceUpdate.hpp

#ifndef PX2RESOURCEUPDATE_HPP
#define PX2RESOURCEUPDATE_HPP

#include "PX2UnityPre.hpp"

namespace PX2
{

	class PX2_UNITY_ITEM ResourceVersion
	{
	public:
		ResourceVersion ();
		explicit ResourceVersion (const std::string &version);
		ResourceVersion (const ResourceVersion &sv);
		~ResourceVersion ();

		int GetMain () const;
		int GetLib () const;
		int GetRes () const;

		std::string GetAsString () const;

		bool operator== (const ResourceVersion &b) const;
		bool operator != (const ResourceVersion &b) const;
		friend bool operator > (const ResourceVersion& a, const ResourceVersion& b);
		friend bool operator < (const ResourceVersion& a, const ResourceVersion& b);

	public:
		int mMain;
		int mLib;
		int mRes;
	};

	class PX2_UNITY_ITEM ResourceVersionItem
	{
	public:
		ResourceVersionItem ();
		~ResourceVersionItem();

		ResourceVersion Version;
		bool IsCurrent;
	};

	class PX2_UNITY_ITEM ResourceFileMark
	{
	public:
		ResourceFileMark ();
		~ResourceFileMark ();

		std::string Path;
		int32_t BufferSize;
		char MD5[16];

		static int ResourceUpdateVersion;
	};

#include "PX2ResourceUpdate.inl"

}

#endif