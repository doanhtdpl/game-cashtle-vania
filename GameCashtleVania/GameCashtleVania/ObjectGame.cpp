#include "ObjectGame.h"
using namespace std;

ObjectGame::ObjectGame(void)
{
	//_ID = 0;
	_isALive = true;
	_rectRS = NULL;
	_isAnimatedSprite = false;
	this->_height = 0;
	this->_width = 0;

}

ObjectGame::ObjectGame(std::vector<std::string> arr)
{

}

ObjectGame::~ObjectGame(void)
{
}

std::string ObjectGame::className()
{
	return "Object Game";
}

Box ObjectGame::getBox()
{
	this->_box = Box(_pos.x, _pos.y, _width, _height);
	return _box;
}