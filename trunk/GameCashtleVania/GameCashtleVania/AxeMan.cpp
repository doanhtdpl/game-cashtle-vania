#include "AxeMan.h"

AxeMan::AxeMan()
{

}

AxeMan::AxeMan(std::vector<std::string> arr) : Enemy(arr)
{

}

void AxeMan::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}