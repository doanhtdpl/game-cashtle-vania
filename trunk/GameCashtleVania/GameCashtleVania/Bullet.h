#ifndef __BULLET_H_
#define __BULLET_H_

#include "Enemy.h"

class Bullet :  public Enemy
{
public:
	Bullet(std::vector<std::string> arr);
	~Bullet();
	void appear(D3DXVECTOR2 pos, D3DXVECTOR2 des);
	virtual void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual void move(float delta_Time);
	virtual void updateMovement(float deltaTime);
	float lifeTime;
	D3DXVECTOR2 _des;
private:

};



#endif // !__BULLET_H_
