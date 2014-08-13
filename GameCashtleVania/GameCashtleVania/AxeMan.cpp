#include "AxeMan.h"
#include "TagClassName.h"


AxeMan::AxeMan()
{

}

AxeMan::AxeMan(std::vector<std::string> arr) : Enemy(arr)
{

}

void AxeMan::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//quay dau lai
	this->_Left = !this->_Left;
}