#ifndef __MAP__H__
#define __MAP__H__
#include "ObjectGame.h"
#include <hash_map>

class Map
{
public:
	std::hash_map< int, ObjectGame*> listObjectInMap;
public:
	void eraseObject(int IDinMap);
	void readMapFromFile(std::string filePath);
	int getIDMaxInList();
	Map(void);
	~Map(void);
};
#endif // !__MAP__H__
