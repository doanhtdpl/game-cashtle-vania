#ifndef __GROUND_BG__FACTORY__
#define __GROUND_BG__FACTORY__

#include "ObjectFactoty.h"
#include "GroundBGObj.h"
#include "MovingPlatform.h"
class GroundBGFac: public ObjectFactory
{
public:
	static GroundBGFac* getInstance();

	//tao doi tuong dua vao ID_BG
	GroundBGObj* createObj(int ID);

	//tao doi tuong Ground doc tu file map
	GroundBGObj* createObj(std::vector<std::string> arr);
	
protected:
private:
	static GroundBGFac* _instance;
	GroundBGFac();
};

#endif // !__GROUND_BG__FACTORY__
