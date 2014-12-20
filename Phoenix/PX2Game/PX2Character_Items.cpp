/*
*
* ÎÄ¼þÃû³Æ	£º	PX2Character_Items.cpp
*
*/

#include "PX2Character.hpp"
using namespace PX2;

//----------------------------------------------------------------------------
bool Character::AddItem (Item *item)
{
	assertion(0!=item, "item must not be 0.");

	if (!item)
		return false;

	if (HasItem(item))
		return false;

	mItems.push_back(item);

	return true;
}
//----------------------------------------------------------------------------
bool Character::HasItem (Item *item)
{
	assertion(0!=item, "item must not be 0.");

	if (!item)
		return false;

	for (int i=0; i <(int)mItems.size(); i++)
	{
		if (mItems[i] == item)
		{
			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
Item *Character::GetItemByID (int id)
{
	for (int i = 0 ; i <(int)mItems.size(); i++)
	{
		if (mItems[i]->GetID() == id)
		{
			return mItems[i];
		}
	}

	return 0;
}
//----------------------------------------------------------------------------
Item *Character::GetItem (int index)
{
	if (0<=index && index<(int)mItems.size())
		return mItems[index];

	return 0;
}
//----------------------------------------------------------------------------
bool Character::RemoveItem (Item *item)
{
	assertion (0!=item, "item must not be 0.");

	if (!item)
		return false;

	UnEquipItem(item);

	std::vector<ItemPtr>::iterator it = mItems.begin();
	for (; it!=mItems.end();)
	{
		if (*it == item)
		{
			it = mItems.erase(it);
			return true;
		}
		else
		{
			it++;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::RemoveAllItems ()
{
	UnEquipAllItems();

	mItems.clear();
}
//----------------------------------------------------------------------------
bool Character::EquipItem (Item *item)
{
	if (!item->IsCanBeEquipped())
		return false;

	if (item->IsEquipped())
		return false;

	mEquippedItems.push_back(item);
	item->SetCharacter(this);
	item->SetEquipped(true);

	return true;
}
//----------------------------------------------------------------------------
int Character::GetNumItemsEquipped ()
{
	return (int)mEquippedItems.size();
}
//----------------------------------------------------------------------------
Item *Character::GetEquippedItem (int index)
{
	assertion(0<=index && index<(int)mEquippedItems.size(),
		"index should be in right range.\n");

	if (0<=index && index<(int)mEquippedItems.size())
		return mEquippedItems[index];

	return 0;
}
//----------------------------------------------------------------------------
bool Character::UnEquipItem (Item *item)
{
	std::vector<ItemPtr>::iterator it = mEquippedItems.begin();
	for (; it!=mEquippedItems.end(); ++it)
	{
		if (item == *it)
		{
			item->SetEquipped(false);
			item->SetCharacter(0);
			mEquippedItems.erase(it);
			return true;
		}
	}

	return false;
}
//----------------------------------------------------------------------------
void Character::UnEquipAllItems ()
{
	for (int i=0; i<GetNumItemsEquipped(); i++)
	{
		GetEquippedItem(i)->SetCharacter(0);
		GetEquippedItem(i)->SetEquipped(false);
	}

	mEquippedItems.clear();
}
//----------------------------------------------------------------------------