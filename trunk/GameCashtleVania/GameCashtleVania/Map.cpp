#include "Map.h"
#include <fstream>
#include "FileUtils.h"
#include "LightFactory.h"
#include "HideObjectFactory.h"
#include "EnemyFactory.h"

Map::Map(void)
{
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
		ObjectGame* obj = NULL;
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

		this->listObjectInMap[ID_Quadtree] = obj;
	}

	//std::string line;
	//std::vector<std::string> arr;
	//std::ifstream* myfile = new std::ifstream(filePath);

	//if (myfile->is_open())
	//{
	//	while ( !myfile->eof()) 
	//	{
	//		if (std::getline(*myfile, line))
	//		{
	//			arr = FileUtils::split(line, '\t');
	//			int ID_Quadtree = atoi(arr.at(0).c_str());
	//			int ID = atoi(arr.at(1).c_str());
	//			ObjectGame* obj = NULL;
	//			if (ID > 700 && ID < 800)
	//			{
	//				//Hide Object
	//				obj = HideObjFactory::getInstance()->createObj(arr);
	//			}else
	//			{
	//				//Light
	//				if (ID > 600 && ID < 700)
	//				{
	//					obj = LightFactory::getInstance()->createObj(arr);
	//				}
	//			}

	//			this->listObjectInMap[ID_Quadtree] = obj;
	//		}
	//	}
	//}
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
	}

	return max;
}

Map::~Map(void)
{
}
