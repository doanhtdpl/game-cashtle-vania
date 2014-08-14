#include "ItemManager.h"
#include "IronRod.h"
#include <stdlib.h>
#include <time.h> 
#include "ItemFactory.h"

ItemManager* ItemManager::_instance = NULL;

ItemManager* ItemManager::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ItemManager();
	}

	return _instance;
}

ItemManager::ItemManager()
{
#pragma region List Item Normal

	this->_listItemNormal.push_back(TypeItem::Cross);
	this->_listItemNormal.push_back(TypeItem::Dagger);
	this->_listItemNormal.push_back(TypeItem::DoubleShot);
	this->_listItemNormal.push_back(TypeItem::FireBomb);
	this->_listItemNormal.push_back(TypeItem::LargeHeart);
	this->_listItemNormal.push_back(TypeItem::MoneyBag);
	this->_listItemNormal.push_back(TypeItem::PorkChop);
	this->_listItemNormal.push_back(TypeItem::SmallHeart);
	this->_listItemNormal.push_back(TypeItem::SmallHeart);
	this->_listItemNormal.push_back(TypeItem::SmallHeart);
	this->_listItemNormal.push_back(TypeItem::SmallHeart);
	this->_listItemNormal.push_back(TypeItem::SmallHeart);
	this->_listItemNormal.push_back(TypeItem::SmallHeart);
	this->_listItemNormal.push_back(TypeItem::TripleShot);
	this->_listItemNormal.push_back(TypeItem::Watch);

#pragma endregion

#pragma region List Item Contain Rod
	this->_listItemContainRod.push_back(TypeItem::SmallHeart);
	this->_listItemContainRod.push_back(TypeItem::MorningStar);
	this->_listItemContainRod.push_back(TypeItem::MoneyBag);
#pragma endregion

}

Item* ItemManager::appearItem(D3DXVECTOR2 posAppear)
{
	Item* item =randomItem();
	item->_isALive = true;
	item->appear(posAppear);
	return item;
}

Item* ItemManager::appearItemEnemyDie(D3DXVECTOR2 posAppear)
{
	srand(time(0));
	//khoang 5 lan se xuat hien 1 con enemy co item
	int x = rand() % 5;
	if (x == 0)
	{
		Item* item = this->randomItem();
		//cap nhat lai pos
		item->appear(posAppear);
		item->_isALive = true;
		return item;
	}else
	{
		return NULL;
	}
}

Item* ItemManager::randomItem()
{
	srand(time(0));

	std::vector<TypeItem> listItem;
	//da la con roi thu 3
	if (IronRod::getInstance()->getTypeRod() == Rod3)
	{
		listItem = _listItemNormal;
	}else
	{
		listItem = _listItemNormal;
	}

	//lay ngau nhien nhung item trong list
	int x = rand() % listItem.size();
	TypeItem typeItem = listItem.at(x);

	return ItemFactory::getInstance()->createObj((int)typeItem);
}

Item* ItemManager::appearItem(TypeItem type, D3DXVECTOR2 posAppear)
{
	Item* item = ItemFactory::getInstance()->createObj((int)type);
	item->appear(posAppear);
	return item;
}