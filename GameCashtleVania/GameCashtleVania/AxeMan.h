#ifndef __AXE_MAN__
#define __AXE_MAN__

#include "Enemy.h"

class AxeMan : public Enemy
{
public:
	AxeMan();
	AxeMan(std::vector<std::string> arr);
	void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);
protected:
private:
};
#endif // !__AXE_MAN__
