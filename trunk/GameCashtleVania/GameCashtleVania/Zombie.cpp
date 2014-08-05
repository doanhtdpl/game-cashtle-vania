#include "Zombie.h"

Zombie::Zombie()
{

}

Zombie::Zombie(std::vector<std::string> arr) : Enemy(arr)
{

}

void Zombie::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}