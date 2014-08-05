#include "Ghost.h"

Ghost::Ghost()
{

}

Ghost::Ghost(std::vector<std::string> arr) : Enemy(arr)
{

}

void Ghost::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}