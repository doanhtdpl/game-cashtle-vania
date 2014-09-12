#ifndef __MOVING_PLATFORM_H_
#define __MOVING_PLATFORM_H_

#include "GroundBGObj.h"

class MovingPlatform : public GroundBGObj
{
public:
	MovingPlatform();
	MovingPlatform(std::vector<std::string> arr);
	~MovingPlatform();
	int distanceX;
	bool isStanding;//dang duoc dung len
	virtual void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual void move(float Delta_Time);// overide IMOVE
	virtual void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);

private:

};


#endif // !__MOVING_PLATFORM_H_
