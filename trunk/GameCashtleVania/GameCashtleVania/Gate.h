#ifndef __GATE__H__
#define __GATE__H__
#include "GroundBGObj.h"
#include "IAnimatedSprite.h"

class Gate : public GroundBGObj, public IAnimatedSprite
{
public:
	Gate();
	Gate(std::vector<std::string> arr);
	void update(float deltaTime);
	void animated(float deltaTime);
	bool finish;
protected:
private:
};
#endif // !__GATE__H__
