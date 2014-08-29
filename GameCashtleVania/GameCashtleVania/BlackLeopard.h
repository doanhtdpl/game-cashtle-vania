#ifndef __BLACK_LEOPARD_H__
#define __BLACK_LEOPARD_H__

#include "Enemy.h"

class BlackLeopard : public Enemy
{
public:
	BlackLeopard();
	BlackLeopard(std::vector<std::string> arr);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	void animated(float deltaTime);
	bool enable;
protected:
private:
};

#endif // !__BLACK_LEOPARD_H__
