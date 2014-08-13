#ifndef __STATE_ENEMY__
#define __STATE_ENEMY__

enum class EnemyMovement
{
	None,
	Idle,
	Moves,
	Jump,
	Free
};

#endif // !__STATE_ENEMY__

#ifndef __ENEMY__H__
#define __ENEMY__H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"
#include "HideObject.h"

class Enemy : public DynamicObject, IAnimatedSprite
{
public:
	virtual std::string className();
	virtual void move(float delta_Time);
	void animated(float deltaTime);
	void updateMovement(float deltaTime);
	//xu ly collision - chi xu ly va cham voi nhung doi tuong Ground. Nhung doi tuong an - Free. 
	virtual void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	Enemy();
	Enemy(std::vector<std::string> arr);
protected:
	EnemyMovement _moveMent;
	float TimeDelay;//bi delay khi va cham voi IronRod
	float _timeDelayCur;
	float _hp;
	virtual void handleCollisionWithHideObject(float deltatime, HideObject* hideObj);
private:
};
#endif // !__ENEMY__H__