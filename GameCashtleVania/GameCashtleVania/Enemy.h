#ifndef __STATE_ENEMY__

enum EnemyMovement
{
	None,
	Idle,
	Moves,
	Free,
	Jump
};
#endif // !__STATE_ENEMY__


#ifndef __ENEMY__H__
#define __ENEMY__H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"

class Enemy : public DynamicObject, IAnimatedSprite
{
public:
	virtual std::string className();
	virtual void move(float delta_Time);
	virtual void animated(float deltaTime);
	virtual void updateMovement(float deltaTime);
	//xu ly collision - chi xu ly va cham voi nhung doi tuong Ground. Nhung doi tuong an - Free. 
	virtual void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	virtual void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	Enemy();
	Enemy(std::vector<std::string> arr);
protected:
	EnemyMovement _movement;
private:
};
#endif // !__ENEMY__H__
