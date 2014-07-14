#ifndef __SIMON_H__
#define __SIMON_H__

#include "DynamicObject.h"
#include "IAnimatedSprite.h"

class Simon : public DynamicObject, IAnimatedSprite
{
public:
	Simon();
	Simon(std::vector<std::string> arr);
	void Move(DWORD Delta_Time);
	void Update(DWORD deltatime);
	void Animated();
protected:
private:
};
#endif // !__SIMON_H__
