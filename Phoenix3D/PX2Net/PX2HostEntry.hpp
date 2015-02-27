// PX2HostEntry.hpp

#ifndef PX2HOSTENTRY_HPP
#define PX2HOSTENTRY_HPP

#include "PX2NetPre.hpp"
#include "PX2IPAddress.hpp"

namespace PX2
{

	/**
	* 存储“主机名”，别名，和IP地址列表
	*/
	class HostEntry
	{
	public:
		typedef std::vector<std::string> AliasList;
		typedef std::vector<IPAddress>   AddressList;

		HostEntry();

#ifndef __ANDROID__
		HostEntry(struct hostent* entry);
#endif

#if defined(PX2_HAVE_ADDRINFO)
		HostEntry(struct addrinfo* info);
#endif
		HostEntry(const HostEntry& entry);
		~HostEntry();

		HostEntry& operator = (const HostEntry& entry);
		void Swap(HostEntry& hostEntry);

		const std::string& GetName() const;
		const AliasList& GetAliases() const;
		const AddressList& GetAddresses() const;

	private:
		std::string mName;
		AliasList mAliases;
		AddressList mAddresses;
	};

}

#endif