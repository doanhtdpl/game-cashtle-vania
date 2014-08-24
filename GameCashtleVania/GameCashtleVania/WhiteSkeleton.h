#ifndef __WHITE_SKELETON_H__
#define __WHITE_SKELETON_H__

#include "Enemy.h"

class WhiteSkeleton : public Enemy
{
public:
	WhiteSkeleton();
	WhiteSkeleton(std::vector<std::string> arr);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
protected:
private:
};

#endif // !__WHITE_SKELETON_H__
