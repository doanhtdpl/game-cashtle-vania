#include "EnemyFactory.h"

EnemyFactory* EnemyFactory::_instance = NULL;

EnemyFactory* EnemyFactory::getInstance()
{
	if (_instance == NULL)
	{
		_instance = new EnemyFactory();
	}
	return _instance;
}

EnemyFactory::EnemyFactory()
{

}

Enemy* EnemyFactory::createObj(int ID)
{
	std::vector<std::string> arr = getInfoByID(ID);
	//int ID = atoi(arr.at(0).c_str());
	switch (ID)
	{
	case 201:
		break;
	case 202:
		break;
	case 203:
		break;
	case 204:
		break;
	case 205:
		break;
	case 206:
		break;
	case 207:
		break;
	case 208:
		break;
	case 209:
		break;
	case 210:
		break;
	default:
		break;
	}

	return NULL;
}

std::vector<std::string> EnemyFactory::getInfoByID(int _ID)
{
	//tim arr nao co ID = _ID thi lay 
	std::vector<std::string> arr;
	for (int i = 0; i < info.size(); i++)
	{
		arr = info.at(i);
		if (atoi(arr.at(0).c_str()) == _ID)
		{
			return arr;
		}
	}
}