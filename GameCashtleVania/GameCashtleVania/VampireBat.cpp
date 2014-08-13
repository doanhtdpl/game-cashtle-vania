#include "VampireBat.h"

VampireBat::VampireBat()
{

}

VampireBat::VampireBat(std::vector<std::string> arr) : Enemy(arr)
{

}

void VampireBat::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}