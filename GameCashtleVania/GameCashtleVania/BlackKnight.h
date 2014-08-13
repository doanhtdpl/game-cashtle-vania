#ifndef __BLACK_KNIGHT__
#define __BLACK_KNIGHT__

#include "Enemy.h"

class BlackKnight : public Enemy
{
public:
	BlackKnight();
	BlackKnight(std::vector<std::string> arr);
	void handleCollisionWithHideObject(float deltatime, HideObject* hideObj);
protected:
private:
};

#endif // !__BLACK_KNIGHT__
