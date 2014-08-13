#ifndef __ITEM__MANAGER__
#define __ITEM__MANAGER__

#include "Item.h"
#include <vector>

//quan ly viec xuat hien cua item cung item hien tai cua Simon

class ItemManager
{
public:
	//rot item khi danh vao den
	Item* appearItem(D3DXVECTOR2 posAppear);

	//rot item khi danh quai
	Item* appearItemEnemyDie(D3DXVECTOR2 posAppear);

	Item* appearItem(TypeItem type, D3DXVECTOR2 posAppear);
	//tao item ngau nhien
	Item* randomItem();
	static ItemManager* getInstance();
protected:
	std::vector<TypeItem> _listItemNormal;
	std::vector<TypeItem> _listItemContainRod;
private:
	static ItemManager* _instance;
	ItemManager();
};
#endif // !__ITEM__MANAGER__
