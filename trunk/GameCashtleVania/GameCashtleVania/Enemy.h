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

#ifndef __TYPE__ENEMY__
#define __TYPE__ENEMY__

enum class TypeEnemy
{
	ZOMBIE = 201,
	BLACK_LEOPARD = 202,
	VAMPIRE_BAT = 203,
	MEDUSA = 204,
	FISH_MAN = 205,
	AXE_MAN = 206,
	DRAGON_SKULL_CANNON = 207,
	BLACK_KNIGHT = 208,
	WHITE_SKELETON = 209,
	GHOST = 210
};
#endif // !__TYPE__ENEMY__


#ifndef __ENEMY__H__
#define __ENEMY__H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"
#include "HideObject.h"

#define PI 3.14159265358979323846

class Enemy : public DynamicObject,public IAnimatedSprite
{
public:
	virtual std::string className();
	virtual void move(float delta_Time);
	virtual void animated(float deltaTime);
	void updateMovement(float deltaTime);
	//xu ly collision - chi xu ly va cham voi nhung doi tuong Ground. Nhung doi tuong an - Free. 
	virtual void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	Enemy();
	Enemy(std::vector<std::string> arr);
	
	//implement lai ham get rect cho tung enemy. Day se la vung di chuyen cua enemy.
	virtual RECT getRect();
	D3DXVECTOR2 posDefault;//vi tri xuat hien dau tien cua enemy

	//bi tan cong
	void isAttack();
protected:
	EnemyMovement _moveMent;
	TypeEnemy _typeEnemy;
	float TimeDelay;//bi delay khi va cham voi IronRod
	float _timeDelayCur;
	bool _canFree;
	float _hp;
	RECT _bound;//vung di chuyen cua enemy
	virtual void handleCollisionWithFreeObject(float deltatime, HideObject* hideObj);
	//virtual void handleColWithGround(float deltatime, HideObject* hideObj);
private:
};
#endif // !__ENEMY__H__