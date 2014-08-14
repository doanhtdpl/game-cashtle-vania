#include "WhiteSkeleton.h"

WhiteSkeleton::WhiteSkeleton()
{

}

WhiteSkeleton::WhiteSkeleton(std::vector<std::string> arr) : Enemy(arr)
{
	
}

void WhiteSkeleton::handleCollisionWithHideObject(float deltatime, HideObject* hideObj)
{
	//chi va cham voi doi tuong Free
	//chua biet lam gi ca
}