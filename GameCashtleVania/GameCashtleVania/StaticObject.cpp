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

std::string StaticObject::className()
{
	return "Static Object";
}

void StaticObject::update(float deltaTime)
{

}
