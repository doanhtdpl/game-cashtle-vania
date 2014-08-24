#ifndef __MEDUSA__
#define __MEDUSA__

#include "Enemy.h"

class Medusa : public Enemy
{
public:
	Medusa();
	Medusa(std::vector<std::string> arr);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	void move(float delta_Time);
protected:
private:
};

#endif // !__MEDUSA__
