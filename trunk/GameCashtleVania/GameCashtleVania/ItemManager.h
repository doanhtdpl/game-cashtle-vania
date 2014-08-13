#ifndef __ITEM__MANAGER__
#define __ITEM__MANAGER__

#include "Item.h"
#include <vector>

//quan ly viec xuat hien cua item cung item hien tai cua Simon

class ItemManager
{
public:
	Item* appearItem();
	Item* appearItemEnemyDie();
protected:
	std::vector<Item*> _listItem;
private:
};
#endif // !__ITEM__MANAGER__
