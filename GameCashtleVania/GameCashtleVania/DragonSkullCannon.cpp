#include "DragonSkullCannon.h"

DragonSkullCannon::DragonSkullCannon()
{

}

DragonSkullCannon::DragonSkullCannon(std::vector<std::string> arr) : Enemy(arr)
{

}

void DragonSkullCannon::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}