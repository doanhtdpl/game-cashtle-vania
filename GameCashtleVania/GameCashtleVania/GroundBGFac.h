#ifndef __GROUND_BG__FACTORY__
#define __GROUND_BG__FACTORY__

#include "ObjectFactoty.h"
#include "GroundBGObj.h"
#include <hash_map>

class GroundBGFac: public ObjectFactory
{
public:
	static GroundBGFac* getInstance();

	//tao doi tuong dua vao ID_BG
	GroundBGObj* createObj(int ID_BG);
	std::vector<std::string> getInfoByIDBG(int ID_BG);
	std::hash_map<int, int> getLishIDImageIDBG();

	std::hash_map<int, int> listIDImageIDBG;
protected:
private:
	static GroundBGFac* _instance;
	GroundBGFac();
};

#endif // !__GROUND_BG__FACTORY__
