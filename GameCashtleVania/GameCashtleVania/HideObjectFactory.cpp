#include "HideObjectFactory.h"

HideObjFactory* HideObjFactory::_instance = NULL;

HideObjFactory* HideObjFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new HideObjFactory();
	}
	return _instance;
}

HideObjFactory::HideObjFactory()
{

}

HideObject* HideObjFactory::createObj(std::vector<std::string> arr)
{
	HideObject* obj = new HideObject(arr);

	//lay type hide object dua vao ID
	TypeHideObect type = TypeHideObect(atoi(arr.at(1).c_str()));

	obj->setTypeHideObj(type);

	return obj;
}