#include "Ghost.h"

Ghost::Ghost()
{

}

Ghost::Ghost(std::vector<std::string> arr) : Enemy(arr)
{

}

void Ghost::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}