#ifndef __TAG_CLASS_NAME__
#define __TAG_CLASS_NAME__

// Gom nhom doi tuong dua vao class name. 
// Lop nay define nhung nhom doi tuong trong game.
// Item - Enemy - Hide Object - Simon - Weapon - GroundObject
#include <string>

class TagClassName
{
public:
	std::string tagEnemy;
	const std::string tagSimon;
	const std::string tagItem;
	const std::string tagHideObject;
	const std::string tagWeapon;
	std::string tagLight;//roi danh thi roi item
	std::string tagGroundObject;
	static TagClassName* getInstance();
	TagClassName();
protected:
private:
	static TagClassName* _instance;
};

#endif // !__TAG_CLASS_NAME__
