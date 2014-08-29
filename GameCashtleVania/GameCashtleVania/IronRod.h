#ifndef __TYPE_ROD__ENUM__
#define __TYPE_ROD__ENUM__
//co' 3 loai rod. Moi loai tuong ung voi Frame anh khac nhau va do dai roi khi quat cung khac nhau
enum Type_Rod
{
	Rod1 = 1,
	Rod2 = 2,
	Rod3 = 3
};
#endif // !__TYPE_ROD__ENUM__

#ifndef __STATE_ROD__ENUM_
#define __STATE_ROD__ENUM_

enum State_Rod
{
	Step1 = 1, //chuan bi quat. Roi dua het ra sau cung. Thoi gian delay lon'.
	Step2 = 2, // chuan bi quat 2: roi dua len vai
	Step3 = 3 // Quat. Roi dua ve phia truoc. attack
};

#endif // !__STATE_ROD__ENUM_

#ifndef __IRON_ROD_H_
#define __IRON_ROD_H_

#include <iostream>
#include "Weapon.h"

class IronRod : public Weapon
{
public:
	void setStateRod(State_Rod state_rod);
	Type_Rod getTypeRod(); // tra ve loai rod dang duoc su dung
	State_Rod getStateRod(); // tra ve trang thai hien tai cua rod
	void ChangeState();//thay doi trang thai 
	void ChangeTypeRod();//thay doi roi
	void Use(D3DXVECTOR2 posSimon, bool Left);//
	void reset();
	Box getBox();// box de va cham
	void animated(float deltaTime);
	void update(float delta_Time, std::vector<ObjectGame*> _ListObjectCollision);
	virtual bool completeAttack();

	static IronRod* getInstance();
	static IronRod* createInstance(std::vector<std::string> arr);
	IronRod();
	IronRod(std::vector<std::string> arr);
protected:
	Type_Rod _typeRod;
	State_Rod _stateRod;
	float timeChangeState;
	float realWidth;//dung trong get box de xet va cham

	float _elapseTimeState1;
	float _elapseTimeState2;
	float _elapseTimeState3;

	float _widthState12;
	float _widthState3;
	float _realWidthType12;//chieu dai thuc su cua roi loai 1 2
	float _realWidthType3;//chieu dai thuc su cua roi loai 3
	float realHeight;//chieu rong thuc su cua roi
private:
	static IronRod* _instance;
};
#endif // !__IRON_ROD_H_