#ifndef __OBJECT_FACTORY_H__
#define __OBJECT_FACTORY_H__
#include "ObjectGame.h"
#include <vector>
#include <string>

class ObjectFactory
{
public:
	void addInfo(std::vector<std::string> arr);
	virtual ObjectGame* createObj();
	virtual ObjectGame* createObj(int ID);
protected:
	// vector chua list cac arr : std::vector<std::string> la thong tin cua 1 object
	std::vector<std::vector<std::string>> info;
private:
};
#endif // !__OBJECT_FACTORY_H__