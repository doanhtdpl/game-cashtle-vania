#ifndef __LIGHT__FACTORY__
#define __LIGHT__FACTORY__

#include "ObjectFactoty.h"
#include "Light.h"

class LightFactory : public ObjectFactory
{
public:
	static LightFactory* getInstance();

	Light* createObj(int ID);
	Light* createObj(std::vector<std::string> arr);
protected:
private:
	LightFactory();
	static LightFactory* _instance;
};
#endif // !__LIGHT__FACTORY__
