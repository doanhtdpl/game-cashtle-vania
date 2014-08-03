#ifndef __GROUND__BG__OBJECT_
#define __GROUND__BG__OBJECT_

#include "StaticObject.h"

class GroundBGObj : public StaticObject
{
public:
	int _ID_BG;//ID cua anh load tu bg
	GroundBGObj();
	GroundBGObj(std::vector<std::string> arr);
	virtual std::string className();
protected:
private:
};

#endif // !__GROUND__BG__OBJECT_
