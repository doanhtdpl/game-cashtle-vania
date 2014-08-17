#include "Map.h"
#include <fstream>
#include "FileUtils.h"
#include "LightFactory.h"
#include "HideObjectFactory.h"
#include "EnemyFactory.h"
#include "MapLoader.h"

Map::Map(void)
{
}

void Map::eraseObject(int IDinMap)
{
	std::hash_map<int, ObjectGame*>::iterator it = this->listObjectInMap.begin();
	while (it != this->listObjectInMap.end())
	{
		if (it->first == IDinMap)
		{
			it = this->listObjectInMap.erase(it);
		}else
		{
			it++;
		}
	}
}

void Map::readMapFromFile(std::string filePath)
{
	std::vector<std::vector<std::string>> info = FileUtils::readFile(filePath, '\t');
	std::vector<std::vector<std::string>>::iterator it;
	it = info.begin();
	std::vector<std::string> arr;

	//duyet nhung dong con lai
	while(it != info.end())
	{
		arr = *it++;
		int ID_Quadtree = atoi(arr.at(0).c_str());
		int ID = atoi(arr.at(1).c_str());
		
		//1 so doi tuong la bound cua scene
		if (ID < 50)
		{
			//add bound cho info scene
			MapLoader::getInstance()->getInfoSceneByKey(ID)->getBoundFromFile(arr);
		}else
		{
			this->listInfoOfObject[ID_Quadtree] = arr;
		}
	}
}

std::vector<ObjectGame*> Map::getListObjectinScreen(std::vector<int> listID)
{
	std::vector<ObjectGame*> listObjInScreen;

	std::vector<int>::iterator it = listID.begin();
	std::vector<std::string> arr;
	ObjectGame* obj = NULL;
	int key_HashMap;
	int ID;
	while(it != listID.end())
	{
		key_HashMap = *it;
		std::hash_map<int, std::vector<std::string>>::iterator itInfo = this->listInfoOfObject.find(key_HashMap);
		if (itInfo != listInfoOfObject.end())
		{
			arr = itInfo->second;
		}
		ID = atoi(arr.at(1).c_str());
		if (ID > 700 && ID < 800)
		{
			//Hide Object
			obj = HideObjFactory::getInstance()->createObj(arr);
		}else
		{
			//Light
			if (ID > 600 && ID < 700)
			{
				obj = LightFactory::getInstance()->createObj(arr);
			}
		}

		if (obj != NULL)
		{
			listObjInScreen.push_back(obj);
		}
	}

	return listObjInScreen;
}

int Map::getIDMaxInList()
{
	int max = 0;
	//lay ID lon nhat hien tai co trong hash map
	std::hash_map<int, ObjectGame*>::iterator it;
	it = this->listObjectInMap.begin();
	
	while(it != this->listObjectInMap.end())
	{
		int ID = it->first;
		if (ID > max)
		{
			max = ID;
		}
		it++;
	}

	return max;
}

Map::~Map(void)
{
}
