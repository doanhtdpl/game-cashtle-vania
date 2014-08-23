#ifndef __BLACK_LEOPARD_H__
#define __BLACK_LEOPARD_H__

#include "Enemy.h"

class BlackLeopard : public Enemy
{
public:
	BlackLeopard();
	BlackLeopard(std::vector<std::string> arr);
	void handleCollisionWithHideObject(float deltatime, HideObject* hideObj);
	void animated(float deltaTime);
protected:
private:
};

#endif // !__BLACK_LEOPARD_H__
