#ifndef __ZOMBIE__H__
#define __ZOMBIE__H__

#include "Enemy.h"

class Zombie : public Enemy
{
public:
	Zombie();
	Zombie(std::vector<std::string> arr);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
protected:
private:
};

#endif // !__ZOMBIE__H__
