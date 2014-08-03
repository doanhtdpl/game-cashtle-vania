#ifndef __MAP__H__
#define __MAP__H__
#include "ObjectGame.h"
#include <hash_map>

class Map
{
public:
	std::hash_map< int, ObjectGame*> ListObjectInMap;
	std::vector<int> List_IdNode;
public:
	void ReadMapFromFile();
	Map(void);
	~Map(void);
};
#endif // !__MAP__H__
