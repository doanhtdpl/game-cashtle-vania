#ifndef __GHOST__
#define __GHOST__

#include "Enemy.h"

class Ghost : public Enemy
{
public:
	Ghost();
	Ghost(std::vector<std::string> arr);
	void handleCollisionWithHideObject(float deltatime, HideObject* hideObj);
protected:
private:
};

#endif // !__GHOST__
