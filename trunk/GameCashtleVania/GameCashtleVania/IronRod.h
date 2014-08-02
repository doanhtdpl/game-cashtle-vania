#ifndef __STATE_ROD__ENUM_
#define __STATE_ROD__ENUM_

enum State_Rod
{
	Step1 = 1, //chuan bi quat. Roi dua het ra sau cung. Thoi gian delay lon'.
	Step2 = 2, // chuan bi quat 2: roi dua len vai
	Step3 = 3 // Quat. Roi dua ve phia truoc. attack
};

#endif // !__STATE_ROD__ENUM_

#ifndef __TYPE_ROD__ENUM__

//co' 3 loai rod. Moi loai tuong ung voi Frame anh khac nhau va do dai roi khi quat cung khac nhau
enum Type_Rod
{
	Rod1 = 1,
	Rod2 = 2,
	Rod3 = 3
};
#endif // !__TYPE_ROD__ENUM__

#ifndef __IRON_ROD_H_
#define __IRON_ROD_H_

#include <iostream>
#include "Weapon.h"
#include "IAnimatedSprite.h"

class IronRod : public Weapon,IAnimatedSprite
{
public:
	Type_Rod getTypeRod(); // tra ve loai rod dang duoc su dung
	State_Rod getStateRod(); // tra ve trang thai hien tai cua rod
	void ChangeState();//thay doi trang thai 
	void ChangeTypeRod();//thay doi roi
	void Use(D3DXVECTOR2 posSimon);//
	Box getBox();// box de va cham
	void updateRectRS(int width, int height);
	float timeChangeState;//doc tu file
	
	static IronRod* getInstance();
	IronRod();
	IronRod(std::vector<std::string> arr);
protected:
	Type_Rod _typeRod;
	State_Rod _stateRod;
	float _realWidth;//chieu dai thuc su cua roi
	float _realHeight;//chieu rong thuc su cua roi
private:
	static IronRod* _instance;
};
#endif // !__IRON_ROD_H_