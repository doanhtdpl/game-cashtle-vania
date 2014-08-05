#ifndef __DYNAMIC_OBJECT_H__
#define __DYNAMIC_OBJECT_H__


#include "ObjectGame.h"
#include "IMove.h"
#include <list>
#include "StaticObject.h"
//#include "InvisibleObject.h"

class DynamicObject: public ObjectGame, public IMove
{
public:
	virtual void move(float Delta_Time);// overide IMOVE
	virtual std::string className();
	virtual void update(float deltatime);
	virtual void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual Box getBox();

	//xu ly collision
	virtual void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
	virtual float collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime);
	virtual float collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime);
	DynamicObject(void);
	~DynamicObject(void);
};

#endif // !__DYNAMIC_OBJECT_H__