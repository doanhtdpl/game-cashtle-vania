#ifndef __ITWEEN__H_
#define __ITWEEN__H_

#include "ObjectGame.h"

class Itween
{
public:
	static Itween* getInstance();
	bool wasActing;//dang dien ra animation
	bool countFinish;//so lan hoan thanh
	D3DXVECTOR2 posTo;
	D3DXVECTOR2 posFrom;
	D3DXVECTOR2 speed;
	float timeDelay;
	//move object game tu 1 vi tri voi 1 vi tri. Tra ve true khi hoan thanh
	bool MoveTo(ObjectGame* obj, float deltaTime);

protected:
private:
	static Itween* _instance;
	Itween();
};
#endif // !__ITWEEN__H_