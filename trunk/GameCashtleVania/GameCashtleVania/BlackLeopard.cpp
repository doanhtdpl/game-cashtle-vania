#include "BlackLeopard.h"

BlackLeopard::BlackLeopard()
{

}

BlackLeopard::BlackLeopard(std::vector<std::string> arr) : Enemy(arr)
{

}

void BlackLeopard::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}