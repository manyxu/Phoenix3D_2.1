/*
*
* ÎÄ¼þÃû³Æ	£º	X_NetData.hpp
*
*/

#ifndef X_NETDATA_HPP
#define X_NETDATA_HPP

#include "X_Pre.hpp"

namespace PX2
{

	class LoginData_Item
	{
	public:
		LoginData_Item();
		~LoginData_Item();

		int ServerID;
		int TypeID;
	};

	class LoginData_Actor
	{
	public:
		LoginData_Actor();
		~LoginData_Actor();

		std::string Nickname;

		int ServerID;
		int TypeID;
		int Level;
		int CurLevelExp;
		int Gold;
		int NewPlayerGuideID;
		int NumBagMax;

		std::vector<LoginData_Item> Items;
	};

}

#endif