#ifndef __ENEMY_FACTORY__
#define __ENEMY_FACTORY__

#include "ObjectFactoty.h"
#include "Enemy.h"

class EnemyFactory : public ObjectFactory
{
public:
	static EnemyFactory* getInstance();
	EnemyFactory();
	Enemy* createObj(int ID);
	Enemy* createObj(std::vector<std::string> arr);
	std::vector<std::string> getInfoByID(int ID);

protected:
private:
	static EnemyFactory* _instance;
};
#endif // !__ENEMY_FACTORY__
