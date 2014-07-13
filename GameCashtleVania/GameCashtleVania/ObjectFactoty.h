#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__
#include "ObjectGame.h"
#include <vector>
#include <string>

class ObjectFactory
{
public:
	virtual ObjectGame* CreateObj() = 0;
protected:
	std::vector<std::string> *info;
private:
};
#endif // !__OBJECT_FACTORY_H__