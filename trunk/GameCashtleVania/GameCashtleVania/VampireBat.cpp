#include "VampireBat.h"

VampireBat::VampireBat()
{

}

VampireBat::VampireBat(std::vector<std::string> arr) : Enemy(arr)
{

}

void VampireBat::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}