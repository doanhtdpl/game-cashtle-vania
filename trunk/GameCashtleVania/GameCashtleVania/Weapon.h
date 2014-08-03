#ifndef __WEAPON__H__
#define __WEAPON__H__

//co 2 loai vu khi. Vu khi chinh: ROd. Va vu khi phu: cac item nhan duoc.
// implement phuong thuc update collision de xac dinh va cham voi enemy

#include "DynamicObject.h"
class Weapon : public DynamicObject
{
public:
	Weapon();
	virtual void Use(D3DXVECTOR2 posSimon, bool Left) = 0;
	void update(float delta_Time, std::list<ObjectGame*> *_ListObjectCollision);
protected:
private:
};
#endif // !__WEAPON__H__
