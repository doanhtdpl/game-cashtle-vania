#ifndef __TYPE__HIDE__OBJECT__
#define __TYPE__HIDE__OBJECT__

enum TypeHideObect
{
	Free = 701,
	Ground = 702,
	DownStair = 703,
	UpStair = 704,
	ChangeScene = 705,
	StopScrollScene = 706,
	AppearEnemy = 707

};
#endif // !__TYPE__HIDE__OBJECT__

#ifndef __HIDE__OBJECT__H_
#define __HIDE__OBJECT__H_

#include "ObjectGame.h"

class HideObject : public ObjectGame
{
public:
	HideObject();
	HideObject(std::vector<std::string> arr);
	HideObject(std::vector<std::string> arr, TypeHideObect _type);
	TypeHideObect getTypeHideObject();
	void setTypeHideObj(TypeHideObect _type);
	std::string className();
protected:
	TypeHideObect _typeHideObject;
private:
};

#endif // !__HIDE__OBJECT__H_
