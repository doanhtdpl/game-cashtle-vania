#ifndef __FISH__MAN__
#define __FISH__MAN__


#include "Enemy.h"

class FishMan : public Enemy
{
public:
	FishMan();
	FishMan(std::vector<std::string> arr);
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
protected:
private:
};

#endif // !__FISH__MAN__
