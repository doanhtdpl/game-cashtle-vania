#ifndef __FIRE__BALL__
#define __FIRE__BALL__
#include "Enemy.h"

class FireBall : public Enemy
{
public:
	FireBall();
	FireBall(std::vector<std::string> arr);
	void appear(D3DXVECTOR2 pos, bool dir);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	float lifeTime;
protected:
private:
};

#endif // !__FIRE__BALL__