#ifndef __BLACK_KNIGHT__
#define __BLACK_KNIGHT__

#include "Enemy.h"

class BlackKnight : public Enemy
{
public:
	BlackKnight();
	BlackKnight(std::vector<std::string> arr);
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
protected:
private:
};

#endif // !__BLACK_KNIGHT__
