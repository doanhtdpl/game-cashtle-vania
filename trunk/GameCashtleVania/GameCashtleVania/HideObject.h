#ifndef __TYPE__HIDE__OBJECT__
#define __TYPE__HIDE__OBJECT__

enum TypeHideObect
{
	Ground = 701,
	UpStair = 702,
	DownStair = 703,
	StopScrollScene = 704,
	AppearEnemy = 705,
	ChangeScene = 706,
	Free = 707
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
	TypeHideObect getTypeHideObject();
	std::string className();
protected:
	TypeHideObect _typeHideObject;
private:
};

#endif // !__HIDE__OBJECT__H_
