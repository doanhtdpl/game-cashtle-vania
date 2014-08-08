#include "LightFactory.h"

LightFactory* LightFactory::_instance = NULL;

LightFactory* LightFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new LightFactory();
	}
	return _instance;
}

LightFactory::LightFactory()
{

}

//tao doi tuong dua vao info load len tu file
Light* LightFactory::createObj(int ID)
{
	std::vector<std::string> arr = getInfoByID(ID);
	return new Light(arr);
}

//tao doi tuong load len tu map
Light* LightFactory::createObj(std::vector<std::string> arr)
{
	int ID = atoi(arr.at(1).c_str());

	//lay thong tin tu info
	Light* obj = createObj(ID);

	//them vao thong tin pos
	int x = atoi(arr.at(2).c_str());
	int y = atoi(arr.at(3).c_str());
	obj->_pos.x = x;
	obj->_pos.y = y;

	return obj;
}