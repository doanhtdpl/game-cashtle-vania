#ifndef __FIRE_BOMB_2__
#define __FIRE_BOMB_2__

#include "Weapon.h"

class FireBomb2 : public Weapon
{
public:
	FireBomb2();
	FireBomb2(std::vector<std::string> arr);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
protected:
	float life_Time;//thoi gian ton tai
private:
};
#endif // !__FIRE_BOMB_2__