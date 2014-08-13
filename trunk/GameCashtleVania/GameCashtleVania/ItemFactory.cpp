#include "ItemFactory.h"

ItemFactory* ItemFactory::_instance = NULL;

ItemFactory* ItemFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new ItemFactory();
	}

	return _instance;
}

ItemFactory::ItemFactory()
{

}

Item* ItemFactory::createObj(int ID)
{
	std::vector<std::string> arr = this->getInfoByID(ID);
	return createObj(arr);
}

Item* ItemFactory::createObj(std::vector<std::string> arr)
{
	return new Item(arr);
}