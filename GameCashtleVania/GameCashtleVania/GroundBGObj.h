#ifndef __GROUND__BG__OBJECT_
#define __GROUND__BG__OBJECT_

#include "StaticObject.h"

// 2 loai: 
class GroundBGObj : public StaticObject
{
public:
	GroundBGObj();
	GroundBGObj(std::vector<std::string> arr);
	virtual std::string className();
protected:
private:
};

#endif // !__GROUND__BG__OBJECT_
