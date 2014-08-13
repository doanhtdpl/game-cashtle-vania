#include "FishMan.h"

FishMan::FishMan()
{

}

FishMan::FishMan(std::vector<std::string> arr) : Enemy(arr)
{

}

void FishMan::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}