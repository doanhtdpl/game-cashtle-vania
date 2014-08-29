#ifndef __GHOST__
#define __GHOST__

#include "Enemy.h"

class Ghost : public Enemy
{
public:
	Ghost();
	Ghost(std::vector<std::string> arr);
	void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	D3DXVECTOR2 posTarget;//vi tri cua simon
	void move(float delta_Time);
protected:
private:
};

#endif // !__GHOST__
