#ifndef __GROUND__BG__OBJECT_
#define __GROUND__BG__OBJECT_

#include "DynamicObject.h"

// 2 loai: 
class GroundBGObj : public DynamicObject
{
public:
	GroundBGObj();
	GroundBGObj(std::vector<std::string> arr);
	virtual std::string className();
	virtual void update(float deltaTime);
	virtual void update(float delta_Time, std::vector<ObjectGame*> _listObjectCollision);
	virtual void move(float Delta_Time);// overide IMOVE
	virtual void handleCollision(float deltatime, std::vector<ObjectGame*> _listObjectCollision);

	D3DXVECTOR2 posDefault;
protected:
private:
};

#endif // !__GROUND__BG__OBJECT_
