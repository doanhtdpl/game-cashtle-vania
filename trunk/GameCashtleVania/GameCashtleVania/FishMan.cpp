#include "FishMan.h"

FishMan::FishMan()
{

}

FishMan::FishMan(std::vector<std::string> arr) : Enemy(arr)
{

}

void FishMan::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}