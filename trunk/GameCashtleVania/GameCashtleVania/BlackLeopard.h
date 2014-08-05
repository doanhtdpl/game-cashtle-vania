#ifndef __BLACK_LEOPARD_H__
#define __BLACK_LEOPARD_H__

#include "Enemy.h"

class BlackLeopard : public Enemy
{
public:
	BlackLeopard();
	BlackLeopard(std::vector<std::string> arr);
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
protected:
private:
};

#endif // !__BLACK_LEOPARD_H__
