#ifndef __ITEM__FACTORY__
#define __ITEM__FACTORY__

#include "ObjectFactoty.h"
#include "Item.h"

class ItemFactory : public ObjectFactory
{
public:
	static ItemFactory* getInstance();
	Item* createObj(int ID);
	Item* createObj(std::vector<std::string> arr);
protected:
private:
	static ItemFactory* _instance;
	ItemFactory();
};
#endif // !__ITEM__FACTORY__