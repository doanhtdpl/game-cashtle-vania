#ifndef __BOSS_LEVEL1_H_
#define	__BOSS_LEVEL1_H_
#include <d3dx9.h>
#include "Boss.h"

#define MAX_TIME_CHANGE_POSITION_RANDOM 2
#define MAX_TIME_CHANGE_POSITION_SIMON 6
class BossLevel1 : public Boss
{

public:	
	BossLevel1(std::vector<std::string> arr);
	BossLevel1();
	~BossLevel1();

private:
	

};



#endif // !__BOSS_LEVEL1_H_
