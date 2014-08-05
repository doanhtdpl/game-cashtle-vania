#include "BlackLeopard.h"

BlackLeopard::BlackLeopard()
{

}

BlackLeopard::BlackLeopard(std::vector<std::string> arr) : Enemy(arr)
{

}

void BlackLeopard::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}