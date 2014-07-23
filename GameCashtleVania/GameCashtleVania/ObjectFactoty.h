#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__
#include "ObjectGame.h"
#include <vector>
#include <string>

class ObjectFactory
{
public:
	void addInfo(std::vector<std::string> arr);
	virtual ObjectGame* createObj() = 0;
protected:
	std::vector<std::string> info;
private:
};
#endif // !__OBJECT_FACTORY_H__