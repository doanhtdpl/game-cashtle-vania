#include "StaticObject.h"


StaticObject::StaticObject(void):ObjectGame()
{
}

StaticObject::StaticObject(std::vector<std::string> arr) : ObjectGame(arr)
{

}

StaticObject::~StaticObject(void)
{
}

char* StaticObject::className()
{
	return "Static Object";
}	