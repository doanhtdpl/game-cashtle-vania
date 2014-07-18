#include "ObjectFactoty.h"
using namespace std;

void ObjectFactory::addInfo(vector<string> arr) 
{
	for (int i = 0; i < arr.size(); i++)
	{
		info.push_back(arr.at(i));
	}
}