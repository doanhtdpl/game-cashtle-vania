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

void ObjectFactory::addInfo(vector<string> arr) 
{
	info.push_back(arr);
}