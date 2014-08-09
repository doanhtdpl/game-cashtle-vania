#ifndef __MAP__OBJECT__
#define __MAP__OBJECT__

#include "Map.h"

class MapObject : public Map
{
public:
	MapObject();
	//list Object trong map
	std::hash_map< int, ObjectGame*> listObjectInMap;

	void readMapFromFile(std::string filePath);
protected:
private:
};

#endif // !__MAP__OBJECT__