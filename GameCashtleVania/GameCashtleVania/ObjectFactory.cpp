#include "ObjectFactoty.h"
using namespace std;

ObjectGame* ObjectFactory::createObj(int ID)
{
	return NULL;
}

ObjectGame* ObjectFactory::createObj()
{
	return NULL;
}

ObjectGame* ObjectFactory::createObj(std::vector<std::string> arr)
{
	return NULL;
}

void ObjectFactory::addInfo(vector<string> arr) 
{
	info.push_back(arr);
}


std::vector<std::string> ObjectFactory::getInfoByID(int ID)
{
	//tim arr nao co ID_Image = ID_BG thi lay 
	std::vector<std::string> arr;
	for (int i = 0; i < info.size(); i++)
	{
		arr = info.at(i);
		if (atoi(arr.at(0).c_str()) == ID)
		{
			return arr;
		}
	}
}