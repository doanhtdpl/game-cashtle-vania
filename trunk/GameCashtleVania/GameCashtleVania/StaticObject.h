#pragma once
#include "ObjectGame.h"
//#include "DynamicObject.h"

class StaticObject : public ObjectGame
{
public:
	virtual std::string className();
	StaticObject(void);
	StaticObject(std::vector<std::string> arr);
	~StaticObject(void);
};

