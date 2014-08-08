#ifndef __TYPE__HIDE__OBJECT__
#define __TYPE__HIDE__OBJECT__

enum TypeHideObect
{
	Ground = 702,
	UpStair = 704,
	DownStair = 703,
	StopScrollScene = 704,
	AppearEnemy = 706,
	ChangeScene = 705,
	Free = 701
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
