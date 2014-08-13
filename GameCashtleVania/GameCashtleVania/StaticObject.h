#pragma once
#include "ObjectGame.h"
//#include "DynamicObject.h"

class StaticObject : public ObjectGame
{
public:
	virtual std::string className() = 0;
	StaticObject(void);
	StaticObject(std::vector<std::string> arr);
	~StaticObject(void);
	virtual void update(float deltaTime);
	virtual void update(float deltaTime, std::vector<ObjectGame*> listObjectCollision);
};

