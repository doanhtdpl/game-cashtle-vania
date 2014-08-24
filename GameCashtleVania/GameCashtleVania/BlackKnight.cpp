#include "BlackKnight.h"

BlackKnight::BlackKnight()
{

}

BlackKnight::BlackKnight(std::vector<std::string> arr) : Enemy(arr)
{

}

void BlackKnight::handleCollisionWithFreeObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
}