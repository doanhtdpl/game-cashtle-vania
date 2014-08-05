#include "WhiteSkeleton.h"

WhiteSkeleton::WhiteSkeleton()
{

}

WhiteSkeleton::WhiteSkeleton(std::vector<std::string> arr) : Enemy(arr)
{

}

void WhiteSkeleton::handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision)
{
	//chi va cham voi doi tuong Free
}