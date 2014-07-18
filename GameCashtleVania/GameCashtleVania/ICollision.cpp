#include "ICollision.h"

bool ICollision::AABB(Box b2, float& moveX, float& moveY)
{
	return !(_box.x + _box.w / 2 < b2.x || _box.x > b2.x + b2.w / 2 || _box.y + _box.h / 2 < b2.y || _box.y > b2.y + b2.h / 2);
}

bool ICollision::AABBCheck(Box b2)
{

}

Box ICollision::GetSweptBroadphaseBox()
{

}

float ICollision::SweptAABB(Box b2, float& normalx, float& normaly)
{

}