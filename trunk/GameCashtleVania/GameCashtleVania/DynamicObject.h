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
	virtual void Move(float Delta_Time);// overide IMOVE
	virtual char* className();
	virtual void Update(float deltatime);
	virtual void Update(float delta_Time, std::list<ObjectGame*> *_ListObjectCollision);
	Box GetBox();
	virtual float Collision(DynamicObject* dynamicOject, float &normalx, float &normaly, float deltaTime);
	virtual float Collision(StaticObject* staticObject, float &normalx, float &normaly, float deltaTime);
	DynamicObject(void);
	~DynamicObject(void);
};

#endif // !__DYNAMIC_OBJECT_H__