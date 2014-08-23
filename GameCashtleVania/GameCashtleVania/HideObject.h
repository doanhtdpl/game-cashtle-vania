#ifndef __TYPE__HIDE__OBJECT__
#define __TYPE__HIDE__OBJECT__

enum class TypeHideObect
{
	Free = 701, // 32 - 32
	Ground = 702,
	DownStairLeft = 703, // 32 - 32
	UpStairLeft = 704,// 32 - 32
	ChangeScene = 705, // 32 - 96
	StopScrollScene = 706, // 32 - max
	DownStairRight = 713, // 32 - 32
	UpStairRight = 714, // 32 - 32
	ChangeTop = 715, // 32 - 32
	ChangeDown = 716 // 32 - 32
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