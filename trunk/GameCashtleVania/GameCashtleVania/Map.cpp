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
	std::string line;
	std::vector<std::string> arr;
	std::ifstream* myfile = new std::ifstream(filePath);

	if (myfile->is_open())
	{
		while ( !myfile->eof()) 
		{
			if (std::getline(*myfile, line))
			{
				arr = FileUtils::split(line, '\t');
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
		}
	}
}

Map::~Map(void)
{
}
