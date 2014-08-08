#ifndef __HIDE__OBJECT__FACTORY__
#define __HIDE__OBJECT__FACTORY__

#include "ObjectFactoty.h"
#include "HideObject.h"

class HideObjFactory : public ObjectFactory
{
public:
	static HideObjFactory* getInstance();
	HideObject* createObj(std::vector<std::string> arr);
protected:
private:
	HideObjFactory();
	static HideObjFactory* _instance;
};

#endif // !__HIDE__OBJECT__FACTORY__
