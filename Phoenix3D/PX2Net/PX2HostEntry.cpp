// PX2HostEntry.cpp

#include "PX2HostEntry.hpp"
#include "PX2Assert.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
HostEntry::HostEntry()
{
}
//----------------------------------------------------------------------------
HostEntry::HostEntry(struct hostent* entry)
{
	assertion(0!=entry, "entry must not be null.\n");

	mName = entry->h_name;	
	char** alias = entry->h_aliases;
	if (alias)
	{
		while (*alias)
		{
			mAliases.push_back(std::string(*alias));
			++alias;
		}
	}
	char** address = entry->h_addr_list;
	if (address)
	{
		while (*address)
		{
			mAddresses.push_back(IPAddress(*address, entry->h_length));
			++address;
		}
	}
}
//----------------------------------------------------------------------------
#if defined(PX2_HAVE_ADDRINFO)
HostEntry::HostEntry(struct addrinfo* ainfo)
{
	assertion(0!=ainfo, "ainfo must not be 0.\n");

	for (struct addrinfo* ai = ainfo; ai; ai = ai->ai_next)
	{
		if (ai->ai_canonname)
		{
			mName.assign(ai->ai_canonname);
		}
		if (ai->ai_addrlen && ai->ai_addr)
		{
			switch (ai->ai_addr->sa_family)
			{
			case AF_INET:
				mAddresses.push_back(IPAddress(
					&reinterpret_cast<struct sockaddr_in*>
					(ai->ai_addr)->sin_addr, sizeof(in_addr)));
				break;
#if defined(PX2_HAVE_IPV6)
			case AF_INET6:
				mAddresses.push_back(IPAddress(
					&reinterpret_cast<struct sockaddr_in6*>
					(ai->ai_addr)->sin6_addr, sizeof(in6_addr),
					reinterpret_cast<struct sockaddr_in6*>(ai->ai_addr)
					->sin6_scope_id));
				break;
#endif
			}
		}
	}
}
#endif
//----------------------------------------------------------------------------
HostEntry::HostEntry(const HostEntry& entry)
	:
mName(entry.mName),
mAliases(entry.mAliases),
mAddresses(entry.mAddresses)
{
}
//----------------------------------------------------------------------------
HostEntry& HostEntry::operator = (const HostEntry& entry)
{
	if (&entry != this)
	{
		mName = entry.mName;
		mAliases = entry.mAliases;
		mAddresses = entry.mAddresses;
	}

	return *this;
}
//----------------------------------------------------------------------------
void HostEntry::Swap(HostEntry& hostEntry)
{
	std::swap(mName, hostEntry.mName);
	std::swap(mAliases, hostEntry.mAliases);
	std::swap(mAddresses, hostEntry.mAddresses);
}
//----------------------------------------------------------------------------
HostEntry::~HostEntry()
{
}
//----------------------------------------------------------------------------
const std::string& HostEntry::GetName() const
{
	return mName;
}
//----------------------------------------------------------------------------
const HostEntry::AliasList& HostEntry::GetAliases() const
{
	return mAliases;
}
//----------------------------------------------------------------------------
const HostEntry::AddressList& HostEntry::GetAddresses() const
{
	return mAddresses;
}
//----------------------------------------------------------------------------